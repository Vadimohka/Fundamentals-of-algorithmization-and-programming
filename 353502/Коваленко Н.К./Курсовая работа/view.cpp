#include "view.h"
#include "gamescene.h"
#include <QKeyEvent>
#include <QApplication>
#include <QKeyEvent>


#include <QApplication>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "mainwindow.h"

View::View(int i)
    : QGraphicsView{}, m_gameScene(new GameScene(i, this))
{
    setScene(m_gameScene);
    resize(m_gameScene->sceneRect().width()+20, m_gameScene->sceneRect().height()+20);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
    {
        MainWindow *menu = new MainWindow;
        this->parentWidget()->layout()->removeWidget(this);
        this->parentWidget()->layout()->addWidget(menu);
        deleteLater();
    }
    break;
    }

    QGraphicsView::keyPressEvent(event);
}
