#ifndef D05211A4_3103_43AF_8091_D63428B2A179
#define D05211A4_3103_43AF_8091_D63428B2A179

#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QScopedPointer>
#include <qcontainerfwd.h>
#include <qelapsedtimer.h>
#include <qevent.h>
#include <qnamespace.h>
#include <qscopedpointer.h>
#include <qwidget.h>
#include "Common.h"

using namespace Common;

enum class InputState { Wrong, Valid, Backspace };


/* QTextEdit for touch typing. Wrong characters are highlighted red, correct are
 * highlighted green*/
class TTTextEdit : public QTextEdit {
  Q_OBJECT

  static const int keyCharBias = 'A' - Qt::Key_A;

  static const int MAX_WRONG = 5;

  const QString * validString = nullptr;

  int wrongAtOrder = 0;
  int lastCursorPos = 0;

  long lastTextSize = 0;

  long totalCorrect = 0;
  long totalSymbols = 0;
  long totalWords = 0;

  Locale locale = Locale::Belarussian;

  qint64 timeShift = 0;

  QScopedPointer<QElapsedTimer> timerPtr{};

  qint64 shiftedElapsed() const;

 

protected :
    void keyPressEvent(QKeyEvent* ev) override;

    
public:
  TTTextEdit(QWidget *parent = nullptr);

  void mousePressEvent(QMouseEvent *) override;
  void inputMethodEvent(QInputMethodEvent*) override;


  void validateText();
  void setLocale(Locale loc);
  void freeze();
  long getCPM() const;
  long getWPM() const;
  double getAccuracy() const;
  double getElapsedTime() const;
  long getTotalChars() const;
  bool isFreezed() const; 
  void resetStats();

  Locale getLocale();

public slots:
  void setValidationString(const QString *s);

signals:
  void inputReceived(InputState);
  void requestValidString();
  void inputBlocked();
  void charKeyPressed(QChar);
};

#endif /* D05211A4_3103_43AF_8091_D63428B2A179 */
