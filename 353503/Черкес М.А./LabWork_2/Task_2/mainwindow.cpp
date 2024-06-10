#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "trains.h"
#include <QApplication>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_5, &QPushButton::pressed, this,
          &MainWindow::loadDataFromFile);
  connect(ui->pushButton_2, &QPushButton::pressed, this, &MainWindow::addTrain);
  connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::exitW);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::saveDataToFile);
  connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::listSort);
  QObject::connect(ui->lineEdit_2, &QLineEdit::textChanged, [&] (const QString &text) {
      for(int i = 0; i < ui->listWidget->count(); ++i) {
          QListWidgetItem *item = ui->listWidget->item(i);
          if(item->text().contains(text, Qt::CaseInsensitive)) {
              item->setBackground(Qt::green);
          } else {
              item->setBackground(Qt::white);
          }
      }
      if(text==""){
          for(int i = 0; i < ui->listWidget->count(); ++i) {
              QListWidgetItem *item = ui->listWidget->item(i);
                  item->setBackground(Qt::white);
          }
      }
  });
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::loadDataFromFile() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/home", tr("Text Files (*)"));

  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return;
  }

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine();
    QStringList fields = line.split('|');

    Trains train;
    train.setDepartureDate(QDate::fromString(fields[0], "dd.MM.yyyy"));
    train.setTrainNumber(fields[1].toInt());
    train.setDestination(fields[2]);
    train.setDepartureTime(QTime::fromString(fields[3], "hh:mm:ss"));
    train.setTotalSeats(fields[4].toInt());
    int five = 4 + 1;
    train.setFreeSeats(fields[five].toInt());

    // Добавляем в динамический массив
    trainsArray.append(train);

    // Добавляем в QListWidget
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(
        "|Дата отправления" + train.getDepartureDate().toString("dd.MM.yyyy") +
        "| Номер рейса" + QString::number(train.getTrainNumber()) +
        "| Пункт назначения" + train.getDestination() + "| Время отправления" +
        train.getDepartureTime().toString("hh:mm") + "| Всего мест" +
        QString::number(train.getTotalSeats()) + "| Свободных мест" +
        QString::number(train.getFreeSeats()));
    ui->listWidget->addItem(item);

    // Выводим данные в консоль для отладки
    qDebug() << "Дата отправления: " << train.getDepartureDate();
    qDebug() << "Номер рейса: " << train.getTrainNumber();
    qDebug() << "Пункт назначения: " << train.getDestination();
    qDebug() << "Время отправления: " << train.getDepartureTime();
    qDebug() << "Число мест: " << train.getTotalSeats();
    qDebug() << "Число свободных мест: " << train.getFreeSeats();
  }

  file.close();
}

void MainWindow::addTrain() {
  ui->lineEdit->setStyleSheet("color: black;");
  ui->lineEdit_3->setStyleSheet("color: black;");
  ui->lineEdit_4->setStyleSheet("color: black;");
  ui->lineEdit_5->setStyleSheet("color: black;");
  Trains train;
  train.setDepartureDate(ui->dateEdit->date());
  if (checkInput(ui->lineEdit, ui->lineEdit_3, ui->lineEdit_4,
                 ui->lineEdit_5)) {
    train.setTrainNumber(ui->lineEdit->text().toInt());
    train.setDestination(ui->lineEdit_3->text());
    train.setTotalSeats(ui->lineEdit_4->text().toInt());
    train.setFreeSeats(ui->lineEdit_5->text().toInt());
    QMessageBox::information(nullptr, "Nice", "Данные внесены");
    train.setDepartureTime(ui->timeEdit->time());

    trainsArray.append(train);
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(
        "|Дата отправления" + train.getDepartureDate().toString("dd.MM.yyyy") +
        "| Номер рейса" + QString::number(train.getTrainNumber()) +
        "| Пункт назначения" + train.getDestination() + "| Время отправления" +
        train.getDepartureTime().toString("hh:mm") + "| Всего мест" +
        QString::number(train.getTotalSeats()) + "| Свободных мест" +
        QString::number(train.getFreeSeats()));
    ui->listWidget->addItem(item);
  } else {
    QMessageBox::warning(nullptr, "Ошибка", "Не, нихуя");
  }
}

bool MainWindow::checkInput(QLineEdit* lineEdit1, QLineEdit* lineEdit2,
                            QLineEdit* lineEdit3, QLineEdit* lineEdit4) {
  try {
    QString text1 = lineEdit1->text();
    QString text2 = lineEdit2->text();
    QString text3 = lineEdit3->text();
    QString text4 = lineEdit4->text();
    bool check = true;

    for (QChar c : text1) {
      if (!c.isDigit()) {
        lineEdit1->setStyleSheet("color: red;");
        check = false;
      }
    }

    for (QChar c : text2) {
      if (!c.isLetter()) {
        lineEdit2->setStyleSheet("color: red;");
        check = false;
      }
    }

    for (QChar c : text3) {
      if (!c.isDigit()) {
        lineEdit3->setStyleSheet("color: red;");
        check = false;
      }
    }

    for (QChar c : text4) {
      if (!c.isDigit()) {
        lineEdit4->setStyleSheet("color: red;");
        check = false;
      }
    }
    if (check && text1 != nullptr && text2 != nullptr && text3 != nullptr &&
        text4 != nullptr) {
      return true;
    } else {
      return false;
    }
  } catch (const std::exception& e) {
    QMessageBox::warning(nullptr, "Ошибка", e.what());
    return false;
  }
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    ui->lineEdit->setStyleSheet("color: black;");
    ui->lineEdit_3->setStyleSheet("color: black;");
    ui->lineEdit_4->setStyleSheet("color: black;");
    ui->lineEdit_5->setStyleSheet("color: black;");
  }
}

void MainWindow::exitW() {
  exit(0);
}

void MainWindow::saveDataToFile() {
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save File"), "/home", tr("Text Files (*)"));
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    return;
  }

  QTextStream out(&file);
  for (const Trains& train : trainsArray) {
    out << train.getDepartureDate().toString("dd.MM.yyyy") << "|"
        << train.getTrainNumber() << "|" << train.getDestination() << "|"
        << train.getDepartureTime().toString("hh:mm") << "|"
        << train.getTotalSeats() << "|" << train.getFreeSeats() << "\n";
  }

  file.close();
}

void MainWindow::listSort() {
  Trains train1;
  for (int i = 0; i < trainsArray.size(); i++) {
    for (int j = 0; j < trainsArray.size() - 1; j++) {
      if (trainsArray[j].getTrainNumber() >
          trainsArray[j + 1].getTrainNumber()) {
        train1 = trainsArray[j];
        trainsArray[j] = trainsArray[j + 1];
        trainsArray[j + 1] = train1;
      }
    }
  }
  ui->listWidget->clear();
  for (auto& i : trainsArray) {
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(
        "|Дата отправления" + i.getDepartureDate().toString("dd.MM.yyyy") +
        "| Номер рейса" + QString::number(i.getTrainNumber()) +
        "| Пункт назначения" + i.getDestination() + "| Время отправления" +
        i.getDepartureTime().toString("hh:mm") + "| Всего мест" +
        QString::number(i.getTotalSeats()) + "| Свободных мест" +
        QString::number(i.getFreeSeats()));
    ui->listWidget->addItem(item);
  }
}
