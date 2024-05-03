#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//,
{
    ui->setupUi(this);

    ui->firstTableWidget->setColumnCount(1);
    ui->secondTableWidget->setColumnCount(2);

    connect(ui->randPushButton, SIGNAL( clicked(bool)), SLOT(slotRandomize()));

    slotRandomize();

    showVec();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::slotRandomize() {
    int size1 = QRandomGenerator::global()->bounded(9) + 1;
    _vec.clear();
    _vec.resize(size1);
    for (int i = 0; i < size1; ++i) {
        int size2 = QRandomGenerator::global()->bounded(9) + 1;
        _vec.at(i).first.resize(size2);
        for (int j = 0; j < size2; ++j) {
            _vec.at(i).first.at(j) = QRandomGenerator::global()->bounded(size2 * 2);
        }

        int size3 = QRandomGenerator::global()->bounded(9) + 1;
        _vec.at(i).second.resize(size3);
        for (int j = 0; j < size3; ++j) {
            _vec.at(i).second.at(j).first = QRandomGenerator::global()->bounded(size3 * 2);
            _vec.at(i).second.at(j).second = QRandomGenerator::global()->bounded(size3 * 5) / size2;
        }
    }

    visualize();
}

void MainWindow::visualize() {
    int rowCntr1 = 0;
    int rowCntr2 = 0;
    ui->firstTableWidget->setRowCount(0);
    ui->secondTableWidget->setRowCount(0);
    ui->firstTableWidget->setColumnCount(_vec.size());
    ui->secondTableWidget->setColumnCount(_vec.size() * 2);

    for (int i = 0; i < _vec.size(); ++i) {
        if (_vec.at(i).first.size() > rowCntr1) {
            rowCntr1 = _vec.at(i).first.size();
            ui->firstTableWidget->setRowCount(rowCntr1);
        }
        for (int j = 0; j < _vec.at(i).first.size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(_vec.at(i).first.at(j)));
            ui->firstTableWidget->setItem(j, i, item);
        }

        if (_vec.at(i).second.size() > rowCntr2) {
            rowCntr2 = _vec.at(i).second.size();
            ui->secondTableWidget->setRowCount(rowCntr2);
        }
        for (int j = 0; j < _vec.at(i).second.size(); ++j) {
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(_vec.at(i).second.at(j).first));
            ui->secondTableWidget->setItem(j, i * 2, item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(_vec.at(i).second.at(j).second));
            ui->secondTableWidget->setItem(j, i * 2 + 1, item2);
        }
    }

    _setNotEditable(ui->firstTableWidget);
    _setNotEditable(ui->secondTableWidget);
}

void MainWindow::_setNotEditable(QTableWidget *table) {
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int column = 0; column < table->columnCount(); ++column) {
            QTableWidgetItem *item = table->item(row, column);
            if (!item) {
                item = new QTableWidgetItem();
                table->setItem(row, column, item);
            }
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
    }
}

void MainWindow::showVec() {
    QFile file("//home//mikalai//gitlabs//Fundamentals-of-algorithmization-and-programming//353503//Дергун Н.О.//LabWork_4//Task_4//Source//myvector.h");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    ui->textEdit->clear();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->textEdit->append(line);
    }

    file.close();
}
