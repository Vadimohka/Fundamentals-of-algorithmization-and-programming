#include "OutputTextEdit.h"

OutpuEdit::OutpuEdit(QWidget* parent) : QTextEdit(parent) {
    highlighter = new CharacterHighlighter(this->document());
    highlighter->setDocument(this->document());
}

void OutpuEdit::setHighlightedIndexes(const QVector<bool>& indexes) {
    highlighter->setHighlightedIndexes(indexes);
    highlighter->rehighlight();
    this->update();
}

void OutpuEdit::clearHighlighting(){
    highlighter->setHighlightedIndexes(QVector<bool>());
    highlighter->rehighlight();
    this->update();
}