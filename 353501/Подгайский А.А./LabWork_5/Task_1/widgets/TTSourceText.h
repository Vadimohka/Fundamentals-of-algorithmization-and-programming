#ifndef BC099FDC_F1E5_480B_BC45_547A08F730FD
#define BC099FDC_F1E5_480B_BC45_547A08F730FD


#include <QTextEdit>
#include <qevent.h>
#include <qtextedit.h>
#include <qtmetamacros.h>
#include "Common.h"

using namespace Common;

class TTSourceText : public QTextEdit {
  Q_OBJECT

  static const QString t_begin;
  static const QString t_begin_right;
  static const QString t_end;
  static const QString t_style_red;
  static const QString t_style_gray;
  static const QString t_style_green;
  static const QString t_style_end;
  
  static const int lineLength;

  static const int CHAR_SIZE_PX = 19;

  
  long lastTextSize = 0;
  long pos = 0;
  int htmlPos = t_begin.size();
  Locale locale = Locale::Belarussian;

  QString htmlString;

  const QString *validString = nullptr;

  QString currentGroup;
  size_t beginPos = 0;
  int lineSymbolCapacity = 10;


private:
  void adjustCursorPos();

void showEvent(QShowEvent*) override;

public:
TTSourceText(QWidget *parent = nullptr);
  void setSourceString(const QString *s);
  void nextSymbolGroup();
  void validateCurrent();
  void invalidateCurrent();
  void backSpace(int back);
  void refreshSymbolCapacity();
  void setLocale(Locale loc);
  void adjustCapacity();
  const QString* getCurrentGroup() const;

signals:
  void validStringEnd();

};


#endif /* BC099FDC_F1E5_480B_BC45_547A08F730FD */
