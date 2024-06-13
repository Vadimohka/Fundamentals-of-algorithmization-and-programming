#ifndef WIDGET_H
#define WIDGET_H

#include "good.h"

#include <QWidget>

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
    void on_addPushButton_clicked();

    void on_updatePushButton_clicked();

    void on_deletePushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_writePushButton_clicked();

    void on_readPushButton_clicked();

    void on_pushButton_3_clicked();

    void on_sortPushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QVector<Good> goods;
    QVector<Good> goodsToShow;
    Ui::Widget *ui;
    void update();
    Good dialog();
};
#endif // WIDGET_H
