#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <QMessageBox>
MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("heap");
    heapar = new ArrayHeap();
    for(int i = 0;i < 20;++i){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> keyDist(0, 100);
        int key = keyDist(gen);
        heapar->insert(key);
    }
    heapar->showHeapOnTreeWidget(ui->treeWidget);
}

void MainWindow::on_extractMaxBut_clicked() {
    try {
        heapar->extractMax();
    }
    catch (const std::runtime_error& e) {
        QMessageBox::warning(nullptr, "Error", e.what());
        return;
    }
    heapar->showHeapOnTreeWidget(ui->treeWidget);
}

void MainWindow::on_insertBut_clicked() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(0, 100);
    int key = keyDist(gen);
    heapar->insert(key);
    heapar->showHeapOnTreeWidget(ui->treeWidget);
}
void MainWindow::on_clearBut_clicked(){
    heapar->clearHeap();
    heapar->showHeapOnTreeWidget(ui->treeWidget);
}


