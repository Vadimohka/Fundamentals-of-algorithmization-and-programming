#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->create->setChecked(true);
    ui->treug->setChecked(true);
    ui->Per_O->setText("0");
    ui->Sq_O->setText("0");
    ui->Coord_O->setText(QString("x: 0 y: 0"));
    ui->myPoints->hide();
    ui->label_2->setText(QString("Now you can size -"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *pe){
    Q_UNUSED(pe);
    QPainter painter(this);
    if(fgr != nullptr)
    {
        fgr->Draw(&painter);
        ui->Per_O->setText(QString::number(fgr->GetP()));
        ui->Sq_O->setText(QString::number(fgr->GetS()));
        ui->Coord_O->setText(QString("x: ") + QString::number(fgr->GetCenter().x()) + QString(" y: ") + QString::number(fgr->GetCenter().y()));
        if (ui->my->isChecked()){
            ui->myPoints->setText(QString::number(pointsMax - pointsNum) + QString("points left"));
        } else {
            ui->myPoints->hide();
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *pe)
{
    int cx = pe->position().x();
    int cy = pe->position().y();

    MouseClick = pe->position();

    if (ui->create->isChecked()){

        if(fgr != nullptr)
        {
            delete fgr;
            fgr = nullptr;
        }

        if (ui->treug->isChecked()){
            fgr = new Triang(cx, cy, 0, 0);
        }
        else if (ui->krug->isChecked()){
            fgr = new Circle(cx, cy, 0, 0);
        }
        else if (ui->romb->isChecked()){
            fgr = new Romb(cx, cy, 0, 0);
        }
        else if (ui->kvadr->isChecked()){
            fgr = new Kvadr(cx, cy, 0, 0);
        }
        else if (ui->pramouh->isChecked()){
            fgr = new Pramouh(cx, cy, 0, 0);
        }
        else if (ui->zvezda->isChecked()){
            if (ui->zvezda_comboBox->currentIndex() == 0) {
                fgr = new Star_5(cx, cy, 0, 0);
            } else if (ui->zvezda_comboBox->currentIndex() == 1){
                fgr = new Star_6(cx, cy, 0, 0);
            } else if (ui->zvezda_comboBox->currentIndex() == 2){
                fgr = new Star_8(cx, cy, 0, 0);
            }
        }
        else if (ui->shestiuh->isChecked()){
            fgr = new Shestiuh(cx, cy, 0, 0);
        }
        else if (ui->my->isChecked()){
            pointsNum = 0;
            fgr = new MyLine(cx, cy, 0, 0);
            ++pointsNum;
        }
    }
    touch = -1;
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *me){
    block = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *me)
{
    if (fgr!= nullptr && !block)
    {
        if (ui->create->isChecked())
         {
             if (ui->krug->isChecked()){
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->CountP();
                fgr->CountS();
             }
            else if (ui->treug->isChecked()){
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->CountP();
                fgr->CountS();
            } else if (ui->pramouh->isChecked()){
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->CountP();
                fgr->CountS();
            } else if (ui->kvadr->isChecked()){
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->CountP();
                fgr->CountS();
            } else if (ui->shestiuh->isChecked()){
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->CountP();
                fgr->CountS();
            } else if (ui->my->isChecked() && pointsNum < pointsMax){
                auto a = fgr->GetPolyg();
                fgr->PlusAng();
                a.push_back(me->position());
                fgr->SetPolyg(a);
                fgr->CountCenter();
                fgr->CountP();
                fgr->CountS();
                ++pointsNum;
            } else if (ui->romb->isChecked()){
                fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                fgr->CountP();
                fgr->CountS();
            } else if (ui->zvezda->isChecked()){
                if (ui->zvezda_comboBox->currentIndex() == 0) {
                    fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                    fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                    fgr->CountP();
                    fgr->CountS();
                } else if (ui->zvezda_comboBox->currentIndex() == 1){
                    fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                    fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                    fgr->CountP();
                    fgr->CountS();
                } else if (ui->zvezda_comboBox->currentIndex() == 2){
                    fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
                    fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
                    fgr->CountP();
                    fgr->CountS();
                }
            }
        } else if (ui->move->isChecked()) {
            fgr->SetCenter(fgr->GetCenter().x() + me->pos().x() - MouseClick.x(), fgr->GetCenter().y() + me->pos().y() - MouseClick.y());
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100000000);
        } else if (ui->change->isChecked()) {
                if (fgr->GetCountOfAngles() != 0){
                QVector<QPointF> polyg = fgr->GetPolyg();
                if (touch != -1)
                    polyg[touch] = QPointF(polyg[touch].x() + me->pos().x() - MouseClick.x(), polyg[touch].y() + me->pos().y() - MouseClick.y());
                else
                    for(int i = 0; i<fgr->GetCountOfAngles(); i++){
                        if((touch == i)||((polyg[i].x() + 5> me->position().x() && polyg[i].x() - 5 < me->position().x()) && (polyg[i].y() + 5 > me->position().y() && polyg[i].y() - 5 < me->position().y())))
                        {
                            polyg[i] = QPointF(polyg[i].x() + me->pos().x() - MouseClick.x(), polyg[i].y() + me->pos().y() - MouseClick.y());
                            touch = i;
                            break;
                        }
                    }
                fgr->SetPolyg(polyg);
                fgr->CountCenter();
                } else {
                    fgr->SetWidth(fgr->GetWidth() + me->pos().x() - MouseClick.x());
                }
        }

    }
    MouseClick = me->position();
    update();
}

void MainWindow::on_pushButton_15_pressed() //rot left
{
    if (fgr!= nullptr)
        while (ui->pushButton_15->isDown()){
            block = true;
            fgr->Rotate(-0.01);
            update();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100000000);
            }
}

void MainWindow::on_pushButton_16_pressed() //rot right
{
    if (fgr!= nullptr)
        while (ui->pushButton_16->isDown()){
            block = true;
            fgr->Rotate(0.01);
            update();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100000000);
        }
}

void MainWindow::on_pushButton_26_pressed() //size +
{
    if (fgr!= nullptr)
        while (ui->pushButton_26->isDown()){
            block = true;
            ui->label_2->setText(QString("Now you can size -"));
            fgr->Resize(true);
            fgr->CountP();
            fgr->CountS();
            update();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100000000);
        }
}

void MainWindow::on_pushButton_27_pressed() //size -
{
    if (fgr!= nullptr){
        while (ui->pushButton_27->isDown() && fgr->GetP() >= 0.01){
            block = true;
            fgr->Resize(false);
            fgr->CountP();
            fgr->CountS();
            if (fgr->GetP() <= 0.01){
                ui->label_2->setText(QString("Now you cant size -"));
                break;
            }
            else{
                ui->label_2->setText(QString("Now you can size -"));
            }
            update();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
        }

    }

}



void MainWindow::on_my_clicked(bool checked)
{
    if (checked){
        ui->myPoints->show();
        pointsNum = 0;

    }
}


void MainWindow::on_pushButton_15_clicked(bool checked)
{
    if (!checked){
        block = false;
    }
}

void MainWindow::on_pushButton_16_clicked(bool checked)
{
    if (!checked)
        block = false;
}

void MainWindow::on_pushButton_26_clicked(bool checked)
{
    if (!checked)
        block = false;
}

void MainWindow::on_pushButton_27_clicked(bool checked)
{
    if (!checked)
        block = false;
}

