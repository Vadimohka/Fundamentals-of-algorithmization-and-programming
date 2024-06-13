#ifndef INCOMPLETEINTIMEDIALOG_H
#define INCOMPLETEINTIMEDIALOG_H

#include <QDialog>
#include <QTableWidget>

#include "product.h"

namespace Ui {
class IncompleteInTimeDialog;
}

class IncompleteInTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncompleteInTimeDialog(QWidget *parent = nullptr);
    ~IncompleteInTimeDialog();

    void getList(QVector<Product>& gettingList);

    void fillTableWidget();

private:
    Ui::IncompleteInTimeDialog *ui;
    QVector<Product> dialogList;
};

#endif // INCOMPLETEINTIMEDIALOG_H
