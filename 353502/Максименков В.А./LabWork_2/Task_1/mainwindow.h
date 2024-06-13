#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QVector>
#include <QFile>

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

    Date ToDate(const QString& str);

private slots:
    void on_addButton_clicked();

    void on_informationButton_clicked();

    void on_hideButton_clicked();

    void on_birthdayButton_clicked();

    void on_fileButton_clicked();

    void on_changeButton_clicked();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QVector<Date> dates;
    QVector<bool> isOpen;
    QString CurrentBurthday = "15.10.2005";
    Date CurrentBurthdayDate = Date(15, 10, 2005);

    void addingDateFromFile(const QString& str);
};
#endif // MAINWINDOW_H
