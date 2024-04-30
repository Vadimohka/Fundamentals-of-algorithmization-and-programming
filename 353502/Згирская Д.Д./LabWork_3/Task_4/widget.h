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

    void hanoi(int n, QString start, QString temp, QString end);

    bool setNumber(QString line);

private slots:
    void on_getSteps_clicked();

private:
    Ui::Widget *ui;

    unsigned _number;
};
#endif // WIDGET_H
