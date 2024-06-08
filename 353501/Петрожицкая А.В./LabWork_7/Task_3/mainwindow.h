#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QChar>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QString>
#include "HashTable.h"

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

private slots:
    void on_generateButton_clicked();

private:
    unsigned int generateRandomNumber();
    QString generateRandomString(unsigned int length);

private:
    Ui::MainWindow *ui;
    HashTableMax<QString> *hashTable;
};
#endif // MAINWINDOW_H
