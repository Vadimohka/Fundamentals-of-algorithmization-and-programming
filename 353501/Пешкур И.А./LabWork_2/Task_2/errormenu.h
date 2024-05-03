#ifndef ERRORMENU_H
#define ERRORMENU_H

#include <QDialog>

namespace Ui {
class ErrorMenu;
}

class ErrorMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorMenu(QWidget *parent = nullptr);
    ~ErrorMenu();

private:
    Ui::ErrorMenu *ui;
};

#endif // ERRORMENU_H
