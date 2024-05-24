#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "date.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QRegularExpression>
#include <QVariant>

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

private slots:
    void on_spinBox_month_editingFinished();

    void on_spinBox_month_valueChanged(int arg1);

    void on_pushButton_setBDay_clicked();

    void on_pushButton_setDur_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_AddDay_clicked();

    void on_pushButton_ChangeDay_clicked();

    void on_pushButton_save_clicked();

    void on_spinBox_year_editingFinished();

private:
    QVector<Date> dates;
    void arrayToTable(QVector<Date>);
    Ui::MainWindow *ui;
    Date Duration = Date(1, 1, 1582);
    Date BDay = Date(1, 1, 1582);

};



#endif // MAINWINDOW_H
