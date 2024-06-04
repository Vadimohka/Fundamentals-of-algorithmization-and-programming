
#pragma once

#include <QWidget>

namespace Ui {class WinScreen; }

// This UI widget is the screen displayed when winning the game
class WinScreen : public QWidget
{
    Q_OBJECT

public:
    // Constructor and destructor
    explicit WinScreen(int score, int moves, QString time, QWidget *parent = nullptr);
    ~WinScreen();

private:
    // Overwritten mouse events
    void mousePressEvent(QMouseEvent* ev) override;

    // Overwritten close event
    void closeEvent(QCloseEvent* ev) override;

private:
    Ui::WinScreen *ui;
};
