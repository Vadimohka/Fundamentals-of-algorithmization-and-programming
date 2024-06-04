#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <QTimer>

#include <string>

#include "movingrect.h"
#include "solider.h"

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

    movingRect *mvr = new movingRect;
    Solider *slr = new Solider;

private:
    Ui::Widget *ui;
    QTimer *timer;
    QGraphicsScene *scene;

protected:
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void aniTimer();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_lineEdit_3_textChanged(const QString &arg1);
    void on_lineEdit_4_textChanged(const QString &arg1);
    void on_lineEdit_8_textChanged(const QString &arg1);
    void on_lineEdit_6_textChanged(const QString &arg1);
    void on_lineEdit_7_textChanged(const QString &arg1);
    void on_lineEdit_5_textChanged(const QString &arg1);
};
#endif // WIDGET_H
