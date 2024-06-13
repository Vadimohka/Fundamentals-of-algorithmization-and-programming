#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->AddButton,    &QPushButton::clicked, this, &MainWindow::AddButton_clicked);
    connect(ui->AddButton_1,  &QPushButton::clicked, this, &MainWindow::AddButton_1_clicked);
    connect(ui->File1OpenButton,  &QPushButton::clicked, this, &MainWindow::File1OpenButton_clicked);
    connect(ui->File2OpenButton,  &QPushButton::clicked, this, &MainWindow::File2OpenButton_clicked);
    connect(ui->SortByPriceButton,  &QPushButton::clicked, this, &MainWindow::SortByPriceButton_clicked);
    connect(ui->SortByNumberButton,  &QPushButton::clicked, this, &MainWindow::SortByNumberButton_clicked);
    connect(ui->NakladButton,  &QPushButton::clicked, this, &MainWindow::NakladButton_clicked);
    connect(ui->genList, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
    connect(ui->genList_2, &QListWidget::itemClicked, this, &MainWindow::onItemClicked_1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void qsortPrice(product *obj,int first,int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        unsigned int midObjPrice = obj[(left + right) / 2].price;
        do {
            while (obj[left].price > midObjPrice)
                ++left;
            while (obj[right].price < midObjPrice)
                --right;
            if (left <= right)
            {
                product tempObj = obj[left];
                obj[left] = obj[right];
                obj[right] = tempObj;
                ++left;
                --right;
            }
        } while (left < right);
        qsortPrice(obj, first, right);
        qsortPrice(obj, left, last);
    }
}

void qsortNumber(order *obj1,int first,int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        unsigned int midObjAmount = obj1[(left + right) / 2].number;
        do {
            while (obj1[left].number > midObjAmount)
                ++left;
            while (obj1[right].number < midObjAmount)
                --right;
            if (left <= right)
            {
                order tempObj1 = obj1[left];
                obj1[left] = obj1[right];
                obj1[right] = tempObj1;
                ++left;
                --right;
            }
        } while (left < right);
        qsortNumber(obj1, first, right);
        qsortNumber(obj1, left, last);
    }
}

void MainWindow::AddButton_clicked()
{
    QString strPrice="",fileDataComplete="",listDataComplete="";
    product *obj=new product;

    obj->code1=ui->CodeField->text();
    obj->name=ui->NameField->text();
    strPrice=ui->PriceField->text();
    obj->price=strPrice.toInt();

    fileDataComplete=
        obj->code1+'\n'+
        obj->name+'\n'+
        strPrice+'\n';
    listDataComplete=
        "Код товара: "+obj->code1+'\n'+
        "Наименование товара: "+obj->name+'\n'+
        "Цена за одну единицу: "+strPrice;

    ui->genList->clear();
    ui->genList->addItem(listDataComplete);
    QFile file("/home/masha/OAiP/Lab2/Task2/products.txt");
    if(file.open(QIODevice::ReadWrite|QIODevice::Append)) file.write(fileDataComplete.toUtf8());

    ui->CodeField->clear();
    ui->NameField->clear();
    ui->PriceField->clear();

}

void MainWindow::AddButton_1_clicked()
{
    QString strNumber="",strAmount="",fileDataComplete1="",listDataComplete1="";
    order *obj1=new order;

    strNumber=ui->NumberField->text();
    obj1->number=strNumber.toInt();
    obj1->date=ui->DateField->text();
    obj1->customer=ui->CustomerField->text();
    obj1->code2=ui->CodeField_1->text();
    strAmount=ui->AmountField->text();
    obj1->amount=strAmount.toInt();

    fileDataComplete1=
        strNumber+'\n'+
        obj1->date+'\n'+
        obj1->customer+'\n'+
        obj1->code2+'\n'+
        strAmount+'\n';
    listDataComplete1=
        "Номер: "+strNumber+'\n'+
        "Дата: "+obj1->date+'\n'+
        "Реквизиты заказчика: "+obj1->customer+'\n'+
        "Код товара: "+obj1->code2+'\n'+
        "Количество товара: "+strAmount;

    ui->genList_2->clear();
    ui->genList_2->addItem(listDataComplete1);
    QFile file("/home/masha/OAiP/Lab2/Task2/orders.txt");
    if(file.open(QIODevice::ReadWrite|QIODevice::Append)) file.write(fileDataComplete1.toUtf8());

    ui->NumberField->clear();
    ui->DateField->clear();
    ui->CustomerField->clear();
    ui->CodeField_1->clear();
    ui->AmountField->clear();
}

