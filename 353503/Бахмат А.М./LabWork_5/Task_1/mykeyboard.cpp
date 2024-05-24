#include "mykeyboard.h"
#include "ui_mykeyboard.h"

MyKeyboard::MyKeyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyKeyboard)
{
    _scene = new QGraphicsScene(0, 0, MAX_H_KEY_AMNT * (KEY_SIZE + KEY_SPOT), MAX_V_KEY_AMNT * (KEY_SIZE + KEY_SPOT));

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

MyKeyboard::~MyKeyboard()
{
    delete ui;
}

Language MyKeyboard::language() const
{
    return _selectedLang;
}

void MyKeyboard::setLanguage(Language newSelectedLang)
{
    _selectedLang = newSelectedLang;
    updateLayout();
}

void MyKeyboard::initKeys()
{

    std::array<QGraphicsRectItem*, 11> keys = {
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

    for (auto key : keys) {
        _scene->addItem(key);
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i) {
        _highestRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_HALF + i * (KEY_SIZE + KEY_SPOT), ROW_1_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_highestRowBtn.at(i));
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i) {
        _topRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_1_5 + i * (KEY_SIZE + KEY_SPOT), ROW_2_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_topRowBtn.at(i));
    }

    for (int i = 0; i < MID_ROW_KEYS; ++i) {
        _midRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2 + i * (KEY_SIZE + KEY_SPOT), ROW_3_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_midRowBtn.at(i));
    }

    for (int i = 0; i < BOT_ROW_KEYS; ++i) {
        _botRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5 + i * (KEY_SIZE + KEY_SPOT), ROW_4_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_botRowBtn.at(i));
    }

    _lastItem = _tab;

}

void MyKeyboard::initLetters()
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

void MyKeyboard::makeGreen(int index)
{
    auto key = atIndex(index);
    if (key != nullptr) {
        _lastItem->setBrush(QBrush(Qt::NoBrush));
        key->setBrush(QBrush(Qt::green));
        _lastItem = key;
    }
}

void MyKeyboard::makeRed(int index)
{
    auto key = atIndex(index);
    if (key != nullptr) {
        _lastItem->setBrush(QBrush(Qt::NoBrush));
        key->setBrush(QBrush(Qt::red));
        _lastItem = key;
    }
}

void MyKeyboard::makeGrey()
{
    _lastItem->setBrush(QBrush(Qt::NoBrush));
}

const std::array<QString, 7> MyKeyboard::getLayouts() const
{
    return _keyboardLayout;
}

void MyKeyboard::addTextToButton(QGraphicsRectItem* button, const QString& text)
{
    QGraphicsTextItem* textItem = _scene->addText(text, QFont("Arial", KEY_SPOT, 10));
    textItem->setPos(button->boundingRect().x() + KEY_SPOT,
                     button->boundingRect().y() + KEY_SIZE / 3.0f);
}

QGraphicsRectItem* MyKeyboard::atIndex(int index)
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

void MyKeyboard::updateLayout()
{
    _scene->clear();
    initKeys();
    initLetters();
}
