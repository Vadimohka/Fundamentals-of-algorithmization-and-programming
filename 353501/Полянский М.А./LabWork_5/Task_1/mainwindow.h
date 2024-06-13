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
    QVector<QVector<QString>> getGermanKeyboard();
    QVector<QVector<QString>> getFranchKeyboard();
    QVector<QVector<QString>> getArabicKeyboard();
    QVector<QVector<QString>> getEnglishKeyboard();
    QVector<QVector<QString>> getBelarussianKeyboard();
    QVector<QVector<QString>> getHerbewKeyboard();
    QVector<QVector<QString>> getChinaseKeyboard();

private slots:
    void readFile();
    void handleTextChange(Qt::Key key, bool pressed);
    void changeLanguage(int index);
    void updateTime();

protected:
    QString texts[6] { 
        "Enhance your typing skills with personalized keyboard training tailored", 
        "Verbessere deine Tippfertigkeiten mit individuellem Tastaturtraining", 
        "Améliorez vos compétences en dactylographie avec un entraînement", 
        "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوزظ", 
        "Палепшыце свае навыкі пісьма з дапамогай індывідуальнага навучання", 
        "提高您的打字技能" 
    };


    QString targetText;
    QStringList words; 

    int elapsedInSeconds = 1;
    bool started;

    int correctChars;
    int corWords;

    QTimer *timer;
    KeyBoard *keyboard;
    QGraphicsScene *keyboardScene;

    Ui::MainWindow *ui;
};
