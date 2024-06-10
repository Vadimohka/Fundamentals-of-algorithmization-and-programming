#pragma once

#include <QtWidgets>
#include "figureView.h"
#include "carView.h"

class ApplicationWindow : public QWidget {
    Q_OBJECT
public:
    explicit ApplicationWindow(QWidget *pobj = nullptr);

private:
    figureView *figure = new figureView;
    carView *car = new carView;

private slots:
    void handleCloseButtonClicked();
    void handleFigureButtonClicked();
    void handleCarButtonClicked();

protected:
};
