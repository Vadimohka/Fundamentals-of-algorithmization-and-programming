#include "CatchyLineEdit.h"
#include <QKeyEvent>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qtextedit.h>
#include <qtimer.h>
#include <qwidget.h>

CatchyLineEdit::CatchyLineEdit(QWidget *parent) : QLineEdit(parent) {}

void CatchyLineEdit::keyPressEvent(QKeyEvent *e) {
  QFlags<Qt::KeyboardModifier> m = e->modifiers();

  if (m.testFlag(Qt::AltModifier) || m.testFlag(Qt::ControlModifier) ||
      m.testFlag(Qt::MetaModifier))
    return;

  if(e->key() == Qt::Key_Backspace) {
    emit doBackspace();
    return;
  }

  emit keyCaught((Qt::Key)e->key(), true);
  QLineEdit::keyPressEvent(e);
}

void CatchyLineEdit::keyReleaseEvent(QKeyEvent *e) {
  emit keyCaught((Qt::Key)e->key(), false);
  QLineEdit::keyReleaseEvent(e);
}

const Qt::Key IME_KEYS[] = {
    Qt::Key_A, Qt::Key_B, Qt::Key_C, Qt::Key_D, Qt::Key_E, Qt::Key_F, Qt::Key_G,
    Qt::Key_H, Qt::Key_I, Qt::Key_J, Qt::Key_K, Qt::Key_L, Qt::Key_M, Qt::Key_N,
    Qt::Key_O, Qt::Key_P, Qt::Key_Q, Qt::Key_R, Qt::Key_S, Qt::Key_T, Qt::Key_U,
    Qt::Key_V, Qt::Key_W, Qt::Key_X, Qt::Key_Y, Qt::Key_Z,
};

void CatchyLineEdit::inputMethodEvent(QInputMethodEvent *e) {
  QString text = e->preeditString();
  if (!text.isEmpty()) {
    QChar btn = text[text.size() - 1];
    if (btn.isLetter() || btn == ' ') {
      Qt::Key code = Qt::Key_Space;
      if (btn.isLetter())
        code = IME_KEYS[btn.toLower().toLatin1() - 'a'];

      emit keyCaught(code, true);
      QTimer::singleShot(250, [this, code]() { emit keyCaught(code, false); });
    }
  }

  QLineEdit::inputMethodEvent(e);
}