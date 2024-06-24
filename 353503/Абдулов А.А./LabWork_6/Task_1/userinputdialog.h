#ifndef USERINPUTDIALOG_H
#define USERINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <car.h>

namespace Ui {
class UserInputDialog;
}

class UserInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserInputDialog(QWidget* = nullptr);
    ~UserInputDialog();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int);

signals:
    void inputInit(Car);

private:
    Ui::UserInputDialog *ui;
    Car input;
};

#endif // USERINPUTDIALOG_H
