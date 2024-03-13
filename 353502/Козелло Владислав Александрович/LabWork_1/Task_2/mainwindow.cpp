#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit3_x, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEdit3_y, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEdit4_x, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEdit4_y, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEdit5_x, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEdit5_y, SIGNAL(editingFinished()), this, SLOT(on_lineEditXY_editingFinished()));
    connect(ui->lineEditPar1, SIGNAL(editingFinished()), this, SLOT(on_lineEditPar_editingFinished()));
    connect(ui->lineEditPar2, SIGNAL(editingFinished()), this, SLOT(on_lineEditPar_editingFinished()));

    figure = new Figures*[MAX_FIGURES];
    timer = new QTimer;

    figure[count] = new Rectangle;

    ui->label1->hide();
    ui->label2->hide();
    ui->lineEditPar1->hide();
    ui->lineEditPar2->hide();
    ui->groupBox_coord->hide();
    ui->groupBox_par->hide();
    ui->figureLabel->clear();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event) {
    if(isPaint)
    {
        figure[selected]->mousePress(event);
        update();
    }
    else
    {
        figure[selected]->mouseDragPress(event);
    }
    showData();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(isPaint)
    {
        if(figure[selected]->getFlag() != 6)
            figure[selected]->mouseMove(event);
    }
    else
    {
        figure[selected]->mouseDragMove(event);
    }
    update();
    showData();
}


void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{

}


void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter* painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    for(int i = 0; i < count; i++)
    {
        figure[i]->create(painter);
    }
    painter->end();
}


void MainWindow::on_drawButton_clicked()
{
    if(isPaint)
    {
        isPaint = false;
        ui->drawButton->setText("↔");
    }
    else
    {
        isPaint = true;
        ui->drawButton->setText("✎");
    }
}


void MainWindow::on_squareButton_clicked()
{
    update();
    selected = count;
    figure[count] = new Square;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->label2->hide();
    ui->lineEditPar2->hide();
    ui->groupBox_coord->hide();
    ui->label1->setText("Сторона");
    ui->figureLabel->setText("Квадрат");
    ui->label1->show();
    ui->lineEditPar1->show();
}


void MainWindow::on_rectButton_clicked()
{
    update();
    selected = count;
    figure[count] = new Rectangle;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->groupBox_coord->hide();
    ui->label1->setText("Сторона 1");
    ui->label2->setText("Сторона 2");
    ui->figureLabel->setText("Прямоугольник");
    ui->label1->show();
    ui->label2->show();
    ui->lineEditPar1->show();
    ui->lineEditPar2->show();
}


void MainWindow::on_circleButton_clicked()
{
    update();
    selected = count;
    figure[count] = new Circle;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->label2->hide();
    ui->lineEditPar2->hide();
    ui->groupBox_coord->hide();
    ui->label1->setText("Радиус");
    ui->figureLabel->setText("Круг");
    ui->label1->show();
    ui->lineEditPar1->show();
}


void MainWindow::on_Rhombbutton_clicked()
{
    update();
    selected = count;
    figure[count] = new Rhomb;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->groupBox_coord->hide();
    ui->label1->setText("Сторона");
    ui->label2->setText("Угол⤒");
    ui->figureLabel->setText("Ромб");
    ui->label1->show();
    ui->label2->show();
    ui->lineEditPar1->show();
    ui->lineEditPar2->show();
}


void MainWindow::on_HexButton_clicked()
{
    update();
    selected = count;
    figure[count] = new Hexagon;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->label2->hide();
    ui->lineEditPar2->hide();
    ui->groupBox_coord->hide();
    ui->label1->setText("Сторона");
    ui->figureLabel->setText("Шестиугольник");
    ui->label1->show();
    ui->lineEditPar1->show();
}


void MainWindow::on_trianglebutton_clicked()
{
    update();
    selected = count;
    figure[count] = new Triangle;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->figureLabel->setText("Треугольник");
    ui->groupBox_coord->show();
    ui->groupBox_par->hide();
}


void MainWindow::on_starButton_5_clicked()
{
    update();
    selected = count;
    figure[count] = new Star5;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->groupBox_coord->hide();
    ui->label1->setText("Малый радиус");
    ui->label2->setText("Больший радиус");
    ui->figureLabel->setText("Пятиконечная звезда");
    ui->label1->show();
    ui->label2->show();
    ui->lineEditPar1->show();
    ui->lineEditPar2->show();
}


void MainWindow::on_starButton_6_clicked()
{
    update();
    selected = count;
    figure[count] = new Star6;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->groupBox_coord->hide();
    ui->label1->setText("Малый радиус");
    ui->label2->setText("Больший радиус");
    ui->figureLabel->setText("Шестиконечная звезда");
    ui->label1->show();
    ui->label2->show();
    ui->lineEditPar1->show();
    ui->lineEditPar2->show();
}


