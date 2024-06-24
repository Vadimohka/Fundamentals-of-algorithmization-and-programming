#ifndef STRUCTINPUTDIALOG_H
#define STRUCTINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <car.h>

namespace Ui {
class StructInputDialog;
}

class StructInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StructInputDialog(QWidget*, Car*);
    ~StructInputDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StructInputDialog *ui;
    Car* a;
    Car input;
};

#endif // STRUCTINPUTDIALOG_H
