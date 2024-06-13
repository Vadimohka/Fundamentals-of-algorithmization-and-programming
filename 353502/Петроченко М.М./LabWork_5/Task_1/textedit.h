//
// Created by acryoz on 5/12/24.
//

#ifndef LAB5_SRC_TEXTEDIT_H_
#define LAB5_SRC_TEXTEDIT_H_

#include <QTextBlock>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextEdit>

QT_BEGIN_NAMESPACE

namespace Ui {
class TextEdit;
}

QT_END_NAMESPACE

static const int FONT_SiZE = 20;
static QTextCharFormat wrong_format;
static QTextCharFormat right_format;

class TextEdit : public QTextEdit {
    Q_OBJECT

   public:
    explicit TextEdit(QWidget* parent = nullptr);
    ~TextEdit() override;
    void setText(QString);
    void reprint();
    void terminate();
   public slots:
    void text_inputed(QString);
   signals:
    void ended(int);
    void mistake(double);

   private:
    int current_char;
    QString text;
    int words = 0;
    int mistakes = 0;
    QString mask;
    QTextCursor cursor;
    Ui::TextEdit* ui;
};


#endif  //LAB5_SRC_TEXTEDIT_H_
