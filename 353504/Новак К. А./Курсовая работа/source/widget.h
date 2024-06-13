#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "graphs.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:


    void paintEvent(QPaintEvent *event);
    void refresh(int capacity);
    void calc(Graph graph);
    QString getSVGLines(Graph graph);
    QString getSVGVertexes(Graph graph);
    Graph getGraph();
    bool allLinesIsNull();

private slots:

    void on_radioButton_6_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_12_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_lounch_clicked();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
