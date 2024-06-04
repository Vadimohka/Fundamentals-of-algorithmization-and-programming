#pragma once

#include <QLineEdit>
#include <QKeyEvent>
#include <qnamespace.h>

class InputLineEdit : public QLineEdit {
    Q_OBJECT
public:
    InputLineEdit(QWidget *parent = nullptr);

signals:
    void keyRegistered(Qt::Key key, bool pressed);

private:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};
