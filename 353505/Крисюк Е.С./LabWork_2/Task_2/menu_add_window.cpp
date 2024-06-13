#include "menu_add_window.h"
#include "ui_menu_add_window.h"

Menu_add_window::Menu_add_window(QWidget *parent) :QDialog(parent), ui(new Ui::Menu_add_window)
{
    ui->setupUi(this);
    ui -> Prise_line -> setInputMask("");

    QIntValidator* val = new QIntValidator(0, 999999, ui -> Prise_line);
    ui -> Prise_line -> setValidator(val);
    ui -> Prise_line -> setMaxLength(6);
//    ui -> Description_line -> setMaximumSize(10);

}

Menu_add_window::~Menu_add_window()
{
    delete ui;
}

void Menu_add_window::on_Cancel_button_clicked()
{
     close();
}

void Menu_add_window::on_Add_button_clicked()
{
     QString Dish_data, Prise, Description;
     Dish_data = ui -> Dish_name_line -> text();
     Prise = ui -> Prise_line -> text();
     Description = ui -> Description_line -> toPlainText();

     first = false;
     second = false;
     third = false;

     ui -> Prise_line -> setText("");
     ui -> Description_line -> setText("");
     ui -> Dish_name_line -> setText("");

     ui -> Add_button -> setEnabled(false);

     QFile file(File_path);

     if(file.open(QIODevice::Append | QIODevice::Text)) {
         QTextStream stream(&file);
         stream << Dish_data << '\n' << Prise << '\n' << Description << '\n';
         file.close();

     }
     else {
         qDebug() << "файл не открылся";
     }
     emit Send_message(File_path);
     qDebug() << File_path;
}

void Menu_add_window::on_Save_button_clicked()
{
     QString current_path = QDir::currentPath();
     current_path += "/menu";

     QDir Menu_dir(current_path);

     if(!Menu_dir.exists())
        QDir().mkdir(current_path);
     
     
     File_path = QFileDialog::getSaveFileName(nullptr, "Сохранить меню", current_path, "Все файлы (*)");

     fourth = true;

     if(first && second && third && fourth) {
         ui -> Add_button -> setEnabled(true);
     }
     if(!File_path.isEmpty()) {
         ui -> Save_button -> setEnabled(false);
     }


}


void Menu_add_window::on_Dish_name_line_textChanged(const QString &arg1)
{
     first = true;
     if(first && second && third && fourth) {
         ui -> Add_button -> setEnabled(true);
     }

}


void Menu_add_window::on_Description_line_textChanged()
{
     second = true;
     if(first && second && third && fourth) {
         ui -> Add_button -> setEnabled(true);
     }
}


void Menu_add_window::on_Prise_line_textChanged(const QString &arg1)
{
     third = true;
     if(first && second && third && fourth) {
         ui -> Add_button -> setEnabled(true);
     }
}
