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

QVector<ClasMenu> menu;
QVector<ClasList> list;
QVector<ClasSthot> sthot;


void MainWindow::on_pushButton_clicked()
{
    ui -> label_23 -> setText("");
    for (int i = 0; i < col_obg_menu; i++){
        if (menu[i].nas == ui -> lineEdit -> text()){
            ui -> label_23 -> setText("Такое блюдо уже есть в меню");
            return;
        }
    }
    QString str;
    ui->table->insertRow(col_obg_menu);
    menu.resize(col_obg_menu + 1);
    menu[col_obg_menu] = ClasMenu(ui -> lineEdit -> text(), ui -> lineEdit_2 -> text(), ui -> spinBox -> value());
    ui->box->addItem(ui -> lineEdit -> text());
    ui->box_2->addItem(ui -> lineEdit -> text());
    ui->table->setItem(col_obg_menu, 0, new QTableWidgetItem(ui -> lineEdit -> text()));
    ui->table->setItem(col_obg_menu, 1, new QTableWidgetItem(ui -> lineEdit_2 -> text()));
    ui->table->setItem(col_obg_menu, 2, new QTableWidgetItem(str.setNum(ui -> spinBox -> value())));
    col_obg_menu ++;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString str;
    QFile file("/home/vlad/Lab_3_t2/ClasMenu.txt");
    QFile file1("/home/vlad/Lab_3_t2/ClasList");
    file.open(QIODevice::WriteOnly);
    file1.open(QIODevice::WriteOnly);
    QTextStream fileQTS(&file);
    QTextStream fileQTS1(&file1);
    file.resize(0);
    file1.resize(0);
    for (int i = 0; i < col_obg_menu; i++)
    {
        fileQTS << "№" + str.setNum(i) << endl << menu[i].nas << endl << menu[i].opis << endl  << str.setNum(menu[i].price) << endl;
    }
    for (int i = 0; i < col_obg_list; i++)
    {
        fileQTS1 << "№" + str.setNum(i) << endl << list[i].nas << endl << str.setNum(list[i].order_number) << endl  << str.setNum(list[i].table_number) << endl << str.setNum(list[i].col) << endl;
    }
    file.close();
    file1.close();
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString std;
    if (ui -> box -> count() == 0){
        return;
    }
    ui->table_2->insertRow(col_obg_list);
    list.resize(col_obg_list + 1);
    sthot.resize(col_obg_list + 1);
    list[col_obg_list] = ClasList(ui -> spinBox_3 -> value(), ui -> spinBox_2 -> value(), ui -> spinBox_4 -> value(), ui -> box -> currentText());
    for (int i = 0; i < col_obg_menu; i++){
        QTableWidgetItem* item = ui->table->item(i, 0);
        if (item -> text() == ui -> box -> currentText()) {
            ind = i;
        }
    }
    QTableWidgetItem* item = ui->table->item(ind, 2);
    QString Text = item->text();
    int price = Text.toInt();
    sthot[col_obg_list] = ClasSthot(ui -> box -> currentText(), ui -> spinBox_3 -> value(), ui -> spinBox_2 -> value(), ui -> spinBox_4 -> value(), price);
    ui->table_2->setItem(col_obg_list, 1, new QTableWidgetItem(std.setNum(ui -> spinBox_3 -> value())));
    ui->table_2->setItem(col_obg_list, 2, new QTableWidgetItem(std.setNum(ui -> spinBox_2 -> value())));
    ui->table_2->setItem(col_obg_list, 3, new QTableWidgetItem(std.setNum(ui -> spinBox_4 -> value())));
    ui->table_2->setItem(col_obg_list, 0, new QTableWidgetItem(ui -> box -> currentText()));
    col_obg_list ++;
}

void MainWindow::on_pushButton_4_clicked()
{
    QString str;
    ui -> label_18 -> setText("");
    int n_str = ui-> lineEdit_3 -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table_2 -> rowCount())
    {
        ui -> label_18 -> setText("Введите правильный НОМЕР");
        return;
    }
    ui -> label_12 -> setText("Заказ №" + str.setNum(sthot[n_str].order_number));
    ui -> label_13 -> setText("Название блюда: " + sthot[n_str].nas);
    ui -> label_14 -> setText("Номер столика: " + str.setNum(sthot[n_str].table_number));
    ui -> label_15 -> setText("Количество: " + str.setNum(sthot[n_str].col));
    ui -> label_16 -> setText("Цена за одну порцию: " + str.setNum(sthot[n_str].price));
    ui -> label_17 -> setText("Полная стоимость: " + str.setNum(sthot[n_str].ful_price));
}


