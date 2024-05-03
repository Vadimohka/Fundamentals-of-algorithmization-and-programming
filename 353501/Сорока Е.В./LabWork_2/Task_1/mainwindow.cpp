#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Date inf = *new Date;



void MainWindow::on_openfile_clicked()
{
    int row = ui->table->rowCount();
    ui->table->insertRow(row);
    QDate date = ui->dateEdit->date();
    inf = Date(date.year(),date.month(),date.day());

    QTableWidgetItem *item1 = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
    ui->table->setItem(row,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(inf.nextDay().str());
    ui->table->setItem(row,1,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(inf.previousDay().str());
    ui->table->setItem(row,2,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(inf.boolToString(inf.isLeap()));
    ui->table->setItem(row,3,item4);

    QTableWidgetItem *item5 = new QTableWidgetItem(inf.shortToString(inf.weekNumber()));
    ui->table->setItem(row,4,item5);

    QTableWidgetItem *item6 = new QTableWidgetItem(inf.intToString(inf.duration(inf)));
    ui->table->setItem(row,5,item6);

    QFile file("NewSave.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }
    QTextStream out(&file);
    out << item1->text()<<'\n';
    ui->table->update();

}




void MainWindow::on_addfile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();


        QDate date = date.fromString(line, "dd.MM.yyyy");
        inf = Date(date.year(), date.month(), date.day());
        int row = ui->table->rowCount();
        ui->table->insertRow(row);

        QTableWidgetItem *item1 = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
        ui->table->setItem(row,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(inf.nextDay().str());
        ui->table->setItem(row,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(inf.previousDay().str());
        ui->table->setItem(row,2,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(inf.boolToString(inf.isLeap()));
        ui->table->setItem(row,3,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem(inf.shortToString(inf.weekNumber()));
        ui->table->setItem(row,4,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem(inf.intToString(inf.duration(inf)));
        ui->table->setItem(row,5,item6);

        ui->table->update();
    }

    file.close();

}


void MainWindow::on_changer_clicked()
{
    QDate d = ui->editdate->date();
    inf = Date(d.year(), d.month(), d.day());
    int row = ui->lineEdit->text().toInt() - 1;



    QTableWidgetItem *itm = new QTableWidgetItem(d.toString("dd.MM.yyyy"));
    ui->table->setItem(row,0,itm);

    QTableWidgetItem *itm1 = new QTableWidgetItem(inf.nextDay().str());
    ui->table->setItem(row,1,itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(inf.previousDay().str());
    ui->table->setItem(row,2,itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(inf.boolToString(inf.isLeap()));
    ui->table->setItem(row,3,itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(inf.shortToString(inf.weekNumber()));
    ui->table->setItem(row,4,itm4);

    QTableWidgetItem *itm5 = new QTableWidgetItem(inf.intToString(inf.duration(inf)));
    ui->table->setItem(row,5,itm5);

    QFile file("NewSave.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << itm->text()<<'\n';
}


void MainWindow::on_saver_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Сохранить"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    int row = ui->table->rowCount();

    for (int i = 0;i< row;i++)
    {
        QTableWidgetItem *itms = new QTableWidgetItem(ui->table->item(i,0)->text());
        out << itms->text() << '\n';
    }
    file.close();
}


void MainWindow::on_drtime_userDateChanged(const QDate &date)
{
    Date birthdaydate = Date(date.year(),date.month(),date.day());
    QDate today = today.currentDate();
    Date td = Date(today.year(),today.month(),today.day());
    ui->daysbefore->display(td.daysTillYourBithday(birthdaydate));
}

