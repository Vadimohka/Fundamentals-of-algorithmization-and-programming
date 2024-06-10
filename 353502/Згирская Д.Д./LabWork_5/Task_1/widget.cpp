#include "widget.h"

#include <utility>
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    displayWidget = new Display(this);
    displayWidget->setGeometry(60, 60, 1800, 500);

    keyboardWidget = new Keyboard(this);
    keyboardWidget->setGeometry(290, 550, 1800, 500);

    displayWidget->show();
    keyboardWidget->show();


    ui->accuracyProgressBar->setFocusPolicy(Qt::NoFocus);
    ui->comboBox->setFocusPolicy(Qt::NoFocus);
    ui->timeLabel->setText(QString("00:00"));
    ui->valueLabel->setText(QString::number(0));

    connect(keyboardWidget, &Keyboard::keyToPrint, this, &Widget::getKey);
    connect(displayWidget, &Display::percent, this, &Widget::successfull);
    connect(displayWidget, &Display::symbolsAndTime, this, &Widget::time);
}

Widget::~Widget() {
    delete displayWidget;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) {
    keyboardWidget->keyPressEvent(event);
}

void Widget::keyReleaseEvent(QKeyEvent *event) {
    keyboardWidget->keyReleaseEvent(event);
}

void Widget::getKey(QString key) {
    displayWidget->getKey(key);
}

void Widget::successfull(double percent) {
    ui->accuracyProgressBar->setValue(percent);
}

void Widget::on_comboBox_currentIndexChanged(int index) {
    keyboardWidget->updateSelf(index);
    displayWidget->updateSelf(index);
    ui->accuracyProgressBar->setValue(100);
    ui->timeLabel->setText(QString("00:00"));
    ui->valueLabel->setText(QString::number(0));
}

void Widget::time(int symbols, QTime time) {
    ui->timeLabel->setText(QString::number(time.elapsed() / 60000) + ":" + QString::number(time.elapsed() / 1000));
    ui->valueLabel->setText(QString::number(symbols * 60000 / time.elapsed()));
}

