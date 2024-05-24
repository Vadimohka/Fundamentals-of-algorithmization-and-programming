#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QWidget>
#include <QGraphicsScene>
#include <QBoxLayout>
#include <QPen>
#include <QtWidgets>

#include "rectangle.h"


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
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *start;
    QPushButton *restart;
    QPen *pen;
    Rectangle *rectangle;

};
#endif // MAINWINDOW_H
