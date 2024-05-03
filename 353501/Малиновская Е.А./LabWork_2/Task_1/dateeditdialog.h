#ifndef DATEEDITDIALOG_H
#define DATEEDITDIALOG_H

#include <QDialog>
#include "date.h"
#include "ui_dateeditdialog.h"

namespace Ui {
class DateEditDialog;
}

class DateEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateEditDialog(const Date& date, QWidget *parent = nullptr);
    ~DateEditDialog();

    Date getEditedDate() const;
    void setEditedDate(const Date& date);
signals:
    void dateEdited(const Date& editedDate);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DateEditDialog *ui;
    Date editedDate;
};

#endif // DATEEDITDIALOG_H
