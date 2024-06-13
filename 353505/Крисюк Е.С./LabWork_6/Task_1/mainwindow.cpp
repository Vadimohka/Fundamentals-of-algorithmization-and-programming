#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDoubleValidator* val = new QDoubleValidator(0,9999, 3);

    ui -> height_line -> setValidator(val);
    ui -> length_line -> setValidator(val);
    ui -> width_line -> setValidator(val);

    Airport airport = {4, 6.7, true, 'I', "Domodedovo", {250, 150, 100}};

    QIntValidator* count_val = new QIntValidator(0,999);
    ui -> airplanes_count_line -> setValidator(count_val);

    QDoubleValidator* double_val = new QDoubleValidator(0,99,5);

    ui -> road_line -> setValidator(double_val);

    set_struct_to_window(airport);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_struct_to_window(Airport airport){

    QString count_of_flights = QString::number(airport.count_of_flights);

    QString road_length = QString::number(airport.road_length);

    QString is_international;
    if(airport.is_international){
        is_international = "True";
    }
    else{
        is_international = "False";
    }

    QString type = QString(airport.type);

    QString airport_name = QString(airport.airport_name);

    QString length = QString::number(airport.size[0]);
    QString width = QString::number(airport.size[1]);
    QString height = QString::number(airport.size[2]);

    ui -> textEdit -> setText(count_of_flights + '|' + road_length + '|' + is_international + '|' + type + '|' + airport_name + '|' + length + '|' + width + '|' + height + '|');
}

bool MainWindow::Is_all_fields_empty(){
    bool is_true = true;

    if(ui -> airplanes_count_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> road_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> type_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> name_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> width_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> length_line -> text() == ""){
        is_true = false;
    }
    else if(ui -> height_line -> text() == ""){
        is_true = false;
    }
    return is_true;
}

void MainWindow::on_Create_button_clicked()
{
    if(!Is_all_fields_empty()){
        QMessageBox::warning(nullptr,"Предупреждение", "Не все поля введены");
    }
    else{
        int index = ui -> create_structure_combobox -> currentIndex();

        if(index == 0){
            Airport airport;

            airport.count_of_flights = ui -> airplanes_count_line -> text().toInt();
            airport.road_length = ui -> road_line -> text().replace(',', '.').toDouble();
            airport.is_international = ui -> international_combobox -> currentIndex() == 0;
            airport.type = ui -> type_line -> text().toStdString()[0];

            int index;
            for(int i = 0; i < ui -> name_line -> text().length(); ++i){
                airport.airport_name[i] = ui -> name_line -> text().toStdString()[i];
                index = i;
            }
            if(index != 50){
                airport.airport_name[index + 1] = '\0';
            }

            airport.size[0] = ui -> length_line -> text().replace(',', '.').toDouble();
            airport.size[1] = ui -> width_line -> text().replace(',', '.').toDouble();
            airport.size[2] = ui -> height_line -> text().replace(',', '.').toDouble();

            set_struct_to_window(airport);

        }

        else if(index == 1){

            Airport airport;
            Airport* airport_prt = &airport;

            airport_prt -> count_of_flights = ui -> airplanes_count_line -> text().toInt();
            airport_prt -> road_length = ui -> road_line -> text().replace(',', '.').toDouble();
            airport_prt -> is_international = ui -> international_combobox -> currentIndex() == 0;
            airport_prt -> type = ui -> length_line -> text().toStdString()[0];

            int index;
            for(int i = 0; i < ui -> name_line -> text().length(); ++i){
                airport_prt -> airport_name[i] = ui -> name_line -> text().toStdString()[i];
                index = i;
            }
            if(index != 50){
                airport.airport_name[index + 1] = '\0';
            }

            airport.airport_name[index + 1] = '\0';
            airport_prt -> size[0] = ui -> length_line -> text().replace(',', '.').toDouble();
            airport_prt -> size[1] = ui -> width_line -> text().replace(',', '.').toDouble();
            airport_prt -> size[2] = ui -> height_line -> text().replace(',', '.').toDouble();

            set_struct_to_window(airport);

        }

        else{

            Airport airport;
            Airport& airport_ref = airport;

            airport_ref.count_of_flights = ui -> airplanes_count_line -> text().toInt();
            airport_ref.road_length = ui -> road_line -> text().replace(',', '.').toDouble();
            airport_ref.is_international = ui -> international_combobox -> currentIndex() == 0;
            airport_ref.type = ui -> length_line -> text().toStdString()[0];

            int index;

            for(int i = 0; i < ui -> name_line -> text().length(); ++i){
                airport.airport_name[i] = ui -> name_line -> text().toStdString()[i];
                index = i;
            }
            if(index != 50){
                airport.airport_name[index + 1] = '\0';
            }

            airport.airport_name[index + 1] = '\0';

            airport_ref.size[0] = ui -> length_line -> text().replace(',', '.').toDouble();
            airport_ref.size[1] = ui -> width_line -> text().replace(',', '.').toDouble();
            airport_ref.size[2] = ui -> height_line -> text().replace(',', '.').toDouble();

            set_struct_to_window(airport);

        }
    }
}

