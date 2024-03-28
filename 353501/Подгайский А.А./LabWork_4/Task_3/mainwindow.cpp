#include "mainwindow.h"
#include <QLineEdit>
#include <climits>


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->table->setSelectionBehavior(QTableWidget::SelectionBehavior::SelectRows);
  ui->table->setSelectionMode(QTableWidget::SingleSelection);

  ui->table->setColumnCount(2);
  addElement();
  addElement();
  setMedians(0,2);

  ui->table->setHorizontalHeaderItem(0, new QTableWidgetItem("Element"));
  ui->table->setHorizontalHeaderItem(1, new QTableWidgetItem("Median"));

  connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::addElementSlot);
  connect(ui->removeBtn, &QPushButton::clicked, this, &MainWindow::removeElement);
  connect(ui->table, &QTableWidget::cellChanged, this, &MainWindow::changedMedians);
}


void MainWindow::addElement(){
  ui->table->setRowCount(ui->table->rowCount() + 1);

  auto newRow = ui->table->rowCount()-1;
  ui->table->setItem(newRow, 0, new QTableWidgetItem("0"));
  ui->table->setItem(newRow, 1, new QTableWidgetItem({}, Qt::ItemIsSelectable | Qt::ItemIsEnabled));
}

void MainWindow::addElementSlot(){
  addElement();
  setMedians(ui->table->rowCount()-2, ui->table->rowCount());
}


void MainWindow::changedMedians(int row, int column){
  if(column != 0){
    return;
  }

  auto beg = std::max(0,  row-2);
  auto end = std::min(ui->table->rowCount(), row + 2);
  setMedians(beg, end);
}

void MainWindow::removeElement(){
  if(ui->table->rowCount() > 2){
    auto sel = ui->table->currentRow();
    ui->table->removeRow(ui->table->currentRow());
    setMedians( std::max(0, sel-2), std::min(sel+2, ui->table->rowCount()));
  }

}


void MainWindow::setMedians(int beg, int end){
  auto sz = ui->table->rowCount();
  auto medianItemFlag = Qt::ItemIsSelectable |  Qt::ItemIsEnabled;
  for(int i = beg; i < end; ++i){

    QString median_s;

    if(i == 0){

      qreal median; bool ok[2];
      auto n1 = ui->table->item(0, 0)->text().toLong(&ok[0]);
      auto n2 = ui->table->item(1, 0)->text().toLong(&ok[1]);
      if(!ok[0] || !ok[1]){
        median_s = "--";
      } else {
         median = (qreal)(n1 + n2)/2;
        median_s = QString::number(median);
      }

    } else if( i == sz-1 ) {

      qreal median; bool ok[2];
      auto n1 = ui->table->item(sz-1, 0)->text().toLong(&ok[0]);
      auto n2 = ui->table->item(sz-2, 0)->text().toLong(&ok[1]);
      if(!ok[0] || !ok[1]){
        median_s= "--";
      } else {
        median = (qreal)(n1 + n2)/2;
        median_s = QString::number(median);
      }

    } else {
      
      long median; bool ok[3];
      auto n1 = ui->table->item(i-1, 0)->text().toLong(&ok[0]);
      auto n2 = ui->table->item(i, 0)->text().toLong(&ok[1]);
      auto n3 = ui->table->item(i+1, 0)->text().toLong(&ok[2]);

      if(!ok[0] || !ok[1] || !ok[2]){
        median_s  = "--";
      } else {

        if(n1 > n2){
          std::swap(n1, n2);
        }
        if(n2 > n3){
          std::swap(n2, n3);
        }
        if(n1 > n2){
          std::swap(n1, n2);
        }

        median_s = QString::number(n2);

      }
    }

    ui->table->setItem(i, 1, new QTableWidgetItem(median_s, medianItemFlag));
  }
}