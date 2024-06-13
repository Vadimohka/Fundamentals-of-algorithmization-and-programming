#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    _scene = new QGraphicsScene(0, 0, MAX_H_KEY_AMNT * (size + spot), MAX_V_KEY_AMNT * (size + spot));

    ui->setupUi(this);
    ui->graphicsView->setScene(_scene);

    _keyboardLayout.at(0) = "^1234567890ß´qwertyuiopü+#asdfghjklöäzxcvbnm,.-";
    _keyboardLayout.at(1) = "²&é\"'(-è_çà)=azertyuiop^$*qsdfghjklmùwxcvbn,;:!";
    _keyboardLayout.at(2) = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوزظ";
    _keyboardLayout.at(3) = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    _keyboardLayout.at(4) = "ё1234567890-=йцукенгшўзх'\\фывапролджэячсмітьбю.";
    _keyboardLayout.at(5) = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ.";
    _keyboardLayout.at(6) = "ё1234567890-=йцукенгшщзхъ\\фывапролджэячсмитьбю.";

    initKeys();
    initLetters();
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::initKeys()
{

    const double spot_half = spot * 0.5;
    const double spot_1_5 = spot * 1.5;
    const double size_1_5 = size * 1.5;
    const double size_2 = size * 2.0;
    const double spot_2_5 = spot * 2.5;
    const double size_2_5 = size * 2.5;
    const double size_3 = size * 3.0;
    const double spot_3_5 = spot * 3.5;
    const double size_4 = size * 4.0;
    const double spot_4_5 = spot * 4.5;
    const double size_4_5 = size * 4.5;
    const double size_7 = size * 7.0;
    const double size_11_5 = size * 11.5;
    const double size_13_5 = size * 13.5;

    const double row_1_Y = spot_half;
    const double row_2_Y = spot_1_5 + size;
    const double row_3_Y = spot * 2.5 + size_2;
    const double row_4_Y = spot * 3.5 + size_3;
    const double row_5_Y = spot * 4.5 + size_4;

    std::array<QGraphicsRectItem*, 11> keys = {
        _tab = new QGraphicsRectItem(spot_half, row_2_Y, size_1_5, size),
        _caps = new QGraphicsRectItem(spot_half, row_3_Y, size_2, size),
        _lShift = new QGraphicsRectItem(spot_half, row_4_Y, size_2_5, size),
        _lCtrl = new QGraphicsRectItem(spot_half, row_5_Y, size_2_5, size),
        _lAlt = new QGraphicsRectItem(spot_1_5 + size_2_5, row_5_Y, size_2, size),
        _space = new QGraphicsRectItem(spot_2_5 + size_4_5, row_5_Y, size_7, size),
        _rAlt = new QGraphicsRectItem(spot_3_5 + size_11_5, row_5_Y, size_2, size),
        _rCtrl = new QGraphicsRectItem(spot_4_5 + size_13_5, row_5_Y, size_2_5, size),
        _back = new QGraphicsRectItem(spot_half + TOP_ROW_KEYS * (size + spot), row_1_Y, size_1_5, size),
        _enter = new QGraphicsRectItem(spot_1_5 + size_2 + MID_ROW_KEYS * (size + spot), row_3_Y, size_1_5 + spot, size),
        _rShift = new QGraphicsRectItem(spot_1_5 + size_2_5 + BOT_ROW_KEYS * (size + spot), row_4_Y, size_2_5 - spot, size)
    };

    for (auto key : keys) {
        _scene->addItem(key);
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i) {
        _highestRowBtn.at(i) = new QGraphicsRectItem(spot_half + i * (size + spot), row_1_Y, size, size);
        _scene->addItem(_highestRowBtn.at(i));
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i) {
        _topRowBtn.at(i) = new QGraphicsRectItem(spot_1_5 + size_1_5 + i * (size + spot), row_2_Y, size, size);
        _scene->addItem(_topRowBtn.at(i));
    }

    for (int i = 0; i < MID_ROW_KEYS; ++i) {
        _midRowBtn.at(i) = new QGraphicsRectItem(spot_1_5 + size_2 + i * (size + spot), row_3_Y, size, size);
        _scene->addItem(_midRowBtn.at(i));
    }

    for (int i = 0; i < BOT_ROW_KEYS; ++i) {
        _botRowBtn.at(i) = new QGraphicsRectItem(spot_1_5 + size_2_5 + i * (size + spot), row_4_Y, size, size);
        _scene->addItem(_botRowBtn.at(i));
    }

    _lastItem = _tab;
}

