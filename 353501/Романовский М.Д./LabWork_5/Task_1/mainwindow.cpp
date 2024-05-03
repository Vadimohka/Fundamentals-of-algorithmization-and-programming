#include "mainwindow.h"
#include "CatchyLineEdit.h"
#include "LetterBox.h"
#include "PixArt.h"
#include <QDateTime>
#include <QFileDialog>
#include <QStringDecoder>
#include <QTimer>
#include <qapplication.h>
#include <qcombobox.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qlineedit.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qtextcursor.h>
#include <qtextdocument.h>
#include <qtextedit.h>
#include <qtextformat.h>
#include <qmath.h>

#include "Keyboard.h"
#include "ui_mainwindow.h"

#include <QGraphicsTextItem>
#include <qtransform.h>
#include <qwindowdefs.h>

QString colors[] = {"red", "green", "blue"};

const int PIX_SIZE = 4;

const char *HEART_ART = "\
________________\
________________\
__bbbb____bbbb__\
_bmmmmb__bmmmmb_\
bmmmmmmbbmmmmmmb\
bmmmmmmmmmmmmmmb\
bmmmmmmmmmmmmmmb\
bmmmmmmmmmmmmmmb\
_bmmmmmmmmmmmmb_\
__bmmmmmmmmmmb__\
___bmmmmmmmmb___\
____bmmmmmmb____\
_____bmmmmb_____\
______bmmb______\
_______bb_______\
________________";

// const char *GHOST_ART = "\
// ________________\
// _______bbb______\
// _____bbcccbb____\
// ____bbcccccbb___\
// ___bbccccccccb__\
// __bbcccccccccww_\
// __bcccccccccwll_\
// __bcccccccccwll_\
// _bbccccccccccwwb\
// _bcccccccccccccb\
// _bcccccccccccccb\
// _bcccccccccccccb\
// _bcccccccccccccb\
// _bcbcccbccccbccb\
// _bb_bcb_bccb_bcb\
// _b___b___bb___bb";

const char *GHOST_ART = "\
________________\
______cccc______\
____cccccccc____\
___cccccccccc___\
__cccwwccccwwc__\
__ccwwwwccwwww__\
__ccwwllccwwll__\
_cccwwllccwwllc_\
_ccccwwccccwwcc_\
_cccccccccccccc_\
_cccccccccccccc_\
_cccccccccccccc_\
_cccccccccccccc_\
_cccc_cccc_cccc_\
__cc___cc___cc__\
________________";

template <typename T> T limitOnSides(T inp, T l, T r) {
  if (inp < l)
    return l;
  if (inp > r)
    return r;
  return inp;
}

QList<QString> splitIntoUtf32s(QString inp) {
  QList<uint> parts = inp.toUcs4();

  int pos = 0;
  QList<QString> res;

  for (uint exp : parts) {
    char32_t expArr[] = {exp, 0};
    QString a = QString::fromUcs4(expArr);
    res.push_back(a);
  }

  return res;
}

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), gameScene(new QGraphicsScene),
      mainTimer(new QTimer), boxGroup(new QGraphicsItemGroup),
      finalText(new QGraphicsTextItem), keyboardScene(new QGraphicsScene),
      keyboard(new Keyboard), ghost(new PixArt(GHOST_ART, 3)) {
  ui->setupUi(this);
  ui->gameView->setScene(gameScene);
  ui->gameView->setSceneRect(-200, -200, 400, 400);
  gameScene->addItem(boxGroup);
  gameScene->addItem(finalText);
  ghost->setPos(0, -60);
  gameScene->addItem(ghost);

  connect(ui->lineEdit, &QLineEdit::textEdited, this, &MainWindow::textEntered);
  connect(ui->lineEdit, &CatchyLineEdit::doBackspace, this,
          &MainWindow::doBackspace);
  connect(mainTimer, &QTimer::timeout, this, &MainWindow::mainTime);
  ui->lineEdit->setText("");

  connect(ui->selectBox, &QComboBox::currentIndexChanged, this,
          &MainWindow::selectedStart);

  for (int i = 0; i < LIVES_COUNT; i++) {
    lives[i] = new PixArt(HEART_ART, 2);
    lives[i]->updateColormap('m', Qt::red);
    lives[i]->setPos((i - 4) * 40 + 20, -180);
    gameScene->addItem(lives[i]);
  }

  {
    QFont font = finalText->font();
    font.setBold(true);
    font.setPointSize(20);
    finalText->setFont(font);
    finalText->setTextWidth(400);
    finalText->setPos(-200, -20);
  }

  ui->keyboardView->setScene(keyboardScene);
  keyboardScene->addItem(keyboard);
  connect(ui->lineEdit, &CatchyLineEdit::keyCaught, this,
          &MainWindow::keyCaught);

  startGame("Ghost writer");

  preferredLang = 0;
}

void MainWindow::textEntered() {
  QString s = ui->lineEdit->text();
  if (!ui->lineEdit->isEnabled())
    return;

  QList<QString> parts = splitIntoUtf32s(s);
  for (QString part : parts) {
    addEntered(part);
  }

  ui->lineEdit->setText("");
}

void MainWindow::addEntered(QString c) {
  if (currentBox == 0)
    startedAt = QDateTime::currentSecsSinceEpoch();

  if (c.isEmpty()) {
    if (currentBox != 0) {
      currentBox--;
    }
    boxes[currentBox]->setEntered("");
  } else {
    bool correct = boxes[currentBox]->setEntered(c);
    if (!correct) {
      livesLeft--;
      lives[livesLeft]->updateColormap('m', Qt::black);
    }

    currentBox++;
  }

  prevUpdate = -1;

  updateKeyboardHint();

  if (livesLeft <= 0) {
    finishGame(false);
  }

  if (currentBox == boxes.count()) {
    finishGame(true);
  }
}

