//
// Created by acryoz on 5/9/24.
//

#ifndef LAB5_SRC_KEYBOARD_H_
#define LAB5_SRC_KEYBOARD_H_

#include <QDebug>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLocale>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "layouts.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class Keyboard;
}

QT_END_NAMESPACE

static const int BUTTON_SIZE = 50;

static const QString pressed_style = "background: #ababab;";
static const QString normal_style = "background:#F4F4F4;";

class Keyboard : public QWidget {
    Q_OBJECT

   public:
    explicit Keyboard(QWidget* parent = nullptr);
    ~Keyboard() override;
    void updateLayout();
   public slots:
    void setNewLayout(int);

   protected:
    void keyPressEvent(QKeyEvent* ev) override;
    void keyReleaseEvent(QKeyEvent* ev) override;

   private:
    int layout_index;
    void nextLayout();
    void shift();
    bool shifted = false;
    QVector<QString> current_layout;
    QVector<QPushButton*> buttons;
    QPushButton* backspace_button;
    QPushButton* space_button;
    QHBoxLayout* number_row;
    QHBoxLayout* first_row;
    QHBoxLayout* second_row;
    QHBoxLayout* third_row;
    QVBoxLayout* vbox;
    Ui::Keyboard* ui;

   signals:
    void pressed(QString);
};
#endif  //LAB5_SRC_KEYBOARD_H_
