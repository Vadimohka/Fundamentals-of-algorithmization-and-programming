#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QMessageBox>
#include"circle.h"
#include "triangle.h"
#include"rectangle.h"
#include"square.h"
#include"hexagon.h"
#include"rhombus.h"
#include"star.h"
#include <QMouseEvent>
#include <QGraphicsLineItem>
#include <QPen>
#include<QHBoxLayout>
#include <QKeyEvent>
#include"custom.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QColor("#FFFFFF"));

    ui->graphicsView->setScene(scene);

    //--------------------------------------------------------------------------------
    //дизайн
    this->setStyleSheet("QMainWindow {"
                        "    background-color: #218c74;"
                        "    color: white;"
                        "}");
    ui->listWidget->setStyleSheet("QListWidget{"
                                  "    background-color: #D9B29C;"
                                  "    color: white;"
                                  "    border-radius: 10px;"
                                  "}");
    //добавление стилей к кнопкам
    ui->Figures->setStyleSheet("QPushButton{"
                               "    background-color: #012845;"
                               "    color: white;"
                               "    border-radius: 10px;"
                               "    font-size: 25px;"
                               "}");
    ui->Clear->setStyleSheet("QPushButton{"
                             "    background-color: #2F5663;"
                             "    color: white;"
                             "    border-radius: 10px;"
                             "    font-size: 25px;"
                             "}");
    ui->center->setStyleSheet("QPushButton{"
                              "    background-color: #8C5F45;"
                              "    color: white;"
                              "    border-radius: 10px;"
                              "    font-size: 20px;"
                              "}");
    ui->plus->setStyleSheet("QPushButton{"
                            "    background-color: #592608;"
                            "    color: white;"
                            "    border-radius: 12px;"
                            "    font-size: 29px;"
                            "}");
    ui->minus->setStyleSheet("QPushButton{"
                             "    background-color: #736853;"
                             "    color: white;"
                             "    border-radius: 12px;"
                             "    font-size: 29px;"
                             "}");
    ui->counterclockwiserotation->setStyleSheet("QPushButton{"
                             "    background-color: #736853;"
                             "    color: white;"
                             "    border-radius: 12px;"
                             "    font-size: 29px;"
                             "}");
    ui->rotateclockwise->setStyleSheet("QPushButton{"
                             "    background-color: #592608;"
                             "    color: white;"
                             "    border-radius: 12px;"
                             "    font-size: 29px;"
                             "}");



    //---------------------------------------------------------------------------------------
    //инициализация надписи
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);

    coordinatesInput = new QLineEdit;
    coordinatesInput->setPlaceholderText("Enter coordinates");
    coordinatesInput->setFixedSize(321, 30);
    ui->listWidget->setItemWidget(item, coordinatesInput);
coordinatesInput->setStyleSheet(" background-color:#012845 ");
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform, true);


    plusScaleTimer = new QTimer(this);
    connect(plusScaleTimer, &QTimer::timeout, this, &::MainWindow::onPlusScaleTimerTimeout);
    minusScaleTimer = new QTimer(this);
    connect(minusScaleTimer, &QTimer::timeout, this, &::MainWindow::onMinusScaleTimerTimeout);

    rotationTimer = nullptr;
    rotationSpeed = 70000000000000.0;          // Начальная скорость вращения (можете изменить)
    rotationInterval = 1;        // Интервал вращения в миллисекундах (можете изменить)

}

MainWindow::~MainWindow()
{
    delete ui;
}

