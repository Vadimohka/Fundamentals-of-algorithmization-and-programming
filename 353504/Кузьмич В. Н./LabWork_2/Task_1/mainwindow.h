#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "date.h"
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

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
    ~MainWindow();
    QString file_id;
    int n_str = 0;
private slots:
    void on_pushButton_clicked();

    void on_Add_clicked();

    void on_OpenFile_clicked();

    bool CheckFile(QString date);

    void on_DateBirt_userDateChanged(const QDate &date);

    void on_pushButton_2_clicked();

    void SaveFile(int index, QString edit);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
