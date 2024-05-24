//
// Created by acryoz on 5/2/24.
//

#ifndef COURSEWORK_LIB_TEXTBOARD_H_
#define COURSEWORK_LIB_TEXTBOARD_H_

#include <QPlainTextEdit>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {
class TextBoard;
}

QT_END_NAMESPACE

static int MAX_BOARD_WIDTH = 340;
static int MAX_BOARD_HEIGHT = 230;

class TextBoard : public QTextEdit {
    Q_OBJECT

   public:
    explicit TextBoard(QWidget* parent = nullptr);
    ~TextBoard() override;

   private:
    void wheelEvent(QWheelEvent* e) override;
    void dragMoveEvent(QDragMoveEvent* e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void keyPressEvent(QKeyEvent* e) override;


    Ui::TextBoard* ui;
};


#endif  //COURSEWORK_LIB_TEXTBOARD_H_
