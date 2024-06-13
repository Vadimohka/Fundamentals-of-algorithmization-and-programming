#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QDate>
#include <QRegularExpression>
#include "date.h"


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
    QString path;
    QVector<Date> date;
    QString s = "";

private slots:
    void on_open_clicked();
    void on_PrintNextDay_clicked();
    void on_PrintDifference_clicked();
    void on_AddDate_clicked();
    void on_ChangeDate_clicked();
    void on_PrintDate_clicked();
    void on_ToBith_clicked();

private:
    Ui::MainWindow *ui;
    QString yourBithday;
    QString newDate;
    QString change;
    QString current = QDate::currentDate().toString("dd.MM.yyyy");
    QFile file;
};
#endif // MAINWINDOW_H