void MainWindow::on_starButton_8_clicked()
{
    update();
    selected = count;
    figure[count] = new Star8;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->groupBox_coord->hide();
    ui->label1->setText("Малый радиус");
    ui->label2->setText("Больший радиус");
    ui->figureLabel->setText("Восьмиконечная звезда");
    ui->label1->show();
    ui->label2->show();
    ui->lineEditPar1->show();
    ui->lineEditPar2->show();
}


void MainWindow::on_octbutton_clicked()
{
    update();
    selected = count;
    figure[count] = new Octagon;
    if(count < MAX_FIGURES - 1)
        count++;
    ui->groupBox_par->show();
    ui->label2->hide();
    ui->lineEditPar2->hide();
    ui->groupBox_coord->hide();
    ui->label1->setText("Сторона");
    ui->figureLabel->setText("Восьмиугольник");
    ui->label1->show();
    ui->lineEditPar1->show();
}


void MainWindow::on_plusButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(resizePlus()));
    timer->start(10);
}


void MainWindow::on_minusbutton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(resizeMinus()));
    timer->start(10);
}


void MainWindow::on_plusButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(resizePlus()));
    timer->stop();
}


void MainWindow::on_minusbutton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(resizeMinus()));
    timer->stop();
}


void MainWindow::resizePlus()
{
    figure[selected]->resizePlus();
    update();
    showData();
}


void MainWindow::resizeMinus()
{
    figure[selected]->resizeMinus();
    update();
    showData();
}

void MainWindow::on_lineCenterX_editingFinished()
{
    QString buf = ui->lineCenterX->text();
    if(isDigit(buf))
    {
        figure[selected]->setCenterPoint(buf.toDouble(), figure[selected]->getCenterPoint().y());
        update();
    }
    showData();
}


void MainWindow::on_lineCenterY_editingFinished()
{
    QString buf = ui->lineCenterY->text();
    if(isDigit(buf))
    {
        figure[selected]->setCenterPoint(figure[selected]->getCenterPoint().x(), buf.toDouble());
        update();
    }
    showData();
}

bool MainWindow::isDigit(QString str)
{
    bool isDot = false;
    if(str.isEmpty())
        return false;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' &&
            str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '0')
        {
            if(str[i] == '.' && isDot == false)
            {
                isDot = true;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}


void MainWindow::rotateR()
{
    figure[selected]->rotateRight();
    update();
}


void MainWindow::rotateL()
{
    figure[selected]->rotateLeft();
    update();
}


void MainWindow::on_rotateLButton_pressed()
{
    if(figure[selected]->getFlag() != 3)
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(rotateL()));
        timer->start(5);
    }
}


void MainWindow::on_rotateLButton_released()
{
    if(figure[selected]->getFlag() != 3)
    {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateL()));
        timer->stop();
    }
}


void MainWindow::on_rotateRButton_pressed()
{
    if(figure[selected]->getFlag() != 3)
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(rotateR()));
        timer->start(5);
    }
}


void MainWindow::on_rotateRButton_released()
{
    if(figure[selected]->getFlag() != 3)
    {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateR()));
        timer->stop();
    }
}


void MainWindow::showData()
{
    ui->lineCenterX->setText(QString::number(figure[selected]->getCenterPoint().x()));
    ui->lineCenterY->setText(QString::number(figure[selected]->getCenterPoint().y()));
    ui->labelPerimetr->setText(QString::number(figure[selected]->getPerimetr()));
    ui->labelSquare->setText(QString::number(figure[selected]->getSquare()));
}


void MainWindow::on_lineEditXY_editingFinished()
{
    QString buf;
    if(isDigit(ui->lineEdit3_x->text()))
    {
        buf = ui->lineEdit3_x->text();
        figure[selected]->setNewPoints(buf.toDouble(), 1);
    }
    else if(isDigit(ui->lineEdit3_y->text()))
    {
        buf = ui->lineEdit3_y->text();
        figure[selected]->setNewPoints(buf.toDouble(), 2);
    }
    else if(isDigit(ui->lineEdit4_x->text()))
    {
        buf = ui->lineEdit4_x->text();
        figure[selected]->setNewPoints(buf.toDouble(), 3);
    }
    else if(isDigit(ui->lineEdit4_y->text()))
    {
        buf = ui->lineEdit4_y->text();
        figure[selected]->setNewPoints(buf.toDouble(), 4);
    }
    else if(isDigit(ui->lineEdit5_x->text()))
    {
        buf = ui->lineEdit5_x->text();
        figure[selected]->setNewPoints(buf.toDouble(), 5);
    }
    else if(isDigit(ui->lineEdit5_y->text()))
    {
        buf = ui->lineEdit5_y->text();
        figure[selected]->setNewPoints(buf.toDouble(), 6);
    }

    ui->lineEdit3_x->clear();
    ui->lineEdit3_y->clear();
    ui->lineEdit4_x->clear();
    ui->lineEdit4_y->clear();
    ui->lineEdit5_x->clear();
    ui->lineEdit5_y->clear();
    update();
    showData();
}


