#include "mainwindow.h"


MainWindow::MainWindow() : ui(new Ui::MainWindow) { ui->setupUi(this); }

void MainWindow::on_tableWidget_itemSelectionChanged() {
  auto selectedI = ui->tableWidget->selectedItems();
  int selected = -1;
  if (selectedI.count() > 0) {
    selected = selectedI[0]->row();
  } 
  QDate qtoday = QDate::currentDate();
  Date today(qtoday.day(), qtoday.month(), qtoday.year());
  QDate qbith = ui->dateEdit->date();
  Date bith(qbith.day(), qbith.month(), qbith.year());
  ui->label->setText(QString("Следующий день: %0\n Прошлый день: %1\n Високосный год?: %2\n Номер недели: %3\n День рождения: %4\n Duration: %5")
  .arg(dates[selected].NextDay().ToString())
  .arg(dates[selected].PreviousDay().ToString())
  .arg(dates[selected].IsLeap())
  .arg(dates[selected].WeekNumber())
  .arg(dates[selected].DaysTillYourBithday(bith))
  .arg(dates[selected].Duration(today)));

}

void MainWindow::on_userDateChanged(){
  on_tableWidget_itemSelectionChanged();
}
void MainWindow::on_openFile_clicked() {
  dates.clear();
  QString filePath = QFileDialog::getOpenFileName(this, "Open Text File", "",
                                                  "Text Files (*.txt)");
  if (!filePath.isEmpty()) {
    newFile = new QFile(filePath);
    if (newFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(newFile);
      QString content = in.readAll();
      qDebug() << content;

      QStringList myStringList = content.split("\n");

      for (int index = 0; index < myStringList.length(); index++) {
        QString s = myStringList.at(index);
        if (s.length() < 10)
          break;
        QStringList parts = s.split(".");

        // for (int index = 0; index < myStringList.length(); index++)
        // {
        //   QString s = myStringList.at(index);
        //     qDebug() << s;
        // }
        int day = parts[0].toInt();
        int month = parts[1].toInt();
        int year = parts[2].toInt();
        dates.push_back(Date(day, month, year));
        // qDebug() << "[" << day << " " << month << " " << year << "] " << s;
      }

      // textEdit->setPlainText(content);
      newFile->close();
    }

  }
  updateTable();
}

void MainWindow::updateTable(){
  ui->tableWidget->setRowCount(dates.length());
  
  for(int i = 0; i < dates.length(); i++){
    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
    qDebug() << dates[i].ToString();
  }
}

bool MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::WindowActivate) {
        dates.clear();
 
  if (!filePath.isEmpty()) {
    newFile = new QFile(filePath);
    if (newFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(newFile);
      QString content = in.readAll();
      qDebug() << content;

      QStringList myStringList = content.split("\n");

      for (int index = 0; index < myStringList.length(); index++) {
        QString s = myStringList.at(index);
        if (s.length() < 10)
          break;
        QStringList parts = s.split(".");

        // for (int index = 0; index < myStringList.length(); index++)
        // {
        //   QString s = myStringList.at(index);
        //     qDebug() << s;
        // }
        int day = parts[0].toInt();
        int month = parts[1].toInt();
        int year = parts[2].toInt();
        dates.push_back(Date(day, month, year));
        // qDebug() << "[" << day << " " << month << " " << year << "] " << s;
      }

      // textEdit->setPlainText(content);
      newFile->close();
    }

  }
  updateTable();
    }
    return QWidget::event(e);
}
