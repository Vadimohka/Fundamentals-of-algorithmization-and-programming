#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = nullptr;
    scene = nullptr;

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::updateGame));
    timer->start(1000/FRAME_RATE);

    menuMusic = new QMediaPlayer();
    gameMusic = new QMediaPlayer();

    menuMusic->setMedia(QUrl("qrc:/music/MenuMusic.mp3"));
    menuMusic->setVolume(100);
    connect(menuMusic, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::repeatMusic);
    menuMusic->play();

    gameMusic = new QMediaPlayer();
    connect(gameMusic, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::repeatMusic);
    gameMusic->setMedia(QUrl("qrc:/music/Alone Against Enemy.ogg"));
    gameMusic->setVolume(50);

    esc = new QShortcut(QKeySequence(Qt::Key_Escape), this);

    diff = Difficulty::EASY;
    selectedLevel = 0;
}

void MainWindow::updateGame()
{
    float deltaTime = dtTimer.elapsed() * 0.001f;
    if(scene)
    {
        if(scene->isOver)
        {
            gameMusic->stop();
            QMessageBox msgBox;
            msgBox.setText("Игра оконечена. Хотите попробовать ещё раз?");
            QPushButton *replayButton = msgBox.addButton("Попровать ещё раз", QMessageBox::ActionRole);
            msgBox.addButton("Вернуться в меню", QMessageBox::ActionRole);

            msgBox.exec();

            if (msgBox.clickedButton() == replayButton) {
                scene->Destroy();
                beginGame();
            }
            else
            {
                returnToMenu();
                return;
            }
        }

        scene->Update(deltaTime);

    }
    dtTimer.start();
}

void MainWindow::on_startButton_clicked()
{
    setupGame();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(!scene) return;

    auto pl = scene->GetObjectsOfClass<Player>();

    if(pl.size() > 0)
    {
        player = pl[0];
        if(player && !scene->isPaused)
        {
            player->keyPressEvent(e);
        }
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(!scene) return;

    auto pl = scene->GetObjectsOfClass<Player>();

    if(pl.size() > 0)
    {
        player = pl[0];
        if(player && !scene->isPaused)
        {
            player->keyReleaseEvent(e);
        }
    }


}

void MainWindow::setupGame()
{
    assert(!view);
    assert(!scene);

    menuMusic->stop();

    enableEscKey();

    scene = new GameScene();
    scene->setSceneRect(0, 0, 1024, 768);

    view = new QGraphicsView(scene, this);
    view->setFixedSize(1024, 768);
    view->setFocusPolicy(Qt::NoFocus);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(view);

    beginGame();
}

void MainWindow::beginGame()
{
    assert(scene);

    scene->Start(selectedLevel * 3);
    gameMusic->play();
    auto pl = scene->GetObjectsOfClass<Player>();

    if(pl.size() > 0)
    {
        player = pl[0];
    }
    assert(player);

    switch(diff)
    {
    case EASY:
        player->diffFactor = 0.5f;
        break;
    case MEDIUM:
        player->diffFactor = 0.8f;
        break;
    case HARD:
        player->diffFactor = 1.2f;
        break;
    }
}

void MainWindow::returnToMenu()
{
    disableEscKey();

    scene->Destroy();

    setCentralWidget(nullptr);
    view = nullptr;
    scene = nullptr;

    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(selectedLevel);
    gameMusic->stop();
    menuMusic->play();
}

void MainWindow::enableEscKey()
{
    connect(esc, &QShortcut::activated, this, &MainWindow::askToQuit);
}

void MainWindow::disableEscKey()
{
    disconnect(esc, &QShortcut::activated, this, &MainWindow::askToQuit);
}

void MainWindow::repeatMusic(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        QMediaPlayer *player = qobject_cast<QMediaPlayer *>(sender());
        player->setPosition(0);
        player->play();
    }
}

void MainWindow::askToQuit()
{
    scene->isPaused = true;
    gameMusic->pause();
    QMessageBox msgBox;
    msgBox.setText("Вы уверены, что хотите выйти?");
    QPushButton *quitButton = msgBox.addButton(tr("Выход"), QMessageBox::ActionRole);
    QPushButton *returnToMenuButton = msgBox.addButton(tr("Вернуться в меню"),
                                                       QMessageBox::ActionRole);
    QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);

    msgBox.exec();

    if (msgBox.clickedButton() == quitButton) {
        QApplication::quit();
    } else if (msgBox.clickedButton() == returnToMenuButton) {
        returnToMenu();
    } else if (msgBox.clickedButton() == cancelButton) {
        scene->isPaused = false;
        gameMusic->play();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_radioButton_Easy_clicked(bool checked)
{
    if(checked)
    {
        diff = Difficulty::EASY;
    }
}


void MainWindow::on_radioButton_Medium_clicked(bool checked)
{
    if(checked)
    {
        diff = Difficulty::MEDIUM;
    }
}


void MainWindow::on_radioButton_Hard_clicked(bool checked)
{
    if(checked)
    {
        diff = Difficulty::HARD;
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    selectedLevel = index;
}

