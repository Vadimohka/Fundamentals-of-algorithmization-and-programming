#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>

namespace Ui {
class TriangleDialog;
}

class TriangleDialog : public QDialog
{
    Q_OBJECT

public:

    explicit TriangleDialog(QWidget *parent = nullptr);
    ~TriangleDialog();

private slots:
    void on_buttonBox_accepted();

private:

    Ui::TriangleDialog *ui;
signals:
    void sendTriangleSignals(int value);
};

#endif // TRIANGLEDIALOG_H
