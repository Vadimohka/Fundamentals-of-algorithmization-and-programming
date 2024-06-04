//
// Created by dmitry on 10.2.24.
//

#ifndef FIRST_BUTTON_H
#define FIRST_BUTTON_H

#include <Boat.h>
#include <Flag.h>

class Button :
        public Boat
{
public:
    Flag *flag;
    Button(QWidget *parent = nullptr);
    ~Button();

protected :
    QPushButton *m_upButton;
    QPushButton *m_downButton;

public slots:
    void upEnabled();
    void downEnabled();
};


#endif //FIRST_BUTTON_H
