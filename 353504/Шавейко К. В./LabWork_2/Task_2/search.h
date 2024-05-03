#ifndef BUTTON_H
#define BUTTON_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class button;
}

class button : public QDialog
{
    Q_OBJECT

public:
    explicit button(QWidget *parent = nullptr);
    ~button();

private slots:

    void on_pushButton_clicked();

private:
    Ui::button *ui;
};

#endif // BUTTON_H
