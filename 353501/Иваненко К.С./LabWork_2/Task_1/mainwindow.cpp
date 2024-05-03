#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectfilebutton, SIGNAL(pressed()), this, SLOT(on_selectfilebutton_clicked()));
    connect(ui->bdateEdit, SIGNAL(pressed()), this, SLOT(on_bdateEdit_userDateChanged(QDate)));
    // connect(ui->adddate, SIGNAL(pressed()), this, SLOT(on_adddateEdit_userDateChanged(QDate)));
    connect(ui->spintable, SIGNAL(pressed()), this, SLOT(on_spintable_valueChanged(int)));
    connect(ui->changedate, SIGNAL(pressed()), this, SLOT(on_changedate_clicked()));
    QDate currdate = QDate::currentDate();
    QString s = currdate.toString("dd.MM.yyyy");
    ui->label_6->setText(s);

    ui->day->setValue(1);
    ui->month->setValue(1);
    ui->year->setValue(1);

}
QString tost(QDate a)
{
    QString st;
    int dayn = a.day();
    int m = a.month();
    int y = a.year();
    st = QString::number(dayn) + "." + QString::number(m) + "." + QString::number(y);
    return st;
}
Date toDate(QDate a)
{
    return Date(a.day(), a.month(), a.year());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatetable()
{
    int cnt = 0;
    file.open(QIODevice::ReadOnly | QIODeviceBase::WriteOnly);

    QString s;

    QString sline;

    while (!file.atEnd())
    {
        s = "";
        sline = file.readLine();
        // qDebug() << " line : " << sline;
        for (int i = 0; i <= sline.length() - 1; i++)
        {

            // qDebug() << sline[i];
            if (sline[i] == ' ' || sline[i] == '\xd' || sline[i] == '\xa')
            {

                if (s.length() < 7)
                {
                    continue;
                }
                if (s.length() > 10)
                {

                    s.remove(11, s.length() - 10);
                    qDebug() << s;
                }
                // qDebug() << s << " to array";
                dates[cnt] = QDate::fromString(s, "dd.MM.yyyy");
                cnt++;
                s = "";
                continue;
            }
            s += sline[i];
        }
    }
    cnt--;
    // qDebug() << "s ost = " << s;
    if (s.length() > 8)
    {
        cnt++;
        // qDebug() << "case1";
        s.remove(10, s.length() - 10);
        dates[cnt] = QDate::fromString(s, "dd.MM.yyyy");
    }
    cnt2 = cnt;
    // qDebug() << "cnt = " << cnt;
    // dates[cnt] = QDate::fromString(s,"d.M.yyyy");
    for (int i = 0; i <= cnt; i++)
    {
        dates2[i] = toDate(dates[i]);
    }
    ui->tableWidget->setRowCount(cnt + 1);
    ui->tableWidget->setColumnCount(4);
    for (int i = 0; i <= cnt; i++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tost(dates[i]));
        ui->tableWidget->setItem(i, 0, itm);
    }
    // qDebug()<<"next date: \n";
    for (int i = 0; i <= cnt; i++)
    {
        // dates2[i].nextday().showinfo();
        QTableWidgetItem *itm = new QTableWidgetItem(tost(dates2[i].nextday().toQDate()));
        ui->tableWidget->setItem(i, 1, itm);
    }
    for (int i = 0; i <= cnt; i++)
    {
        QTableWidgetItem *itm;
        if (dates2[i].prevday().toQDate() != QDate(0,0,0))
        itm = new QTableWidgetItem(tost(dates2[i].prevday().toQDate()));
        else
        itm = new QTableWidgetItem(QString("--.--.----"));
        ui->tableWidget->setItem(i, 2, itm);
    }
    // QDate currentday = QDate::currentDate();
    for (int i = 0; i <= cnt; i++)
    {
        // qDebug()<<dates2[i].duration(toDate(currentday))<<"\n";
        QTableWidgetItem *itm;
        QDate currdate = QDate::currentDate();
        itm = new QTableWidgetItem(QString::number(dates2[i].duration(toDate(currdate))));
        ui->tableWidget->setItem(i, 3, itm);
    }

    for (int i = 0; i <= cnt; i++)
    {
        // qDebug() << "massive";
        // qDebug() << dates[i].day() << "." << dates[i].month() << "." << dates[i].year();
    }
    // qDebug()<<bday.day()<<"..."<<bday.month()<<"..."<<bday.year();
    file.close();
}

