#include "mainwindow.h"
#include "PlotBuilder.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qchartview.h>
#include <qmessagebox.h>
#include <qpainter.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->chart->setRenderHint(QPainter::Antialiasing);
  on_typeBox_currentIndexChanged(0);
}

void MainWindow::on_plotBtn_clicked() {
  auto table_size = ui->sizeBox->currentText().toInt();
  switch (ui->typeBox->currentIndex()) {
  case 0:
    PlotBuilder::speedComparisonPlot(ui->chart, 1 << 11);
    break;
  case 1:
    PlotBuilder::hashComparisonPlot(ui->chart, table_size);
    break;
  }
}

void MainWindow::on_typeBox_currentIndexChanged(int ind){
  ui->sizeBox->setEnabled( ind != 0 );
}
