#ifndef CARD_DATA_WINDOW_H
#define CARD_DATA_WINDOW_H

#include <QDialog>

#include "card.h"
#include "allusersfile.h"
#include "add_money_window.h"

namespace Ui {
class Card_data_window;
}

class Card_data_window : public QDialog
{
    Q_OBJECT

public:
    explicit Card_data_window(long long, Card* card,QWidget *parent = nullptr);
    ~Card_data_window();

private slots:
    void on_Accept_button_clicked();

    void on_Add_money_to_card_button_clicked();

private:
    Ui::Card_data_window *ui;
    Add_money_window* add_money_window;

    Card* current_card;
    long long current_user_index;
};

#endif // CARD_DATA_WINDOW_H