void MainWindow::File1OpenButton_clicked()
{
    QString line="";
    int counterLines=0,newObjsAmount=0,counterNewObjsCreated=0;
    QFile file("/home/masha/OAiP/Lab2/Task2/products.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line=in.readLine();
        if(line!=nullptr) counterLines++;
    }
    newObjsAmount=counterLines/3;
    product *newObj=new product[newObjsAmount];
    QString *strPrice=new QString[newObjsAmount];
    QTextStream q(&file);
    q.seek(0);
    while(!q.atEnd())
    {
        newObj[counterNewObjsCreated].code1=q.readLine().toUtf8();
        newObj[counterNewObjsCreated].name=q.readLine().toUtf8();
        strPrice[counterNewObjsCreated]=q.readLine().toUtf8();
        newObj[counterNewObjsCreated].price=strPrice[counterNewObjsCreated].toInt();
        counterNewObjsCreated++;
    }
    if(newObjsAmount!=0)
    {
        QString data="";
        //data.toUtf8();
        ui->genList->clear();
        for(int i=newObjsAmount-1;i>=0;i--)
        {
            data=
                "Код товара: "+newObj[i].code1+'\n'+
                "Наименование товара: "+newObj[i].name+'\n'+
                "Цена: "+strPrice[i];

            ui->genList->addItem(data);
        }
    }
    // Закрываем файл
    file.close();
    delete[] newObj;
    delete[] strPrice;
}

void MainWindow::File2OpenButton_clicked()
{
    QString line1="";
    int counterLines1=0,newObjsAmount1=0,counterNewObjsCreated1=0;
    QFile file("/home/masha/OAiP/Lab2/Task2/orders.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line1=in.readLine();
        if(line1!=nullptr) counterLines1++;
    }
    newObjsAmount1=counterLines1/5;
    order *newObj1=new order[newObjsAmount1];
    QString *strNumber=new QString[newObjsAmount1];
    QString *strAmount=new QString[newObjsAmount1];
    QTextStream q(&file);
    q.seek(0);

    while(!q.atEnd())
    {
        strNumber[counterNewObjsCreated1]=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].number=strNumber[counterNewObjsCreated1].toInt();
        newObj1[counterNewObjsCreated1].date=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].customer=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].code2=q.readLine().toUtf8();
        strAmount[counterNewObjsCreated1]=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].amount=strAmount[counterNewObjsCreated1].toInt();
        counterNewObjsCreated1++;
    }

    if(newObjsAmount1!=0)
    {
        QString data="";
        //data.toUtf8();
        ui->genList_2->clear();
        for(int i=newObjsAmount1-1;i>=0;i--)
        {
            data=
                "Номер заказа: "+strNumber[i]+'\n'+
                "Дата: "+newObj1[i].date+'\n'+
                "Реквизиты заказчика: "+newObj1[i].customer+'\n'+
                "Код товара: "+newObj1[i].code2+'\n'+
                "Количество: "+strAmount[i];
            ui->genList_2->addItem(data);
        }
    }
    delete[] newObj1;
    delete[] strNumber;
    delete[] strAmount;
}

void MainWindow::SortByPriceButton_clicked()
{
    QString line="";
    int counterLines=0,newObjsAmount=0,counterNewObjsCreated=0;
    QFile file("/home/masha/OAiP/Lab2/Task2/products.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line=in.readLine();
        if(line!=nullptr) counterLines++;
    }
    newObjsAmount=counterLines/3;
    product *newObj=new product[newObjsAmount];
    QString *strPrice=new QString[newObjsAmount];
    QTextStream q(&file);
    q.seek(0);
    while(!q.atEnd())
    {
        newObj[counterNewObjsCreated].code1=q.readLine().toUtf8();
        newObj[counterNewObjsCreated].name=q.readLine().toUtf8();
        strPrice[counterNewObjsCreated]=q.readLine().toUtf8();
        newObj[counterNewObjsCreated].price=strPrice[counterNewObjsCreated].toInt();
        counterNewObjsCreated++;
    }

    qsortPrice(newObj,0,newObjsAmount-1);

    if(newObjsAmount!=0)
    {
        QString data="";

        ui->genList->clear();
        ui->genList->addItem("Товары, отсортированные по цене:");
        for(int i=newObjsAmount-1;i>=0;i--)
        {
            data=
                "Код товара: "+newObj[i].code1+'\n'+
                "Наименование товара: "+newObj[i].name+'\n'+
                "Цена: "+QString::number(newObj[i].price) + '\n';
            ui->genList->addItem(data);

        }
    }
    delete[] newObj;
    delete[] strPrice;

}