void MainWindow::mainTime() {
  updateOuts();

  float targetPos = -currentBox * 16 * 4;
  if (isRTL)
    targetPos = -targetPos;

  float reqDif = targetPos - boxGroup->x();

  boxGroup->moveBy(limitOnSides<float>(reqDif, -15, 15), 0);

  if (ui->lineEdit->isEnabled())
    ui->lineEdit->setFocus();
}

void MainWindow::updateOuts() {
  long long nowTime = QDateTime::currentSecsSinceEpoch();
  if (currentBox == 0)
    startedAt = nowTime;
  long long curTime = nowTime - startedAt;

  if (curTime == prevUpdate)
    return;
  prevUpdate = curTime;

  ui->outTime->setText(QString("%0:%1")
                           .arg(curTime / 60, 2, 10, QLatin1Char('0'))
                           .arg(curTime % 60, 2, 10, QLatin1Char('0')));

  long long cpm = 0;
  long long wpm = 0;
  for (auto s : wordEnds) {
    if (s > currentBox)
      break;
    wpm++;
  }

  if (curTime != 0) {
    cpm = currentBox * 60 / curTime;
    wpm = wpm * 60 / curTime;
  }

  ui->outCpm->setText(QString::number(cpm));
  ui->outWpm->setText(QString::number(wpm));
}

void MainWindow::startGame(QString expected) {
  ui->selectBox->setVisible(false);

  QList<QString> expectedParts = splitIntoUtf32s(expected);

  while (!boxes.empty()) {
    LetterBox *box = boxes.last();
    boxes.pop_back();
    boxGroup->removeFromGroup(box);
    delete box;
  }
  boxGroup->setPos(0, 0);
  finalText->setVisible(false);
  wordEnds.clear();

  isRTL = expected.isRightToLeft();
  
  int pos = 0;
  bool prevSpace = true;
  for (QString exp : expectedParts) {
    if (exp == "\r")
      continue;
    if (exp == "\n")
      exp = " ";

    LetterBox *box = new LetterBox(exp, PIX_SIZE);
    box->setX(isRTL ? -pos : pos);

    pos += PIX_SIZE * 16;
    boxGroup->addToGroup(box);

    prevSpace = false;
    if (exp == " ") {
      if (!prevSpace)
        wordEnds.push_back(boxes.count());
      prevSpace = true;
    }

    boxes.push_back(box);
  }
  boxGroup->setVisible(true);
  if (!prevSpace)
    wordEnds.push_back(boxes.count());

  QTransform rtlTransform;
  if (isRTL)
    rtlTransform.scale(-1, 1);
  ghost->setTransform(rtlTransform, false);

  currentBox = 0;

  livesLeft = LIVES_COUNT;
  for (int i = 0; i < LIVES_COUNT; i++) {
    lives[i]->updateColormap('m', Qt::red);
  }

  ui->lineEdit->setText("");
  prevUpdate = -1;

  playing = true;
  ui->lineEdit->setEnabled(true);
  ui->lineEdit->setVisible(true);

  keyboard->setAllColor(Qt::white);
  textEntered();
  mainTimer->start(20);

  updateKeyboardHint();
}

const QString VICTORY_HTML = "<h1 align=\"center\">Victory !!!</h1>";
const QString DEFEAT_HTML = "<h1 align=\"center\">Game over :(</h1>";

void MainWindow::finishGame(bool victory) {
  playing = false;
  ui->lineEdit->setEnabled(false);
  ui->lineEdit->setVisible(false);
  mainTimer->stop();

  boxGroup->setVisible(false);
  finalText->setVisible(true);
  finalText->setHtml(victory ? VICTORY_HTML : DEFEAT_HTML);

  updateOuts();
  keyboard->setAllColor(victory ? Qt::green : Qt::red);

  ui->selectBox->setCurrentIndex(0);
  ui->selectBox->setVisible(true);
}

void MainWindow::keyCaught(Qt::Key key, bool pressed) {
  // keyboard->updateKey(key, pressed);
}

const QString LANG_PREMADE[] = {
    "qwertyuiop asdfghjkl zxcvbnm",
    "asdfghjklöä qwertzuiopü yxcvbnm",
    "azertyuiop qsdfghjklmù wxcvbn",
    "ضصثقفغعهخحجد شسيبلاتنمكط ئءؤرلاىةوزظ",
    "北京 上海 我",
    "йцукенгшўзх фывапролджэ ячсмітьбю",
    "/'קראטוןםפ שדגכעיחלךף זסבהנמצתץ",
};

const int NEW_PREFERRED[] = {-1, -1, 0, 1, 2, 3, 0, 4, 5, 6};

void MainWindow::selectedStart() {
  int selectedIndex = ui->selectBox->currentIndex();
  if (selectedIndex == 0)
    return;
  if (selectedIndex == 1) {
    QString fileName = QFileDialog::getOpenFileName(
        this, "Open Training Text", "", tr("Text Files (*.txt)"));
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QString contents = file.readAll();
    startGame(contents);
    return;
  }

  int newPreffered = NEW_PREFERRED[selectedIndex];
  if (newPreffered != -1)
    preferredLang = newPreffered;

  startGame(LANG_PREMADE[selectedIndex - 2]);
}

void MainWindow::doBackspace() { addEntered(""); }

void MainWindow::updateKeyboardHint() {
  if (currentBox >= 0 && currentBox < boxes.count())
    keyboard->setCombo(boxes[currentBox]->getLetter(), preferredLang);
}