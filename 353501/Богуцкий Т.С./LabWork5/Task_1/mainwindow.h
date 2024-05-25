#pragma once
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include "outputtext.h"
#include "lineedit.h"
#include "obbject.h"
#include "keyboard.h"

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
    void changeLanguage(/*int index*/);
    void updateTime();

protected:
    QString texts[6] {
        "Hello World!",
        "Ich möchte mit dir ein Spiel spielen",
        "azertyuiop", // eto french
        "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوزظ",
        "Лепей лабу здаць чым яе не здаць",
        "一二三四五"
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
