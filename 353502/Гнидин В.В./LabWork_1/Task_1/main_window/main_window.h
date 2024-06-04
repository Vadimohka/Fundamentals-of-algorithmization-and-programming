//
// Created by volodya-petarda on 3/3/24.
//

#ifndef GALAVA_MAIN_WINDOW_H
#define GALAVA_MAIN_WINDOW_H

#include <QWidget>
#include <QGraphicsScene>


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


#endif //GALAVA_MAIN_WINDOW_H
