#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
 
  connect(ui->addDish, &QPushButton::clicked, this, &MainWindow::addDish);

  connect(ui->sortMenuPrices, &QPushButton::clicked, this, &MainWindow::sortMenu);

  connect(ui->addOrder, &QPushButton::clicked, this, &MainWindow::addOrder);

  connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::calculateCheck);

  connect(ui->sortByPopularity, &QPushButton::clicked, this, &MainWindow::sortByPopularity);

  connect(ui->changeButton, &QPushButton::clicked, this, &MainWindow::change);

  connect(ui->openFile, &QPushButton::clicked, this, &MainWindow::openFile);

  connect(ui->delete_2, &QPushButton::clicked, this, &MainWindow::deleteOrder);
  
  connect(ui->saveFile, &QPushButton::clicked, this, &MainWindow::saveFile);

  connect(ui->cancelOrder, &QPushButton::clicked, this, &MainWindow::cancelOrder);
}

void MainWindow::cancelOrder(){
  if(!orders.empty()){
    QMessageBox::critical(0,tr("Ошибка"),tr("Блюдо уже готовится"));
  }
}


void MainWindow::saveFile(){
  QString str;
  QFile fileMenu(path);
  QFile fileOrders("/home/__maks__/Lab2/orders.txt");
  fileMenu.open(QIODevice::WriteOnly);
  fileOrders.open(QIODevice::WriteOnly);
  QTextStream fileQTS(&fileMenu);
  QTextStream fileQTS1(&fileOrders);
  fileMenu.resize(0);
  fileOrders.resize(0);
  for (int i = 0; i < menu.size(); i++)
  {
      fileQTS << menu[i].getName() << " " << menu[i].getDiscription() << " "  << str.setNum(menu[i].getPrice()) << Qt::endl;
  }
  for (int i = 0; i < orders.size(); i++)
  {
      fileQTS1 << orders[i].getName() << " " << str.setNum(orders[i].getOrderNumber()) << " "  << str.setNum(orders[i].getTableNumber()) << " " << str.setNum(orders[i].getDishNumber()) << Qt::endl;
  }
  fileMenu.close();
  fileOrders.close();
}

