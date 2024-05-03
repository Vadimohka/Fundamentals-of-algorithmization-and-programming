#ifndef TRYAGAIN_H
#define TRYAGAIN_H

#include <QDialog>
#include "hanoibashni.h"

namespace Ui {
class TryAgain;
}

class TryAgain : public QDialog
{
    Q_OBJECT

public:
    explicit TryAgain(QWidget *parent = nullptr);
    ~TryAgain();
    void ChangeMem( long long a );

private slots:
    void on_pushButtonAgain_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::TryAgain *ui;
    long long mem;
};

#endif // TRYAGAIN_H
