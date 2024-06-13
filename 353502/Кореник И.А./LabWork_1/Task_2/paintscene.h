#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QWidget>

class PaintScene : public QWidget
{
    Q_OBJECT
public:
    explicit PaintScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);
signals:
};

#endif // PAINTSCENE_H
