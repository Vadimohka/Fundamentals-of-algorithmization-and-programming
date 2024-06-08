#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->addDish, &QPushButton::clicked, this, &MainWindow::addDish);

    connect(ui->sortMenuPrices, &QPushButton::clicked, this, &MainWindow::sortMenu);

    connect(ui->addOrder, &QPushButton::clicked, this, &MainWindow::addOrder);

    connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::calculateCheck);

    connect(ui->popular, &QPushButton::clicked, this, &MainWindow::popular);

    connect(ui->changeButton, &QPushButton::clicked, this, &MainWindow::change);

    connect(ui->openFile, &QPushButton::clicked, this, &MainWindow::openFile);

    connect(ui->delete_2, &QPushButton::clicked, this, &MainWindow::deleteOrder);

    connect(ui->saveFile, &QPushButton::clicked, this, &MainWindow::saveFile);
}

void MainWindow::saveFile(){
    QString str;
    QFile fileMenu(path);
    QFile fileOrders("/home/arina/оаип/lab2_2/orders.txt");
    fileMenu.open(QIODevice::WriteOnly);
    fileOrders.open(QIODevice::WriteOnly);
    QTextStream fileQTS(&fileMenu);
    QTextStream fileQTS1(&fileOrders);
    fileMenu.resize(0);
    fileOrders.resize(0);
    for (int i = 0; i < menu.size(); i++)
    {
        fileQTS << menu[i].getDishName() << " " << menu[i].getDiscription() << " "  << str.setNum(menu[i].getPrice()) << Qt::endl;
    }
    for (int i = 0; i < orders.size(); i++)
    {
        fileQTS1 << orders[i].getDishName() << " " << str.setNum(orders[i].getOrderNum()) << " "  << str.setNum(orders[i].getTableNum()) << " " << str.setNum(orders[i].getQuantity()) << Qt::endl;
    }
    fileMenu.close();
    fileOrders.close();
}

void MainWindow::deleteOrder(){
    QString dishName = ui->menuDishNameDelete->text();
    for(int i = 0; i < menu.size(); i++){
        if(dishName == menu[i].getDishName()){
            menu.erase(menu.begin() + i);
            ui->menuTable->removeRow(i);
            ui->menuBox->removeItem(i);
            ui->newDishName->removeItem(i);
        }
    }
}

