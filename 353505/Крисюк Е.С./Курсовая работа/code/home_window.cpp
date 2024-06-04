#include "home_window.h"
#include "ui_home_window.h"
#include "allusersfile.h"
#include <QScrollArea>

extern Bank_meneger& meneger;

Home_window::Home_window(long long user_index, QWidget *parent) :QDialog(parent),ui(new Ui::Home_window)
{
    ui->setupUi(this);

    ui -> stackedWidget -> setCurrentIndex(0);
    scene = new QGraphicsScene();

    ui -> graphicsView -> setScene(scene);

    this -> user_index = user_index;

    ui -> Transactions_table_widget -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    current_card = new Card();

    Add_Personal_user_data_to_window();

    Add_cards_to_scene();

    Update_transaction_table();

    Add_cards_to_window();
}

Home_window::~Home_window()
{
    delete ui;
}

void Home_window::on_Exit_button_clicked()
{

    emit(OpenMainWindow());
    this -> close();
}

void Home_window::Add_Personal_user_data_to_window(){

    ui -> Name_line -> setText(meneger.GetUserName(user_index));
    ui -> Middle_name_line -> setText(meneger.GetUserMiddlename(user_index));
    ui -> Surname_line -> setText(meneger.GetUserSurname(user_index));

    ui -> Birthday_line -> setText(meneger.GetUserBirthDay(user_index).toString("dd.MM.yyyy"));

    ui -> Login_line -> setText(meneger.GetUserLogin(user_index));
    ui -> Email_line -> setText(meneger.GetUserEmail(user_index));


}

void Home_window::Add_cards_to_window(){

    for(int i = 0 ; i < meneger.Get_user_card_count(user_index); ++i){
        ui -> Cards_combo_box -> addItem(meneger.Get_user_card_number(user_index, i));
    }

    if(meneger.Get_user_card_count(user_index) > 0){

        current_card = meneger.Get_user_card(user_index, 0);

        ui -> Card_number_line -> setText(current_card -> GetCardNumber());

        card_rect = new Card_rect(current_card);
        card_rect -> Add_card_to_scene(scene);
    }


}

void Home_window::on_Account_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void Home_window::on_Cards_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(1);

    if(meneger.Get_user_card_count(user_index) == 0){
        QMessageBox* box = new QMessageBox();

        box -> setWindowTitle("Предупреждение");
        box -> setText("У вас нет зарегестрированных карт");

        box -> exec();
    }
}

void Home_window::on_Transactions_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);

    if(meneger.Get_user_card_count(user_index) == 0){
        QMessageBox* box = new QMessageBox();

        box -> setWindowTitle("Предупреждение");
        box -> setText("У вас нет зарегестрированных карт");

        box -> exec();
    }
}


void Home_window::Add_cards_to_scene(){
    scene -> clear();



}

void Home_window::on_Card_data_button_clicked()
{

    if(meneger.Get_user_card_count(user_index) > 0){
        card_data_window = new Card_data_window(user_index,current_card);
        card_data_window -> exec();

        Update_transaction_table();
        scene -> clear();

        card_rect = new Card_rect(current_card);
        card_rect -> Add_card_to_scene(scene);
    }
    else{
        QMessageBox::warning(nullptr, "Предупреждение", "У вас нет карт, зарегестрируйте");
    }
}


void Home_window::on_stackedWidget_currentChanged(int index)
{
    ui -> Account_button -> setStyleSheet("color: white;");
    ui -> Cards_button -> setStyleSheet("color: white;");
    ui -> Transactions_button -> setStyleSheet("color: white;");


    if(index == 0){
        ui -> Account_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 1){
        ui -> Cards_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 2){
        ui -> Transactions_button -> setStyleSheet("background-color:blue;color: white;");
    }
}

