#include "Keyboard.h"
#include <QPainter>
#include <qgraphicsitem.h>
#include <qlogging.h>
#include <qnamespace.h>

class Layouts {
public:
  Layouts(QString source) {
    QStringList langs = source.split("\n");
    chToKey.resize(langs.count() / 2);
    for (int layout = 0; layout < langs.count(); layout += 2) {
      if (langs[layout].isEmpty())
        break;
      QStringList lowerKeys = langs[layout].split(" ");
      QStringList upperKeys = langs[layout + 1].split(" ");
      for (int i = 0; i < MAIN_KEYS_COUNT; i++) {
        chToKey[layout / 2][lowerKeys[i]] = {false, i};
        chToKey[layout / 2][upperKeys[i]] = {true, i};
      }
    }
  };

  QPair<bool, int> findCombo(QString combo, int preferredLayout) const {
    for (int i = -1; i < chToKey.count(); i++) {
      int targLayout = i == -1 ? preferredLayout : i;
      if (targLayout < 0 || targLayout >= chToKey.count())
        continue;

      if (chToKey[targLayout].contains(combo)) {
        return chToKey[targLayout][combo];
      }
    }

    return {false, -1};
  }

  QList<QMap<QString, QPair<bool, int>>> chToKey;
};

const char *LAYOUT_SRC =
    R"TOKEN(q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /
Q W E R T Y U I O P { } A S D F G H J K L : " Z X C V B N M < > ?
q w e r t z u i o p ü + a s d f g h j k l ö ä y x c v b n m , . /
Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _
a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !
A Z E R T Y U I O P ¨ £ Q S D F G H J K L M % W X C V B N ? . / §
ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر لا ى ة و ز ظ
َ ً ُ ٌ لإ إ ` ÷ × ؛ < > ِ ٍ ] [ لأ أ ـ ، / : " ~ ْ } { لآ آ ' , . ؟
й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э я ч с м і т ь б ю .
Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,
/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .
Q W E R T Y U I O P { } A S D F G H J K L : " Z X  V B N M < > ?
)TOKEN";

const Layouts LAYOUTS(LAYOUT_SRC);

KeyboardKey::KeyboardKey(int width, QGraphicsItem *parent)
    : QGraphicsObject(parent), width(width) {
  color = Qt::white;
}

void KeyboardKey::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {

  painter->setPen(Qt::NoPen);
  painter->setBrush(color);
  painter->drawRoundedRect(boundingRect(), 12., 12.);
};

void KeyboardKey::setColor(QBrush _color) {
  color = _color;
  update();
}

QRectF KeyboardKey::boundingRect() const {
  return QRectF(-width / 2., -32, width, 64);
};

const Qt::Key KEY_ORDER[] = {
    Qt::Key_Q,    Qt::Key_W,         Qt::Key_E,           Qt::Key_R,
    Qt::Key_T,    Qt::Key_Y,         Qt::Key_U,           Qt::Key_I,
    Qt::Key_O,    Qt::Key_P,         Qt::Key_BracketLeft, Qt::Key_BracketRight,
    Qt::Key_A,    Qt::Key_S,         Qt::Key_D,           Qt::Key_F,
    Qt::Key_G,    Qt::Key_H,         Qt::Key_J,           Qt::Key_K,
    Qt::Key_L,    Qt::Key_Semicolon, Qt::Key_Apostrophe,  Qt::Key_Z,
    Qt::Key_X,    Qt::Key_C,         Qt::Key_V,           Qt::Key_B,
    Qt::Key_N,    Qt::Key_M,         Qt::Key_Comma,       Qt::Key_Period,
    Qt::Key_Slash};

Keyboard::Keyboard() {
  int curk = 0;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 12 - row; col++) {
      KeyboardKey *key = new KeyboardKey();
      key->setPos(col * 70 + row * 35, row * 70);
      addToGroup(key);

      mainKeys[curk] = key;
      curk++;
    }
  }

  {
    KeyboardKey *key = new KeyboardKey(490);
    key->setPos(385, 210);
    addToGroup(key);

    space = key;
  }

  {
    KeyboardKey *key = new KeyboardKey(99);
    key->setPos(-18, 140);
    addToGroup(key);

    shifts[0] = key;
  }

  {
    KeyboardKey *key = new KeyboardKey(99);
    key->setPos(788, 140);
    addToGroup(key);

    shifts[1] = key;
  }

  curCombo = nullptr;
}

void Keyboard::setCombo(QString keyName, int preferredLang) {
  if (curCombo) {
    curCombo->setColor(Qt::white);
    curCombo = nullptr;
  }

  bool shouldShift = false;
  if (keyName == " ") {
    curCombo = space;
  } else {
    QPair<bool, int> key = LAYOUTS.findCombo(keyName, preferredLang);
    if (key.second != -1) {
      shouldShift = key.first;
      curCombo = mainKeys[key.second];
    }
  }

  if (curCombo)
    curCombo->setColor(Qt::magenta);

  shifts[0]->setColor(shouldShift ? Qt::magenta : Qt::white);
  shifts[1]->setColor(shouldShift ? Qt::magenta : Qt::white);
}

void Keyboard::setAllColor(QBrush color) {
  for (int i = 0; i < MAIN_KEYS_COUNT; i++) {
    mainKeys[i]->setColor(color);
  }

  shifts[0]->setColor(color);
  shifts[1]->setColor(color);
  space->setColor(color);
}
