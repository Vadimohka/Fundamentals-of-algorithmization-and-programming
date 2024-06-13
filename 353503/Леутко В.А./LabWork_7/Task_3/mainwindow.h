#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"
#include <QRandomGenerator>
#include <QString>
#include "hashtableavg.h"

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
    void on_generateBtn_clicked();

private:
    Ui::MainWindow *ui;
    HashTableAvg<QString> *hashTable;

    QString generateRandomString(int length);
    int64_t generateRandomNumber();

};
#endif // MAINWINDOW_H
