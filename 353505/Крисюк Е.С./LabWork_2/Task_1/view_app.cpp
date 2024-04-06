#include "view_app.h"
#include "ui_view_app.h"

View_App::View_App(QWidget *parent) :QDialog(parent),ui(new Ui::View_App)
{
    ui->setupUi(this);


}


void View_App::App_open(QList<Date> Date_list, QString Birthday_date, int index)
{
    this -> Date_list = Date_list;

    qDebug() << index;
    ui -> Next_day_line -> setText(Date_list[index].Next_Day(Date_list[index].Current_date));
    ui -> Previous_day_line -> setText(Date_list[index].Previous_Day(Date_list[index].Current_date));
    ui -> Week_number_line -> setText(QString::number(Date_list[index].Week_Number(Date_list[index].Current_date)));

    ui -> Days_till_birthday -> setText(QString::number(Date_list[index].Days_Till_Your_Bithday(Birthday_date)));

    if(Date_list[index].Is_Leap(ui -> User_input_date_line -> text())){
        ui -> Is_Lepp_line -> setText("Да");
    }
    else{
        ui -> Is_Lepp_line -> setText("Нет");
    }
    ui -> Days_between_line -> setText(QString::number(Date_list[0] . Duration(ui -> User_input_date_line -> text())));

}

View_App::~View_App()
{
    delete ui;
}

void View_App::on_User_input_date_line_userDateChanged(const QDate &date)
{
    if(Date_list[0].Is_Leap(ui -> User_input_date_line -> text())){
        ui -> Is_Lepp_line -> setText("Да");
    }

    else{
        ui -> Is_Lepp_line -> setText("Нет");
    }

    ui -> Days_between_line -> setText(QString::number(Date_list[0] . Duration(ui -> User_input_date_line -> text())));
}

