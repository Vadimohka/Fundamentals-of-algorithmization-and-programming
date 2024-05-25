#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

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

    bool setNumber(QString line);
    size_t findReverseNumber(size_t number1, size_t number2 = 0);

private slots:
    void on_show_answer_clicked();

private:
    size_t _number;
    Ui::Widget *ui;
};
#endif // WIDGET_H
