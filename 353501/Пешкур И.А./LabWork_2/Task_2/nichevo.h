#ifndef NICHEVO_H
#define NICHEVO_H

#include <QDialog>

namespace Ui {
class Nichevo;
}

class Nichevo : public QDialog
{
    Q_OBJECT

public:
    explicit Nichevo(QWidget *parent = nullptr);
    ~Nichevo();

private:
    Ui::Nichevo *ui;
};

#endif // NICHEVO_H
