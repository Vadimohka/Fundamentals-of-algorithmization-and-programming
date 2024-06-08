#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>

namespace Ui {
class VirtualKeyboard;
}
enum language
{
    _angl = 1,
    _rus,
    _ara,
    _ger,
    _heb,
    _chi,
    _fre
};

class Keyboard :public QWidget
{
    Q_OBJECT
public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard() override;
    void setLanguage(language newLang);
    void drawKeys();
private:

    void addButtons();
    QGraphicsScene* _scene;
    Ui::VirtualKeyboard *ui;
    QPainter* painter;

    const static int TOP_ROW_KEYS = 13; // number of buttons
    const static int MID_ROW_KEYS = 11;
    const static int BOT_ROW_KEYS = 10;

    const int KEY_SIZE = 60; // size of buttons
    const int KEY_SPOT = 10;
    const int MAX_H_KEY_AMNT = 15;
    const int MAX_V_KEY_AMNT = 5;

    std::array<QGraphicsRectItem*, TOP_ROW_KEYS> _highestRowBtn;
    std::array<QGraphicsRectItem*, TOP_ROW_KEYS> _topRowBtn;
    std::array<QGraphicsRectItem*, MID_ROW_KEYS> _midRowBtn;
    std::array<QGraphicsRectItem*, BOT_ROW_KEYS> _botRowBtn;

    QGraphicsRectItem
        *_tab,
        *_caps,
        *_lShift,
        *_rShift,
        *_lCtrl,
        *_rCtrl,
        *_lAlt,
        *_rAlt,
        *_enter,
        *_back,
        *_space;

    QGraphicsRectItem* _lastItem;

    language _selectedLang = _angl;
};

#endif // KEYBOARD_H
