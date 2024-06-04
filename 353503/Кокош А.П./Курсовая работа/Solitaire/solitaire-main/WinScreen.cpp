
#include "WinScreen.h"
#include <QLabel>
#include <QWidget>
#include "Main.h"

#include "ui_WinScreen.h"

WinScreen::WinScreen(int score, int moves, QString time, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WinScreen)
{
    ui->setupUi(this);

    // Place the window at the center of the screen
    QWidget *desktop = new QWidget();
    int screenW = desktop->width();
    int screenH = desktop->height();
    int windowW = this->size().width();
    int windowH = this->size().height();
    this->move((screenW / 2) - (windowW / 2), (screenH / 2) - (windowH / 2));

    // Pixmap of the win screen)
    QPixmap winPixmap(":/assets/winscreen.png");

    // Add the win image
    QLabel* winImage = new QLabel(this);
    winImage->setPixmap(winPixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    winImage->resize(500, 500);
    ui->gridLayout_2->addWidget(winImage, 0, 0, 1, 3);

    // Create the score label
    QLabel* scoreLabel = new QLabel("Score: " + QString::number(score), this);

    // Set up a font to use
    QFont font = scoreLabel->font();
    font.setBold(true);
    font.setPointSize(12);

    // Apply the score label
    scoreLabel->setFont(font);
    scoreLabel->setStyleSheet("color: white;");
    ui->gridLayout_2->addWidget(scoreLabel, 1, 0, Qt::AlignCenter);

    // Create the moves label
    QLabel* movesLabel = new QLabel("Moves: " + QString::number(moves), this);
    movesLabel->setFont(font);
    movesLabel->setStyleSheet("color: white;");
    ui->gridLayout_2->addWidget(movesLabel, 1, 1, Qt::AlignCenter);

    // Create the time label
    QLabel* timeLabel = new QLabel("Time: " + time, this);
    timeLabel->setFont(font);
    timeLabel->setStyleSheet("color: white;");
    ui->gridLayout_2->addWidget(timeLabel, 1, 2, Qt::AlignCenter);

    // Assign the background to the window's palette
    QPixmap bg(":/assets/table_background.png");
    bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bg);
    this->setPalette(palette);
}

void WinScreen::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    // Restart the game
    Main::get()->getGameInstance()->restartGame();
    Main::get()->getGameWindow()->resetGameWindow();
}

void WinScreen::closeEvent(QCloseEvent *ev)
{
    Q_UNUSED(ev);

    // Restart the game
    Main::get()->getGameInstance()->restartGame();
    Main::get()->getGameWindow()->resetGameWindow();
}

WinScreen::~WinScreen()
{
    // Delete the UI
    delete ui;
}
