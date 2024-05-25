#include "mainwindow.h"
#include "lineedit.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <qapplication.h>
#include <qcolor.h>
#include <qcombobox.h>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qsize.h>
#include <qsizepolicy.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    targetText = texts[ui->comboBox->currentIndex()];
    words = targetText.split(" ");

    started = false;

    keyboard = new Keyboard;
    timer = new QTimer;
    keyboardScene = new QGraphicsScene;
    keyboardScene->addItem(keyboard);
    ui->keyboardView->setScene(keyboardScene);

    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->inputEdit->setFocus();

    connect(ui->inputEdit, &InputLineEdit::keyRegistered, this, &MainWindow::handleTextChange);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::changeLanguage);
    connect(ui->openFileButton, &QPushButton::pressed, this, &MainWindow::readFile);
}

void MainWindow::changeLanguage(/*int index*/) {
    targetText = texts[ui->comboBox->currentIndex()];
    words = targetText.split(" ");
    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->outputTextEdit->clearHighlighting();
    ui->inputEdit->setFocus();

    ui->cpm->setText("--");
    ui->wpm->setText("--");
    ui->accuracy->setText("--");

    QSize size = ui->outputTextEdit->document()->size().toSize();
    ui->outputTextEdit->setFixedHeight(size.height() + 3);
}

void MainWindow::handleTextChange(Qt::Key key, bool pressed) {
    QString currentText = ui->inputEdit->text();
    QStringList currentWords = currentText.split(" ");
    QVector<bool> indexes;

    if (currentText.size() > 0 && !started) {
        started = true;
        correctChars = 0;
        correctWords = 0;
        connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
        elapsedTimeInSeconds = 1;
        timer->start(1000);
    }

    bool isCorrect;
    correctChars = 0;
    for (int i = 0 ; i < currentText.size() && i < targetText.size(); i++) { //проверяем правильные и неправильные символы
        isCorrect = ( currentText[i] == targetText[i] );
        indexes.append(isCorrect);

        if (isCorrect)
            ++correctChars;
    }

    correctWords = 0;
    for (int i = 0; i < currentWords.size() && i < words.size(); i++) {
        if (currentWords[i] == words[i])
            ++correctWords;
    }

    QColor color;
    if (pressed)
        color = Qt::magenta;
    else
        color = Qt::white;

    keyboard->setKeyColor(key, color);
    ui->outputTextEdit->setHighlightedIndexes(indexes);

    if (currentText.size() == targetText.size()) {
        started = false;
        disconnect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
        double accuracy = ((double)correctChars / ui->inputEdit->text().size()) * 100;
        ui->accuracy->setText(QString::number(accuracy) + "%");
        ui->inputEdit->clear();
        timer->stop();

        elapsedTimeInSeconds = 0;
    }
}

void MainWindow::updateTime() {

    int targetSize = targetText.size();
    int inputSize = ui->inputEdit->text().size();

    double cpm = ((double)correctChars / elapsedTimeInSeconds) * 60;
    double wpm = ((double)correctWords / elapsedTimeInSeconds) * 60;
    double accuracy = ((double)correctChars / inputSize) * 100;

    ui->cpm->setText(QString::number(cpm));
    ui->wpm->setText(QString::number(wpm));
    ui->accuracy->setText(QString::number(accuracy) + "%");
    ui->timerLabel->setText(QString::number(elapsedTimeInSeconds) + "s");

    elapsedTimeInSeconds++;
}

void MainWindow::readFile() {
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt)");
    QFile file(filename);
    QString content;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        int lineCount = 0;
        while (!in.atEnd() && lineCount < 5) {
            QString line = in.readLine();
            content += line.trimmed() + " ";
            lineCount++;
        }
        file.close();
    }

    targetText = content;
    words = targetText.split(" ");
    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->outputTextEdit->clearHighlighting();
    ui->inputEdit->setFocus();

    ui->cpm->setText("--");
    ui->wpm->setText("--");
    ui->accuracy->setText("--");

    QSize size = ui->outputTextEdit->document()->size().toSize();
    ui->outputTextEdit->setFixedHeight(size.height() + 3);
}

