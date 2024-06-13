#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    player1Name_(DEFAULT_PLAYER_1_NAME),
    player2Name_(DEFAULT_PLAYER_2_NAME),
    player1Color_(DEFAULT_PLAYER_1_COLOR),
    player2Color_(DEFAULT_PLAYER_2_COLOR),
    gameStarted_(false),
    gameFinished_(true)
{
    ui_->setupUi(this);
    ui_->message->setText(START_GAME_MSG);
    ui_->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui_->colorMessage->setText("");

    transparentPixmap_= QPixmap(PLAYER_COLOR_LABEL_WIDTH, PLAYER_COLOR_LABEL_WIDTH);
    transparentPixmap_.fill(QColor("transparent"));

    this->setMinimumSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
    initGameField();

    QObject::connect(ui_->graphicsView, &SizeFitGraphicsView::graphicsViewClicked,
                     this, &MainWindow::gameFieldClickedPosition);
}

MainWindow::~MainWindow(){
    for(unsigned int i = 0; i<timers_.size(); ++i){
        delete timers_[i];
    }

    timers_.clear();
    delete scene_;
    delete ui_;
}

void MainWindow::initGameField(){
    // create new scene object
    scene_ = new QGraphicsScene();

    // init game squares
    for(unsigned int i = 0; i<GAME_BOARD_WIDTH; ++i ){
        for(unsigned int j = 0; j<GAME_BOARD_HEIGHT; ++j){
            gameField[i][j] = Empty;
            GameSquare *tmp = new GameSquare(GAME_SQUARE_SIDE_LENGTH);
            tmp->setPos(i*GAME_SQUARE_SIDE_LENGTH, j*GAME_SQUARE_SIDE_LENGTH);
            scene_->addItem(tmp);
        }
    }

    ui_->graphicsView->setScene(scene_);
    ui_->graphicsView->setBackgroundBrush(BACKGROUND_BRUSH);

    ui_->colorMessage->setPixmap(transparentPixmap_);
}


void MainWindow::resetGameField(){
    // clear timers and delete previous scene
    for(unsigned int i = 0; i<timers_.size(); ++i){
        delete timers_[i];
    }

    timers_.clear();
    delete scene_;
    initGameField();
}


void MainWindow::startGame(){
    resetGameField();

    int tmp = rand()%2;

    if(tmp == 0){
        player1Turn_ = true;
    }
    else {
        player1Turn_ = false;
    }

    player1Pixmap_ = QPixmap(PLAYER_COLOR_LABEL_WIDTH, PLAYER_COLOR_LABEL_WIDTH);
    player1Pixmap_.fill(player1Color_);
    player2Pixmap_ = QPixmap(PLAYER_COLOR_LABEL_WIDTH, PLAYER_COLOR_LABEL_WIDTH);
    player2Pixmap_.fill(player2Color_);
    setPlayerLabels();

    gameStarted_ = true;
    gameFinished_ = false;
}

void MainWindow::makeMove(int x)
{
    int column = x/GAME_SQUARE_SIDE_LENGTH;

    if(gameField[column][GAME_BOARD_HEIGHT-1] == Empty){
        unsigned int row = 0;
        for(unsigned int y = 0; y<GAME_BOARD_HEIGHT; ++y){
            if(gameField[column][y] == Empty){
                row = y;
                break;
            }
        }

        QPointF begin(column*GAME_SQUARE_SIDE_LENGTH + GAME_SQUARE_ELLIPSE_PERCENT/2*GAME_SQUARE_SIDE_LENGTH,
                      GAME_SQUARE_ELLIPSE_PERCENT/2*GAME_SQUARE_SIDE_LENGTH);
        QPointF end(column*GAME_SQUARE_SIDE_LENGTH + GAME_SQUARE_ELLIPSE_PERCENT/2*GAME_SQUARE_SIDE_LENGTH,
                               (GAME_BOARD_HEIGHT-1-row)*GAME_SQUARE_SIDE_LENGTH);
        QSizeF size((1-GAME_SQUARE_ELLIPSE_PERCENT)*GAME_SQUARE_SIDE_LENGTH,
                            (1-GAME_SQUARE_ELLIPSE_PERCENT)*GAME_SQUARE_SIDE_LENGTH);
        QRectF recEllipse(begin, size);

        Disc *disc = new Disc();

        disc->setEnd(end);
        disc->setRect(recEllipse);
        disc->setZValue(-1);

        if(player1Turn_){
            disc->setBrush(player1Color_);
            gameField[column][row] = Player1;
        }
        else {
            disc->setBrush(player2Color_);
            gameField[column][row] = Player2;
        }

        disc->setZValue(-1);
        scene_->addItem(disc);

        QTimer *timer = new QTimer();
        QObject::connect(timer, &QTimer::timeout, disc, &Disc::moveDisc);
        QObject::connect(disc, &Disc::animationHaveFinish, this, &MainWindow::animationHaveFinish);
        timer->start(20);

        timers_.emplace_back(timer);

        gameFinished_ = isGameFinished();

        if(!isGameFinished()){
            changePlayerTurn();
        }
    }
}

void MainWindow::changePlayerTurn()
{
    if(player1Turn_){
        player1Turn_ = false;
    }
    else {
        player1Turn_ = true;
    }

    setPlayerLabels();
}

void MainWindow::setPlayerLabels()
{
    if(player1Turn_){
        ui_->message->setText(player1Name_ +" turn");
        ui_->colorMessage->setPixmap(player1Pixmap_);
    }
    else{
        ui_->message->setText(player2Name_ +" turn");
        ui_->colorMessage->setPixmap(player2Pixmap_);
    }
}


