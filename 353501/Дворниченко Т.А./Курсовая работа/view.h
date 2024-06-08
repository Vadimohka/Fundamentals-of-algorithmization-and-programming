#ifndef VIEW_H
#define VIEW_H

#include "mainmenu.h"
#include <QLabel>
#include <QWidget>
#include <QPushButton>
class View : public QGraphicsView{
    Q_OBJECT
signals:
    void sceneChanged();

public:
    View();
    void sceneSet(QGraphicsScene *);
    QMediaPlaylist *bgm;



QPushButton *submit;
QLabel *uLabel;

private slots:


};

#endif // VIEW_H
