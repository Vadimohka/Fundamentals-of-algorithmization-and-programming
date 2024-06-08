#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEditTask1->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->textEditTask2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->lineEditTask2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->textEditTask3txt->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->textEditTask3bin->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->textEditTask4->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    ui->groupBoxMotorbike->setVisible(false);
    ui->groupBoxTask2->setVisible(false);
    ui->groupBoxTask3->setVisible(false);
    ui->groupBoxTask4->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEditTask1_editingFinished()
{
    if(ui->lineEditTask4->isActiveWindow()){
        QFile file("HirilukLab20.txt");
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&file);
            QString strToFile = ui->lineEditTask1->text();
            for(int i = 0; i < strToFile.length(); i++){
                stream << strToFile.at(i).toLatin1();
            }

            QString strFromFile;
            stream.seek(0);
            for(int i = 0; i < file.size(); i++){
                QChar c;
                stream >> c;
                strFromFile.push_back(c);
            }
            ui->textEditTask1->setText(strFromFile);
            file.close();
        }
    }
}


void MainWindow::on_spinBoxSize_valueChanged(int arg1)
{
    if(array != nullptr){
        delete array;
        array = nullptr;
    }
    array = new long int[arg1];
    ui->lineEditTask2->clear();
    ui->textEditTask2->clear();
    trueSize = arg1;
    size = 0;
}


void MainWindow::on_pushButtonAddNember_clicked()
{
    if(size < trueSize){
        array[size] = ui->spinBoxNumber->value();
        ui->lineEditTask2->insert(QString::number(ui->spinBoxNumber->value()) + "!");
        size++;
        if(size == trueSize){
            QFile file("HirilukLab20_0.txt");
            if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                file.resize(0);
                QTextStream stream(&file);
                for(int i = 0; i < size; i++){
                    stream << array[i];
                    stream << '!';
                }

                QString strFromFile;
                stream.seek(0);
                for(int i = 0; i < file.size()/2; i++){
                    long int number;
                    stream >> number;
                    strFromFile.push_back(QString::number(number) + ' ');
                    QChar c;
                    stream >> c;
                }
                ui->textEditTask2->setText(strFromFile);
                file.close();
            }
        }
    }
}


void MainWindow::on_pushButtonAddBike_clicked()
{
    if(ui->lineEditColor->text().length() > 1 || ui->lineEditColor->text().length() == 0){
        QMessageBox::critical(this, "Wrong Color!", "Wrong Color!\nInput only the first symbol of the color!");
        return;
    }
    if(ui->lineEditColor->text().length() == 0 || ui->lineEditName->text().length() > 10){
        QMessageBox::critical(this, "Wrong Name!", "Wrong name! Name is empty or more than 10 symbols");
        return;
    }
    Motorbike bike{
       ui->spinBoxSerialNumber->value(),
       ui->doubleSpinBoxMaxSpeed->value(),
       ui->lineEditColor->text().at(0).toLatin1(),
       ui->checkBox->isChecked(),
       ui->lineEditName->text().toStdString().c_str(),
       {ui->spinBoxLength->value(), ui->spinBoxWidth->value(), ui->spinBoxHeight->value()},
    };

    QFile file("HirilukLab20_1.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)) {
        ui->textEditTask3txt->setText("");
        QTextStream stream(&file);
        stream << bike.serialNumber << '\n';
        stream << bike.maxSpeed << '\n';
        stream << bike.color << '\n';
        stream << (bike.isMoving ? "True" : "Flase") << '\n';
        stream << bike.name << '\n';
        stream << bike.size[0] << '\n';
        stream << bike.size[1] << '\n';
        stream << bike.size[2] << '\n';

        QString strFromFile;
        stream.seek(0);
        while(stream.pos() != file.size()){
            stream >> bike.serialNumber;
            stream >> bike.maxSpeed;
            stream >> strFromFile;
            bike.color = strFromFile.at(0).toLatin1();
            stream >> strFromFile;
            bike.isMoving = strFromFile == "True" ? true : false;
            stream >> strFromFile;
            bike.name = strFromFile.toStdString().c_str();
            stream >> bike.size[0];
            stream >> bike.size[1];
            stream >> bike.size[2];
            ui->textEditTask3txt->append(bike.toQString('|') + '\n');
        }
        file.close();
    }

    QFile binFile("HirilukLab20_2.bin");
    if (binFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
        ui->textEditTask3bin->setText("");
        QDataStream stream(&binFile);
        stream.writeRawData((char*)(&bike.serialNumber), 4);
        stream.writeRawData((char*)(&bike.maxSpeed), 8);
        stream.writeRawData((char*)(&bike.color), 1);
        stream.writeRawData((char*)(&bike.isMoving), 1);
        stream.writeRawData((char*)bike.name, 10);
        stream.writeRawData((char*)(&bike.size[0]), 4);
        stream.writeRawData((char*)(&bike.size[1]), 4);
        stream.writeRawData((char*)(&bike.size[2]), 4);

        QString strFromFile;
        stream.device()->seek(0);
        while(stream.device()->pos() <= file.size()){
            stream.readRawData((char*)(&bike.serialNumber), 4);
            stream.readRawData((char*)(&bike.maxSpeed), 8);
            stream.readRawData((char*)(&bike.color), 1);
            stream.readRawData((char*)(&bike.isMoving), 1);
            stream.readRawData((char*)bike.name, 10);
            stream.readRawData((char*)(&bike.size[0]), 4);
            stream.readRawData((char*)(&bike.size[1]), 4);
            stream.readRawData((char*)(&bike.size[2]), 4);
            ui->textEditTask3bin->append(bike.toQString(';') + '\n');
        }
        binFile.close();
    }
}


void MainWindow::on_lineEditTask4_editingFinished()
{
    if(ui->lineEditTask4->isActiveWindow()){
        QFile file("HirilukLab20_3.txt");
        if (file.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice::Append)) {
            QTextStream stream(&file);
            QString strToFile = ui->lineEditTask4->text();
            stream << strToFile << '\n';

            QString strFromFile;
            stream.seek(0);
            while(true){
                QString str = stream.readLine();
                if(str == ""){
                    break;
                }
                strFromFile.push_back(str + '\n');
            }
            ui->textEditTask4->setText(strFromFile);
            file.close();
        }
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->groupBoxMotorbike->setVisible(false);
    ui->groupBoxTask1->setVisible(false);
    ui->groupBoxTask2->setVisible(false);
    ui->groupBoxTask3->setVisible(false);
    ui->groupBoxTask4->setVisible(false);
    switch(index){
        case 0:
        ui->groupBoxTask1->setVisible(true);
        break;
        case 1:
        ui->groupBoxTask2->setVisible(true);
        break;
        case 2:
        ui->groupBoxMotorbike->setVisible(true);
        ui->groupBoxTask3->setVisible(true);
        break;
        case 3:
        ui->groupBoxTask4->setVisible(true);
        break;
        defoult:
        break;
    }
}

