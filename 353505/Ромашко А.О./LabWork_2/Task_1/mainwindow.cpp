#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <ctime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    lineEdit = new QLineEdit;
    lineEdit_1 = new QLineEdit;
    d = new Date(0,0,0);
    BD = new Date(0,0,0);
    d->setDate("00.00.0000");
    //labelBD  =  new QLabel;

    time_t t1 = time(NULL);
    tm t = *localtime(&t1);
    QString a;
    a.append(asctime(localtime(&t1)));
    a.erase(a.begin()+10,a.begin()+19);
    ui->label_Now->setText(a);
    ui->pushButton_4->hide();
    ui->pushButton_->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dateArray(QString str)
{
    int a = str.size();
    QString temp;
    for(int i = 0 ; i < a; i++)
    {
        if(str[i] != '\n')
        {
            temp += str[i];
        }
        else
        {
            date[arrsize] = temp;
            arrsize++;
            temp = "";
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    filepath = QFileDialog::getOpenFileName(this,"Выбрать файл", "/Users/aleksandr/Documents/2_semestr/QT_projects/LabWork_2");
    ui->label->setText(filepath);

    QFile file(filepath);
    file.open(QIODevice::ReadWrite|QIODevice::Text);

    if(!file.exists())
        qDebug() <<"net takogo";
    fopen = true;
    int k = 0;
    while (!file.atEnd()) {
        date.push_back(QString(file.readLine()));

        k++;
        if (k > 1000) break;
    }

    arrsize = date.size();
    for(int i = 0; i < arrsize; i++)
    {
        qDebug() << i;
        date[i].removeLast();
        dateclass.push_back(*d);
        dateclass[i].setDate(date[i]);
        if(dateclass[i].qstoi()==false){
            ui->label->setText("Ошибочный ввод!");
            qDebug() << "qstoi = false but "<< dateclass[i].getDate();
        }
        dateclass[i].dateToStandart();
    }

    ui->tableWidget->setRowCount(arrsize);

    for(int i = 0 ; i<ui->tableWidget->rowCount(); i++)
        for(int j = 0; j<ui->tableWidget->columnCount();j++)
        {
            QTableWidgetItem *tbl = new QTableWidgetItem(dateclass[i].getDate());
            ui->tableWidget->setItem(i,0,tbl);
        }
    file.close();
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

}

void MainWindow::on_pushButton_2_clicked()
{

    if(fopen)
        addElements(ui->lineEdit->text());
}

void MainWindow::addElements(QString arg1)
{
    Date *d = new Date(0,0,0);
    d->setDate(arg1);
    dateclass.push_back(*d);

    dateclass[arrsize].setDate(arg1);
    qDebug() << arrsize << "=arrsize\n" << dateclass[arrsize].getDate() << "=data\n" <<dateclass[arrsize].qstoi() << "=qstoi";
    if(dateclass[arrsize].qstoi()==false){
        qDebug() << "Error input";
        ui->label->setText("Ошибочный ввод!");
    }
    else{

        dateclass[arrsize].dateToStandart();

        qDebug() << "+1 el "<< dateclass[arrsize].getDate();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        date.push_back(d->getDate());
        QString str = dateclass[arrsize].getDate();
        QFile file(filepath);

        if( file.open( QIODevice::WriteOnly|QIODevice::Append) ) {
            QTextStream stream( &file );
            qDebug() << date[arrsize];

            stream  << str  << '\n';
            QTableWidgetItem *tbl = new QTableWidgetItem(arg1);
            ui->tableWidget->setItem(arrsize,0,tbl);
        }
        arrsize++;
    }
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEditBD_textChanged(const QString &arg1)
{
        BD->setDate(arg1);
}

void MainWindow::on_labelBD_linkActivated(const QString &link)
{

}

void MainWindow::on_pushButton_3_clicked()
{
    if(BD->qstoi()){
        ui->labelBD->setText(BD->getDate());
        ui->pushButton_3->setText("Нажмите, чтобы поменять дату рождения");
    }
    else
        ui->labelBD->setText("Ошибочный ввод!");
}


void MainWindow::on_label_Now_linkActivated(const QString &link)
{

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{

    if(fopen && arg1>0 && arg1<=dateclass.size()){
        datenum= arg1-1;
        indexSB = arg1-1;
       // dateclass[datenum];dat

        Date a =dateclass[datenum].NextDay();
        a.setDate(dateclass[datenum].NextDay().dateToStandart());
        a.qstoi();

        ui->label_Next->setText(a.getDate());
        int b=1;
        if(arg1==dateclass.size())
            b=-datenum;
        qDebug( ) << datenum+b <<" datebum + b";
        ui->label_DurND->setText(QString::number(dateclass[datenum].Duration(dateclass[datenum+b])));
        ui->label_ForBD->setText(QString::number(BD->DaysTillYourBithday(&dateclass[datenum])));
    }
}


void MainWindow::on_pushButton__clicked()
{
    //удалить
}


void MainWindow::on_pushButton_4_clicked()
{
    //изменить
    if(fopen)
    {
        dateclass[indexSB].qstoi();
        QTableWidgetItem *tbl = new QTableWidgetItem(dateclass[indexSB].getDate());
        ui->tableWidget->editItem(tbl);
        ui->tableWidget->update();
    }
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    // if(fopen){
    //     dateclass[indexSB].setDate(arg1);
    // }
}

