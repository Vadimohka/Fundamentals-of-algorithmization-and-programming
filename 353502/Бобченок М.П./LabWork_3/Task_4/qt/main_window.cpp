//
// Created by u on 09.03.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"
#include <unistd.h>

void main_window::moveRect()
{
    std::cout << 1 << " 2" <<"\n\n";
    pin[curPin].rbegin()->setX(3);
    pin[curPin].rbegin()->setY(5);

    QCoreApplication::processEvents();
    updateWindow();
}

void main_window::restart()
{
    solving = false;
}

void main_window::solve()
{
    if (solving)
        return;
    solving = true;
    rec(0, 2, pin[0].size() - 1);
}

void main_window::updateWindow()
{
    pinX[0] = -530;
    pinX[1] = -30;
    pinX[2] = 470;

    if (!solving)
    {
        ui->table->setRowCount(0);
        cur = -1;

        for (auto & i : pin)
            i.clear();

        pin[0].emplace_back(0, 0, 0, 0, 1);
        pin[1].emplace_back(0, 0, 0, 0, 1);
        pin[2].emplace_back(0, 0, 0, 0, 1);

        for (int i = ui->numOfLayers->value() - 1; i >= 0; i--)
        {
            pin[0].push_back(moving_rect(-530 - (i + 1) * 20, -(ui->numOfLayers->value() - i) * 50, 2 * (50 + i * 20), 50, 1));
            //pin2.emplace_back(-30 - (i + 1) * 20, -(ui->numOfLayers->value() - i) * 50, 2 * (50 + i * 20), 50, 1);
            //pin3.emplace_back(470 - (i + 1) * 20, -(ui->numOfLayers->value() - i) * 50, 2 * (50 + i * 20), 50, 1);
        }

        for (auto &u : pin[0])
            this->scene->addItem(&u);

        for (auto &u : pin[1])
            this->scene->addItem(&u);

        for (auto &u : pin[2])
            this->scene->addItem(&u);
    }
    else
    {
        for (auto &u : pin[0])
            std::cout << u.getW() << " "; std::cout << "\n";

        for (auto &u : pin[1])
            std::cout << u.getW() << " "; std::cout << "\n";

        for (auto &u : pin[2])
            std::cout << u.getW() << " "; std::cout << "\n";

        for (auto &u : pin[0])
            this->scene->addItem(&u);

        for (auto &u : pin[1])
            this->scene->addItem(&u);

        for (auto &u : pin[2])
            this->scene->addItem(&u);
    }
}

void main_window::moveP(int fromPin, int toPin)
{
    curPin = fromPin;
    cur++;
    ui->table->setRowCount(cur + 1);

    auto *from = new QTableWidgetItem();
    from->setText(QString::fromStdString(std::to_string(fromPin)));
    ui->table->setItem(cur, 0, from);

    auto *arrow = new QTableWidgetItem();
    arrow->setText(QString::fromStdString("           -->"));
    ui->table->setItem(cur, 1, arrow);

    auto *to = new QTableWidgetItem();
    to->setText(QString::fromStdString(std::to_string(toPin)));
    ui->table->setItem(cur, 2, to);

    int w = pin[fromPin].rbegin()->getW();
    int h = pin[fromPin].rbegin()->getH();
    int x = pin[fromPin].rbegin()->getX() + (toPin - fromPin) * 500;
    int y = pin[toPin].rbegin()->getY() - 50;

    int speed = 5 + ui->speedSlider->value() / (ui->speedSlider->maximum() / 95);
    speed *= -1;
    while (pin[fromPin].rbegin()->getY() + speed > -600)
    {
        pin[fromPin].rbegin()->setY(pin[fromPin].rbegin()->getY() + speed);

        QCoreApplication::processEvents();
        updateWindow();
    }
    pin[fromPin].rbegin()->setY(-600);

    speed = 5 + ui->speedSlider->value() / (ui->speedSlider->maximum() / 95);
    int end = pin[fromPin].rbegin()->getX() + (toPin - fromPin) * 500;
    if (end < pin[fromPin].rbegin()->getX())
    {
        speed *= -1;
        while (pin[fromPin].rbegin()->getX() + speed > end)
        {
            pin[fromPin].rbegin()->setX(pin[fromPin].rbegin()->getX() + speed);

            QCoreApplication::processEvents();
            updateWindow();
        }
    }
    else
    {
        while (pin[fromPin].rbegin()->getX() + speed < end)
        {
            pin[fromPin].rbegin()->setX(pin[fromPin].rbegin()->getX() + speed);

            QCoreApplication::processEvents();
            updateWindow();
        }
    }
    pin[fromPin].rbegin()->setX(end);

    speed = 5 + ui->speedSlider->value() / (ui->speedSlider->maximum() / 95);

    while (pin[fromPin].rbegin()->getY() + speed < y)
    {
        pin[fromPin].rbegin()->setY(pin[fromPin].rbegin()->getY() + speed);

        QCoreApplication::processEvents();
        updateWindow();
    }

    pin[toPin].push_back(moving_rect(x, y, w, h, 1));
    pin[fromPin].pop_back();
}

void main_window::rec(int fromPin, int toPin, int num)
{
    int maxSpeed = 1000000;
    if (num == 1)
    {
        usleep(maxSpeed - ui->speedSlider->value());
        moveP(fromPin, toPin);
        QCoreApplication::processEvents();
        updateWindow();

        return;
    }
    int tmp[] = {0, 0, 0};
    tmp[fromPin] = 1;
    tmp[toPin] = 1;
    for (int i = 0; i < 3; i++)
    {
        if (tmp[i] != 0)
            continue;
        rec(fromPin, i, num - 1);

        QCoreApplication::processEvents();
        updateWindow();

        rec(fromPin, toPin, 1);

        QCoreApplication::processEvents();
        updateWindow();

        rec(i, toPin, num - 1);

        QCoreApplication::processEvents();
        updateWindow();
    }
}

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window)
{

    this->scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

//    auto *w = new waggon(-400, 0, 800, 200);
//    w->setFlag(QGraphicsObject::ItemIsMovable);
//    scene->addItem(w);

    auto *mv = new moving_rect(-800, 0, 1600, 20, 2);
    scene->addItem(mv);
    mv = new moving_rect(-10, -500, 20, 500, 2);
    scene->addItem(mv);
    mv = new moving_rect(-510, -500, 20, 500, 2);
    scene->addItem(mv);
    mv = new moving_rect(490, -500, 20, 500, 2);
    scene->addItem(mv);

    auto *timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start();

    connect(ui->restartButton, SIGNAL(clicked(bool)), this, SLOT(restart()));
    connect(ui->solveButton, SIGNAL(clicked(bool)), this, SLOT(solve()));
}

main_window::~main_window()
{
    delete ui;
}
