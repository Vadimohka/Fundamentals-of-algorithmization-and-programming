#ifndef TRAINER_H
#define TRAINER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTextCharFormat>
#include <QPushButton>
#include <QTimer>

#include "wordgenerator.h"
#include "statsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Trainer;
}
QT_END_NAMESPACE

class Trainer : public QMainWindow
{
    Q_OBJECT

public:
    Trainer(QWidget *parent = nullptr);
    ~Trainer();

    void updateButtonLanguage(int LangIndex);
    void updateTrainingText(int LangIndex);

    void initButtons();

    void startTraining();
    void stopTraining();

    void backspaceClicked();

    void showStats();

    void colorizeButton(QString letter);

    // void keyPressEvent(QKeyEvent *event) override;

public slots:
    void updateLanguage(int LangIndex);
    void updateTimer();
    void changeTime(int TimeIndex);
    void changeLetterColor(QString letter);

private:
    Ui::Trainer *ui;
    StatsDialog *stats;
    WordGenerator *wordGenerator;

    bool isRunning = false;
    int charIndex;
    int errors;
    int time{15};
    int sizeInputStr;

    QTextCharFormat red;
    QTextCharFormat green;
    QTextCharFormat grey;

    QVector<QPushButton*> buttons;

    QTimer *timer;
};
#endif // TRAINER_H
