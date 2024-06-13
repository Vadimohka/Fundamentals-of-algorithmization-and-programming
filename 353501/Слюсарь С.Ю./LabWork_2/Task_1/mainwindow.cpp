#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CurrentDate->setText("Today: " + current);
    QRegularExpression rx("([0-2]?[0-9]|3[0-1])\\.([0]?[1-9]|1[0-2])\\.([0-9]{4})");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(rx);
    ui->Bithday->setValidator(validator);
    ui->NewDate->setValidator(validator);
    ui->Change->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    ui->Output->clear();
    path = QFileDialog::getOpenFileName();
    file.setFileName(path);
    if (file.exists())
    {
        file.open(QIODevice::ReadWrite);
        s = file.readAll();
        ui->Output->setText("File open");
    }

    for (int i = 0; i < s.length(); i += 11)
    {
        QString sub = s.mid(i, 10);
        date.append(Date(sub));
        while (i + 11 == ' ')
        {
            ++i;
        }
    }
}

void MainWindow::on_PrintNextDay_clicked()
{
    ui->Output->clear();
    for (int i = 0; i < date.size(); ++i)
    {
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(date[i].NextDay().print()));
    }
    if (!file.isOpen())
    {
        ui->Output->setText("File not open");
    }
}


void MainWindow::on_PrintDifference_clicked()
{
    ui->Output->clear();
    for (int i = 0; i < date.size(); ++i)
    {
        if (i + 1 < date.size())
        {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(date[i].Duration(date[i + 1]))));
        }
        else
        {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(date[i].Duration(date[0]))));
        }
    }
    if (!file.isOpen())
    {
        ui->Output->setText("File not open");
    }
}

void MainWindow::on_AddDate_clicked()
{
    ui->Output->clear();
    if (file.isOpen())
    {
        QTextStream stream(&file);
        if (ui->NewDate->text().length() == 10)
        {
            newDate = ui->NewDate->text();
            Date d = Date(newDate);
            if (d.day_ > d.maxDay(d.month_))
            {
                ui->NewDate->setText("Wrong Date");
            }
            else
            {
                date.append(Date(newDate));
                stream << newDate << ' ';
                ui->NewDate->clear();
            }
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }

}


void MainWindow::on_ChangeDate_clicked()
{
    ui->Output->clear();
    if (file.isOpen())
    {
        QTextStream stream(&file);
        if (ui->Change->text().length() == 10)
        {
            change = ui->Change->text();
            Date d = Date(change);
            if (d.day_ > d.maxDay(d.month_))
            {
                ui->Change->setText("Wrong Date");
            }
            else
            {
                date[ui->NumOfDate->text().toInt() - 1] = Date(change);
                file.seek(ui->NumOfDate->text().toInt() * 11 - 11);
                stream << change;
                ui->Change->clear();
                ui->NumOfDate->clear();
            }
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }
}

void MainWindow::on_PrintDate_clicked()
{
    ui->Output->clear();
    ui->tableWidget->setRowCount(date.size());
    for (int i = 0; i < date.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(date[i].print()));
    }
    if (!file.isOpen())
    {
        ui->Output->setText("File not open");
    }
}

void MainWindow::on_ToBith_clicked()
{
    Date d;
    ui->Output->clear();
    if (ui->Bithday->text().length() == 10)
    {
        yourBithday = ui->Bithday->text();
        d = Date(yourBithday);
        if (d.day_ > d.maxDay(d.month_))
        {
            ui->DayTillBithday->setText("Wrong Date");
        }
        else
        {
            Date bith = Date(yourBithday);
            Date currentDate = Date(current);
            int diff = currentDate.DaysTillYourBithday(bith);
            ui->DayTillBithday->setText(QString::number(diff));
        }
    }
    else
    {
        ui->Output->setText("Wrong input");
    }
}
