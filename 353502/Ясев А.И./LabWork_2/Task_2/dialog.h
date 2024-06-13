#ifndef DIALOG_H
#define DIALOG_H

#include "good.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Good getGood();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
