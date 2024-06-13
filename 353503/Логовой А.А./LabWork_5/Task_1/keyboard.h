#ifndef KEYBOARD_H
#define KEYBOARD_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QPainter>
#include<QKeyEvent>
#include<QMap>
#include<QLineEdit>
#include<QTextEdit>
#include<langauges.h>
#include<QRegularExpression>
#include<QColor>

class KeyBoard:public QWidget
{
    Q_OBJECT

private:

    int symbols = 0;

    QString language = "";
    QString  up_language ="";

    QLineEdit* line_edit;
    QTextEdit* text_edit;
    QTextEdit* text_line;

    QMap<QString, QRect> constKey;
    QMap<QString, QRect> keyMap;
    QMap<QString, bool> keyPressed;
    QMap<QString, bool> constKeyPressed;

    QString text;
    QString input;

public:

    void setText(QString text);

    void setLanguage(QString str, QString up_str);

    explicit KeyBoard(QWidget *parent = nullptr) : QWidget(parent){
        setFocusPolicy(Qt::StrongFocus);
    }

    void setLineEdit(QTextEdit* edit);

    void paintEvent(QPaintEvent* event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void handleBackspaceKey();

    void handleCharacterInput(const QString& key);

    void updateTextDisplay();

    void reloadtext();

signals:

    void realoadStatistic();

    void firstKeyPress();

    void characterTyped(bool isCorrect);

    void finalText();
};
#endif // KEYBOARD_H