void MainWindow::SortByNumberButton_clicked()
{
    QString line1="";
    int counterLines1=0,newObjsAmount1=0,counterNewObjsCreated1=0;
    QFile file("/home/masha/OAiP/Lab2/Task2/orders.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line1=in.readLine();
        if(line1!=nullptr) counterLines1++;
    }
    newObjsAmount1=counterLines1/5;
    order *newObj1=new order[newObjsAmount1];
    QString *strNumber=new QString[newObjsAmount1];
    QString *strAmount=new QString[newObjsAmount1];
    QTextStream q(&file);
    q.seek(0);
    while(!q.atEnd())
    {
        strNumber[counterNewObjsCreated1]=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].number=strNumber[counterNewObjsCreated1].toInt();
        newObj1[counterNewObjsCreated1].date=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].customer=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].code2=q.readLine().toUtf8();
        strAmount[counterNewObjsCreated1]=q.readLine().toUtf8();
        newObj1[counterNewObjsCreated1].amount=strAmount[counterNewObjsCreated1].toInt();
        counterNewObjsCreated1++;
    }
    qsortNumber(newObj1,0,newObjsAmount1-1);
    if(newObjsAmount1!=0)
    {
        QString data="";
        //data.toUtf8();
        ui->genList_2->clear();
        ui->genList_2->addItem("Заказы, отсортированные по номеру:");
        for(int i=newObjsAmount1-1;i>=0;i--)
        {
            data=
                "Номер заказа: "+QString::number(newObj1[i].number) + '\n'+
                "Дата: "+newObj1[i].date+'\n'+
                "Реквизиты заказчика: "+newObj1[i].customer+'\n'+
                "Код товара: "+newObj1[i].code2+'\n'+
                "Количество: "+QString::number(newObj1[i].amount)+ '\n';
            ui->genList_2->addItem(data);
        }
    }
    delete[] newObj1;
    delete[] strNumber;
    delete[] strAmount;

}

