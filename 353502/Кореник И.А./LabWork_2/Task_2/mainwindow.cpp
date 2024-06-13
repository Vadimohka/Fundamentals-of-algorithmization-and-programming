#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newOrder->hide();
    ui->newDish->hide();
    QPair<QVector<Dish *>*, QVector<Order *>*>p =fileManager.LoadFromFile(filename);
    menu = *p.first;
    orders = *p.second;
    setUpTables();
    fillTables();
    getTablesList();
    getPopularDishes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    filename = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;");
    fileManager.LoadFromFile(filename);
    fillTables();
    getTablesList();
    getPopularDishes();

}


void MainWindow::on_saveButton_clicked()
{
    fileManager.SaveToFile(filename, menu, orders);
}


void MainWindow::setUpTables()
{

    ui->tableMenu->setColumnCount(3);
    ui->tableMenu->setShowGrid(true); // Включаем сетку
    ui->tableMenu->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableMenu->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableMenu->setHorizontalHeaderLabels(QStringList() << ("id")
                                                           << ("dish")
                                                           << ("price"));

    ui->tableMenu->horizontalHeader()->setStretchLastSection(true);

    ui->tableMenu->hideColumn(0);

    ui->tableOrders->setColumnCount(4);
    ui->tableOrders->verticalHeader()->setVisible(false);
    ui->tableOrders->setShowGrid(true); // Включаем сетку
    ui->tableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableOrders->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableOrders->setHorizontalHeaderLabels(QStringList() << ("№")
                                                           << ("table")
                                                           << ("dish")
                                                           << ("count"));

    ui->tableBill->setColumnCount(3);
    ui->tableBill->setShowGrid(true); // Включаем сетку
   //r ui->tableBill->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //ui->tableBill>setSelectionBehavior(QAbstractItemView::SelectRows);

 //   ui->tableMenu->horizontalHeader()->setStretchLastSection(true);
    ui->tableBill->horizontalHeader()->hide();
    ui->tableBill->verticalHeader()->hide();
   // ui->tableBill->hideColumn(0);
    ui->tableBill->setColumnWidth(0, 100);
    ui->tableBill->setColumnWidth(1, 50);
    ui->tableBill->setColumnWidth(2, 58);

    ui->tableBill->hide();
}

void MainWindow::fillTables()
{
    int n = menu.size();
    ui->tableMenu->setRowCount(n);

    for (int i = 0; i < n; i++){
        ui->tableMenu->setItem(i ,1 , new QTableWidgetItem(menu[i]->getName()));
        ui->tableMenu->setItem(i ,2 , new QTableWidgetItem(QString::number(menu[i]->getPrice())));
    }

    int m = orders.size();
    ui->tableOrders->setRowCount(m);

    for (int i = 0; i < m; i++){
        ui->tableOrders->setItem(i ,0 , new QTableWidgetItem(QString::number(orders[i]->num)));
        ui->tableOrders->setItem(i ,1 , new QTableWidgetItem(QString::number(orders[i]->table)));
        ui->tableOrders->setItem(i ,2 , new QTableWidgetItem(orders[i]->dish));
        ui->tableOrders->setItem(i ,3 , new QTableWidgetItem(QString::number(orders[i]->count)));
    }
    getTablesList();
}

void MainWindow::getTablesList()
{
    tables.clear();
    ui->getBillForTable->clear();
    for (auto order : orders){
        tables.insert(order->table);
    }

    for (auto table : tables){
        ui->getBillForTable->addItem(QString::number(table));
    }
}


void MainWindow::getPopularDishes()
{
    QMap<QString, int>popular;
    for (auto order : orders){
        popular[order->dish] += order->count;
    }

    QVector<QPair<int, QString>>keys;
    for (auto i = popular.cbegin(), end = popular.cend(); i!= end; i++){
        QPair<int, QString>p = {i.value(), i.key()};
        keys.push_back(p);
    }
    std::sort(keys.begin(), keys.end());

    for (int i = 0; i < fmin(3, keys.size()); i++){
        if (i == 0) ui->dish1->setText(keys[i].second);
        if (i == 1) ui->dish2->setText(keys[i].second);
        if (i == 2) ui->dish1->setText(keys[i].second);
    }
}


void MainWindow::on_addDishButton_clicked()
{
    change = -1;
    ui->newDishLabel->clear();
    ui->priceLabel->clear();

    ui->newDish->show();
}


void MainWindow::on_addOrderButton_clicked()
{
    change = -1;
    ui->number->setText(QString::number(orders.size() + 1));
    ui->tableLabel->clear();
    ui->dishLabel->clear();
    ui->countLabel->clear();
    ui->newOrder->show();

}


