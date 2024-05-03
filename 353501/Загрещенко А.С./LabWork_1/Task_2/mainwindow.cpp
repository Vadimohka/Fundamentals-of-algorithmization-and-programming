#include "mainwindow.h"

#include "ellipsefigure.h"
#include "trianglefigure.h"
#include "star5figure.h"
#include "rectanglefigure.h"
#include "rhombusfigure.h"
#include "star6figure.h"
#include "star8figure.h"
#include "polygon6figure.h"
#include "polygon8figure.h"

#include "mathfunction.h"

#include "QTimer"
#include "QSpacerItem"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    colors = {"black", "white", "red", "blue", "green", "lime", "yellow", "orange", "brown", "purple", "pink", "cyan"};
    figures_img = {"ellipse", "rect", "triangle", "rhombus", "polygon6", "polygon8", "star5", "star6", "star8"};

    is_left_button_pressed = false;
    is_ctrl_pressed = false;
    is_shift_pressed = false;

    is_drawing = false;

    selected_figure = nullptr;
    cord_offset = QPoint(0, 0);
    past_cord = QPoint(0, 0);

    scene = new Canva(this);
    scene->setSceneRect(0, 0, 1500, 800);

    view = new QGraphicsView(scene);
    view->setFixedSize(1500, 800);

    selected_color = QColor("black");


    QWidget *centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);
    this->setCentralWidget(centralWidget);

    action_buttons.resize(figures_img.size());
    for (int i = 0; i < action_buttons.size(); i++) {
        action_buttons[i] = new QPushButton(this);
        action_buttons[i]->setFixedSize(40, 40);
        action_buttons[i]->setCheckable(true);
        action_group.addButton(action_buttons[i]);
        layout->addWidget(action_buttons[i], 0, i);
        QIcon buttonIcon("../images/" + figures_img[i] + ".png");
        action_buttons[i]->setIcon(buttonIcon);
        action_buttons[i]->setIconSize(QSize(35, 35));
    }
    action_buttons[0]->setChecked(true);

    color_buttons.resize(colors.size());
    for (int i = 0; i < color_buttons.size(); i++) {
        color_buttons[i] = new QPushButton(this);
        color_buttons[i]->setFixedSize(40, 40);
        color_buttons[i]->setCheckable(true);
        color_group.addButton(color_buttons[i]);
        layout->addWidget(color_buttons[i], 0, action_buttons.size() + 2 + i);
        color_buttons[i]->setStyleSheet("background-color: " + colors[i].name() + ";");
    }
    action_buttons[0]->setChecked(true);

    QSpacerItem *spacer = new QSpacerItem(40, 10, QSizePolicy::Maximum);

    label_center = new QLabel;
    label_center->setText("Центр:");
    label_square = new QLabel;
    label_square->setText("Площадь:");
    label_perimetr = new QLabel;
    label_perimetr->setText("Периметр:");

    layout->addWidget(label_center, 1, 0, 1, 4);
    layout->addWidget(label_square, 2, 0, 1, 4);
    layout->addWidget(label_perimetr, 3, 0, 1, 4);
    layout->addItem(spacer, 0, action_buttons.size(), 1, 1);
    layout->addWidget(view, 4, 0, 1, action_buttons.size() + 2 + color_buttons.size());

    connect(scene, &Canva::signalMouseDoubleLeftClickEvent, this, &MainWindow::doubleClickLeftButton);
    connect(scene, &Canva::signalMousePressLeftButtonEvent, this, &MainWindow::setLeftButtonPress);
    connect(scene, &Canva::signalMouseReleaseLeftButtonEvent, this, &MainWindow::setLeftButtonUnPress);
    connect(scene, &Canva::signalMousePressRightButtonEvent, this, &MainWindow::setRightButtonPress);
    connect(scene, &Canva::signalMousePressRightButtonEvent, this, &MainWindow::setRightButtonUnPress);
    connect(scene, &Canva::signalMouseMoveEvent, this, &MainWindow::MouseMoveEvent);

}

MainWindow::~MainWindow() {
}

void MainWindow::doubleClickLeftButton(QGraphicsSceneMouseEvent *event) {
    QPointF scenePoint = event->scenePos();
    QGraphicsItem *clickedItem = view->scene()->itemAt(scenePoint, QTransform());

    if (clickedItem) {
        auto *item = dynamic_cast<AbstractFigure *>(clickedItem);
        if (item) {
            if (item != selected_figure) {
                if (selected_figure) {
                    selected_figure->setShowBorders(false);
                }
                selected_figure = item;
                for (auto &i: items) {
                    i->setShowCorrectPoints(false);
                    i->setZValue(0);

                }
                selected_figure->setShowBorders(true);

                for (int i = 0; i < items.size(); i++) {
                    items[i]->setShowCorrectPoints(false);
                    items[i]->setZValue(i);
                }


                selected_figure->setZValue(items.size());
                QPointF center = selected_figure->mapToScene(selected_figure->boundingRect().center());
                label_center->setText("Центр: " + QString::number(center.x()) + ", " + QString::number(center.y()));
                label_square->setText("Площадь: " + QString::number(selected_figure->getSquare()));
                label_perimetr->setText("Периметр: " + QString::number(selected_figure->getPerimetr()));
            }
        }
    } else {
        if (selected_figure) {
            selected_figure->setShowBorders(false);
        }
        selected_figure = nullptr;
    }
    scene->update();
}

