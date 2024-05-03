#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QSpacerItem>
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QLabel>
#include "date.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTableWidget *table;
    QWidget *widget;
    QHBoxLayout *layout;
    QHBoxLayout *hlayout;
    QVBoxLayout *buttons;
    QLineEdit *dateInput;
    QLabel *label;

    QPushButton *open;
    QPushButton *daysTillBirthday;
    QPushButton *isLeap;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *clearFields;
    QPushButton *currTime;
    QPushButton *previous;
    QPushButton *week;
    QPushButton *duration;
    QPushButton *change;
    QString fileName;

    void setupTable();
    void updateTable();
    Date readDateFromLine();
    QString path = "/home/kostyanych2005/Qt/Labs/Lab 2/Task1";
private slots:
    void openButtonClicked();
    void clearFieldsClicked();
    void daysTillBirthdayClicked();
    void currTimeClicked();
    void isLeapClicked();
    void previousClicked();
    void weekNumberClicked();
    void durationClicked();
    void addClicked();
    void removeClicked();
    void changeClicked();
};


#endif // MAINWINDOW_H