Language Keyboard::language() const
{
    return _selectedLang;
}

void Keyboard::setLanguage(Language newSelectedLang)
{
    _selectedLang = newSelectedLang;
    updateLayout();
}

void Keyboard::makeGrey()
{
    _lastItem->setBrush(QBrush(Qt::NoBrush));
}

const std::array<QString, 7> Keyboard::getLayouts() const
{
    return _keyboardLayout;
}

void Keyboard::addTextToButton(QGraphicsRectItem* button, const QString& text)
{
    QGraphicsTextItem* textItem = _scene->addText(text, QFont("Arial", spot, 10));
    textItem->setPos(button->boundingRect().x() + spot,
                     button->boundingRect().y() + size / 3.0f);
}

QGraphicsRectItem* Keyboard::atIndex(int index)
{
    if (index == -1) {
        return nullptr;
    }

    if (index >= TOP_ROW_KEYS * 2 + MID_ROW_KEYS + BOT_ROW_KEYS) {
        index -= TOP_ROW_KEYS * 2 + MID_ROW_KEYS + BOT_ROW_KEYS;
        switch (index) {
            case 0:
                return _space;
            case 1:
                return _enter;
        }
        return nullptr;
    }
    else if (index >= TOP_ROW_KEYS * 2 + MID_ROW_KEYS) {
        return _botRowBtn.at(index - TOP_ROW_KEYS * 2 - MID_ROW_KEYS);
    } else if (index >= TOP_ROW_KEYS * 2) {
        return _midRowBtn.at(index - TOP_ROW_KEYS * 2);
    } else if (index >= TOP_ROW_KEYS) {
        return _topRowBtn.at(index - TOP_ROW_KEYS);
    }
    return _highestRowBtn.at(index);
}

void Keyboard::initLetters()
{
    addTextToButton(_tab, "Tab");
    addTextToButton(_caps, "Caps");
    addTextToButton(_lShift, "Shift");
    addTextToButton(_rShift, "Shift");
    addTextToButton(_lCtrl, "Ctrl");
    addTextToButton(_rCtrl, "Ctrl");
    addTextToButton(_lAlt, "Alt");
    addTextToButton(_rAlt, "Alt");
    addTextToButton(_enter, "Enter");
    addTextToButton(_back, "Backspace");
    addTextToButton(_space, "Space");

    for (int i = 0; i < TOP_ROW_KEYS; ++i) {
        addTextToButton(_highestRowBtn.at(i), _keyboardLayout.at(_selectedLang).at(i));
        addTextToButton(_topRowBtn.at(i), _keyboardLayout.at(_selectedLang).at(TOP_ROW_KEYS + i));
        if (i >= MID_ROW_KEYS) {
            continue;
        }
        addTextToButton(_midRowBtn.at(i), _keyboardLayout.at(_selectedLang).at(TOP_ROW_KEYS * 2 + i));
        if (i >= BOT_ROW_KEYS) {
            continue;
        }
        addTextToButton(_botRowBtn.at(i), _keyboardLayout.at(_selectedLang).at(TOP_ROW_KEYS * 2 + MID_ROW_KEYS + i));
    }
}


void Keyboard::updateLayout()
{
    _scene->clear();
    initKeys();
    initLetters();
}
