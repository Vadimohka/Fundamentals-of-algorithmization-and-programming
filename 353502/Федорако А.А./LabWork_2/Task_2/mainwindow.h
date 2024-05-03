#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextEdit>
#include "fileprocessing.h"
#include <QDebug>
#include <QMessageBox>
#include "fileprocessing.h"
#include <QErrorMessage>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    FileProcessing* file = new FileProcessing();
    void showErrorEvent(QString information);
    void showInformationEvent(QString information);

private slots:
    void on_pushButton_open_file_clicked();
    void on_pushButton_search_drive_place_clicked();
    void on_pushButton_search_drive_date_clicked();
    void on_pushButton_save_five_clicked();
    void on_pushButton_close_file_clicked();
    void on_pushButton_cancel_search_clicked();
    void on_pushButton_clicked();
    void on_pushButton_add_trip_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
