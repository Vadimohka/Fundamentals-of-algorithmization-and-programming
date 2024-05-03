#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->open, &QPushButton::clicked, this, &MainWindow::openFile);
 
  ui->currentDate->setText(QDate::currentDate().toString("dd.MM.yyyy"));

  connect(ui->confirmBirthdayDate, &QPushButton::clicked, this, &MainWindow::setBirthdayDate);

  connect(ui->add_date, &QPushButton::clicked, this, &MainWindow::on_addDate_clicked);

  connect(ui->tableWidget, &QTableWidget::itemClicked, this,&MainWindow::handleTableRowClicked);

}

void MainWindow::handleTableRowClicked(QTableWidgetItem* item) {
    index = item->row();

    connect(ui->change, &QPushButton::pressed, this, &MainWindow::editDate);
}

void MainWindow::editDate() {
  
    Date newDate = Date(ui->changeDate->date().day(), ui->changeDate->date().month(), ui->changeDate->date().year());

    myDatesVector[index] = newDate;

    QTableWidgetItem *newItem = new QTableWidgetItem(newDate.dateToString());
    ui->tableWidget->setItem(index,0,newItem);

    QTableWidgetItem *newItemNextDay = new QTableWidgetItem(newDate.nextDay().dateToString());
    ui->tableWidget->setItem(index,1,newItemNextDay);

    QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(newDate.PreviousDay().dateToString());
    ui->tableWidget->setItem(index,2,newItemPreviousDay);

    QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(newDate.weekNumber()));
    ui->tableWidget->setItem(index,3,newItemWeekNumber);

    QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( newDate.Duration(newDate) ) );
    ui->tableWidget->setItem(index,4,newItemDuration);

    setDurations();

    editFile(index, newDate.dateToString());
}

void MainWindow::editFile(int index, QString edit) {
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek((index)* 11 * sizeof(char));
    fileStream << edit << "\n";
    file.close();
}

void MainWindow::on_addDate_clicked()
{


    QString dateString = ui->addDate->text();

    if(!Date::CheckStringDate(dateString)){
          QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
          return;
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    Date newDate = Date::fromString(dateString);
    myDatesVector.push_back(newDate);

    QTableWidgetItem *newItem = new QTableWidgetItem(newDate.dateToString());
    ui->tableWidget->setItem(row,0,newItem);

    QTableWidgetItem *newItemNextDay = new QTableWidgetItem(newDate.nextDay().dateToString());
    ui->tableWidget->setItem(row,1,newItemNextDay);

    QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(newDate.PreviousDay().dateToString());
    ui->tableWidget->setItem(row,2,newItemPreviousDay);

    QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(newDate.weekNumber()));
    ui->tableWidget->setItem(row,3,newItemWeekNumber);

    QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( newDate.Duration(newDate) ) );
    ui->tableWidget->setItem(row,4,newItemDuration);

    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << newItem->text()<<'\n';
    setDurations();
    ui->tableWidget->update();
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
    
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    QTableWidgetItem *newItem = new QTableWidgetItem(DateString);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,0,newItem);

    QTableWidgetItem *newItemNextDay = new QTableWidgetItem(date.nextDay().dateToString());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,1,newItemNextDay);

    QTableWidgetItem *newItemPreviousDay = new QTableWidgetItem(date.PreviousDay().dateToString());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,2,newItemPreviousDay);

    QTableWidgetItem *newItemWeekNumber = new QTableWidgetItem(QString::number(date.weekNumber()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,3,newItemWeekNumber);

    QTableWidgetItem *newItemDuration = new QTableWidgetItem( QString::number( date.Duration(date) ) );
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,4,newItemDuration);

  }

  setDurations();

  file.close();  

}

void MainWindow::setDurations(){
  int row = 0;
  for(auto date = myDatesVector.begin(); date != myDatesVector.end(); ++date){
    auto nextDate = *std::next(date);
    if(std::next(date) != myDatesVector.end()){
      QTableWidgetItem *DurationThisAndNext = new QTableWidgetItem( QString::number( date->Duration(*date, nextDate) ) );
      ui->tableWidget->setItem(row ,5,DurationThisAndNext);
    }
    row++;
  }
}
