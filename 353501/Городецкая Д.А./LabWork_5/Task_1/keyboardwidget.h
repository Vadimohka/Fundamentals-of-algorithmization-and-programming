#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#pragma once
#include <QtWidgets>
#include "Locals.h"

namespace Ui {
class KeyboardWidget;
}

class KeyboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardWidget(QWidget *parent = nullptr);
    ~KeyboardWidget();
    void keyPressEvent(QKeyEvent *event) override;
    void setKeys(int);
public slots:
    void handleButtonClicked();
private:
    Ui::KeyboardWidget *ui;
    QMap<int, QPushButton *> buttonsMap;
};

#endif // KEYBOARDWIDGET_H
