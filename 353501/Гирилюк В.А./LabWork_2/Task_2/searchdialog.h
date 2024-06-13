#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QTableWidget>

#include "product.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

    void getList(QVector<Product>& gettingList);

    void search();

private slots:
    void on_completeRadioButton_clicked();

    void on_incompleteRadioButton_clicked();

    void on_searchGroup_editingFinished();

    void on_searchBrandEditLine_editingFinished();

    void on_acceptanceDateEditLine_editingFinished();

    void on_executionDateEditLIne_editingFinished();

    void on_unknownRadioButton_clicked();

    void setProductRow(int row, int index);

private:
    Ui::SearchDialog *ui;
    QVector<Product> dialogList;
    bool complete = false;
    bool unknown = true;
};

#endif // SEARCHDIALOG_H
