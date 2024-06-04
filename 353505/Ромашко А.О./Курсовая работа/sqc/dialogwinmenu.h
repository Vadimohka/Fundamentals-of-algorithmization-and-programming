#ifndef DIALOGWINMENU_H
#define DIALOGWINMENU_H

#include <QDialog>
#include <QString>
#include "card.h"
namespace Ui {
class DialogWinMenu;
}

class DialogWinMenu : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWinMenu(QWidget *parent = nullptr);
    ~DialogWinMenu();
    void takeInfoMONEYCARDHP(int m,Card *c,int h);
public slots:
    void open();
private:
    Ui::DialogWinMenu *ui;
    int money;
    Card *card;
    int hp;
};

#endif // DIALOGWINMENU_H
