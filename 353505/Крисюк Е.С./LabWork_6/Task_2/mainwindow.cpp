#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QInputDialog>
#include <QTimer>
#include <QIntValidator>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> stackedWidget -> setCurrentIndex(0);

    Labname_path = QDir::currentPath() + "/KrisyukLab20.txt";
    Lab_name_0_path = QDir::currentPath() + "/KrisyukLab20_0.txt";

    Txt_path = QDir::currentPath() + "/KrisyukLab20_1.txt";
    Bin_path = QDir::currentPath() + "/KrisyukLab20_2.bin";

    index = 0;

    edit = new MyTextEdit(ui -> stackedWidget);
    connect(edit, &MyTextEdit::Put_text_to_MainWindow, this, &MainWindow::SetTextToFile_20);

    edit -> move(50,140);
    edit -> resize(451,221);


    array = new int[0];

    QIntValidator* val_1 = new QIntValidator(0,99);

    ui -> Text_page_input_line -> setValidator(val_1);

    QDoubleValidator* val = new QDoubleValidator(0,9999, 3);

    ui -> height_line_4 -> setValidator(val);
    ui -> length_line_4 -> setValidator(val);
    ui -> width_line_4 -> setValidator(val);

    QIntValidator* count_val = new QIntValidator(0,999);
    ui -> airplanes_count_line_4 -> setValidator(count_val);

    QDoubleValidator* double_val = new QDoubleValidator(0,99,5);

    ui -> road_line_4 -> setValidator(double_val);

    ui -> stackedWidget -> setCurrentIndex(index);

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]() mutable{

        Start();
        timer -> stop();
    });
    timer -> start(10);

}

MainWindow::~MainWindow()

{
    QApplication::exit();
    delete ui;
}


void MainWindow::Start(){


    while(true){

        QCoreApplication::processEvents();

        Switch_menu();

    }

}

void MainWindow::Switch_menu(){

    switch (index){

    case 0:
        ui -> comboBox -> setCurrentIndex(0);
        if(!edit -> isHidden()){

            edit -> setFocus();
        }
        break;

    case 1:
        ui -> comboBox -> setCurrentIndex(1);
        ui -> second_page_text_edit -> setFocus();
        Add_text_to_mainwindow_choose_2();

        break;

    case 2:
        ui -> comboBox -> setCurrentIndex(2);
        break;

    case 3:
        ui -> comboBox -> setCurrentIndex(3);

        Add_text_to_mainwindow_from_array();

        break;

    case 4:
        ui -> comboBox -> setCurrentIndex(4);
        break;

    case 5:
        ui -> comboBox -> setCurrentIndex(5);
        Add_structs_txt_to_window();
        break;

    case 6:
        ui -> comboBox -> setCurrentIndex(6);
        Add_structs_bin_to_window();

        break;

    case 8:

        QApplication::exit();
        close();

        break;

    default:
        setFocus();
        break;

    }
}

void MainWindow::SetTextToFile_20(QString &text){

    QFile file(Labname_path);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);

        wchar_t* wchar_array = new wchar_t[text.length() + 1];

        text.toWCharArray(wchar_array);

        wchar_array[text.length()] = L'\0';

        for(int i = 0; wchar_array[i] != L'\0'; ++i){
            stream << wchar_array[i] << ' ';
        }

        file.close();

        edit -> clear();
    }
    else {
        qDebug() << "no SetTextToFile_20";
    }

}

void MainWindow::Add_text_to_mainwindow_choose_2(){

    QFile file(Labname_path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        QString text;

        while(!stream.atEnd()){
            text+= stream.read(1);
        }
        file.close();

        QStringList numbersList = text.split(" ");

        QString result;

        foreach (const QString& number, numbersList) {
            bool ok;
            int asciiCode = number.toInt(&ok);
            if (ok) {
                result += QChar(asciiCode);
            }
        }

        ui->second_page_text_edit->setText(result);


        index = -1;
    }
    else {
        qDebug() << "no SetTextToFile_20";
    }
}

void MainWindow::Set_text_to_file_name_0(int length){

    QFile file(Lab_name_0_path);

    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);
        file.resize(0);

        for(int i = 0 ; i < length; ++i){
            stream << array[i] << "~";
        }

        file.close();

    }
}
void MainWindow::on_comboBox_currentIndexChanged(int index1)
{

    int current_index = ui -> stackedWidget -> currentIndex();

    if(current_index != index1){
        index = index1;
        ui -> stackedWidget -> setCurrentIndex(index1);

        if(index == 0){
            edit -> setHidden(false);
        }
        else{
            edit -> setHidden(true);
        }
    }
}


void MainWindow::on_Text_page_input_line_textChanged(const QString &text)
{
    delete[]array;
    
    if(text != ""){
        ui -> Array_page_text_edit -> setReadOnly(false);

    }

    else{
        ui -> Text_page_input_line -> setText("0");

    }

    array = new int[text.toInt()];

}