void MainWindow::on_selectfilebutton_clicked()
{
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Выберете файл (поддерживаются только .txt)")));
    QMessageBox bruh;

    if (!file.exists())
    {

        bruh.setWindowTitle("Warning!");
        bruh.setInformativeText(
            "error 228");
        bruh.setText("Something wrong...");
        bruh.exec();
    }
    else
    {

        file.open(QIODeviceBase::ReadOnly);
        QString s = file.readAll();
        // qDebug() << "string::" << s;
        bool ans;
        for (int i = 0; i < s.length(); i++)
        {
            // qDebug() << s[i];
            if (s[i] == '\r' || s[i] == '\n' || (s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '.')
            {
                ans = 1;
            }
            else
            {
                ans = 0;
                break;
            }
        }
        if (s == "")
        {
            ans = 1;
        }
        chk = ans;
        file.close();
        if (!ans)
        {

            bruh.setWindowTitle("Warning!");
            bruh.setText("All's ok.");
            bruh.exec();
            updatetable();
        }
        updatetable();
    }
}
void MainWindow::on_bdateEdit_userDateChanged(const QDate &date)
{
    bday = date;
    QDate cur = QDate::currentDate();
    Date date2 = toDate(bday);
    int n = toDate(cur).daystillmybday(date2);
    QString s = QString::number(n % 356);
    ui->label_3->setText(s);
    updatetable();
}

void MainWindow::on_day_valueChanged(int arg1) {
    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    aday = arg1;
}

void MainWindow::on_month_valueChanged(int arg1) {
    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    amonth = arg1;
    if (amonth == 2 && ((ayear % 4 == 0 && ayear % 100 != 0) || ayear % 400 == 0)) ui->day->setMaximum(29);
    if (amonth == 2 && !((ayear % 4 == 0 && ayear % 100 != 0) || ayear % 400 == 0)) ui->day->setMaximum(28);
    if (amonth == 1 || amonth == 3 || amonth == 5 || amonth == 7 || amonth == 8 || amonth == 10 || amonth == 12) ui->day->setMaximum(31);
    if (amonth == 4 || amonth == 6 || amonth == 9 || amonth == 11) ui->day->setMaximum(30);
    if (amonth < 1) amonth = 1;
}

void MainWindow::on_year_valueChanged(int arg1) {
    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    ayear = arg1;
    if (amonth == 2 && ((ayear % 4 == 0 && ayear % 100 != 0) || ayear % 400 == 0)) ui->day->setMaximum(29);
    if (amonth == 2 && !((ayear % 4 == 0 && ayear % 100 != 0) || ayear % 400 == 0)) ui->day->setMaximum(28);
    if (amonth == 1 || amonth == 3 || amonth == 5 || amonth == 7 || amonth == 8 || amonth == 10 || amonth == 12) ui->day->setMaximum(31);
    if (amonth == 4 || amonth == 6 || amonth == 9 || amonth == 11) ui->day->setMaximum(30);
    if (ayear > 10000) ayear = 1;

}

void MainWindow::on_adddate_clicked()
{

    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning!");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Append);

    QTextStream stream(&file);

    // qDebug() << " bruh " << cnt2 * 10 + cnt2 - 1;

    if (aday < 10) stream << "0";
    if (aday < 1) aday = 1;
    stream << aday << ".";
    if (amonth < 10) stream << "0";
    if (amonth < 1 || amonth > 12) amonth = 1;
    stream << amonth << ".";
    if (ayear > 11000) ayear = 1;
    if (ayear < 10) stream << "000"; else
    if (ayear < 100) stream << "00"; else
    if (ayear < 1000) stream << "0";
    stream << ayear << " ";

    file.close();
    updatetable();
}

void MainWindow::on_spintable_valueChanged(int arg1)
{
    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning!");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    if (arg1 < 1 || arg1 > cnt2 + 1)
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning!");
        bruh.setInformativeText(
            "error 69");
        bruh.setText("Choose correct row.");
        bruh.exec();
        return;
    }
    toChange = arg1;
}

void MainWindow::on_changedate_clicked()
{
    if (!file.exists())
    {
        QMessageBox bruh;
        bruh.setWindowTitle("Warning!");
        bruh.setInformativeText(
            "error 1337");
        bruh.setText("Please, select file firstly.");

        bruh.exec();
        return;
    }
    if (!toChange)
    {
        return;
    }
    if (toChange > cnt2 + 1)
    {
        return;
    }
    std::string debug;

    file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Text);
    QString bigdebug;

    bigdebug = file.readAll();
    // qDebug() << "big debug: " << bigdebug;
    debug = bigdebug.toStdString();

    QString input = adate.toString("dd.MM.yyyy");
    QTextStream bebra(&file);

    bebra.seek((toChange - 1) * 10 + 2 * (toChange - 1));

    bebra << input;
    file.close();
    updatetable();
}