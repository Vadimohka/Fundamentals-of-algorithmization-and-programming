#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

#include <QStringList>

enum Languages {
    BELARUSIAN = 0,
    RUSSIAN,
    ENGLISH,
    GERMAN,
    FRENCH,
    CHINESE,
    ARABIC,
    HEBREW
};

class WordGenerator
{
public:
    explicit WordGenerator();

    void initWords();

    QStringList shuffleWords(int LangIndex);

    QStringList belWords;
    QStringList rusWords;
    QStringList engWords;
    QStringList gerWords;
    QStringList fraWords;
    QStringList araWords;
    QStringList chiWords;
    QStringList hebWords;
};

#endif // WORDGENERATOR_H
