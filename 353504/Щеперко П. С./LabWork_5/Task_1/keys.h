#ifndef KEYS_H
#define KEYS_H

#include <QGraphicsTextItem>
#include <QWidget>

const int TOP_ROW_KEYS = 13;
const int MID_ROW_KEYS = 11;
const int BOT_ROW_KEYS = 10;

const int KEY_SIZE = 60;
const int KEY_SPOT = 10;
const int MAX_H_KEY_AMNT = 15;
const int MAX_V_KEY_AMNT = 5;

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

enum Language { Bel, Ger, Fra, Ara, Chi, };

namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public QWidget
{
    Q_OBJECT

private:
    QGraphicsScene* _scene;
    Ui::VirtualKeyboard *ui;
    std::array<QString, 7> _keyboardLayout;
    QGraphicsRectItem *_tab, *_caps, *_lShift, *_rShift, *_lCtrl, *_rCtrl, *_lAlt, *_rAlt, *_enter,
        *_back, *_space;

    std::array<QGraphicsRectItem *, TOP_ROW_KEYS> _highestRowBtn;
    std::array<QGraphicsRectItem *, TOP_ROW_KEYS> _topRowBtn;
    std::array<QGraphicsRectItem *, MID_ROW_KEYS> _midRowBtn;
    std::array<QGraphicsRectItem*, BOT_ROW_KEYS> _botRowBtn;

    QGraphicsRectItem* _lastItem;
    Language _selectedLang = Bel;
    void addTextToButton(QGraphicsRectItem* button, const QString& text);
    QGraphicsRectItem* atIndex(int index);
    void initKeys();
    void initLetters();
    void updateLayout();

public:
    explicit VirtualKeyboard(QWidget *parent = nullptr);
    ~VirtualKeyboard() override;
    Language language() const;
    void setLanguage(Language newSelectedLang);
    void makeGreen(int index);
    void makeRed(int index);
    void makeGrey();
    const std::array<QString, 7> getLayouts() const ;
};

#endif // KEYS_H
