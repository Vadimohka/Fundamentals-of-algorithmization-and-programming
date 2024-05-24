#ifndef DATELINEEDIT_H
#define DATELINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class DateLineEdit : public QLineEdit
{
public:
    DateLineEdit();

    void keyPressEvent(QKeyEvent *event) override;
};

#endif // DATELINEEDIT_H
