#include "Underline.h"

CharacterHighlighter::CharacterHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent) {}

void CharacterHighlighter::setHighlightedIndexes(const QVector<bool>& indexes) { highlightedIndexes = indexes; }

void CharacterHighlighter::highlightBlock(const QString& text) {
    QTextCharFormat correctForm, incorrectForm;
    incorrectForm.setBackground(Qt::red);
    incorrectForm.setForeground(Qt::white); 
    correctForm.setBackground(Qt::green);  
    correctForm.setForeground(Qt::black);
    
    for (int i = 0; i < highlightedIndexes.size(); i++) {
        if (highlightedIndexes[i] == true)
            setFormat(i, 1, correctForm);
        else
            setFormat(i, 1, incorrectForm);
    }
}