#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <iostream>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    struct Movie {
        int id;
        double rating;
        char genre;
        bool isAvailable;
        static const int TITLE_SIZE = 100;
        static const int NUM_ARRAY_SIZE = 10;
        char title[TITLE_SIZE];
        static int ratings[NUM_ARRAY_SIZE];
    };
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printMovie(QString output);
    void intializate(QString output);
private slots:
    void onButtonClick();

private: 

    Movie movie;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
