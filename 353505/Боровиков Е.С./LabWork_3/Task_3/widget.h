#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

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

    Ui::Widget *ui;
    QPushButton * close;
    QPushButton * Otvet;
    QLineEdit * line1;
    //QLineEdit * line2;
    QLabel * rez;

    int reverseNumber(int n, int reversed);
public slots:
    void fun_rez();
};
#endif // WIDGET_H
