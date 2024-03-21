#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "triangledialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValues() // обновление значений
{
    ui->spinBox->setValue(figure->getCenter().x());
    ui->spinBox_2->setValue(figure->getCenter().y());
    ui->areaLabel->setText(QString::number(figure->findArea(), 'f', 2));
    ui->perimeterLabel->setText(QString::number(figure->findPerimeter(), 'f', 2));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);

    if (figure && ui->checkBox->isChecked()) {
        if (!point) {
            point = new QGraphicsEllipseItem(QRectF(figure->getCenter().x() - 1, figure->getCenter().y()-1, 2, 2), figure);
            point->setBrush(Qt::red);
            point->setPen(QPen(Qt::red));
            scene->addItem(point);
        }
    }

}

void MainWindow::on_pushButton_clicked() // рисование фигуры
{

    if (ui->checkBox->isChecked()) {
        ui->checkBox->setCheckState(Qt::Unchecked);
    }

    if (ui->comboBox->currentIndex() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не выбрана!\nВыберите фигуру в списке выше");
    } else if (ui->comboBox->currentIndex() == 1){
        scene->clear();
        figure = new Triangle();
        Triangle* triangle = dynamic_cast<Triangle*>(figure);
        connect(&triangleD, &TriangleDialog::sendTriangleSignals, triangle, &Triangle::setA);
        triangleD.exec();
        if (triangle->getA()) {
            scene->addItem(figure);
            updateValues();
            curF = 1;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;

        }
    } else if (ui->comboBox->currentIndex() == 2) {
        scene->clear();
        figure = new Circle();
        Circle* circle = dynamic_cast<Circle*>(figure);
        connect(&circleD, &CircleDialog::sendCircleSignals, circle, &Circle::setR);
        connect(&circleD, &CircleDialog::sendCheckSignal, circle, &Circle::isCh);
        circleD.exec();
        if (circle->getR()) {
            scene->addItem(figure);
            updateValues();
            curF = 2;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 3) {
        scene->clear();
        figure = new Rhombus();
        Rhombus* rhombus = dynamic_cast<Rhombus*>(figure);
        connect(&rhombusD, &RhombusDialog::sendRhombusSignals, rhombus, &Rhombus::setAB);
        rhombusD.exec();
        if (rhombus->getA() && rhombus->getB()) {
            scene->addItem(figure);
            updateValues();
            curF = 3;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 4) {
        scene->clear();
        figure = new Square();
        Square* square = dynamic_cast<Square*>(figure);
        connect(&squareD, &SquareDialog::sendSquareSignals, square, &Square::setA);
        squareD.exec();
        if (square->getA()) {
            scene->addItem(figure);
            updateValues();
            curF = 4;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 5) {
        scene->clear();
        figure = new Rectangle();
        Rectangle* rectangle = dynamic_cast<Rectangle*>(figure);
        connect(&rectangleD, &RectangleDialog::sendRectangleSignals, rectangle, &Rectangle::setAB);
        rectangleD.exec();
        if (rectangle->getA() && rectangle->getB()) {
            scene->addItem(figure);
            updateValues();
            curF = 5;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 6) {
        scene->clear();
        figure = new Star5Pntd();
        Star5Pntd* star = dynamic_cast<Star5Pntd*>(figure);
        connect(&starD, &StarDialog::sendStarSignals, star, &Star5Pntd::setRs);
        connect(&starD, &StarDialog::sendRBtnsSignal, star, &Star5Pntd::setPoints);
        starD.exec();
        if (star->getPoints() == 6) {
            int r1, r2;
            r1 = star->getR1();
            r2 = star->getR2();
            figure = new Star6Pntd();
            Star6Pntd* star = dynamic_cast<Star6Pntd*>(figure);
            star->setRs(r1, r2);
        } else if (star->getPoints() == 8) {
            int r1, r2;
            r1 = star->getR1();
            r2 = star->getR2();
            figure = new Star8Pntd();
            Star8Pntd* star = dynamic_cast<Star8Pntd*>(figure);
            star->setRs(r1, r2);
        }
        if (star->getR1() && star->getR2()) {
            scene->addItem(figure);
            updateValues();
            curF = 6;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 7) {
        scene->clear();
        figure = new Hexagon();
        Hexagon* hex = dynamic_cast<Hexagon*>(figure);
        connect(&hexagonD, &HexagonDialog::sendHexagonSignals, hex, &Hexagon::setR);
        hexagonD.exec();
        if (hex->getR()) {
            scene->addItem(figure);
            updateValues();
            curF = 7;
        } else {
            figure = nullptr;
        }
    } else if (ui->comboBox->currentIndex() == 8) {
        scene->clear();
        figure = new Trapezoid();
        Trapezoid* trapezoid = dynamic_cast<Trapezoid*>(figure);
        connect(&trapezoidD, &TrapezoidDialog::sendTrapezoidSignals, trapezoid, &Trapezoid::setABH);
        trapezoidD.exec();
        if (trapezoid->getA() && trapezoid->getB() && trapezoid->getH()) {
            scene->addItem(figure);
            updateValues();
            curF = 8;
        } else {
            QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
            figure = nullptr;
        }
    }
}

void MainWindow::on_pushButton_moveUp_clicked()
{
    if (figure) {
        figure->moveUp();
        updateValues();
    }
}


void MainWindow::on_pushButton_moveRight_clicked()
{
    if (figure) {
        figure->moveRight();
        updateValues();
    }
}

void MainWindow::on_pushButton_moveDown_clicked()
{
    if (figure) {
        figure->moveDown();
        updateValues();
    }
}


void MainWindow::on_pushButton_moveLeft_clicked()
{
    if (figure) {
        figure->moveLeft();
        updateValues();
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    if (figure) {
        figure->rotateLeft();
        updateValues();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (figure) {
        figure->rotateRight();
        updateValues();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if (figure) {
        figure->upScale();
        updateValues();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if (figure) {
        figure->downScale();
        updateValues();
    }
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (figure) {
        figure->SBMoveX(arg1);
    } else {
        if (arg1 != 0) {
            ui->spinBox->setValue(0);
            QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы изменять её центр масс");
        }
    }
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    if (figure) {
        figure->SBMoveY(arg1);
    } else {
        if (arg1 != 0) {
            ui->spinBox_2->setValue(0);
            QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы изменять её центр масс");
        }
    }
}


void MainWindow::on_pushButton_4_clicked() // изменение параметров
{
    if (figure) {
        if (curF == 1) {

            Triangle* triangle = dynamic_cast<Triangle*>(figure);
            int temp = triangle->getA();
            connect(&triangleD, &TriangleDialog::sendTriangleSignals, triangle, &Triangle::setA);
            if (triangle->getA() == 0) triangle->setA(temp);
            triangleD.exec();
            if (triangle->getA() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                triangle->setA(temp);
            }

        } else if (curF == 2) {
            Circle* circle = dynamic_cast<Circle*>(figure);
            int temp = circle->getR();
            connect(&circleD, &CircleDialog::sendCircleSignals, circle, &Circle::setR);
            if (circle->getR() == 0) circle->setR(temp);
            connect(&circleD, &CircleDialog::sendCheckSignal, circle, &Circle::isCh);
            circleD.exec();
            if (circle->getR() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                circle->setR(temp);
            }

        } else if (curF == 3) {
            Rhombus* rhombus = dynamic_cast<Rhombus*>(figure);
            int temp1 = rhombus->getA(), temp2 = rhombus->getB();
            connect(&rhombusD, &RhombusDialog::sendRhombusSignals, rhombus, &Rhombus::setAB);
            if (rhombus->getA() == 0 || rhombus->getB() == 0) rhombus->setAB(temp1, temp2);
            rhombusD.exec();
            if (rhombus->getA() == 0 || rhombus->getB() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                rhombus->setAB(temp1, temp2);
            }
        } else if (curF == 4) {
            Square* square = dynamic_cast<Square*>(figure);
            int temp = square->getA();
            connect(&squareD, &SquareDialog::sendSquareSignals, square, &Square::setA);
            if (square->getA() == 0) square->setA(temp);
            squareD.exec();
            if (square->getA() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                square->setA(temp);
            }
        } else if (curF == 5) {
            Rectangle* rectangle = dynamic_cast<Rectangle*>(figure);
            int temp1 = rectangle->getA(), temp2 = rectangle->getB();
            connect(&rectangleD, &RectangleDialog::sendRectangleSignals, rectangle, &Rectangle::setAB);
            if (rectangle->getA() == 0 || rectangle->getB() == 0) rectangle->setAB(temp1, temp2);
            rectangleD.exec();
            if (rectangle->getA() == 0 || rectangle->getB() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                rectangle->setAB(temp1, temp2);
            }
        } else if (curF == 6) {
            Star5Pntd* star = dynamic_cast<Star5Pntd*>(figure);
            int temp1 = star->getR1(), temp2 = star->getR2();
            connect(&starD, &StarDialog::sendStarSignals, star, &Star5Pntd::setRs);
            if (star->getR1() == 0 || star->getR2() == 0) star->setRs(temp1, temp2);
            connect(&starD, &StarDialog::sendRBtnsSignal, star, &Star5Pntd::setPoints);
            starD.exec();
            if (star->getR1() == 0 || star->getR2() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                star->setRs(temp1, temp2);
            }
            if (star->getPoints() == 6) {
                int r1, r2;
                r1 = star->getR1();
                r2 = star->getR2();
                Star6Pntd* star = dynamic_cast<Star6Pntd*>(figure);
                star->setRs(r1, r2);
            } else if (star->getPoints() == 8) {
                int r1, r2;
                r1 = star->getR1();
                r2 = star->getR2();
                Star8Pntd* star = dynamic_cast<Star8Pntd*>(figure);
                star->setRs(r1, r2);
            }
        } else if (curF == 7) {
            Hexagon* hex = dynamic_cast<Hexagon*>(figure);
            int temp = hex->getR();
            connect(&hexagonD, &HexagonDialog::sendHexagonSignals, hex, &Hexagon::setR);
            if (hex->getR() == 0) hex->setR(temp);
            hexagonD.exec();
            if (hex->getR() == 0) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                hex->setR(temp);
            }
        } else if (curF == 8) {
            Trapezoid* trapezoid = dynamic_cast<Trapezoid*>(figure);
            int temp1 = trapezoid->getA(), temp2 = trapezoid->getB(), temp3 = trapezoid->getH();
            connect(&trapezoidD, &TrapezoidDialog::sendTrapezoidSignals, trapezoid, &Trapezoid::setABH);
            if (trapezoid->getA() == 0 || trapezoid->getB() || trapezoid->getH()) trapezoid->setABH(temp1, temp2, temp3);
            trapezoidD.exec();
            if (trapezoid->getA() == 0 || trapezoid->getB() || trapezoid->getH()) {
                QMessageBox::critical(nullptr, "Ошибка", "Введено неверное значение");
                trapezoid->setABH(temp1, temp2, temp3);
            }
        }
        scene->addItem(figure);
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы изменять параметры");
    }
}


void MainWindow::on_pushButton_5_clicked() //
{
    if (figure) {
        scene->clear();
        figure = nullptr;

        ui->spinBox->setValue(0);
        ui->spinBox_2->setValue(0);

        ui->areaLabel->setText("");
        ui->perimeterLabel->setText("");

        ui->checkBox->setCheckState(Qt::Unchecked);
        points.clear();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы её удалить");
    }
}


void MainWindow::on_pushButton_moveUp_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveUpSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_moveUp_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUpSlot()));
    timer->stop();
}




void MainWindow::on_pushButton_moveRight_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRightSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_moveRight_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRightSlot()));
    timer->stop();
}


void MainWindow::on_pushButton_moveDown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDownSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_moveDown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDownSlot()));
    timer->stop();
}


