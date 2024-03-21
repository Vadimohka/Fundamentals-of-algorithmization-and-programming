#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lefthandman.h"
#include "righthandman.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QPushButton>


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



    QGraphicsView* view;
    QGraphicsScene* scene;

    LeftHandMan* lhand;
    RightHandMan* rhand;
    QTimer* timer;
    QPushButton* greenButton;
    QPushButton* redButton;
    QPushButton* midButton;

    void check1();
    void check2();
    void check3();

private slots:
    void ClickedSlotG();
    void ClickedSlotR();
    void ClickedSlotM();
};
#endif // MAINWINDOW_H
