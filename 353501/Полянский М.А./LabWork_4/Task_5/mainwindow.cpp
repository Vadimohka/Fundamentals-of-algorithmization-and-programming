#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);


  firstVector.push_back(12);
  firstVector.push_back(124);
  firstVector.push_back(123151);
  updateFirst();
 

  secondVector.push_back({12, 12.123});
  secondVector.push_back({122312, 31.131});
  secondVector.push_back({87, 12.12});
  updateSecond();

  // 1 table 
  connect(ui->push1, &QPushButton::clicked, [&](){
    firstVector.push_back(getFirVal());
    updateFirst();
  });

  connect(ui->insert1, &QPushButton::clicked, [&](){
    firstVector.insert(getFirRow(), getFirVal());
    updateFirst();
  });
  connect(ui->pop1, &QPushButton::clicked, [&](){
    firstVector.pop_back();
    updateFirst();
  });
  connect(ui->erase1, &QPushButton::clicked, [&](){
    firstVector.erase(getFirRow());
    updateFirst();
  });

  // 2 table
  connect(ui->push2, &QPushButton::clicked, [&](){
    secondVector.push_back(getSecVal());
    updateSecond();
  });
  connect(ui->insert2, &QPushButton::clicked, [&](){
    secondVector.insert(getSecRow(), getSecVal());
    updateSecond();
  });
  connect(ui->pop2, &QPushButton::clicked, [&](){
    secondVector.pop_back();
    updateSecond();
  });
  connect(ui->erase2, &QPushButton::clicked, [&](){
    secondVector.erase(getSecRow());
    updateSecond();
  });
  

  
  
}

void MainWindow::updateFirst(){
  ui->erase1->setEnabled(!firstVector.isEmpty());
  ui->pop1->setEnabled(!firstVector.isEmpty());
  ui->insert1->setEnabled(!firstVector.isEmpty());
  ui->tableWidget->setRowCount(firstVector.size());
  ui->tableWidget->setColumnCount(1);
  int r =0;
  for(auto val: firstVector){
    ui->tableWidget->setItem(r, 0, new QTableWidgetItem(QString::number(val)));
    r++;
  }
}

int MainWindow::getFirVal(){
  return ui->inputF->value();
}

int MainWindow::getFirRow(){
  auto val = ui->tableWidget->selectedItems();
  if(val.isEmpty()){
    return 0;
  }
  return val[0]->row();
}

int MainWindow::getSecRow(){
  auto val = ui->tableWidget_2->selectedItems();
  if(val.isEmpty()){
    return 0;
  }
  return val[0]->row();
}
void MainWindow::updateSecond(){
  ui->erase2->setEnabled(!secondVector.isEmpty());
  if(secondVector.size()<= 1){
    ui->pop2->setEnabled(false);
  }else{
    ui->pop2->setEnabled(true);
  }
  ui->insert2->setEnabled(!secondVector.isEmpty());
  ui->tableWidget_2->setRowCount(secondVector.size());
  ui->tableWidget_2->setColumnCount(2);
  int r =0;
  for(auto val: secondVector){
    ui->tableWidget_2->setItem(r, 0, new QTableWidgetItem(QString::number(val.first)));
    ui->tableWidget_2->setItem(r, 1, new QTableWidgetItem(QString::number(val.second)));
    r++;
  }
}

Pair<int, double> MainWindow::getSecVal(){
  return {ui->spinBox->value(), ui->doubleSpinBox->value()};
}






