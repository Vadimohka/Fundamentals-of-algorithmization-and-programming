#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    getSettings();
    setChordTransposerConnection();
    setMetronomeConnection();
    setTunerConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fromChordTransposerToMetronomeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_fromChordTransposerToTunerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_fromMetronomeToChordTransposerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_fromMetronomeToTunerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_fromTunerToChordTransposerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_fromTunerToMetronomeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    QMainWindow::closeEvent(event);
}

QString MainWindow::xorEncrypt(QString str)
{
    QString result;
    size_t keyLength = _key.length();

    for (size_t i = 0; i < str.length(); ++i) {
        QChar char1 = str.at(i);
        QChar char2 = _key.at(i % keyLength);

        QChar encryptedChar = QChar(char1.unicode() ^ char2.unicode());
        result += encryptedChar;
    }

    return result;
}

void MainWindow::saveSettings()
{
    QString settingsStr = "";
    QString volume = QString::number(ui->volumeSlider->value());
    QString BPM = QString::number(ui->BPMSlider->value());
    QString stressFirstBit = (ui->stressFirstBitCheckBox->isChecked())?"1":"0";
    settingsStr = volume + " " + BPM + " " + stressFirstBit + " ";

    QString chordsStr;
    if(ui->textEdit->toPlainText() != "" && ui->textEdit->toPlainText() != "Неправильный ввод. Пожалуйста, прочитайте правила ввода аккордов и введите правильные аккорды.")
    {
        chordsStr = ui->textEdit->toPlainText();
    }
    else
    {
        chordsStr = "No data";
    }
    settingsStr += chordsStr;

    QFile _file("/home/bahmatok/coursach/untitled1/settings.txt");
    if (!_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "Произошла ошибка! Ваши настройки не сохранены :(");
        return;
    }
    QTextStream textStream(&_file);
    textStream << xorEncrypt(settingsStr);
    _file.close();
}

void MainWindow::getSettings()
{
    QFile _file("/home/bahmatok/coursach/untitled1/settings.txt");
    if (!_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "Произошла ошибка! Не удаётся получить сохранённые настройки :(");
        _isGetSettings = false;
        return;
    }

    QTextStream in(&_file);
    _settingsStr = "";
    _settingsStr = in.readAll();
    if(_settingsStr == "")
    {
        _isGetSettings = false;
        return;
    }
    _settingsStr = xorEncrypt(_settingsStr);
    _file.close();
}

void MainWindow::setMetronomeConnection()
{
    ui->BPMSpinBox->setRange(1, 200);
    ui->BPMSlider->setRange(1,200);
    ui->volumeSlider->setRange(0,100);
    if(!_isGetSettings)
    {
        ui->volumeSlider->setSliderPosition(60);
        ui->volumeLabel->setText("60");
        ui->BPMSlider->setSliderPosition(60);
        ui->BPMSpinBox->setValue(60);
    }
    else
    {
        bool flag = true;
        int volume = _settingsStr.split(" ")[0].toInt(&flag);
        int BPM = _settingsStr.split(" ")[1].toInt(&flag);
        int stressFirstBit = _settingsStr.split(" ")[2].toInt(&flag);
        //qDebug() << volume << BPM << stressFirstBit;
        if(flag)
        {
            ui->volumeSlider->setSliderPosition(volume);
            ui->volumeLabel->setText(QString::number(volume));
            ui->BPMSlider->setSliderPosition(BPM);
            ui->BPMSpinBox->setValue(BPM);
            if(stressFirstBit == 1)
                ui->stressFirstBitCheckBox->setCheckState(Qt::Checked);
            else
                ui->stressFirstBitCheckBox->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->volumeSlider->setSliderPosition(60);
            ui->volumeLabel->setText("60");
            ui->BPMSlider->setSliderPosition(60);
            ui->BPMSpinBox
                ->setValue(60);
        }
    }

    ticker = new Ticker(this);
    timer = new Timer(this);
    connect(timer, &Timer::timeout, ticker, &Ticker::playSound);

    connect(ui->volumeSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            ui->volumeLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(ui->volumeSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            ticker, static_cast<void (Ticker::*)(int)>(&Ticker::setVolumeLevel));

    connect(ui->BPMSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=] () {
                ui->BPMSlider->setValue(ui->BPMSpinBox->value());
            });

    connect(ui->BPMSlider, &QSlider::valueChanged,
            [=] () {
                ui->BPMSpinBox->setValue(ui->BPMSlider->value());
            });

    connect(ui->BPMSlider, &QSlider::valueChanged,
            [=] () {
                timer->setTickingValue(ui->BPMSlider->value());
            });

    connect(ui->startMetronomeButton, &QPushButton::clicked, timer, &Timer::start);
    connect(ui->stopMetronomeButton, &QPushButton::clicked, timer, &Timer::stop);

    connect(ui->stressFirstBitCheckBox, &QCheckBox::stateChanged, ticker, &Ticker::reqToStressFirstBeat);
}

