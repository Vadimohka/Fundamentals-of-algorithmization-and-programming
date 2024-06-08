#pragma once
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include "OutputTextEdit.h"
#include "InputLineEdit.h"
#include "KeyObject.h"
#include "Keyboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

private slots:
    void readFile();
    void handleTextChange(Qt::Key key, bool pressed);
    void changeLanguage(int index);
    void updateTime();

protected:
    QString texts[6] {
        "The quick brown fox jumps over the lazy dog", // 0 - En
        "Ich möchte mit dir ein Spiel spielen", // 1 - De
        "Aujourd'hui je voulais manger un croissant", // 2 - Fr
        "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوزظ", // 3 - Ara
        "Лепей трошкі зрабіць, чым багата нагаварыць", // 4 - Be
        "一二三四五" // 5 -Cn
    };
    QString targetText;
    QStringList words;  //разбиение строки на слова

    int elapsedTimeInSeconds = 1;
    bool started;

    int correctChars;
    int correctWords;

    QTimer *timer;
    Keyboard *keyboard;
    QGraphicsScene *keyboardScene;

    Ui::MainWindow *ui;
};
