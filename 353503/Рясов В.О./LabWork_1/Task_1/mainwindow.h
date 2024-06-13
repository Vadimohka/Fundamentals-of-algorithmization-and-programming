#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "rectangle.h"
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public Rectangle
{
    Q_OBJECT

public:
    MainWindow(Rectangle *parent = nullptr);
    ~MainWindow();
private:
    QPushButton *downButton;
    QPushButton *upButton;
    QPushButton *straightButton;

    QVBoxLayout *lout;
protected:
    void paintEvent(QPaintEvent *event) override;
    void downButtonClicked();
    void upButtonClicked();
    void straightButtonClicked();

};
#endif // MAINWINDOW_H