void MainWindow::setChordTransposerConnection()
{
    transposer = new ChordTransposer;
    for (int i = -6; i <= 6; ++i)
    {
        ui->tonesComboBox->addItem(QString::number(i), i);
    }
    //connect(ui->sortChordsButton, &QPushButton::clicked, chordTransposer, &ChordTransposer::sort);
}

void MainWindow::setTunerConnection()
{
    tuner = new Tuner;
    if(_isGetSettings)
    {
        int spaces = 0, i = 0;
        while(spaces < 3 && i < 10)
        {
            if(_settingsStr[i] == ' ')
                spaces++;
            i++;
        }
        QString chordsStr = _settingsStr.mid(i);
        if(chordsStr != "No data")
        {
            ui->textEdit->setPlainText(chordsStr);
        }
    }
}


void MainWindow::on_sortChordsButton_clicked()
{
    chords = ui->textEdit->toPlainText().split(QRegExp("\\s+"), QString::SkipEmptyParts);

    if (!transposer->validateChords(chords)) {
        ui->textEdit->setText("Неправильный ввод. Пожалуйста, прочитайте правила ввода аккордов и введите правильные аккорды.");
        chords.clear();
        return;
    }

    chords = transposer->sortChords(chords);
    ui->textEdit->clear();
    ui->textEdit->setPlainText(chords.join(" "));
    /*for (const QString &chord : sortedChords) {
        ui->textEdit->append(chord);
    }*/
}


void MainWindow::on_transposeButton_clicked()
{
    chords = ui->textEdit->toPlainText().split(QRegExp("\\s+"), QString::SkipEmptyParts);

    if (!transposer->validateChords(chords)) {
        ui->textEdit->setText("Неправильный ввод. Пожалуйста, прочитайте правила ввода аккордов и введите правильные аккорды.");
        chords.clear();
        return;
    }

    int transposeInterval = ui->tonesComboBox->currentData().toInt();
    QStringList transposedChords = transposer->transposeChords(chords, transposeInterval);
    ui->textEdit->clear();
    ui->textEdit->setPlainText(transposedChords.join(" "));
    /*for (const QString &chord : transposedChords) {
        ui->textEdit->append(chord);
    }*/
}


void MainWindow::on_guitarTypeComboBox_currentIndexChanged(int index)
{
    ui->tunerStackedWidget->setCurrentIndex(index);
    tuner->setGuitarType(static_cast<Tuner::GuitarType>(index));
}


void MainWindow::on_playButton_clicked()
{
    tuner->playFrequency(stringNumber);
}


void MainWindow::on_guitar6String1RadioButton_clicked()
{
    double frequency = tuner->getFrequency(1);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 1;
}


void MainWindow::on_guitar6String2RadioButton_clicked()
{
    double frequency = tuner->getFrequency(2);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 2;
}


void MainWindow::on_guitar6String3RadioButton_clicked()
{
    double frequency = tuner->getFrequency(3);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 3;
}


void MainWindow::on_guitar6String4RadioButton_clicked()
{
    double frequency = tuner->getFrequency(4);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 4;
}


