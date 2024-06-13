#include "information_view.h"
#include "ui_information_view.h"

Information_View::Information_View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_View)
{
    ui->setupUi(this);
}

Information_View::~Information_View()
{
    delete ui;
}

void Information_View::Reseive_data(const QString &file_path, const QString &menu_path){
    QFile file(file_path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        QString line;
        line = stream.readLine();
        ui -> Order_number_line -> setText(line);

        line = stream.readLine();
        ui -> Table_number_line -> setText(line);

        ui -> Order_number_line -> setReadOnly(true);
        ui -> Table_number_line -> setReadOnly(true);

        ui -> treeWidget -> setColumnCount(4);
        ui -> treeWidget -> setColumnWidth(0,80);
        ui -> treeWidget -> setColumnWidth(1,80);
        ui -> treeWidget -> setColumnWidth(2,110);
        ui -> treeWidget -> setColumnWidth(3,140);

        ui -> treeWidget -> setHeaderLabels({"Блюдо" , "Количество", "Цена,$", "Сумма,$"});
        QTreeWidgetItem* item;
        QFile menu_file(menu_path);

        if(menu_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        }
        else {
            qDebug() << "123";
        }
        QTextStream menu_stream(&menu_file);

        long long result = 0;

        while(!stream.atEnd()){
            menu_stream.seek(0);

            line = stream.readLine();
            item = new QTreeWidgetItem;

            item -> setText(0,line);
            QString menu_line;

            while(menu_line != line) {
                menu_line = menu_stream.readLine();
            }

            line = stream.readLine();

            item -> setText(1,line);

            menu_line = menu_stream.readLine();

            item -> setText(2,menu_line);

            long long num_1 = line.toInt();
            long long num_2 = menu_line.toInt();

            long long sum = num_1 * num_2;
            result += sum;
            QString result_sum = QString::number(sum);

            item -> setText(3, result_sum);
            ui -> treeWidget -> addTopLevelItem(item);
        }

        ui -> Check_line -> setText(QString::number(result));
        emit(Send_check(QString::number(result)));

    }

    else{
        qDebug() << "файл не открылся";
    }

}

void Information_View::on_Cancel_button_clicked()
{
    ui -> Order_number_line -> setText("");
    ui -> Table_number_line -> setText("");
    ui -> treeWidget -> clear();

    close();
}

