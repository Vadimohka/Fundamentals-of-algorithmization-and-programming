#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1180,750);
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(750,725);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_triangle_clicked()
{
    int x = ui->triangle_x->text().toInt();
    int y = ui->triangle_y->text().toInt();
    auto *item = new trianglee();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->triangle_w->text().toInt();
    item->h = ui->triangle_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_circle_clicked()
{
    int x = ui->circle_x->text().toInt();
    int y = ui->circle_y->text().toInt();
    auto *item = new Circle();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->radius = ui->circle_r->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_sqare_clicked()
{
    int x = ui->sqare_x->text().toInt();
    int y = ui->sqare_y->text().toInt();
    auto *item = new Sqare();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->sqare_w->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_polygon_clicked()
{
    int x = ui->polygon_x->text().toInt();
    int y = ui->polygon_y->text().toInt();
    auto *item = new polygon();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->polygon_w->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_rhombus_clicked()
{
    int x = ui->rhombus_x->text().toInt();
    int y = ui->rhombus_y->text().toInt();
    auto *item = new rhombus();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->rhombus_w->text().toInt();
    item->h = ui->rhombus_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_ellipse_clicked()
{
    int x = ui->ellipse_x->text().toInt();
    int y = ui->ellipse_y->text().toInt();
    auto *item = new ellipse();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->ellipse_w->text().toInt();
    item->h = ui->ellipse_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_star_clicked()
{
    int x = ui->star_x->text().toInt();
    int y = ui->star_y->text().toInt();
    auto *item = new star();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->star_w->text().toInt();
    item->n = ui->star_n->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_btn_rectangle_clicked()
{
    int x = ui->rect_x->text().toInt();
    int y = ui->rect_y->text().toInt();
    auto *item = new rectangle();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->rect_w->text().toInt();
    item->h = ui->rect_h->text().toInt();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity = ui->Tgravity;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}
void MainWindow::on_Tgravity_clicked()
{
    ui->Tgravity->setText("Choose object to move");
}
void MainWindow::on_btn_ResetScene_clicked()
{
    scene ->clear();
    scene->update();
}
