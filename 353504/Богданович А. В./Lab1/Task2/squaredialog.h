#ifndef SQUAREDIALOG_H
#define SQUAREDIALOG_H

#include <QDialog>

namespace Ui {
class SquareDialog;
}

class SquareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SquareDialog(QWidget *parent = nullptr);
    ~SquareDialog();

private slots:
    void on_buttonBox_accepted();
signals:
    void sendSquareSignals(int a);

private:
    Ui::SquareDialog *ui;
};

#endif // SQUAREDIALOG_H
