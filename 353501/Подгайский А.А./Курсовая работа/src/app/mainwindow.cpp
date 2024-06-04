//
// Created by artemious on 21.02.24.
//

#include "mainwindow.h"
#include "BaseEffect.h"
#include "Constructor.h"
#include "CoreAudio.h"
#include "CoreInfo.h"
#include "TimelineScene.h"
#include "exporter.h"
#include "loader.h"
#include "portaudio.h"
#include "ui_MainWindow.h"
#include <QAudioDecoder>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMovie>
#include <QTimer>
#include <qaudiodecoder.h>
#include <qaudioformat.h>
#include <qfiledialog.h>
#include <qicon.h>
#include <qlistwidget.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qpushbutton.h>
#include <qthread.h>
#include <qwindowdefs.h>
#include <stdexcept>

namespace ae {

ae::MainWindow *MainWindow::_instance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(size());

  PaError err = CoreAudio::init();
  CoreAudio::initializeTestStream();
  if (err != paNoError) {
    qDebug() << Pa_GetErrorText(err);
  }

  loader = new Loader;

  ui->timeline->setMouseTracking(false);
  tlScene = new TimelineScene(ui->timeline);
  ui->timeline->setSceneRect(0, 0, ui->timeline->frameSize().width(),
                             ui->timeline->frameSize().height());
  ui->timeline->setScene(tlScene);
  tlScene->drawWaveform();

  on_effectsBox_textActivated("Gain");

  connect(loader, &Loader::onFinish, this, &MainWindow::onBufReady);
  connect(loader, &Loader::error, this, &MainWindow::onError);
  connect(tlScene, &TimelineScene::selectionChanged, this,
          &MainWindow::on_selectionChanged);
  foreach (auto w, findChildren<QWidget *>()) {
    w->setFocusPolicy(Qt::NoFocus);
  }
}

MainWindow::~MainWindow() {
  currentEffect->requestStop();
  while (!currentEffect->hasStopped()) {
    QThread::msleep(100);
  }

  CoreAudio::pause();
  CoreAudio::terminate();
  delete loader;
  delete ui;
}

void MainWindow::onError(QString s) {
  QMessageBox::critical(
      this, "Error", QString("The file decoding resulted in error: %1").arg(s));
      if(isBlocked){
        blockAudio(false);
      }
}

void MainWindow::onBufReady() {
  qDebug() << "buf ready!";
  CoreAudio::setBuffer(loader->getResultingBuffer());
  clearHistory();
  tlScene->drawWaveform();
  blockAudio(false);
}

void MainWindow::on_playBtn_clicked() { CoreAudio::play(); }

void MainWindow::on_pauseBtn_clicked() { CoreAudio::pause(); }

void MainWindow::on_stopBtn_clicked() { CoreAudio::stop(); }

void MainWindow::on_selAllBtn_clicked(){
  ui->selButton->toggle();
  tlScene->selectAll();
  
}

} // namespace ae

void ae::MainWindow::on_actionOpen_triggered() {
  QString fname = QFileDialog::getOpenFileName(this, "Open file", "",
                                               "Music (*.mp3 *.wav)");
  if (fname.isEmpty()) {
    return;
  }
CoreAudio::stop();
  blockAudio(true);
  ui->navButton->toggle(); // go into navigation mode
  loader->startDecoding(fname);
  ui->fnameLabel->setText(fname);
}

void ae::MainWindow::on_actionExport_triggered() {
  auto fname =
      QFileDialog::getSaveFileName(this, "Export file", {}, "PCM WAV (*.wav)");
  if (fname.isEmpty()) {
    return;
  }

  try {
    Exporter::exportCoreBuffer(fname);
  } catch (const std::runtime_error &) {
    QMessageBox::warning(this, "Warning", "Could not save the file");
  }
}

const TimelineScene *ae::MainWindow::getTimeline() { return tlScene; }

