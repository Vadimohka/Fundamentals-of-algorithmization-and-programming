#include <QVBoxLayout>
#include "slider.h"

Slider::Slider(QWidget *parent)
    : QWidget(parent) {

    QVBoxLayout *hbox = new QVBoxLayout(this);

    sldr = new QSlider(Qt::Vertical , this);
    hbox->addWidget(sldr);

    label = new QLabel("0", this);
    hbox->addWidget(label);

    connect(sldr, &QSlider::valueChanged, label,
            static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}
