#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFile>
#include <date.h>
#include <QTableWidget>
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
    void on_addButton_clicked();

    void on_birthdayButton_clicked();

    void on_deleteButton_clicked();

    void on_changeButton_clicked();



    void on_open_clicked();

private:
    Ui::MainWindow *ui;

    void createUI(const QStringList &headers);

    void readFile(QString filename, QVector<Date>*input);

    QString filename = "/home/lidskae/Lab2_task1/dates.txt";

    QVector<Date>input;

    void addRow(Date* date, int row);

    Date* getInfo();

    void deleteDate(int);

    void changeDate(Date*, int);
};
#endif // MAINWINDOW_H
