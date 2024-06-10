#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>

namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(QWidget *parent = nullptr);
    ~StatsDialog();

    void setInfo(int err, double accur, double wpm);

public slots:
    void closeDialog();

private:
    Ui::StatsDialog *ui;

    int errors;
    double accuracy;
    double wpm;
};

#endif // STATSDIALOG_H
