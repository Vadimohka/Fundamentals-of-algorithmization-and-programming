#include "inputdialogs.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    xInput(new QSpinBox(this)),
    yInput(new QSpinBox(this))
{
    xInput->setMaximum(999);
    yInput->setMaximum(999);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение x в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение y в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}


InputDialogkrds::InputDialogkrds(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this)),
    yInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите координату x для перемещения: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите координату y для перемещения: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

InputDialogzv::InputDialogzv(QWidget *parent) :
    QDialog(parent),
    xInput(new QSpinBox(this)),
    yInput(new QSpinBox(this)),
    radioButton5(new QRadioButton("5", this)),
    radioButton6(new QRadioButton("6", this)),
    radioButton8(new QRadioButton("8", this))
{
        xInput->setMaximum(999);
        yInput->setMaximum(999);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение большего диаметра в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение меньшего диаметра в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    mainLayout->addWidget(radioButton5);
    mainLayout->addWidget(radioButton6);
    mainLayout->addWidget(radioButton8);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

InputDialogrb::InputDialogrb(QWidget *parent) :
    QDialog(parent),
    xInput(new QSpinBox(this)),
    yInput(new QSpinBox(this))
{
    xInput->setMaximum(999);
    yInput->setMaximum(999);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение первой диагонали в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение второй диагонали в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

InputDialogkv::InputDialogkv(QWidget *parent) :
    QDialog(parent),
    xInput(new QSpinBox(this))
{
        xInput->setMaximum(999);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение стороны/диаметра(шара) в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

int InputDialog::getX()
{
    return xInput->text().toLongLong();
}

int InputDialog::getY()
{
    return yInput->text().toLongLong();
}

int InputDialogkrds::getX()
{
    return xInput->text().toLongLong();
}

int InputDialogkrds::getY()
{
    return yInput->text().toLongLong();
}

int InputDialogrb::getX()
{
    return xInput->text().toLongLong();
}

int InputDialogrb::getY()
{
    return yInput->text().toLongLong();
}

int InputDialogzv::getX()
{
    return xInput->text().toLongLong();
}

int InputDialogzv::getY()
{
    return yInput->text().toLongLong();
}

int InputDialogzv::getRadio(){
    if (radioButton5->isChecked()) {
        return 5;
    } else if (radioButton6->isChecked()) {
        return 6;
    } else if (radioButton8->isChecked()) {
        return 8;
    }
    return 5;
}

int InputDialogkv::getX()
{
    return xInput->text().toLongLong();
}
