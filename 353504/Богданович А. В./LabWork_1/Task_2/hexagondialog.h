#ifndef HEXAGONDIALOG_H
#define HEXAGONDIALOG_H

#include <QDialog>

namespace Ui {
class HexagonDialog;
}

class HexagonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HexagonDialog(QWidget *parent = nullptr);
    ~HexagonDialog();
signals:
    void sendHexagonSignals(int);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::HexagonDialog *ui;
};

#endif // HEXAGONDIALOG_H
