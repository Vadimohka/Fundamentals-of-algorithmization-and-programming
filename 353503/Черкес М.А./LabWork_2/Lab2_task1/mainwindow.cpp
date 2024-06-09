#include "mainwindow.h"
#include "QListWidget"
#include "QTableWidget"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->dateEdit, &QDateEdit::dateChanged, this,
          &MainWindow::onDateChanged);
  connect(ui->dateEdit_2, &QDateEdit::dateChanged, this,
          &MainWindow::onDateChanged2);
  connect(ui->pushButton, &QPushButton::pressed, this,
          &MainWindow::on_pushButton_pressed);
  connect(ui->listWidget, &QListWidget::itemClicked, this,
          &MainWindow::on_listWidgetItem_clicked);
  onDateChanged(ui->dateEdit->date());
  onDateChanged2(ui->dateEdit_2->date());
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::onDateChanged(const QDate& date) {
  if (!date.isValid()) {
    qDebug() << "Invalid date";
    return;
  }
  QDate currentDate = QDate::currentDate();
  MyDate MycurrentDate(currentDate.day(), currentDate.month(),
                       currentDate.year());
  MyDate myDate(date.day(), date.month(), date.year());
  MyDate nextDay = myDate.NextDay();
  MyDate prevDay = myDate.PreviousDay();
  ui->label_3->setText(nextDay.GetDateAsString());
  ui->label_4->setText(prevDay.GetDateAsString());
  if (myDate.IsLeap()) {
    ui->label_2->setText("Yes");
  } else {
    ui->label_2->setText("No");
  }
  ui->label->setText(QString::number(myDate.WeekNumber()));
  qDebug() << "New date: " << myDate.GetDateAsString();
  ui->label_6->setText(currentDate.toString("dd.MM.yyyy"));
  int days = MycurrentDate.Duration(myDate);

  ui->label_8->setText(QString::number(days));
}

void MainWindow::onDateChanged2(const QDate& date) {
  QDate currentDate = QDate::currentDate();
  MyDate MycurrentDate(currentDate.day(), currentDate.month(),
                       currentDate.year());
  QDate Birthday = date;
  MyDate Mybirthday(Birthday.day(), Birthday.month(), currentDate.year());
  int daysBday = MycurrentDate.Duration(Mybirthday);
  ui->label_12->setText(QString::number(daysBday));
}

void MainWindow::on_pushButton_pressed() {
  QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                  tr("Text Files (*)"));
  if (!filePath.isEmpty()) {
    QList<MyDate> dates;
    readFromFileAndWriteToDate(filePath, dates);

    // Create a new QTableWidget instance
    QTableWidget *table = new QTableWidget(dates.size(), 6);

    // Set the headers
    QStringList headers;
    headers << "Date" << "Next Day" << "Previous Day" << "Is Leap Year" << "Week Number" << "Days Until Next Date";
    table->setHorizontalHeaderLabels(headers);

    // Populate the table with dates and their calculated values
    for (int i = 0; i < dates.size(); ++i) {
      QTableWidgetItem *dateItem = new QTableWidgetItem(dates[i].GetDateAsString());
      QTableWidgetItem *nextDayItem = new QTableWidgetItem(dates[i].NextDay().GetDateAsString());
      QTableWidgetItem *prevDayItem = new QTableWidgetItem(dates[i].PreviousDay().GetDateAsString());
      QTableWidgetItem *isLeapYearItem = new QTableWidgetItem(dates[i].IsLeap() ? "Yes" : "No");
      QTableWidgetItem *weekNumberItem = new QTableWidgetItem(QString::number(dates[i].WeekNumber()));

      // Calculate the difference between the current date and the next date
      QTableWidgetItem *daysUntilNextDateItem;
      if (i < dates.size() - 1) {
        int daysUntilNextDate = dates[i].Duration(dates[i+1]);
        daysUntilNextDateItem = new QTableWidgetItem(QString::number(daysUntilNextDate));
      } else {
        daysUntilNextDateItem = new QTableWidgetItem("N/A");
      }

      table->setItem(i, 0, dateItem);
      table->setItem(i, 1, nextDayItem);
      table->setItem(i, 2, prevDayItem);
      table->setItem(i, 3, isLeapYearItem);
      table->setItem(i, 4, weekNumberItem);
      table->setItem(i, 5, daysUntilNextDateItem);
    }

    // Show the table in a new window
    table->setWindowTitle("Dates");
    table->show();
  }
}

void MainWindow::readFromFileAndWriteToDate(QString filePath, QList<MyDate>& dates) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Не удалось открыть файл";
    return;
  }

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine();
    QStringList dateStrings = line.split(" ");
    for (const QString& dateString : dateStrings) {
      QStringList dateParts = dateString.split(".");
      if (dateParts.size() == 3) {
        MyDate MyFileDate(dateParts[0].toInt(), dateParts[1].toInt(),
                          dateParts[2].toInt());

        // Check if the date already exists in the list
        bool dateExists = false;
        for (const MyDate& date : dates) {
          if (date.GetDateAsString() == MyFileDate.GetDateAsString()) {
            dateExists = true;
            break;
          }
        }

        // If the date does not exist in the list, add it
        if (!dateExists) {
          dates.append(MyFileDate);
          qDebug() << "New date: " << MyFileDate.GetDateAsString();
        }
      }
    }
  }

  file.close();

  // Update the QListWidget after reading the file
  ui->listWidget->clear();
  for (const MyDate& date : dates) {
    ui->listWidget->addItem(
        "Дата: " +
        date.GetDateAsString());  // добавление даты в QListWidget с префиксом "Дата: "
  }
}




void MainWindow::on_listWidgetItem_clicked(QListWidgetItem* item) {
  QString dateString =
      item->text().split(": ").last();  // получаем дату из строки "Дата: ..."
  QDate date = QDate::fromString(dateString,
                                 "dd.MM.yyyy");  // преобразуем строку в QDate
  onDateChanged(date);  // вызываем функцию onDateChanged с полученной датой
  onDateChanged2(ui->dateEdit_2->date());
}
