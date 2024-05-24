#include "../Headers/Widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget* w = new Widget;

    Fire* fire = new Fire(w);

    Rocket* rocket = new Rocket(w);

    Widget* layer1 = new Widget(w);

    layer1->setGeometry(925,275,50,50);

    QPushButton* MoveButton = new QPushButton("^",layer1);

    MoveButton->setGeometry(0,0,50,50);

    w->setMaximumSize(1000,600);
    w->setMinimumSize(1000,600);

    rocket->move(450,400);
    fire->move(485,530);

    Rocket::connect(MoveButton, SIGNAL(pressed()), rocket, SLOT(MoveObject()));

    Rocket::connect(MoveButton, SIGNAL(released()), rocket, SLOT(StopMoving()));

    Rocket::connect(MoveButton, SIGNAL(pressed()), fire, SLOT(MoveObject()));

    Rocket::connect(MoveButton, SIGNAL(released()), fire, SLOT(StopMoving()));

    w->show();
    return a.exec();
}
