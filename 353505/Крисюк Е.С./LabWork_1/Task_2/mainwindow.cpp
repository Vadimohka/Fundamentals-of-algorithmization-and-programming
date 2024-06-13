#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();


    ui -> graphicsView -> setScene(scene);

    ui -> graphicsView -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui -> graphicsView -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    all_shapes = new All_shapes();

//    ui -> graphicsView -> setInteractive(true);
//    ui -> graphicsView -> setDragMode(QGraphicsView::ScrollHandDrag);
//    ui -> graphicsView -> setRenderHint(QPainter::Antialiasing);

//    ui -> graphicsView -> setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//    ui -> graphicsView -> setResizeAnchor(QGraphicsView::AnchorUnderMouse);
//    ui -> graphicsView -> scale(1.0, 1.0);  // Начальный масштаб (1.0 = 100%)

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent* event)
{
    painter = new QPainter(this);
    painter -> end();
}

void MainWindow::wheelEvent(QWheelEvent* event) {


}

void MainWindow::on_Rect_button_clicked()
{
    rect_1 = new Rect(10,10,100,40,nullptr);
    rect_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    rect_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    rect_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    rect_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(rect_1);
    ui -> line_of_X -> setText(QString::number(rect_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(rect_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number((rect_1 -> width) * (rect_1 -> height)));
    ui -> line_of_perimetr -> setText(QString::number(2 * (rect_1 -> width + rect_1 -> height)));


    ui -> Rotate_Right_button -> setEnabled(true);

    All_shapes::item = All_shapes::Item::RECT;

}
void MainWindow::on_Square_button_clicked()
{
    square_1 = new Square(10,10,50, nullptr);
    square_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    square_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    square_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    square_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(square_1);
    ui -> line_of_X -> setText(QString::number(square_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(square_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number(abs(square_1 -> height) * (square_1 -> height)));
    ui -> line_of_perimetr -> setText(QString::number(abs(4 * (square_1 -> height))));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::Item::SQUARE;
}

void MainWindow::on_Triangle_button_clicked()
{
    triangle_1 = new Triangle(10,10,150, nullptr);

    triangle_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    triangle_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    triangle_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    triangle_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(triangle_1);
    ui -> line_of_X -> setText(QString::number(triangle_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(triangle_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number( triangle_1 -> width * triangle_1 -> width * sqrt(3) / 4 ));
    ui -> line_of_perimetr -> setText(QString::number(3 * triangle_1 -> width));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::TRIANGLE;;

}

void MainWindow::on_Star_5_clicked()
{
    star_5_1 = new Star_5(30,30,110, nullptr);

    star_5_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    star_5_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    star_5_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    star_5_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(star_5_1);

    ui -> line_of_X -> setText(QString::number(star_5_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(star_5_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number((abs(star_5_1 -> radius * star_5_1 -> radius - (star_5_1 -> width) * (star_5_1 -> width) * 3.14 * 6))));
    ui -> line_of_perimetr -> setText(QString::number(abs(2 * (star_5_1 -> width) * 5)));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::STAR_5;
}


void MainWindow::on_Circle_clicked()
{
    circle_1 = new Circle(10,10,50,nullptr);

    circle_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    circle_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    circle_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    circle_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(circle_1);

    ui -> line_of_X -> setText(QString::number(circle_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(circle_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number( abs(3.14 * (circle_1 -> diametr) * (circle_1 -> diametr) / 4)));
    ui -> line_of_perimetr -> setText(QString::number(abs(3.14 * circle_1 -> diametr)));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::CIRCLE;
}
void MainWindow::on_Star_6_clicked()
{
    star_6_1 = new Star_6(30,30,110,nullptr);

    star_6_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    star_6_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    star_6_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    star_6_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(star_6_1);

    ui -> line_of_X -> setText(QString::number(star_6_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(star_6_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number( abs( star_6_1 -> radius * star_6_1 -> radius - (star_6_1 -> width) * (star_6_1 -> width) * 3.14 * 5)));
    ui -> line_of_perimetr -> setText(QString::number(abs(2 * (star_6_1 -> width ) * 6)));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::STAR_6;
}

void MainWindow::on_Star_8_clicked()
{
    star_8_1 = new Star_8(30,30,110,nullptr);
    scene -> addItem(star_8_1);

    ui -> Rotate_Right_button -> setEnabled(true);
    all_shapes -> item = All_shapes::STAR_8;
}
void MainWindow::on_Rhomb_clicked()
{
    rhomb_1 = new Rhomb(130,30,100,40,nullptr);

    rhomb_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    rhomb_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    rhomb_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    rhomb_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(rhomb_1);

    ui -> line_of_X -> setText(QString::number(rhomb_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(rhomb_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number( abs(rhomb_1 -> width ) * (rhomb_1 -> width)));
    ui -> line_of_perimetr -> setText(QString::number(abs(4 * rhomb_1 -> width)));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::RHOMB;

}
void MainWindow::on_Hexagon_clicked()
{
    hexagon_1 = new Hexagon(130,30,110, nullptr);

    hexagon_1 -> line_of_X = findChild<QLineEdit*>("line_of_X");
    hexagon_1 -> line_of_Y = findChild<QLineEdit*>("line_of_Y");
    hexagon_1 -> line_of_Square = findChild<QLineEdit*>("line_of_square");
    hexagon_1 -> line_of_Perimetr = findChild<QLineEdit*>("line_of_perimetr");

    scene -> addItem(hexagon_1);

    ui -> line_of_X -> setText(QString::number(hexagon_1 -> Centre_of_mass.x()));
    ui -> line_of_Y -> setText(QString::number(hexagon_1 -> Centre_of_mass.y()));

    ui -> line_of_square -> setText(QString::number( abs(3.14 * (circle_1 -> diametr) * (circle_1 -> diametr) / 4)));
    ui -> line_of_perimetr -> setText(QString::number(abs(3.14 * circle_1 -> diametr)));

    ui -> Rotate_Right_button -> setEnabled(true);
    All_shapes::item = All_shapes::Item(HEXAGON);
}
void MainWindow::on_Rotate_Right_button_pressed()
{
    QTimer* timer = new QTimer();

    static qreal angle = 0;


    timer -> setInterval(15);
    qDebug() << All_shapes::item;

    if(All_shapes::item == All_shapes::Item(RECT)){
        rect_1 -> setTransformOriginPoint(rect_1 -> Centre_of_mass);
    }
    else if(All_shapes::item  == All_shapes::Item(SQUARE)){
        square_1 -> setTransformOriginPoint(square_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::TRIANGLE){
        triangle_1 -> setTransformOriginPoint(triangle_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::CIRCLE){
        circle_1 -> setTransformOriginPoint(circle_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::STAR_5){
        star_5_1 -> setTransformOriginPoint(star_5_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::STAR_6){
        star_6_1 -> setTransformOriginPoint(star_6_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::STAR_8){
        star_8_1 -> setTransformOriginPoint(star_8_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::Item(HEXAGON)){
        hexagon_1 -> setTransformOriginPoint(hexagon_1 -> Centre_of_mass);
    }
    else if(All_shapes::item == All_shapes::RHOMB){
        rhomb_1 -> setTransformOriginPoint(rhomb_1 -> Centre_of_mass);
    }
    else {
        qDebug() << "NONE";
    }

    connect(timer, &QTimer::timeout, this, [=] ()  mutable {

        if(ui -> Rotate_Right_button -> isDown() ) {
            ++angle;
            if(All_shapes::item == All_shapes::Item::RECT){
                rect_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::Item::SQUARE){
                square_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::TRIANGLE){
                triangle_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::CIRCLE){
                circle_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::STAR_5){
                star_5_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::STAR_6){
                star_6_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::STAR_8){
                star_8_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::HEXAGON){
                hexagon_1 -> setRotation(angle);
            }
            else if(All_shapes::item == All_shapes::RHOMB){
                rhomb_1 -> setTransformOriginPoint(rhomb_1 -> Centre_of_mass);
            }
        }
        else {
            timer -> stop();
        }
    });
    timer -> start();


}

void MainWindow::on_line_of_X_inputRejected()
{
    ui -> line_of_X -> setText("Неверные данные");
}


void MainWindow::on_line_of_X_editingFinished()
{
    rect_1 -> Centre_of_mass.setX( ui -> line_of_X -> text().toDouble());
    rect_1 -> Left_up_point.setX(rect_1 -> Centre_of_mass.x() - rect_1 -> width / 2);
    rect_1 -> QGraphicsRectItem::setRect(rect_1 -> Left_up_point.x() , rect_1 -> Left_up_point.y(),  rect_1 -> width, rect_1 -> height);
}


void MainWindow::on_line_of_Y_editingFinished()
{
    rect_1 -> Centre_of_mass.setY(ui -> line_of_Y -> text().toDouble());
    rect_1 -> Left_up_point.setY(rect_1 -> Centre_of_mass.y() - rect_1 -> height / 2 );
    rect_1 -> QGraphicsRectItem::setRect(rect_1 -> Left_up_point.x() , rect_1 -> Left_up_point.y(),  rect_1 -> width, rect_1 -> height);
}


void MainWindow::on_Scene_clear_clicked()
{
    scene -> clear();

    ui -> line_of_X -> setText("");
    ui -> line_of_Y -> setText("");
    ui -> line_of_perimetr -> setText("");
    ui -> line_of_square -> setText("");

    ui -> Rotate_Right_button -> setEnabled(false);

}


void MainWindow::on_Draw_toggled(bool checked)
{

    draw_1 = new Draw(current_event.x(), current_event.y() , nullptr);
    if(checked){
        qDebug() << "123";
        scene -> addItem(draw_1);

    }
}
void MainWindow::mousePressEvent(QMouseEvent* event) {
    current_event.setX((event -> scenePosition()).x());
    current_event.setY((event -> scenePosition()).y());
    qDebug() << current_event;
}


void MainWindow::on_Scale_up_pressed()
{

    QVector<QGraphicsItem*> items = scene -> items();

    QTimer* timer = new QTimer();
    timer -> setInterval(100);
    qreal Scale_Factor = 1.0;

    connect(timer, &QTimer::timeout, this, [=] () mutable {


        if(QApplication::mouseButtons() != Qt::LeftButton || Scale_Factor >= 1.17) {
            timer -> stop();
            ui -> Scale_up -> setEnabled(false);

        }

        Scale_Factor += 0.008;

        qDebug() << Scale_Factor;

        foreach (QGraphicsItem* item, items) {
            item->setScale(item->scale() * Scale_Factor);
        }

        ui -> graphicsView->update();
    });
    timer -> start();


}


void MainWindow::on_Scale_down_pressed()
{
    QVector<QGraphicsItem*> items = scene -> items();

    QTimer* timer = new QTimer();
    timer -> setInterval(100);
    qreal Scale_Factor = 1.0;

    connect(timer, &QTimer::timeout, this, [=] () mutable {


        if(QApplication::mouseButtons() != Qt::LeftButton || Scale_Factor > 0.8) {
            timer -> stop();
            ui -> Scale_up -> setEnabled(false);

        }

        Scale_Factor -= 0.008;

        qDebug() << Scale_Factor;

        foreach (QGraphicsItem* item, items) {
            item->setScale(item->scale() * Scale_Factor);
        }

        ui -> graphicsView->update();
    });
    timer -> start();
}

