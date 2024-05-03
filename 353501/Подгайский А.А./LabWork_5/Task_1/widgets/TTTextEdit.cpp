#include "TTTextEdit.h"
#include "Common.h"
#include <QGuiApplication>
#include <QKeyEvent>
#include <pthread.h>
#include <qapplication.h>
#include <qdebug.h>
#include <qelapsedtimer.h>
#include <qevent.h>
#include <qguiapplication.h>
#include <qnamespace.h>
#include <qplaintextedit.h>
#include <qtextcursor.h>
#include <qtextedit.h>
#include <qtextoption.h>

TTTextEdit::TTTextEdit(QWidget *parent)
    : QTextEdit(parent), timerPtr(new QElapsedTimer) {
  setTextInteractionFlags(Qt::TextEditable);
  setUndoRedoEnabled(false);
  setWordWrapMode(QTextOption::NoWrap);
  connect(this, &TTTextEdit::textChanged, this, &TTTextEdit::validateText);
}

void TTTextEdit::mousePressEvent(QMouseEvent *) { setFocus(); }

void TTTextEdit::validateText() {

//  PREPARATION

  if (!validString) {
    // qDebug() << "no validation string!";
    return;
  }

  if (!timerPtr->isValid()) {
    timerPtr->start();
  }

  auto new_sz = toPlainText().size();
  auto vstring_sz = validString->size();
  if (new_sz == lastTextSize) {
    return;
  }


// CHECK BACKSPACE

  if (new_sz < lastTextSize) {
    // qDebug() << "Backspace" << new_sz << lastTextSize;
    emit inputReceived(InputState::Backspace);
    wrongAtOrder = std::max((qsizetype)0, wrongAtOrder - (lastTextSize - new_sz));
    lastTextSize = new_sz;
    return;
  }

  //qDebug() << "validate call";

  //EMIT SIGNAL FOR LAST CHARACTER
  if(locale != Locale::Chinese){
    emit charKeyPressed(toPlainText().back());
  }


  // FOR EACH CHAR IN ADDED, DO VALIDATION OR INVALIDATION
  // kill me pls
  for (int pos = lastTextSize; pos < std::min(new_sz, vstring_sz); ++pos) {
    // qDebug() <<  toPlainText();
    if (pos >= 0 && (*validString)[pos] != toPlainText()[pos]) {
        emit inputReceived(InputState::Wrong);
        ++wrongAtOrder;
        ++totalSymbols;
    } else {

      wrongAtOrder = 0;
      ++totalCorrect;
      ++totalSymbols;
      if ((*validString)[pos] == ' ') {
        ++totalWords;
      }

      emit inputReceived(InputState::Valid);
      //qDebug() << "Valid!";
    }
    // qDebug() << "size: " << validString->size();

    if (pos >= validString->size() - 1) {
      emit requestValidString();
      lastTextSize = 0;
      wrongAtOrder = 0;
      blockSignals(true);
      setText({});
      blockSignals(false);
      return;
    } else {
      lastTextSize = new_sz;
    }
  }


  // IF WE HAVE TO MANY WRONG CHARS AT ORDER, DELETE THEM 
//qDebug() << wrongAtOrder;
if(wrongAtOrder > MAX_WRONG){
  // qDebug() << wrongAtOrder << "DELETING WRONG CHARACTERS";
  blockSignals(true);
  auto cur = textCursor();
  while(wrongAtOrder > MAX_WRONG){
    cur.deletePreviousChar();
    --wrongAtOrder;
  }
  //++wrongAtOrder;
  setTextCursor(cur);
  lastTextSize = toPlainText().size();
  blockSignals(false);
  emit inputReceived(InputState::Backspace);
  emit inputBlocked();
}

}

void TTTextEdit::setValidationString(const QString *s) {
  validString = s;
  lastTextSize = 0;
  qDebug() << "vstring set";
}

void TTTextEdit::setLocale(Locale loc) {
  if (loc == Locale::Arabic || loc == Locale::Hebrew) {
    //QGuiApplication::setLayoutDirection(Qt::RightToLeft);
    setAlignment(Qt::AlignRight);
  } else {
    //QGuiApplication::setLayoutDirection(Qt::LeftToRight);
    setAlignment(Qt::AlignLeft);
  }
  locale = loc;
}

long TTTextEdit::getCPM() const {
  if (!timerPtr->isValid()) {
    return -1;
  }

  auto time = shiftedElapsed();
  if (time < 10'000) {
    return -1;
  } else {
    return (double)totalSymbols / time * 60'000;
  }
}

long TTTextEdit::getWPM() const {
  if (!timerPtr->isValid()) {
    return -1;
  }

  auto time = shiftedElapsed();
  if (time < 10'000) {
    return -1;
  } else {
    return (double)totalWords / time * 60'000;
  }
}

double TTTextEdit::getAccuracy() const {
  if (totalSymbols != 0)
    return (double)totalCorrect / totalSymbols;
  else {
    return 0.0;
  }
}

double TTTextEdit::getElapsedTime() const {
  return timerPtr->isValid() ? (double)shiftedElapsed() / 1'000 : 0.0;
}

void TTTextEdit::resetStats() {
  timerPtr->invalidate();
  wrongAtOrder = 0;
  lastCursorPos = 0;
  lastTextSize = 0;

  totalCorrect = 0;
  totalSymbols = 0;
  totalWords = 0;
  timeShift = 0;
}

void TTTextEdit::freeze() {
  // if already freezed
  if (!timerPtr->isValid()) {
    return;
  }

  timeShift = shiftedElapsed();
  timerPtr->invalidate();
}

bool TTTextEdit::isFreezed() const { return !timerPtr->isValid(); }

long TTTextEdit::getTotalChars() const { return totalSymbols; }

qint64 TTTextEdit::shiftedElapsed() const {
  return timeShift + timerPtr->elapsed();
}

void TTTextEdit::keyPressEvent(QKeyEvent *ev) {
  qDebug() << "press event!";
  // prevent paste
  if (ev->keyCombination() != QKeyCombination(Qt::CTRL, Qt::Key_C) &&
      ev->keyCombination() != QKeyCombination(Qt::CTRL, Qt::Key_V) &&
      ev->keyCombination() != QKeyCombination(Qt::CTRL, Qt::Key_X)) {
    QTextEdit::keyPressEvent(ev);
  }
}



void TTTextEdit::inputMethodEvent(QInputMethodEvent* ev) {
  qDebug() << "input event";
  qDebug() << ev->commitString();
  // if(locale == Locale::Chinese){
    auto input = ev->preeditString();
    if(!input.isEmpty()){
      qDebug() << "pressed " << input.back().toLower();
      emit charKeyPressed( input.back().toLower().toLatin1() );
    }
  // }
  QTextEdit::inputMethodEvent(ev);
}

Locale TTTextEdit::getLocale() {
  return locale;    
}
