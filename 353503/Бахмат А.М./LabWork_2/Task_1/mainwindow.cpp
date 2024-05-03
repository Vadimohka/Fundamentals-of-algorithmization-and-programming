#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::changeEvent(QEvent * e) {
    if(e->type() == QEvent::ActivationChange && this->isActiveWindow()) {
        if(_filePath != "")
        {
            readTextFile();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    _currentDate = QDate::currentDate();

    ui -> tableWidget -> setColumnCount(5);

}



void MainWindow::readTextFile()
{
    if (_filePath.isEmpty())
        return;

    _file.setFileName(_filePath);
    if (!_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream fileStream(&_file);
    QString s;
    do
    {
        fileStream >> s;
        if(!s.isEmpty())
        {
            if(s.endsWith('\\'))
            {
                s.chop(1);
            }
            if(checkDateLine(s))
            {
                addDateToVector(s);
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Wrong data");
                ui-> tableWidget -> setRowCount(0);
                return;
            }
        }
    } while (!fileStream.atEnd());

    ui -> tableWidget -> setRowCount(dates.size());
    for (int i = 0; i < dates.size(); ++i)
    {
        QTableWidgetItem* item0 = new QTableWidgetItem(dates[i].FromDateToString());
        ui -> tableWidget -> setItem(i, 0, item0);

        QTableWidgetItem* item1 = new QTableWidgetItem(dates[i].NextDay().FromDateToString());
        ui -> tableWidget -> setItem(i, 1, item1);

        QTableWidgetItem* item2 = new QTableWidgetItem(dates[i].PreviousDay().FromDateToString());
        ui -> tableWidget -> setItem(i, 2, item2);

        QTableWidgetItem* item3 = new QTableWidgetItem(dates[i].FromShortToString(dates[i].WeekNumber()));
        ui -> tableWidget -> setItem(i, 3, item3);

        QTableWidgetItem* item4 = new QTableWidgetItem(dates[i].FromBoolToString(dates[i].IsLeap()));
        ui -> tableWidget -> setItem(i, 4, item4);

        QTableWidgetItem* item6 = new QTableWidgetItem(dates[i].FromIntToString(dates[i].Duration(dates[i].FromQDatetoDate(_currentDate))));
        ui -> tableWidget -> setItem(i, 6, item6);

        if(i < dates.size() - 1)
        {
            QTableWidgetItem* item7 = new QTableWidgetItem(dates[i].FromIntToString(dates[i].Duration(dates[i + 1])));
            ui-> tableWidget -> setItem(i, 7, item7);
        }
        else
        {
            QTableWidgetItem* item7 = new QTableWidgetItem("-");
            ui -> tableWidget -> setItem(i, 7, item7);
        }
    }

    _file.close();
}

bool MainWindow::checkDateLine(QString dateLine)
{
    if(dateLine.length() > 11)
    {
        return false;
    }

    for(int i = 0; i < 10; i++)
    {
        if(i == 0 || i == 1 || i == 3 || i == 4 || (i >= 6 && i < 10))
        {
            if(dateLine[i] < '0' || dateLine[i] > '9')
                return false;
        }
        else
        {
            if(dateLine[i] != '.')
                return false;
        }
    }

    QStringList dateParts = dateLine.split('.');
    int day = dateParts[0].toInt();
    int month = dateParts[1].toInt();
    int year = dateParts[2].toInt();

    if (month < 1 || month > 12 || day < 1)
    {
        return false;
    }

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (isLeapYear && month == 2)
    {
        return (day <= 29);
    }
    else
    {
        return (day <= daysInMonth[month]);
    }
}

void MainWindow::addDateToVector(QString dateLine)
{
    QString strDay, strMonth, strYear;
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 1)
        {
            strDay += dateLine[i];
        }

        if(i >= 3 && i <= 4)
        {
            strMonth += dateLine[i];
        }

        if(i >= 6)
        {
            strYear += dateLine[i];
        }
    }

    int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
    Date date(year, month, day);
    dates.push_back(date);
}



