//
// Created by dmitry on 19.3.24.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tableWidget->hide();
  regularExpression =
      QRegularExpression("(\\w+)\\s+(\\w+)\\s+(\\w+)\\s+(\\d+)\\s+(\\d+)");
  table = new Table(ui->tableWidget);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::openFile() {
  pathToFile =
      QFileDialog::getOpenFileName(this, tr("Open File"), "/home/dmitry/");
  if (pathToFile.isEmpty()) {
    showErrorMessage("Ни один файл не выбран.");
    _isFileOpen = false;
    return;
  }
  file.setFileName(pathToFile);
  file.open(QIODevice::ReadWrite);
  QTextStream fileStream(&file);
  QString str;
  while (!fileStream.atEnd()) {
    str = fileStream.readLine();
    QRegularExpressionMatch match = regularExpression.match(str);
    if (!match.hasMatch()) {
      showErrorMessage("Ошибка чтения / неправильний формат");
      qDebug() << str;
      _isFileOpen = false;
      file.close();
      return;
    }
  }
  file.close();
  putDataFromFileToTable();
}

void MainWindow::putDataFromFileToTable() {
  if (pathToFile.isEmpty())
    return;
  file.setFileName(pathToFile);
  file.open(QIODevice::ReadWrite);
  QTextStream fileStream(&file);
  QRegularExpressionMatch match;
  QString s;
  do {
    s = fileStream.readLine();
    if (!s.isEmpty()) {
      match = regularExpression.match(s);
      if (match.hasMatch()) {
        QString author = match.captured(1);
        QString title = match.captured(2);
        QString publisher = match.captured(3);
        int year = match.captured(4).toInt();
        int number = match.captured(5).toInt();
        Book* b = new Book(author, title, year, publisher, number);
        books.push_back(b);
      }
    }
  } while (!fileStream.atEnd());
  _isFileOpen = true;
  ui->tableWidget->show();
  table->setTableInfo(books);
  file.close();
}

void MainWindow::on_btnSelectFile_clicked() {
  openFile();
  qDebug() << pathToFile;
}

void MainWindow::on_line_author_returnPressed() {
  _author = ui->line_author->text();
  _isAuthorEntered = true;
}

void MainWindow::on_lineEdit_title_returnPressed() {
  _title = ui->lineEdit_title->text();
  _isTitleEntered = true;
}

void MainWindow::on_lineEdit_publisher_returnPressed() {
  _publisher = ui->lineEdit_publisher->text();
  _isPublisherEntered = true;
}

void MainWindow::on_lineEdit_year_returnPressed() {
  bool Ok;
  _year = ui->lineEdit_year->text().toInt(&Ok);
  if (!Ok) {
    showErrorMessage("Ошибка конвертации в год.");
    _isYearEntered = false;
    return;
  }
  _isYearEntered = true;
}

void MainWindow::on_lineEdit_pages_returnPressed() {
  bool Ok;
  _pages = ui->lineEdit_pages->text().toInt(&Ok);
  if (!Ok) {
    showErrorMessage("Ошибка конвертации в страницы.");
    _isPagesEntered = false;
    return;
  }
  _isPagesEntered = true;
}

void MainWindow::on_btn_AddBook_clicked() {
  if (_isFileOpen && _isAuthorEntered && _isPagesEntered &&
      _isPublisherEntered && _isTitleEntered && _isYearEntered) {
    table->addRow(&file, new Book(_author, _title, _year, _publisher, _pages));
    ui->lineEdit_year->clear();
    ui->line_author->clear();
    ui->lineEdit_pages->clear();
    ui->lineEdit_publisher->clear();
    ui->lineEdit_title->clear();
    _isAuthorEntered = 0;
    _isPagesEntered = 0;
    _isPublisherEntered = 0;
    _isTitleEntered = 0;
    _isYearEntered = 0;
  } else {
    showErrorMessage("Недостаточно иформации.");
    return;
  }
}

void MainWindow::on_lineEdit_NumToEdit_returnPressed() {
  bool Ok = true;
  _numToEdit = ui->lineEdit_NumToEdit->text().toInt(&Ok);
  if (!Ok) {
    showErrorMessage("Ошибка конвертиции  текста.");
    return;
  }
}

void MainWindow::on_lineEdit_EditedRow_returnPressed() {
  QString str = ui->lineEdit_EditedRow->text();
  QRegularExpressionMatch match = regularExpression.match(str);
  if (!match.hasMatch()) {
    showErrorMessage("Ошибка чтения.");
    return;
  }
  QString author = match.captured(1);
  QString title = match.captured(2);
  QString publisher = match.captured(3);
  int year = match.captured(4).toInt();
  int number = match.captured(5).toInt();
  Book* b = new Book(author, title, year, publisher, number);

  table->setRow(b, _numToEdit - 1);
  books[_numToEdit - 1] = b;
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream fileStream(&file);
  fileStream.seek(0);
  for (int var = 0; var < ui->tableWidget->rowCount(); ++var) {
    fileStream << books.at(var)->toString();
  }
  file.close();
  ui->lineEdit_EditedRow->clear();
  ui->lineEdit_NumToEdit->clear();
}

void MainWindow::on_btn_SortYear_clicked() {
  if (_isFileOpen)
    table->sortByYear();
}

void MainWindow::on_btn_SortPublisher_clicked() {
  if (_isFileOpen)
    table->sortByPublisher();
}

void MainWindow::on_lineInput_returnPressed() {
  int status = 0;
  if (ui->btn_delete->isChecked())
    status = 1;
  if (ui->btn_find->isChecked())
    status = 2;
  bool Ok = true;
  int num = 0;
  switch (status) {
    case 0:
      ui->lbl_info->setText("Ошибка!");
      break;

    case 1:
      num = ui->lineInput->text().toInt(&Ok);
      if (!Ok) {
        showErrorMessage("Ошибка конвертации текста в страницы.");
        return;
      }
      table->deleteRow(&file, num);
      break;
    case 2:
      table->showNecessary(ui->lineInput->text());
      break;
    default:
      break;
  }
}

void MainWindow::on_btn_delete_clicked(bool checked) {
  if (checked) {
    ui->lbl_info->setText("Введите строку для удаления");
    ui->btn_find->setChecked(false);
  }
}

void MainWindow::showErrorMessage(const QString& message) {
  QMessageBox::warning(this, "Ошибка", message);
}

void MainWindow::on_btn_find_clicked(bool checked) {
  if (checked) {
    ui->lbl_info->setText("Введите название для поиска!");
    ui->btn_delete->setChecked(false);
  }
}
