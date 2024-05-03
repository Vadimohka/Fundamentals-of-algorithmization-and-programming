#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui -> page_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
QVector<Date> datearr;


void MainWindow::SaveFile(int index, QString str_save) {
    QFile file(file_id);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek((index)* 11 * sizeof(char));
    fileStream << str_save << "\n";
    file.close();
}

void MainWindow::on_Add_clicked()
{
    QString str;
    int year = ui->DateAdd->date().year();
    int month = ui->DateAdd->date().month();
    int day = ui->DateAdd->date().day();

    n_str = ui-> table -> rowCount();
    ui->table->insertRow(n_str);
    datearr.resize(n_str + 1);

    datearr[n_str] = Date(day, month, year);
    QString TO_STR = QString("%1.%2.%3").arg(day).arg(month).arg(year);

    Date ND = datearr[n_str].NextDay();
    QString ND_STR = QString("%1.%2.%3").arg(ND.day).arg(ND.month).arg(ND.year);

    Date PD = datearr[n_str].PreviousDay();
    QString PD_STR = QString("%1.%2.%3").arg(PD.day).arg(PD.month).arg(PD.year);

    ui->table->setItem(n_str, 0, new QTableWidgetItem(TO_STR));
    ui->table->setItem(n_str, 1, new QTableWidgetItem(ND_STR));
    ui->table->setItem(n_str, 2, new QTableWidgetItem(PD_STR));
    ui->table->setItem(n_str, 3, new QTableWidgetItem(str.setNum(datearr[n_str].weekNumber())));
    ui->table->setItem(n_str, 4, new QTableWidgetItem(datearr[n_str].IsLeap() == true ? "ДА" : "НЕТ"));
    ui->table->setItem(n_str, 5, new QTableWidgetItem(str.setNum(datearr[n_str].Duration(datearr[n_str]))));
    QString STR_F = day < 10 ? "0" + str.setNum(day) + "." : str.setNum(day) + ".";
    STR_F += month < 10 ? "0" + str.setNum(month) + "." : str.setNum(month) + ".";
    STR_F += year < 10 ? "000" + str.setNum(year) : (year < 100 ? "00" + str.setNum(year) : (year < 1000 ? "0" + str.setNum(year) : str.setNum(year)));
    SaveFile(n_str, STR_F);
}
void MainWindow::on_OpenFile_clicked()
{
    file_id = QFileDialog::getOpenFileName(this, tr("Открыттие файла"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(file_id);
    file.open(QIODevice::ReadOnly);
    QTextStream fileQTS(&file);
    while (!fileQTS.atEnd())
    {
        ui->stackedWidget->setCurrentWidget(ui -> page);
        QString str;
        QString line = fileQTS.readLine();
        if (!CheckFile(line))
        {
            ui -> label_6 -> setText("НЕВЕРНЫЕ данные в файле");
            return;
        }
        else{
            ui -> label_6 -> setText("");
        }
        int n_str = ui->table->rowCount();
        ui->table->insertRow(n_str);
        datearr.resize(n_str + 1);

        QString day, month, year;
        day = line[0];
        day += line[1];
        month = line[3];
        month += line[4];
        year = line[6];
        year += line[7];
        year += line[8];
        year += line[9];
        int day_int = day.toInt(), month_int = month.toInt(), year_int = year.toInt();
        datearr[n_str] = Date(day_int, month_int, year_int);
        QString TO_STR = QString("%1.%2.%3").arg(day).arg(month).arg(year);

        Date ND = datearr[n_str].NextDay();
        QString ND_STR = QString("%1.%2.%3").arg(ND.day).arg(ND.month).arg(ND.year);

        Date PD = datearr[n_str].PreviousDay();
        QString PD_STR = QString("%1.%2.%3").arg(PD.day).arg(PD.month).arg(PD.year);

        ui->table->setItem(n_str, 0, new QTableWidgetItem(TO_STR));
        ui->table->setItem(n_str, 1, new QTableWidgetItem(ND_STR));
        ui->table->setItem(n_str, 2, new QTableWidgetItem(PD_STR));
        ui->table->setItem(n_str, 3, new QTableWidgetItem(str.setNum(datearr[n_str].weekNumber())));
        ui->table->setItem(n_str, 4, new QTableWidgetItem(datearr[n_str].IsLeap() == true ? "ДА" : "НЕТ"));
        ui->table->setItem(n_str, 5, new QTableWidgetItem(str.setNum(datearr[n_str].Duration(datearr[n_str]))));
    }
    file.close();
}

bool MainWindow::CheckFile(QString date)
{
    if (date[2] != '.' || date[5] != '.' || date.length() != 10)
    {
        return false;
    }
    for(int i = 0; i < date.length(); ++i)
    {
        if ((date[i] > '9' || date[i] < '0') && date[i] != '.' )
        {
            return false;
        }
    }
    QString day, month, year;
    day = date[0];
    day += date[1];
    month = date[3];
    month += date[4];
    year = date[6];
    year += date[7];
    year += date[8];
    year += date[9];

    int day_int = day.toInt(), month_int = month.toInt(), year_int = year.toInt();
    Date obg(day_int,month_int,year_int);

    if (month_int > 12 || day_int > 31 || month_int < 0 || day_int < 0 || year_int > 9999 || year_int < 0)
    {
        return false;
    }

    if (!obg.IsLeap() && month_int == 2 && day_int > 28)
    {
        return false;
    }

    if (obg.IsLeap() && month_int == 2 && day_int > 29)
    {
        return false;
    }

    if(day_int > 30 && (month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11))
    {
        return false;
    }

    return true;
}


void MainWindow::on_DateBirt_userDateChanged(const QDate &date)
{
    Date birthdaydate = Date(date.day(),date.month(),date.year());
    QDate now = now.currentDate();
    Date td = Date(now.year(), now.month(), now.day());
    int days_br = td.DaysTillYourBithday(birthdaydate);
    QString str = QString::number(days_br);
    ui->label_6->setText("Ваше день рождение через " + str + " дней");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str;
    int year = ui->DateNew->date().year();
    int month = ui->DateNew->date().month();
    int day = ui->DateNew->date().day();

    int n_str = ui-> NamberStr -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table -> rowCount())
    {
        ui -> label_6 -> setText("Введите правильный НОМЕР даты");
        return;
    }

    datearr[n_str] = Date(day, month, year);
    QString TO_STR = QString("%1.%2.%3").arg(day).arg(month).arg(year);

    Date ND = datearr[n_str].NextDay();
    QString ND_STR = QString("%1.%2.%3").arg(ND.day).arg(ND.month).arg(ND.year);

    Date PD = datearr[n_str].PreviousDay();
    QString PD_STR = QString("%1.%2.%3").arg(PD.day).arg(PD.month).arg(PD.year);

    ui->table->setItem(n_str, 0, new QTableWidgetItem(TO_STR));
    ui->table->setItem(n_str, 1, new QTableWidgetItem(ND_STR));
    ui->table->setItem(n_str, 2, new QTableWidgetItem(PD_STR));
    ui->table->setItem(n_str, 3, new QTableWidgetItem(str.setNum(datearr[n_str].weekNumber())));
    ui->table->setItem(n_str, 4, new QTableWidgetItem(datearr[n_str].IsLeap() == true ? "ДА" : "НЕТ"));
    ui->table->setItem(n_str, 5, new QTableWidgetItem(str.setNum(datearr[n_str].Duration(datearr[n_str]))));
    QString STR_F = day < 10 ? "0" + str.setNum(day) + "." : str.setNum(day) + ".";
    STR_F += month < 10 ? "0" + str.setNum(month) + "." : str.setNum(month) + ".";
    STR_F += year < 10 ? "000" + str.setNum(year) : (year < 100 ? "00" + str.setNum(year) : (year < 1000 ? "0" + str.setNum(year) : str.setNum(year)));
    SaveFile(n_str, STR_F);
}
