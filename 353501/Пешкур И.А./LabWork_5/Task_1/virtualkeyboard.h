#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QWidget>
#include <array>
#include <VirtKeyboardConsts.h>

namespace Ui {
class VirtualKeyboard;
}

const int TOP_ROW_KEYS = 13;
const int MID_ROW_KEYS = 11;
const int BOT_ROW_KEYS = 10;

enum Language {
    Ger = 0,
    Fra,
    Ara,
    Chi,
    Bel
};

class VirtualKeyboard : public QWidget
{
    Q_OBJECT

private:
    QGraphicsScene* _scene;
    Ui::VirtualKeyboard *ui;

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

#endif // VIRTUALKEYBOARD_H
