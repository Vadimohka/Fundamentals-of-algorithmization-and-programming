#ifndef CIRCLEDIALOG_H
#define CIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class CircleDialog;
}

class CircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CircleDialog(QWidget *parent = nullptr);
    ~CircleDialog();

private:
    Ui::CircleDialog *ui;
signals:
    void sendCircleSignals(int value);
    void sendCheckSignal(bool);
private slots:
    void on_buttonBox_accepted();
};

#endif // CIRCLEDIALOG_H
