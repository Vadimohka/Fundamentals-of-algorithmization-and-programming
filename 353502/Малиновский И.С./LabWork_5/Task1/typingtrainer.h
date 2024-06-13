// typingtrainer.h
#ifndef TYPINGTRAINER_H
#define TYPINGTRAINER_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QElapsedTimer>
#include <QRandomGenerator>

class TypingTrainer : public QWidget {
    Q_OBJECT

public:
    TypingTrainer(QWidget *parent = nullptr);

private slots:
    void startTraining();
    void checkInput();
    void updateStats();
    void toggleTraining();
    void changeDifficulty(int index);

private:
    void generateNewText();
    QString generateRandomText(int length);
    QString generateRandomWord(int length);
    void updateUI(bool training);

    QTextEdit *textEdit;
    QTextEdit *inputEdit;
    QLabel *statsLabel;
    QPushButton *startButton;
    QPushButton *toggleButton;
    QPushButton *easyButton;
    QPushButton *mediumButton;
    QPushButton *hardButton;

    QString targetText;
    QElapsedTimer timer;
    int errorCount;
    int difficulty;
};

#endif // TYPINGTRAINER_H
