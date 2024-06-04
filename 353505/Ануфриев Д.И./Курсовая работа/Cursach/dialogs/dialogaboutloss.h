#ifndef DIALOGABOUTLOSS_H
#define DIALOGABOUTLOSS_H

#include <QDialog>

namespace Ui {
class DialogAboutLoss;
}

class DialogAboutLoss : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAboutLoss(QWidget *parent = nullptr);
    ~DialogAboutLoss();

private:
    Ui::DialogAboutLoss *ui;
};

#endif // DIALOGABOUTLOSS_H
