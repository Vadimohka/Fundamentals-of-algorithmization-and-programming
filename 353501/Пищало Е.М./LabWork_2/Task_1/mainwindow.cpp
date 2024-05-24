#include "mainwindow.h"
#include "ui_mainwindow_2.h"
#include <QDebug>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->open, &QPushButton::clicked, this, &MainWindow::openFile);

    ui->currentDa->setText(QDate::currentDate().toString("dd.MM.yyyy"));

    connect(ui->confirmBirthdayDate, &QPushButton::clicked, this, &MainWindow::setBirthdayDate);

    connect(ui->add_date, &QPushButton::clicked, this, &MainWindow::on_addDate_clicked);

    connect(ui->table, &QTableWidget::itemClicked, this,&MainWindow::handleTableRowClicked);
    ui->table->setColumnCount(6);

}

void MainWindow::handleTableRowClicked(QTableWidgetItem* item) {

    index = item->row();

    connect(ui->change, &QPushButton::pressed, this, &MainWindow::editDate);

}

void MainWindow::editDate() {

    Date newDate =  Date(ui->changeDate->date().day(), ui->changeDate->date().month(), ui->changeDate->date().year());

    myDatesVector[index] = newDate;

    QTableWidgetItem *newItem = new QTableWidgetItem(newDate.str());
    ui->table->setItem(index,0,newItem);

    QTableWidgetItem *newItemNextDay = new QTableWidgetItem(newDate.NextDay().str());
    ui->table->setItem(index,1,newItemNextDay);

    QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(newDate.PreviousDay().str());
    ui->table->setItem(index,2,newItemPreviousDay);

    QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(newDate.WeekNumber()));
    ui->table->setItem(index,3,newItemWeekNumber);

    QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( newDate.Duration(newDate) ) );
    ui->table->setItem(index,4,newItemDuration);

    QTableWidgetItem *newItemIsLeap = new QTableWidgetItem(newDate.IsLeap() ? "Yes" : "No");
    ui->table->setItem(index,5,newItemIsLeap);

    setDurations();

    editFile(index, newDate.str());
}

void MainWindow::editFile(int index, QString edit) {
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek((index)* 11 * sizeof(char));
    fileStream << edit << "\n";
    file.close();
}
void MainWindow::on_savefile_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Сохранение"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    int row = ui->table->rowCount();

    for (int i = 0;i< row;i++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(ui->table->item(i,0)->text());
        out << itm->text() << '\n';
    }
    file.close();

}
void MainWindow::on_addDate_clicked()
{


    QString dateString = ui->addDate->text();

    if(!Date::CheckStringDate(dateString)){
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }

    int row = ui->table->rowCount();
    ui->table->insertRow(row);

    Date newDate = Date::fromString(dateString);
    myDatesVector.push_back(newDate);

    QTableWidgetItem *newItem = new QTableWidgetItem(newDate.str());
    ui->table->setItem(row,0,newItem);

    QTableWidgetItem *newItemNextDay = new QTableWidgetItem(newDate.NextDay().str());
    ui->table->setItem(row,1,newItemNextDay);

    QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(newDate.PreviousDay().str());
    ui->table->setItem(row,2,newItemPreviousDay);

    QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(newDate.WeekNumber()));
    ui->table->setItem(row,3,newItemWeekNumber);

    QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( newDate.Duration(newDate) ) );
    ui->table->setItem(row,4,newItemDuration);

    QTableWidgetItem *newItemIsLeap = new QTableWidgetItem(newDate.IsLeap() ? "Yes" : "No");
    ui->table->setItem(row,5,newItemIsLeap);

    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << newItem->text()<<'\n';
    setDurations();
    ui->table->update();
}

void MainWindow::setBirthdayDate(){
    QDate Qtoday = Qtoday.currentDate();
    Date today = Date(Qtoday.day(),  Qtoday.month(), Qtoday.year());

    Date birthdayDate = Date(ui->dateEdit->date().day(), ui->dateEdit->date().month(), Qtoday.year());

    ui->DaysLeft->setText( QString::number( today.DaysTillYourBithday(birthdayDate) ) );

}

void MainWindow::openFile(){

    path = QFileDialog::getOpenFileName();

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    };

    QTextStream in (&file);

    while(!in.atEnd()){
        QString DateString = in.readLine();

        if(!Date::CheckStringDate(DateString)){
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
            break;
        }

        Date date = Date::fromString(DateString);
        myDatesVector.push_back(date);

        ui->table->insertRow(ui->table->rowCount());

        QTableWidgetItem *newItem = new QTableWidgetItem(DateString);
        ui->table->setItem(ui->table->rowCount() - 1,0, newItem);

        QTableWidgetItem *newItemNextDay = new QTableWidgetItem(date.NextDay().str());
        ui->table->setItem(ui->table->rowCount() - 1,1,newItemNextDay);

        QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(date.PreviousDay().str());
        ui->table->setItem(ui->table->rowCount() - 1,2,newItemPreviousDay);

        QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(date.WeekNumber()));
        ui->table->setItem(ui->table->rowCount() - 1,3,newItemWeekNumber);

        QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( date.Duration(date) ) );
        ui->table->setItem(ui->table->rowCount() - 1,4,newItemDuration);

        QTableWidgetItem *newItemIsLeap = new QTableWidgetItem(date.IsLeap() ? "Yes" : "No");
        ui->table->setItem(ui->table->rowCount() - 1,5,newItemIsLeap);

    }

    setDurations();

    file.close();

}
void MainWindow::setDurations(){
    int row = 0;
    /*for(auto date = myDatesVector.begin(); date != myDatesVector.end(); ++date){
        auto nextDate = *std::next(date);
        if(std::next(date) != myDatesVector.end()){
            QTableWidgetItem *DurationThisAndNext = new QTableWidgetItem( QString::number( date->duration(*date, nextDate) ) );
            ui->table->setItem(row, 5, DurationThisAndNext);
        }
        row++;
    }*/
}


