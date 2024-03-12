#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsScene>
#include <QBoxLayout>
#include <QPen>
#include <QtWidgets>


#include "rocket.h"


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
    QAction *action;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *start;
    QPushButton *restart;
    QPen *pen;
    Rocket *rocket;
};
#endif // MAINWINDOW_H
