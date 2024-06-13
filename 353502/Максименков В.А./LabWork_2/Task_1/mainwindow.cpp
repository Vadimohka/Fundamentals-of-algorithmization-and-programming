#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->birthdayBrowser->setText(CurrentBurthday);
    ui->selectingSpinBox->setMinimum(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}

Date MainWindow::ToDate(const QString &str)
{
    QString now;
    int sz = str.size();
    int cnt = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    for(int i = 0; i < sz; ++i)
    {
        if (str[i] != '.' && str[i] != '\n') now.push_back(str[i]);
        else
        {
            if(cnt == 0)
            {
                day = now.toInt();
                now = "";
                ++cnt;
            }
            else if(cnt == 1)
            {
                month = now.toInt();
                now = "";
                ++cnt;
            }
            //date = Date(day, month, year);
            else year = now.toInt();
        }
    }
    return Date(day, month, year);
}


void MainWindow::on_addButton_clicked()
{
    ui->selectingSpinBox->setMaximum(isOpen.size() + 1);
    QDate tempDate = ui->dateEdit->date();
    Date date(0, 0, 0);
    int day = tempDate.day();
    int month = tempDate.month();
    int year = tempDate.year();
    date = Date(day, month, year);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    QString stringDate = date.DateInStringFormat();
    QTableWidgetItem* item = new QTableWidgetItem(stringDate);
    ui->tableWidget->setItem(row, 0, item);
    dates.push_back(date);
    isOpen.push_back(false);

    for (int i = 1; i <= 6; ++i)
    {
        item = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(ui->selectingSpinBox->maximum() - 1, i, item);
    }

    if (isOpen.size() > 1)
    {
        if (isOpen[ui->selectingSpinBox->maximum() - 2])
        {
            item = new QTableWidgetItem(QString::number(dates[ui->selectingSpinBox->value() - 1].Duration(dates[ui->selectingSpinBox->value()])));
            ui->tableWidget->setItem(ui->selectingSpinBox->maximum() - 2, 5, item);
        }
    }
}


void MainWindow::on_informationButton_clicked()
{
    if (ui->selectingSpinBox->value() == 0) return;
    isOpen[ui->selectingSpinBox->value() - 1] = true;

    QTableWidgetItem* item = new QTableWidgetItem(dates[ui->selectingSpinBox->value() - 1].NextDay().DateInStringFormat());
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 1, item);

qDebug() << 1;
    item = new QTableWidgetItem(dates[ui->selectingSpinBox->value() - 1].PreviousDay().DateInStringFormat());
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 2, item);
qDebug() << 2;
    QString temp = (dates[ui->selectingSpinBox->value() - 1].IsLeap() ? "Yes" : "No");
    item = new QTableWidgetItem(temp);
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 3, item);
qDebug() << 3;
    item = new QTableWidgetItem(QString::number(dates[ui->selectingSpinBox->value() - 1].WeekNumber()));
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 4, item);
qDebug() << 4;
    item = new QTableWidgetItem(QString::number(dates[ui->selectingSpinBox->value() - 1].DaysTillYourBirthday(CurrentBurthdayDate)));
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 6, item);
qDebug() << 5;
    if (ui->selectingSpinBox->value() == dates.size())
    {
        item = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 5, item);
        ui->selectingSpinBox->setValue(ui->selectingSpinBox->value() + 1);
        return;
    }
    item = new QTableWidgetItem(QString::number(dates[ui->selectingSpinBox->value() - 1].Duration(dates[ui->selectingSpinBox->value()])));
    ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, 5, item);
    ui->selectingSpinBox->setValue(ui->selectingSpinBox->value() + 1);
}


void MainWindow::on_hideButton_clicked()
{
    if (ui->selectingSpinBox->value() == 0) return;
    isOpen[ui->selectingSpinBox->value() - 1] = false;

    QTableWidgetItem* item;
    for (int i = 1; i <= 6; ++i)
    {
        item = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(ui->selectingSpinBox->value() - 1, i, item);
    }
    ui->selectingSpinBox->setValue(ui->selectingSpinBox->value() + 1);
}


