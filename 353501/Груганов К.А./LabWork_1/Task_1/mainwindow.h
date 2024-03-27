#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include<QGraphicsRectItem>
#include <QHBoxLayout>
#include <QKeyEvent>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *p) override;
private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QPushButton *Right;
    QPushButton *Left;
    QPushButton *Stop;
    QPushButton*Salute;
    Person *person;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
