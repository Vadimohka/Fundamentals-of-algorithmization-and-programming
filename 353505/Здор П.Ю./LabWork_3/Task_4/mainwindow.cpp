#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(sc);
    sc->addRect(-50, -100, 5, 250);
    sc->addRect(125, -100, 5, 250);
    sc->addRect(275, -100, 5, 250);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
  ui->tableWidget->removeColumn(0);
      ui->tableWidget->removeColumn(0);
    while(ui->tableWidget->rowCount()>0){
        ui->tableWidget->removeRow(0);
    }
    ui-> tableWidget->setColumnCount(1);
    ui->tableWidget->setColumnWidth(0,200);

    h=new hanoi;
    h->hanoi_solver(arg1,'A','B','C',ui->tableWidget);
    t=arg1;
    fl1=1;
    create();


}
void MainWindow::create(){
    if(fl1){
        t1.clear();
        sc->clear();
        sc->addRect(-50, -100, 5, 250);
        sc->addRect(125, -100, 5, 250);
        sc->addRect(275, -100, 5, 250);
    for(int i=0;i<t;++i){
      QGraphicsRectItem *ll1=new QGraphicsRectItem(-65+i,140-10*i,35-2*i,10);
        ll1->setBrush(QColor(255-16*i,255-10*i,255-10*i));
         sc->addItem(ll1);
        t1.append(ll1);
    }
    A=-t*10;
    t2=t1;
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    A=0;
    B=0;
    C=0;
    create();
    for(int i=0;i<=row;++i){

        QTableWidgetItem *p=ui->tableWidget->item(i,0);
        QString h=p->text();
        int ac=h[10].unicode()-48;
        if(h[11]!=' ') ac=ac*10+h[11].unicode();
        if(h[h.size()-1]=='C' && h[h.size()-6]=='A'){
            t1[t1.size()-ac]->setPos(325,C+10*(t1.size()-ac));
            A+=10;
            C-=10;
            sc->update();
        }
        else if(h[h.size()-1]=='C' && h[h.size()-6]=='B') {
            t1[t1.size()-ac]->setPos(325,C+10*(t1.size()-ac));
            C-=10;
            B+=10;
            sc->update();
        }
        else if(h[h.size()-1]=='B' && h[h.size()-6]=='A') {
            t1[t1.size()-ac]->setPos(175,B+10*(t1.size()-ac));
            B-=10;
            A+=10;
            sc->update();
        }
        else if(h[h.size()-1]=='B' && h[h.size()-6]=='C'){
            t1[t1.size()-ac]->setPos(175,B+10*(t1.size()-ac));
            B-=10;
            C+=10;
            sc->update();
        }
        else if(h[h.size()-1]=='A' && h[h.size()-6]=='B'){
            t1[t1.size()-ac]->setPos(0,A+10*(t1.size()-ac));
            A-=10;
            B+=10;
            sc->update();
        }
        else if(h[h.size()-1]=='A' && h[h.size()-6]=='C'){
            t1[t1.size()-ac]->setPos(0,A+10*(t1.size()-ac));
            A-=10;
            C+=10;
            sc->update();
        }
    }
}

