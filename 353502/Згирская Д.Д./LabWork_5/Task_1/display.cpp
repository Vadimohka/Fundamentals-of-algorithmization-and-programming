#include "display.h"
#include "QDebug"
#include "ui_display.h"


Display::Display(QWidget *parent) :
        QWidget(parent), ui(new Ui::Display) {
    ui->setupUi(this);

    ui->textEdit->setFocusPolicy(Qt::NoFocus);

    language = 0;
    first = false;
    counter = 0;
    counterRight = 0;

    for (int i = 0; i < Text[language].size(); ++i) {
        symbolColour.push_back(QColor(Qt::gray));
    }
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;

    for (int i = 0; i < Text[language].size(); ++i) {
        format.setForeground(symbolColour[i]);
        format.setFontPointSize(23);
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(QString(Text[language][i]), format);
    }

    timer = new QTimer(this);
    timer->start(1000);
}

Display::~Display() {
    delete ui;
}

void Display::getKey(QString key) {
    if (!first){
        first = true;
        time.start();
        connect(timer, SIGNAL(timeout()), this, SLOT(timerEmiter()));
    }

    if (counter < Text[language].size()){
        qDebug() << key;
        if (Text[language][counter] != key) {
            symbolColour[counter] = QColor(Qt::red);
        } else {
            symbolColour[counter] = QColor(Qt::green);
            counterRight++;
        }
        ++counter;
        emit percent(static_cast<double>(counterRight) * 100 / counter);

        QTextCursor cursor = ui->textEdit->textCursor();
        QTextCharFormat format;
        ui->textEdit->clear();
        for (int i = 0; i < Text[language].size(); ++i) {
            format.setForeground(symbolColour[i]);
            format.setFontPointSize(23);
            cursor.movePosition(QTextCursor::End);
            cursor.insertText(QString(Text[language][i]), format);
        }
        if (counter == Text[language].size()) {
            ui->textEdit->clear();
            format.setForeground(Qt::blue);
            format.setFontPointSize(32);
            cursor.insertText(QString("Congratulations!!! Chose another language to continue."), format);
            disconnect(timer, SIGNAL(timeout()), this, SLOT(timerEmiter()));
            time.elapsed();
        }
    }
}

void Display::updateSelf(int index) {
    language = index;

    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;

    symbolColour.clear();
    for (int i = 0; i < Text[language].size(); ++i) {
        symbolColour.push_back(QColor(Qt::gray));
    }

    ui->textEdit->clear();
    for (int i = 0; i < Text[language].size(); ++i) {
        format.setForeground(symbolColour[i]);
        format.setFontPointSize(23);
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(QString(Text[language][i]), format);
    }
    first = false;
    counter = 0;
    counterRight = 0;
}

void Display::timerEmiter() {
    emit symbolsAndTime(counterRight,time);
}