void MainWindow::setLeftButtonPress(QGraphicsSceneMouseEvent *event) {
    if (selected_figure) {
        cord_offset.setX(selected_figure->x() - event->scenePos().x());
        cord_offset.setY(selected_figure->y() - event->scenePos().y());
        QPointF item_pos = selected_figure->mapFromScene(event->scenePos());
        past_cord.setX(item_pos.x());
        past_cord.setY(item_pos.y());

        QPointF center = selected_figure->boundingRect().center();
        QPointF centerSceneCord = selected_figure->mapToScene(center);

        double cx = centerSceneCord.x();
        double cy = centerSceneCord.y();
        double dx = cx - event->scenePos().x();
        double dy = cy - event->scenePos().y();
        start_angle = fmod(calculateAngle(dx, -dy) - selected_figure->rotation(), 360);

        is_left_button_pressed = true;
        setResizePoint(event);
    }
    else {

    }
    is_drawing = true;
    start_pos = event->scenePos();
}

void MainWindow::setLeftButtonUnPress(QGraphicsSceneMouseEvent *event) {
    is_left_button_pressed = false;

    is_left_bottom_resize = false;
    is_left_top_resize = false;
    is_right_bottom_resize = false;
    is_right_top_resize = false;

    if (!selected_figure) {
        QPointF scenePoint = event->scenePos();
        QGraphicsItem *clickedItem = view->scene()->itemAt(scenePoint, QTransform());


        QPointF point1 = event->scenePos();
        QPointF point2 = start_pos;

        QRectF size_rect(qMin(point1.x(), point2.x()), qMin(point1.y(), point2.y()),
                         qAbs(point1.x() - point2.x()), qAbs(point1.y() - point2.y()));


        if (size_rect.height()>10 && size_rect.width()>10) {

            items.append(nullptr);
            int number = items.size()-1;
            if (action_buttons[0]->isChecked()) {
                items[number] = new EllipseFigure;
            }
            else if (action_buttons[1]->isChecked()) {
                items[number] = new RectangleFigure;
            }
            else if (action_buttons[2]->isChecked()) {
                items[number] = new TriangleFigure;
            }
            else if (action_buttons[3]->isChecked()) {
                items[number] = new RhombusFigure;
            }
            else if (action_buttons[4]->isChecked()) {
                items[number] = new Polygon6Figure;
            }
            else if (action_buttons[5]->isChecked()) {
                items[number] = new Polygon8Figure;
            }
            else if (action_buttons[6]->isChecked()) {
                items[number] = new Star5Figure;
            }
            else if (action_buttons[7]->isChecked()) {
                items[number] = new Star6Figure;
            }
            else if (action_buttons[8]->isChecked()) {
                items[number] = new Star8Figure;
            }
            for (int i = 0; i < colors.size(); i++) {
                if (color_buttons[i]->isChecked()) {
                    selected_color = colors[i];
                }
            }

            items[number]->setFillColor(selected_color);
            items[number]->setPos(size_rect.x(), size_rect.y());
            items[number]->setSize(size_rect.width(), size_rect.height());
            items[number]->setZValue(number);
            items[number]->setRect(0,0,0,0);
            scene->addItem(items[items.size()-1]);
        }

    }
    is_drawing = false;
}

void MainWindow::setRightButtonPress(QGraphicsSceneMouseEvent *event)
{
    is_right_button_pressed;
    if (selected_figure) {
        selected_figure->setShowBorders(false);
    }
    selected_figure = nullptr;

}

void MainWindow::setRightButtonUnPress(QGraphicsSceneMouseEvent *event)
{
    is_right_button_pressed = false;
}

