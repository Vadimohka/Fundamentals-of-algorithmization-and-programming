#ifndef RHOMBUSDIALOG_H
#define RHOMBUSDIALOG_H

#include <QDialog>

namespace Ui {
class RhombusDialog;
}

class RhombusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RhombusDialog(QWidget *parent = nullptr);
    ~RhombusDialog();
signals:
    void sendRhombusSignals(int a, int b);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::RhombusDialog *ui;
};

#endif // RHOMBUSDIALOG_H