//выбор фигур для отрисовки
void MainWindow::on_Figures_clicked()
{

    // Выбор фигуры с помощью диалогового окна
    QStringList items;
    items << "Triangle" << "Circle" << "Rectangle" << "Rhombus" << "Square" << "Hexagon"
          << "FivePointStar" << "SixPointStar" << "EightPointStar"<<"figures";

    bool ok;
    QString item = QInputDialog::getItem(this, "Select a Figure", "Choose a figure:", items, 0, false, &ok);

    if (ok && !item.isEmpty()) {
        currentFigure = item;

        // Выводим информацию о выбранной фигуре (по желанию)
        QMessageBox::information(this, "Selected Figure", "You selected: " + currentFigure);

        // Вызываем соответствующую функцию для вычисления свойств фигуры
        if (currentFigure == "Triangle") {
            calculateTriangle();
        } else if (currentFigure == "Circle") {
            // Аналогично для других фигур
            calculateCircle();
        } else if (currentFigure == "Rectangle") {
            calculateRectangle();
        } else if (currentFigure == "Rhombus") {
            calculateRhombus();
        } else if (currentFigure == "Square") {
            calculateSquare();
        } else if (currentFigure == "Hexagon") {
            calculateHexagon();
        } else if (currentFigure == "FivePointStar") {
            calculateFivePointStar();
        } else if (currentFigure == "SixPointStar") {
            calculateSixPointStar();
        } else if (currentFigure == "EightPointStar") {
            calculateEightPointStar();
        }else if (currentFigure == "figures") {
            QGraphicsScene *newScene = new QGraphicsScene(this);
            QLinearGradient gradient(0, 0, 0, 100);
            gradient.setColorAt(0, QColor("#FFC0CB")); // Розовый цвет
            gradient.setColorAt(1, QColor("#800080")); // Фиолетовый цвет

            // Установка градиентной кисти как фона для сцены
            newScene->setBackgroundBrush(QBrush(gradient));
            line = new Line();
            newScene->addItem(line);

ui->graphicsView->setScene(newScene);

        }
    }
}

