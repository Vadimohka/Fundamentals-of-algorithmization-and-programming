#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "triangle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new CustomScene())
{
    ui->setupUi(this);

    ui->graphicsView->setFocusPolicy(Qt::StrongFocus);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    figures = QVector<QGraphicsItem*>();
    temp_points = QVector<QPointF>();

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(ui->graphicsView->x(), ui->graphicsView->y(), ui->graphicsView->width(), ui->graphicsView->height());

    scene->addLine(0, 255, 0, -255);
    scene->addLine(255, 0, -255, 0);

    ui->Create_button->setChecked(true);

    connect(scene, SIGNAL(leftMousePressed(QPointF)), this, SLOT(SetPoint(QPointF)));
    connect(scene, SIGNAL(rightMousePressed(QGraphicsSceneMouseEvent*)), this, SLOT(Selection(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(mouseMoved(QPointF,QPointF)), this, SLOT(SetMove()));
    connect(scene, SIGNAL(mouseMoved(QPointF,QPointF)), this, SLOT(SetRotate(QPointF,QPointF)));
    connect(scene, SIGNAL(mouseMoved(QPointF,QPointF)), this, SLOT(SetScale(QPointF,QPointF)));
    connect(scene, SIGNAL(deleteItem()), this, SLOT(SetDelete()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete temp_figure;
    delete current_figure;
    delete scene;

    for (int i = 0; i < figures.size() - 1; ++i)
    {
        delete (figures.at(i));
    }
}

void MainWindow::SetPoint(QPointF pos)
{
    if (ui->Create_button->isChecked())
    {
        if (current_figure != nullptr) {
            current_figure->setFlag(QGraphicsItem::ItemIsMovable, false);
        }

        temp_points.append(pos);
        if (ui->Figure_box->currentIndex() == 0 && temp_points.size() == 3)
        {
            figures.append(new Triangle(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 1 && temp_points.size() == 2)
        {
            figures.append(new Circle(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 2 && temp_points.size() == 2)
        {
            figures.append(new Ellipse(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 3 && temp_points.size() == 2)
        {
            figures.append(new Rectangle(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if(ui->Figure_box->currentIndex() == 4 && temp_points.size() == 2)
        {
            figures.append(new Square(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 5 && temp_points.size() == 2)
        {
            figures.append(new Rhombus(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 6 && temp_points.size() == 2)
        {
            figures.append(new Star5(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 7 && temp_points.size() == 2)
        {
            figures.append(new Star6(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
        else if (ui->Figure_box->currentIndex() == 8 && temp_points.size() == 2)
        {
            figures.append(new Star8(temp_points));
            temp_points.clear();
            scene->addItem(figures.last());
        }
    }
}

void MainWindow::Selection(QGraphicsSceneMouseEvent *event)
{
    if (!(ui->Create_button->isChecked()))
    {
        temp_figure = current_figure;

        const QColor no_color(0,0,0);

        if (temp_figure != nullptr) {
            temp_figure->SetPenColor(no_color);
        }

        const QColor color(255, 0, 0);
        current_figure = (Figure*)(scene->itemAt(event->scenePos(), {}));

        if (current_figure != nullptr)
        {
            current_figure->SetPenColor(color);
            UpdateInfo(current_figure->scale());
        }
    }
}

void MainWindow::UpdateInfo(qreal scale)
{
    QString c = QString::number(current_figure->GetCenter().toPoint().x()) + QString(", ") + QString::number(current_figure->GetCenter().toPoint().y());

    ui->Center_label->setText(c);

    ui->Perim_label->setText(QString::number(current_figure->GetPerim() * scale));

    ui->Square_label->setText(QString::number(current_figure->GetSquare() * scale));
}

void MainWindow::SetMove()
{

    if (ui->Move_button->isChecked() && current_figure != nullptr)
    {
        current_figure->setFlag(QGraphicsItem::ItemIsMovable, true);


        if (temp_figure != nullptr)
        {
            temp_figure->setFlag(QGraphicsItem::ItemIsMovable, false);
        }
        UpdateInfo(current_figure->scale());
    }
}

void MainWindow::SetRotate(QPointF prev_pos, QPointF curr_pos)
{
    if (ui->Rotate_button->isChecked() && current_figure != nullptr)
    {
        current_figure->setFlag(QGraphicsItem::ItemIsMovable, false);

        qreal angle = current_figure->rotation() + (curr_pos.x() - prev_pos.x()) * 0.1;
        current_figure->setRotation(angle);
    }
}

void MainWindow::SetScale(QPointF prev_pos, QPointF curr_pos)
{
    if (ui->Resize_button->isChecked() && current_figure != nullptr)
    {
        current_figure->setFlag(QGraphicsItem::ItemIsMovable, false);

        qreal scale = current_figure->scale() - (curr_pos.y() - prev_pos.y()) * 0.005;
        if (scale < 0) {
            scale = 0;
        }
        current_figure->setScale(scale);

        UpdateInfo(current_figure->scale());
    }
}

void MainWindow::SetDelete()
{
    if (ui->Delete_button->isChecked() && current_figure != nullptr)
    {
        current_figure->setFlag(QGraphicsItem::ItemIsMovable, false);

        scene->removeItem(current_figure);
        delete current_figure;
        current_figure = nullptr;
    }
}


void MainWindow::on_Choose_cl_clicked()
{
    if (current_figure != nullptr)
    {
        QColor color = QColorDialog::getColor(Qt::white, this, tr("Select color"));
        current_figure->SetBrushColor(color);
    }
}

