#include"typingstatistic.h"
#include<QTimer>

TypingStatistic::TypingStatistic(QLabel* currency, QLabel* currency_words, QLabel* times, QLabel* correct_chars, QWidget *parent)
    : QWidget{parent}, currency{currency}, currency_words{currency_words}, times{times}, correct_chars{correct_chars} , timer_(new QTimer(this))
{
    connect(timer_, &QTimer::timeout, this, &TypingStatistic::startTimer);
    start = true;
    timer = new QElapsedTimer();
    timer->start();
}

void TypingStatistic::realoadStatistics()
{
    timer_->start();
    correct_char = 0;
    chars = 0;
    incorrect_char = 0;
}

void TypingStatistic::correctChar()
{
    qint64 elapsedMs = timer->elapsed();
    int seconds = (elapsedMs / ONE_THOUSAND) % SECONDS;
    int minutes = (elapsedMs / (ONE_THOUSAND * SECONDS)) % SECONDS;
     double  per_min = (chars*SECONDS)/(minutes*SECONDS + seconds + 1);
    correct_chars->clear();
    correct_chars->setText(QString::number(per_min));
}

void TypingStatistic::startTimer()
{
    if(start)
    {
        timer_->start();
        timer->start();
        start = false;
    }
    times->clear();

    wordsPerMinute();
    correctChar();

    qint64 elapsedMs = timer->elapsed();
    int seconds = (elapsedMs / ONE_THOUSAND) % SECONDS;
    int minutes = (elapsedMs / (ONE_THOUSAND * SECONDS)) % SECONDS;

    QString timeText = QString("%1:%2").arg(minutes, 2, TEN, QChar('0')).arg(seconds, 2, TEN, QChar('0'));
    times->setText(timeText);

}

void TypingStatistic::wordsPerMinute()
{
    int words = chars/AVEARGE_LENGHT_WORD;
    qint64 elapsedMs = timer->elapsed();
    int seconds = (elapsedMs / ONE_THOUSAND) % SECONDS;
    int minutes = (elapsedMs / (ONE_THOUSAND * SECONDS)) % SECONDS;
    double  per_min = (words*SECONDS)/(minutes*SECONDS + seconds + 1);
    currency_words->clear();
    currency_words->setText(QString::number(per_min));
}

void TypingStatistic::updateStatistics(bool isCorrect)
{
    if (isCorrect)
    {
        correct_char++;
    }
    else
    {
        incorrect_char++;
    }

    chars++;

    double currency1 = (correct_char * ONE_HUNDRED)/chars;

    currency->clear();
    currency->setText(QString::number(currency1)  + "%");

}
