#ifndef DIALOGCONDIDATE_H
#define DIALOGCONDIDATE_H

#include <QDialog>
#include "Condidate.h"

namespace Ui {
class DialogCondidate;
}

class DialogCondidate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCondidate(QWidget *parent = nullptr);
    ~DialogCondidate();

    void closeEvent(QCloseEvent* event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogCondidate *ui;
};

#endif // DIALOGCONDIDATE_H
