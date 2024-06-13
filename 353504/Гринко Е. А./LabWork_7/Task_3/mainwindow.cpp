#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_clicked()
{
    _table.add(ui->key->value(), ui->value->text());
    updateWidgets();
}

void MainWindow::on_random_clicked()
{
    _table.clear();

    uint8_t size = QRandomGenerator::global()->bounded(MIN_SIZE, MAX_SIZE);
    for (uint8_t i = 0; i < size; ++i) {
        _table.add(QRandomGenerator::global()->bounded(-KEY_BOUNDS, KEY_BOUNDS), QString::number(i) + "val");
    }

    updateWidgets();
}

void MainWindow::on_taskBtn_clicked()
{
    ui->taskReturn->setValue(_table.getIndexOfMin());
}

void MainWindow::on_clear_clicked()
{
    _table.clear();
    updateWidgets();
}


void MainWindow::on_indexBox_valueChanged(int arg1)
{
    try {
        visualizeStack(_table.getByInnerIndex(arg1), ui->indexList);
    } catch (...) {
        qDebug() << "buuug";
    }
}

void MainWindow::on_keyBox_valueChanged(int arg1)
{
    visualizeStack(_table.get_c(arg1), ui->keyList);
}


void MainWindow::updateWidgets()
{
    ui->size->setValue(_table.size());
    ui->empty->setText(_table.empty() ? "True" : "False");

    ui->indexBox->setMaximum(_table.size());
    ui->indexBox->setReadOnly(_table.empty());

    on_keyBox_valueChanged(ui->keyBox->value());
    on_indexBox_valueChanged(ui->indexBox->value());
}

template<typename T>
void MainWindow::visualizeStack(const T& stack, QListWidget *view)
{
    view->clear();
    auto st = stack;

    while (!st.empty()) {
        view->addItem(QString::number(st.top().key) + " " + st.top().value);
        st.pop();
    }
}
