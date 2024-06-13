#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getInt();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
