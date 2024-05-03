#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 792);
    setFixedSize(800, 792);
    figure5 = new FivePointedStar(vec);
    figure6 = new SixPointedStar(star6);
    figure8 = new EightPointedStar(star8);
    cir = new Circle(30, QPointF(50,50));
    triangle = new Triangle(QPointF(20, 20), QPointF(80, 20), QPointF(50, 50));
    rect = new Rect(QPointF(30, 30), 90, 40);
    square = new Square(QPointF(20,20), 60);
    par = new Parallelogram(QPointF(20, 20), 80, 50);
    romb = new Rhombus(QPointF(20, 20), 80);
    hex = new Hexagon(60);
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        setup_Buttons();
    });
    timer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete figure5;
    delete figure6;
    delete figure8;
    delete triangle;
    delete cir;
    delete timer;
    delete rect;
    delete square;
    delete par;
    delete romb;
    delete hex;
    delete yd;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    x = event->position().x();
    y = event->position().y();
    if (was_figure==3) {
        square->SetNewCenter(QPointF(x, y));
        square->moveToNewCenter();
    }
    else if (was_figure == 1) {
        cir->SetNewCenter(QPointF(x, y));
    }
    else if (!was_figure) {
        triangle->SetNewCenter(QPointF(x, y));
        triangle->moveToNewCenter();
    }
    else if (was_figure == 4) {
        rect->SetNewCenter(QPointF(x, y));
        rect->moveToNewCenter();
    }
    else if (was_figure == 9) {
        par->SetNewCenter(QPointF(x, y));
        par->moveToNewCenter();
    }
    else if (was_figure == 2) {
        romb->SetNewCenter(QPointF(x, y));
        romb->moveToNewCenter();
    }
    else if (was_figure == 8) {
        hex->SetNewCenter(QPointF(x, y));
        hex->moveToNewCenter();
    }
    else if (was_figure == 5) {
        figure5->SetNewCenter(QPointF(x, y));
        figure5->moveToNewCenter();
    }
    else if (was_figure == 6) {
        figure6->SetNewCenter(QPointF(x, y));
        figure6->moveToNewCenter();
    }
    else if (was_figure == 7) {
        figure8->SetNewCenter(QPointF(x, y));
        figure8->moveToNewCenter();
    }
    else if (was_figure == 10) {
        if (isDrawing) {
            objectPoints.clear();
            objectPoints.push_back(event->pos());
        }
        else {
            yd->SetNewCenter(QPointF(x, y));
            yd->moveToNewCenter();
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::green);
    painter.setPen(Qt::red);
    if (was_figure == 3) square->draw(&painter);
    else if (was_figure == 1) cir->draw(&painter);
    else if (!was_figure) triangle->draw(&painter);
    else if (was_figure == 4) rect->draw(&painter);
    else if (was_figure == 9) par->draw(&painter);
    else if (was_figure == 2) romb->draw(&painter);
    else if (was_figure == 8) hex->draw(&painter);
    else if (was_figure == 5) figure5->draw(&painter);
    else if (was_figure == 6) figure6->draw(&painter);
    else if (was_figure == 7) figure8->draw(&painter);
    else if (was_figure == 10) {
        painter.setBrush(Qt::black);
        painter.setPen(QPen(Qt::black, 4));
        if (!xz_kak_nazvat) {
            if (!objectPoints.empty()) {
                painter.drawPolyline(objectPoints);
            }
        }
        else yd->draw(&painter);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrawing && was_figure == 10) {
        if (objectPoints.size() < 3000) objectPoints.push_back(event->pos());
        else ui->label->setText("Превышено число координат для фигуры!!!");
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (isDrawing && was_figure == 10) {
        isDrawing = false;
        update();
        yd = new YourDrawing(objectPoints);
        xz_kak_nazvat = true;
    }
}

void MainWindow::setup_Buttons()
{
    if (was_figure == -1 || (isDrawing && was_figure == 10)) {
        ui->bntSandP->setEnabled(false);
        ui->bntSandP->setStyleSheet("background-color: red;");
        ui->bntNewAngle->setEnabled(false);
        ui->bntNewAngle->setStyleSheet("background-color: red;");
        ui->bntResize->setEnabled(false);
        ui->bntResize->setStyleSheet("background-color: red;");
        ui->bntMovement->setEnabled(false);
        ui->bntMovement->setStyleSheet("background-color: red;");
        ui->bntSave->setEnabled(false);
        ui->bntSave->setStyleSheet("background-color: red;");
    }
    else {
        if (ui->lblX->text() == "Вы ввели все нужные координаты" || ui->lblX->text() == "Для данной фигуры недоступна смена координат" || ui->lblX->text() == "Нельзя сменить координаты пустоты)))" || ui->lblX->text() == "Треугольника с такими координатами не существует!!!") {
            ui->bntSave->setEnabled(false);
            ui->bntSave->setStyleSheet("background-color: red;");
        }
        else {
            ui->bntSave->setEnabled(true);
            ui->bntSave->setStyleSheet("background-color: white;");
        }
        QString message = QString("Значение: %1").arg(ui->progressBar->value());
        ui->znachlbl->setText(message);
        if (was_figure == 69) {
            ui->bntSandP->setEnabled(false);
            ui->bntSandP->setStyleSheet("background-color: red;");
            ui->bntNewAngle->setEnabled(false);
            ui->bntNewAngle->setStyleSheet("background-color: red;");
            ui->bntResize->setEnabled(false);
            ui->bntResize->setStyleSheet("background-color: red;");
            ui->bntMovement->setEnabled(false);
            ui->bntMovement->setStyleSheet("background-color: red;");
        }
        else if (was_figure == 10) {
            ui->bntSandP->setEnabled(false);
            ui->bntSandP->setStyleSheet("background-color: red;");
        }
        if (figure5->Get_animation_is_true() || figure6->Get_animation_is_true() || cir->Get_animation_is_true() || figure8->Get_animation_is_true() || triangle->Get_animation_is_true() || rect->Get_animation_is_true() || square->Get_animation_is_true() || par->Get_animation_is_true() || romb->Get_animation_is_true() || hex->Get_animation_is_true() || (xz_kak_nazvat && yd->Get_animation_is_true())) {
            ui->bntNewAngle->setEnabled(false);
            ui->bntNewAngle->setStyleSheet("background-color: red;");
            ui->bntResize->setEnabled(false);
            ui->bntResize->setStyleSheet("background-color: red;");
            ui->bntMovement->setEnabled(false);
            ui->bntMovement->setStyleSheet("background-color: red;");
        }
        else if (was_figure != 10 && was_figure != 69) {
            ui->bntSandP->setEnabled(true);
            ui->bntSandP->setStyleSheet("background-color: blue;");
            ui->bntNewAngle->setEnabled(true);
            ui->bntNewAngle->setStyleSheet("background-color: blue;");
            ui->bntResize->setEnabled(true);
            ui->bntResize->setStyleSheet("background-color: blue;");
            ui->bntMovement->setEnabled(true);
            ui->bntMovement->setStyleSheet("background-color: blue;");
        }
        else if (was_figure != 69) {
            ui->bntNewAngle->setEnabled(true);
            ui->bntNewAngle->setStyleSheet("background-color: blue;");
            ui->bntResize->setEnabled(true);
            ui->bntResize->setStyleSheet("background-color: blue;");
            ui->bntMovement->setEnabled(true);
            ui->bntMovement->setStyleSheet("background-color: blue;");
        }
    }
}

void MainWindow::on_bntResize_clicked()
{
    if (ui->checkBox->isChecked()) mov = mov2;
    else mov = mov1;
    if (was_figure==3) square->resize_animation(mov, time_animation);
    else if (was_figure == 1) cir->resize_animation(mov, time_animation);
    else if (!was_figure) triangle->resize_animation(mov, time_animation);
    else if (was_figure == 4) rect->resize_animation(mov, time_animation);
    else if (was_figure == 9) par->resize_animation(mov, time_animation);
    else if (was_figure == 2) romb->resize_animation(mov, time_animation);
    else if (was_figure == 8) hex->resize_animation(mov, time_animation);
    else if (was_figure == 5) figure5->resize_animation(mov, time_animation);
    else if (was_figure == 6) figure6->resize_animation(mov, time_animation);
    else if (was_figure == 7) figure8->resize_animation(mov, time_animation);
    else if (was_figure == 10) yd->resize_animation(mov, time_animation);
}


void MainWindow::on_bntNewAngle_clicked()
{
    if (ui->checkBox_2->isChecked()) turn_angle *= -1;
    if (was_figure==3) square->turn_animation(turn_angle, time_animation);
    else if (!was_figure) triangle->turn_animation(turn_angle, time_animation);
    else if (was_figure == 4) rect->turn_animation(turn_angle, time_animation);
    else if (was_figure == 9) par->turn_animation(turn_angle, time_animation);
    else if (was_figure == 2) romb->turn_animation(turn_angle, time_animation);
    else if (was_figure == 8) hex->turn_animation(turn_angle, time_animation);
    else if (was_figure == 5) figure5->turn_animation(turn_angle, time_animation);
    else if (was_figure == 6) figure6->turn_animation(turn_angle, time_animation);
    else if (was_figure == 7) figure8->turn_animation(turn_angle, time_animation);
    else if (was_figure == 10) yd->turn_animation(turn_angle, time_animation);
}


void MainWindow::on_bntSandP_clicked()
{
    QString labelPer;
    QString labelSquare;
    QString labelCenter;
    if (was_figure == 3) {
        square->find_per();
        square->find_square();
        square->find_center();
        labelPer = QString("Периметр: %1").arg(square->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(square->GetSquare());
        labelCenter = QString("Центр масс: (%1;%2)").arg(square->GetCenter().x()).arg(square->GetCenter().y());
    }
    else if (was_figure == 1) {
        cir->find_per();
        cir->find_square();
        labelPer = QString("Периметр: %1").arg(cir->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(cir->GetSquare());
        labelCenter = QString("Центр масс: (%1;%2)").arg(cir->GetCenter().x()).arg(cir->GetCenter().y());
    }
    else if (!was_figure) {
        triangle->findSquareTriangle();
        triangle->find_center();
        triangle->find_per();
        labelPer = QString("Периметр: %1").arg(triangle->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(triangle->GetSquareTriangle());
        labelCenter = QString("Центр масс: (%1;%2)").arg(triangle->GetCenter().x()).arg(cir->GetCenter().y());
    }
    else if (was_figure == 4) {
        rect->findSquareRect();
        rect->find_center();
        rect->find_per();
        labelPer = QString("Периметр: %1").arg(rect->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(rect->GetSquareRect());
        labelCenter = QString("Центр масс: (%1;%2)").arg(rect->GetCenter().x()).arg(cir->GetCenter().y());
    }
    else if (was_figure == 9) {
        par->findSquarePar();
        par->find_center();
        par->find_per();
        labelPer = QString("Периметр: %1").arg(par->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(par->GetSquarePar());
        labelCenter = QString("Центр масс: (%1;%2)").arg(par->GetCenter().x()).arg(par->GetCenter().y());
    }
    else if (was_figure == 2) {
        romb->findSquarePar();
        romb->find_center();
        romb->find_per();
        labelPer = QString("Периметр: %1").arg(romb->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(romb->GetSquarePar());
        labelCenter = QString("Центр масс: (%1;%2)").arg(romb->GetCenter().x()).arg(romb->GetCenter().y());
    }
    else if (was_figure == 8) {
        hex->SquareHexagon();
        hex->find_center();
        hex->find_per();
        labelPer = QString("Периметр: %1").arg(hex->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(hex->GetSquareHex());
        labelCenter = QString("Центр масс: (%1;%2)").arg(hex->GetCenter().x()).arg(hex->GetCenter().y());
    }
    else if (was_figure == 5) {
        figure5->find_square();
        figure5->find_center();
        figure5->find_per();
        labelPer = QString("Периметр: %1").arg(figure5->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(figure5->GetSquare());
        labelCenter = QString("Центр масс: (%1;%2)").arg(figure5->GetCenter().x()).arg(figure5->GetCenter().y());
    }
    else if (was_figure == 6) {
        figure6->find_square();
        figure6->find_center();
        figure6->find_per();
        labelPer = QString("Периметр: %1").arg(figure6->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(figure6->GetSquare());
        labelCenter = QString("Центр масс: (%1;%2)").arg(figure6->GetCenter().x()).arg(figure6->GetCenter().y());
    }
    else if (was_figure == 7) {
        figure8->find_square();
        figure8->find_center();
        figure8->find_per();
        labelPer = QString("Периметр: %1").arg(figure8->GetPerimeter());
        labelSquare = QString("Площадь: %1").arg(figure8->GetSquare());
        labelCenter = QString("Центр масс: (%1;%2)").arg(figure8->GetCenter().x()).arg(figure8->GetCenter().y());
    }
    ui->txtPerimeter->setText(labelPer);
    ui->txtSquare->setText(labelSquare);
    ui->txtCenter->setText(labelCenter);
}


void MainWindow::on_bntMovement_clicked()
{
    if (ui->checkBox_3->isChecked()) mov_point = mov_point2;
    else mov_point = mov_point1;
    if (was_figure==3) square->movement_animation(mov_point, time_animation);
    else if (was_figure==1) cir->movement_animation(mov_point, time_animation);
    else if (!was_figure) triangle->movement_animation(mov_point, time_animation);
    else if (was_figure == 4) rect->movement_animation(mov_point, time_animation);
    else if (was_figure == 9) par->movement_animation(mov_point, time_animation);
    else if (was_figure == 2) romb->movement_animation(mov_point, time_animation);
    else if (was_figure == 8) hex->movement_animation(mov_point, time_animation);
    else if (was_figure == 5) figure5->movement_animation(mov_point, time_animation);
    else if (was_figure == 6) figure6->movement_animation(mov_point, time_animation);
    else if (was_figure == 7) figure8->movement_animation(mov_point, time_animation);
    else if (was_figure == 10) yd->movement_animation(mov_point, time_animation);
}


void MainWindow::on_bntSave_clicked()
{
    ui->progressBar->value();
    QString message = QString("Значение: %1").arg(ui->progressBar->value());
    ui->znachlbl->setText(message);
    if (!was_figure) {
        int ind = -1;
        for (int i = 0; i < 6; ++i) {
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 5) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            bool is_tr = triangle->isTriangle(QPointF(coord[0], coord[1]), QPointF(coord[2], coord[3]), QPointF(coord[4],coord[5]));
            if (is_tr) triangle->SetNewCoord(QPointF(coord[0], coord[1]), QPointF(coord[2], coord[3]), QPointF(coord[4],coord[5]));
            else ui->lblX->setText("Треугольника с такими координатами не существует!!!");
        }
        else if (ind % 2 == 0) {
            ui->lblX->setText("Введите y");
        }
        else ui->lblX->setText("Введите x");
    }
    else if (was_figure == 1) {
        int ind = -1;
        for (int i = 0; i < 3; ++i) {
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 2) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            cir->SetNewCoord(coord[2], QPointF(coord[0], coord[1]));
        }
        else if (ind == 0) ui->lblX->setText("Введите y");
        else if (ind == 1) ui->lblX->setText("Введите радиус");
    }
    else if (was_figure == 3) {
        int ind = -1;
        for (int i = 0; i < 3; ++i) {ui->lblX->setText("Введите x");
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 2) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            square->SetNewCoord(QPointF(coord[0], coord[1]), coord[2]);
        }
        else if (ind == 0) ui->lblX->setText("Введите y");
        else if (ind == 1) ui->lblX->setText("Введите длину стороны");
    }
    else if (was_figure == 4) {
        int ind = -1;
        for (int i = 0; i < 4; ++i) {
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 3) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            rect->SetNewCoord(QPointF(coord[0], coord[1]), coord[2], coord[3]);
        }
        else if (ind == 0) ui->lblX->setText("Введите y");
        else if (ind == 1) ui->lblX->setText("Введите длину");
        else if (ind == 2) ui->lblX->setText("Введите ширину");
    }
    else if (was_figure == 8) {
        coord[0] = ui->progressBar->value();
        hex->SetNewCoord(coord[0]);
        ui->lblX->setText("Вы ввели все нужные координаты");
    }
    else if (was_figure == 9) {
        int ind = -1;
        for (int i = 0; i < 4; ++i) {
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 3) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            par->SetNewCoord(QPointF(coord[0], coord[1]), coord[2], coord[3]);
        }
        else if (ind == 0) ui->lblX->setText("Введите y");
        else if (ind == 1) ui->lblX->setText("Введите длину");
        else if (ind == 2) ui->lblX->setText("Введите ширину");
    }
    else if (was_figure == 2) {
        int ind = -1;
        for (int i = 0; i < 3; ++i) {
            if (coord[i] == -1) {
                coord[i] = ui->progressBar->value();
                if (i == 2) ind = -1;
                else ind = i;
                break;
            }
        }
        if (ind == -1) {
            ui->lblX->setText("Вы ввели все нужные координаты");
            romb->SetNewCoord(QPointF(coord[0], coord[1]), coord[2]);
        }
        else if (ind == 0) ui->lblX->setText("Введите y");
        else if (ind == 1) ui->lblX->setText("Введите длину стороны");
    }
}


void MainWindow::on_bntsaveok_clicked()
{
    if (ui->bntTriangle->isChecked()) {
        was_figure = 0;
        triangle->SetStartParams();
        coord.resize(6);
        coord={-1, -1, -1, -1, -1, -1};
        ui->label->setText("Введите координаты 3 точек, значение по x и y 3 раза");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntCircle->isChecked()) {
        was_figure = 1;
        cir->SetStartParams();
        coord.resize(3);
        coord = {-1, -1, -1};
        ui->label->setText("Введите значение по x по y центра и радиус");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntRhombus->isChecked()) {
        was_figure = 2;
        romb->SetStartParams();
        coord.resize(4);
        coord = {-1, -1, -1, -1};
        ui->label->setText("Введите значение по x по y 3 точек");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntSquare->isChecked()){
        was_figure = 3;
        square->SetStartParams();
        coord.resize(3);
        coord = {-1, -1, -1};
        ui->label->setText("Введите значение по x по y 1 точки, длину стороны");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntRect->isChecked()){
        was_figure = 4;
        rect->SetStartParams();
        coord.resize(4);
        coord = {-1, -1, -1, -1};
        ui->label->setText("Введите значение по x по y 1 точки, длину и ширину");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntStar5->isChecked()) {
        was_figure = 5;
        ui->label->setText("Читайте документацию, ой, точнее текст снизу");
        ui->lblX->setText("Для данной фигуры недоступна смена координат");
        figure5->SetStartParams();
    }
    else if(ui->bntStar6->isChecked()) {
        was_figure = 6;
        ui->label->setText("Читайте документацию, ой, точнее текст снизу");
        ui->lblX->setText("Для данной фигуры недоступна смена координат");
        figure6->SetStartParams();
    }
    else if (ui->bntStar8->isChecked()){
        was_figure = 7;
        ui->label->setText("Читайте документацию, ой, точнее текст снизу");
        ui->lblX->setText("Для данной фигуры недоступна смена координат");
        figure8->SetStartParams();
    }
    else if (ui->bntHexagon->isChecked()) {
        was_figure = 8;
        hex->SetStartParams();
        coord.resize(1);
        coord = {-1};
        ui->label->setText("Введите радиус описанной окр.");
        ui->lblX->setText("Введите R");
    }
    else if (ui->bntMy->isChecked()) {
        was_figure = 9;
        par->SetStartParams();
        coord.resize(4);
        coord = {-1, -1, -1, -1};
        ui->label->setText("Введите значение по x по y точки и длины сторон");
        ui->lblX->setText("Введите x");
    }
    else if (ui->bntdrawMY->isChecked()) {
        was_figure = 10;
        isDrawing = true;
        objectPoints.clear();
        xz_kak_nazvat = false;
        ui->label->setText("Читайте документацию, ой, точнее текст снизу");
        ui->lblX->setText("Для данной фигуры недоступна смена координат");
    }
    else if (ui->bntDelete->isChecked()) {
        was_figure = 69;
        ui->label->setText("Читайте документацию, ой, точнее текст снизу");
        ui->lblX->setText("Нельзя сменить координаты пустоты)))");
    }
}
