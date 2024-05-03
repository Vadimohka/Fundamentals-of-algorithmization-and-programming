#include "mainwindow.h"
#include "mycstring.h"
#include "ui_mainwindow.h"
#include <cstddef>
#include <cstring>
#include <qcheckbox.h>
#include <qdebug.h>
#include <qnamespace.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
   ui->setupUi(this); 
   source = ui->s1str;
   target = ui->s2str;
}


void MainWindow::on_chkBox_toggled(bool st){
  qDebug() << "check!";
  if(st){
    source = ui->s2str;
    target = ui->s1str;
  } else {
    source = ui->s1str;
    target = ui->s2str;
  }
}


MainWindow::~MainWindow(){
  delete ui;
}

 void MainWindow::setOutput(int n){
  ui->noutput->setText(QString::number(n));
 }

 void MainWindow::setTarget(const char* c){
  QString s{c};
  target->setText(s);
 }

  void MainWindow::setSource(const char* c){
  QString s {c};
  source->setText(s);
 }



  void MainWindow::on_scmp_clicked(){
    auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    int outp = my_strcmp(p.first, p.second);
    setOutput(outp);
  }


  void MainWindow::on_sncmp_clicked(){
  auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};
    int outp = my_strncmp(p.first, p.second, ui->NSBox->value());
    setOutput(outp);
  }


  void MainWindow::on_scoll_clicked(){
    on_scmp_clicked();
  }


  void MainWindow::on_scpy_clicked(){
    auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    my_strcpy(n, p.first);
    qDebug() << p.first;
    qDebug() << n;
    setTarget(n);
    delete[] n;
  }


  void MainWindow::on_sncpy_clicked(){
    auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    my_strncpy(n, p.second, ui->NSBox->value());
    setTarget(n);
    delete[] n;
  }



  void MainWindow::on_scat_clicked(){
  auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    my_strcpy(n, p.second);
    my_strcat(n, p.first);
    setTarget(n);
    delete[] n;
  }


  void MainWindow::on_sncat_clicked(){
    auto s1 = source->text().toStdString();
    auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    char* n = new char[s1.size() + s2.size() + 16];
    my_strcpy(n, p.second);
    my_strncat(n, p.first, ui->NSBox->value());
    setTarget(n);
    delete[] n;
  }

  void MainWindow::on_slen_clicked(){
     auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};

    int outp = my_strlen(p.second);
    setOutput(outp);
  }


  void MainWindow::on_stok_clicked(){

    auto s1 = source->text().toStdString();
    auto s2 = target->text().toStdString();

    auto c1 = s1.c_str();
    auto c2 = s2.c_str();
    QPair<const char*, const char*> p = {c1, c2};

    //kill me pls
    char * src = new char[s1.size() + 2038];
    my_strcpy(src, p.second);

    char * dst = new char[s2.size() + 1024];
    *dst = '\0';
    char* token = my_strtok(src, p.first);
    while (token != NULL) {
      my_strcat(dst, token);
      token = my_strtok(NULL, p.first);
      my_strcat(dst, " | ");
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


  void MainWindow::on_serr_clicked(){
     auto s1 = source->text().toStdString();
  auto s2 = target->text().toStdString();

  auto c1 = s1.c_str();
  auto c2 = s2.c_str();
  QPair<const char*, const char*> p = {c1, c2};


    auto output = my_strerror(ui->errnoSBox->value());
    if(output){
      setTarget(output);
    } else {
      setTarget("-- no such error --");
    }
  }