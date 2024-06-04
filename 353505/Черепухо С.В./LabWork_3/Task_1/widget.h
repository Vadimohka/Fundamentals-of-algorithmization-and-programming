#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string>
#include <math.h>

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
    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    std::string floatToBinary(float ch);
    std::string floatToBinary_small(float ch, short step);

    bool minus = false;
};
#endif // WIDGET_H
