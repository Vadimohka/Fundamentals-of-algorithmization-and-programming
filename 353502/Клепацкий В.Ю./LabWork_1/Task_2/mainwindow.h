#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QTimer>
#include "circle.h"
#include "rectangle.h"
#include "rhomb.h"
#include "shestiygol.h"
#include "square.h"
#include "stareight.h"
#include "starfive.h"
#include "starsix.h"
#include "triangle.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void updateLabel();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Figure *item;
    QTimer *timer;
    int ygol=0;

    void updateScene();
};
#endif // MAINWINDOW_H