void MainWindow::MouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (is_ctrl_pressed && selected_figure) {

        QPointF center = selected_figure->boundingRect().center();
        QPointF centerSceneCord = selected_figure->mapToScene(center);

        double cx = centerSceneCord.x();
        double cy = centerSceneCord.y();
        double dx = cx - event->scenePos().x();
        double dy = cy - event->scenePos().y();

        selected_figure->setTransformOriginPoint(center);
        selected_figure->setRotation(calculateAngle(dx, -dy) - start_angle);


    } else if (is_shift_pressed && is_left_button_pressed && selected_figure) {

        QPointF mouse_pos = event->scenePos();
        QPointF item_pos = selected_figure->mapFromScene(mouse_pos);
        double dx = (item_pos.x() - past_cord.x());
        double dy = (item_pos.y() - past_cord.y());
        past_cord = item_pos;

        if (is_left_top_resize) {
            selected_figure->setRect(dx, dy, 0, 0);
        } else if (is_right_top_resize) {
            selected_figure->setRect(0, dy, dx, 0);
        } else if (is_right_bottom_resize) {
            selected_figure->setRect(0, 0, dx, dy);
        } else if (is_left_bottom_resize) {
            selected_figure->setRect(dx, 0, 0, dy);
        }

    } else if (is_left_button_pressed && selected_figure) {

        double dx = cord_offset.x();
        double dy = cord_offset.y();

        selected_figure->setPos(event->scenePos().x() + dx, event->scenePos().y() + dy);
    }
    if (selected_figure) {
        QPointF center = selected_figure->mapToScene(selected_figure->boundingRect().center());
        label_center->setText("Центр: " + QString::number(center.x()) + ", " + QString::number(center.y()));
        label_square->setText("Площадь: " + QString::number(selected_figure->getSquare()));
        label_perimetr->setText("Периметр: " + QString::number(selected_figure->getPerimetr()));
    }
    scene->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers() & Qt::ShiftModifier) {
        is_shift_pressed = true;
        if (selected_figure) {
            selected_figure->setShowCorrectPoints(true);
        }
    }
    if (event->modifiers() & Qt::ControlModifier) {
        is_ctrl_pressed = true;
        setCursor(Qt::OpenHandCursor);
    }
    if (event->key() == Qt::Key_Delete) {
        if (selected_figure) {
            for (int i = 0; i < items.size(); i++) {
                if (selected_figure == items[i]) {
                    scene->removeItem(items[i]);
                    items.erase(items.begin() + i);
                    selected_figure = nullptr;
                    break;
                }
            }
        }
    }
    if (event->key() == Qt::Key_Escape) {
        scene->clear();
        items.clear();
        scene->update();
        selected_figure = nullptr;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    is_ctrl_pressed = false;
    is_shift_pressed = false;

    for (auto &i: items) {
        i->setShowCorrectPoints(false);
    }
    setCursor(Qt::ArrowCursor);
}

void MainWindow::wheelEvent(QWheelEvent *event) {
    double delta = event->pixelDelta().y();
    if (is_shift_pressed) {
        if (delta > 0) {
            selected_figure->setRect(-10, -10, 0, 0);
        } else if (delta < 0) {
            selected_figure->setRect(10, 10, 0, 0);
        }
        QPointF center = selected_figure->mapToScene(selected_figure->boundingRect().center());
        label_center->setText("Центр: " + QString::number(center.x()) + ", " + QString::number(center.y()));
        label_square->setText("Площадь: " + QString::number(selected_figure->getSquare()));
        label_perimetr->setText("Периметр: " + QString::number(selected_figure->getPerimetr()));
        scene->update();
    }
}

void MainWindow::setResizePoint(QGraphicsSceneMouseEvent *event) {
    if (selected_figure) {
        QPointF mousePos = event->scenePos();
        QPointF itemPos = selected_figure->mapFromScene(mousePos);

        QRectF rect = selected_figure->boundingRect();
        QPointF topLeft = rect.topLeft();
        QPointF topRight = rect.topRight();
        QPointF bottomLeft = rect.bottomLeft();
        QPointF bottomRight = rect.bottomRight();

        qreal tolerance = 5.0;
        QRectF topLeftRect(topLeft.x() - tolerance, topLeft.y() - tolerance, 2 * tolerance, 2 * tolerance);
        QRectF topRightRect(topRight.x() - tolerance, topRight.y() - tolerance, 2 * tolerance, 2 * tolerance);
        QRectF bottomLeftRect(bottomLeft.x() - tolerance, bottomLeft.y() - tolerance, 2 * tolerance, 2 * tolerance);
        QRectF bottomRightRect(bottomRight.x() - tolerance, bottomRight.y() - tolerance, 2 * tolerance, 2 * tolerance);

        if (topLeftRect.contains(itemPos)) {
            is_left_top_resize = true;
        } else if (topRightRect.contains(itemPos)) {
            is_right_top_resize = true;
        } else if (bottomLeftRect.contains(itemPos)) {
            is_left_bottom_resize = true;
        } else if (bottomRightRect.contains(itemPos)) {
            is_right_bottom_resize = true;
        }
    }
}

void MainWindow::chooseColor(QColor color)
{
    selected_color = color;
}

