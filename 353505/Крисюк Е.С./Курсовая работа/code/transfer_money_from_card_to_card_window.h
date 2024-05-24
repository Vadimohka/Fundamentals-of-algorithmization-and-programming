#ifndef TRANSFER_MONEY_FROM_CARD_TO_CARD_WINDOW_H
#define TRANSFER_MONEY_FROM_CARD_TO_CARD_WINDOW_H

#include <QDialog>

#include "transactions.h"
#include "allusersfile.h"


namespace Ui {
class Transfer_money_from_card_to_card_window;
}

class Transfer_money_from_card_to_card_window : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer_money_from_card_to_card_window(QWidget *parent = nullptr);
    ~Transfer_money_from_card_to_card_window();

private slots:
    void on_Cancel_button_clicked();

    void on_Transfer_button_clicked();

private:
    Ui::Transfer_money_from_card_to_card_window *ui;
};

#endif // TRANSFER_MONEY_FROM_CARD_TO_CARD_WINDOW_H
