#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QString toString(int num);
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QFile* openFile;
    int currentAction = 0;
    void setButtons(bool signal);
    void showDate();
    void turnAssert(bool signal);
    void dafaultRangeButtons();
    void birthdayRangeButtons();
    QVector<Date> data;
    Ui::Widget *ui;
};
#endif // WIDGET_H
