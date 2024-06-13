// typingtrainer.cpp
#include "typingtrainer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QCoreApplication>

TypingTrainer::TypingTrainer(QWidget *parent)
    : QWidget(parent), errorCount(0), difficulty(1)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);

    inputEdit = new QTextEdit(this);
    inputEdit->setMinimumSize(400, 50); // Установка минимального размера для inputEdit
    inputEdit->setVisible(true); // Устанавливаем видимость виджета

    connect(inputEdit, &QTextEdit::textChanged, this, &TypingTrainer::checkInput);
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    startButton = new QPushButton("Start", this);
    connect(startButton, &QPushButton::clicked, this, &TypingTrainer::startTraining); // Добавленный код
    toggleButton = new QPushButton("Pause", this);
    connect(toggleButton, &QPushButton::clicked, this, &TypingTrainer::toggleTraining);
    toggleButton->setEnabled(false);
    easyButton = new QPushButton("Easy", this);
    connect(easyButton, &QPushButton::clicked, [=](){ changeDifficulty(0); });
    mediumButton = new QPushButton("Medium", this);
    connect(mediumButton, &QPushButton::clicked, [=](){ changeDifficulty(1); });
    hardButton = new QPushButton("Hard", this);
    connect(hardButton, &QPushButton::clicked, [=](){ changeDifficulty(2); });

    buttonsLayout->addWidget(startButton);
    buttonsLayout->addWidget(toggleButton);
    buttonsLayout->addWidget(easyButton);
    buttonsLayout->addWidget(mediumButton);
    buttonsLayout->addWidget(hardButton);

    statsLabel = new QLabel("Time: 0s   Errors: 0", this);

    layout->addWidget(textEdit);
    layout->addWidget(inputEdit);
    layout->addLayout(buttonsLayout);
    layout->addWidget(statsLabel);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TypingTrainer::updateStats);
    timer->start(1000);
}



void TypingTrainer::startTraining() {
    toggleButton->setEnabled(true);
    startButton->setEnabled(false);
    generateNewText();
    inputEdit->clear();
    timer.start();
    errorCount = 0;
}

void TypingTrainer::toggleTraining() {
    if (toggleButton->text() == "Pause") {
        toggleButton->setText("Resume");
        timer.invalidate();
    } else {
        toggleButton->setText("Pause");
        timer.start();
    }
}

void TypingTrainer::checkInput() {
    //qDebug() << "OK";
    QString inputText = inputEdit->toPlainText();

    QStringList inputWords = inputText.split(" ", Qt::SkipEmptyParts);
    QStringList targetWords = targetText.split(" ", Qt::SkipEmptyParts);

    errorCount = 0;

    for (int i = 0; i < qMin(inputWords.size(), targetWords.size()); ++i) {
        if (inputWords[i] != targetWords[i]) {
            errorCount++;
        }
    }

    if (inputText == targetText) {
        QMessageBox::information(this, "Correct", "You typed the text correctly!");
        toggleButton->setEnabled(false);
        startButton->setEnabled(true);
    }

    updateStats(); // Обновление информации об ошибках
}



void TypingTrainer::updateStats() {
    int elapsedTime = timer.isValid() ? timer.elapsed() / 1000 : 0; // in seconds
    QString stats = QString("Time: %1s   Errors: %2").arg(elapsedTime).arg(errorCount);
    statsLabel->setText(stats);
}

void TypingTrainer::generateNewText() {
    int length;
    switch (difficulty) {
    case 0: // Easy
        length = 20;
        break;
    case 1: // Medium
        length = 40;
        break;
    case 2: // Hard
        length = 60;
        break;
    default:
        length = 40;
    }

    targetText = generateRandomText(length);
    textEdit->setText(targetText);
}

QString TypingTrainer::generateRandomText(int length) {
    QString text;
    const int wordCount = qCeil(length / 5.0);
    for (int i = 0; i < wordCount; ++i) {
        text.append(generateRandomWord(QRandomGenerator::global()->bounded(3, 10)));
        text.append(" ");
    }
    return text.trimmed();
}

QString TypingTrainer::generateRandomWord(int length) {
    const QString possibleCharacters = "abcdefghijklmnopqrstuvwxyz";
    QString word;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        word.append(nextChar);
    }
    return word;
}

void TypingTrainer::changeDifficulty(int index) {
    difficulty = index;
    updateUI(false); // reset UI
}

void TypingTrainer::updateUI(bool training) {
    toggleButton->setEnabled(training);
    startButton->setEnabled(!training);
    easyButton->setEnabled(!training);
    mediumButton->setEnabled(!training);
    hardButton->setEnabled(!training);
}

