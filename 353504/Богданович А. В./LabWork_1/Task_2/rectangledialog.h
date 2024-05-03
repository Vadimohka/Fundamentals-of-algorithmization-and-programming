#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H

#include <QDialog>

namespace Ui {
class RectangleDialog;
}

class RectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RectangleDialog(QWidget *parent = nullptr);
    ~RectangleDialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendRectangleSignals(int a, int b);

private:
    Ui::RectangleDialog *ui;
};

#endif // RECTANGLEDIALOG_H
