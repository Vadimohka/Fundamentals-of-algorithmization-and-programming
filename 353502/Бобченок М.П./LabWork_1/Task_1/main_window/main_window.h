//
// Created by u on 09.03.24.
//

#ifndef TELEGA_MAIN_WINDOW_H
#define TELEGA_MAIN_WINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Ui::main_window *ui;
    QGraphicsScene *scene;
};


#endif //TELEGA_MAIN_WINDOW_H
