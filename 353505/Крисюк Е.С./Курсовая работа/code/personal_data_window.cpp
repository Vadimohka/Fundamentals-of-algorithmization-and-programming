#include "personal_data_window.h"
#include "ui_personal_data_window.h"

extern Bank_meneger& meneger;

Personal_data_window::Personal_data_window(long long index, QWidget *parent) :QDialog(parent),ui(new Ui::Personal_data_window)
{
    ui->setupUi(this);
    ui -> date_datetime -> setButtonSymbols(QAbstractSpinBox::NoButtons);

    index_in_bank = index;

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    this -> setPalette(palette);

    palette.setColor(QPalette::Button, QColor(231, 19, 82));
    ui -> Cancel_button -> setPalette(palette);

    palette.setColor(QPalette::Button, QColor(34, 245, 73));
    ui -> Continue_button -> setPalette(palette);

    ui -> Error_date_label -> setHidden(true);
    ui -> Error_middlename_label -> setHidden(true);
    ui -> Error_name_label -> setHidden(true);
    ui -> Error_surname_label -> setHidden(true);
    ui -> Error_email_label -> setHidden(true);

    QIcon icon ("/home/krisyuk-egor/Загрузки/Картинки/gratis-png-linea-triangular-negra-m-circulo-atras-flecha-atras-thumbnail.png");
    ui -> Return_to_prev_window_button -> setIcon(icon);

}

Personal_data_window::~Personal_data_window()
{
    delete ui;
}


bool Personal_data_window::Is_dont_have_numbers(QString str){
    bool is_ok = true;
    QRegularExpression expr_rus("^([А-Я][а-я]*)$");
    QRegularExpression expr_english ("^([A-Z][a-z]*)$");

    if(expr_rus.match(str).hasMatch() || expr_english.match(str).hasMatch()){
        is_ok = false;
    }

    return is_ok;
}

bool Personal_data_window::Is_all_lines_not_empty(){
    bool is_true = true;

    if(ui -> name_line -> text() == ""){
        ui -> Error_name_label -> setText("Это поле не должно быть пустым");
        ui -> Error_name_label -> setHidden(false);
        is_true = false;
    }

    if(ui -> Email_line -> text() == ""){
        ui -> Error_email_label -> setText("Это поле не должно быть пустым");
        ui -> Error_email_label -> setHidden(false);
        is_true = false;
    }

    if(ui -> surname_line -> text() == ""){
        ui -> Error_surname_label -> setText("Это поле не должно быть пустым");
        ui -> Error_surname_label -> setHidden(false);
        is_true = false;
    }

    if(ui -> middle_name_line -> text() == ""){
        ui -> Error_middlename_label -> setText("Это поле не должно быть пустым");
        ui -> Error_middlename_label -> setHidden(false);
        is_true = false;
    }

    return is_true;
}



void Personal_data_window::on_Continue_button_clicked()
{
    if(Is_all_lines_not_empty()){
        QString name = ui -> name_line -> text();

        if(Is_dont_have_numbers(name)){
            ui -> Error_name_label -> setText("Неправильное имя");
            ui -> Error_name_label -> setHidden(false);
            QMessageBox::warning(nullptr,"Предупреждение", "Обратите внимание на то, что имя должно начинаться с большой буквы, а последующие должны быть маленькими");
        }

        else{
            QString surname = ui -> surname_line -> text();

            if(Is_dont_have_numbers(surname)){
                ui -> Error_surname_label -> setText("Неправильная фамилия");
                ui -> Error_surname_label -> setHidden(false);
                QMessageBox::warning(nullptr,"Предупреждение", "Обратите внимание на то, что фамилия должна начинаться с большой буквы, а последующие должны быть маленькими");
            }

            else {
                QString middle_name = ui -> middle_name_line -> text();

                if(Is_dont_have_numbers(middle_name)){
                    ui -> Error_middlename_label -> setText("Неправильное отчество");
                    ui -> Error_middlename_label -> setHidden(false);

                    QMessageBox::warning(nullptr,"Предупреждение", "Обратите внимание на то, что отчество должно начинаться с большой буквы, а последующие должны быть маленькими");
                }
                else{
                    QString email = ui -> Email_line -> text();

                    if(!Check_Email()){
                        ui -> Error_email_label -> setText("Неправильный email");
                        ui -> Error_email_label -> setHidden(false);
                    }

                    else{

                        if(!meneger.Check_email(email)){
                            ui -> Error_email_label -> setText("Такой email уже зарегестрирован");
                            ui -> Error_email_label -> setHidden(false);
                        }
                        else{
                            QDate date = ui -> date_datetime -> date();

                            meneger.ChangeUserName(index_in_bank, name);
                            meneger.ChangeUserSurname(index_in_bank, surname);
                            meneger.ChangeUserMiddlename(index_in_bank, middle_name);
                            meneger.ChangeUserBirthday(index_in_bank,date);
                            meneger.ChangeUserEmail(index_in_bank, email);
                            meneger.SetUserId(index_in_bank);


                            AllUsersFile::Add_user_base_data_to_all_users_file(index_in_bank);
                            AllUsersFile::Add_user_personal_data_to_file(index_in_bank);

                            emit(OpenMainWindow());
                            close();
                            QMessageBox* box = new QMessageBox();
                            box -> setWindowTitle("Уведомление");
                            box -> setText("Аккаунт успешно создан!");
                            box -> exec();
                        }
                    }

                }
            }

        }
    }

}

bool Personal_data_window::Check_Email(){
    QString email = ui -> Email_line -> text();

    QRegularExpression emailCheck("^([a-zA-Z0-9]+@[a-z]+\\.[a-z]{2,})");

    return emailCheck.match(email).hasMatch();

}

void Personal_data_window::on_name_line_textChanged(const QString &text)
{
    if(text != ""){
        ui -> Error_name_label -> setHidden(true);
    }
}


void Personal_data_window::on_surname_line_textChanged(const QString &text)
{
    if(text != ""){
        ui -> Error_surname_label -> setHidden(true);
    }
}


void Personal_data_window::on_middle_name_line_textChanged(const QString &text)
{
    if(text != ""){
        ui -> Error_middlename_label -> setHidden(true);
    }
}

void Personal_data_window::on_Cancel_button_clicked()
{

    meneger.RemoveUser();


    emit(OpenMainWindow());
    close();
}

void Personal_data_window::on_Email_line_textChanged(const QString &text)
{
    if(text != ""){
        ui -> Error_email_label -> setHidden(true);
    }
}


void Personal_data_window::on_Return_to_prev_window_button_clicked()
{
    meneger.RemoveUser();

    emit(OpenRegWindow());

    close();
}

