#include <QMessageBox>
#include<QInputDialog>
#include "mainwindow.h"
#include "Common.h"
#include "TTKeyDict.h"
#include "TTSourceText.h"
#include "TTTextEdit.h"
#include "ui_mainwindow.h"
#include <exception>
#include <qapplication.h>
#include <qfiledialog.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qinputdevice.h>
#include <qinputdialog.h>
#include <qlocale.h>
#include <qmessagebox.h>
#include <qmetaobject.h>
#include <qtextcursor.h> 
#include <qtextformat.h>
#include "TTLoader.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  statsUpdater.reset(new QTimer);
  inpFont.setPixelSize(fontSzPx);
  inpFont.setStyleHint(QFont::TypeWriter);
  ui->userText->setFont(inpFont);

  connect(ui->userText, &TTTextEdit::requestValidString, this, &MainWindow::provideValidString);
  connect(ui->userText, &TTTextEdit::inputReceived, this,
          &MainWindow::handleInput);
  connect(statsUpdater.data(), &QTimer::timeout, this,
          &MainWindow::updateStats);

  connect(ui->sourceText, &TTSourceText::validStringEnd, this,
   &MainWindow::onTrainingCompleted);

  connect(ui->userText, &TTTextEdit::charKeyPressed,  this, &MainWindow::highlightChar);
  connect(ui->userText, &TTTextEdit::inputBlocked, this, &MainWindow::onInputBlocked);

  ui->userText->setEnabled(false);
  ui->userText->setStyleSheet("background-color: gray");
  ui->inpBlockedLbl->hide();
  updateStats();
  statsUpdater->start(STATS_UPDATE_FREQ);

  //defaultTrainingRoutine(Locale::Arabic);
}

void MainWindow::onInputBlocked(){
  ui->inpBlockedLbl->show();
}

void MainWindow::handleInput(InputState state) {
  ui->inpBlockedLbl->hide();
  switch (state) {

  case InputState::Valid: {
    ui->sourceText->validateCurrent();
  } break;

  case InputState::Wrong: {
    ui->sourceText->invalidateCurrent();
  } break;

  case InputState::Backspace: {
    ui->sourceText->backSpace(ui->userText->toPlainText().size() - 1);
    break;
  }
  }
}

void MainWindow::on_defTrainingBtn_clicked(){
  bool ok;
  auto item = QInputDialog::getItem(this, "Choose locale", "Locale: ", {"Arabic", "Hebrew", "Belarussian",
   "French", "German", "Chinese"}, 0, false, &ok);
   if(!ok){
    return;
   }

  Locale loc;
  if(item == "Arabic"){
    loc = Locale::Arabic;
  } else if(item == "Hebrew"){
    loc  = Common::Locale::Hebrew;
  } else if(item == "Belarussian"){
    loc = Common::Locale::Belarussian;
  } else if(item == "French"){
    loc = Common::Locale::French;
  } else if(item == "German"){
    loc = Locale::German;
  } else if(item == "Chinese"){
    loc = Locale::Chinese;
  } else {
    return;
  }

  defaultTrainingRoutine(loc);
  
}



void MainWindow::on_customTrainingBtn_clicked(){

  auto fname = QFileDialog::getOpenFileName(this, "Open training",
  "", "Text files (*.txt)");
  if(fname.isEmpty()){
    return;
  }

  ui->keyboard->setKeyboardChars(keyDict.getLocString(Locale::Belarussian));

  ui->userText->setLocale(Locale::Belarussian);
  ui->sourceText->setLocale(Locale::Belarussian);

  vstring = TTLoader::loadCustom(fname);
  removeMultipleSpaces(vstring);
  vstring = vstring.trimmed();
  ui->sourceText->setSourceString(&vstring);

  ui->userText->blockSignals(true);
  ui->userText->setText({});
  ui->userText->blockSignals(false);
  ui->userText->resetStats();

  provideValidString();
  ui->userText->setEnabled(true);
  ui->userText->setStyleSheet("");

}


void MainWindow::provideValidString(){
  ui->userText->setValidationString(ui->sourceText->getCurrentGroup());
}

void MainWindow::onTrainingCompleted(){
  ui->userText->freeze();
  ui->userText->setEnabled(false);
  vstring = "";
  ui->sourceText->setHtml({});
   ui->userText->setStyleSheet("background-color: gray");
  QMessageBox::information(this, "Info", "Training completed! See you results in \"Stats\". You can choose new training. ");
}


void MainWindow::updateStats() {
  const auto usrText = ui->userText;

  if (usrText->isFreezed()) {
    ui->statsFreezedLbl->setText("Stats freezed");
    ui->wpmLbl->setStyleSheet("QLabel {background-color: gray}");
    ui->smpLbl->setStyleSheet("QLabel {background-color: gray}");
     ui->accuracyLbl->setStyleSheet( "QLabel {background-color: gray}");
      ui->timeLbl->setStyleSheet( "QLabel {background-color: gray}");
  } else {
      ui->statsFreezedLbl->setText("");
    ui->wpmLbl->setStyleSheet({});
    ui->smpLbl->setStyleSheet({});
    ui->accuracyLbl->setStyleSheet({});
    ui->timeLbl->setStyleSheet({});
     
      auto wpm = usrText->getWPM();
    auto cpm = usrText->getCPM();
    auto acc = usrText->getAccuracy();
    auto time = usrText->getElapsedTime();

    ui->wpmLbl->setText(wpm == -1 ? "--" : QString::number(wpm));
    ui->smpLbl->setText(cpm == -1 ? "--" : QString::number(cpm));
    ui->accuracyLbl->setText(QString::number(acc, 'g', 2));
    ui->timeLbl->setText(QString::number(time));

    if (lastTotalSymbols == usrText->getTotalChars()) {
        ++updateStatsCallsWithNoChange;
        if (updateStatsCallsWithNoChange == STATS_UPDATE_CALLS_BEFORE_FREEZE) {
          usrText->freeze();
        }
    } else {
        updateStatsCallsWithNoChange = 0;
    }

    lastTotalSymbols = usrText->getTotalChars();
  }
  
  
}

void MainWindow::defaultTrainingRoutine(Locale loc){
  ui->keyboard->setKeyboardChars(keyDict.getLocString(loc));

  ui->userText->setLocale(loc);
  ui->sourceText->setLocale(loc);


try{
  vstring = TTLoader::loadDefault(loc);
} catch(const std::exception& ex){
  QMessageBox::critical(this, "Error", ex.what());
  QApplication::exit(0);
}
  
  removeMultipleSpaces(vstring);
  vstring = vstring.trimmed();
  ui->sourceText->setSourceString(&vstring);

  ui->userText->blockSignals(true);
  ui->userText->setText({});
  ui->userText->blockSignals(false);

  ui->userText->resetStats();

  provideValidString();
  ui->userText->setEnabled(true);
  ui->userText->setStyleSheet("");
}


// html does not show multiple spaces, only with &nbsp, which woul break TTTextEdit strucutre
void MainWindow::removeMultipleSpaces(QString& s) {
  int cnt = 0;
  auto i = s.begin();
  while(i != s.end()){
    if( *i == ' ' || *i == '\t' || *i == '\n'){
      ++cnt;
      *i = ' ';
    } else {
      cnt = 0;
    }

    if(cnt > 1){
      i = s.erase(i);
    } else {
      ++i;
    }
  }
}

void MainWindow::highlightChar(QChar c){
  ui->keyboard->highlightKey( keyDict.getKey(c, ui->userText->getLocale()) );
}