void MainWindow::on_pushButton_5_clicked()
{
    QString str;
    for (int i = 0; i < col_obg_menu - 1; i++) {
        for (int j = 0; j < col_obg_menu - i - 1; j++) {
            if (menu[j].price > menu[j + 1].price) {
                ClasMenu temp = menu[j];
                menu[j] = menu[j+1];
                menu[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i <= col_obg_menu - 1; i++){
        ui->table->setItem(i, 0, new QTableWidgetItem(menu[i].nas));
        ui->table->setItem(i, 1, new QTableWidgetItem(menu[i].opis));
        ui->table->setItem(i, 2, new QTableWidgetItem(str.setNum(menu[i].price)));
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QString str;
    ui -> label_18 -> setText("");
    int n_str = ui-> lineEdit_4 -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table_2 -> rowCount())
    {
        ui -> label_18 -> setText("Введите правильный НОМЕР");
        return;
    }
    ui -> table_2 -> removeRow(n_str);
    list.remove(n_str);
    sthot.remove(n_str);
    col_obg_list --;
}


void MainWindow::on_pushButton_7_clicked()
{
    QString str;
    ui -> label_23 -> setText("");
    int n_str = ui-> lineEdit_5 -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table -> rowCount())
    {
        ui -> label_23 -> setText("Введите правильный НОМЕР");
        return;
    }
    ui -> table -> removeRow(n_str);
    menu.remove(n_str);
    ui -> box -> removeItem(n_str);
    ui -> box_2 -> removeItem(n_str);
    col_obg_menu --;
}


void MainWindow::on_pushButton_8_clicked()
{
    QString std;
    ui -> label_18 -> setText("");
    int n_str = ui -> lineEdit_6 -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table_2 -> rowCount())
    {
        ui -> label_18 -> setText("Введите правильный НОМЕР");
        return;
    }
    list[n_str] = ClasList(ui -> spinBox_5 -> value(), ui -> spinBox_7 -> value(), ui -> spinBox_6 -> value(), ui -> box_2 -> currentText());
    for (int i = 0; i < col_obg_menu; i++){
        QTableWidgetItem* item = ui->table_2->item(i, 0);
        if (item -> text() == ui -> box_2 -> currentText()) {
            ind = i;
        }
    }
    QTableWidgetItem* item = ui->table->item(ind, 2);
    QString Text = item->text();
    int price = Text.toInt();
    sthot[n_str] = ClasSthot(ui -> box_2 -> currentText(), ui -> spinBox_5 -> value(), ui -> spinBox_7 -> value(), ui -> spinBox_6 -> value(), price);
    ui->table_2->setItem(n_str, 1, new QTableWidgetItem(std.setNum(ui -> spinBox_5 -> value())));
    ui->table_2->setItem(n_str, 2, new QTableWidgetItem(std.setNum(ui -> spinBox_7 -> value())));
    ui->table_2->setItem(n_str, 3, new QTableWidgetItem(std.setNum(ui -> spinBox_6 -> value())));
    ui->table_2->setItem(n_str, 0, new QTableWidgetItem(ui -> box_2 -> currentText()));
}


void MainWindow::on_pushButton_9_clicked()
{
    QString std;
    ui -> label_23 -> setText("");
    for (int i = 0; i < col_obg_menu; i++){
        if (menu[i].nas == ui -> lineEdit_7 -> text()){
            ui -> label_23 -> setText("Такое блюдо уже есть в меню");
            return;
        }
    }
    int n_str = ui -> lineEdit_7 -> text().toInt() - 1;
    if(n_str < 0 || n_str >= ui -> table -> rowCount())
    {
        ui -> label_23 -> setText("Введите правильный НОМЕР");
        return;
    }
    menu[n_str] = ClasMenu(ui -> lineEdit_8 -> text(), ui -> lineEdit_9 -> text(), ui -> spinBox_8 -> value());
    ui->table->setItem(n_str, 1, new QTableWidgetItem(ui -> lineEdit_9 -> text()));
    ui->table->setItem(n_str, 2, new QTableWidgetItem(std.setNum(ui -> spinBox_8 -> value())));
    ui->table->setItem(n_str, 0, new QTableWidgetItem(ui -> lineEdit_8 -> text()));
    ui -> box -> removeItem(n_str);
    ui -> box_2 -> removeItem(n_str);
    ui -> box -> insertItem(n_str, ui -> lineEdit_8 -> text());
    ui -> box_2 -> insertItem(n_str, ui -> lineEdit_8 -> text());
}


void MainWindow::on_pushButton_10_clicked()
{
    QString str;
    int ind = 0;
    if (col_obg_list <= 0){
        return;
    }
    int zn = list[0].col;
    for (int i = 0; i < col_obg_list; i++){
        if (zn < list[i].col){
            zn = list[i].col;
            ind = i;
        }
    }
    ui -> label_36 -> setText("Название блюда: " + list[ind].nas);
    ui -> label_37 -> setText("Номер заказа: " + str.setNum(list[ind].order_number));
    ui -> label_38 -> setText("Номер столика: " + str.setNum(list[ind].table_number));
    ui -> label_39 -> setText("Количество: " + str.setNum(list[ind].col));
}

