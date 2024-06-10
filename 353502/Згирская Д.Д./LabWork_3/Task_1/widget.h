#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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

    bool setNumber10(QString number10);

    QString from10To2(double number10);
    QString decimalTo2(int decimal, QString answer);
    QString undecimalTo2(double undecimal, QString answer, int step);
    double getNumber2();
private slots:
    void on_getAnswer_clicked();

private:
    Ui::Widget *ui;

    double _number10;
    double _number2;
};
#endif // WIDGET_H
