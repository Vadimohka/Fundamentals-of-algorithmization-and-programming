#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    bool soundon= true;

    Ui::FirstWindow *ui;
    MainWindow *sFirstWindow;
};

#endif // FIRSTWINDOW_H
