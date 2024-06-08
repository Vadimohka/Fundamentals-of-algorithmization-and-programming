#ifndef STRUCTINPUTDIALOG_H
#define STRUCTINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <auto.h>

namespace Ui {
class StructInputDialog;
}

class StructInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StructInputDialog(QWidget*, Auto*);
    ~StructInputDialog();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int);

private:
    Ui::StructInputDialog *ui;
    Auto* a;
    Auto input;
};

#endif // STRUCTINPUTDIALOG_H