void MainWindow::NakladButton_clicked()
{
    QString line = "";
    int counterLines = 0, newObjsAmount = 0;
    QFile file("/home/masha/OAiP/Lab2/Task2/products.txt");
    if (!file.open(QIODevice::ReadOnly)) {

        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
        if (line != nullptr)
            counterLines++;
    }
    newObjsAmount = counterLines / 3;
    product* newObj = new product[newObjsAmount];
    QString* strPrice = new QString[newObjsAmount];
    file.seek(0);
    for (int i = 0; i < newObjsAmount; i++) {
        newObj[i].code1 = in.readLine().toUtf8();
        newObj[i].name = in.readLine().toUtf8();
        strPrice[i] = in.readLine().toUtf8();
        newObj[i].price = strPrice[i].toInt();
    }
    file.close();

    QString line1 = "";
    QString strOrderGiven = ui->NakladField->text();
    unsigned int orderGiven = strOrderGiven.toInt();
    int counterLines1 = 0, newObjsAmount1 = 0;

    QFile file1("/home/masha/OAiP/Lab2/Task2/orders.txt");
    if (!file1.open(QIODevice::ReadOnly)) {
        delete[] newObj;
        delete[] strPrice;// Обработка ошибки открытия файла
        return;
    }
    QTextStream in1(&file1);
    while (!in1.atEnd()) {
        line1 = in1.readLine();
        if (!line1.isNull()) {
            counterLines1++;
        }
    }
    newObjsAmount1 = counterLines1 / 5;
    QVector<Order> orders;
    file1.seek(0);
    for (int i = 0; i < newObjsAmount1; i++) {
        Order order;
        order.number = in1.readLine().toUInt();
        order.date = in1.readLine().toUtf8();
        order.customer = in1.readLine().toUtf8();
        OrderItem item;
        item.code = in1.readLine().toUtf8();
        item.amount = in1.readLine().toInt();
        order.items.append(item);
        orders.append(order);
    }
    file1.close();

    unsigned int sum = 0;
    bool orderYes = false;

    QVector<int> sameNumbers;
    for (int i = 0; i < newObjsAmount1; i++) {
        if (orderGiven == orders[i].number) {
            orderYes = true;
            sameNumbers.append(i);
        }
    }
    if (!orderYes) {
        ui->genList_3->clear();
        ui->genList_3->addItem("Такого заказа нет");
    }
    else {
        for (int i : sameNumbers) {
            for (const OrderItem& item : orders[i].items) {
                for (int j = 0; j < newObjsAmount; j++) {
                    if (item.code == newObj[j].code1) {
                        sum += newObj[j].price * item.amount;
                    }
                }
            }
        }
        ui->genList_3->clear();
        ui->genList_3->addItem("                                                              НАКЛАДНАЯ") ;
        ui->genList_3->addItem("                                                        Номер заказа: " + QString::number(orderGiven));
        ui->genList_3->addItem("                                             Суммарная стоимость: " + QString::number(sum));
        ui->genList_3->addItem("\nСписок товаров:");

        for (int i : sameNumbers) {
            for (const OrderItem& item : orders[i].items) {
                QString itemName;
                int itemPrice;
                bool itemFound = false;
                for (int j = 0; j < newObjsAmount; j++) {
                    if (item.code == newObj[j].code1) {
                        itemName = newObj[j].name;
                        itemPrice = newObj[j].price;
                        itemFound = true;
                        break;
                    }
                }
                if (!itemFound) {
                    ui->genList_3->clear();
                    QString data = "Товар с кодом " + item.code + " отсутствует, добавьте его в список товаров и повторите попытку";
                    ui->genList_3->addItem(data);
                    delete[] newObj;
                    delete[] strPrice;
                    return;
                } else {
                    QString data = "Наименование: " + itemName + ",  Код: " + item.code + ",  Количество: " + QString::number(item.amount) + ",  Стоимость за единицу: " + QString::number(itemPrice);
                    ui->genList_3->addItem(data);

                }
            }
        }
    }

    delete[] newObj;
    delete[] strPrice;
}

void MainWindow::onItemClicked()
{
    QListWidgetItem* selectedItem = ui->genList->currentItem();
    delete ui->genList->takeItem(ui->genList->row(selectedItem));
    QFile tempFile("/home/masha/OAiP/Lab2/Task2/products_temp.txt");
    if (tempFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&tempFile);
        for (int i = 0; i < ui->genList->count(); ++i)
        {
            QListWidgetItem* item = ui->genList->item(i);
            QString itemText = item->text();
            itemText.remove("Код товара: ");
            itemText.remove("Наименование товара: ");
            itemText.remove("Цена: ");
            out << itemText << '\n';
        }
        tempFile.close();
        QFile::remove("/home/masha/OAiP/Lab2/Task2/products.txt");
        QFile::rename("/home/masha/OAiP/Lab2/Task2/products_temp.txt",
                      "/home/masha/OAiP/Lab2/Task2/products.txt");
    }
}

void MainWindow::onItemClicked_1()
{
    QListWidgetItem* selectedItem = ui->genList_2->currentItem();
    delete ui->genList_2->takeItem(ui->genList_2->row(selectedItem));
    QFile tempFile("/home/masha/OAiP/Lab2/Task2/orders_temp.txt");
    if (tempFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&tempFile);
        for (int i = 0; i < ui->genList_2->count(); ++i)
        {
            QListWidgetItem* item = ui->genList_2->item(i);
            QString itemText = item->text();

            itemText.remove("Номер заказа: ");
            itemText.remove("Дата: ");
            itemText.remove("Реквизиты заказчика: ");
            itemText.remove("Код товара: ");
            itemText.remove("Количество: ");
             out << itemText << '\n';
        }
        tempFile.close();
        QFile::remove("/home/masha/OAiP/Lab2/Task2/orders.txt");
        QFile::rename("/home/masha/OAiP/Lab2/Task2/orders_temp.txt",
                      "/home/masha/OAiP/Lab2/Task2/orders.txt");
    }
}










