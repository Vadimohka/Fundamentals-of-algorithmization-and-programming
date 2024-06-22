#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>

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
    QStandardItemModel *model;
    QStandardItem *item;
    const int col = 2, row = 3;
    int numDates = 0;
    QLineEdit *dateAdd;
    QPushButton *dateAddButton;
    QCheckBox *dr;
    QLabel *drLab;
    bool drBool = 0;
private slots:
    void checkboxStateChanged(int state);
    void addDates();
    void opener();
    void nextDates();
    void difference();
};
#endif // MAINWINDOW_H
