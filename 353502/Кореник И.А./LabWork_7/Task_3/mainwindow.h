#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"
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

private:
    Ui::MainWindow *ui;

    size_t hashTableSize;

    HashTable<QString>* hashTable;

    void fillHashtable();

    int size = 0;

    bool correctSize;

    int currentKey;

    QString currentData;

    bool correctKey = false;

    bool correctData = false;
private slots:
    void fillTableRandom(bool random = true);


    void on_insertButton_clicked();
    void on_randomButton_clicked();
    void on_eraseButton_clicked();
};
#endif // MAINWINDOW_H