void MainWindow::deleteOrder(){
  QString dishName = ui->menuDishNameDelete->text();
  for(int i = 0; i < menu.size(); i++){
    if(dishName == menu[i].getName()){
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
  if(orderNumber < orders.size() && ui->amountOrderChange->value() > 0 && correctNumber) {
    Order newOrder = Order(ui->newDishName->currentText(), orderNumber, ui->tableNumberChange->value(), ui->amountOrderChange->value());

    orders[orderNumber] = newOrder;

    QTableWidgetItem *orderNameText = new QTableWidgetItem(newOrder.getName());
    orderNameText->setFlags(orderNameText->flags() & ~Qt::ItemIsEditable);
    ui->orderTable->setItem(orderNumber,0,orderNameText);

    QTableWidgetItem *orderNUmberText = new QTableWidgetItem(QString::number(newOrder.getOrderNumber()));
    orderNUmberText->setFlags(orderNUmberText->flags() & ~Qt::ItemIsEditable);
    ui->orderTable->setItem(orderNumber,1,orderNUmberText);

    QTableWidgetItem *dishTableNumberText = new QTableWidgetItem( QString::number( newOrder.getTableNumber() ) );
    dishTableNumberText->setFlags(dishTableNumberText->flags() & ~Qt::ItemIsEditable);
    ui->orderTable->setItem(orderNumber,2,dishTableNumberText);

    QTableWidgetItem *dishAmountText = new QTableWidgetItem( QString::number( newOrder.getDishNumber() ) );
    dishAmountText->setFlags(dishAmountText->flags() & ~Qt::ItemIsEditable);
    ui->orderTable->setItem(orderNumber,3,dishAmountText);
  }
}

void MainWindow::drawMenu(){
  for(int i = 0; i < menu.size(); i++){
    Dish newDish = Dish(menu[i].getName(), menu[i].getDiscription(), menu[i].getPrice());

    QTableWidgetItem *dishNameText = new QTableWidgetItem(newDish.getName());
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

void MainWindow::sortByPopularity(){
  if(!menu.empty() && !orders.empty()){
    std::vector <int> numberOfDishes(menu.size(), 0);
    for(int i = 0; i < menu.size(); i++){
      QString findDishName = menu[i].getName();
      for(int j = 0; j < orders.size(); j++){
        if(findDishName == orders[j].getName()){
          numberOfDishes[i] += orders[j].getDishNumber();
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
    if(calcDishName == menu[i].getName()){
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

      Dish newDish = Dish(words[0], words[1], price);
      menu.push_back(newDish);

      ui->menuBox->addItem(newDish.getName());

      ui->newDishName->addItem(newDish.getName());
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

    QString calcDishName = orders[orderIndex].getName();
    int index = findOrderInMenu(calcDishName);

    double check = orders[orderIndex].getDishNumber() * menu[index].getPrice();
    ui->checkLabel->setText(QString::number(check));
  }
}

bool MainWindow::wasInMenuCheck(const QString DishName){
    for (int i = 0; i < menu.size(); ++i) {
        if (menu[i].getName() == DishName) {
            return true;
        }
    }
    return false;
}

void MainWindow::addDish(){

    Dish newDish = Dish(ui->dishName->text(), ui->dishDiscription->text(), ui->dishPriceSpinBox->value());

    if(!wasInMenuCheck(newDish.getName()) && !ui->dishName->text().isEmpty() && !ui->dishDiscription->text().isEmpty() && ui->dishPriceSpinBox->value() != 0){
        int row = ui->menuTable->rowCount();
        ui->menuTable->insertRow(row);

        menu.push_back(newDish);

        QTableWidgetItem *dishNameText = new QTableWidgetItem(newDish.getName());
        dishNameText->setFlags(dishNameText->flags() & ~Qt::ItemIsEditable);
        ui->menuTable->setItem(row,0,dishNameText);

        QTableWidgetItem *dishDiscriptionText = new QTableWidgetItem(newDish.getDiscription());
        dishDiscriptionText->setFlags(dishDiscriptionText->flags() & ~Qt::ItemIsEditable);        
        ui->menuTable->setItem(row,1,dishDiscriptionText);

        QTableWidgetItem *dishPriceText = new QTableWidgetItem( QString::number( newDish.getPrice() ) );
        dishPriceText->setFlags(dishPriceText->flags() & ~Qt::ItemIsEditable);   
        ui->menuTable->setItem(row,2,dishPriceText);

        ui->menuBox->addItem(newDish.getName());

        ui->newDishName->addItem(newDish.getName());
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

    QTableWidgetItem *orderNameText = new QTableWidgetItem(newOrder.getName());
    orderNameText->setFlags(orderNameText->flags() & ~Qt::ItemIsEditable);   
    ui->orderTable->setItem(row,0,orderNameText);

    QTableWidgetItem *orderNUmberText = new QTableWidgetItem(QString::number(newOrder.getOrderNumber()));
    orderNUmberText->setFlags(orderNUmberText->flags() & ~Qt::ItemIsEditable);   
    ui->orderTable->setItem(row,1,orderNUmberText);

    QTableWidgetItem *dishTableNumberText = new QTableWidgetItem( QString::number( newOrder.getTableNumber() ) );
    dishTableNumberText->setFlags(dishTableNumberText->flags() & ~Qt::ItemIsEditable);  
    ui->orderTable->setItem(row,2,dishTableNumberText);

    QTableWidgetItem *dishAmountText = new QTableWidgetItem( QString::number( newOrder.getDishNumber() ) );
    dishAmountText->setFlags(dishAmountText->flags() & ~Qt::ItemIsEditable);  
    ui->orderTable->setItem(row,3,dishAmountText);

    ui->orderNumberCheck->addItem(QString::number(newOrder.getOrderNumber()));
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

