#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

#include "Animal.h"

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();

public slots:
    void onEnterClicked();

signals:
    void animalEntered(Animal);

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
