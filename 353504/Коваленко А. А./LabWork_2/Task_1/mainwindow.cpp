#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTodayDate();
    ui->nowDate->setText(today.getStrDate());

    ui->spinBoxBirthDay->setMaximum(DAYS31);
    ui->spinBoxBirthDay->setMinimum(1);
    ui->spinBoxBirthMonth->setMaximum(DEC);
    ui->spinBoxBirthMonth->setMinimum(1);
    ui->spinBoxBirthYear->setMinimum(1);
    ui->spinBoxBirthYear->setMaximum(today.getYear());
    ui->spinBoxBirthDay->setValue(MY_BIRTH_DAY);
    ui->spinBoxBirthMonth->setValue(MY_BIRTH_MONTH);
    ui->spinBoxBirthYear->setValue(MY_BIRTH_YEAR);

    ui->spinBoxNewMonth->setMaximum(DEC);
    ui->spinBoxNewMonth->setMinimum(1);
    ui->spinBoxNewDay->setMaximum(DAYS31);
    ui->spinBoxNewDay->setMinimum(1);
    ui->spinBoxNewYear->setMinimum(1);
    ui->spinBoxNewYear->setMaximum(9999);
    ui->spinBoxNewDay->setValue(today.getDay());
    ui->spinBoxNewMonth->setValue(today.getMonth());
    ui->spinBoxNewYear->setValue(today.getYear());

    ui->spinBoxDelete->setMinimum(1);

    birthdayDate.setDate(MY_BIRTH_DAY, MY_BIRTH_MONTH, MY_BIRTH_YEAR);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTodayDate()
{
    time_t currentTime = time(nullptr);
    struct tm *localTime = localtime(&currentTime);
    today.setDate(localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + TIME_CONST);
}

void MainWindow::on_actionOpen_triggered()
{
    sourseFile = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    QFile file(sourseFile);
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        ui->tableWidget->setRowCount(0);
        QString str = "";
        str = file.readLine();
        qDebug() << str;
        str.remove(str.size() - 1, 1);
        count = str.toInt();
        dates = new Date[count];
        ui->tableWidget->setRowCount(count);
        ui->spinBoxDelete->setMinimum(1);
        ui->spinBoxDelete->setMaximum(count);
        for (int i = 0; i < count; i++) {
            str = file.readLine();
            QString day = "", month = "", year = "";
            day.append(str[0]);
            day.append(str[1]);
            month.append(str[3]);
            month.append(str[4]);
            year.append(str[6]);
            year.append(str[7]);
            year.append(str[8]);
            year.append(str[9]);
            dates[i].setDate(day.toInt(), month.toInt(), year.toInt());
            qDebug() << day + '.' + month + '.' + year;
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(day + '.' + month + '.' + year));
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Error!", "File isn't open or isn't exist!");
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (!sourseFile.isEmpty()) {
        QFile file(sourseFile);
        if ((file.exists()) && (file.open(QIODevice::WriteOnly))) {
            QString buf;
            buf = QString::number(count);
            file.write(buf.toStdString().c_str());
            file.write("\n");
            for (int i = 0; i < count; i++) {
                if (!(dates[i].getDay() / TWO_DIGIT_NUM)) {
                    buf = '0' + QString::number(dates[i].getDay());
                    file.write(buf.toStdString().c_str());
                } else {
                    buf = QString::number(dates[i].getDay());
                    file.write(buf.toStdString().c_str());
                }
                file.write(".");
                if (!(dates[i].getMonth() / TWO_DIGIT_NUM)) {
                    buf = '0' + QString::number(dates[i].getMonth());
                    file.write(buf.toStdString().c_str());
                } else {
                    buf = QString::number(dates[i].getMonth());
                    file.write(buf.toStdString().c_str());
                }

                file.write(".");
                if (!(dates[i].getYear() / TWO_DIGIT_NUM)) {
                    buf = "000" + QString::number(dates[i].getYear());
                    file.write(buf.toStdString().c_str());
                } else if (!(dates[i].getYear() / THREE_DIGIT_NUM)) {
                    buf = "00" + QString::number(dates[i].getYear());
                    file.write(buf.toStdString().c_str());
                } else if (!(dates[i].getYear() / FOUR_DIGIT_NUM)) {
                    buf = '0' + QString::number(dates[i].getYear());
                    file.write(buf.toStdString().c_str());
                } else {
                    buf = QString::number(dates[i].getYear());
                    file.write(buf.toStdString().c_str());
                }
                file.write("\n");
            }
            file.close();
        }
    } else {
        QMessageBox::critical(this, "Error!", "You can't save without opening");
    }
}

void MainWindow::on_buttonNextDay_clicked()
{
    Date buf;
    for (int i = 0; i < count; i++) {
        buf.setDate(dates[i].NextDay());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(buf.getStrDate()));
    }
}

void MainWindow::on_buttonPreviousDay_clicked()
{
    Date buf;
    for (int i = 0; i < count; i++) {
        buf.setDate(dates[i].PreviousDay());
        if (buf.getYear()) {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(buf.getStrDate()));
        } else {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("doesn't exist"));
        }
    }
}

void MainWindow::on_buttonIsLeap_clicked()
{
    for (int i = 0; i < count; i++) {
        if (dates[i].IsLeap()) {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("yes")));
        } else {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString("no")));
        }
    }
}

