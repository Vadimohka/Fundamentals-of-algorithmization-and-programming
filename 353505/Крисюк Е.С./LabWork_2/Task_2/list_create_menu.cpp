#include "list_create_menu.h"
#include "ui_list_create_menu.h"

List_create_menu::List_create_menu(QWidget *parent) : QDialog(parent), ui(new Ui::List_create_menu)
{
    ui->setupUi(this);
    ui -> Order_number_line -> setMaxLength(8);
    ui -> Table_number_line -> setMaxLength(5);

    QIntValidator* val = new QIntValidator(1, 1000, ui -> Dish_count);
    ui -> Dish_count -> setValidator(val);

    ui -> treeWidget -> setColumnCount(2);
    ui -> treeWidget -> setColumnWidth(0, 150);
    ui -> treeWidget -> setColumnWidth(1, 150);

    ui -> treeWidget -> setHeaderLabels({"Блюдо", "Кол-во"});
}

List_create_menu::~List_create_menu()
{
    delete ui;
}

void List_create_menu::Reseive_path(const QString& File_path) {
    QFile File(File_path);
    QTextStream stream(&File);

    qDebug() << File_path;
    QString line;

    if(File.open(QIODevice::ReadOnly | QIODevice::Text)) {

        if(!stream.atEnd()){
            while(!stream.atEnd()){
                line = stream.readLine();
                qDebug() << "line" <<line;
                ui -> comboBox -> addItem(line);

                line = stream.readLine();
                line = stream.readLine();
            }
        }
        else{
            qDebug() << "End";
        }
    }

}

void List_create_menu::on_Cancel_button_clicked()
{
    ui -> comboBox -> clear();
    close();
}




void List_create_menu::on_Dish_count_textChanged(const QString &arg1)
{
    ui -> Add_dish_button -> setEnabled(true);
}


void List_create_menu::on_Add_dish_button_clicked()
{
    QTreeWidgetItem* TreeItem = new QTreeWidgetItem(ui -> treeWidget);
    TreeItem -> setText(0, ui -> comboBox -> currentText());
    TreeItem -> setText(1, ui -> Dish_count -> text());

    ui -> Dish_count -> setText("");
    ui -> Add_dish_button -> setEnabled(false);
    third = true;
    if(first && second && third){
        ui -> Add_order_button -> setEnabled(true);
    }
}


void List_create_menu::on_Order_number_line_textChanged(const QString &arg1)
{
    first = true;
    if(first && second && third){
        ui -> Add_order_button -> setEnabled(true);
    }
}


void List_create_menu::on_Table_number_line_textChanged(const QString &arg1)
{
    second = true;
    if(first && second && third){
        ui -> Add_order_button -> setEnabled(true);
    }
}


void List_create_menu::on_Add_order_button_clicked()
{

    QString current_path = QDir::currentPath() + "/orders";

    QDir dir(current_path);

    if(!dir.exists()){
        dir.mkdir(current_path);
    }

    QFile file(current_path +"/" + ui -> Order_number_line -> text());
    QTextStream stream(&file);

    if(!QFile::exists(current_path +"/" + ui -> Order_number_line -> text())){
        if(file.open(QIODevice::Append | QIODevice::Text)){

            stream << ui -> Order_number_line -> text() << '\n';
            stream << ui -> Table_number_line -> text() << '\n';

            int count_of_lines = ui -> treeWidget -> topLevelItemCount();
            int count_of_colums = ui -> treeWidget -> columnCount();

            QVariant temp;
            QString data;

            QTreeWidgetItem* tree_item;

            for(int i = 0; i < count_of_lines; ++i) {
                tree_item = ui -> treeWidget -> topLevelItem(i);

                for(int j = 0; j < count_of_colums; ++j){
                    temp = tree_item -> data(j, Qt::DisplayRole);
                    data = temp.toString();

                    stream << data << '\n';
                }
            }

            file.close();
        }
        else{
            qDebug() << "SOS";
        }
    }
    else{
//        QString name, count, data_name_in_file, data_count_in_file;
//        QVariant temp, temp_1;

//        name = stream.readLine();
//        name = stream.readLine();

//        QTreeWidgetItem* item = ui -> treeWidget -> topLevelItem(0);

//        temp = item -> data(0, Qt::DisplayRole);
//        temp_1 = item -> data(1,Qt::DisplayRole);

//        data_name_in_file = temp.toString();
//        data_count_in_file = temp_1.toString();

//        name = stream.readLine();
//        count = stream.readLine();

//        if(name == data_name_in_file) {

//            for(int i = 1; name == data_name_in_file && count == data_count_in_file; ++i) {

//                name = stream.readLine();
//                count = stream.readLine();

//                item = ui -> treeWidget -> topLevelItem(i);

//                temp = item -> data(0, Qt::DisplayRole);
//                temp_1 = item -> data(1, Qt::DisplayRole);

//                data_name_in_file = temp.toString();
//                data_count_in_file = temp_1.toString();

//                qDebug() << "name" << name;
//                qDebug() << "data" << data_name_in_file;

//            }
//        }
//        else{

//        }

    }
    emit Send_path(current_path +"/" + ui -> Order_number_line -> text());
    ui -> Order_number_line -> setText("");
    ui -> Table_number_line -> setText("");
    ui -> treeWidget -> clear();
    ui -> comboBox -> clear();
    close();
}

