#ifndef CONSOLEEDIT_H
#define CONSOLEEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTextBlock>

class ConsoleEdit : public QTextEdit
{
    Q_OBJECT

public:
    ConsoleEdit();
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void print(QString string);
    void print(std::string string);
    void print(const char *string);
    void print(wchar_t ch);

    QString input(QEventLoop &loop);


    QString getCurrentString();

private:
    QString currentString;
    bool isInput;

signals:
    void inputFinished();
};

#endif // CONSOLEEDIT_H
