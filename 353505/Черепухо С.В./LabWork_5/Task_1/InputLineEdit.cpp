#include "InputLineEdit.h"
#include <qevent.h>
#include <qline.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QTimer>


InputLineEdit::InputLineEdit(QWidget *parent) 
    : QLineEdit(parent) {}

void InputLineEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace) {
        emit backspace();
        return;
    }

    emit keyRegistered((Qt::Key)event->key(), true);
    QLineEdit::keyPressEvent(event);
}

void InputLineEdit::keyReleaseEvent(QKeyEvent *event) {
    emit keyRegistered((Qt::Key)event->key(), false);
    QLineEdit::keyReleaseEvent(event);
}
