#include "mainwindow.h"
#include "abiturient.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>
#include <qdebug.h>
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qtablewidget.h>
#include <QJsonDocument>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // m_abiturients.push_back(Abiturient("2h2123", "iahfsdkf", 1.52, 65, 56, 58));
  // m_abiturients.push_back(Abiturient("srthtd", "dskgspeikgf", 5.4, 52, 99, 1));
  // m_abiturients.push_back(Abiturient("shrdtfd", "isegns", 2.2, 65, 85, 0));
  // m_abiturients.push_back(Abiturient("sdfgfdsfgfdfg", "sj", 10, 100, 100, 100));
  updateTable();

  connect(ui->openFile, &QPushButton::clicked, this, &MainWindow::openFile);
  connect(ui->saveFile, &QPushButton::clicked, this, &MainWindow::saveFile);
  connect(ui->pushButtonAdd, &QPushButton::clicked, this,
          &MainWindow::onAddAbiturient);
  connect(ui->pushButtonRemove, &QPushButton::clicked, this,
          &MainWindow::onDeleteAbiturient);
  connect(ui->pushButtonSearch, &QPushButton::clicked, this,
          &MainWindow::onSearchAbiturient);
  connect(ui->pushButtonSort, &QPushButton::clicked, this,
          &MainWindow::onSortByScore);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::saveFile() {
    QJsonArray arr;

    for (int i = 0; i< m_abiturients.length(); i++){
        arr.push_back(m_abiturients[i].toJson());
    }

    QJsonDocument docum(arr);
    // qDebug() << docum.toJson();
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                  tr("Json Document (*.json)"));
  if (fileName.isEmpty())
    return;

  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::critical(this, tr("Error"),
                          tr("Could not open file for writing"));
    return;
  }
    file.write(docum.toJson());
//   QTextStream out(&file);
//   // Пример записи данных: out << "Some data" << endl;

  file.close();
}

void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(m_abiturients.length());
    for(int i = 0; i<m_abiturients.length(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(m_abiturients[i].getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(m_abiturients[i].getSpecialty()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(m_abiturients[i].getAverageScore())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(m_abiturients[i].getMath())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(m_abiturients[i].getPhysics())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(m_abiturients[i].getRussian())));
    }
}

void MainWindow::onAddAbiturient() {
  // Здесь реализуйте добавление нового абитуриента
  m_abiturients.push_back(Abiturient(ui->FIO->text(), ui->Spetiality->text(), ui->ball->value(), ui->math->value(), ui->russian->value(), ui->physics->value()));
  updateTable();

}

void MainWindow::onDeleteAbiturient() {
  auto selected = ui->tableWidget->selectedItems();
  if(selected.empty()) return;
  int selectedRow = selected[0]->row();
  qDebug() << selectedRow;
  m_abiturients.remove(selectedRow);
  updateTable();
  // Здесь реализуйте удаление выбранного абитуриента
}

void MainWindow::onUpdateAbiturient() {
  // Здесь реализуйте обновление данных абитуриента
}

void MainWindow::onSortByScore() {
  // Здесь реализуйте сортировку абитуриентов по среднему баллу
  doComparison();
}

void MainWindow::onSearchAbiturient() {
  // Здесь реализуйте поиск абитуриента по ФИО
  for(int i = 0; i < m_abiturients.length(); i++){
    if(m_abiturients[i].getName().contains(ui->FIO_search->text())) {
        ui->tableWidget->selectRow(i);
    }
  }
}

// void MainWindow::displayAbiturients() {
//   // Здесь реализуйте отображение списка абитуриентов в таблице
// }

void MainWindow::openFile() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                  tr("Json Document (*.json)"));
  if (fileName.isEmpty())
    return;
  
  QFile f(fileName);
  f.open(QFile::ReadOnly);
  QByteArray g = f.readAll();
  QJsonDocument doc = QJsonDocument::fromJson(g);

  m_abiturients.clear();

  QJsonArray arr = doc.array();
  for(int i = 0; i < arr.count(); i++) {
    QJsonObject obj = arr[i].toObject();
    m_abiturients.push_back(Abiturient(obj));
    // qDebug() << i;
  }
  updateTable();

  // Действия с открытым файлом
}

 // Compare two variants.
 bool variantLessThan(const Abiturient &v1, const Abiturient &v2)
 {
     
     return v1.getAverageScore() < v2.getAverageScore();
 }

 void MainWindow::doComparison()
 {
     QList<Abiturient> fieldsList;

     // Add items to fieldsList.

    std::sort(m_abiturients.begin(), m_abiturients.end(), variantLessThan);
    updateTable();
 }
