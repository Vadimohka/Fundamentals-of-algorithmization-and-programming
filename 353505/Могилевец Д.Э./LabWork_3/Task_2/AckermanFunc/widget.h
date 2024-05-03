#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ackermanfunctioncalculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void on_pushButton_clicked();
    Ui::Widget *ui;
    AckermanFunctionCalculator calculator;
};
#endif // WIDGET_H
