#ifndef STARDIALOG_H
#define STARDIALOG_H

#include <QDialog>

namespace Ui {
class StarDialog;
}

class StarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StarDialog(QWidget *parent = nullptr);
    ~StarDialog();

signals:
    void sendStarSignals(float, float);
    void sendRBtnsSignal(int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StarDialog *ui;
};

#endif // STARDIALOG_H
