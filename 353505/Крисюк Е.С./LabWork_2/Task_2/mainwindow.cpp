#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui -> groupBox -> setVisible(false);
    ui -> listWidget -> setVisible(false);
    ui -> View_order_button -> setVisible(false);
    ui -> View_order_button -> setEnabled(false);
    ui -> Add_order_button -> setVisible(false);
    ui -> Sort_button -> setVisible(false);
    ui -> label -> setText("Меню");

    menu_add_window = new Menu_add_window(this);
    connect(menu_add_window, &Menu_add_window::Send_message, this, &MainWindow::Reseive_data);

    list_create_menu = new List_create_menu(this);

    connect(this, &MainWindow::Send_path, list_create_menu, &List_create_menu::Reseive_path);
    connect(list_create_menu, &List_create_menu::Send_path, this, &MainWindow::Reseive_path);

    connect(ui -> listWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::Infotmation_view);

    information_view = new Information_View(this);
    connect(this, &MainWindow::Send_information_path, information_view, &Information_View::Reseive_data);

    QPalette pal;
    pal.setColor(QPalette::Window, QColor(135, 206, 250));
    list_create_menu -> setPalette(pal);

    ui -> Menu_tree_widget -> setColumnCount(2);
    ui -> Menu_tree_widget -> setColumnWidth(0, 370);
    ui -> Menu_tree_widget -> setColumnWidth(1, 100);

    ui -> Menu_tree_widget -> setHeaderLabels({"Блюдо", "Цена($)"});

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Menu_action_triggered()
{
//    ui -> groupBox -> setVisible(true);
    ui -> listWidget -> setVisible(false);
    ui -> View_order_button -> setVisible(false);
    ui -> Add_order_button -> setVisible(false);
    ui -> Sort_button -> setVisible(false);

    ui -> label -> setText("Меню");
    ui -> Menu_tree_widget -> setVisible(true);
    ui -> Add_dish_button -> setVisible(true);
}


void MainWindow::on_Order_action_triggered()
{
//    ui -> groupBox -> setVisible(false);
    ui -> listWidget -> setVisible(true);
    ui -> View_order_button -> setVisible(true);
    ui -> Add_order_button -> setVisible(true);
    ui -> Sort_button -> setVisible(true);

    ui -> label -> setText("Номера заказов");
    ui -> Menu_tree_widget -> setVisible(false);
    ui -> Add_dish_button -> setVisible(false);

}


void MainWindow::on_Add_order_button_clicked()
{

    QString current_path = QDir::currentPath() + "/menu";

    QDir Dir(current_path);

    if(Dir.isEmpty()) {
        QMessageBox box;
        box.setText("У вас пока нет доступных кменю");
        box.exec();
    }

    else {
        Path_to_create_File = QFileDialog::getOpenFileName(nullptr, "Выберите меню", current_path, "Файлы (*)");

        list_create_menu -> setWindowTitle("Список заказов");
        emit Send_path(Path_to_create_File);

        list_create_menu -> exec();
        Reseive_data(Path_to_create_File);

    }
}

void MainWindow::Reseive_data(const QString& File_path) {
    QFile file(File_path);

    qDebug() << "reseive path: " << File_path;
    this -> File_path = File_path;

    if(file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        QString line;

        ui -> Menu_tree_widget -> clear();

        while(!stream.atEnd()) {
            line = stream.readLine();
            QTreeWidgetItem *Name_of_Dish = new QTreeWidgetItem(ui -> Menu_tree_widget);

            Name_of_Dish -> setText(0, line);
            Name_of_Dish -> setToolTip(0, line);
            line = stream.readLine();

            Name_of_Dish -> setText(1, line);
            Name_of_Dish -> setToolTip(1, line);

            QTreeWidgetItem* Description = new QTreeWidgetItem(Name_of_Dish);

            line = stream.readLine();

            Description -> setText(0,line);
            Description -> setToolTip(0,line);
        }


    }
    else {
        qDebug("File not opened");
    }
    file.close();

}

void MainWindow::Reseive_path(const QString& file_path) {

    QFile File_inf(file_path);

    if(File_inf.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&File_inf);
        QString line;

        line = stream.readLine();
        ui -> listWidget -> addItem(line);
        ui -> Sort_button -> setEnabled(true);

    }
    else{
        qDebug() << "File not opened";
    }

}

void MainWindow::on_Add_dish_button_clicked()
{
    menu_add_window -> setWindowTitle("Добавить в меню блюдо");
    menu_add_window -> exec();

}

void MainWindow::Infotmation_view(){
    QListWidgetItem* widget = ui -> listWidget -> currentItem();
    if(widget) {

        File_name = widget -> text();
        qDebug() << File_name;
        ui -> View_order_button -> setEnabled(true);
    }
    else{
        qDebug() << "Ничего не выбрано";
    }

}


void MainWindow::on_View_order_button_clicked()
{
    QString current_path = QDir::currentPath() + "/orders/" + File_name;
    QFile file(current_path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        QFileInfo file_info(current_path);

        QString line;
        information_view -> setWindowTitle(QString("Заказ № " + file_info.fileName()));

        emit Send_information_path(current_path, Path_to_create_File);
        information_view -> exec();
    }
    else{
        qDebug() << "Файл не открылся";
    }

}



void MainWindow::on_Sort_button_clicked()
{
    ui -> listWidget -> sortItems(Qt::AscendingOrder);
}

