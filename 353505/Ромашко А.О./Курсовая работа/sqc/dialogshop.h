#ifndef DIALOGSHOP_H
#define DIALOGSHOP_H

#include <QDialog>
#include "player.h"

namespace Ui {
class DialogShop;
}

class DialogShop : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShop(QWidget *parent = nullptr);
    ~DialogShop();
    void getPlayer(Player *v){this->player=v;}
public slots:
    void openSlot();
private slots:
    void on_pushButton_EasyP_clicked();
    void on_buttonBox_accepted();

    void on_pushButton_add50hp_clicked();

signals:
     void showLines();
private:
    Ui::DialogShop *ui;
    bool epath=0;
    Player *player;
};

#endif // DIALOGSHOP_H
