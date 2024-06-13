#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QLineEdit>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QTableWidget>
#include <QGridLayout>
#include <QStringList>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <magicNumbers.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT


public :

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QTableWidget* table;

    QStringList headers;

    QVector < Date > dates;

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QPushButton* button6;

    QFile file;
    QString fileName;

    QLabel* add_label1;
    QLabel* label_bithday;
    QLabel* label_change;

    QLineEdit* bithday_line;
    QLineEdit* add_line;
    QLineEdit* change_line;
    QLineEdit* index_line;

    QRegularExpressionValidator* validator;

    QIntValidator* intValidator;

    void addDateToTable(Date newDate);

    void editDateInTable(Date newDate, short index);

    void insertDateToTable(Date newDate, short row);

    void inputInformation();

    void openFile();

    void createFile();

    void closeFile();

    void writeToFile();

    void changeBithday();

    void changeDate();

    void rewriteFile();

};
#endif // MAINWINDOW_H
