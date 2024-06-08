#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include <QTimer>
#include "comp.h"

namespace Ui {
class Input;
}

class Input : public QWidget
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = nullptr);
    ~Input();

private slots:
    void on_bnt_send_clicked();

signals:
    void buttonClicked(Animal an);

private:
    Ui::Input *ui;
    Animal temp;
    QTimer *timer;
};

#endif // INPUT_H