void MainWindow::on_pushButton_moveLeft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeftSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_moveLeft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeftSlot()));
    timer->stop();
}


void MainWindow::on_pushButton_2_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_2_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftSlot()));
    timer->stop();
}




void MainWindow::on_pushButton_3_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRightSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_3_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRightSlot()));
    timer->stop();
}


void MainWindow::on_pushButton_8_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(upScaleSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_8_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(upScaleSlot()));
    timer->stop();
}


void MainWindow::on_pushButton_9_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(downScaleSlot()));
    timer->start(10);
}


void MainWindow::on_pushButton_9_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(downScaleSlot()));
    timer->stop();
}

void MainWindow::moveUpSlot()
{
    if(figure) {
        figure->moveUp();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы двигать её");
    }
}

void MainWindow::moveDownSlot()
{
    if(figure) {
        figure->moveDown();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы двигать её");
    }
}

void MainWindow::moveRightSlot()
{
    if (figure) {
        figure->moveRight();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы двигать её");
    }
}


void MainWindow::moveLeftSlot()
{
    if(figure) {
        figure->moveLeft();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы двигать её");
    }
}

void MainWindow::rotateRightSlot()
{
    if (figure) {
        figure->rotateRight();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы вращать её");
    }
}

void MainWindow::rotateLeftSlot()
{
    if(figure) {
        figure->rotateLeft();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы вращать её");
    }
}


