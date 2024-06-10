#ifndef LAB5TASK1_WIDGET_H
#define LAB5TASK1_WIDGET_H

#include <QWidget>
#include "display.h"
#include "keyboard.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

    Display *displayWidget;
    Keyboard *keyboardWidget;
public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

private slots:

    void getKey(QString key);\

    void successfull(double percent);

    void time(int symbols, QTime time);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;

};


#endif //LAB5TASK1_WIDGET_H
