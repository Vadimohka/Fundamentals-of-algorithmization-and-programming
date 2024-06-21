#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <QDialog>

#include "canvas.h"

namespace Ui {
class paintWindow;
}

class paintWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::paintWindow *ui;

    Canvas *scene;

public:
    explicit paintWindow(QWidget *parent = nullptr);
    ~paintWindow() override;

public slots:
    void getSize(int, int);
};

#endif // PAINTWINDOW_H
