#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "QLineEdit"

constexpr int SMALLEST_WINDOW_BORDER = 50;
constexpr int HIGHEST_WINDOW_BORDER = 2000;
constexpr int SMALLEST_STAR = 3;
constexpr int BIGGEST_STAR = 999;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateScene();

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_paint_button_clicked()
{
    if (ui->W_width->text().toInt() > SMALLEST_WINDOW_BORDER &&
        ui->W_width->text().toInt() < HIGHEST_WINDOW_BORDER &&
        ui->W_height->text().toInt() > SMALLEST_WINDOW_BORDER &&
        ui->W_height->text().toInt() < HIGHEST_WINDOW_BORDER)
    {
        wind = new paintWindow;
        wind->setGeometry(0, 0, ui->W_width->text().toInt(), ui->W_height->text().toInt());
        connect(this, &MainWindow::signal, wind, &paintWindow::getSize);
        emit signal(ui->W_width->text().toInt(), ui->W_height->text().toInt());
        wind->exec();
    }
}

void MainWindow::on_buttRomb_toggled(bool checked)
{
    if (ui->buttRomb->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttRomb;
        tempButt->setEnabled(false);
    }
    emit buttRomb(checked);
}

void MainWindow::on_buttRect_toggled(bool checked)
{
    if (ui->buttRect->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttRect;
        tempButt->setEnabled(false);
    }
    emit buttRect(checked);
}

void MainWindow::on_buttCircle_toggled(bool checked)
{
    if (ui->buttCircle->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttCircle;
        tempButt->setEnabled(false);
    }
    emit buttCircle(checked);
}

void MainWindow::on_buttTriangle_toggled(bool checked)
{
    if (ui->buttTriangle->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttTriangle;
        tempButt->setEnabled(false);
    }
    emit buttTriange(checked);
}

void MainWindow::on_buttSquare_toggled(bool checked)
{
    if (ui->buttSquare->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttSquare;
        tempButt->setEnabled(false);
    }
    emit buttSquare(checked);
}

void MainWindow::on_buttSixStar_toggled(bool checked)
{
    if (ui->buttSixStar->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttSixStar;
        tempButt->setEnabled(false);
    }
    emit buttSixStar(checked);
}

void MainWindow::on_buttStar_toggled(bool checked)
{
    if (ui->buttStar->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttStar;
        tempButt->setEnabled(false);
    }
    emit buttStar(checked);
}

void MainWindow::on_hexagonButt_toggled(bool checked)
{
    if (ui->hexagonButt->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->hexagonButt;
        tempButt->setEnabled(false);
    }
    emit buttHexagon(checked);
}

void MainWindow::on_buttDrag_toggled(bool checked)
{
    if (ui->buttDrag->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttDrag;
        tempButt->setEnabled(false);
    }
    emit buttDrag(checked);
}

void MainWindow::on_buttRotate_toggled(bool checked)
{
    if (ui->buttRotate->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttRotate;
        tempButt->setEnabled(false);
    }
    ui->counterClockwiseButt->setEnabled(checked);
    ui->ClockwiseButt->setEnabled(checked);
    emit buttRotate(checked);
}

void MainWindow::on_buttTransform_toggled(bool checked)
{
    if (ui->buttTransform->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->buttTransform;
        tempButt->setEnabled(false);
    }
    ui->plusButt->setEnabled(checked);
    ui->minusButt->setEnabled(checked);
    emit buttScale(checked);
}

void MainWindow::on_deletItem_toggled(bool checked)
{
    if (ui->deletItem->isChecked())
    {
        emit blankFigure(false);
        tempButt->setEnabled(true);
        tempButt->setChecked(false);
        tempButt = ui->deletItem;
        tempButt->setEnabled(false);
    }
    emit deleteI(checked);
}

void MainWindow::on_buttClear_clicked()
{
    CreateScene();
}

void MainWindow::CreateScene()
{
    scene = new MWscene;
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    connect(this, &MainWindow::blankFigure, scene, &MWscene::blank_checked);
    connect(this, &MainWindow::buttRect, scene, &MWscene::buttRect_checked);
    connect(this, &MainWindow::buttRomb, scene, &MWscene::buttRomb_checked);
    connect(this, &MainWindow::buttCircle, scene, &MWscene::buttCircle_checked);
    connect(this, &MainWindow::buttTriange, scene, &MWscene::buttTriangle_checked);
    connect(this, &MainWindow::buttSquare, scene, &MWscene::buttSquare_checked);
    connect(this, &MainWindow::buttSixStar, scene, &MWscene::buttSixStar_checked);
    connect(this, &MainWindow::buttStar, scene, &MWscene::buttStar_checked);
    connect(this, &MainWindow::buttHexagon, scene, &MWscene::buttHexagon_checked);
    connect(this, &MainWindow::buttDrag, scene, &MWscene::buttDrag_checked);
    connect(this, &MainWindow::buttRotate, scene, &MWscene::buttRotate_checked);
    connect(this, &MainWindow::buttScale, scene, &MWscene::buttScale_checked);
    connect(this, &MainWindow::deleteI, scene, &MWscene::buttDelete_checked);
    connect(this, &MainWindow::scaleFact, scene, &MWscene::getScale);
    connect(this, &MainWindow::rotate, scene, &MWscene::getRotation);
    connect(this, &MainWindow::setCorners, scene, &MWscene::getCorners);

    connect(scene, &MWscene::sendPerimeter, this, &MainWindow::setPerimeterText);
    connect(scene, &MWscene::sendArea, this, &MainWindow::setAreaText);

    tempButt = new QPushButton;
    tempButt->setEnabled(true);
    tempButt->setChecked(false);
    emit blankFigure(true);
}

void MainWindow::on_plusButt_clicked()
{
    emit scaleFact(ui->SetScale->text().toInt());
}

void MainWindow::on_minusButt_clicked()
{
    emit scaleFact(-ui->SetScale->text().toInt());
}

void MainWindow::on_ClockwiseButt_clicked()
{
    emit rotate(ui->SetRotationAngle->text().toInt());
}

void MainWindow::on_counterClockwiseButt_clicked()
{
    emit rotate(-ui->SetRotationAngle->text().toInt());
}

void MainWindow::on_pointEdit_textEdited(const QString &arg1)
{
    if (arg1.toInt() >= SMALLEST_STAR && arg1.toInt() <= BIGGEST_STAR)
    {
        emit setCorners(arg1.toInt());
    }
}

void MainWindow::setPerimeterText(QString str)
{
    ui->perimeterOutput->setText(str);
}

void MainWindow::setAreaText(QString str)
{
    ui->areaOutput->setText(str);
}