void MainWindow::on_guitar6String5RadioButton_clicked()
{
    double frequency = tuner->getFrequency(5);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 5;
}


void MainWindow::on_guitar6String6RadioButton_clicked()
{
    double frequency = tuner->getFrequency(6);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 6;
}


void MainWindow::on_guitar7String1RadioButton_clicked()
{
    double frequency = tuner->getFrequency(1);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 1;
}


void MainWindow::on_guitar7String2RadioButton_clicked()
{
    double frequency = tuner->getFrequency(2);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 2;
}


void MainWindow::on_guitar7String3RadioButton_clicked()
{
    double frequency = tuner->getFrequency(3);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 3;
}


void MainWindow::on_guitar7String4RadioButton_clicked()
{
    double frequency = tuner->getFrequency(4);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 4;
}


void MainWindow::on_guitar7String5RadioButton_clicked()
{
    double frequency = tuner->getFrequency(5);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 5;
}


void MainWindow::on_guitar7String6RadioButton_clicked()
{
    double frequency = tuner->getFrequency(6);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 6;
}


void MainWindow::on_guitar7String7RadioButton_clicked()
{
    double frequency = tuner->getFrequency(7);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 7;
}


void MainWindow::on_ukuleleString1RadioButton_clicked()
{
    double frequency = tuner->getFrequency(1);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 1;
}


void MainWindow::on_ukuleleString2RadioButton_clicked()
{
    double frequency = tuner->getFrequency(2);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 2;
}


void MainWindow::on_ukuleleString3RadioButton_clicked()
{
    double frequency = tuner->getFrequency(3);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 3;
}


void MainWindow::on_ukuleleString4RadioButton_2_clicked()
{
    double frequency = tuner->getFrequency(4);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 4;
}


void MainWindow::on_bass4String1RadioButton_clicked()
{
    double frequency = tuner->getFrequency(1);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 1;
}


void MainWindow::on_bass4String2RadioButton_clicked()
{
    double frequency = tuner->getFrequency(2);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 2;
}


void MainWindow::on_bass4String3RadioButton_clicked()
{
    double frequency = tuner->getFrequency(3);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 3;
}


void MainWindow::on_bass4String4RadioButton_clicked()
{
    double frequency = tuner->getFrequency(4);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 4;
}


void MainWindow::on_bass5String1RadioButton_clicked()
{
    double frequency = tuner->getFrequency(1);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 1;
}


void MainWindow::on_bass5String2RadioButton_clicked()
{
    double frequency = tuner->getFrequency(2);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 2;
}


void MainWindow::on_bass5String3RadioButton_clicked()
{
    double frequency = tuner->getFrequency(3);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 3;
}


void MainWindow::on_bass5String4RadioButton_clicked()
{
    double frequency = tuner->getFrequency(4);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 4;
}


void MainWindow::on_bass5String5RadioButton_clicked()
{
    double frequency = tuner->getFrequency(5);
    ui->frequencyLabel->setText(QString::number(frequency, 'f', 2) + " Hz");
    stringNumber = 5;
}


void MainWindow::on_searchButton_clicked()
{
    chords = ui->textEdit->toPlainText().split(QRegExp("\\s+"), QString::SkipEmptyParts);

    QString chordToFind = ui->searchLineEdit->text();

    if (chordToFind.isEmpty()) {
        ui->searchResultLabel->setText("Пожалуйста, ведите аккорд для поиска.");
        return;
    }

    if (!transposer->validateChords(chords)) {
        ui->textEdit->setText("Неправильный ввод. Пожалуйста, прочитайте правила ввода аккордов и введите правильный аккорд.");
        return;
    }

    QStringList sortedChords = transposer->sortChords(chords);

    bool found = transposer->binarySearch(sortedChords, chordToFind);
    if (found) {
        ui->searchResultLabel->setText("Аккорд найден!");
    } else {
        ui->searchResultLabel->setText("Аккорд не найден.");
    }
}

