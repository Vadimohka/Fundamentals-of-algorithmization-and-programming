//
// Created by acryoz on 10.2.24.
//

#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H
#define FPS 60

#include <QWidget>
#include <QPalette>
#include <QTimer>




QT_BEGIN_NAMESPACE
namespace Ui { class Rectangle; }
QT_END_NAMESPACE

class Rectangle : public QWidget {
Q_OBJECT

public:
    explicit Rectangle(QWidget *parent = nullptr);
    float hspeed = 5;
    float vspeed = 0;
    float prev_hspeed = 5;
    float prev_vspeed = 0;
    void stop();
    ~Rectangle() override;
public slots:
    virtual void moveSideways();
    virtual void moveUpDown();

protected slots:
    virtual void moveTick();

protected:
    QTimer g_clock;
    Ui::Rectangle *ui;
};


#endif //UNTITLED_RECTANGLE_H
