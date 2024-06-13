//
// Created by acryoz on 17.2.24.
//

#ifndef UNTITLED_REDACTAREA_H
#define UNTITLED_REDACTAREA_H

#include <QFrame>
#include <QRadioButton>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class RedactArea; }
QT_END_NAMESPACE

class RedactArea : public QFrame {
Q_OBJECT

public:
    explicit RedactArea(QWidget *parent = nullptr);
    QSlider* rotation_slider;
    QSlider* scale_slider;
    ~RedactArea() override;

private:
    QWidget* rotation_slider_box;
    QWidget* scale_slider_box;
    Ui::RedactArea *ui;
};


#endif //UNTITLED_REDACTAREA_H
