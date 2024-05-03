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

void MainWindow::UpdateTextBox()
{
    QString text;
    for (Date date : dates)
    {
        text.append(date.ToQString());
        text.append('\n');
    }

    ui->textEdit->setPlainText(text);

    text = "";

    for (Date date : dates)
    {
        text.append(date.NextDate().ToQString());
        text.append('\n');
    }

    ui->textEdit_2->setPlainText(text);

    text = "";

    for (Date date : dates)
    {
        text.append(QString::number(date.DaysTillYourBirthday(birthdayDate)));
        text.append('\n');
    }

    ui->textEdit_3->setPlainText(text);
}

void MainWindow::UpdateBirthdayDateBox()
{
    birthdayDate.SetInstanceFromQString(ui->textEdit_4->toPlainText());
}

void MainWindow::on_pushButton_clicked()
{
    dates = fileService.ReadQFileDialogForDatesByLines(this);

    UpdateTextBox();
}

void MainWindow::on_pushButton_2_clicked()
{
    fileService.WriteInQFileDialogDatesByLines(this, dates);
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    QString current;
    std::vector<Date> updatedDates;

    int iterator = 0;
    while (iterator != text.size())
    {
        if (text[iterator] == '\n')
        {
            Date currentDate;
            currentDate.SetInstanceFromQString(current);
            updatedDates.push_back(currentDate);
            current = "";
        } else {
            current.append(text[iterator]);
        }

        iterator++;
    }

    if (current != "")
    {
        Date currentDate;
        currentDate.SetInstanceFromQString(current);
        updatedDates.push_back(currentDate);
    }

    dates = updatedDates;
}

void MainWindow::on_pushButton_3_clicked()
{
    UpdateBirthdayDateBox();
    UpdateTextBox();
}

