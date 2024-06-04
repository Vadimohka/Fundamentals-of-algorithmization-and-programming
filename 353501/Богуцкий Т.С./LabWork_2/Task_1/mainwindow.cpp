#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_lineEdit_editingFinished()
{
    int day = -1, month = -1, year = -1, res;
    int *h1 = &day, *h2 = &month, *h3 = &year;
    QString str = ui->lineEdit->text();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Неверный формат даты или данной даты не существует!");
    msgBox.setWindowTitle("Предупреждение");

    helper.getDate(str, h1, h2, h3);
    bool mistake = false;
    if (year % 4 == 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_vis_amount_days[month] || day < 1) mistake = true;
    }
    else if (year % 4 != 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_amount_days[month] || day < 1) mistake = true;
    }

    if(mistake)
    {
        msgBox.exec();
    }

    else
    {
        Date class_date;
        class_date.day = day;
        class_date.month = month;

        res = helper.DaysTillYourBirthday(class_date);
        QString help = QString::number(res);

        ui->days_birthday->setText(help);
    }
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    int day = -1, month = -1, year = -1, res;
    int *h1 = &day, *h2 = &month, *h3 = &year;
    QString str = ui->lineEdit_2->text();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Неверный формат даты или данной даты не существует!");
    msgBox.setWindowTitle("Предупреждение");

    helper.getDate(str, h1, h2, h3);
    bool mistake = false;
    if (year % 4 == 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_vis_amount_days[month] || day < 1) mistake = true;
    }
    else if (year % 4 != 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_amount_days[month] || day < 1) mistake = true;
    }

    if(mistake)
    {
        msgBox.exec();
    }
    else
    {
        QDate date = QDate::currentDate();
        int current_day = date.day(), current_month = date.month(), current_year = date.year();

        Date class_date;
        class_date.day = day;
        class_date.month = month;
        class_date.year = year;

        Date class_current_date;
        class_current_date.day = current_day;
        class_current_date.month = current_month;
        class_current_date.year = current_year;

        res = helper.Duration(class_date, class_current_date);
        QString help = QString::number(res);

        ui->days_date ->setText(help);
    }

}


void MainWindow::on_choose_file_clicked()
{
    ui->tableWidget->setRowCount(0);
    list_for_dates.clear();
    int day, month, year;
    int *h1 = &day, *h2 = &month, *h3 = &year;
    Date helper;

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
    if (!fileName.isEmpty()) {
        reserve = fileName;
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                // Обработайте строку line по вашим потребностям
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] != " ") help_string += line[i];
                    if ((line[i] ==" " || i == line.size() - 1) && help_string!=nullptr)
                    {
                        helper.getDate(help_string, h1, h2, h3);
                        helper.day = day;
                        helper.month = month;
                        helper.year = year;
                        list_for_dates.append(helper);
                        help_string = nullptr;
                    }
                }
                qDebug() << "Прочитано из файла:" << line;
            }
            file.close();
        } else {
            qWarning() << "Не удалось открыть файл для чтения.";
        }
    }
    else {
        qDebug() << "Файл не выбран.";
    }

    ui->tableWidget->setRowCount(list_for_dates.size());

    QString str = nullptr;
    for (int i = 0; i< list_for_dates.size(); i++)
    {
        Date kluch = list_for_dates[i];
        if (kluch.day <= 9) str+= "0";
        str += QString::number(kluch.day);
        str +=".";
        if (kluch.month <= 9) str+= "0";
        str += QString::number(kluch.month);
        str +=".";
        if (kluch.year <= 9) str+= "0";
        str += QString::number(kluch.year);

        QTableWidgetItem *item1 = new QTableWidgetItem(str);
        item1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, item1);
        str = QString::number(kluch.WeekNumber());

        QTableWidgetItem *item2 = new QTableWidgetItem(str);
        item2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, item2);
        if (kluch.isLeap()) str = "IsLeap";
        else str = "NotLeap";

        QTableWidgetItem *item3 = new QTableWidgetItem(str);
        item3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 2, item3);

        str = kluch.NextDay();
        QTableWidgetItem *item4 = new QTableWidgetItem(str);
        item4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 3, item4);

        QDate date = QDate::currentDate();
        int current_day = date.day(), current_month = date.month(), current_year = date.year();
        Date class_current_date;
        class_current_date.day = current_day;
        class_current_date.month = current_month;
        class_current_date.year = current_year;

        str = QString::number(kluch.Duration(kluch, class_current_date));
        QTableWidgetItem *item5 = new QTableWidgetItem(str);
        item5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 4, item5);


        Date class_for_duration;
        if (i < list_for_dates.size()-1)
        {
            class_for_duration.day = list_for_dates[i+1].day;
            class_for_duration.month = list_for_dates[i+1].month;
            class_for_duration.year = list_for_dates[i+1].year;
            str = QString::number(kluch.Duration(class_for_duration, kluch));
        }
        else str = "-1";
        QTableWidgetItem *item6 = new QTableWidgetItem(str);
        item6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 5, item6);

        str = nullptr;
    }

}