void ae::MainWindow::onBufferChanged(int beg, int end, QString changeInfo) {
  tlScene->drawWaveform();
  tlScene->pushEffect(beg, end);

  auto last_col = tlScene->getLastEffectColor();
  QPixmap pm(16, 16);
  pm.fill(last_col);
  auto item = new QListWidgetItem(changeInfo);
  item->setIcon(QIcon(pm));

  ui->historyList->addItem(item);
  ui->historyList->setCurrentRow(ui->historyList->count() - 1);
}

void ae::MainWindow::on_effectsBox_textActivated(const QString &text) {
  if (currentEffect) {
    delete currentEffect;
  }
  currentEffect = Constructor::getEffect(text.toStdString());
  if (!currentEffect) {
    qDebug() << "Constructor: no such effect";
    return;
  }

  currentEffect->setUpUi(ui->effectWidget);
  foreach (QWidget *w, ui->effectWidget->findChildren<QWidget *>()) {
    w->setFocusPolicy(Qt::ClickFocus);
  }
  connect(currentEffect, &BaseEffect::modifiedBuffer, this,
          &MainWindow::onBufferChanged);
}

void ae::MainWindow::on_navButton_toggled(bool b) {
  if (b) {
    tlScene->setMouseBehaviour(MouseBehaviour::Navigation);
    ui->fromLbl->setText("--:--:--.---");
    ui->toLbl->setText("--:--:--.---");
  }
}

void ae::MainWindow::on_selButton_toggled(bool b) {
  if (b) {
    tlScene->setMouseBehaviour(MouseBehaviour::Selection);
  }
}

void ae::MainWindow::keyPressEvent(QKeyEvent *keyEvent) {
  QMainWindow::keyPressEvent(keyEvent);
  if (isBlocked) {
    return;
  }
  if (keyEvent->key() == Qt::Key_Space) {
    if (CoreAudio::isPlaying()) {
      qDebug() << "pausing";
      CoreAudio::pause();
    } else {
      CoreAudio::play();
    }
  }
}

ae::MainWindow *ae::MainWindow::MainWindow::getInstance() {
  if (!_instance) {
    _instance = new MainWindow();
  }
  return _instance;
}

void ae::MainWindow::MainWindow::releaseInstance() {
  if (_instance) {
    delete _instance;
  }
}

void ae::MainWindow::on_historyList_currentRowChanged(int row) {
  tlScene->selectEffect(row);
}

void ae::MainWindow::MainWindow::setTimeLabel(QString s) {
  ui->timeLbl->setText(s);
}

void ae::MainWindow::MainWindow::clearHistory() {
  tlScene->resetEffects();
  ui->historyList->clear();
}

void ae::MainWindow::MainWindow::blockAudio(bool b) {
  static bool wasPlaying;

  isBlocked = b;

  ui->playBtn->setEnabled(!b);
  ui->pauseBtn->setEnabled(!b);
  ui->stopBtn->setEnabled(!b);
  ui->effectsBox->setEnabled(!b);
  setLoading(b);
  ui->actionOpen->setEnabled(!b);
  ui->actionExport->setEnabled(!b);

  if (b) {
    wasPlaying = CoreAudio::isPlaying();
    CoreAudio::pause();
  } else {
    if (wasPlaying)
      CoreAudio::play();
  }
}

void ae::MainWindow::MainWindow::setLoading(bool b) {
  static QMovie *movie = new QMovie(":/GIF/Loading.gif");
  movie->setScaledSize(QSize(20, 20));
  if (b) {
    ui->loadingLbl->setMovie(movie);
    // ui->loadingLbl->show();
    movie->start();
  } else {
    ui->loadingLbl->clear();
    movie->stop();
    // ui->loadingLbl->hide();
  }
}

void ae::MainWindow::on_selectionChanged(int beg, int end) {
  auto buf = CoreAudio::getBuffer();
  int sampPerPx = buf.size / tlScene->width();
  if (beg > end) {
    std::swap(beg, end);
  }
  ui->fromLbl->setText(CoreInfo::getTimeString(sampPerPx * beg));
  ui->toLbl->setText(CoreInfo::getTimeString(sampPerPx * end));
}
