#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qplaintextedit.h>
#include <qtextedit.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  sou = ui->s1str;
  tar = ui->s2str;
  
}

 void MainWindow::setOutput(int n){
  ui->noutput->setText(QString::number(n));
 }

 void MainWindow::setTarget(const char* c){
  QString s{c};
  tar->setText(s);
 }

void MainWindow::setSource(const char* c){
  QString s {c};
  sou->setText(s);
 }


void MainWindow::on_chkbox_toggled(bool st){
  qDebug() << "check!";
  if(st){
    sou = ui->s2str;
    tar = ui->s1str;
  } else {
    sou = ui->s1str;
    tar = ui->s2str;
  }
}


void MainWindow::on_scmp_clicked(){
  auto s1 = sou->text().toStdString();
  auto s2 = sou->text().toStdString();
  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};
  int o = strcmp(p.first, p.second);
  setOutput(o);
}
  void MainWindow::on_scoll_clicked(){
    on_scmp_clicked();
  }


  void MainWindow::on_scpy_clicked(){
    auto s1 = sou->text().toStdString();
  auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    strcpy(n, p.first);
    qDebug() << p.first;
    qDebug() << n;
    setTarget(n);
    delete[] n;
  }


  void MainWindow::on_sncpy_clicked(){
    auto s1 = sou->text().toStdString();
  auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    strncpy(n, p.second, ui->Nbox->value());
    setTarget(n);
    delete[] n;
  }



  void MainWindow::on_scat_clicked(){
  auto s1 = sou->text().toStdString();
  auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    strcpy(n, p.second);
    strcat(n, p.first);
    setTarget(n);
    delete[] n;
  }


  void MainWindow::on_sncat_clicked(){
    auto s1 = sou->text().toStdString();
    auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    strcpy(n, p.second);
    strncat(n, p.first, ui->Nbox->value());
    setTarget(n);
    delete[] n;
  }

  void MainWindow::on_slen_clicked(){
     auto s1 = sou->text().toStdString();
  auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    int outp = strlen(p.second);
    setOutput(outp);
  }


  void MainWindow::on_stok_clicked(){

    auto s1 = sou->text().toStdString();
    auto s2 = tar->text().toStdString();

    auto c1 = s1.c_str();
    auto c2 = s2.c_str();
    QPair<const char*, const char*> p = {c1, c2};

    //kill me pls
    char * src = new char[s1.size() + 2038];
    strcpy(src, p.second);

    char * dst = new char[s2.size() + 1024];
    *dst = '\0';
    char* token = strtok(src, p.first);
    while (token != NULL) {
      strcat(dst, token);
      token = strtok(NULL, p.first);
      strcat(dst, " | ");
    }

    // int a = my_strlen(dst);
    // dst[a-3]='\0';
    
    setTarget(dst);

    delete[] dst;
    delete[] src;
}


  void MainWindow::on_strxfrm_clicked(){
    on_scpy_clicked();
  }

  void MainWindow::on_sncmp_clicked(){
  auto s1 = sou->text().toStdString();
  auto s2 = tar->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};
    int outp = strncmp(p.first, p.second, ui->Nbox->value());
    setOutput(outp);
  }

