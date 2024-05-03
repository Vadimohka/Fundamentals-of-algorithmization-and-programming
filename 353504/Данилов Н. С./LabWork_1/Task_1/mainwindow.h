#pragma once

#include <QtWidgets>
#include "figurewindow.h"
#include "soldierwindow.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *pobj = nullptr);

private:
    figureWindow *figure = new figureWindow;
    soldierWindow *soldier = new soldierWindow;
    bool aaaa = false;

private slots:
    void on_closeButton_clicked();

    void on_figureButton_clicked();

    void on_soldierButton_clicked();


protected:
};
