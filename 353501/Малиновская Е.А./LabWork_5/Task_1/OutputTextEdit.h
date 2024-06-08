#pragma once

#include <QTextEdit>
#include <qcontainerfwd.h>
#include "Highlighter.h"

class OutputTextEdit : public QTextEdit {
public:
    OutputTextEdit(QWidget* parent = nullptr);

    void setHighlightedIndexes(const QVector<bool>& indexes);
    void clearHighlighting();

private:
    CharacterHighlighter* highlighter;
};
