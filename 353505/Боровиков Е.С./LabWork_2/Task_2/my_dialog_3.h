#ifndef MY_DIALOG_3_H
#define MY_DIALOG_3_H

#include<QtWidgets>

class my_dialog_3: public QDialog {
    Q_OBJECT
public:
    my_dialog_3(QWidget *parent = nullptr);

    QPushButton *women_btn;
    QPushButton *men_btn;

    QPushButton * close_dialog1;

signals:
    void nextPageRequested1(); // Сигнал для открытия второго диалогового окна
    void nextPageRequested2(); // Сигнал для открытия второго диалогового окна


};

#endif // MY_DIALOG_3_H
