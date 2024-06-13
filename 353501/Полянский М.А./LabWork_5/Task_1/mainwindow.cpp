#include "mainwindow.h"
#include "InputLineEdit.h"
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
  
    keyboard = new KeyBoard;
    timer = new QTimer;
    keyboardScene = new QGraphicsScene;
    keyboardScene->addItem(keyboard);
    ui->keyboardView->setScene(keyboardScene);

    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->inputEdit->setFocus();

    connect(ui->inputEdit, &InputLineEdit::keyRegistered, this, &MainWindow::handleTextChange);
    connect(ui->comboBox, &QComboBox::activated, this, &MainWindow::changeLanguage);
    connect(ui->openFileButton, &QPushButton::pressed, this, &MainWindow::readFile);
}

void MainWindow::changeLanguage(int index) {
    targetText = texts[ui->comboBox->currentIndex()];
    words = targetText.split(" ");
    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->outputTextEdit->clearHighlighting();
    ui->inputEdit->setFocus();

    ui->cpm->setText(">--<");
    ui->wpm->setText(">--<");
    ui->accuracy->setText(">--<");

    QSize size = ui->outputTextEdit->document()->size().toSize();
    ui->outputTextEdit->setFixedHeight(size.height() + 3);
}

void MainWindow::handleTextChange(Qt::Key key, bool pressed) {
    QString currentText = ui->inputEdit->text();
    QStringList curw = currentText.split(" ");
    QVector<bool> indexes;

    qDebug() << "curw size:" << curw.size();
    qDebug() << "words size:" << words.size();

    if (currentText.size() > 0 && !started) {
        started = true;
        correctChars = 0;
        corWords = 0;
        connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
        elapsedInSeconds = 1;
        timer->start(1000);
    }

    bool isCorrect;
    correctChars = 0;
    for (int i = 0 ; i < currentText.size() && i < targetText.size(); i++) { 
        isCorrect = ( currentText[i] == targetText[i] );
        indexes.append(isCorrect);   

        if (isCorrect) 
            ++correctChars;
    }
    
    corWords = 0;
    for (int i = 0; i < curw.size() && i < words.size(); i++) { 
        if (curw[i] == words[i]) 
            ++corWords;
    }

    QColor color; 
    if (pressed)
        color = Qt::yellow;
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

        elapsedInSeconds = 0;
    }
}

void MainWindow::updateTime() {

    int targetSize = targetText.size();
    int inputSize = ui->inputEdit->text().size();

    double cpm = ((double)correctChars / elapsedInSeconds) * 60;
    double wpm = ((double)corWords / elapsedInSeconds) * 60;
    double accuracy = ((double)correctChars / inputSize) * 100;
    
    

    ui->cpm->setText(QString::number(cpm));
    ui->wpm->setText(QString::number(wpm));
    ui->accuracy->setText(QString::number(accuracy) + "%");
    ui->timerLabel->setText(QString::number(elapsedInSeconds) + "s");

    elapsedInSeconds++;
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
    } else {
        qDebug() << "Failed to open the file:" << filename;
    }

    targetText = content;
    words = targetText.split(" ");
    ui->outputTextEdit->setText(targetText);
    ui->outputTextEdit->setAlignment(Qt::AlignCenter);
    ui->outputTextEdit->clearHighlighting();
    ui->inputEdit->setFocus();

    ui->cpm->setText(">--<");
    ui->wpm->setText(">--<");
    ui->accuracy->setText(">--<");

    QSize size = ui->outputTextEdit->document()->size().toSize();
    ui->outputTextEdit->setFixedHeight(size.height() + 3);
}
QVector<QVector<QString>> MainWindow::getGermanKeyboard()
{
    QVector<QVector<QString>> germanKeyboard = {
        { "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "^", "shift", "#", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "shift", "space", "caps"},
        {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "°", "shift", "|", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+", "#", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "^", "shift", "#", "Y", "X", "C", "V", "B", "N", "M", ",", ".", "-", "shift", "space", "caps"},
        {"!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`", "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "*", "'", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "°", "shift", "|", "y", "x", "c", "v", "b", "n", "m", ";", ":", "_", "shift", "space", "caps"}};
    return germanKeyboard;
}

QVector<QVector<QString>> MainWindow::getFranchKeyboard()
{
    QVector<QVector<QString>> franchKeyboard = {
        {"&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "²", "shift", "*", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "~", "shift", "µ", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift", "space", "caps"},
        {"&&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=", "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "²", "shift", "*", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "¨", "£", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "%", "~", "shift", "", "w", "x", "c", "v", "b", "n", "?", ".", "/", "§", "shift", "space", "caps"}};
    return franchKeyboard;
}

QVector<QVector<QString>> MainWindow::getArabicKeyboard()
{
    QVector<QVector<QString>> arabicKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َّ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"}};
    return arabicKeyboard;
}

QVector<QVector<QString>> MainWindow::getEnglishKeyboard()
{
    QVector<QVector<QString>> englishKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`", "shift", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "{", "}", "a", "s", "d", "f", "g", "h", "j", "k", "l", ":", "\"", "~", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "<", ">", "?", "shift", "space", "caps"}};
    return englishKeyboard;
}

QVector<QVector<QString>> MainWindow::getBelarussianKeyboard()
{
    QVector<QVector<QString>> belarussianKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "\\", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ".", "shift", "space", "caps"},
        {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "/", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "\\", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
        {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "/", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ",", "shift", "space", "caps"}};
    return belarussianKeyboard;
}

QVector<QVector<QString>> MainWindow::getHerbewKeyboard()
{
    QVector<QVector<QString>> herbewKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "]", "[", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", ",", ";", "shift", "\\", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "}", "{", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", ">", "<", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "]", "[", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", ";", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ">", "<", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "}", "{", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", "\"", "~", "shift", "|", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", "?", "shift", "space", "caps"}};
    return herbewKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinaseKeyboard()
{
    QVector<QVector<QString>> chinaseKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "【", "】", "a", "s", "d", "f", "g", "h", "j", "k", "l", "；", "‘", "`", "shift", "、", "z", "x", "c", "v", "b", "n", "m", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "『", "』", "A", "S", "D", "F", "G", "H", "J", "K", "L", "：", "“", "～", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "《", "》", "？", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "【", "】", "A", "S", "D", "F", "G", "H", "J", "K", "L", "；", "’", "`", "shift", "、", "Z", "X", "C", "V", "B", "N", "M", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "『", "』", "a", "s", "d", "f", "g", "h", "j", "k", "l", "：", "”", "～", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "《", "》", "？", "shift", "space", "caps"}};
    return chinaseKeyboard;
}