#ifndef GROUPCOMPLETE_H
#define GROUPCOMPLETE_H

#include <QDialog>
#include <QTableWidget>

#include "product.h"

namespace Ui {
class GroupComplete;
}

class GroupComplete : public QDialog
{
    Q_OBJECT

public:
    explicit GroupComplete(QWidget *parent = nullptr);
    ~GroupComplete();

    void getList(QVector<Product>& gettingList);

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::GroupComplete *ui;
    QVector<Product> dialogList;
    QString aimGroup;
};

#endif // GROUPCOMPLETE_H
