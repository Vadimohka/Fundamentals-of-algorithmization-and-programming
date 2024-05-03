#ifndef DIALOGMODULEINPUT_H
#define DIALOGMODULEINPUT_H

#include <QDialog>

namespace Ui {
class DialogModuleInput;
}

class DialogModuleInput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModuleInput(QWidget *parent = nullptr);
    ~DialogModuleInput();

    long long getValue();

private:
    Ui::DialogModuleInput *ui;
};

#endif // DIALOGMODULEINPUT_H
