#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> User_birthday -> setCalendarPopup(true);

    ui -> Table -> setSelectionBehavior(QAbstractItemView::SelectRows);
    ui -> Table -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> Table -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    current_index = ui -> Table -> currentIndex().row();
    count_of_columns = 3;
    count_of_row = 4;

    ui -> Table -> setRowCount(count_of_row);
    ui -> Table -> setColumnCount(count_of_columns);

    for(int i = 0; i < 4; ++i){
        ui -> Table -> setRowHeight(i,35);
    }

    for (int i = 0; i < 2; ++i) {
        ui -> Table -> setColumnWidth(i,520 / 3);
    }


    QStringList List;

    List << "День" << "Месяц" << "Год";

    ui -> Table -> setHorizontalHeaderLabels(List);



    current_path = QDir::currentPath() + "/files" + "/original";

    qDebug() << current_path;
    QDir dir;
    if(!dir.exists(current_path)){
        dir.mkpath(current_path);
    }

    QFile file(current_path);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "open";
        QTextStream stream(&file);
        stream << "01.01.0001" << '\n' << "24.04.2000" << '\n' << "29.02.2000" << '\n' << "31.12.2021" << '\n';
        file.close();
    }
    else{
        qDebug() << "123";
    }
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        QTableWidgetItem* item;

        QString line;
        QString  day;
        int row = 0, column = 0;

        while(!stream.atEnd()){
            column = 0;
            line = stream.readLine();
            Date date;
            date.Current_date = line;
            Date_list << date;

            for(int j = 0; j < 3; ++j){
                for(int i = 0; i < line.length(); ++i){
                    if(line[i] == '.'){
                        day = line.mid(0,i);
                        line.remove(0,i + 1);
                        break;
                    }
                    else{
                        day = line;
                    }
                }
                item = new QTableWidgetItem(day);
                ui -> Table -> setItem(row,column,item);
                column++;
            }
            row++;
        }
    }

    menu = new QMenu(this);
    ui -> Table -> setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui ->Table, &QTableWidget::customContextMenuRequested, this, &MainWindow::View_Menu);

    QAction* view = new QAction("Просмотреть", this);
    menu -> addAction(view);

    connect(view, &QAction::triggered, this, &MainWindow::View_all_information);

    QAction* add = new QAction("Добавить", this);
    menu -> addAction(add);

    connect(add, &QAction::triggered, this, &MainWindow::Add_information);

    QAction* delete_menu_item = new QAction("Удалить", this);
    menu -> addAction(delete_menu_item);

    connect(delete_menu_item, &QAction::triggered, this, &MainWindow::Delete_information);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::View_Menu(){

    menu -> exec(QCursor::pos());
}


void MainWindow::View_all_information(){

    view_app = new View_App();
    connect(this, &MainWindow::App_is_open, view_app, &View_App::App_open);

    emit(App_is_open(Date_list, ui -> User_birthday -> text(), current_index));
    view_app -> exec();
}



void MainWindow::on_Table_itemSelectionChanged()
{
    current_index = ui -> Table -> currentIndex().row();
}

void MainWindow::Add_information(){

    current_index = ui -> Table -> currentIndex().row();
    add_to_table = new Add_to_Table();

    add_to_table -> setModal(true);
    connect(add_to_table, &Add_to_Table::Send_new_day, this, &MainWindow::Reseive_new_day);
    add_to_table -> exec();



}

void MainWindow::Reseive_new_day(QString Date){

    QFile File(current_path);

    if(File.open(QIODevice::QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&File);
        qint64 total_size = 0;

        int count = 0;
        qint64 temp;
        QString line;

        while(count < current_index){
            count++;
            line = stream.readLine();

            temp = line.toUtf8().size() + 1;
            total_size += temp;
        }

        QList <QString> list;

        while(!stream.atEnd()){
            qDebug() << "12";
            list << stream.readLine();
        }

        File.seek(total_size);


        stream << Date << '\n';
        qDebug() << Date;

        for(int i = 0; i < list.size(); ++i){
            stream  << list[i] << '\n';
        }

        File.close();

    }
    else{
        qDebug() << "Файл не открылся";
    }

    count_of_row++;
    ui -> Table -> setRowCount(count_of_row);

    if(File.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&File);
        QTableWidgetItem* item;

        QString line;
        QString  day;
        int row = 0, column = 0;
        Date_list.clear();

        while(!stream.atEnd()){
            column = 0;
            line = stream.readLine();

            class Date date;

            date.Current_date = line;
            Date_list << date;


            for(int j = 0; j < 3; ++j){
                for(int i = 0; i < line.length(); ++i){
                    if(line[i] == '.'){
                        day = line.mid(0,i);
                        line.remove(0,i + 1);
                        break;
                    }
                    else{
                        day = line;
                    }
                }
                item = new QTableWidgetItem(day);
                ui -> Table -> setItem(row,column,item);
                column++;
            }
            row++;
        }
        qDebug() << "len" << Date_list.length();
    }



}

void MainWindow::Delete_information(){

    QFile File(current_path);

    if(File.open(QIODevice::QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&File);
        qint64 total_size = 0;

        int count = 0;
        qint64 temp;
        QString line;

        while(count < current_index ){
            count++;
            line = stream.readLine();

            temp = line.toUtf8().size() + 1;
            total_size += temp;
        }

        line = stream.readLine();
        QList <QString> list;

        while(!stream.atEnd()){
            list << stream.readLine();
        }

        File.seek(total_size);


        qDebug() << "length" << list.length();


        File.resize(total_size);
        for(int i = 0; i < list.length(); ++i){
            stream << list[i] << '\n';
        }

        File.close();
    }

    if(File.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&File);

        count_of_row--;

        ui -> Table -> clear();
        ui -> Table -> setRowCount(count_of_row);

        File.seek(0);

        QString line;
        QTableWidgetItem* item;
        QString  day;
        int row = 0, column = 0;
        Date_list.clear();

        while(!stream.atEnd()){
            column = 0;
            line = stream.readLine();

            class Date date;

            date.Current_date = line;
            Date_list << date;


            for(int j = 0; j < 3; ++j){
                for(int i = 0; i < line.length(); ++i){
                    if(line[i] == '.'){
                        day = line.mid(0,i);
                        line.remove(0,i + 1);
                        break;
                    }
                    else{
                        day = line;
                    }
                }
                item = new QTableWidgetItem(day);
                ui -> Table -> setItem(row,column,item);
                column++;
            }
            row++;
        }

        File.close();

        QStringList List;

        List << "День" << "Месяц" << "Год";

        ui -> Table -> setHorizontalHeaderLabels(List);
    }
}
