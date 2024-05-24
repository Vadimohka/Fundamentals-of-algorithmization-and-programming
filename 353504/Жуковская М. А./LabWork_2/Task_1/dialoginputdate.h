#ifndef DIALOGINPUTDATE_H
#define DIALOGINPUTDATE_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <date.h>

namespace Ui {
class DialogInputDate;
}

class DialogInputDate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputDate(QWidget *parent = nullptr);
    ~DialogInputDate();

    Date getDate();
    void setDate(Date date);

private:
    Ui::DialogInputDate *ui;
};

#endif // DIALOGINPUTDATE_H
