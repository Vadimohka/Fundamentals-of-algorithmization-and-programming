#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    for(int i=0;i<100;++i){

        a[i]=  (powf(2,(10*i+1+i)%7))*3;



    }
   cc->sorting_q(a,0,100-1);

    for(int i=0;i<100;++i){
        double kk=i;
        QGraphicsRectItem *ll1=new QGraphicsRectItem(50+kk*10,-a[i],5,a[i]);

        t1.append(ll1);

        scene->addItem(t1[i]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::inter(double*a,int low,int high,double x){
    int pos;

    ui->graphicsView->viewport()->repaint();
    for(int i=low;i<high+1;++i){

        scene->addItem(t1[i]);

    }
    for(long long i=0;i<1000;++i){
        ui->graphicsView->viewport()->repaint();
    }
    if (low <= high && x >= a[low] && x <= a[high]) {

        pos = low+ (((double)(high - low) / (a[high] - a[low]))* (x - a[low]));

        if (a[pos] == x){
            for(int i=low;i<high+1;++i){
                scene->removeItem(t1[i]);
            }
             scene->addItem(t1[pos]);
            for(long long i=0;i<100;++i){
                ui->graphicsView->viewport()->repaint();
            }
            return pos;
        }

        if (a[pos] < x){
            for(int i=low;i<high+1;++i){
                scene->removeItem(t1[i]);
            }
            return inter(a, pos + 1, high, x);}

        if (a[pos] > x){
                for(int i=low;i<high+1;++i){
                    scene->removeItem(t1[i]);
                }
            return inter(a, low, pos - 1, x);
        }
    }
    return -1;



}
void MainWindow::on_pushButton_clicked()
{


    inter(a,0,100-1,a[25]);
}

