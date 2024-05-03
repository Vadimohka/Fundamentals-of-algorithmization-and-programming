#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setColumnCount(5);
    ui->calendar->hide();
    ui->calendaredit->hide();
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDate( QString date)
{
    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day+=date[i];
        }

        if(i > 2 && i < 5)
        {
            Month+=date[i];
        }

        if(i > 5)
        {
            Year+=date[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date dateline(year,month,day);
    days.push_back(dateline);
}
void MainWindow::on_openfilebutton_clicked()
{

    pathToFile = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), tr("TXT файл (*.txt)"));
    file.setFileName(pathToFile);
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    QTextStream fileStream(&file);
    //file.close();
    FromFiletoarr();
}
void MainWindow::FromFiletoarr()
{
    if (pathToFile.isEmpty())
        return;

    file.setFileName(pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Обработка ошибки открытия файла
        return;
    }

    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty()) {
            // Remove the trailing backslash character
            if (s.endsWith('\\')) {
                s.chop(1);
            }
            if (checkstr(s)) {
                addDate(s);
            } else {
                QMessageBox::warning(this, "Warning", "Wrong data");
                ui->table->setRowCount(0);
                return;
            }
        }
    } while (!fileStream.atEnd());
    ui->table->setRowCount(days.size());
    for (int i = 0; i < days.size(); ++i) {
        QTableWidgetItem* itm0 = new QTableWidgetItem(days[i].fromDateToString());
        ui->table->setItem(i, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(days[i].nextDay().fromDateToString());
        ui->table->setItem(i, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(days[i].previousDay().fromDateToString());
        ui->table->setItem(i, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(days[i].duration(days[i]));
        ui->table->setItem(i, 3, itm3);

        if(i < days.size() - 1){
        QTableWidgetItem* itm4 = new QTableWidgetItem(days[i].durationnextandthis(days[i + 1]));
        ui->table->setItem(i, 4, itm4);
        }else{
            //QTableWidgetItem* itm4 = new QTableWidgetItem(0);
            ui->table->setItem(i, 4, 0);
        }
    }

    file.close();
}

void MainWindow::EditFile(int ind,QString edit)
{
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek((index) * 11 * sizeof(char));
    fileStream << edit << "\n";
    file.close();
}
bool MainWindow::checkstr(QString date){
    if ((date[2] != '-' && date[2] != '.') || (date[5] != '-' && date[5] != '.') || date.length() != 10)
    {
        return false;
    }

    for(int i = 0; i < date.length(); ++i)
    {
        if ((date[i] > '9' || date[i] < '0') && (date[i] != '-' && date[i] != '.'))
        {
            return false;
        }
    }

    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day+=date[i];
        }

        if(i > 2 && i < 5)
        {
            Month+=date[i];
        }

        if(i > 5)
        {
            Year+=date[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date dateline(year,month,day);

    if (month > 12 || day > 31 || month < 0 || day< 0 || year > 9999 || year < 0)
    {
        return false;
    }

    if (!dateline.is_Leap() && month == 2 && day > 28)
    {
        return false;
    }

    if (dateline.is_Leap() && month == 2 && day > 29)
    {
        return false;
    }

    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        return false;
    }

    return true;
}


void MainWindow::on_coundaysbut_clicked()
{

    QString bd = ui->lineEdit->text();
    if(!checkstr(bd)){
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }
    QDate today = today.currentDate();
    Date td = Date(today.year(),today.month(),today.day());

    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day += bd[i];
        }

        if(i > 2 && i < 5)
        {
            Month += bd[i];
        }

        if(i > 5)
        {
            Year += bd[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date bdtodate(year,month,day);
    QString resultstr = QString::number(td.daysTillYourBithday(bdtodate));
    ui->daysoutputlabel->setText(resultstr);

}


void MainWindow::on_pushButton_clicked()
{
    ui->calendar->show();
}


void MainWindow::on_calendar_clicked(const QDate &date)
{
    QString dat = date.toString("dd.MM.yyyy");
    addDate(dat);
    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day += dat[i];
        }

        if(i > 2 && i < 5)
        {
            Month += dat[i];
        }

        if(i > 5)
        {
            Year += dat[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date da(year,month,day);
    int row = ui->table->rowCount();
    ui->table->insertRow(row);

    QTableWidgetItem* itm0 = new QTableWidgetItem(da.fromDateToString());
    ui->table->setItem(row, 0, itm0);

    QTableWidgetItem* itm1 = new QTableWidgetItem(da.nextDay().fromDateToString());
    ui->table->setItem(row, 1, itm1);

    QTableWidgetItem* itm2 = new QTableWidgetItem(da.previousDay().fromDateToString());
    ui->table->setItem(row, 2, itm2);

    QTableWidgetItem* itm3 = new QTableWidgetItem(da.duration(da));
    ui->table->setItem(row, 3, itm3);
    if(row < days.size() - 1){
        QTableWidgetItem* itm4 = new QTableWidgetItem(days[row].durationnextandthis(days[row + 1]));
        ui->table->setItem(row, 4, itm4);
    }else{
        //QTableWidgetItem* itm4 = new QTableWidgetItem(0);
        ui->table->setItem(row, 4, 0);
    }
    if(row > 0){
        QTableWidgetItem* itm6 = new QTableWidgetItem(days[row - 1].durationnextandthis(days[row]));
        ui->table->setItem(row - 1, 4, itm6);
    }
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << dat << "\n";
        file.close();
    }
    ui->table->update();
    ui->calendar->hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    index = ui->table->currentRow();
    ui->calendaredit->show();
}


void MainWindow::on_calendaredit_clicked(const QDate &date)
{
    QString dat = date.toString("dd.MM.yyyy");
    QString Day, Month, Year;
    for(int i = 0; i < 10; i++)
    {
        if(i>-1 && i<2)
        {
            Day += dat[i];
        }

        if(i > 2 && i < 5)
        {
            Month += dat[i];
        }

        if(i > 5)
        {
            Year += dat[i];
        }
    }

    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date da(year,month,day);
    days[index] = da;
    QTableWidgetItem* itm0 = new QTableWidgetItem(da.fromDateToString());
    ui->table->setItem(index, 0, itm0);

    QTableWidgetItem* itm1 = new QTableWidgetItem(da.nextDay().fromDateToString());
    ui->table->setItem(index, 1, itm1);

    QTableWidgetItem* itm2 = new QTableWidgetItem(da.previousDay().fromDateToString());
    ui->table->setItem(index, 2, itm2);

    QTableWidgetItem* itm3 = new QTableWidgetItem(da.duration(da));
    ui->table->setItem(index, 3, itm3);
    if(index < days.size() - 1){
        QTableWidgetItem* itm4 = new QTableWidgetItem(days[index].durationnextandthis(days[index + 1]));
        ui->table->setItem(index, 4, itm4);
    }else{
        ui->table->setItem(index, 4, 0);
    }
    if(index > 0){
        QTableWidgetItem* itm6 = new QTableWidgetItem(days[index - 1].durationnextandthis(days[index]));
        ui->table->setItem(index - 1, 4, itm6);
    }
    ui->calendaredit->hide();
    EditFile(index,dat);
}

