#ifndef RESTARAUNTMENU_H
#define RESTARAUNTMENU_H

#include <QDialog>

namespace Ui {
class RestarauntMenu;
}

class RestarauntMenu : public QDialog
{
    Q_OBJECT

public:
    explicit RestarauntMenu(QWidget *parent = nullptr);
    ~RestarauntMenu();

private:

    QVector < QString > dishesName;
    QMap < QString , long long > dishesPrice;

private:
    Ui::RestarauntMenu *ui;
    void putToTable();
};

#endif // RESTARAUNTMENU_H
