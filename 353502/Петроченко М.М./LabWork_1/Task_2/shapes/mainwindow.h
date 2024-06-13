//
// Created by acryoz on 14.2.24.
//

#pragma once

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QRadioButton>
#include <QDoubleValidator>
#include "canvas.h"
#include "../headers/redactarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void resetSliders();
    void selectFigure();
    void next();
    void previous();
    void upd();
private:
    QDoubleValidator* x_validator;
    QDoubleValidator* y_validator;
    QLabel* info;
    QTimer* ticker;
    QGridLayout* lines;
    QLineEdit* line1x;
    QLineEdit* line2x;
    QLineEdit* line3x;
    QLineEdit* line4x;
    QLineEdit* line1y;
    QLineEdit* line2y;
    QLineEdit* line3y;
    QLineEdit* line4y;
    QPushButton* draw_button;
    QPushButton* choose_next;
    QPushButton* choose_prev;
    Canvas* canvas;
    QHBoxLayout* hbox;
    QHBoxLayout* choice_buttons;
    QHBoxLayout* buttons;
    QVBoxLayout* vbox;
    QVBoxLayout* redact_vbox;
    QRadioButton* triangle_button;
    QRadioButton* rectangle_button;
    QRadioButton* circle_button;
    QRadioButton* square_button;
    QRadioButton* hexagon_button;
    QRadioButton* rhombus_button;
    QRadioButton* pentagram_button;
    QRadioButton* hexagram_button;
    QRadioButton* octagram_button;
    QRadioButton* custom_button;
    RedactArea* redact_area;
    Ui::MainWindow *ui;
};


#endif //UNTITLED_MAINWINDOW_H