void MainWindow::upScaleSlot()
{
    if(figure) {
        figure->upScale();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы изменять её размер");
    }
}


void MainWindow::downScaleSlot()
{
    if(figure) {
        figure->downScale();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы изменять её размер");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if (figure) {
        ui->graphicsView->centerOn(figure);
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы перевести на неё камеру");
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (figure) {
        update();
    } else {
        if (arg1 == Qt::Checked){
            ui->checkBox->setCheckState(Qt::Unchecked);
            QMessageBox::critical(nullptr, "Ошибка", "Фигура не нарисвована!\nНарисуйте фигуру, чтобы отобразить его центр масс");
        }
    }

    if (arg1 == Qt::Unchecked && point) {
        scene->removeItem(point);
        point = nullptr;
    }
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);


}


void MainWindow::on_radioButton_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->radioButton_2->isChecked()) {
        if (ui->comboBox->currentIndex() == 1) { // Треугольник
            if (event->button() == Qt::LeftButton) {
                points.push_back(ui->graphicsView->mapToScene(event->pos()));
                if (points.size() == 3) {
                    figure = new Triangle();
                    Triangle* triangle = dynamic_cast<Triangle*>(figure);
                    triangle->isDrawing = true;
                    triangle->setPoints(points); // Установка точек треугольника
                    scene->addItem(figure);
                    updateValues();
                    curF = 1;
                }
            }
        } else if (ui->comboBox->currentIndex() == 2) {

        } else if (ui->comboBox->currentIndex() == 3) {

        } else if (ui->comboBox->currentIndex() == 4) { // Квадрат
            if (event->button() == Qt::LeftButton) {
                points.push_back(ui->graphicsView->mapToScene(event->pos()));
                if (points.size() == 1) {
                    figure = new Square();
                    Square* square = dynamic_cast<Square*>(figure);
                    square->isDrawing = true;
                    qDebug() << "!!";
                    scene->addItem(figure);
                    qDebug() << "!!";
                    //updateValues();

                    curF = 4; // Индекс для квадрата
                }
            }
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->radioButton_2->isChecked()) {
        if (ui->comboBox->currentIndex() == 4 && figure != nullptr) { // Индекс для квадрата
            Square* square = dynamic_cast<Square*>(figure);
            if (square->isDrawing) {
                if (points.size() == 2) {
                    points.pop_back(); // Удалить последнюю точку
                }
                points.push_back(ui->graphicsView->mapToScene(event->pos()));
                square->setPoints(points); // Установка точек квадрата
                figure->update(); // Добавьте эту строку
                updateValues();
            }
        }
    }
}



void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (ui->radioButton_2->isChecked()) {
        if (ui->comboBox->currentIndex() == 4 && figure != nullptr) { // Индекс для квадрата
            Square* square = dynamic_cast<Square*>(figure);
            if (square->isDrawing) {
                square->isDrawing = false;
                points.clear();
            }
        }
    }
}