void MainWindow::on_openFileButton_clicked()
{
    _filePath = QFileDialog::getOpenFileName(nullptr, "Выберите файл", QDir::homePath(), "Текстовые файлы (*.txt)");

    readTextFile();
}

void MainWindow::on_pushButtonBirthdayDate_clicked()
{
    _birthdayDate = ui -> lineEdit -> text();
    if(!checkDateLine(_birthdayDate))
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    _isBirthdayShow = true;

    QString strDay, strMonth, strYear;
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 1)
        {
            strDay += _birthdayDate[i];
        }

        if(i >= 3 && i <= 4)
        {
            strMonth += _birthdayDate[i];
        }

        if(i >= 6)
        {
            strYear += _birthdayDate[i];
        }
    }

    int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
    Date birthdayDate(year, month, day);

    for(int i = 0; i < dates.size(); ++i)
    {
        QTableWidgetItem* item5 = new QTableWidgetItem(dates[i].FromIntToString(dates[i].DaysTillYourBirthday(birthdayDate)));
        ui -> tableWidget -> setItem(i, 5, item5);
    }
}


void MainWindow::on_pushButtonAddDate_clicked()
{
    QString dateLine = ui -> lineEdit_2 -> text();

    if(!checkDateLine(dateLine))
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    addDateToVector(dateLine);

    QString strDay, strMonth, strYear;
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 1)
        {
            strDay += dateLine[i];
        }

        if(i >= 3 && i <= 4)
        {
            strMonth += dateLine[i];
        }

        if(i >= 6)
        {
            strYear += dateLine[i];
        }
    }

    int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
    Date date(year, month, day);

    int row = ui -> tableWidget -> rowCount();
    ui -> tableWidget -> insertRow(row);

    QTableWidgetItem* item0 = new QTableWidgetItem(date.FromDateToString());
    ui -> tableWidget -> setItem(row, 0, item0);

    QTableWidgetItem* item1 = new QTableWidgetItem(date.NextDay().FromDateToString());
    ui -> tableWidget -> setItem(row, 1, item1);

    QTableWidgetItem* item2 = new QTableWidgetItem(date.PreviousDay().FromDateToString());
    ui -> tableWidget -> setItem(row, 2, item2);

    QTableWidgetItem* item3 = new QTableWidgetItem(date.FromShortToString(date.WeekNumber()));
    ui -> tableWidget -> setItem(row, 3, item3);

    QTableWidgetItem* item4 = new QTableWidgetItem(date.FromBoolToString(date.IsLeap()));
    ui -> tableWidget -> setItem(row, 4, item4);

    QTableWidgetItem* item6 = new QTableWidgetItem(date.FromIntToString(date.Duration(date.FromQDatetoDate(_currentDate))));
    ui -> tableWidget -> setItem(row, 6, item6);

    if(row < dates.size() - 1)
    {
        QTableWidgetItem* item7 = new QTableWidgetItem(dates[row].FromIntToString(dates[row].Duration(dates[row + 1])));
        ui-> tableWidget -> setItem(row, 7, item7);
    }
    else
    {
        QTableWidgetItem* item7 = new QTableWidgetItem("-");
        ui -> tableWidget -> setItem(row, 7, item7);
    }

    if(row > 0)
    {
        QTableWidgetItem* item8 = new QTableWidgetItem(dates[row - 1].FromIntToString(dates[row - 1].Duration(dates[row])));
        ui-> tableWidget -> setItem(row - 1, 7, item8);
    }

    if(_isBirthdayShow)
    {
        QString strDay, strMonth, strYear;
        for(int i = 0; i < 10; i++)
        {
            if(i >= 0 && i <= 1)
            {
                strDay += _birthdayDate[i];
            }

            if(i >= 3 && i <= 4)
            {
                strMonth += _birthdayDate[i];
            }

            if(i >= 6)
            {
                strYear += _birthdayDate[i];
            }
        }

        int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
        Date birthdayDate(year, month, day);

        QTableWidgetItem* item5 = new QTableWidgetItem(dates[row].FromIntToString(dates[row].DaysTillYourBirthday(birthdayDate)));
        ui -> tableWidget -> setItem(row, 5, item5);
    }

    if(_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&_file);
        stream << dateLine << "\n";
        _file.close();
    }
    ui -> tableWidget -> update();
}


