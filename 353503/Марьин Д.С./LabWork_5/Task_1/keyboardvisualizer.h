#ifndef KEYBOARDVISUALIZER_H
#define KEYBOARDVISUALIZER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPainter>

namespace Ui {
class KeyboardVisualizer;
}

enum language
{
    _angl = 1,
    _bel,
    _rus,
    _ara,
    _ger,
    _heb,
    _chi,
    _fre
};

class KeyboardVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyboardVisualizer(QWidget *parent = nullptr);
    ~KeyboardVisualizer();
    void setLanguage(language newLang);
    void drawKeys();
    void addTextToButton(QGraphicsRectItem* button, const QString& text);
    void addText();
    QGraphicsRectItem *atIndex(int index);
    void makeButtonGreen(int index);
    void makeButtonRed(int index);
    void makeButtonGray(int index);
    void makeButtonBlue(int index);
    int getLanguage();
private:
    Ui::KeyboardVisualizer *ui;
    QGraphicsScene* _scene;
    QPainter* painter;
    language _currentLang = _angl;
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
        *_lOption,
        *_rOption,
        *_lCommand,
        *_rCommand,
        *_enter,
        *_back,
        *_space;

    QGraphicsRectItem* _lastItem = nullptr;
    QString languageLayout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

};

#endif // KEYBOARDVISUALIZER_H
