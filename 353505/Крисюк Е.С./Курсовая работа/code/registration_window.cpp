#include "registration_window.h"
#include "ui_registration_window.h"

extern Bank_meneger& meneger;

Registration_window::Registration_window(QWidget *parent) :QDialog(parent), ui(new Ui::Registration_window)
{
    ui->setupUi(this);

    Bank_meneger& meneger = Bank_meneger::getInstance();

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    this -> setPalette(palette);

    setWindowFlag(Qt::WindowMaximizeButtonHint, false);

    ui -> Error_login_line_label -> setHidden(true);
    ui -> Error_password_line_label -> setHidden(true);
    ui -> Error_repeat_password_line_label -> setHidden(true);

    ui -> Login_line -> setMaxLength(20);
    ui -> Password_line -> setMaxLength(20);
    ui -> Repeat_password_line -> setMaxLength(20);

    QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/71681.png");
    ui -> View_PassWord_button -> setIcon(icon);
    ui -> View_PassWord_button -> setCheckable(true);
    ui -> View_PassWord_button -> setFlat(true);

    palette.setColor(QPalette::Button, QColor(231, 19, 82));
    ui -> Cancel_button -> setPalette(palette);

    palette.setColor(QPalette::Button, QColor(34, 245, 73));
    ui -> Continue_button -> setPalette(palette);


}

Registration_window::~Registration_window()
{
    delete ui;
}

void Registration_window::on_Cancel_button_clicked()
{
    emit(OpenMainWindow());

    close();
}

void Registration_window::on_View_PassWord_button_toggled(bool checked)
{
    if(checked){
        QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/png-transparent-computer-icons-eye-closed-eyes-cdr-people-desktop-wallpaper-thumbnail.png");
        ui -> View_PassWord_button -> setIcon(icon);

        ui -> Password_line -> setEchoMode(QLineEdit::Normal);
        ui -> Repeat_password_line -> setEchoMode(QLineEdit::Normal);
    }
    else{
        QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/71681.png");
        ui -> View_PassWord_button -> setIcon(icon);

        ui -> Password_line -> setEchoMode(QLineEdit::Password);
        ui -> Repeat_password_line -> setEchoMode(QLineEdit::Password);
    }
}

bool Registration_window::Is_all_lines_not_empty() {
    bool is_true = true;

    if(ui -> Login_line -> text() == ""){
        ui -> Error_login_line_label -> setText("Это поле не должно быть пустым");
        ui -> Error_login_line_label -> setHidden(false);
        is_true = false;
    }

    if(ui -> Password_line -> text() == ""){
        ui -> Error_password_line_label -> setText("Это поле не должно быть пустым");
        ui -> Error_password_line_label -> setHidden(false);
        is_true = false;
    }
    if(ui -> Repeat_password_line -> text() == "") {
        ui -> Error_repeat_password_line_label -> setText("Это поле не должно быть пустым");
        ui -> Error_repeat_password_line_label -> setHidden(false);
        is_true = false;
    }

    return is_true;
}

void Registration_window::on_Continue_button_clicked()
{

    if(Is_all_lines_not_empty()){
        QString login;
        QString password;
        QString password_repeat;

        login = ui -> Login_line -> text();

        password = ui -> Password_line -> text();
        password_repeat = ui -> Repeat_password_line -> text();

        if(password_repeat.length() < 8 || password.length() < 8){

            if(password.length() < 8){
                ui -> Error_password_line_label -> setText("Длина меньше 8 символов");
                ui -> Error_password_line_label -> setHidden(false);
            }
            if(password_repeat.length() < 8){
                ui -> Error_repeat_password_line_label -> setText("Длина меньше 8 символов");
                ui -> Error_repeat_password_line_label -> setHidden(false);
            }
        }

        else{
            if(password != password_repeat){
                ui -> Error_repeat_password_line_label -> setText("Пароли должны совпадать");
                ui -> Error_repeat_password_line_label -> setHidden(false);

            }
            else{

                QString dir_path = QDir::currentPath();

                dir_path += "/files";

                QDir dir(dir_path);

                if(!dir.exists()){

                    dir.mkdir(dir_path);
                }

                if(meneger.Is_user_login_exist(login) != -1){

                    ui -> Error_login_line_label -> setText("Такой пользователь уже есть");
                    ui -> Error_login_line_label -> setHidden(false);

                }

                else{
                    User* user = new User();

                    user -> setLogin(login);

                    password = SHA256::GetSha256(password);

                    Bank_meneger& meneger = Bank_meneger::getInstance();
                    meneger.AddUser(user, password);

                    int index = meneger.GetUserCount() - 1;

                    personal_data_window = new Personal_data_window(index);

                    connect(personal_data_window, &Personal_data_window::OpenMainWindow, this, &Registration_window::OpenWindow);
                    connect(personal_data_window, &Personal_data_window::OpenRegWindow, this, &Registration_window::Open);

                    hide();
                    personal_data_window -> show();

                }

            }
        }

    }

}

void Registration_window::on_Login_line_textChanged(const QString &temp)
{
    if(temp != ""){
        ui -> Error_login_line_label -> setHidden(true);
    }
}


void Registration_window::on_Password_line_textChanged(const QString &temp)
{    
    if(temp != ""){
        ui -> Error_password_line_label -> setHidden(true);
    }
}

void Registration_window::on_Repeat_password_line_textChanged(const QString &temp)
{
    if(temp != ""){
        ui -> Error_repeat_password_line_label -> setHidden(true);
    }
}

void Registration_window::OpenWindow(){

    emit(OpenMainWindow());
    close();
}

void Registration_window::Open(){
    show();
}
