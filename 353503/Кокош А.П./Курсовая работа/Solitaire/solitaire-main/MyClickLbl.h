
#pragma once

#include <QLabel>
#include <QWidget>

class MyClickLbl : public QLabel
{
    Q_OBJECT

public:
    // Constructor
    MyClickLbl(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

signals:
    // Fires when clicked
    void clicked();

protected:
    // Handles the mouse press event
    void mousePressEvent(QMouseEvent* ev);
};
