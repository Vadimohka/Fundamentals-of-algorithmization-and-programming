#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);

    mainLayout = new QHBoxLayout;
    widget->setLayout(mainLayout);

    moves = new QTextEdit(this);
    moves->setReadOnly(true);
    moves->setGeometry(200, 50, 80, 120);

    start = new QPushButton("Start", this);
    start->setGeometry(50, 50, 100, 50);

    stop = new QPushButton("Stop", this);
    stop->setGeometry(50, 120, 100, 50);

    restart = new QPushButton("Restart", this);
    restart->setGeometry(50, 190, 100, 50);
    ringsCountLabel = new QLabel("Ring count: ", this);
    ringsCountLabel->setGeometry(50, 260, 100, 20);

    ringCount = new QSpinBox(this);
    ringCount->setMinimum(3);
    ringCount->setMaximum(8);
    ringCount->setGeometry(50, 300, 100, 50);
    ringCount->setValue(3);

    view = new QGraphicsView(this);
    mainScene = new QGraphicsScene(this);

    view->setScene(mainScene);

    mainScene->setSceneRect(0, 0, 800, 600);
    mainLayout->addWidget(view);

    for (int i = 0; i < 3; i++) {
        rodRings.push_back(stack<Ring *>());
    }

    for (int i = 0; i < 3; i++) {
        Rods *rod = new Rods(i);
        rods.push_back(rod);
        Bases *base = new Bases(i);
        bases.push_back(base);
        rod->setBrush(Qt::black);
        base->setBrush(Qt::black);
        mainScene->addItem(rod);
        mainScene->addItem(base);
    }
    QColor ringColors[] = {Qt::red, Qt::green, Qt::blue};
    for (int i = 0; i < 3; i++) {
        Ring *ring = new Ring(i, ringColors[i]);

        rings.push_back(ring);
        rodRings[0].push(ring);

        ring->setPos(10 - (200 - i * 20) / 2, 600 - (i + 1) * 30);

        ring->setBrush(ringColors[i]);

        mainScene->addItem(ring);
    }
    timer = new QTimer(this);
    animation = new QGraphicsItemAnimation;
    time = new QTimeLine(1000);
    connect(ringCount, SIGNAL(valueChanged(int)), this, SLOT(RestartHanoi()));
    connect(timer, &QTimer::timeout, this, &MainWindow::execAction);
    connect(start, SIGNAL(clicked()), this, SLOT(StartHanoi()));
    connect(stop, SIGNAL(clicked()), this, SLOT(StopHanoi()));
    connect(restart, SIGNAL(clicked()), this, SLOT(RestartHanoi()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execAction()
{
    if (currActionID < actions.size() && animation != nullptr) {
        Action action = actions[currActionID];
        currActionID++;
        moveRing(action.fromRod, action.toRod);
    } else {
        timer->stop();

        finish = true;
    }
}

QPointF MainWindow::calcPos(int rodID, int ringCount, int ringW, int rodW)
{
    int x = rodID * 400 + rodW / 2 - ringW / 2;
    int y = 600 - (ringCount) *30;
    return QPointF(x, y);
}

void MainWindow::generateActions(int n, int fromRod, int toRod, int auxRod)
{
    if (n < 1) {
        return;
    }
    if (n == 1) {
        actions.append({fromRod, toRod});
        return;
    }
    generateActions(n - 1, fromRod, auxRod, toRod);
    actions.append({fromRod, toRod});
    generateActions(n - 1, auxRod, toRod, fromRod);
}

void MainWindow::RestartHanoi()
{
    int newRingCount = ringCount->value();

    for (Ring *ring : rings) {
        mainScene->removeItem(ring);
        delete ring;
    }
    rings.clear();
    actions.clear();
    moves->clear();
    for (int i = 0; i < 3; i++) {
        while (!rodRings[i].empty()) {
            rodRings[i].pop();
        }
    }

    currActionID = 0;

    for (int i = 0; i < newRingCount; i++) {
        Ring *ring = new Ring(i, ringColors[i]);

        rings.push_back(ring);
        rodRings[0].push(ring);

        ring->setPos(10 - (200 - i * 20) / 2, 600 - (i + 1) * 30);

        ring->setBrush(ringColors[i]);

        mainScene->addItem(ring);
    }
    finish = false;

    if (timer != nullptr) {
        delete timer;
        timer = nullptr;
    }
    if (animation != nullptr) {
        delete animation;
        animation = nullptr;
    }
    if (time != nullptr) {
        delete time;
        time = nullptr;
    }
    timer = new QTimer(this);
    animation = new QGraphicsItemAnimation;
    time = new QTimeLine(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::execAction);
}

void MainWindow::moveRing(int fromRod, int toRod)
{
    if (!rodRings[fromRod].empty() && !finish) {
        Ring *ring = rodRings[fromRod].top();
        rodRings[fromRod].pop();
        rodRings[toRod].push(ring);

        int ringW = ring->rect().width();
        int rodW = rods[0]->rect().width();

        QPointF startPos = ring->pos();
        QPointF endPos = calcPos(toRod, rodRings[toRod].size(), ringW, rodW);
        QPointF upPos = QPointF(startPos.x(), 300);
        QPointF downPos = QPointF(endPos.x(), 300);

        animation = new QGraphicsItemAnimation;
        time = new QTimeLine(1000);
        animation->setTimeLine(time);
        animation->setItem(ring);
        animation->setPosAt(0, startPos);
        animation->setPosAt(0.33, upPos);
        animation->setPosAt(0.66, downPos);
        animation->setPosAt(1, endPos);
        time->start();

        QString moveText = QString("%1 -> %2").arg(rodMoves[fromRod]).arg(rodMoves[toRod]);
        moves->append(moveText);
    }
}

void MainWindow::StartHanoi()
{
    if (!finish) {
        if (timer != nullptr) {
            disconnect(timer, &QTimer::timeout, this, &MainWindow::execAction);
            delete timer;
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::execAction);

        if (timer != nullptr && timer->isActive()) {
            return;
        }

        generateActions(rodRings[0].size(), 0, 2, 1);
        if (pause && time != nullptr) {
            time->setCurrentTime(progress);
            time->start();
        }
        timer->start(1000);
    }
}

void MainWindow::StopHanoi()
{
    if (timer != nullptr && timer->isActive()) {
        timer->stop();
    }
    if (animation != nullptr && time != nullptr) {
        progress = time->currentTime();
        time->stop();
        pause = true;
    }
}
