#include "Highlighter.h"

CharacterHighlighter::CharacterHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent) {}

void CharacterHighlighter::setHighlightedIndexes(const QVector<bool>& indexes) { highlightedIndexes = indexes; }

void CharacterHighlighter::highlightBlock(const QString& text) {
    QTextCharFormat formatCorrect, formatIncorrect;
    formatIncorrect.setBackground(Qt::red);
    formatIncorrect.setForeground(Qt::white); 
    formatCorrect.setBackground(Qt::green);  
    formatCorrect.setForeground(Qt::black);
    
    for (int i = 0; i < highlightedIndexes.size(); i++) {
        if (highlightedIndexes[i] == true)
            setFormat(i, 1, formatCorrect);
        else
            setFormat(i, 1, formatIncorrect);
    }
}