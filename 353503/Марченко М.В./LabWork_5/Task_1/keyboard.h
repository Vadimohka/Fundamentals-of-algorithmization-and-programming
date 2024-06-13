#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QWidget>
#include <array>

namespace Ui {
class Keyboard;
}

const int TOP_ROW_KEYS = 13;
const int MID_ROW_KEYS = 11;
const int BOT_ROW_KEYS = 10;

enum Language {
    Ger = 0,
    Fra,
    Ara,
    Chi,
    Bel,
    Heb
};

class Keyboard : public QWidget
{
    Q_OBJECT

private:
    QGraphicsScene* _scene;
    Ui::Keyboard *ui;

    const int size = 60;
    const int spot = 10;
    const int MAX_H_KEY_AMNT = 15;
    const int MAX_V_KEY_AMNT = 5;

    std::array<QString, 7> _keyboardLayout;

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

    std::array<QGraphicsRectItem*, TOP_ROW_KEYS> _highestRowBtn;
    std::array<QGraphicsRectItem*, TOP_ROW_KEYS> _topRowBtn;
    std::array<QGraphicsRectItem*, MID_ROW_KEYS> _midRowBtn;
    std::array<QGraphicsRectItem*, BOT_ROW_KEYS> _botRowBtn;

    QGraphicsRectItem* _lastItem;

    Language _selectedLang = Ger;

    void addTextToButton(QGraphicsRectItem* button, const QString& text);
    QGraphicsRectItem* atIndex(int index);

    void initKeys();
    void initLetters();
    void updateLayout();

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard() override;

    Language language() const;
    void setLanguage(Language newSelectedLang);
    void makeGrey();

    const std::array<QString, 7> getLayouts() const ;

};

#endif // KEYBOARD_H
