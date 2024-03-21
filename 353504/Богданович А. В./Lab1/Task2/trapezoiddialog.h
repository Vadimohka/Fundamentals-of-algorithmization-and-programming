#ifndef TRAPEZOIDDIALOG_H
#define TRAPEZOIDDIALOG_H

#include <QDialog>

namespace Ui {
class TrapezoidDialog;
}

class TrapezoidDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrapezoidDialog(QWidget *parent = nullptr);
    ~TrapezoidDialog();

signals:
    void sendTrapezoidSignals(int, int, int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TrapezoidDialog *ui;
};

#endif // TRAPEZOIDDIALOG_H
