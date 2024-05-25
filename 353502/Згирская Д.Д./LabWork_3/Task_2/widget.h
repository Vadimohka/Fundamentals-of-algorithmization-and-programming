#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDebug>

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

private slots:
    void on_calculate_clicked();

private:
    Ui::Widget *ui;

    unsigned long long _firstNumber;
    unsigned long long _secondNumber;

    void setFirstNumber(QString firstString);
    void setSecondNumber(QString secondString);

    unsigned long long functionOfAccerman(unsigned  long long m, unsigned  long long n);
};
#endif // WIDGET_H
