#pragma once

#include <QTextEdit>
#include <qcontainerfwd.h>
#include "Underline.h"

class OutpuEdit : public QTextEdit {
public:
    OutpuEdit(QWidget* parent = nullptr);

    void setHighlightedIndexes(const QVector<bool>& indexes);
    void clearHighlighting();

private:
    CharacterHighlighter* highlighter;
};