void MainWindow::on_birthdayButton_clicked()
{
    QDate tempBirthday = ui->dateEdit->date();
    int day = tempBirthday.day();
    int month = tempBirthday.month();
    int year = tempBirthday.year();
    CurrentBurthdayDate = Date(day, month, year);
    CurrentBurthday = CurrentBurthdayDate.DateInStringFormat();
    ui->birthdayBrowser->setText(CurrentBurthday);
    QTableWidgetItem* item;

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        if (isOpen[i])
        {
            item = new QTableWidgetItem(QString::number(dates[i].DaysTillYourBirthday(CurrentBurthdayDate)));
            ui->tableWidget->setItem(i, 6, item);
        }
    }
}


void MainWindow::on_fileButton_clicked()
{
    QVector<QString> v;
    QFile file("/home/vlad/QTprojects/Lab_2__Task_1/in.txt");
    QString now;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << "Файл для чтения открыт!";
    else qDebug() << "Не удалось открыть файл для чтения!!!";

    while(!file.atEnd())
    {
        now = file.readLine();
        v.push_back(now);
    }

    file.close();

    qDebug() << "Данные успешно прочитаны!";

    for (int i = 0; i < v.size(); ++i)
    {
        addingDateFromFile(v[i]);
    }
}


void MainWindow::addingDateFromFile(const QString &str) // будет работать только в начале!!!
{
    ui->selectingSpinBox->setMaximum(isOpen.size() + 1);
    Date date = ToDate(str);

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    QString stringDate = date.DateInStringFormat();
    QTableWidgetItem* item = new QTableWidgetItem(stringDate);
    ui->tableWidget->setItem(row, 0, item);
    dates.push_back(date);
    isOpen.push_back(false);

    for (int i = 1; i <= 6; ++i)
    {
        item = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(ui->selectingSpinBox->maximum() - 1, i, item);
    }

    if (isOpen.size() > 1)
    {
        if (isOpen[ui->selectingSpinBox->maximum() - 2])
        {
            item = new QTableWidgetItem(QString::number(dates[ui->selectingSpinBox->value() - 1].Duration(dates[ui->selectingSpinBox->value()])));
            ui->tableWidget->setItem(ui->selectingSpinBox->maximum() - 2, 5, item);
        }
    }
}


void MainWindow::on_changeButton_clicked()
{
    int ind = ui->selectingSpinBox->value();
    QDate tempNewDate = ui->dateEdit->date();
    Date newDate(0, 0, 0);
    int day = tempNewDate.day();
    int month = tempNewDate.month();
    int year = tempNewDate.year();
    newDate = Date(day, month, year);
    dates[ind-1] = newDate;
    QString stringDate = newDate.DateInStringFormat();
    QTableWidgetItem* item = new QTableWidgetItem(stringDate);
    ui->tableWidget->setItem(ind-1, 0, item);
    isOpen[ind-1] = false;


    for (int i = 1; i <= 6; ++i)
    {
        item = new QTableWidgetItem(QString(""));
        ui->tableWidget->setItem(ind - 1, i, item);
    }
}


void MainWindow::on_actionSave_triggered()
{
    QFile file("/home/vlad/QTprojects/Lab_2__Task_1/out.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) qDebug() << "Файл для записи открыт!";
    else qDebug() << "Не удалось открыть файл для записи!!!";

    QTextStream fout(&file);
    QString temp;
    file.seek(0);
    for (int i = 0; i < dates.size(); ++i)
    {
        temp = dates[i].DateInStringFormat();
        fout << temp << '\n';
    }

    file.close();
    QMessageBox::information(this, "INFORMATIOON", "Данные успешно записаны!");
    //qDebug() << "Данные успешно записаны!";
}