bool MainWindow::isGameFinished()
{
    int winner = checkWhoWins();

    if(winner != Nobody){
        return true;
    }

    for(unsigned int i = 0; i<GAME_BOARD_WIDTH; ++i){
        if(gameField[i][GAME_BOARD_HEIGHT-1]==Empty){
            return false;
        }
    }

    return true;
}

int MainWindow::checkWhoWins()
{
    // check vertically
    for(unsigned int  j = 0; j<GAME_BOARD_WIDTH; ++j){
        for(unsigned int  i = 0; i<GAME_BOARD_HEIGHT-3; ++i){
            if( gameField[j][i]!=Empty &&
                gameField[j][i] == gameField[j][i+1] &&
                gameField[j][i+1] == gameField[j][i+2] &&
                gameField[j][i+2] == gameField[j][i+3]){
                if(gameField[j][i] == Player1)
                    return Player1Wins;
                else
                    return Player2Wins;
            }
        }
    }

    // check horizonally
    for(unsigned int  j = 0; j<GAME_BOARD_WIDTH-3; ++j){
        for(unsigned int  i = 0; i<GAME_BOARD_HEIGHT; ++i){
            if( gameField[j][i]!=Empty &&
                gameField[j][i] == gameField[j+1][i] &&
                gameField[j+1][i] == gameField[j+2][i] &&
                gameField[j+2][i] == gameField[j+3][i]){
                if(gameField[j][i] == Player1)
                    return Player1Wins;
                else
                    return Player2Wins;
            }
        }
    }

    // check diagonaly left bottom to right top
    for(unsigned int j = 0; j<GAME_BOARD_WIDTH-3; ++j){
        for(unsigned int  i = 0; i<GAME_BOARD_HEIGHT-3; ++i){
            if( gameField[j][i]!=Empty &&
                gameField[j][i] == gameField[j+1][i+1] &&
                gameField[j+1][i+1] == gameField[j+2][i+2] &&
                gameField[j+2][i+2] == gameField[j+3][i+3]){
                if(gameField[j][i] == Player1)
                    return Player1Wins;
                else
                    return Player2Wins;
            }
        }
    }

    //check diagonaly left top to right button
    for(unsigned int  j = GAME_BOARD_WIDTH-1; j>=3; --j){
        for(unsigned int  i = 0; i<GAME_BOARD_HEIGHT-3; ++i){
            if( gameField[j][i]!=Empty &&
                gameField[j][i] == gameField[j-1][i+1] &&
                gameField[j-1][i+1] == gameField[j-2][i+2] &&
                gameField[j-2][i+2] == gameField[j-3][i+3]){
                if(gameField[j][i] == Player1)
                    return Player1Wins;
                else
                    return Player2Wins;
            }
        }
    }

    return Nobody;
}

// slots

void MainWindow::on_actionNewGame_triggered()
{
    PlayerMenu playerMenu(player1Name_, player2Name_, player1Color_, player2Color_, this);
    playerMenu.setModal(true);
    playerMenu.exec();

    if(playerMenu.result() == QDialog::Accepted){
        player1Name_ = playerMenu.getPlayer1Name();
        player1Color_ = playerMenu.getPlayer1Color();
        player2Name_ = playerMenu.getPlayer2Name();
        player2Color_ = playerMenu.getPlayer2Color();

        startGame();
    }
}

void MainWindow::on_actionGameHelp_triggered(){
    QMessageBox::information(this, "Game Help", GAME_HELP_MSG);
}

void MainWindow::on_actionAbout_triggered(){
    QMessageBox::information(this, "About", ABOUT_MSG);
}

void MainWindow::on_actionContact_triggered(){
    QMessageBox::information(this, "Contact", CONTACT_MSG);
}

void MainWindow::gameFieldClickedPosition(int x){
    if(!gameStarted_ && gameFinished_){
        on_actionNewGame_triggered();
    }
    else if(!gameFinished_ && x<=GAME_SQUARE_SIDE_LENGTH*GAME_BOARD_WIDTH){
        makeMove(x);
    }
}

void MainWindow::animationHaveFinish(){
    if(gameFinished_){
        gameStarted_ = false;

        QFont font;
        font.setPixelSize(50);
        font.setBold(false);
        font.setFamily("Calbri");

        int winner = checkWhoWins();

        if(winner == Player1Wins){
            QPainterPath *painterPath = new QPainterPath();
            painterPath->addText(GAME_SQUARE_SIDE_LENGTH, GAME_SQUARE_SIDE_LENGTH*2, font, player1Name_ + " wins!");
            scene_->addPath(*painterPath, QPen(QBrush(Qt::black), 2), QBrush(player1Color_));
            delete painterPath;
        }
        else if(winner == Player2Wins){
            QPainterPath *painterPath = new QPainterPath();
            painterPath->addText(GAME_SQUARE_SIDE_LENGTH, GAME_SQUARE_SIDE_LENGTH*2, font, player2Name_ + " wins!");
            scene_->addPath(*painterPath, QPen(QBrush(Qt::black), 2), QBrush(player2Color_));
            delete painterPath;

        } else{
            QPainterPath *painterPath = new QPainterPath();
            painterPath->addText(GAME_SQUARE_SIDE_LENGTH, GAME_SQUARE_SIDE_LENGTH*2, font, "Draw...");
            scene_->addPath(*painterPath, QPen(QBrush(Qt::black), 2), QBrush(Qt::black));
            delete painterPath;
        }

        ui_->message->setText(START_GAME_MSG);
        ui_->colorMessage->setPixmap(transparentPixmap_);
    }
}

