#ifndef TRANSFER_MONEY_WINDOW_H
#define TRANSFER_MONEY_WINDOW_H

#include <QDialog>

#include "transactions.h"
#include <QRegularExpression>
#include <QMessageBox>
#include "luna.h"


namespace Ui {
class Transfer_money_window;
}

class Transfer_money_window : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer_money_window(QWidget *parent = nullptr);
    ~Transfer_money_window();

private slots:
    void on_Cancel_button_clicked();

    void on_Transfer_button_clicked();

    bool Is_lines_right();

    bool Is_line_exist(int,QString, long long&);

    bool Cvv_check(int, long long);


private:
    Ui::Transfer_money_window *ui;
    long long current_user_index;
};

#endif // TRANSFER_MONEY_WINDOW_H
