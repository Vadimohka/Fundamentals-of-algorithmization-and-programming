#ifndef DIALOGINPUTPUSHBACK_H
#define DIALOGINPUTPUSHBACK_H

#include <QDialog>

namespace Ui {
class DialogInputPushBack;
}

class DialogInputPushBack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputPushBack(QWidget *parent = nullptr);
    ~DialogInputPushBack();

    int getValue();
    void setRange(int min, int max);
    void setValue(int value);

private:
    Ui::DialogInputPushBack *ui;
};

#endif // DIALOGINPUTPUSHBACK_H
