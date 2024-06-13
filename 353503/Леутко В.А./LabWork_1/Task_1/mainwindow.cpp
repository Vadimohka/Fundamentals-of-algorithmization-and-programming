#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1500,750);
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(900,725);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // сглаживает границы графических объектов
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // отключает скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // отключает скроллбар по горизонтали
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_square_clicked()
{
    int x = ui->square_x->text().toInt();
    int y = ui->square_y->text().toInt();
    auto *item = new square();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->square_sl->text().toInt();
    item->h = ui->square_sl->text().toInt();
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
    item->btn_fill = ui->btn_fill;
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_triangle_clicked()
{
    auto *item = new triangle();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    QStringList str = ui->triangle_xy->toPlainText().split(" ");
    while (str[str.length()-1].toInt()==0) str.pop_back();
    for (int i = 0;i<str.length();i+=2)
    {
        item->cords.push_back( {str[i].toInt(),str[i+1].toInt()});
    }
    item->initialization();
    item->R = ui->pen_color_R->text().toInt();
    item->G = ui->pen_color_G->text().toInt();
    item->B = ui->pen_color_B->text().toInt();
    item->PenSize = ui->pen_size->text().toInt();
    item->setPos(item->Center.first,item->Center.second);
    item->out_area = ui->area;
    item->out_perimeter = ui->perimeter;
    item->out_centerX = ui->center_x;
    item->out_centerY = ui->center_y;
    item->out_angle = ui->angle;
    item->Tgravity =ui->Tgravity;
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item -> rotate_angle = ui->rotate_angle;
    item -> change_size = ui->size;
    if (str.length()==6)
        scene->addItem(item);
    str.clear();
}

void MainWindow::on_btn_diamond_clicked()
{
    int x = ui->romb_x->text().toInt();
    int y = ui->romb_y->text().toInt();
    auto *item = new diamond();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->romb_d1->text().toInt();
    item->h = ui->romb_d2->text().toInt();
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_hexagon_clicked()
{
    int x = ui->hexagon_x->text().toInt();
    int y = ui->hexagon_y->text().toInt();
    auto *item = new hexagon();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->hexagon_sl->text().toInt();
    item->h = ui->hexagon_sl->text().toInt();
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_star5_clicked()
{
    int x = ui->star5_x->text().toInt();
    int y = ui->star5_y->text().toInt();
    auto *item = new star5();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->star5_r1->text().toInt();
    item->h = ui->star5_r2->text().toInt();
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_star6_clicked()
{
    int x = ui->star6_x->text().toInt();
    int y = ui->star6_y->text().toInt();
    auto *item = new star6();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->star6_r1->text().toInt();
    item->h = ui->star6_r2->text().toInt();
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
    item->btn_fill = ui->btn_fill;
    item->centergravity_x = ui->centergravity_x;
    item->centergravity_y = ui->centergravity_y;
    item->rotate_angle = ui->rotate_angle;
    item->change_size = ui->size;
    item->initialization();
    scene->addItem(item);
}

void MainWindow::on_btn_star8_clicked()
{
    int x = ui->star8_x->text().toInt();
    int y = ui->star8_y->text().toInt();
    auto *item = new star8();
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setPos(x,y);
    item->w = ui->star8_r1->text().toInt();
    item->h = ui->star8_r2->text().toInt();
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
    item->btn_fill = ui->btn_fill;
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

void MainWindow::on_btn_fill_clicked()
{
    ui->btn_fill->setText("No");
}

void MainWindow::on_btn_ResetScene_clicked()
{
    scene ->clear();
    scene->update();
}
