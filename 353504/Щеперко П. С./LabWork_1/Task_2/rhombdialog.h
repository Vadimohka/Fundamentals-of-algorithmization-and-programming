#ifndef RHOMBDIALOG_H
#define RHOMBDIALOG_H

#include <QDialog>

namespace Ui {
class RhombDialog;
}

class RhombDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RhombDialog(QWidget *parent = nullptr);
    ~RhombDialog();
signals:
    void sendRhombSignals(int a, int b);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::RhombDialog *ui;
};

#endif // RHOMBUSDIALOG_H
