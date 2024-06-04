#include "mainwindow.h"
#include "./ui_mainwindow.h"

extern Bank_meneger& meneger;

Bank_meneger& meneger = Bank_meneger::getInstance();

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("background-color: white;");

    ui -> Error_login_line_label -> setHidden(true);
    ui -> Error_PassWord_line_label -> setHidden(true);

    ui -> Login_line -> setMaxLength(20);
    ui -> Password_line -> setMaxLength(20);

    ui -> Enter_button -> setStyleSheet("background-color: lightgreen;");

    ui -> Registration_label -> setText("<a href=\"https://www.example.com\">Зарегистрироваться</a>");
    ui -> Registration_label -> setCursor(Qt::PointingHandCursor);

    QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/71681.png");
    ui -> View_PassWord_button -> setIcon(icon);
    ui -> View_PassWord_button -> setCheckable(true);
    ui -> View_PassWord_button -> setFlat(true);

    QString folder_path = QDir::currentPath() + "/files";
    QString file_path = folder_path + "/All users";

    meneger.Set_file_path_to_all_users(file_path);
    meneger.Set_folder_path(folder_path);

    AllUsersFile::Users_in_file_to_meneger();

    connect(ui -> Registration_label, &QLabel::linkActivated, this, &MainWindow::Open_Registration_window);


    QString number = "098";

    number = BlowFish::Encrypt(number);
    qDebug() << "dec" << BlowFish::Decrypt(number);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Login_line_textChanged(const QString &arg1)
{
    if(ui -> Login_line -> text() != ""){
        ui -> Login_label -> setHidden(true);
        ui -> Error_login_line_label -> setHidden(true);
    }
    else {
        ui -> Login_label -> setHidden(false);
    }
}

void MainWindow::on_Password_line_textChanged(const QString &arg1)
{
    if(ui -> Password_line -> text() != ""){
        ui -> Password_label -> setHidden(true);
        ui -> Error_PassWord_line_label -> setHidden(true);
    }
    else {
        ui -> Password_label -> setHidden(false);
    }
}


void MainWindow::on_Enter_button_clicked()
{
    QString login = ui -> Login_line -> text();
    QString password = ui -> Password_line -> text();

    password = SHA256::GetSha256(password);

    if(login == "" || password == ""){

        if(login == ""){
            ui -> Error_login_line_label -> setHidden(false);
        }

        if(password == ""){
            ui -> Error_PassWord_line_label -> setHidden(false);
        }
    }

    else{

        long long user_index_in_user_list = meneger.Is_user_login_exist(login);

        if(user_index_in_user_list == -1){
            ui -> Error_login_line_label -> setText("Пользователя с таким именем нет");
            ui -> Error_login_line_label -> setHidden(false);
        }

        else{
            if(!meneger.Check_password(password, user_index_in_user_list)){
                ui -> Error_PassWord_line_label -> setText("Неправильный пароль");
                ui -> Error_PassWord_line_label -> setHidden(false);
            }

            else{
                home_window = new Home_window(user_index_in_user_list);

                home_window -> setWindowTitle("");
                home_window -> setFixedSize(1200,800);


                connect(home_window, &Home_window::OpenMainWindow, this, &MainWindow::Open);

                ui -> Login_line -> setText("");
                ui -> Password_line -> setText("");

                hide();
                home_window -> show();
            }
        }
    }
}


void MainWindow::Open_Registration_window()
{
    this -> hide();
    registration_window = new Registration_window();
    connect(registration_window, &Registration_window::OpenMainWindow, this, &MainWindow::Open);

    registration_window -> setWindowTitle("");
    registration_window -> setFixedSize(772,537);

    registration_window -> exec();
}

void MainWindow::Open(){
    this -> show();
}

void MainWindow::on_View_PassWord_button_toggled(bool checked)
{
    if(checked){
        QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/png-transparent-computer-icons-eye-closed-eyes-cdr-people-desktop-wallpaper-thumbnail.png");
        ui -> View_PassWord_button -> setIcon(icon);

        ui -> Password_line -> setEchoMode(QLineEdit::Normal);
    }
    else{
        QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/71681.png");
        ui -> View_PassWord_button -> setIcon(icon);

        ui -> Password_line -> setEchoMode(QLineEdit::Password);

    }
}


void MainWindow::on_Leave_button_clicked()
{
    close();
}

