#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "derivedhashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_initHashTableButton_clicked();
    void on_addElementButton_clicked();
    void on_removeElementButton_clicked();
    void on_findMaxKeyStackButton_clicked();
    void updateHashTableView();

private:
    Ui::MainWindow *ui;
    DerivedHashTable *hashTable;
};

#endif // MAINWINDOW_H
