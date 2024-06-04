#ifndef PAY_THE_BILL_WINDOW_H
#define PAY_THE_BILL_WINDOW_H

#include <QDialog>
#include "transactions.h"
#include "allusersfile.h"

namespace Ui {
class Pay_the_bill_window;
}

class Pay_the_bill_window : public QDialog
{
    Q_OBJECT

public:
    explicit Pay_the_bill_window(long long, Card*, QWidget *parent = nullptr);
    ~Pay_the_bill_window();

private slots:

    void on_Cancel_button_clicked();

    void on_Pay_button_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Pay_the_bill_window *ui;
    long long user_index;
    Card* current_card;

};

#endif // PAY_THE_BILL_WINDOW_H
