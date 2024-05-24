#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _keyboard(new VirtualKeyboard(this))
    , _analizer(new InputAnalizer("", _keyboard, Bel, this))
{
    ui->setupUi(this);
    ui->editorsLayout->addWidget(_keyboard);
    ui->checkTextEdit->installEventFilter(_analizer);

    ui->checkTextEdit->setReadOnly(true);
    ui->accuracyBox->setReadOnly(true);
    ui->wordsBox->setReadOnly(true);
    ui->timerBox->setReadOnly(true);

    connect(ui->presetBtn, SIGNAL(clicked(bool)), SLOT(slotInsertPreset()));
    connect(ui->openBtn, SIGNAL(clicked(bool)), SLOT(slotOpenFile()));
    connect(ui->langBox, SIGNAL(currentIndexChanged(int)), SLOT(slotChangeLang(int)));
    connect(ui->startBtn, SIGNAL(clicked(bool)), SLOT(slotStartCheck()));
    connect(_analizer, SIGNAL(endCheck()), SLOT(slotFinishCheck()));
    connect(_analizer, SIGNAL(updateStat()), SLOT(slotUpdateInfo()));
    connect(_analizer, SIGNAL(textChanged(QChar)), SLOT(slotColorText(QChar)));

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

void MainWindow::slotInsertPreset()
{
    ui->aimTextEdit->setText(_presets.at(static_cast<int>(_languge)));
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


void MainWindow::presets()
{
    _presets.at(0) = "Rosen sind rot Veilchen sind blau Zucker ist süß Und so bist du.";
    _presets.at(1) = "Roses sont rouges Les violettes sont bleues Le sucre est doux Et donc êtes-vous.";
    _presets.at(2) = "وردة حمراء البنفسج أزرق السكر حلو وأنت أيضا.";
    _presets.at(3) = "Mei gui shi hong se de Zi luo lan shi lan se de Tang shi tian de Ni ye shi.";
    _presets.at(4) = "Ружы чырвоныя Фіялеткі сінія Цукер лёгкі І так сама ты.";

}

void MainWindow::slotChangeLang(int newLangIndex)
{
    _languge = static_cast<Language>(newLangIndex);
    _keyboard->setLanguage(_languge);
    _analizer->setLanguage(_languge);
    ui->aimTextEdit->setText(_presets.at(_languge));
}

void MainWindow::slotStartCheck()
{
    if (_analizer->isRunning()) {
        _analizer->finishCheck();
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

    _analizer->setText(ui->aimTextEdit->toPlainText());
    _analizer->slotStartCheck();
    slotUpdateInfo();
}

void MainWindow::slotFinishCheck()
{
    setReadOnly(false);
    ui->langBox->setFocus();
    slotUpdateInfo();
}

void MainWindow::slotColorText(QChar newChar)
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

void MainWindow::slotUpdateInfo()
{
    ui->wordsBox->setValue(_analizer->words());
    ui->accuracyBox->setValue(_analizer->accuracy());
    ui->timerBox->setValue(_analizer->seconds());
}

void MainWindow::slotOpenFile()
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

