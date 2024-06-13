#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    void continuePlay();

    void backToMainMenu();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
