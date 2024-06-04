#ifndef STRUCTINPUTDIALOG_H
#define STRUCTINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <ship.h>

namespace Ui {
class StructInputDialog;
}

class StructInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StructInputDialog(QWidget*, Ship*);
    ~StructInputDialog();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int);

private:
    Ui::StructInputDialog *ui;
    Ship* a;
    Ship input;
};

#endif // STRUCTINPUTDIALOG_H
