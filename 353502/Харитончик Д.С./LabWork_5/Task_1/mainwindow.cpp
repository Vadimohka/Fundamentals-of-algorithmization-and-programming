#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextCursor cursor = ui -> Word_write_textedit -> textCursor();

    this -> setFocus();

    ui -> Word_write_textedit ->setTextCursor(cursor);
    ui -> time_label -> setText(QString::number(time));

    folder_path = QDir::currentPath() + "/files";
    qDebug() << folder_path;

    Add_buttons_to_array();

    Bel_symbols_array_input();
    German_symbols_array_input();
    French_symbols_array_input();
    Arabic_symbols_array_input();
    Chinese_symbols_array_input();
    Hebrew_symbols_array_input();

    current_language = &bel_symbols;
    Change_keyboard_language();

    Add_bel_text();
}

void MainWindow::Add_bel_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    qDebug() << "ok";

    current_file_path = folder_path + "/belarussian.txt";
    qDebug() << current_file_path;

    QFile bel_file(current_file_path);

    if(bel_file.open(QIODevice::ReadOnly | QIODevice:: Text)){
        qDebug() << "ok";

        QTextStream stream(&bel_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

void MainWindow::Add_German_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/german.txt";

    QFile german_file(current_file_path);

    if(german_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&german_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

void MainWindow::Add_French_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/french.txt";

    QFile frecnch_file(current_file_path);

    if(frecnch_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&frecnch_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

void MainWindow::Add_Arabic_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/arabic.txt";

    QFile frecnch_file(current_file_path);

    if(frecnch_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&frecnch_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

void MainWindow::Add_Chinese_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/chinese.txt";

    QFile frecnch_file(current_file_path);

    if(frecnch_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&frecnch_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

void MainWindow::Add_Hebrew_text(){
    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/hebrew.txt";

    QFile frecnch_file(current_file_path);

    if(frecnch_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&frecnch_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();

            words = line.split(" ");

            for(int i = 0 ; i < words.length(); ++i){
                if(words[i] != ""){
                    words_list.append(Check_symbols(words[i]));
                }
            }


        }
        Random_word_list();
        Add_text_to_Widget();
    }
}

QString MainWindow::Check_symbols(QString& str){

    QString result;

    for(int i = 0; i < str.length(); ++i){
        for(int j = 0; j < current_language -> length(); ++j){

        QString symbol(str.at(i));

        QString current_language_str(current_language -> at(j));

            if(current_language_str == symbol.toLower()){
                result += symbol.toLower();
            }
        }
    }

    return result;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {

    Define_button_to_light(event, current_language);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Add_text_to_Widget(){
    QString text;
    for(int i = 0; i < words_list.length(); ++i){
        text += words_list[i] + " ";
    }

    ui -> Word_write_textedit -> setText(text);
}

void MainWindow::Random_word_list(){

    QStringList words_list_copy;

    int temp_index;

    for(int i = 0; i < words_list.length(); ++i){
        temp_index = QRandomGenerator::global() -> bounded(0, words_list.length() - 1);
        words_list_copy.append(words_list[temp_index]);
    }

    words_list = words_list_copy;
}

void MainWindow::Define_button_to_light(QKeyEvent *event, QList<QString>* current_language){
    QString text = event -> text();

    int index = -1;

    if(text != '\b'){

        for(int i = 0; i < current_language -> length(); ++i){
            if(text == current_language -> at(i)){
                index = i;
                break;
            }
        }

        if(index != -1){
            Start_the_test(index);
        }

        else{
            QMessageBox::warning(this, "Предупреждение", "Incorrent language or button");


        }
    }
    else {
        Last_letter_in_text_clear_color();
    }

}

void MainWindow::Start_the_test(int index){

    Light_the_button(buttons_list[index]);
    Letter_in_text_change_color(index);

    if(!is_timer_start){
        Start_timer();
        is_timer_start = true;
    }
}
void MainWindow::Start_timer(){
    QTimer* timer = new QTimer(this);

    timer -> setInterval(1000);
    int count_of_sec = 0;

    connect(timer, &QTimer::timeout, this, [=]() mutable{
        count_of_sec++;

        ui -> time_label -> setText(QString::number(time - count_of_sec));

        if(count_of_sec == time){
            timer -> stop();
            stats_window = new Stats_window(count_of_right_symbols, count_of_incorrect_symbols, count_of_wrongs, time);
            ui -> time_label -> setText(QString::number(time));

            stats_window -> exec();
            Clear_all_color_text();

            ui -> comboBox -> setEnabled(true);
            ui -> time_combobox -> setEnabled(true);
            ui -> update_text_edit_button -> setEnabled(true);

        }
    });
    timer -> start();

    ui -> comboBox -> setEnabled(false);
    ui -> time_combobox -> setEnabled(false);
    ui -> update_text_edit_button -> setEnabled(false);
}


void MainWindow::Clear_all_color_text(){

    int temp = current_word_index;

    for(int i = 0; i < temp; ++i){
        Last_letter_in_text_clear_color();
    }

    Zero();

    text_cursor.movePosition(QTextCursor::Start);

    ui -> Word_write_textedit -> setTextCursor(text_cursor);

}

void MainWindow::Zero(){
    count_of_right_symbols = 0;
    count_of_incorrect_symbols = 0;
    count_of_wrongs = 0;
    is_timer_start = false;


}

void MainWindow::Last_letter_in_text_clear_color(){

    if(current_word_index > 0){

        text_cursor.setPosition(current_word_index);

        QTextCharFormat prev_format = text_cursor.charFormat();

        QColor prev_color = prev_format.foreground().color();

        if(prev_color == QColor(10,10,10)){

            count_of_right_symbols--;
        }

        else if(prev_color == Qt::red){
            count_of_incorrect_symbols--;
        }

        QTextCharFormat format;
        text_cursor.setPosition(current_word_index - 1);

        text_cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

        text_cursor.setCharFormat(format);

        current_word_index--;

    }
}

void MainWindow::Letter_in_text_change_color(int index){
    text_cursor = ui-> Word_write_textedit -> textCursor();

    QString temp = ui -> Word_write_textedit -> toPlainText();


    QString keyPressed = current_language -> at(index);
    QString text(temp.at(current_word_index));


    if (text == keyPressed) {

        QTextCharFormat format;
        format.setForeground(QColor(10,10,10));

        text_cursor.setPosition(current_word_index);
        text_cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

        text_cursor.setCharFormat(format);

        count_of_right_symbols++;

    }
    else {

        QTextCharFormat format;
        format.setForeground(Qt::red);
        format.setUnderlineStyle(QTextCharFormat::SingleUnderline);

        text_cursor.setPosition(current_word_index);
        text_cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

        text_cursor.setCharFormat(format);

        count_of_incorrect_symbols++;
        count_of_wrongs++;

    }
    current_word_index++;

    QRect cursorRect = ui -> Word_write_textedit -> cursorRect(text_cursor);
    QRect visibleRect = ui -> Word_write_textedit -> viewport() -> rect();

    int cursorPosition = cursorRect.center().y();
    int viewportMiddle = visibleRect.height() / 2;

    if (cursorPosition > viewportMiddle) {

        int cursorPosition = text_cursor.position();

        text_cursor.movePosition(QTextCursor::PreviousCharacter);
        int previousPosition = text_cursor.position();


        if (previousPosition < cursorPosition) {

            text_cursor.movePosition(QTextCursor::StartOfLine);

            ui -> Word_write_textedit -> setTextCursor(text_cursor);
        }
    }

}

void MainWindow::Light_the_button(QPushButton* button){

    QTimer* timer = new QTimer(this);

    timer -> setInterval(60);

    QString style = "background-color: yellow;";

    connect(timer, &QTimer::timeout, this, [=] () mutable{
        button->setStyleSheet("");
        timer -> stop();
    });

    button -> setStyleSheet(style);

    timer -> start();
}



void MainWindow::on_time_combobox_currentIndexChanged(int index)
{
    if(index == 0){
        time = 15;
    }
    else if(index == 1){
        time = 30;
    }
    else if(index == 2){
        time = 45;
    }
    else if(index == 3){
        time = 60;
    }

    this -> setFocus();
    ui -> time_label -> setText(QString::number(time));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui -> Word_write_textedit -> clear();
    words_list.clear();
    this -> setFocus();

    if(index == 0){
        current_language = &bel_symbols;
        Add_bel_text();
    }
    else if(index == 1){
        current_language = &german_symbols;
        Add_German_text();

    }
    else if(index == 2){
        current_language = &french_symbols;
        Add_French_text();
    }

    else if(index == 3){
        current_language = &arabic_symbols;
        Add_Arabic_text();
    }
    else if(index == 4){
        current_language = &chinese_symbols;
        Add_Chinese_text();
    }

    else if(index == 5){
        current_language = &hebrew_symbols;
        Add_Hebrew_text();
    }
    Change_keyboard_language();

}

void MainWindow::on_update_text_edit_button_clicked()
{
    this -> setFocus();

    ui -> Word_write_textedit -> clear();
    Random_word_list();
    Add_text_to_Widget();
    Zero();
}


void MainWindow::Bel_symbols_array_input(){

    bel_symbols.append("й");
    bel_symbols.append("ц");
    bel_symbols.append("у");
    bel_symbols.append("к");
    bel_symbols.append("е");
    bel_symbols.append("н");
    bel_symbols.append("г");
    bel_symbols.append("ш");
    bel_symbols.append("ў");
    bel_symbols.append("з");
    bel_symbols.append("х");
    bel_symbols.append("’");

    bel_symbols.append("ф");
    bel_symbols.append("ы");
    bel_symbols.append("в");
    bel_symbols.append("а");
    bel_symbols.append("п");
    bel_symbols.append("р");
    bel_symbols.append("о");
    bel_symbols.append("л");
    bel_symbols.append("д");
    bel_symbols.append("ж");
    bel_symbols.append("э");

    bel_symbols.append("я");
    bel_symbols.append("ч");
    bel_symbols.append("с");
    bel_symbols.append("м");
    bel_symbols.append("і");
    bel_symbols.append("т");
    bel_symbols.append("ь");
    bel_symbols.append("б");
    bel_symbols.append("ю");
    bel_symbols.append(" ");
}

void MainWindow::German_symbols_array_input(){
    german_symbols.append("q");
    german_symbols.append("w");
    german_symbols.append("e");
    german_symbols.append("r");
    german_symbols.append("t");
    german_symbols.append("y");
    german_symbols.append("u");
    german_symbols.append("i");
    german_symbols.append("o");
    german_symbols.append("p");
    german_symbols.append("[");
    german_symbols.append("]");

    german_symbols.append("a");
    german_symbols.append("s");
    german_symbols.append("d");
    german_symbols.append("f");
    german_symbols.append("g");
    german_symbols.append("h");
    german_symbols.append("j");
    german_symbols.append("k");
    german_symbols.append("l");
    german_symbols.append(";");
    german_symbols.append("'");

    german_symbols.append("z");
    german_symbols.append("x");
    german_symbols.append("c");
    german_symbols.append("v");
    german_symbols.append("b");
    german_symbols.append("n");
    german_symbols.append("m");
    german_symbols.append(",");
    german_symbols.append(".");
    german_symbols.append(" ");
}

void MainWindow::French_symbols_array_input(){
    french_symbols.append("a");
    french_symbols.append("w");
    french_symbols.append("e");
    french_symbols.append("r");
    french_symbols.append("t");
    french_symbols.append("y");
    french_symbols.append("u");
    french_symbols.append("i");
    french_symbols.append("o");
    french_symbols.append("p");
    french_symbols.append("^");
    french_symbols.append("$");
    french_symbols.append("q");
    french_symbols.append("s");
    french_symbols.append("d");
    french_symbols.append("f");
    french_symbols.append("g");
    french_symbols.append("h");
    french_symbols.append("j");
    french_symbols.append("k");
    french_symbols.append("l");
    french_symbols.append("m");
    french_symbols.append("ù");
    french_symbols.append("w");
    french_symbols.append("x");
    french_symbols.append("c");
    french_symbols.append("v");
    french_symbols.append("b");
    french_symbols.append("n");
    french_symbols.append(",");
    french_symbols.append(";");
    french_symbols.append(":");
    french_symbols.append(" ");
}

void MainWindow::Arabic_symbols_array_input(){
    arabic_symbols.append("ض");
    arabic_symbols.append("ص");
    arabic_symbols.append("ث");
    arabic_symbols.append("ق");
    arabic_symbols.append("ف");
    arabic_symbols.append("غ");
    arabic_symbols.append("ع");
    arabic_symbols.append("ه");
    arabic_symbols.append("خ");
    arabic_symbols.append("ح");
    arabic_symbols.append("ج");
    arabic_symbols.append("د");

    arabic_symbols.append("ش");
    arabic_symbols.append("س");
    arabic_symbols.append("ي");
    arabic_symbols.append("ب");
    arabic_symbols.append("ل");
    arabic_symbols.append("ا");
    arabic_symbols.append("ت");
    arabic_symbols.append("ن");
    arabic_symbols.append("م");
    arabic_symbols.append("ك");
    arabic_symbols.append("ط");

    arabic_symbols.append("ئ");
    arabic_symbols.append("ء");
    arabic_symbols.append("ؤ");
    arabic_symbols.append("ر");
    arabic_symbols.append("ﻻ");
    arabic_symbols.append("ى");
    arabic_symbols.append("ة");
    arabic_symbols.append("و");
    arabic_symbols.append("ز");
    arabic_symbols.append(" ");
}
void MainWindow::Chinese_symbols_array_input(){
    chinese_symbols.append("手");
    chinese_symbols.append("田");
    chinese_symbols.append("水");
    chinese_symbols.append("口");
    chinese_symbols.append("廿");
    chinese_symbols.append("卜");
    chinese_symbols.append("山");
    chinese_symbols.append("戈");
    chinese_symbols.append("人");
    chinese_symbols.append("心");
    chinese_symbols.append("「");
    chinese_symbols.append("」");
    chinese_symbols.append("日");
    chinese_symbols.append("尸");
    chinese_symbols.append("木");
    chinese_symbols.append("火");
    chinese_symbols.append("土");
    chinese_symbols.append("竹");
    chinese_symbols.append("十");
    chinese_symbols.append("大");
    chinese_symbols.append("中");
    chinese_symbols.append("；");
    chinese_symbols.append("'");
    chinese_symbols.append("　");
    chinese_symbols.append("║");
    chinese_symbols.append("金");
    chinese_symbols.append("女");
    chinese_symbols.append("月");
    chinese_symbols.append("弓");
    chinese_symbols.append("一");
    chinese_symbols.append("，");
    chinese_symbols.append("。");
    chinese_symbols.append(" ");
}

void MainWindow::Hebrew_symbols_array_input(){
    hebrew_symbols.append("/");
    hebrew_symbols.append("'");
    hebrew_symbols.append("ק");
    hebrew_symbols.append("ר");
    hebrew_symbols.append("א");
    hebrew_symbols.append("ט");
    hebrew_symbols.append("ו");
    hebrew_symbols.append("ן");
    hebrew_symbols.append("ם");
    hebrew_symbols.append("פ");
    hebrew_symbols.append("]");
    hebrew_symbols.append("[");

    hebrew_symbols.append("ש");
    hebrew_symbols.append("ד");
    hebrew_symbols.append("ג");
    hebrew_symbols.append("כ");
    hebrew_symbols.append("ע");
    hebrew_symbols.append("י");
    hebrew_symbols.append("ח");
    hebrew_symbols.append("ל");
    hebrew_symbols.append("ך");
    hebrew_symbols.append("ף");
    hebrew_symbols.append(",");

    hebrew_symbols.append("ז");
    hebrew_symbols.append("ס");
    hebrew_symbols.append("ב");
    hebrew_symbols.append("ה");
    hebrew_symbols.append("נ");
    hebrew_symbols.append("מ");
    hebrew_symbols.append("צ");
    hebrew_symbols.append("ת");
    hebrew_symbols.append("ץ");
    hebrew_symbols.append(" ");

}
void MainWindow::Change_keyboard_language(){
    ui -> English_q_button -> setText(current_language -> at(0).toUpper());
    ui -> English_w_button -> setText(current_language -> at(1).toUpper());
    ui -> English_e_button -> setText(current_language -> at(2).toUpper());
    ui -> English_r_button -> setText(current_language -> at(3).toUpper());
    ui -> English_t_button -> setText(current_language -> at(4).toUpper());
    ui -> English_y_button -> setText(current_language -> at(5).toUpper());
    ui -> English_u_button -> setText(current_language -> at(6).toUpper() );
    ui -> English_i_button -> setText(current_language -> at(7).toUpper());
    ui -> English_o_button -> setText(current_language -> at(8).toUpper());
    ui -> English_p_button -> setText(current_language -> at(9).toUpper());
    ui -> English_array_left_button -> setText(current_language -> at(10).toUpper());
    ui -> English_array_right_button -> setText(current_language -> at(11).toUpper());

    ui -> English_a_button -> setText(current_language -> at(12).toUpper());
    ui -> English_s_button -> setText(current_language -> at(13).toUpper());
    ui -> English_d_button -> setText(current_language -> at(14).toUpper());
    ui -> English_f_button -> setText(current_language -> at(15).toUpper());
    ui -> English_g_button -> setText(current_language -> at(16).toUpper());
    ui -> English_h_button -> setText(current_language -> at(17).toUpper());
    ui -> English_j_button -> setText(current_language -> at(18).toUpper());
    ui -> English_k_button -> setText(current_language -> at(19).toUpper());
    ui -> English_l_button -> setText(current_language -> at(20).toUpper());
    ui -> English_CAD_button -> setText(current_language -> at(21).toUpper());
    ui -> English_quotes_button -> setText(current_language -> at(22).toUpper());

    ui -> English_z_button -> setText(current_language -> at(23).toUpper());
    ui -> English_x_button -> setText(current_language -> at(24).toUpper());
    ui -> English_c_button -> setText(current_language -> at(25).toUpper());
    ui -> English_v_button -> setText(current_language -> at(26).toUpper());
    ui -> English_b_button -> setText(current_language -> at(27).toUpper());
    ui -> English_n_button -> setText(current_language -> at(28).toUpper());
    ui -> English_m_button -> setText(current_language -> at(29).toUpper());
    ui -> English_comma_button -> setText(current_language -> at(30).toUpper());
    ui -> English_dot_button -> setText(current_language -> at(31).toUpper());

}

void MainWindow::Add_buttons_to_array(){
    buttons_list.append(ui -> English_q_button);
    buttons_list.append(ui -> English_w_button);
    buttons_list.append(ui -> English_e_button);
    buttons_list.append(ui -> English_r_button);
    buttons_list.append(ui -> English_t_button);
    buttons_list.append(ui -> English_y_button);
    buttons_list.append(ui -> English_u_button);
    buttons_list.append(ui -> English_i_button);
    buttons_list.append(ui -> English_o_button);
    buttons_list.append(ui -> English_p_button);
    buttons_list.append(ui -> English_array_left_button);
    buttons_list.append(ui -> English_array_right_button);

    buttons_list.append(ui -> English_a_button);
    buttons_list.append(ui -> English_s_button);
    buttons_list.append(ui -> English_d_button);
    buttons_list.append(ui -> English_f_button);
    buttons_list.append(ui -> English_g_button);
    buttons_list.append(ui -> English_h_button);
    buttons_list.append(ui -> English_j_button);
    buttons_list.append(ui -> English_k_button);
    buttons_list.append(ui -> English_l_button);
    buttons_list.append(ui -> English_CAD_button);
    buttons_list.append(ui -> English_quotes_button);

    buttons_list.append(ui -> English_z_button);
    buttons_list.append(ui -> English_x_button);
    buttons_list.append(ui -> English_c_button);
    buttons_list.append(ui -> English_v_button);
    buttons_list.append(ui -> English_b_button);
    buttons_list.append(ui -> English_n_button);
    buttons_list.append(ui -> English_m_button);
    buttons_list.append(ui -> English_comma_button);
    buttons_list.append(ui -> English_dot_button);
    buttons_list.append(ui -> English_space_button);

}

void MainWindow::on_English_q_button_clicked()
{
    int index = 0;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_w_button_clicked()
{
    int index = 1;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_e_button_clicked()
{
    int index = 2;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_r_button_clicked()
{
    int index = 3;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_t_button_clicked()
{
    int index = 4;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_y_button_clicked()
{
    int index = 5;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_u_button_clicked()
{
    int index = 6;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_i_button_clicked()
{
    int index = 7;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_o_button_clicked()
{
    int index = 8;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_p_button_clicked()
{
    int index = 9;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_array_left_button_clicked()
{
    int index = 10;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_array_right_button_clicked()
{
    int index = 11;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_a_button_clicked()
{
    int index = 12;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_s_button_clicked()
{
    int index = 13;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_d_button_clicked()
{
    int index = 14;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_f_button_clicked()
{
    int index = 15;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_g_button_clicked()
{
    int index = 16;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_h_button_clicked()
{
    int index = 17;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_j_button_clicked()
{
    int index = 18;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_k_button_clicked()
{
    int index = 19;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_l_button_clicked()
{
    int index = 20;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_CAD_button_clicked()
{
    int index = 21;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_quotes_button_clicked()
{
    int index = 22;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_z_button_clicked()
{
    int index = 23;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_x_button_clicked()
{
    int index = 24;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_c_button_clicked()
{
    int index = 25;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_v_button_clicked()
{
    int index = 26;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_b_button_clicked()
{
    int index = 27;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_n_button_clicked()
{
    int index = 28;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_m_button_clicked()
{
    int index = 29;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_comma_button_clicked()
{
    int index = 30;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_dot_button_clicked()
{
    int index = 31;
    this -> setFocus();

    Start_the_test(index);
}


void MainWindow::on_English_space_button_clicked()
{
    int index = 32;
    this -> setFocus();

    Start_the_test(index);
}
