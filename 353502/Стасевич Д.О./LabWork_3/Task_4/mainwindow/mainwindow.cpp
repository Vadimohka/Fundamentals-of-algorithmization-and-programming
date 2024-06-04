#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>


mainwindow::mainwindow(): ui(new Ui::mainwindow), scene (new QGraphicsScene(this)) {

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(perform_task(int)));

    left_tick = new QTimer(this);
    right_tick = new QTimer(this);
    up_tick = new QTimer(this);
    down_tick = new QTimer(this);
    auto *global_timer = new QTimer(this);

    left_tick->setInterval(10);
    right_tick->setInterval(10);
    up_tick->setInterval(10);
    down_tick->setInterval(10);
    global_timer->setInterval(20);

    connect(left_tick, SIGNAL(timeout()), this, SLOT(on_leftmove()));
    connect(right_tick, SIGNAL(timeout()), this, SLOT(on_rightmove()));
    connect(up_tick, SIGNAL(timeout()), this, SLOT(on_upmove()));
    connect(down_tick, SIGNAL(timeout()), this, SLOT(on_downmove()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(animate()));
    connect(ui->pushButton, SIGNAL(pressed()), global_timer, SLOT(start()));
    connect(ui->pushButton, SIGNAL(released()), global_timer, SLOT(stop()));
    connect(global_timer, SIGNAL(timeout()), this, SLOT(animate()));

    //  connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(animate()));
}

void mainwindow::perform_task(int n) {
    ui->textEdit->clear();
    answer = Hanoi::hanoi(n, 1, 3);
    for(int i = 0; i < answer.size(); i += 2)
    {
        ui->textEdit->append("move disk from tower " + answer[i] + " to tower " + answer[i + 1]);
    }
    if(!on_scene)
    {
        scene->addItem(towersbase);
        on_scene = 1;
    }
    else
    {
        scene->removeItem(towersbase);
        scene->addItem(towersbase);
        for(int i = 0; i < 4; i ++)
        {
            for(auto x : tower[i])
            {
                scene->removeItem(x);
            }
        }
    }
    cur = 0;
    tower[0].clear();
    tower[1].clear();
    tower[2].clear();
    tower[3].clear();


    double mx_w = 160;
    for(int i = 1; i <= n; i ++)
    {
        MovingRectangle *r = new MovingRectangle(-270 + (i - 1) * h, 100 - 10 * i, mx_w - 10 * (i - 1));
        tower[1].push_back(r);
        scene->addItem(r);
/*        r = new MovingRectangle(-70 + (i - 1) * 5, 100 - 10 * i, mx_w - 10 * (i - 1));
        tower[2].push_back(r);
        scene->addItem(r);
        r = new MovingRectangle(130 + (i - 1) * 5, 100 - 10 * i, mx_w - 10 * (i - 1));
        tower[2].push_back(r);
        scene->addItem(r);
*/
    }


}

void mainwindow::on_downmove() {
    if(reach_2 == 0)
        return;
    if(currentrectangle->getY() == down_mx)
    {
        reach_3 = 1;
        down_tick->stop();
        is_animated = 0;
        return;
    }
    currentrectangle->move(0, h);
}

void mainwindow::on_leftmove() {
    if(reach_1 == 0)
        return;
    if(currentrectangle->getX() == stop_pos)
    {
        reach_2 = 1;
        left_tick->stop();
        return;
    }
    currentrectangle->move(-h, 0);
}

void mainwindow::on_rightmove() {
    if(reach_1 == 0)
        return;
    if(currentrectangle->getX() == stop_pos)
    {
        reach_2 = 1;
        right_tick->stop();
        return;
    }
    currentrectangle->move(h, 0);
}

void mainwindow::on_upmove() {
    if(currentrectangle->getY() <= up_mx)
    {
        reach_1 = 1;
        up_tick->stop();
        return;
    }
    currentrectangle->move(0, -h);
}

void mainwindow::animate() {
    if(is_animated == 1 || cur >= answer.size())
        return;
    is_animated = 1;
    auto st = ((QString)answer[cur]).toInt();
    auto fin = ((QString)answer[cur + 1]).toInt();

    func(st, fin);
    cur += 2;
}

void mainwindow::func(int st, int fin) {
    if(reach_3 == 0)
        return;
    reach_1 = 0, reach_2 = 0, reach_3 = 0;
    currentrectangle = tower[st].back();
    tower[fin].push_back(tower[st].back());
    stop_pos = centre[fin] - currentrectangle->getW() / 2;
    down_mx = 100 - 10 * tower[fin].size();
    up_tick->start();
    if (st < fin) {
        right_tick->start();
    } else {
        left_tick->start();
    }
    down_tick->start();
    tower[st].pop_back();

}
