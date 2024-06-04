//
// Created by u on 09.03.24.
//

#ifndef TELEGA_MAIN_WINDOW_H
#define TELEGA_MAIN_WINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>
#include <QKeyEvent>
#include "src/paintScene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

public slots:
    static void quit();
    void setStar() const;
    void setPolygon() const;

public:
    Ui::main_window *ui;
    paintScene *scene;

    void keyPressEvent(QKeyEvent *e) override;

    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;
};


#endif //TELEGA_MAIN_WINDOW_H
