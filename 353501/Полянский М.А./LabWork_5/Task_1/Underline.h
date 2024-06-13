#pragma once

#include <QLineEdit>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <qnamespace.h>
#include <qtextformat.h>

class CharacterHighlighter : public QSyntaxHighlighter {
public:
    CharacterHighlighter(QTextDocument* parent = nullptr);

    void setHighlightedIndexes(const QVector<bool>& indexes);

protected:
    void highlightBlock(const QString& text) override;

private:
    QVector<bool> highlightedIndexes;
};
