//
// Created by volodya-petarda on 3/10/24.
//

#ifndef RISOVALKA_PAINTSCENE_H
#define RISOVALKA_PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class main_window;


class paintScene : public QGraphicsScene {
Q_OBJECT
public:
    void reset();

    explicit paintScene(QObject *parent = nullptr, main_window *par_w = nullptr);

    ~paintScene() override;

    void setParentWindow(main_window *window);

private:
    bool isSelected = false;
    qreal x1, x2, y1, y2;
    main_window *parentWindow;
    bool isLeftTimer = false, isRightTimer = false, isDownTimer = false, isUpTimer = false, isLeftRotateTimer = false, isRightRotateTimer = false;

private:
    QTimer *leftTimer, *rightTimer, *downTimer, *upTimer, *leftRotateTimer, *rightRotateTimer;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;
};


#endif //RISOVALKA_PAINTSCENE_H
