#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include "QLineEdit"
#include "QPushButton"
#include "QGridLayout"
#include "QLabel"
#include "statement.h"
#include "checkstr.h"
#include "QIntValidator"

class DialogEdit : public QDialog
{
    Q_OBJECT
public:
    explicit DialogEdit(QWidget *parent = nullptr);
    DialogEdit(Statement *good,int number, QWidget *parent);
    ~DialogEdit();

    int number;

    QLineEdit *group_line;
    QLineEdit *code_line;
    QLineEdit *name_line;
    QLineEdit *model_line;
    QLineEdit *price_line;
    QLineEdit *count_line;

    QLabel *group_label;
    QLabel *code_label;
    QLabel *name_label;
    QLabel *model_label;
    QLabel *price_label;
    QLabel *count_label;

    QPushButton *save_button;
    QPushButton *cancel_button;

    QGridLayout *layout;

    bool CheckAddLinesCorrect();

    void SaveButtonClick();

signals:

    void EditSignal(int count, int price, QString model, QString name, int code, QString group, int number);
};

#endif // DIALOGEDIT_H
