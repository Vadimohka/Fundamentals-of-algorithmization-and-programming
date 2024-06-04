#include "keyboard.h"
#include "ui_virtualkeyboard.h"

Keyboard::Keyboard(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::VirtualKeyboard)

{
    _scene = new QGraphicsScene(0, 0, MAX_H_KEY_AMNT * (KEY_SIZE + KEY_SPOT), MAX_V_KEY_AMNT * (KEY_SIZE + KEY_SPOT));
    painter = new QPainter();
   // switch ()
   //  {
   //  case _angl:

   //      break;
   //  case _rus:

   //      break;
   //  case _ara:

   //      break;
   //  case _ger:

   //      break;
   //  case _heb:

   //      break;
   //  case _chi:

   //      break;
   //  case _fre:

   //      break;
   //  default:
   //      qDebug() << "Something went wrong!";
   //      break;
   //  }

}

void Keyboard::drawKeys()
{
    const double KEY_SPOT_HALF = KEY_SPOT * 0.5;
    const double KEY_SPOT_1_5 = KEY_SPOT * 1.5;
    const double KEY_SIZE_1_5 = KEY_SIZE * 1.5;
    const double KEY_SIZE_2 = KEY_SIZE * 2.0;
    const double KEY_SPOT_2_5 = KEY_SPOT * 2.5;
    const double KEY_SIZE_2_5 = KEY_SIZE * 2.5;
    const double KEY_SIZE_3 = KEY_SIZE * 3.0;
    const double KEY_SPOT_3_5 = KEY_SPOT * 3.5;
    const double KEY_SIZE_4 = KEY_SIZE * 4.0;
    const double KEY_SPOT_4_5 = KEY_SPOT * 4.5;
    const double KEY_SIZE_4_5 = KEY_SIZE * 4.5;
    const double KEY_SIZE_7 = KEY_SIZE * 7.0;
    const double KEY_SIZE_11_5 = KEY_SIZE * 11.5;
    const double KEY_SIZE_13_5 = KEY_SIZE * 13.5;

    const double ROW_1_Y = KEY_SPOT_HALF;
    const double ROW_2_Y = KEY_SPOT_1_5 + KEY_SIZE;
    const double ROW_3_Y = KEY_SPOT * 2.5 + KEY_SIZE_2;
    const double ROW_4_Y = KEY_SPOT * 3.5 + KEY_SIZE_3;
    const double ROW_5_Y = KEY_SPOT * 4.5 + KEY_SIZE_4;

    std::array<QGraphicsRectItem*, 11> keys =
        {
        _tab = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_2_Y, KEY_SIZE_1_5, KEY_SIZE),
        _caps = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_3_Y, KEY_SIZE_2, KEY_SIZE),
        _lShift = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_4_Y, KEY_SIZE_2_5, KEY_SIZE),
        _lCtrl = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_5_Y, KEY_SIZE_2_5, KEY_SIZE),
        _lAlt = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5, ROW_5_Y, KEY_SIZE_2, KEY_SIZE),
        _space = new QGraphicsRectItem(KEY_SPOT_2_5 + KEY_SIZE_4_5, ROW_5_Y, KEY_SIZE_7, KEY_SIZE),
        _rAlt = new QGraphicsRectItem(KEY_SPOT_3_5 + KEY_SIZE_11_5, ROW_5_Y, KEY_SIZE_2, KEY_SIZE),
        _rCtrl = new QGraphicsRectItem(KEY_SPOT_4_5 + KEY_SIZE_13_5, ROW_5_Y, KEY_SIZE_2_5, KEY_SIZE),
        _back = new QGraphicsRectItem(KEY_SPOT_HALF + TOP_ROW_KEYS * (KEY_SIZE + KEY_SPOT), ROW_1_Y, KEY_SIZE_1_5, KEY_SIZE),
        _enter = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2 + MID_ROW_KEYS * (KEY_SIZE + KEY_SPOT), ROW_3_Y, KEY_SIZE_1_5 + KEY_SPOT, KEY_SIZE),
        _rShift = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5 + BOT_ROW_KEYS * (KEY_SIZE + KEY_SPOT), ROW_4_Y, KEY_SIZE_2_5 - KEY_SPOT, KEY_SIZE)
    };

    for (auto key : keys)
    {
        _scene->addItem(key);
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i)
    {
        _highestRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_HALF + i * (KEY_SIZE + KEY_SPOT), ROW_1_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_highestRowBtn.at(i));
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i)
    {
        _topRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_1_5 + i * (KEY_SIZE + KEY_SPOT), ROW_2_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_topRowBtn.at(i));
    }

    for (int i = 0; i < MID_ROW_KEYS; ++i)
    {
        _midRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2 + i * (KEY_SIZE + KEY_SPOT), ROW_3_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_midRowBtn.at(i));
    }

    for (int i = 0; i < BOT_ROW_KEYS; ++i)
    {
        _botRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5 + i * (KEY_SIZE + KEY_SPOT), ROW_4_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_botRowBtn.at(i));
    }

    _lastItem = _tab;
}

void Keyboard::addButtons()
{


}
