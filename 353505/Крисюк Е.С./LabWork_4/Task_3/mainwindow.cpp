#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    index_of_letter = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Input_line_textChanged(const QString &text)
{
    if(text != ""){

        QString text_not_const = text;

        if(Is_have_letters(text_not_const)){

            text_not_const.remove(index_of_letter, 1);
            ui -> Input_line -> setText(text_not_const);

            QMessageBox* box = new QMessageBox();
            box -> setText("В этой строке не может быть таких символов");
            box -> exec();
        }

        program_result.clear();
        GetMedianVector(text_not_const);

        ui -> Output_line -> setText(program_result);
    }

    else{

        ui -> Output_line -> setText("");
    }
}

bool MainWindow::Is_have_letters(QString &text){

    bool is_have_letters = false;

    QChar letter;

    for(int i = 0; i < text.length(); ++i){
        letter = text[i];

        if(!letter.isNumber() && letter != ' '){
            is_have_letters = true;
            index_of_letter = i;
            break;
        }
    }

    return is_have_letters;
}


void MainWindow::GetMedianVector(QString &text){

    if(text.length() == 0){
        return;
    }

    QString first_number;

    for(int i = 0; i < text.length(); ++i){

        if(text[i] == ' ') {
            first_number = text.mid(0,i);
            text.remove(0,i + 1);
            break;
        }

        else if(i == text.length() - 1){
            first_number = text.mid(0,i + 1);
            text.remove(0,i + 1);
        }
    }


    if(text.length() == 0){
        program_result += first_number + " ";
        return;
    }

    QString second_number;

    for(int i = 0; i < text.length(); ++i){

        if(text[i] == ' ') {
            second_number = text.mid(0,i);
            text.remove(0,i + 1);
            break;
        }

        else if(i == text.length() - 1){
            second_number = text.mid(0,i + 1);
            text.remove(0,i + 1);
        }
    }


    QString temp_result;


    Long_sum(first_number, second_number, 0, temp_result);

    Long_divide(temp_result);


    if(text.length() == 0){
        program_result += temp_result + " ";
        return;
    }

    QString third_number;

    for(int i = 0; i < text.length(); ++i){

        if(text[i] == ' ') {
            third_number = text.mid(0,i);
            text.remove(0,i + 1);
            break;
        }

        else if(i == text.length() - 1){
            third_number = text.mid(0,i + 1);
            text.remove(0,i + 1);
        }
    }

    temp_result = Get_mid_number(first_number, second_number, third_number);

    program_result += temp_result + ' ';

    GetMedianVector(text);
}

QString MainWindow::Get_mid_number(QString &first_number, QString &second_number, QString &third_number){

    int first_number_length = first_number.length();
    int second_number_length = second_number.length();
    int third_number_length = third_number.length();

    QPair <QString, QChar> first_pair, second_pair, third_pair;

    first_pair.first = first_number;
    second_pair.first = second_number;
    third_pair.first = third_number;


    const int max_length = std::max(first_number_length, std::max(second_number_length, third_number_length));

    Get_max_length(first_pair.first, max_length);
    Get_max_length(second_pair.first, max_length);
    Get_max_length(third_pair.first, max_length);

    QString temp = Get_max_number(first_pair.first, second_pair.first);
    QString max_number = Get_max_number(third_pair.first, temp);


    QString mid_result;

    if(max_number == first_pair.first){
        mid_result = Get_max_number(second_pair.first, third_pair.first);
    }

    else if(max_number == second_pair.first){
        mid_result = Get_max_number(first_pair.first, third_pair.first);
    }

    else if(max_number == third_pair.first){
        mid_result = Get_max_number(second_pair.first, first_pair.first);
    }

    int index_of_last_zero = 0;

    for(int i = 0 ; mid_result[i] == '0'; ++i){
        index_of_last_zero = i;
    }

    mid_result.remove(0,index_of_last_zero);

    if(mid_result[0] == '0'){
        mid_result.remove(0,1);
    }
    return mid_result;
}

QString MainWindow::Get_max_number(QString &first_number, QString &second_number){

    for(int i = 0 ; i < first_number.length(); ++i){
        if(first_number[i].digitValue() > second_number[i].digitValue()){
            return first_number;
        }
        else if(first_number[i].digitValue() < second_number[i].digitValue()){
            return second_number;
        }
    }
    return first_number;
}

QString MainWindow::Get_min_number(QString &first_number, QString &second_number){

    for(int i = 0 ; i < first_number.length(); ++i){
        if(first_number[i].digitValue() < second_number[i].digitValue()){
            return first_number;
        }
        else if(first_number[i].digitValue() > second_number[i].digitValue()) {
            return second_number;
        }
    }
    return first_number;
}

void MainWindow::Get_max_length(QString &number, const int length){

    for(int i = number.length(); i < length; ++i){
        number.insert(0,'0');
    }
}
void MainWindow::Long_sum(QString &first_number, QString &second_number, int temp1, QString &func_result){

    QString first_number_copy = first_number;

    QString second_number_copy = second_number;

    if(first_number.length() == 0 && second_number.length() == 0){
        if(temp1 != 0){
            func_result.insert(0, QString::number(temp1));
        }
        return;
    }

    QChar first_number_last_symbol;

    if(first_number.length() != 0){
        first_number_last_symbol = first_number[first_number.length() - 1];
        first_number_copy.remove(first_number.length() - 1, 1);
    }

    QChar second_number_last_symbol;
    if(second_number.length() != 0){
        second_number_last_symbol = second_number[second_number.length() - 1];
        second_number_copy.remove(second_number.length() - 1, 1);
    }


    int first_number_last_symbol_int = first_number_last_symbol.digitValue();
    int second_number_last_symbol_int = second_number_last_symbol.digitValue();

    if(first_number_last_symbol_int == -1){
        first_number_last_symbol_int++;
    }
    if(second_number_last_symbol_int == -1){
        second_number_last_symbol_int++;
    }

    int result_int = first_number_last_symbol_int + second_number_last_symbol_int + temp1;

    int temp = 0;

    if(result_int > 9){
        temp = 1;
        result_int -= 9;
    }
    func_result.insert(0, QString::number(result_int));

    Long_sum(first_number_copy, second_number_copy, temp, func_result);
}

void MainWindow::Long_divide(QString &number){
    QString result;

    QChar temp;

    int* a = new int[number.length()];

    for(int i = 0; i < number.length(); ++i){
        temp = number[i];
        a[i] = temp.digitValue();
    }


    for(int i = 0; i < number.length() - 1; ++i){
        if(a[i] % 2 == 1){
            a[i] --;
            a[i + 1] += 10;
        }
        a[i] /= 2;

        result += QString::number(a[i]);
    }
    a[number.length() - 1] /= 2;

    result += QString::number(a[number.length() - 1]);

    delete[] a;

    if(result[0] == '0'){
        result.remove(0,1);
    }
    number = result;
}