void Home_window::on_menu_change_size_button_toggled(bool checked)
{
    qreal width = ui -> menu_card_frame -> width();
    qreal height = ui -> menu_card_frame -> height();

    QTimer* timer = new QTimer(this);

    timer -> setInterval(1);

    if(checked){

        connect(timer, &QTimer::timeout, this, [=] () mutable{
            if(width > ui -> menu_change_size_button -> x() + ui -> menu_change_size_button -> width() + 20){
                width -= 5;
                ui -> menu_card_frame -> resize(width, height);
            }
            else{
                timer -> stop();
            }
        });
    }
    else{

        connect(timer, &QTimer::timeout, this, [=] () mutable{
            if(width < ui -> Register_new_card_button -> x() + ui -> Register_new_card_button -> width() + 20){
                width += 5;
                ui -> menu_card_frame -> resize(width, height);
            }
            else{
                timer -> stop();
            }
        });
    }

    timer -> start();
}

void Home_window::Update_transaction_table(){


    ui -> Transactions_table_widget -> setColumnCount(3);

    for(int i = 0 ; i < 3; ++i){
        ui -> Transactions_table_widget -> setColumnWidth(i,ui -> Transactions_table_widget -> width() / 3);
    }

    Bank_account* account = current_card -> Get_bank_account();

    QTableWidgetItem* item;

    int current_row_count = 0;

    for(int i = 0; i < current_card -> Get_banking_app_transsactions_count(); ++i){
        ui -> Transactions_table_widget -> setRowCount(current_row_count + 1);

        item = new QTableWidgetItem();

        item -> setText(account -> Get_transactions_time(i).toString("hh:mm:ss dd-MM-yyyy"));

        ui -> Transactions_table_widget -> setItem(current_row_count, 0, item);

        item = new QTableWidgetItem();
        item -> setText(account -> Get_transactions_state(i));

        ui -> Transactions_table_widget -> setItem(current_row_count, 1, item);


        item = new QTableWidgetItem();

        item -> setText(AllUsersFile::From_long_double_to_QString(account -> Get_transactions_money(i)));

        ui -> Transactions_table_widget -> setItem(current_row_count, 2, item);

        current_row_count++;
    }


}

void Home_window::on_Register_new_card_button_clicked()
{

    register_new_card_window = new Register_new_card_window(user_index);
    register_new_card_window -> exec();

    ui -> Cards_combo_box -> addItem(meneger.Get_user_card_number(user_index, meneger.Get_user_card_count(user_index) -1));

    ui -> Cards_combo_box -> setCurrentIndex(meneger.Get_user_card_count(user_index) - 1);
}


void Home_window::on_Transfer_money_button_clicked()
{
    if(meneger.Get_user_card_count(user_index) > 0){
        transfer_money_window = new Transfer_money_window();
        transfer_money_window -> exec();

        Update_transaction_table();

        scene -> clear();

        card_rect = new Card_rect(current_card);
        card_rect -> Add_card_to_scene(scene);
    }
    else{
        QMessageBox::warning(nullptr, "Предупреждение", "У вас нет карт, зарегестрируйте");
    }

}


void Home_window::on_Pay_the_bill_button_clicked()
{
    if(meneger.Get_user_card_count(user_index) > 0){

        pay_the_bill_window = new Pay_the_bill_window(user_index,current_card);
        pay_the_bill_window -> exec();

        Update_transaction_table();

        scene -> clear();

        card_rect = new Card_rect(current_card);
        card_rect -> Add_card_to_scene(scene);
    }
    else{
        QMessageBox::warning(nullptr, "Предупреждение", "У вас нет карт, зарегестрируйте");
    }
}


void Home_window::on_Cards_combo_box_currentIndexChanged(int index)
{

    current_card = meneger.Get_user_card(user_index, index);

    Update_transaction_table();
    ui -> Card_number_line -> setText(current_card -> GetCardNumber());

    scene -> clear();

    card_rect = new Card_rect(current_card);
    card_rect -> Add_card_to_scene(scene);

}

