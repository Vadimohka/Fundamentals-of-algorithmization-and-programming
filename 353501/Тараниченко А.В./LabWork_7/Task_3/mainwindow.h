#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtablechild.h"
#include "hashtablechild.cpp"

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


    void listUpdate();

private slots:
    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_getButton_clicked();

    void on_removeEvenKeys_clicked();

    void on_insertButton_2_clicked();

private:
    Ui::MainWindow *ui;
    HashTableChild<QString>* hashtable;
};
#endif // MAINWINDOW_H