//вывод информации о каждой фигуры
//-----------------------------------------------------------
void MainWindow::calculateTriangle()
{

    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()!=6){
        QMessageBox::critical(this,"Error","please enter 6 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());

    Triangle triangle;
    QVector<QPointF> points;
    points << point1 << point2 << point3;

    qreal perimeter = triangle.Perimeter(points);
    qreal area = triangle.Area(points);
    QPointF centerofmass = triangle.centerMass(points);

    QMessageBox::information(this, "Triangle Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass.x())
                                 .arg(centerofmass.y()));
    // Сохраняем вершины треугольника
    trianglePoints = points;
    // Триггерим перерисовку
    update();

}
void MainWindow::calculateCircle(){
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()!=4){
        QMessageBox::critical(this,"Error","please enter 4 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    Circle circle;
    QVector<QPointF> points;
    points << point1 << point2 ;
    qreal perimeter = circle.Perimeter(points);
    qreal area = circle.Area(points);
    QPointF centerofmass = circle.centerMass(points);
    qreal r=circle.radius(points);
    QMessageBox::information(this, "Circle Properties",
                             QString("Radius: %1\nPerimeter: %2\nArea: %3\nCenter of Mass: (%4, %5)")
                                 .arg(r)
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    circlePoints = points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateRectangle()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<8){
        QMessageBox::critical(this,"Error","please enter 8 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    Rectangle rectagle;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4;
    qreal perimeter = rectagle.Perimeter(points);
    qreal area = rectagle.Area(points);
    QPointF centerofmass = rectagle.centerMass(points);

    QMessageBox::information(this, "Rectangle Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    rectanglePoints = points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateRhombus()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<8){
        QMessageBox::critical(this,"Error","please enter 8 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    Rhombus rhombus;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4;
    qreal perimeter = rhombus.Perimeter(points);
    qreal area = rhombus.Area(points);
    QPointF centerofmass = rhombus.centerMass(points);
    QMessageBox::information(this, "Rhombus Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    rhombusPoints = points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateSquare()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<8){
        QMessageBox::critical(this,"Error","please enter 8 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    Square square;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4;
    qreal perimeter = square.Perimeter(points);
    qreal area = square.Area(points);
    QPointF centerofmass = square.centerMass(points);
    QMessageBox::information(this, "Square Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    rhombusPoints = points;

    // Триггерим перерисовку
    update();
}
void MainWindow::calculateHexagon()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<12){
        QMessageBox::critical(this,"Error","please enter 12 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    QPointF point5(coordinates[8].toDouble(), coordinates[9].toDouble());
    QPointF point6(coordinates[10].toDouble(), coordinates[11].toDouble());
    Hexagon hexagon;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4<<point5<<point6;
    qreal perimeter = hexagon.Perimeter(points);
    qreal area = hexagon.Area(points);
    QPointF centerofmass = hexagon.centerMass(points);
    QMessageBox::information(this, "Hexagon Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    hexagonPoints = points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateFivePointStar()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<20){
        QMessageBox::critical(this,"Error","please enter 20 coordinates");
        return;
    }
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    QPointF point5(coordinates[8].toDouble(), coordinates[9].toDouble());
    QPointF point6(coordinates[10].toDouble(), coordinates[11].toDouble());
    QPointF point7(coordinates[12].toDouble(), coordinates[13].toDouble());
    QPointF point8(coordinates[14].toDouble(), coordinates[15].toDouble());
    QPointF point9(coordinates[16].toDouble(), coordinates[17].toDouble());
    QPointF point10(coordinates[18].toDouble(), coordinates[19].toDouble());
    FivePointStar fivepointstar;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4<<point5<<point6<<point7<<point8<<point9<<point10;
    qreal perimeter = fivepointstar.Perimeter(points);
    qreal area = fivepointstar.Area(points);
    QPointF centerofmass = fivepointstar.centerMass(points);
    QMessageBox::information(this, "FivePointStar Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    fivePointstarPoints=points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateSixPointStar()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<24){
        QMessageBox::critical(this,"Error","please enter 24 coordinates");
        return;}
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    QPointF point5(coordinates[8].toDouble(), coordinates[9].toDouble());
    QPointF point6(coordinates[10].toDouble(), coordinates[11].toDouble());
    QPointF point7(coordinates[12].toDouble(), coordinates[13].toDouble());
    QPointF point8(coordinates[14].toDouble(), coordinates[15].toDouble());
    QPointF point9(coordinates[16].toDouble(), coordinates[17].toDouble());
    QPointF point10(coordinates[18].toDouble(), coordinates[19].toDouble());
    QPointF point11(coordinates[20].toDouble(), coordinates[21].toDouble());
    QPointF point12(coordinates[22].toDouble(), coordinates[23].toDouble());
    SixPointStar sixpointstar;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4<<point5<<point6<<point7<<point8<<point9<<point10<<point11<<point12;
    qreal perimeter = sixpointstar.Perimeter(points);
    qreal area = sixpointstar.Area(points);
    QPointF centerofmass = sixpointstar.centerMass(points);
    QMessageBox::information(this, "FivePointStar Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    sixPointstarPoints=points;
    // Триггерим перерисовку
    update();
}
void MainWindow::calculateEightPointStar()
{
    QStringList coordinates=coordinatesInput->text().split(",");
    if(coordinates.size()<34){
        QMessageBox::critical(this,"Error","please enter 34 coordinates");
        return;}
    QPointF point1(coordinates[0].toDouble(), coordinates[1].toDouble());
    QPointF point2(coordinates[2].toDouble(), coordinates[3].toDouble());
    QPointF point3(coordinates[4].toDouble(), coordinates[5].toDouble());
    QPointF point4(coordinates[6].toDouble(), coordinates[7].toDouble());
    QPointF point5(coordinates[8].toDouble(), coordinates[9].toDouble());
    QPointF point6(coordinates[10].toDouble(), coordinates[11].toDouble());
    QPointF point7(coordinates[12].toDouble(), coordinates[13].toDouble());
    QPointF point8(coordinates[14].toDouble(), coordinates[15].toDouble());
    QPointF point9(coordinates[16].toDouble(), coordinates[17].toDouble());
    QPointF point10(coordinates[18].toDouble(), coordinates[19].toDouble());
    QPointF point11(coordinates[20].toDouble(), coordinates[21].toDouble());
    QPointF point12(coordinates[22].toDouble(), coordinates[23].toDouble());
    QPointF point13(coordinates[24].toDouble(), coordinates[25].toDouble());
    QPointF point14(coordinates[26].toDouble(), coordinates[27].toDouble());
    QPointF point15(coordinates[28].toDouble(), coordinates[29].toDouble());
    QPointF point16(coordinates[30].toDouble(), coordinates[31].toDouble());
     QPointF point17(coordinates[32].toDouble(), coordinates[33].toDouble());
    EightPointStar eightpointstar;
    QVector<QPointF> points;
    points << point1 << point2 <<point3<<point4<<point5<<point6<<point7<<point8<<point9<<point10<<point11<<point12<<point13<<point14<<point15<<point16<<point17;
    qreal perimeter = eightpointstar.Perimeter(points);
    qreal area = eightpointstar.Area(points);
    QPointF centerofmass = eightpointstar.centerMass(points);
    QMessageBox::information(this, "FivePointStar Properties",
                             QString("Perimeter: %1\nArea: %2\nCenter of Mass: (%3, %4)")
                                 .arg(perimeter)
                                 .arg(area)
                                 .arg(centerofmass .x())
                                 .arg(centerofmass .y()));

    eightPointstarPoints=points;
    // Триггерим перерисовку
    update();
}
//----------------------------------------------------------------------------
//отрисовка фигур на сцене
void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    scene->clear();
    // Отрисовка фигур на сцене
    scene->addPolygon(trianglePoints);
 if (circlePoints.size() == 2) {
     // Отрисовка круга
     qreal diameter = QLineF(circlePoints[0], circlePoints[1]).length();

     QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(
         QRectF((circlePoints[0].x() + circlePoints[1].x()) / 2.0 - diameter / 2.0,
                (circlePoints[0].y() + circlePoints[1].y()) / 2.0 - diameter / 2.0,
                diameter,
                diameter));
     scene->addItem(ellipseItem);
     // Отрисовка линии, равной диаметру круга
     QGraphicsLineItem *lineItem = new QGraphicsLineItem(
         (circlePoints[0].x() + circlePoints[1].x()) / 2.0 - diameter / 2.0,
         (circlePoints[0].y() + circlePoints[1].y()) / 2.0,
         (circlePoints[0].x() + circlePoints[1].x()) / 2.0 + diameter / 2.0,
         (circlePoints[0].y() + circlePoints[1].y()) / 2.0);
     // Установка зеленой кисти для линии
     scene->addItem(lineItem);
 }
    scene->addPolygon(rectanglePoints);
    scene->addPolygon(rhombusPoints);
    scene->addPolygon(hexagonPoints);
    scene->addPolygon(fivePointstarPoints);
    scene->addPolygon(sixPointstarPoints);
    scene->addPolygon(eightPointstarPoints);

}
//clear сцены
void MainWindow::on_Clear_clicked()
{
    if (currentFigure == "figures") {
        scene->clear(); // Очищаем сцену
    }
    // Очистка данных о фигурах
    trianglePoints.clear();
    circlePoints.clear();
    rectanglePoints.clear();
    rhombusPoints.clear();
    squarePoints.clear();
    hexagonPoints.clear();
    fivePointstarPoints.clear();
    sixPointstarPoints.clear();
    eightPointstarPoints.clear();

    // Перерисовка
    update();
}
//смещение центра масс
void MainWindow::on_center_clicked()
{

    if (currentFigure.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please choose a figure first.");
        return;
    }
    // В зависимости от выбранной фигуры, выполняем соответствующую операцию смещения центра масс
    if (currentFigure == "Triangle") {
        moveCenterOfMass(trianglePoints);
    } else if (currentFigure == "Circle") {
        moveCenterOfMass(circlePoints);
    } else if (currentFigure == "Rectangle") {
        moveCenterOfMass(rectanglePoints);
    } else if (currentFigure == "Rhombus") {
        moveCenterOfMass(rhombusPoints);
    } else if (currentFigure == "Square") {
        moveCenterOfMass(squarePoints);
    } else if (currentFigure == "Hexagon") {
        moveCenterOfMass(hexagonPoints);
    } else if (currentFigure == "FivePointStar") {
        moveCenterOfMass(fivePointstarPoints);
    } else if (currentFigure == "SixPointStar") {
        moveCenterOfMass(sixPointstarPoints);
    } else if (currentFigure == "EightPointStar") {
        moveCenterOfMass(eightPointstarPoints);
    }else if(currentFigure == "figures") {


    }

    // Триггерим перерисовку
    update();
}

void MainWindow::moveTriangleCenter()
{
    moveCenterOfMass(trianglePoints);
}

void MainWindow::moveCircleCenter()
{
    moveCenterOfMass(circlePoints);
}

void MainWindow::moveRectangleCenter()
{
    moveCenterOfMass(rectanglePoints);
}

void MainWindow::moveRhombusCenter()
{
    moveCenterOfMass(rhombusPoints);
}

void MainWindow::moveSquareCenter()
{
    moveCenterOfMass(squarePoints);
}

void MainWindow::moveHexagonCenter()
{
    moveCenterOfMass(hexagonPoints);
}

void MainWindow::moveFivePointStarCenter()
{
    moveCenterOfMass(fivePointstarPoints);
}
void MainWindow::moveSixPointStarCenter()
{
    moveCenterOfMass(sixPointstarPoints);
}
void MainWindow::moveEightPointStarCenter()
{
    moveCenterOfMass(eightPointstarPoints);
}
void MainWindow::moveCenterOfMass(QVector<QPointF> &points)
{
    QPointF newCenterMass = getNewCenterMass();

    if (!newCenterMass.isNull()) {
        // Устанавливаем новый центр масс для текущей фигуры
        for (QPointF &point : points) {
            point += newCenterMass;
        }

        // Триггерим перерисовку
        update();
    }
}
QPointF MainWindow::getNewCenterMass()
{
    QStringList centerMassCoordinates = coordinatesInput->text().split(",");
    if (centerMassCoordinates.size() < 2) {
        QMessageBox::critical(this, "Error", "Please enter valid coordinates for the new center of mass.");
        return QPointF();
    }

    double newX = centerMassCoordinates[0].toDouble();
    double newY = centerMassCoordinates[1].toDouble();

    return QPointF(newX, newY);
}
//анимация увеличения и уменьшения фигур
//----------------------------------------------

void MainWindow::on_plus_pressed()
{

  plusScaleTimer->start(100);

}
void MainWindow::on_plus_released()
{
    // Останавливаем таймер при отпускании кнопки
    plusScaleTimer->stop();
}
void MainWindow::onPlusScaleTimerTimeout()
{
    // Масштабируем фигуры увеличением
    scaleFigures(1.1);
}
//-------------------------------------------------------

void MainWindow::on_minus_pressed()
{

    minusScaleTimer->start(100);
}

void MainWindow::on_minus_released()
{
    // Останавливаем таймер уменьшения при отпускании кнопки
    minusScaleTimer->stop();
}
void MainWindow::onMinusScaleTimerTimeout()
{
    // Масштабируем фигуры уменьшением
    scaleFigures(0.9);
}
//---------------------------------------------------
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
    {

        on_plus_pressed();
    }
    else if (event->key() == Qt::Key_Minus)
    {

        on_minus_pressed();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
    {

        on_plus_released();
    }
    else if (event->key() == Qt::Key_Minus)
    {

        on_minus_released();
    }
}
void MainWindow::scaleFigures(qreal scaleFactor)
{

    // Масштабирование для каждой фигуры
    scaleFigure(trianglePoints, scaleFactor,getFigureCenter(trianglePoints));
    scaleFigure(circlePoints, scaleFactor,getFigureCenter(circlePoints));
    scaleFigure(rectanglePoints, scaleFactor,getFigureCenter(rectanglePoints));
    scaleFigure(hexagonPoints, scaleFactor,getFigureCenter(hexagonPoints));
     scaleFigure(squarePoints, scaleFactor,getFigureCenter(squarePoints));
     scaleFigure(rhombusPoints, scaleFactor,getFigureCenter(rhombusPoints));
      scaleFigure( eightPointstarPoints, scaleFactor,getFigureCenter(eightPointstarPoints));
     scaleFigure( sixPointstarPoints, scaleFactor,getFigureCenter(sixPointstarPoints));
      scaleFigure( fivePointstarPoints, scaleFactor,getFigureCenter(fivePointstarPoints));

    // Триггерим перерисовку
    update();
}

void MainWindow::scaleFigure(QVector<QPointF> &points, qreal scaleFactor, const QPointF &center)
{
    for (QPointF &point : points)
    {
        // Вычисляем отклонение относительно центра
        QPointF offset = point - center;

        // Масштабируем отклонение
        offset *= scaleFactor;

        // Новые координаты точки с учетом центра
        point = center + offset;
    }
}
QPointF MainWindow::getFigureCenter(const QVector<QPointF> &points)
{
    if (points.size() < 3) {
        // Возвращаем какую-то значения по умолчанию, так как центр неопределен для менее чем трех точек
        if (!circlePoints.isEmpty()) {
            return (circlePoints[0] + circlePoints[1]) / 2.0;
        } else {
            return QPointF(0, 0); // Или любое другое значение по умолчанию
        }
    }

    // Просто усредним все координаты, чтобы найти центр
    QPointF center;
    for (const QPointF &point : points)
    {
        center += point;
    }
    center /= points.size();
    return center;
}

//вращение
void MainWindow::on_counterclockwiserotation_pressed()
{
 startRotationTimer(-rotationSpeed);
}


void MainWindow::on_counterclockwiserotation_released()
{
 stopRotationTimer();
}


void MainWindow::on_rotateclockwise_pressed()
{
startRotationTimer(rotationSpeed);
}


void MainWindow::on_rotateclockwise_released()
{
stopRotationTimer();
}
void MainWindow::startRotationTimer(qreal rotationSpeed)
{
    stopRotationTimer();  // Остановить текущий таймер, если он есть

    // Создаем новый таймер для вращения
    rotationTimer = new QTimer(this);

    connect(rotationTimer, &QTimer::timeout, this, [=]() {
        rotateAllFigures(rotationSpeed); // Вращаем все фигуры при срабатывании таймера
    });

    // Устанавливаем интервал таймера (регулирует скорость вращения)
    rotationTimer->start(rotationInterval);
}

void MainWindow::stopRotationTimer()
{
    // Останавливаем таймер при отпускании кнопки
    if (rotationTimer) {
        rotationTimer->stop();
        delete rotationTimer;
        rotationTimer = nullptr;
    }
}

// Метод для вращения всех фигур на сцене
void MainWindow::rotateAllFigures(qreal rotationSpeed)
{
    foreach (QGraphicsItem *item, scene->items()) {
        // Получаем точки фигуры
        QVector<QPointF> points = getFigurePoints(item);

        // Получаем центр масс и устанавливаем точку трансформации
        QPointF center = getFigureCenter(points);
        item->setTransformOriginPoint(center);

        // Вращаем фигуру относительно её центра масс
        item->setRotation(item->rotation() + rotationSpeed);

        // Обновляем положение фигуры на сцене
        item->setPos(item->pos() + center - item->mapToScene(item->boundingRect().center()));
    }
    scene->update();
}
QVector<QPointF> MainWindow::getFigurePoints(QGraphicsItem *item)
{
    QVector<QPointF> points;

    if (item->type() == QGraphicsPolygonItem::Type || item->type() == QGraphicsEllipseItem::Type) {
        // Если это полигон или эллипс, добавляем их точки
        QPolygonF polygon;
        if (item->type() == QGraphicsPolygonItem::Type) {
            polygon = dynamic_cast<QGraphicsPolygonItem*>(item)->polygon();
        } else if (item->type() == QGraphicsEllipseItem::Type) {
            QRectF rect = dynamic_cast<QGraphicsEllipseItem*>(item)->rect();
            // Преобразуем прямоугольник в полигон
            polygon << rect.topLeft() << rect.topRight() << rect.bottomRight() << rect.bottomLeft();
        }

        for (int i = 0; i < polygon.size(); ++i) {
            points.append(polygon.at(i));
        }
    }

    return points;
}
//0,-100,38,-92,71,-71,92,-38,100,0,92,38,71,71,38,92,0,100,-38,92,-71,71,-92,38,-100,0,-92,-38,-71,-71,-38,-92,0,-100
//50,0,65,30,100,40,75,65,80,100,50,85,20,100,25,65,0,40,35,30
//100, 100, 200, 100, 250, 200, 50, 200










