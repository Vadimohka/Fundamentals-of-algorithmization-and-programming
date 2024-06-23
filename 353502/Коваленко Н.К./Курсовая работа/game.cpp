#include "game.h"
#include <QKeyEvent>

const size_t Game::COUNT_OF_KIND_OF_BLOCKS = 5;
const int Game::DEATH_Y_LEVEL = 520;
const QSize Game::NUMBER_SIZE = QSize(32,32);

Game::Game()
    : RESOLUTION(QSize(528, 450)), PATH_TO_BACKGROUND_PIXMAP(":/images/background.png"),
      PATH_TO_PADDLE_PIXMAP(":/images/paddle.png"), PATH_TO_BALL_PIXMAP(":/images/ball.png"),
      PATH_TO_BLOCKS_PIXMAP{":/images/block01.png", ":/images/block02.png", ":/images/block03.png",
                            ":/images/block04.png", ":/images/block05.png"},
      PATH_TO_GAME_OVER_BG_PIXMAP(":/images/bg_gameover.png"), PATH_TO_PAUSE_BG_PIXMAP(":/images/bg_pause.png"),
      PATH_TO_VICTORY_BG_PIXMAP(":/images/bg_victory.png"), PATH_TO_ALL_NUMBERS_PIXMAP(":/images/all_numbers.png"),
    PATH_TO_MENU_PIXMAP(":/images/Menu.png"),
      ITERATION_VALUE(1000.0f/60.0f), PADDLE_SPEED(6), m_isBallStucked(true), m_deltaX(1),
      m_deltaY(-1), m_state(State::Active), m_score(0)
{

}
