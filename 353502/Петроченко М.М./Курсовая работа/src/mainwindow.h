//
// Created by acryoz on 5/1/24.
//

#ifndef COURSEWORK_SRC_MAINWINDOW_H_
#define COURSEWORK_SRC_MAINWINDOW_H_

#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include "../include/Board.h"
#include "endmenu.h"
#include "movelineedit.h"
#include "startmenu.h"
#include "textboard.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

static const int TIMER_INTERVAL = 1001;
static const int RIGHT_MENU_MINIMUM_WIDTH = 100;
static const int MOVE_LOG_MAX_HEIGHT = 250;
static const int KOMADAI_HEIGHT = 25;
static const int KOMADAI_WIDTH = MAX_BOARD_WIDTH;
static const int MOVE_LINE_WIDTH = MAX_BOARD_WIDTH;

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    uint8_t starting_color;
    QVector<QRegExp> reg_exprs;
    TextBoard* board_rep;
    QLabel* vertical_coords;
    QLabel* horizontal_coords;
    QTime* black_time;
    QTime* white_time;
    QLabel* black_timer;
    QLabel* white_timer;
    QVBoxLayout* timer_vbox;
    MoveLineEdit* move_prompt;
    QPushButton* move_button;
    Board board;
    QGridLayout* board_grid;
    QGridLayout* main_grid;
    QTextEdit* move_log;
    QLineEdit* black_komadai;
    QLineEdit* white_komadai;
    bool isBot;
    Ui::MainWindow* ui;
    QTimer* timer;
    QTimer* mate_checker;
    Move MoveValidator(QString move_string);
    void endGame(uint8_t);
    QString moveToPGN(const Move& move);
    EndMenu* end_menu;
    StartMenu* start_menu;
    uint32_t move_count = 1;

   signals:
    void gameEnd(uint8_t);
   private slots:
    void makeMove();
    void tick();
    void start(bool, uint8_t);
    void end();
    void restart();
    void mate(uint8_t);
    void mateCheck();
};


#endif  //COURSEWORK_SRC_MAINWINDOW_H_