void MainWindow::on_buttonBox_accepted()
{
    bool ok1, ok2 = false;
    bool fromMenu = false;
    int _table = ui->tableLabel->text().toInt(&ok1);
    QString _dish = ui->dishLabel->text();
    int _count = ui->countLabel->text().toInt(&ok2);

    for (auto elem : menu){
        if (elem->getName() == _dish){
            fromMenu = true;
            break;
        }
    }
    if (ok1 && ok2 && fromMenu){

        int i{};
        Order* order;
        if (change == -1){
            i = orders.size();
            order = new Order(i + 1, _table, _dish, _count);
            orders.push_back(order);
            ui->tableOrders->insertRow(i);
        }
        else{

            i = change;
            order = new Order(i + 1, _table, _dish, _count);
        }


        ui->tableOrders->setItem(i ,0 , new QTableWidgetItem(QString::number(order->num)));
        ui->tableOrders->setItem(i ,1 , new QTableWidgetItem(QString::number(order->table)));
        ui->tableOrders->setItem(i ,2 , new QTableWidgetItem(order->dish));
        ui->tableOrders->setItem(i ,3 , new QTableWidgetItem(QString::number(order->count)));


        ui->newOrder->close();
        getTablesList();
        getPopularDishes();
    }
}


void MainWindow::on_buttonBox_rejected()
{
    ui->newOrder->close();
}


void MainWindow::on_buttonBox_2_rejected()
{
    ui->newDish->close();
}


void MainWindow::on_buttonBox_2_accepted()
{
    bool ok;


    QString _dish = ui->newDishLabel->text();
    double _price = ui->priceLabel->text().toDouble(&ok);

    if (ok){

        int i{};
        if (change == -1)
            i = menu.size();
        else
            i = change;

        for (int j = 0; j < i; j++){
            if (menu[j]->getName() == _dish){
                if (change == -1)
                {
                    menu[j]->setPrice(_price);
                    ui->tableMenu->setItem(j, 2, new QTableWidgetItem(QString::number(_price)));
                    ui->newDish->close();
                }
                else{

                }

                return;
            }

        }

        Dish* dish = new Dish(_dish, _price);
        if (change == -1)
            menu.push_back(dish);
        else
            menu[i] = dish;
        if (change == -1)
            ui->tableMenu->insertRow(i);
        ui->tableMenu->setItem(i ,1 , new QTableWidgetItem(dish->getName()));
        ui->tableMenu->setItem(i ,2 , new QTableWidgetItem(QString::number(dish->getPrice())));

        change = - 1;
        ui->newDish->close();
    }
}


void MainWindow::on_deleteDishButton_clicked()
{
    if (!ui->tableMenu->selectedItems().empty()){
        int i = ui->tableMenu->selectedItems()[0]->row();

        menu.remove(i);
        ui->tableMenu->removeRow(i);
    }
}


void MainWindow::on_deleteOrderButton_clicked()
{
    if (!ui->tableOrders->selectedItems().empty()){
        int i = ui->tableOrders->selectedItems()[0]->row();

        orders.remove(i);
        ui->tableOrders->removeRow(i);
        getTablesList();
    }
}


void MainWindow::on_changedishButton_clicked()
{
    ui->newDishLabel->clear();
    ui->priceLabel->clear();
    if (!ui->tableMenu->selectedItems().empty()){
        int i = ui->tableMenu->selectedItems()[0]->row();
        change = i;
        ui->newDish->show();
    }
}


void MainWindow::on_changeOrderButton_clicked()
{
    if (!ui->tableOrders->selectedItems().empty()){
        int i = ui->tableOrders->selectedItems()[0]->row();
        change = i;
        ui->number->setText(QString::number(change + 1));
        ui->tableLabel->clear();
        ui->dishLabel->clear();
        ui->countLabel->clear();
        ui->newOrder->show();
        getTablesList();
    }

}


void MainWindow::on_pushButton_clicked()
{
    int currentTable = ui->getBillForTable->currentText().toInt();
    ui->tableBill->setRowCount(0);
    int i = 0;
    int sum = 0;
    for (auto order : orders){
        if (order->table == currentTable){
            ui->tableBill->insertRow(i);
            ui->tableBill->setItem(i, 0, new QTableWidgetItem(order->dish));
            ui->tableBill->setItem(i, 1, new QTableWidgetItem(QString::number(order->count)));
            int price{};
            for (auto dish : menu){
                if (dish->getName() == order->dish){
                    price = dish->getPrice();
                    break;
                }
            }
            int add = order->count * price;
            sum += add;
            ui->tableBill->setItem(i, 2, new QTableWidgetItem(QString::number(add)));
            ++i;
        }
    }

    ui->tableBill->insertRow(i);
    ui->tableBill->setItem(i, 0, new QTableWidgetItem("Total :"));
    ui->tableBill->setItem(i, 2, new QTableWidgetItem(QString::number(sum)));
    ui->tableBill->show();
}


//bool operator< (Dish* a, Dish* b) { return a->getPrice() < b->getPrice();}

bool compPrice(Dish* a, Dish* b)
{
    return a->getPrice() < b->getPrice();
}



void MainWindow::on_sortingMenu_clicked()
{
    std::sort(menu.begin(), menu.end(), compPrice);
    fillTables();
}

