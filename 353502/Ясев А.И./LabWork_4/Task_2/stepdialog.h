#ifndef STEPDIALOG_H
#define STEPDIALOG_H

#include <QDialog>

namespace Ui {
class StepDialog;
}

class StepDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StepDialog(QWidget *parent = nullptr);
    ~StepDialog();
    void set(QVector<int> vector);

private:
    Ui::StepDialog *ui;
};

#endif // STEPDIALOG_H
