#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QMessageBox>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDate>
#include <QLineEdit>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addDate_clicked();

    void on_openfile_clicked();

    bool CheckFile(QString date);

    void on_savefile_clicked();

    void on_DateBirthdayText_userDateChanged(const QDate &date);

    void on_changeDate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
