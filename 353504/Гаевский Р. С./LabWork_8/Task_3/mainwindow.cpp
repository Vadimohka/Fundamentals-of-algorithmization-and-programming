#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setTextEdit->setReadOnly(true);
    ui->mapTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{
    QString str;

    str += "Tree Iterator for set:\n";
    auto treeIter_set = set.begin();
    while (treeIter_set != set.end()) {
        auto temp = treeIter_set;
        ++temp;
        if (temp != set.end()) str += QString("%1, ")
                   .arg(treeIter_set->data.first);
        else str += QString("%1")
                       .arg(treeIter_set->data.first);
        ++treeIter_set;
    }

    str += "\nList Iterator for set:\n";
    auto listIter_set = set.begin();
    while (listIter_set != set.end()) {
        auto temp = listIter_set;
        ++temp;
        if (temp != set.end()) str += QString("%1, ")
                   .arg(listIter_set->data.first);
        else str += QString("%1")
                       .arg(listIter_set->data.first);
        ++listIter_set;
    }

    ui->setTextEdit->setText(str);
    str.clear();

    str += "Tree Iterator for map:\n";
    auto treeIter_map = map.begin();
    while (treeIter_map != map.end()) {
        auto temp = treeIter_map;
        ++temp;
        if (temp != map.end()) str += QString("[%1] = %2, ")
                   .arg(treeIter_map->data.first)
                   .arg(treeIter_map->data.second);
        else str += QString("[%1] = %2")
                       .arg(treeIter_map->data.first)
                       .arg(treeIter_map->data.second);
        ++treeIter_map;
    }

    str += "\nList Iterator for map:\n";
    auto listIter_map = map.begin();
    while (listIter_map != map.end()) {
        auto temp = listIter_map;
        ++temp;
        if (temp != map.end()) str += QString("[%1] = %2, ")
                   .arg(listIter_map->data.first)
                   .arg(listIter_map->data.second);
        else str += QString("[%1] = %2")
                       .arg(listIter_map->data.first)
                       .arg(listIter_map->data.second);
        ++listIter_map;
    }

    ui->mapTextEdit->setText(str);
}

void MainWindow::on_bnt_set_add_clicked()
{
    set.insert(ui->spb_set_value->value());
    display();
}


void MainWindow::on_bnt_set_remove_clicked()
{
    set.erase(ui->spb_set_value->value());
    display();
}


void MainWindow::on_bnt_set_clear_clicked()
{
    set.clear();
    display();
}


void MainWindow::on_spb_map_add_clicked()
{
    map.insert(ui->spb_map_key->value(), ui->spb_map_value->value());
    display();
}


void MainWindow::on_spb_map_remove_clicked()
{
    map.erase(ui->spb_map_key->value());
    display();
}


void MainWindow::on_spb_map_clear_clicked()
{
    map.clear();
    display();
}


void MainWindow::on_spb_map_getValue_clicked()
{
    auto tmp = map.get(ui->spb_map_key->value());
    if (tmp == INT_MIN) QMessageBox::information(this, "Полученное значение                                         ", "Заданного ключа нет в map");
    else QMessageBox::information(this, "Полученное значение                                         ", "Значение составило: " + QString::number(tmp));
}


void MainWindow::on_pushButton_clicked()
{
    try {
        QMessageBox::information(this, "Полученное значение                                         ", "Максимальный элемент: " + QString::number(set.getMax()));
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Ошибка                                   ", "На данный момент Set пуст");
    }
}
