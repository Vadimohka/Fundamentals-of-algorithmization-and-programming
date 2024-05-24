#ifndef FINDELEMENT_H
#define FINDELEMENT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class FIndElement;
}

class FIndElement : public QDialog
{
    Q_OBJECT

public:
    explicit FIndElement(QWidget *parent = nullptr);
    ~FIndElement();

private slots:
    void on_pushButtonEnter_clicked();

private:
    Ui::FIndElement *ui;
    long long QStrToLong( QString s );
};

#endif // FINDELEMENT_H
