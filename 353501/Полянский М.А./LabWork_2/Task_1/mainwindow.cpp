#include <QDateEdit>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <exception>
#include <qdatetimeedit.h>
#include <qerrormessage.h>
#include <qlogging.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <stdexcept>
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(): ui(new Ui::MainWindow) { 
    selRow = -1;
  ui->setupUi(this);
  ui->tableWidget->setColumnWidth(0, 100);
  ui->tableWidget->setColumnCount(1);
  connect(ui->open, &QPushButton::clicked, this, &MainWindow::onOpenClick);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addNew);
  connect(ui->editbut, &QPushButton::clicked, this, &MainWindow::edit);
  connect(ui->deletebut, &QPushButton::clicked, this, &MainWindow::deleteRow);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::selectRow);
    updateInfo();
}


void MainWindow::onNewClick() {
    
    QString fileName = QFileDialog::getSaveFileName(this, "New File", "", tr("Text files (*.txt)"));
    if (fileName.isEmpty())
        return;

    try {
        
        if (file) {
            file->close();
            delete file;
            file = nullptr;
        }

       
        file = new QFile(fileName, this);
        if (!file) {
            QMessageBox::critical(this, "Failed to create file", "Failed to allocate memory for file.");
            return;
        }

        // Open the file for read/write
        if (!file->open(QFile::ReadWrite)) {
            QMessageBox::critical(this, "Failed to create file", "Failed to open file for read/write.");
            delete file;
            file = nullptr;
            return;
        }

        // Update the table
        updateTable();
    } catch (std::exception &e) {
        QMessageBox::critical(this, "Failed to create file", QString("Failed to create file:\n%0").arg(e.what()));
    }
}


void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(datesList.count());

    for (int i = 0; i < datesList.count(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(datesList[i].toString());
        ui->tableWidget->setItem(i, 0, item);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }
}

void MainWindow::onOpenClick() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", tr("Text files (*.txt)"));
    if (fileName.isEmpty())
        return;

    if (file) {
        file->close();
        delete file;
        file = nullptr;
    }

    file = new QFile(fileName, this);

    try {
        file->open(QFile::ReadWrite);

        QByteArray contents = file->readAll();
        loadFile(contents);
    } catch (std::exception &e) {
        QMessageBox::critical(this, "Failed to load file", QString("Failed to load file:\n%0").arg(e.what()));
    }
}

void MainWindow::selectRow() {
  auto selected = ui->tableWidget->selectedItems();
  if (selected.count() > 0) {
     selRow = selected[0]->row();
  } else {
    selRow = -1;
  }

    updateInfo();
}


void MainWindow::loadFile(QByteArray contents) {
    datesList.clear();
    if (contents.length() == 0)
        return;

    int pos = 0;
    while (pos < contents.length()) {
        if (contents[pos] == ' ' || contents[pos] == '\n' || contents[pos] == '\t') {
            pos++;
        } else {
            if (pos + 10 > contents.length())
                throw std::invalid_argument("Not enough file");

            QByteArray dateBytes = contents.mid(pos, 10);
            std::string dateString = dateBytes.toStdString();
            Date date = Date::FromString(dateString);
            datesList.append(date);
            filePos.append(pos);

            pos += 10;
        }
    }   

    updateTable();
}


void MainWindow::getRow() {
    bool norm = false;
    int row = 0;

    while (!norm) {
        row = QInputDialog::getInt(this, "Enter Row", "Enter the row number:", 0, 0, datesList.size() - 1, 1, &norm);
        if (!norm) {
            
            return;
        }
        
        if (row >= 0 && row < datesList.size()) {
            norm = true;
        } else {
            QMessageBox::warning(this, "Invalid Row", "Please enter a valid row number.");
        }
    }
    
    selRow = row;
    
}


void MainWindow::addNew() {
    bool norm =true;

   
    Date today = Date::today();

    QString newDateS = QInputDialog::getText(this, "Add entry", "New date:", QLineEdit::Normal, today.toString(), &norm);
    if (!norm)
        return;

    try {
        
        Date newDate = Date::stringToDate(newDateS);

        // Add the new date to the list
        datesList.push_back(newDate);

       
        ui->tableWidget->setRowCount(datesList.count());
        updateTable();

        
        if (file) {
            file->seek(file->size());
            filePos.push_back(file->size() + 1);
            file->write(QString("\n" + newDate.toString()).toUtf8());
            file->flush();
        }
    } catch (std::exception &e) {
        QMessageBox::critical(this, "Failed to add entry", QString("Failed to add entry:\n%0").arg(e.what()));
    }
}

void MainWindow::updateRow(int row){
    if (row < 0 || row >= ui->tableWidget->rowCount())
        return;

    const Date& date = datesList[row];
    QString dateString = Date::dateToString(date);

    QTableWidgetItem* item = ui->tableWidget->item(row, 0);
    if (!item) {
        item = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 0, item);
    }

    item->setText(dateString);
}

void MainWindow::edit() {
    bool norm;
    getRow(); 
    QString newStr = QInputDialog::getText(
        this, "Edit entry", "New date:", QLineEdit::Normal,
        Date::dateToString(datesList[selRow]), &norm);

    if(!norm || selRow < 0 || selRow >= datesList.size()){
        return;
    }

    try {
        // Convert newStr to QString
        QString newDateQString = newStr;

        Date newDate = Date::stringToDate(newDateQString);
        datesList[selRow] = newDate;

        if (file) {
            file->seek(filePos[selRow]);
            file->write(QByteArray::fromStdString(newDate.toString().toStdString()));
            file->flush();
        }
        updateRow(selRow);
    } catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", "Invalid date format");
    }
}

void MainWindow::deleteRow(){
    getRow();

    if (selRow < 0 || selRow >= ui->tableWidget->rowCount()) {
       
        return;
    }

    
    datesList.removeAt(selRow);
    if (file) {
        file->seek(filePos[selRow]);
        file->write("          ");
        file->flush();
        filePos.remove(selRow);
    } 
    
    ui->tableWidget->removeRow(selRow);
    updateRow(selRow - 1);

    updateTable();
    ui->tableWidget->clearSelection();
}


void MainWindow::updateInfo(){
    if(selRow >= datesList.count()){
        selRow = -1;
    }
    ui->editbut->setDisabled(selRow == -1);
    ui->deletebut->setDisabled(selRow == -1);
    Date tday = Date::today();
    Date selectedDate = selRow!= -1 ? datesList[selRow] : tday;

    ui->leap->setText(selectedDate.isLeapYear(selectedDate.year()) ? "Yes" : "No");
    ui->curday->setText(tday.toString());
    ui->weeknum->setText(QString::number(selectedDate.weekNumber()));
    ui->prev->setText(selectedDate.previousDay().toString());
    ui->next->setText(selectedDate.nextDay().toString());
}
