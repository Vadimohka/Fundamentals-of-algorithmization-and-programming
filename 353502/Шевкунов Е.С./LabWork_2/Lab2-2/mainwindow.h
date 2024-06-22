#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QComboBox>
#include "student.h"

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
    QPushButton *saveNameButton;
    QPushButton *sortButton;
    QPushButton *exellentButton;
    QPushButton *searchButton;
    QLineEdit *name;
    QLineEdit *marks;
    QLineEdit *search;
    QTextEdit *output;
    QComboBox *group;
    QComboBox *form;
    QComboBox *speciality;
    Student **students;
    int number = 0;
    QString file = "/home/egor/qt labs/Lab2-2/data.txt";

    void saveToFile(const QString& filename);
    void loadFromFile(const QString& filename);

private slots:
    void saveStudent();
    void sort();
    void showExcellentStudents();
    void searchStudents();
};
#endif // MAINWINDOW_H
