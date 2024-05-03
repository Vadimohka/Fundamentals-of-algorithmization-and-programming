#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(0, 0, 10000, 10000);
    scene->setSceneRect(ui->graphicsView->rect());

    connect(scene, SIGNAL(signalMousePressEvent(QGraphicsSceneMouseEvent*)), SLOT(MousePressed(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalMouseMoveEvent(QGraphicsSceneMouseEvent*)), SLOT(MouseMoved(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalMouseReleaseEvent(QGraphicsSceneMouseEvent*)), SLOT(MouseReleased(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalWheelRotationEvent(QGraphicsSceneWheelEvent*)), SLOT(WheelTrigered(QGraphicsSceneWheelEvent*)));
    connect(scene, SIGNAL(signalKeyPressEvent(QKeyEvent*)), SLOT(KeyPressed(QKeyEvent*)));

    connect(ui->ShapeBox, SIGNAL(currentIndexChanged(int)), SLOT(FigureChanged()));

    ui->graphicsView->setScene(scene);

    selected_shape = CRectangle;    
}

Widget::~Widget()
{
    delete ui;
    delete scene;
}

void Widget::MousePressed(QGraphicsSceneMouseEvent *event)
{
    pt_pressed = event->scenePos();
    item = (Shape*) scene->itemAt(pt_pressed, {});

    // if (event->button() == Qt::LeftButton){
    //     if(!item){
    //         track_move = true;
    //         creation = true;
    //         CreateFigure(event);
    //     }
    //     else {
    //         track_move = true;
    //         item->setFlag(QGraphicsItem::ItemIsMovable);
    //         update();
    //         repaint();
    //     }
    // }
    if (event->button() == Qt::RightButton){
        track_move = true;
        creation = true;
        CreateFigure(event);
    }
    else{
        if(item){
            track_move = true;
            item->setFlag(QGraphicsItem::ItemIsMovable);
            update();
            repaint();
        }
    }
}

void Widget::MouseMoved(QGraphicsSceneMouseEvent *event)
{
    if(track_move){
        pt_move = event->scenePos();
        if(creation){
            current_item->SetEndPoint(event->scenePos());
            update();
        }
    }
    if(item){
        item->update();
    }
    UpdateInfo();
    update();
    repaint();
}

void Widget::MouseReleased(QGraphicsSceneMouseEvent *event)
{
    pt_released = event->scenePos();
    track_move = false;
    creation = false;
    scale = false;
    if(item){
        item->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}

void Widget::WheelTrigered(QGraphicsSceneWheelEvent *event)
{
    if(item){
        scale_on = 0;
        rotate_on = 0;

        if(QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier)){
            rotate_on = 0;
            if(event->delta() > 0){
                rotate_on += 7;
                item->SetRotate(rotate_on);
            }
            else{
                rotate_on -= 7;
                item->SetRotate(rotate_on);
            }
            item->setTransformOriginPoint(item->boundingRect().center());
            item->setRotation(item->GetRotation());
        }
        //Scale
        else{
            scale_on = 0;
            if(event->delta() > 0){
                scale_on += 0.1;
                item->SetScale(scale_on);
            }
            else{
                scale_on -= 0.1;
                item->SetScale(scale_on);
            }
            item->UpdateInfo_(item->GetScale());
            UpdateInfo();
            item->setTransformOriginPoint(item->boundingRect().center());
            item->setScale(item->GetScale());
        }
        update();
        repaint();
    }
}

void Widget::KeyPressed(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        scene->removeItem(item);
    }
}

void Widget::FigureChanged()
{
    switch (ui->ShapeBox->currentIndex())
    {
    case 0:
        selected_shape = CRectangle;
        break;
    case 1:
        selected_shape = CSquare;
        break;
    case 2:
        selected_shape = CRomb;
        break;
    case 3:
        selected_shape = CHexagon;
        break;
    case 4:
        selected_shape = CEllipse;
        break;
    case 5:
        selected_shape = CCircle;
        break;
    case 6:
        selected_shape = CTriangle;
        break;
    case 7:
        selected_shape = CStar_5;
        break;
    case 8:
        selected_shape = CStar_6;
        break;
    case 9:
        selected_shape = CStar_8;
        break;
    case 10:
        selected_shape = CDraw;
        break;

        default:
        break;
    }
}
void Widget::CreateFigure(QGraphicsSceneMouseEvent* event)
{
    switch (selected_shape){
    case CRectangle:{
        Rectangle* new_item = new Rectangle(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CSquare:{
        Square* new_item = new Square(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CRomb:{
        Romb* new_item = new Romb(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CHexagon:{
        Hexagon* new_item = new Hexagon(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CEllipse:{
        Ellipse* new_item = new Ellipse(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CCircle:{
        Circle* new_item = new Circle(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CTriangle:{
        Triangle* new_item = new Triangle(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CStar_5:{
        Star_5* new_item = new Star_5(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CStar_6:{
        Star_6* new_item = new Star_6(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CStar_8:{
        Star_8* new_item = new Star_8(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }
    case CDraw:{
        Draw* new_item = new Draw(event->scenePos());
        new_item->setPos(event->pos());
        current_item = new_item;
        break;
    }

    default: break;
    }

    item = current_item;
    item->update();

    scene->addItem(current_item);
}

void Widget::UpdateInfo()
{
    if(!item){
        ui->CentralLabel->clear();
        ui->PerimetrLabel->clear();
        ui->SquareLabel->clear();
    }
    else{
        QPointF pt = item->pos();
        ui->CentralLabel->setText(QString().setNum(pt.x()) + ", " +  QString().setNum(pt.y()));
        ui->PerimetrLabel->setNum(item->GetPerimetr());
        ui->SquareLabel->setNum(item->GetSquare());
    }
}
