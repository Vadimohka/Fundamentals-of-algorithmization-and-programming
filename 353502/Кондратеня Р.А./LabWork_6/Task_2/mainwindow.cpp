#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    textEdit = new CustomTextEdit(this);
    ui->comboBox->addItem("Ввести абзац текста");
    ui->comboBox->addItem("Вывести абзац текста");
    ui->comboBox->addItem("Ввести массив float");
    ui->comboBox->addItem("Вывести массив");
    ui->comboBox->addItem("Записать объект структуры в текстовый файл");
    ui->comboBox->addItem("Вывести все объекты");
    ui->comboBox->addItem("Записать объект в бинарный файл");
    ui->comboBox->addItem("Вывести все объекты бинарного файла");



    textEdit->move(0, 104);
    textEdit->setFixedHeight(440);
    textEdit->setFixedWidth(800);

    show();

    while(true)
    {
        QCoreApplication::processEvents();
        switch(ui->comboBox->currentIndex())
        {
        case 0:
            textEdit->setAction("Ввести абзац текста");
            textEdit->show();
            break;
        case 1:
            textEdit->setAction("Вывести абзац текста");
            textEdit->getTextFromFile("/home/kbadpat/OAiP/Lab6/Task2/text.txt");
            textEdit->show();
            break;
        case 2:
            textEdit->setAction("Ввести массив float");
            textEdit->show();
            break;
        case 3:
            textEdit->setAction("Вывести массив");
            textEdit->loadFloatArrayFromFile();
            textEdit->show();
            break;
        case 4:
            textEdit->setAction("Записать объект структуры в текстовый файл");
            textEdit->hide();
            break;
        case 5:
            textEdit->setAction("Вывести все объекты");
            textEdit->getTextFromFile("/home/kbadpat/OAiP/Lab6/build-Task2-Desktop-Debug/data.txt");
            textEdit->show();
            break;
        case 6:
            textEdit->setAction("Записать объект в бинарный файл");
            textEdit->hide();
            break;
        case 7:
            textEdit->setAction("Вывести все объекты бинарного файла");
            textEdit->loadTextFromBinaryFile("data.bin");
            textEdit->show();
            break;
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setCount()
{
    textEdit->setN(ui->spinBox->value());
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    textEdit->setN(arg1);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << "ok";
    textEdit->clear();
    Q_UNUSED(index);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() == 4)
    {
        plant.age = ui->lineEdit->text().toInt();
        plant.height = ui->lineEdit_2->text().toDouble();
        plant.category = ui->lineEdit_3->text().at(0).toLatin1();
        plant.isHealthy = ui->lineEdit_4->text().toInt();
        QByteArray nameBytes = ui->lineEdit_5->text().toUtf8();
        qstrncpy(plant.name, nameBytes.constData(), sizeof(plant.name));
        QStringList humidityValues = ui->lineEdit_6->text().split(" ");
        for (int i = 0; i < humidityValues.size(); ++i) {
            plant.humidity[i] = humidityValues[i].toInt();
        }
        if(ui->lineEdit_4->text() == "true")
            plant.isHealthy = true;
        else
            plant.isHealthy = false;

        QFile file("/home/kbadpat/OAiP/Lab6/build-Task2-Desktop-Debug/data.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << plant.age << " " << plant.height << " " << plant.category << " "
                   << plant.isHealthy << " " << plant.name << " ";
            for (int i = 0; i < humidityValues.size(); ++i) {
                stream << humidityValues[i] << ",";
            }
            stream << "\n";
            file.close();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
        }
    }
    if(ui->comboBox->currentIndex() == 6)
    {
        Plant plant;
        plant.age = ui->lineEdit->text().toInt();
        plant.height = ui->lineEdit_2->text().toDouble();
        plant.category = ui->lineEdit_3->text().at(0).toLatin1();
        plant.isHealthy = ui->lineEdit_4->text().toInt();
        QByteArray nameBytes = ui->lineEdit_5->text().toUtf8();
        qstrncpy(plant.name, nameBytes.constData(), sizeof(plant.name));
        QStringList humidityValues = ui->lineEdit_6->text().split(" ");
        for (int i = 0; i < humidityValues.size(); ++i) {
            plant.humidity[i] = humidityValues[i].toInt();
        }
        if(ui->lineEdit_5->text() == "true")
            plant.isHealthy = true;
        else
            plant.isHealthy = false;

        QFile file("data.bin");
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream stream(&file);
            stream.writeRawData(reinterpret_cast<const char*>(&plant), sizeof(Plant));
            stream.writeRawData(reinterpret_cast<const char*>(plant.humidity), humidityValues.size() * sizeof(int));
            file.close();
        }
    }

}

