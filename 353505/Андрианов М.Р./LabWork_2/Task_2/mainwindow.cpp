#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->pushButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    sch=0;
    pos=0;
    aa=a->openfile();
    while(a->check(aa,sch)){
        c[sch%6]=a->readFromFile(aa,sch);
        sch++;

        if(sch%6==0 && sch>=6){
            data[pos].cr(c);
            pos++;
            for(int i=0;i<6;++i){
                ui->textEdit->insertPlainText(c[i]+"\n");
            }

        }
    }

}

void MainWindow::on_pushButton_clicked()
{

    if(c1[0].length()!=0 &&c1[1].length()!=0&& c1[2].length()!=0 && c1[3].length()!=0 && c1[3].length()!=0 && c1[4].length()!=0 && c1[5].length()!=0){
        if(aa.length()!=0){

            for(int i=0;i<6;++i){
                a->writeIntoFile(aa,c1[i]);
                ui->textEdit->insertPlainText(c1[i]+"\n");
            }
        }
        else {
            QMessageBox::critical(nullptr,"Error","Please open a file");
        }
    }
    else {
        QMessageBox::critical(nullptr,"Error","Please enter all information");
    }
}


void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    fl2=0;
    QString p=arg1;
    if(p.length()>=10){
        if((a->check_str(p))){
            fl2=1;
            c1[4]=arg1;
            if(fl2 && fl1){
                ui->pushButton->setHidden(false);
                return;
            }
        }
        else if(p.length()!=0 && p.length()>=10){

            QMessageBox::critical(nullptr,"Error","Error appeared");
            ui->lineEdit_5->clear();
        }
    }
}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    QString p=arg1;
    if(p.length()>0){
        fl1=0;
        for(int i=0;i<p.length();++i){
            if(arg1[i]<'0' || arg1[i]>'9') {
                QMessageBox::critical(nullptr,"Error","Error appeared");
                ui->lineEdit_6->clear();
                break;
            }
            if(i==p.length()-1) {
                c1[5]=arg1;
                fl1=1;
            }
        }
        if(fl2 && fl1){
            ui->pushButton->setHidden(false);
        }
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    c1[0]=arg1;
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    c1[1]=arg1;
}


void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    c1[2]=arg1;
}


void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    c1[3]=arg1;
}



void MainWindow::on_pushButton_5_clicked()
{
    aa=a->openfile();
    QString search;
    bool ok;
    search=QInputDialog::getText(nullptr,"Enterind a string","Enter a name",QLineEdit::Normal,"",&ok);
    if(ok && !search.isEmpty()){
        sch=0;
        pos=0;
        while(a->check(aa,sch)){
            c[sch%6]=a->readFromFile(aa,sch);
            sch++;
            if(sch%6==0 && sch>=6){
                data[pos].cr(c);
                pos++;
            }
        }
        for(int i=0;i<pos;++i){
            if(data[i].check(search)!=""){
                for(int t=0;t<6;++t){
                    c[t]=data[i].ret(t);
                    ui->textEdit->insertPlainText(c[t]+"\n");
                }
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    aa=a->openfile();

    bool ok=1;
    if(ok){
        sch=0;
        pos=0;
        while(a->check(aa,sch)){
            c[sch%6]=a->readFromFile(aa,sch);
            sch++;
            if(sch%6==0 && sch>=6){
                data[pos].cr(c);
                pos++;
            }
        }
        for(int i=0;i<pos;++i){
            if(data[i].checker("31.04.2024")!=""){
                for(int t=0;t<6;++t){
                    c[t]=data[i].ret(t);
                    ui->textEdit->insertPlainText(c[t]+"\n");
                }
            }
        }
    }
}
