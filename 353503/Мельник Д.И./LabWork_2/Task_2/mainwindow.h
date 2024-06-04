//
// Created by dmitry on 19.3.24.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "table.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);

  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  QFile file;
  QString pathToFile;
  Table* table;
  QVector<Book*> books;
  QRegularExpression regularExpression;

  QString _author;
  QString _title;
  QString _publisher;

  int _year;
  int _pages;
  int _numToEdit;

  bool _isFileOpen = false;
  bool _isAuthorEntered = false;
  bool _isTitleEntered = false;
  bool _isPublisherEntered = false;
  bool _isYearEntered = false;
  bool _isPagesEntered = false;
  bool _isNumEntered = false;

  void openFile();

  void putDataFromFileToTable();

  void showErrorMessage(const QString& message);

 private slots:

  // Обработка ввода
  void on_line_author_returnPressed();

  void on_lineEdit_title_returnPressed();

  void on_lineEdit_publisher_returnPressed();

  void on_lineEdit_year_returnPressed();

  void on_lineEdit_pages_returnPressed();

  void on_lineEdit_NumToEdit_returnPressed();

  void on_lineEdit_EditedRow_returnPressed();

  void on_lineInput_returnPressed();

  // Обработка кликов по кнопкам
  void on_btnSelectFile_clicked();

  void on_btn_AddBook_clicked();

  void on_btn_SortYear_clicked();

  void on_btn_SortPublisher_clicked();

  void on_btn_delete_clicked(bool checked);

  void on_btn_find_clicked(bool checked);
};

#endif  // MAINWINDOW_H
