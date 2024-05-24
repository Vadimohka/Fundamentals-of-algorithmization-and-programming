#ifndef REGISTER_NEW_CARD_WINDOW_H
#define REGISTER_NEW_CARD_WINDOW_H

#include <QDialog>
#include "bank_meneger.h"


namespace Ui {
class Register_new_card_window;
}

class Register_new_card_window : public QDialog
{
    Q_OBJECT

public:
    explicit Register_new_card_window(long long,QWidget *parent = nullptr);
    ~Register_new_card_window();

private slots:
    void on_Cancel_button_clicked();

    void on_Visa_button_toggled(bool checked);

    void on_Mastercard_button_toggled(bool checked);

    void on_Register_card_button_clicked();

private:
    Ui::Register_new_card_window *ui;

    bool is_mastercard = false;
    long long user_index;
};

#endif // REGISTER_NEW_CARD_WINDOW_H