void MainWindow::change(){
    QString orderNumberText = ui->orderNumberChange->text();
    bool correctNumber;
    int orderNumber = orderNumberText.toInt(&correctNumber);
    if (orderNumber < orders.size() && ui->amountOrderChange->value() > 0 && correctNumber) {
        Order newOrder = Order(ui->newDishName->currentText(), orderNumber, ui->tableNumberChange->value(), ui->amountOrderChange->value());

        orders[orderNumber] = newOrder;

        QTableWidgetItem *orderNameText = new QTableWidgetItem(newOrder.getDishName());
        orderNameText->setFlags(orderNameText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(orderNumber,0,orderNameText);

        QTableWidgetItem *orderNUmberText = new QTableWidgetItem(QString::number(newOrder.getOrderNum()));
        orderNUmberText->setFlags(orderNUmberText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(orderNumber,1,orderNUmberText);

        QTableWidgetItem *dishTableNumberText = new QTableWidgetItem( QString::number( newOrder.getTableNum() ) );
        dishTableNumberText->setFlags(dishTableNumberText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(orderNumber,2,dishTableNumberText);

        QTableWidgetItem *dishAmountText = new QTableWidgetItem( QString::number( newOrder.getQuantity() ) );
        dishAmountText->setFlags(dishAmountText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(orderNumber,3,dishAmountText);
    }
}

void MainWindow::drawMenu(){
    for(int i = 0; i < menu.size(); i++){
        Menu newDish = Menu(menu[i].getDishName(), menu[i].getDiscription(), menu[i].getPrice());

        QTableWidgetItem *dishNameText = new QTableWidgetItem(newDish.getDishName());
        dishNameText->setFlags(dishNameText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(i,0,dishNameText);

        QTableWidgetItem *dishDiscriptionText = new QTableWidgetItem(newDish.getDiscription());
        dishDiscriptionText->setFlags(dishDiscriptionText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(i ,1,dishDiscriptionText);

        QTableWidgetItem *dishPriceText = new QTableWidgetItem( QString::number( newDish.getPrice() ) );
        dishPriceText->setFlags(dishPriceText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(i ,2,dishPriceText);
    }
}

void MainWindow::popular(){
    if(!menu.empty() && !orders.empty()){
        std::vector <int> numberOfDishes(menu.size(), 0);
        for(int i = 0; i < menu.size(); i++){
            QString findDishName = menu[i].getDishName();
            for(int j = 0; j < orders.size(); j++){
                if(findDishName == orders[j].getDishName()){
                    numberOfDishes[i] += orders[j].getQuantity();
                }
            }
        }

        for (int i = 0; i < numberOfDishes.size() - 1; i++) {
            for (int j = 0; j < numberOfDishes.size() - i - 1; j++) {
                if (numberOfDishes[j] < numberOfDishes[j + 1]) {
                    std::swap(numberOfDishes[j], numberOfDishes[j + 1]);
                    std::swap(menu[j], menu[j + 1]);
                }
            }
        }

        drawMenu();
    }
}

int MainWindow::findOrderInMenu(const QString calcDishName){
    for(int i = 0; i < menu.size(); i++){
        if(calcDishName == menu[i].getDishName()){
            return i;
        }
    }
    return 0;
}

void MainWindow::openFile(){

    path = QFileDialog::getOpenFileName();

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    };

    QTextStream in (&file);

    while(!in.atEnd()){

        QString DishForMenuString = in.readLine();

        QStringList words = DishForMenuString.split(" ", Qt::SkipEmptyParts);

        bool correctDish;
        double price;

        if(words.length() == 3){
            bool correctPrice;
            price = words[2].toDouble(&correctPrice);
            if(correctPrice == true){
                correctDish = true;
            }
            else{
                correctDish = false;
            }
        }
        else{
            correctDish = false;
        }

        if(correctDish && !wasInMenuCheck(words[0])){
            ui->menuTable->insertRow(ui->menuTable->rowCount());

            QTableWidgetItem *dishName = new QTableWidgetItem(words[0]);
            dishName->setFlags(dishName->flags() & ~Qt::ItemIsEditable);
            ui->menuTable->setItem(ui->menuTable->rowCount() - 1, 0, dishName);

            QTableWidgetItem *dishDiscription = new QTableWidgetItem(words[1]);
            dishDiscription->setFlags(dishDiscription->flags() & ~Qt::ItemIsEditable);
            ui->menuTable->setItem(ui->menuTable->rowCount() - 1, 1, dishDiscription);

            QTableWidgetItem *dishPrice = new QTableWidgetItem(words[2]);
            dishPrice->setFlags(dishPrice->flags() & ~Qt::ItemIsEditable);
            ui->menuTable->setItem(ui->menuTable->rowCount() - 1, 2, dishPrice);

            Menu newDish = Menu(words[0], words[1], price);
            menu.push_back(newDish);

            ui->menuBox->addItem(newDish.getDishName());

            ui->newDishName->addItem(newDish.getDishName());
        }
        else{
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"));
            break;
        }


    }

    file.close();

}

void MainWindow::calculateCheck(){
    if(!orders.empty()){
        QString orderNumberText = ui->orderNumberCheck->currentText();
        int orderIndex = orderNumberText.toInt();

        QString calcDishName = orders[orderIndex].getDishName();
        int index = findOrderInMenu(calcDishName);

        double check = orders[orderIndex].getQuantity() * menu[index].getPrice();
        ui->checkLabel->setText(QString::number(check));
    }
}

bool MainWindow::wasInMenuCheck(const QString DishName){
    for (int i = 0; i < menu.size(); ++i) {
        if (menu[i].getDishName() == DishName) {
            return true;
        }
    }
    return false;
}

void MainWindow::addDish(){

    Menu newDish = Menu(ui->dishName->text(), ui->dishDiscription->text(), ui->dishPriceSpinBox->value());

    if(!wasInMenuCheck(newDish.getDishName()) && !ui->dishName->text().isEmpty() && !ui->dishDiscription->text().isEmpty() && ui->dishPriceSpinBox->value() != 0){
        int row = ui->menuTable->rowCount();
        ui->menuTable->insertRow(row);

        menu.push_back(newDish);

        QTableWidgetItem *dishNameText = new QTableWidgetItem(newDish.getDishName());
        dishNameText->setFlags(dishNameText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(row,0,dishNameText);

        QTableWidgetItem *dishDiscriptionText = new QTableWidgetItem(newDish.getDiscription());
        dishDiscriptionText->setFlags(dishDiscriptionText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(row,1,dishDiscriptionText);

        QTableWidgetItem *dishPriceText = new QTableWidgetItem( QString::number( newDish.getPrice() ) );
        dishPriceText->setFlags(dishPriceText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(row,2,dishPriceText);

        ui->menuBox->addItem(newDish.getDishName());

        ui->newDishName->addItem(newDish.getDishName());
    }
    else if(ui->dishPriceSpinBox->value() == 0){
        QMessageBox::critical(0,tr("Ошибка"),tr("Блюдо не может стоить 0 дирхам"));
    }
    else if(ui->dishName->text().isEmpty()){
        QMessageBox::critical(0,tr("Ошибка"),tr("Введите имя блюда"));
    }
    else if(ui->dishDiscription->text().isEmpty()){
        QMessageBox::critical(0,tr("Ошибка"),tr("Введите описание блюда"));
    }
    else{
        QMessageBox::critical(0,tr("Ошибка"),tr("Такое блюдо уже есть в меню"));
    }
}

void MainWindow::addOrder(){
    if(!menu.empty() && ui->dishAmount->value() != 0){
        int row = ui->orderTable->rowCount();
        ui->orderTable->insertRow(row);

        Order newOrder = Order(ui->menuBox->currentText(), row, ui->tableNumber->value(), ui->dishAmount->value());
        orders.push_back(newOrder);

        QTableWidgetItem *orderNameText = new QTableWidgetItem(newOrder.getDishName());
        orderNameText->setFlags(orderNameText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(row,0,orderNameText);

        QTableWidgetItem *orderNUmberText = new QTableWidgetItem(QString::number(newOrder.getOrderNum()));
        orderNUmberText->setFlags(orderNUmberText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(row,1,orderNUmberText);

        QTableWidgetItem *dishTableNumberText = new QTableWidgetItem( QString::number( newOrder.getTableNum() ) );
        dishTableNumberText->setFlags(dishTableNumberText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(row,2,dishTableNumberText);

        QTableWidgetItem *dishAmountText = new QTableWidgetItem( QString::number( newOrder.getQuantity() ) );
        dishAmountText->setFlags(dishAmountText->flags() & ~Qt::ItemIsEditable);
        ui->orderTable->setItem(row,3,dishAmountText);

        ui->orderNumberCheck->addItem(QString::number(newOrder.getOrderNum()));
    }
}

void MainWindow::sortMenu(){
    for(int i = 0; i < menu.size(); i++){
        double key = menu[i].getPrice();
        auto tempMenu = menu[i];
        int j = i - 1;

        while (j >= 0 && menu[j].getPrice() > key) {
            menu[j + 1] = menu[j];
            --j;
        }

        menu[j + 1] = tempMenu;
    }

    drawMenu();
}
