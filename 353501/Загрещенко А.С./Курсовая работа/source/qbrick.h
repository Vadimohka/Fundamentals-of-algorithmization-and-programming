#ifndef QBRICK_H
#define QBRICK_H

#include <QLabel>

class Brick;

class QBrick : public QLabel
{
    Q_OBJECT
public:
    QBrick(Brick* brick);
    QBrick(const QString &text);
    void draw();

signals:

public slots:

private:
    Brick *brick;

};

#endif // QBRICK_H
