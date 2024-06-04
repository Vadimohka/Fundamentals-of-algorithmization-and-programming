//
// Created by dmitry on 10.2.24.
//

#include "Button.h"


Button::Button(QWidget *parent)
{
    m_downButton = new QPushButton("DOWN");
    m_upButton  = new QPushButton("UP");

    flag = new Flag;

    m_upButton->setEnabled(false);

    connect(m_upButton, &QPushButton::clicked, this, &Flag::timerSlotUp);
    connect(m_downButton, &QPushButton::clicked, this,&Flag::timerSlotDown);

    connect(this, &Flag::isUp, this, &Button::upEnabled);
    connect(this, &Flag::isDown, this, &Button::downEnabled);
}

void Button::upEnabled()
{
    qDebug() <<"upEnabled";
    m_upButton->setEnabled(false);
    m_downButton->setEnabled(true);
}

void Button::downEnabled()
{
    qDebug() <<"downEnabled";
    m_upButton->setEnabled(true);
    m_downButton->setEnabled(false);
}


Button::~Button() noexcept {
}
