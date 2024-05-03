#include "TTSourceText.h"
#include "Common.h"
#include <algorithm>
#include <iterator>
#include <qbytearrayalgorithms.h>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qevent.h>
#include <qfontmetrics.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qplaintextedit.h>
#include <qtextcursor.h>
#include <qtextedit.h>
#include <qwindowdefs.h>
#include <QLayout>

const QString TTSourceText::t_begin =       QString("<p style=\"font-size:%1px; font-family: monospace\">").arg(CHAR_SIZE_PX);
const QString TTSourceText::t_begin_right = QString("<p style=\"text-align: left; font-size:%1px; font-family: monospace\">").arg(CHAR_SIZE_PX);
const QString TTSourceText::t_end =         "</p>";
const QString TTSourceText::t_style_red =   "<span style=\"background-color:red  \">";
const QString TTSourceText::t_style_green = "<span style=\"background-color:green\">";
const QString TTSourceText::t_style_gray =  "<span style=\"background-color:gray \">";
const QString zwj = "&zwj;";
const QString nbsp = "&nbsp;";
const QString TTSourceText::t_style_end = "</span>";

const int TTSourceText::lineLength = TTSourceText::t_style_red.size() +
                                     TTSourceText::t_style_end.size() +
                                     + 1;


TTSourceText::TTSourceText(QWidget *parent) : QTextEdit(parent) {
  setReadOnly(true);
  setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
}

//why do we have set and change source string? it a god damn workaround,
//cuz setSourceString is called from the constructor while widget is still not visible
//and we obtain html only when the appropriate size in layout is set
//but when we change the source string, we at moment set html.
void TTSourceText::setSourceString(const QString *s) {
  validString = s;
  beginPos = 0;
  currentGroup = "";
  if(isVisible()){
    nextSymbolGroup();
  }
}



void TTSourceText::validateCurrent() {
  QString sInsert = t_style_green % QChar( currentGroup[pos] )  % t_style_end;
  htmlString.replace(htmlPos, sInsert.size(), sInsert);

  setHtml(htmlString);
  htmlPos += lineLength;

  qDebug() << htmlString;
  pos++;

  if (pos == currentGroup.size()) {
    nextSymbolGroup();
  }
}

void TTSourceText::invalidateCurrent() {
  QString sInsert = t_style_red % QChar( currentGroup[pos] ) % t_style_end;
  htmlString.replace(htmlPos, sInsert.size(), sInsert);

  setHtml(htmlString);
  htmlPos += lineLength;
  pos++;

  if (pos == currentGroup.size()) {
    nextSymbolGroup();
  }
}

void TTSourceText::backSpace(int back_pos) {
  for (int i = pos-1; i > back_pos; --i) {
    htmlPos -= lineLength;
    QString sInsert = t_style_gray  % QChar( currentGroup[i] )  % t_style_end;
    htmlString.replace(htmlPos, sInsert.size(), sInsert);
  }

  pos = back_pos + 1;
  setHtml(htmlString);
  qDebug() << htmlString;
}


void TTSourceText::nextSymbolGroup() {
  pos = 0;
  beginPos += currentGroup.size();
  htmlString.clear();

  qDebug() << "next group";
  qDebug() << beginPos;
  qDebug() << validString->size();

  //at the end of the string
  if (beginPos >= validString->size()) {
    emit validStringEnd();
    return;
  }

  auto groupSize = std::min((unsigned long long)lineSymbolCapacity,
                            validString->size() - beginPos);

  currentGroup = validString->mid(beginPos, groupSize);

  //remove starting space, since html doesn't show them.
  if(!currentGroup.isEmpty() && currentGroup[0] == ' '){
    currentGroup.erase(currentGroup.begin());
    --groupSize;
  }

  qDebug() << currentGroup;

  // //separate new line groups
  // qDebug() << "next group:";
  // auto newLine = std::find(currentGroup.begin(), currentGroup.end(), '\n');
  // qDebug() << std::distance( currentGroup.begin(), newLine); 
  // if(newLine != currentGroup.end() && std::distance(currentGroup.begin(), newLine) < groupSize){
  //   groupSize = std::distance(currentGroup.begin(), newLine) ;
  //   currentGroup = currentGroup.first(groupSize);
  // }

  if(locale == Locale::Arabic || locale == Locale::Hebrew){
    htmlPos = t_begin_right.size();
    htmlString = t_begin_right;
  } else {
    htmlPos = t_begin.size();
    htmlString = t_begin;
  }
  
  for(auto ch : currentGroup ){
    htmlString += t_style_gray % ch % t_style_end;
  }
  htmlString += t_end;

  qDebug() << htmlString;
  setHtml(htmlString);
}

void TTSourceText::refreshSymbolCapacity() {
  //qDebug() << sizeHint();
  lineSymbolCapacity = sizeHint().width() / 10;
}

void TTSourceText::showEvent(QShowEvent *ev) {
  QTextEdit::showEvent(ev);
  adjustCapacity();
 }
  


const QString* TTSourceText::getCurrentGroup() const{
  return &currentGroup;    
}


void TTSourceText::setLocale(Locale loc) {
  locale = loc;   
  if(loc == Locale::Arabic || loc == Locale::Hebrew){
    setAlignment(Qt::AlignRight);
  } else {
    setAlignment(Qt::AlignLeft);
  }
  adjustCapacity();
}

void TTSourceText::adjustCapacity() {
if(locale == Locale::Arabic){
    lineSymbolCapacity = 60;
  } else if (locale == Locale::Chinese){
    lineSymbolCapacity = 45; 
  } else if(locale == Locale::Hebrew){
    lineSymbolCapacity = 80;
  } else {
    lineSymbolCapacity = 64;
  }
}