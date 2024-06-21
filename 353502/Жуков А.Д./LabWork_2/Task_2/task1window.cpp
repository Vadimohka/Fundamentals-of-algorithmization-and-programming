#include "task1window.h"
#include "ui_task1window.h"

#include <QDebug>

enum {first, second, third, fourth, fifth, sixth};

Task1Window::Task1Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task1Window)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    QFile file("Dates.txt");
    QTextStream stream(&file);

    if (file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        if (file.size() == 0)
        {
            stream << "01.01.0001\n";
            stream << "24.04.2000\n";
            stream << "29.02.2000\n";
            stream << "31.12.2021\n";
        }
    }
    file.close();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!stream.atEnd())
        {
            dateList << Date(stream.readLine());
        }
    }
    file.close();

    updateFile();
    showData();
}

Task1Window::~Task1Window()
{
    delete ui;
}

///////////////редактирование

void Task1Window::on_addToTable_clicked()
{
    QFile file("Dates.txt");
    if (file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        QString input = ui->textEdit->toPlainText();
        if (Date::CheckFormat(input))
        {
            stream << ui->textEdit->toPlainText() << "\n";
            dateList << Date(ui->textEdit->toPlainText());
        }
        else
        {
            file.close();
            return;
        }
    }
    file.close();

    showData();
}

void Task1Window::on_deleteLine_clicked()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        return;
    }

    dateList.removeAt(ui->comboBox->currentText().toInt() - 1);

    updateFile();
    showData();
}

void Task1Window::on_editLine_clicked()
{
    if (!Date::CheckFormat(ui->textEdit->toPlainText()) || ui->tableWidget->rowCount() == 0)
    {
        return;
    }

    dateList[ui->comboBox->currentText().toInt() - 1].setDateStr(ui->textEdit->toPlainText());

    updateFile();
    showData();
}

////////////////////////обновление

void Task1Window::showData()
{
    ui->comboBox->clear();
    ui->tableWidget->setRowCount(dateList.count());
    for (int i = 0; i < dateList.count(); ++i)
    {
        ui->comboBox->addItem(QString::number(i + 1));
        date = new Date(dateList[i].GetDateStr());

        ui->tableWidget->setItem(i,
                                 first,
                                 new QTableWidgetItem(dateList[i].GetDateStr()));

        ui->tableWidget->setItem(i,
                                 second,
                                 new QTableWidgetItem(date->NextDay()->ToStr()));

        ui->tableWidget->setItem(i,
                                 third,
                                 new QTableWidgetItem(date->PreviousDay()->ToStr()));

        ui->tableWidget->setItem(i,
                                 fourth,
                                 new QTableWidgetItem(date->isLeapYear() == true ? "да" : "нет"));

        ui->tableWidget->setItem(i,
                                 fifth,
                                 new QTableWidgetItem(QString::number(Date::DaysBetweenDates(Date(dateList[i].GetDateStr()), Date(i == dateList.count() - 1 ? dateList[0].GetDateStr() : dateList[i + 1].GetDateStr())))));

        ui->tableWidget->setItem(i,
                                 sixth,
                                 new QTableWidgetItem(QString::number(Date::DaysBetweenDates(Date(dateList[i].GetDateStr())))));
    }
}

void Task1Window::updateFile()
{
    QFile file1("Dates.txt");
    file1.remove();

    QFile file("Dates.txt");
    QTextStream stream(&file);

    if (file.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        for (int i = 0; i < dateList.count(); ++i)
        {
            if (Date::CheckFormat(dateList[i].GetDateStr()))
            {
                stream << dateList[i].GetDateStr() << "\n";
            }
            else
            {
                dateList.removeAt(i);
            }
        }
    }
    file.close();
}

////////////////остальные кнопки

void Task1Window::on_openFileDirectory_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Тектовый документ с датами"),
                                                    "../build-lab2-Desktop_Qt_6_6_2_shared_MinGW_w64_MINGW64_MSYS2-Debug",
                                                    tr("*.txt"));

    if (!filePath.isEmpty()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }

    updateFile();
    showData();
}


void Task1Window::on_weekNumber_clicked()
{
    msgbx = new QMessageBox();
    msgbx->setText(QString::number(date->WeekNumber()));
    msgbx->setWindowTitle("НОМЕР НЕДЕЛИ...");
    msgbx->exec();
}


void Task1Window::on_DaysTillBirthday_clicked()
{
    if (!Date::CheckFormat(ui->textEdit_2->toPlainText()))
    {
        return;
    }
    Date birthDay(ui->textEdit_2->toPlainText());
    msgbx = new QMessageBox();
    msgbx->setText(QString::number(Date::DaysTillYourBithday(birthDay)) + " дней !");
    msgbx->setWindowTitle("ДР ЧЕРЕЗ...");
    msgbx->exec();
}
