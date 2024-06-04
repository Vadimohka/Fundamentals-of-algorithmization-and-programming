#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QMainWindow>
#include <QRandomGenerator>
#include "HashModTable.h"
#include "HashMultTable.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    unsigned int generateRandomNumber();
    QString generateRandomString(unsigned int length);
    void fillHashTableRandomValue(unsigned int size);

    void plotSearchTimes(QCustomPlot *customPlot, QVector<double> &times1, QVector<double> &times2);
    void speedFindHashModTable();
    void speedFindHashMultTable();
    void setCollisions();

private slots:
    void on_buildButton_clicked();

    void on_timeFindButton_clicked();

    void on_clearButton_clicked();

    void on_checkBox16_clicked();

    void on_checkBox64_clicked();

    void on_checkBox128_clicked();

    void on_checkBox2048_clicked();

private:
    Ui::MainWindow *ui;
    HashModTable<QString> *modTable;
    HashMultTable<QString> *multTable;
    QVector<double> timesMod, timesMult;
    QElapsedTimer *timerFind;
    qint64 elapsedTime;
};
#endif // MAINWINDOW_H
