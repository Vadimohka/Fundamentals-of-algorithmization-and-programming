#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _keyboard(new Keyboard(this))
    , _trainer(new Trainer("", _keyboard, Ger, this))
{
    ui->setupUi(this);
    ui->editorsLayout->addWidget(_keyboard);
    ui->checkTextEdit->installEventFilter(_trainer);

    ui->checkTextEdit->setReadOnly(true);
    ui->accuracyBox->setReadOnly(true);
    ui->wordsBox->setReadOnly(true);
    ui->timerBox->setReadOnly(true);

    connect(ui->presetBtn, SIGNAL(clicked(bool)), SLOT(InsertPreset()));
    connect(ui->openBtn, SIGNAL(clicked(bool)), SLOT(OpenFile()));
    connect(ui->langBox, SIGNAL(currentIndexChanged(int)), SLOT(ChangeLang(int)));
    connect(ui->startBtn, SIGNAL(clicked(bool)), SLOT(StartCheck()));
    connect(_trainer, SIGNAL(endCheck()), SLOT(FinishCheck()));
    connect(_trainer, SIGNAL(updateStat()), SLOT(UpdateInfo()));
    connect(_trainer, SIGNAL(textChanged(QChar)), SLOT(ColorText(QChar)));

    _redF.setForeground(Qt::red);
    _greenF.setForeground(Qt::darkGreen);
    _blackF.setForeground(Qt::black);

    presets();
    ui->aimTextEdit->setText(_presets.at(_languge));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::presets()
{
    _presets.at(0) = "Und dann gab es Stille, Einsamkeit und eine leere Straße. Dunkle rote Dahlien blühten unter den tauben Fenstern von jemandem.";
    _presets.at(1) = "Et puis il y avait le silence, le désert et la rue vide. Les dahlias rouges s'épanouissaient sous les fenêtres sourdes de quelqu'un.";
    _presets.at(2) = "وهنا كان هناك صمت وخراب وشارع فارغ. ازدهرت الداليا الحمراء بشكل مظلم تحت النوافذ العمياء لشخص ما.";
    _presets.at(3) = "Mei gui shi hong se de Zi luo lan shi lan se de Tang shi tian de Ni ye shi.";
    _presets.at(4) = "А тут была цiшыня, бязлюднасць i пустая вулiца. Цёмна цвiлi пад нечымi глухiмi вокнамi чырвоныя вяргiнi.";
    _presets.at(5) = "וכאן היתה שתיקה, שממה ורחוב ריק. דליות אדומות פרחו בחושך מתחת לחלונות העיוורים של מישהו.";
}

bool MainWindow::isReadOnly() const
{
    return _isReadOnly;
}

void MainWindow::setReadOnly(bool newStatus)
{
    _isReadOnly = newStatus;

    ui->presetBtn->setEnabled(!newStatus);
    ui->openBtn->setDisabled(newStatus);
    ui->checkTextEdit->setReadOnly(!newStatus);
    ui->aimTextEdit->setReadOnly(newStatus);
}

void MainWindow::ChangeLang(int newLangIndex)
{
    _languge = static_cast<Language>(newLangIndex);
    _keyboard->setLanguage(_languge);
    _trainer->setLanguage(_languge);
    ui->aimTextEdit->setText(_presets.at(_languge));
}

void MainWindow::StartCheck()
{
    if (_trainer->isRunning()) {
        _trainer->finishCheck();
        return;
    }

    setReadOnly(true);
    ui->checkTextEdit->clear();
    ui->checkTextEdit->setFocus();

    _text = ui->aimTextEdit->toPlainText();
    _charCntr = 0;

    QTextCursor cursor = ui->aimTextEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(_blackF);

    _trainer->setText(ui->aimTextEdit->toPlainText());
    _trainer->StartCheck();
    UpdateInfo();
}

void MainWindow::FinishCheck()
{
    setReadOnly(false);
    ui->langBox->setFocus();
    UpdateInfo();
}

void MainWindow::ColorText(QChar newChar)
{
    QTextCursor cursor(ui->aimTextEdit->document());
    cursor.setPosition(_charCntr, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    if (ui->aimTextEdit->toPlainText().at(_charCntr) == newChar){
        cursor.mergeCharFormat(_greenF);
    } else {
        cursor.mergeCharFormat(_redF);
    }

    ++_charCntr;
}

void MainWindow::InsertPreset()
{
    ui->aimTextEdit->setText(_presets.at(static_cast<int>(_languge)));
}

void MainWindow::UpdateInfo()
{
    ui->wordsBox->setValue(_trainer->words());
    ui->accuracyBox->setValue(_trainer->accuracy());
    ui->timerBox->setValue(_trainer->seconds());
}

void MainWindow::OpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Text File", "", "");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    _text = in.readAll();
    file.close();

    ui->aimTextEdit->setText(_text);
}