void MainWindow::on_buttonWeekNumber_clicked()
{
    for (int i = 0; i < count; i++) {
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(dates[i].WeekNumber())));
    }
}

void MainWindow::on_buttonDuration_clicked()
{
    for (int i = 0; i < count; i++) {
        ui->tableWidget->setItem(i,
                                 5,
                                 new QTableWidgetItem(QString::number(dates[i].Duration(today))));
    }
}

void MainWindow::on_buttonDaysBirthday_clicked()
{
    for (int i = 0; i < count; i++) {
        ui->tableWidget->setItem(i,
                                 6,
                                 new QTableWidgetItem(
                                     QString::number(dates[i].DaysTillYourBirthday(birthdayDate))));
    }
}

void MainWindow::on_buttonBirth_clicked()
{
    birthdayDate.setDate(ui->spinBoxBirthDay->value(),
                         ui->spinBoxBirthMonth->value(),
                         ui->spinBoxBirthYear->value());
}

void MainWindow::on_buttonNew_clicked()
{
    if (sourseFile != "") {
        int day = 0, month = 0, year = 0;
        day = ui->spinBoxNewDay->value();
        month = ui->spinBoxNewMonth->value();
        year = ui->spinBoxNewYear->value();

        Date *temp = new Date[count + 1];
        for (int i = 0; i < count; i++) {
            temp[i].setDate(dates[i]);
        }
        temp[count].setDate(day, month, year);
        count++;
        delete[] dates;
        dates = temp;
        temp = nullptr;

        ui->tableWidget->setRowCount(count);
        ui->spinBoxDelete->setMaximum(count);
        for (int i = 0; i < count; i++) {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates[i].getStrDate()));
        }
    } else {
        QMessageBox::critical(this, "Error!", "Firstly open the file!");
    }
}

void MainWindow::on_pushButtonDelete_clicked()
{
    if (count > 0) {
        int num = ui->spinBoxDelete->value() - 1;
        for (int i = num; i < count; i++) {
            dates[i].setDate(dates[i + 1]);
        }
        count--;
        ui->tableWidget->setRowCount(count);
        Date *temp = new Date[count];
        for (int i = 0; i < count; i++) {
            temp[i].setDate(dates[i]);
        }
        delete[] dates;
        dates = temp;
        temp = nullptr;
        ui->spinBoxDelete->setMaximum(count);
        for (int i = 0; i < count; i++) {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates[i].getStrDate()));
        }
    } else {
        QMessageBox::critical(this, "Error!", "You can't delete unexisting item!");
    }
}

void MainWindow::on_spinBoxBirthYear_valueChanged(int year)
{
    Date temp(1, 1, year);
    int month = ui->spinBoxBirthMonth->value();
    if (temp.IsLeap() && month == FEB) {
        ui->spinBoxBirthDay->setMaximum(FEB_DAYS_LEAP);
    } else if (month == FEB) {
        ui->spinBoxBirthDay->setMaximum(FEB_DAYS);
    } else if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG
               || month == OCT || month == DEC) {
        ui->spinBoxBirthDay->setMaximum(DAYS31);
    } else if (month == APR || month == JUN || month == SEP || month == NOV) {
        ui->spinBoxBirthDay->setMaximum(DAYS30);
    }
}

void MainWindow::on_spinBoxBirthMonth_valueChanged(int month)
{
    Date temp(1, 1, ui->spinBoxBirthYear->value());
    if (temp.IsLeap() && month == FEB) {
        ui->spinBoxBirthDay->setMaximum(FEB_DAYS_LEAP);
    } else if (month == FEB) {
        ui->spinBoxBirthDay->setMaximum(FEB_DAYS);
    } else if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG
               || month == OCT || month == DEC) {
        ui->spinBoxBirthDay->setMaximum(DAYS31);
    } else if (month == APR || month == JUN || month == SEP || month == NOV) {
        ui->spinBoxBirthDay->setMaximum(DAYS30);
    }
}

void MainWindow::on_spinBoxNewYear_valueChanged(int year)
{
    Date temp(1, 1, year);
    int month = ui->spinBoxNewMonth->value();
    if (temp.IsLeap() && month == FEB) {
        ui->spinBoxNewDay->setMaximum(FEB_DAYS_LEAP);
    } else if (month == FEB) {
        ui->spinBoxNewDay->setMaximum(FEB_DAYS);
    } else if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG
               || month == OCT || month == DEC) {
        ui->spinBoxNewDay->setMaximum(DAYS31);
    } else if (month == APR || month == JUN || month == SEP || month == NOV) {
        ui->spinBoxNewDay->setMaximum(DAYS30);
    }
}

void MainWindow::on_spinBoxNewMonth_valueChanged(int month)
{
    Date temp(1, 1, ui->spinBoxNewYear->value());
    if (temp.IsLeap() && month == FEB) {
        ui->spinBoxNewDay->setMaximum(FEB_DAYS_LEAP);
    } else if (month == FEB) {
        ui->spinBoxNewDay->setMaximum(FEB_DAYS);
    } else if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG
               || month == OCT || month == DEC) {
        ui->spinBoxNewDay->setMaximum(DAYS31);
    } else if (month == APR || month == JUN || month == SEP || month == NOV) {
        ui->spinBoxNewDay->setMaximum(DAYS30);
    }
}
