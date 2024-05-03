#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRandomGenerator>

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
    void on_reloadVectorButton_clicked();

    void on_amountOfElementsSpinBox_valueChanged(int arg1);

private:
    Ui::Widget *ui;

    QVector<int> vect;

    int amountOfElementsInArray;

    void printVector();
    void printMedians();

    double findMedian(int);
};
#endif // WIDGET_H