void MainWindow::on_lineEditPar_editingFinished()
{
    QString buf1, buf2;
    if(isDigit(ui->lineEditPar1->text()))
    {
        buf1 = ui->lineEditPar1->text();
        figure[selected]->setParameters(buf1.toDouble(), 1);
    }
    else if(isDigit(ui->lineEditPar2->text()))
    {
        buf2 = ui->lineEditPar2->text();
        figure[selected]->setParameters(buf2.toDouble(), 2);
    }
    ui->lineEditPar2->clear();
    ui->lineEditPar1->clear();
    update();
    showData();
}

void MainWindow::on_leftButton_clicked()
{
    if(selected > 0)
        selected--;
    showPar();
    showData();
    update();
}


void MainWindow::on_rightButton_clicked()
{
    if(selected < count - 1)
        selected++;
    showPar();
    showData();
    update();
}


void MainWindow::on_deleteButton_clicked()
{
    if(count != 0)
    {
        figure[count - 1]->clear();
        count--;
        if(selected == count && count != 0)
            selected--;

    }
    showPar();
    showData();
    update();
}

void MainWindow::showPar()
{
    switch(figure[selected]->getFlag())
    {
    case 1:
        ui->groupBox_par->show();
        ui->label2->hide();
        ui->lineEditPar2->hide();
        ui->groupBox_coord->hide();
        ui->label1->setText("Сторона");
        ui->figureLabel->setText("Квадрат");
        ui->label1->show();
        ui->lineEditPar1->show();
        break;
    case 2:
        ui->groupBox_par->show();
        ui->groupBox_coord->hide();
        ui->label1->setText("Сторона 1");
        ui->label2->setText("Сторона 2");
        ui->figureLabel->setText("Прямоугольник");
        ui->label1->show();
        ui->label2->show();
        ui->lineEditPar1->show();
        ui->lineEditPar2->show();
        break;
    case 3:
        ui->groupBox_par->show();
        ui->label2->hide();
        ui->lineEditPar2->hide();
        ui->groupBox_coord->hide();
        ui->label1->setText("Радиус");
        ui->figureLabel->setText("Круг");
        ui->label1->show();
        ui->lineEditPar1->show();
        break;
    case 4:
        ui->groupBox_par->show();
        ui->groupBox_coord->hide();
        ui->label1->setText("Сторона");
        ui->label2->setText("Угол⤒");
        ui->figureLabel->setText("Ромб");
        ui->label1->show();
        ui->label2->show();
        ui->lineEditPar1->show();
        ui->lineEditPar2->show();
        break;
    case 5:
        ui->groupBox_par->show();
        ui->label2->hide();
        ui->lineEditPar2->hide();
        ui->groupBox_coord->hide();
        ui->label1->setText("Сторона");
        ui->figureLabel->setText("Шестиугольник");
        ui->label1->show();
        ui->lineEditPar1->show();
        break;
    case 6:
        ui->groupBox_coord->show();
        ui->groupBox_par->hide();
        ui->figureLabel->setText("Треугольник");
        break;
    case 7:
        ui->groupBox_par->show();
        ui->groupBox_coord->hide();
        ui->label1->setText("Малый радиус");
        ui->label2->setText("Больший радиус");
        ui->figureLabel->setText("Пятиконечная звезда");
        ui->label1->show();
        ui->label2->show();
        ui->lineEditPar1->show();
        ui->lineEditPar2->show();
        break;
    case 8:
        ui->groupBox_par->show();
        ui->groupBox_coord->hide();
        ui->label1->setText("Малый радиус");
        ui->label2->setText("Больший радиус");
        ui->figureLabel->setText("Шестиконечная звезда");
        ui->label1->show();
        ui->label2->show();
        ui->lineEditPar1->show();
        ui->lineEditPar2->show();
        break;
    case 9:
        ui->groupBox_par->show();
        ui->groupBox_coord->hide();
        ui->label1->setText("Малый радиус");
        ui->label2->setText("Больший радиус");
        ui->figureLabel->setText("Восьмиконечная звезда");
        ui->label1->show();
        ui->label2->show();
        ui->lineEditPar1->show();
        ui->lineEditPar2->show();
        break;
    case 10:
        ui->groupBox_par->show();
        ui->label2->hide();
        ui->lineEditPar2->hide();
        ui->groupBox_coord->hide();
        ui->label1->setText("Сторона");
        ui->figureLabel->setText("Восьмиугольник");
        ui->label1->show();
        ui->lineEditPar1->show();
        break;
    }
}
