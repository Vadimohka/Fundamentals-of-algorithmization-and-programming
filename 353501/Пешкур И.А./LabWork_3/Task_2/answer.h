#ifndef ANSWER_H
#define ANSWER_H

#include <QDialog>

namespace Ui {
class Answer;
}

class Answer : public QDialog
{
    Q_OBJECT

public:
    explicit Answer(QWidget *parent = nullptr);
    ~Answer();

private:
    Ui::Answer *ui;

public:

    void setAnswer( long long Ans );

};

#endif // ANSWER_H
