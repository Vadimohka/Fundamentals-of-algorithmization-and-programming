#ifndef LAB3TASK3_WIDGET_H
#define LAB3TASK3_WIDGET_H

#include "QWidget"
#include "QPushButton"
#include "QLabel"
#include "QLineEdit"
#include "QPainter"
#include "QDebug"

#define uint unsigned long long

class Widget : public QWidget{
    Q_OBJECT

    QLineEdit *lineEdit;
    QLabel *label;
public slots:
    void solve();
public:
    explicit Widget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    uint coup(uint num1, uint num2);
};


#endif //LAB3TASK3_WIDGET_H
