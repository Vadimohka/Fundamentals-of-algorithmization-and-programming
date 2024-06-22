#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "extendedhashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsertRandomClicked();
    void onFindMaxKeyClicked();
    void onPrintTableClicked();

private:
    Ui::MainWindow *ui;
    ExtendedHashTable *hashTable;
    QTextEdit *outputTextEdit;
    QPushButton *insertRandomButton;
    QPushButton *findMaxKeyButton;
    QPushButton *printTableButton;
};

#endif // MAINWINDOW_H