void MainWindow::on_lineEdit_3_editingFinished()
{
    int day = -1, month = -1, year = -1;
    int *h1 = &day, *h2 = &month, *h3 = &year;
    QString str = ui->lineEdit_3->text();
    ALLOW = false;

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Неверный формат даты или данной даты не существует!");
    msgBox.setWindowTitle("Предупреждение");

    helper.getDate(str, h1, h2, h3);
    bool mistake = false;
    if (year % 4 == 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_vis_amount_days[month] || day < 1 || str.size() < 5) mistake = true;
    }
    else if (year % 4 != 0)
    {
        if (month > 12 || month < 1 || year <0 || day > month_amount_days[month] || day < 1 || str.size() < 5) mistake = true;
    }

    if(mistake)
    {
        ALLOW = false;
        msgBox.exec();
    }
    else ALLOW = true;

}


void MainWindow::on_input_date_clicked()
{
    if (ALLOW){
    QString str1 = ui->lineEdit_3->text();


    QFile file(reserve);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QTextStream out(&file);
        out << str1 << Qt::endl;
        QMessageBox::information(this, "Успех", "Дата успешно добавлена");
    }

    ui->tableWidget->setRowCount(0);
    list_for_dates.clear();
    int day, month, year;
    int *h1 = &day, *h2 = &month, *h3 = &year;
    Date helper;

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
    if (!fileName.isEmpty()) {
        reserve = fileName;
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                // Обработайте строку line по вашим потребностям
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] != " ") help_string += line[i];
                    if ((line[i] ==" " || i == line.size() - 1) && help_string!=nullptr)
                    {
                        helper.getDate(help_string, h1, h2, h3);
                        helper.day = day;
                        helper.month = month;
                        helper.year = year;
                        list_for_dates.append(helper);
                        help_string = nullptr;
                    }
                }
                qDebug() << "Прочитано из файла:" << line;
            }
            file.close();
        } else {
            qWarning() << "Не удалось открыть файл для чтения.";
        }
    }
    else {
        qDebug() << "Файл не выбран.";
    }

    ui->tableWidget->setRowCount(list_for_dates.size());

    QString str = nullptr;
    for (int i = 0; i< list_for_dates.size(); i++)
    {
        Date kluch = list_for_dates[i];
        if (kluch.day <= 9) str+= "0";
        str += QString::number(kluch.day);
        str +=".";
        if (kluch.month <= 9) str+= "0";
        str += QString::number(kluch.month);
        str +=".";
        if (kluch.year <= 9) str+= "0";
        str += QString::number(kluch.year);

        QTableWidgetItem *item1 = new QTableWidgetItem(str);
        item1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, item1);
        str = QString::number(kluch.WeekNumber());

        QTableWidgetItem *item2 = new QTableWidgetItem(str);
        item2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, item2);
        if (kluch.isLeap()) str = "IsLeap";
        else str = "NotLeap";

        QTableWidgetItem *item3 = new QTableWidgetItem(str);
        item3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 2, item3);

        str = kluch.NextDay();
        QTableWidgetItem *item4 = new QTableWidgetItem(str);
        item4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 3, item4);

        QDate date = QDate::currentDate();
        int current_day = date.day(), current_month = date.month(), current_year = date.year();
        Date class_current_date;
        class_current_date.day = current_day;
        class_current_date.month = current_month;
        class_current_date.year = current_year;

        str = QString::number(kluch.Duration(kluch, class_current_date));
        QTableWidgetItem *item5 = new QTableWidgetItem(str);
        item5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 4, item5);


        Date class_for_duration;
        if (i < list_for_dates.size()-1)
        {
            class_for_duration.day = list_for_dates[i+1].day;
            class_for_duration.month = list_for_dates[i+1].month;
            class_for_duration.year = list_for_dates[i+1].year;
            str = QString::number(kluch.Duration(class_for_duration, kluch));
        }
        else str = "-1";
        QTableWidgetItem *item6 = new QTableWidgetItem(str);
        item6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 5, item6);

        str = nullptr;
    }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Что-то пошло не так");
        msgBox.setWindowTitle("Предупреждение");
        msgBox.exec();
    }

}

