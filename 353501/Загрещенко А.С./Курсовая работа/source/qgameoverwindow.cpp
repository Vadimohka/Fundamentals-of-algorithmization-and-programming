#include "qgameoverwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QResizeEvent>
#include <QLabel>



qGameOverWindow::qGameOverWindow(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("QGameOverWindow {background: rgb(237,224,200); }");
    setFixedSize(425,205);
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel {color: rgb(119,110,101); font: 40pt; font: bold;} ");

    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(100);

    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    layout->insertWidget(1,reset,0,Qt::AlignCenter);

}

QResetButton *qGameOverWindow::GetResetButton() const
{
    return reset;
}
