#ifndef ADD_MONEY_WINDOW_H
#define ADD_MONEY_WINDOW_H

#include <QDialog>
#include <QDoubleValidator>
#include <QMessageBox>

#include "card.h"
#include "allusersfile.h"
#include "transactions.h"

namespace Ui {
class Add_money_window;
}

class Add_money_window : public QDialog
{
    Q_OBJECT

public:
    explicit Add_money_window(Card*,long long,QWidget *parent = nullptr);
    ~Add_money_window();

private slots:
    void on_Cancel_button_clicked();

    void on_Add_money_button_clicked();

    void on_Add_money_line_textChanged(const QString &arg1);

private:
    Ui::Add_money_window *ui;
    Card* current_card;

    void Update_window_money();
    long long current_user_index;
};

#endif // ADD_MONEY_WINDOW_H