void MainWindow::on_pushButtonEdit_clicked()
{
    int index = ui -> spinBox -> value();

    if(index < 1 || index > dates.size())
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    index--;

    QString dateLine = ui -> lineEdit_3 -> text();

    if(!checkDateLine(dateLine))
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    _file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&_file);
    fileStream.seek((index) * 11 * sizeof(char));
    fileStream << dateLine << "\n";

    QString strDay, strMonth, strYear;
    for(int i = 0; i < 10; i++)
    {
        if(i >= 0 && i <= 1)
        {
            strDay += dateLine[i];
        }

        if(i >= 3 && i <= 4)
        {
            strMonth += dateLine[i];
        }

        if(i >= 6)
        {
            strYear += dateLine[i];
        }
    }

    int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
    Date date(year, month, day);

    QTableWidgetItem* item0 = new QTableWidgetItem(date.FromDateToString());
    ui -> tableWidget -> setItem(index, 0, item0);

    QTableWidgetItem* item1 = new QTableWidgetItem(date.NextDay().FromDateToString());
    ui -> tableWidget -> setItem(index, 1, item1);

    QTableWidgetItem* item2 = new QTableWidgetItem(date.PreviousDay().FromDateToString());
    ui -> tableWidget -> setItem(index, 2, item2);

    QTableWidgetItem* item3 = new QTableWidgetItem(date.FromShortToString(date.WeekNumber()));
    ui -> tableWidget -> setItem(index, 3, item3);

    QTableWidgetItem* item4 = new QTableWidgetItem(date.FromBoolToString(date.IsLeap()));
    ui -> tableWidget -> setItem(index, 4, item4);

    QTableWidgetItem* item6 = new QTableWidgetItem(date.FromIntToString(date.Duration(date.FromQDatetoDate(_currentDate))));
    ui -> tableWidget -> setItem(index, 6, item6);

    if(index < dates.size() - 1)
    {
        QTableWidgetItem* item7 = new QTableWidgetItem(date.FromIntToString(date.Duration(dates[index + 1])));
        ui-> tableWidget -> setItem(index, 7, item7);
    }
    else
    {
        QTableWidgetItem* item7 = new QTableWidgetItem("-");
        ui -> tableWidget -> setItem(index, 7, item7);
    }

    if(index > 0)
    {
        QTableWidgetItem* item8 = new QTableWidgetItem(dates[index - 1].FromIntToString(dates[index - 1].Duration(date)));
        ui-> tableWidget -> setItem(index - 1, 7, item8);
    }

    if(_isBirthdayShow)
    {
        QString strDay, strMonth, strYear;
        for(int i = 0; i < 10; i++)
        {
            if(i >= 0 && i <= 1)
            {
                strDay += _birthdayDate[i];
            }

            if(i >= 3 && i <= 4)
            {
                strMonth += _birthdayDate[i];
            }

            if(i >= 6)
            {
                strYear += _birthdayDate[i];
            }
        }

        int day = strDay.toInt(), month = strMonth.toInt(), year = strYear.toInt();
        Date birthdayDate(year, month, day);

        QTableWidgetItem* item5 = new QTableWidgetItem(date.FromIntToString(date.DaysTillYourBirthday(birthdayDate)));
        ui -> tableWidget -> setItem(index, 5, item5);
    }

    ui -> tableWidget -> update();

    _file.close();
}

void MainWindow::update()
{
    readTextFile();
}

