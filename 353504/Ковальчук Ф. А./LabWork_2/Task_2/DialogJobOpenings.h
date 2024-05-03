#ifndef DIALOGJOBOPENINGS_H
#define DIALOGJOBOPENINGS_H

#include <QDialog>
#include "JobOpenings.h"

namespace Ui {
class DialogJobOpenings;
}

class DialogJobOpenings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJobOpenings(QWidget *parent = nullptr);
    ~DialogJobOpenings();

private slots:
    void on_pushButton_clicked();

    void closeEvent(QCloseEvent* event);

private:
    Ui::DialogJobOpenings *ui;
};

#endif // DIALOGJOBOPENINGS_H