void MainWindow::Add_text_to_mainwindow_from_array(){

    QFile file(Lab_name_0_path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        qDebug() << "open";

        QString symbol = "";
        QString element;
        QStringList list;

        while(!stream.atEnd()){

            for(int i = 0; symbol != "~"; ++i){
                element += symbol;
                symbol = stream.read(1);
            }

            list.append(element);

            symbol.clear();

            element.clear();
        }

        file.close();

        QString result;

        for(int i = 0; i < list.length(); ++i){
            result += list[i] + " ";
        }

        ui -> Array_output_text_edit -> setText(result);


        index = -1;
    }
    else {
        qDebug() << "no SetTextToFile_20";
    }

}


void MainWindow::on_Array_page_text_edit_textChanged()
{
    QString text = ui -> Array_page_text_edit -> toPlainText();

    QStringList list = text.split(' ');

    int line_length = ui -> Text_page_input_line -> text().toInt();

    int index;

    for(int i = 0; i < list.length() && line_length; ++i){
        array[i] = list[i].toInt();
        index = i;
    }

    Set_text_to_file_name_0(index);

}


void MainWindow::on_Create_button_clicked()
{
    Airport airport;

    airport.count_of_flights = ui -> airplanes_count_line_4 -> text().toInt();
    airport.road_length = ui -> road_line_4 -> text().replace(',', '.').toDouble();
    airport.is_international = ui -> international_combobox_4 -> currentIndex() == 0;
    airport.type = ui -> type_line_4 -> text().toStdString()[0];

    int index;
    for(int i = 0; i < ui -> name_line_4 -> text().length(); ++i){
        airport.airport_name[i] = ui -> name_line_4 -> text().toStdString()[i];
        index = i;
    }
    if(index != 50){
        airport.airport_name[index + 1] = '\0';
    }

    airport.size[0] = ui -> length_line_4 -> text().replace(',', '.').toDouble();
    airport.size[1] = ui -> width_line_4 -> text().replace(',', '.').toDouble();
    airport.size[2] = ui -> height_line_4 -> text().replace(',', '.').toDouble();

    int choose = ui -> create_structure_combobox -> currentIndex();

    if(choose == 0){
        Add_struct_to_txt_file(airport);
    }
    else if(choose == 1){
       Add_struct_to_bin_file(airport);
    }

}

void MainWindow::Add_struct_to_txt_file(Airport &airport){

    QFile file(Txt_path);

    if(file.open(QIODevice::Append | QIODevice:: Text)){
       QTextStream stream(&file);

       qDebug() << airport.type;

       stream << airport.count_of_flights << '\n';
       stream << airport.road_length << '\n';
       stream << airport.is_international << '\n';
       stream << airport.type << '\n';
       stream << airport.airport_name << '\n';
       stream << airport.size[0] << '\n';
       stream << airport.size[1] << '\n';
       stream << airport.size[2] << '\n';

       file.close();

       index = -1;

    }
}

void MainWindow::Add_struct_to_bin_file(Airport &airport){

    QFile file(Bin_path);

    if(file.open(QIODevice::Append | QIODevice::WriteOnly)){
       QDataStream stream(&file);

       stream.writeRawData(reinterpret_cast<const char*>(&airport), sizeof(airport));

       file.close();

       index = -1;

    }

}

void MainWindow::Add_structs_bin_to_window(){
    Airport airport;

    QFile file(Bin_path);

    if(file.open(QIODevice::ReadOnly)){
       QDataStream stream(&file);
       QString result;

       while(stream.readRawData(reinterpret_cast<char*>(&airport), sizeof(airport))){

            result += QString::number(airport.count_of_flights) + "|";
            result += QString::number(airport.road_length) + "|";
            if(airport.is_international){
                result += "True|";
            }
            else{
                result += "False|";
            }

            result += QString(airport.type) + "|";
            result += QString(airport.airport_name) + "|";
            result += QString::number(airport.size[0]) + "|";
            result += QString::number(airport.size[1]) + "|";
            result += QString::number(airport.size[2]) + "|";

            result += "\n";
            qDebug() << result;

       }

       ui -> Output_struct_bin_text_edit -> insertPlainText(result);

       file.close();



       index = -1;

    }

}

void MainWindow::Add_structs_txt_to_window(){
    QFile file(Txt_path);

    if(file.open(QIODevice::ReadOnly | QIODevice:: Text)){
       QTextStream stream(&file);
       QString result;

       while(!stream.atEnd()){

            result += stream.readLine() + "|";
            result += stream.readLine() + "|";
            QString is_international = stream.readLine();
            if(is_international == "1"){
                result += "True|" ;
            }
            else{
                result += "False|" ;
            }
            result += stream.readLine() + "|";
            result += stream.readLine() + "|";
            result += stream.readLine() + "|";
            result += stream.readLine() + "|";
            result += stream.readLine() + "|";

            result += "\n";

            ui -> Output_struct_txt_text_edit -> insertPlainText(result);
            result.clear();
       }

       file.close();

       index = -1;

    }

}
