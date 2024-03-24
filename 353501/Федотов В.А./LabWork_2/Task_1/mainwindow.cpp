#include "mainwindow.h"

#include "date.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>
#include <algorithm>
#include <qaction.h>
#include <qdebug.h>
#include <qheaderview.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <stdexcept>

MainWindow::MainWindow() : ui(new Ui::MainWindow) { //week number
  ui->setupUi(this);
  
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::refreshFile);
    connect(ui->bdayDateEdit, &QDateEdit::userDateChanged, this,&MainWindow::setBday);
    connect(ui->tableWidget, &QTableWidget::itemClicked, this,&MainWindow::handleTableRowClicked);

    connect(ui->daySpinBox, &QSpinBox::valueChanged, this, &MainWindow::setDay);
    connect(ui->monthSpinBox, &QSpinBox::valueChanged, this, &MainWindow::setMonth);
    connect(ui->yearSpinBox, &QSpinBox::valueChanged, this, &MainWindow::setYear);

    connect(ui->addDateButton, &QPushButton::pressed, this, &MainWindow::addDate);

    Date today = Date::today();
    ui->todayValueLabel->setText(Date::dateToString(today));
    ui->tillBdayValueLabel->setText(today.tillBday(bday));
    ui->removeDateButton->hide();
}

void MainWindow::openFile() {
    fileName = QFileDialog::getOpenFileName(
        this, "Open File", "/home/marahetters/OAIP", "Text Files (*.txt)");
    
    if (fileName.isEmpty())
      return;

    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

    readFile();
    populateTable(dates);
}

void MainWindow::refreshFile() {
    readFile();
}

void MainWindow::readFile() {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qDebug() << "Failed to open the file.";
      return;
    }

    dates.clear(); 

    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line = in.readLine();
      QStringList words = line.split(' ', Qt::SkipEmptyParts);

      for (const QString &word : words) {
        try {
          Date date = Date::stringToDate(word);
          dates.append(date);
        } catch (const std::exception &e) {
          QMessageBox::critical(nullptr, "Error", "File data is not correct");
          dates.clear();
          qDebug() << "Error: " << e.what();
          return;
        }
      }
    }

    file.close();
    populateTable(dates);
}

void MainWindow::addToFile(QString date) {
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
      qDebug() << "Failed to open the file.";
      return;
    }

    QTextStream out(&file);
    out << date << "\n";
    file.close();
    readFile();
}

void MainWindow::editFile(QString edit) {
    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek((index)*11 * sizeof(char));
    fileStream << edit << "\n";
    file.close();
    readFile();
}

void MainWindow::addDate() {
    Date date{new_day, new_month, new_year};

    if (!date.isDateValid()) {
      QMessageBox::critical(nullptr, "Error", "Date is incorrect");
      return;
    }

    if (!file.isOpen()) {
      QMessageBox::critical(nullptr, "Error", "No file is currently opened");
      return;
    }

    addToFile(Date::dateToString(date));
}

void MainWindow::populateTable(const QVector<Date> &dates) {
    ui->tableWidget->setRowCount(dates.size());
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Date", "Next Day", "Previous Day", "To Birthday", "Days to next date"});

    for (int i = 0; i < dates.size(); i++) {
        Date date = dates.at(i);
        Date nextDate = dates.at((i + 1) % dates.size());
        
        QTableWidgetItem *dateItem = new QTableWidgetItem(Date::dateToString(date));
        QTableWidgetItem *nextDayItem = new QTableWidgetItem(Date::dateToString(date.nextDay()));
        QTableWidgetItem *toBdayItem = new QTableWidgetItem(QString::number(Date::duration(date, bday)));
        QTableWidgetItem *durationItem = new QTableWidgetItem(QString::number(Date::duration(date, nextDate)));
        QTableWidgetItem *prevDayItem;
        if (Date::dateToString(date.previousDay()) == Date::dateToString(date)) {
          prevDayItem = new QTableWidgetItem("None");
        } else {
          prevDayItem = new QTableWidgetItem(Date::dateToString(date.previousDay()));
        }

        ui->tableWidget->setItem(i, 0, dateItem);
        ui->tableWidget->setItem(i, 1, nextDayItem);
        ui->tableWidget->setItem(i, 2, prevDayItem);
        ui->tableWidget->setItem(i, 3, toBdayItem);
        ui->tableWidget->setItem(i, 4, durationItem);

        dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsEditable);
        nextDayItem->setFlags(nextDayItem->flags() & ~Qt::ItemIsEditable);
        prevDayItem->setFlags(prevDayItem->flags() & ~Qt::ItemIsEditable);
        toBdayItem->setFlags(toBdayItem->flags() & ~Qt::ItemIsEditable);
        durationItem->setFlags(durationItem->flags() & ~Qt::ItemIsEditable);
    }
    column_count = ui->tableWidget->columnCount();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(column_count -1, QHeaderView::Stretch );
}

void MainWindow::setBday(QDate date) {
    bday.setDay(date.day());
    bday.setMonth(date.month());
    bday.setYear(date.year());

    for (int i = 0; i < dates.size(); i++) {
        QTableWidgetItem *toBdayItem =
            new QTableWidgetItem(QString::number(Date::duration(dates.at(i), bday)));
        ui->tableWidget->setItem(i, 3, toBdayItem);
    }

    Date today = Date::today();
    ui->todayValueLabel->setText(Date::dateToString(today));
    ui->tillBdayValueLabel->setText(today.tillBday(bday));
}

void MainWindow::handleTableRowClicked(QTableWidgetItem* item) {
    index = item->row();
    int column = item->column();
    Date date = dates[index];

    ui->daySpinBox->setValue(date.day());
    ui->monthSpinBox->setValue(date.month());
    ui->yearSpinBox->setValue(date.year());

    Date labelValDate = date; 
    ui->weekdayValueLabel->setText(Date::weekdayToString(labelValDate.dayOfWeek()));
    ui->weekNumValueLabel->setText(QString::number(labelValDate.weekNumber()));
    ui->durationLabel->setText(QString::number(Date::duration(labelValDate, Date::today())));
    
    connect(ui->applyChangesButton, &QPushButton::pressed, this, &MainWindow::editDate);
}

void MainWindow::editDate() {
  
    Date newDate{ui->daySpinBox->value(), ui->monthSpinBox->value(),ui->yearSpinBox->value()};

    if (!newDate.isDateValid()) {
      QMessageBox::critical(nullptr, "Error", "Date is incorrect");
      return;
    }

    editFile(Date::dateToString(newDate));
}

void MainWindow::setDay(int day) { new_day = day; }
void MainWindow::setMonth(int month) { new_month = month; }
void MainWindow::setYear(int year) { new_year = year; }

