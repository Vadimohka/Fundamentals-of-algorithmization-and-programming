#ifndef BASA_H
#define BASA_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>


#include "rectangle.h"
#include "triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Basa; }
QT_END_NAMESPACE

class Basa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Basa(QWidget *parent = nullptr);
    ~Basa();

protected:


private:
    Ui::Basa *ui;

    Rectangle *rect1;
    Rectangle *rect2;
    Rectangle *rect3;
    Rectangle *rect4;
    Rectangle *rect5;
    Rectangle *rect6;
    Rectangle *rect7;
    Rectangle *rect8;

    Triangle *trian1;

    QPushButton *doorButton1;
    QPushButton *doorButton2;
    QPushButton *doorButton3;
    QPushButton *windowButton1_1;
    QPushButton *windowButton1_2;
    QPushButton *windowButton1_3;
    QPushButton *windowButton2_1;
    QPushButton *windowButton2_2;
    QPushButton *windowButton2_3;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;

    int W1, W2, W3, Max1, Max2, Max3;

private slots:
    void openDoor();
    void closeDoor();
    void stopDoor();
    void openWindow1();
    void closeWindow1();
    void stopWindow1();
    void openWindow2();
    void closeWindow2();
    void stopWindow2();
    void open1(int& x, int dx);
    void close1(int& x, int max, int dx);
    void open2(int& x, int dx);
    void close2(int& x, int max, int dx);
    void open3(int& x, int dx);
    void close3(int& x, int max, int dx);
};
#endif // BASA_H
