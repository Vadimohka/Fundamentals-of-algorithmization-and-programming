#ifndef TYPINGSTATISTIC_H
#define TYPINGSTATISTIC_H

#include<QObject>
#include<QWidget>
#include<QTime>
#include<QLabel>
#include<QElapsedTimer>
#include<magicnumbers.h>

class TypingStatistic : public QWidget
{
    Q_OBJECT
public:

    explicit TypingStatistic(QLabel* currency, QLabel* currency_words, QLabel* times, QLabel* correct_chars, QWidget *parent = nullptr);

private:
    QTimer* timer_;
    QLabel* currency;
    QLabel* currency_words;
    QLabel* times;
    QLabel* correct_chars;

    QElapsedTimer* timer;
    int correct_words{};
    int correct_char{};
    int incorrect_char{};
    int chars {};

    bool start;

public slots:

    void realoadStatistics();

    void correctChar();

    void startTimer();

    void wordsPerMinute();

    void updateStatistics(bool isCorrect);
};

#endif  //TYPINGSTATISTIC_H
