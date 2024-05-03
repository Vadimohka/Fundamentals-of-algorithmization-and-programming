#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
#include <QMessageBox>
#include "date.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QFile File;
    QString Path;
    bool checkDate(QString str);
    void fileToTable();
    void changeFile(int row, QString date);
    void deleteFile(int row);

private slots:


    void on_pushButton_clicked();

    void on_tableInfo_cellEntered(int row, int column);

    void on_tableInfo_cellChanged(int row, int column);

    void on_pushButton_2_clicked();

    void on_IsLeapButton_clicked();

    void on_BirthdayButton_clicked();

    void on_pushButton_5_clicked();

    void on_DurationButton_clicked();

    void on_nowButton_clicked();

    void on_spinBoxChange_textChanged(const QString &arg1);

    void on_ChangeDateButton_clicked();

    void on_DurationButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_DeleteDateButton_clicked();

    void on_openFileButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
