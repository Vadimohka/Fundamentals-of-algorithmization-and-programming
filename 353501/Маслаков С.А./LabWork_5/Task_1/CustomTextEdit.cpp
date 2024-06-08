#include "OutputTextEdit.h"

OutputTextEdit::OutputTextEdit(QWidget* parent) : QTextEdit(parent) {
    highlighter = new CharacterHighlighter(this->document());
    highlighter->setDocument(this->document());
}

void OutputTextEdit::setHighlightedIndexes(const QVector<bool>& indexes) {
    highlighter->setHighlightedIndexes(indexes);
    highlighter->rehighlight();
    this->update();
}

void OutputTextEdit::clearHighlighting(){
    highlighter->setHighlightedIndexes(QVector<bool>());
    highlighter->rehighlight();
    this->update();
}