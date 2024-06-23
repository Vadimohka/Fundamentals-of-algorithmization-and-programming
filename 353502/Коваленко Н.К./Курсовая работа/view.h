#ifndef VIEW_H
#define VIEW_H

#pragma once

#include "ui_mainwindow.h"
#include <QGraphicsView>

class GameScene;
class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(int i);

signals:

private:
    GameScene* m_gameScene;
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

};

#endif // VIEW_H
