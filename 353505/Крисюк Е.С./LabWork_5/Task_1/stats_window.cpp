#include "stats_window.h"
#include "ui_stats_window.h"

Stats_window::Stats_window(int correct_count, int incorrect_count, int wrongs_count, int time, QWidget *parent) :QDialog(parent),ui(new Ui::Stats_window)
{
    ui->setupUi(this);
    this -> correct_count = correct_count;
    this -> incorrect_count = incorrect_count;
    this -> wrongs_count = wrongs_count;

    ui -> wrongs_count_line -> setText(QString::number(wrongs_count));
    ui -> correct_symbols_count_line -> setText(QString::number(correct_count));
    ui -> incorrect_symbols_count_line -> setText(QString::number(incorrect_count));

    int symbols_per_min = 60 / time * (correct_count + incorrect_count);
    ui -> symbols_per_minute_line -> setText(QString::number(symbols_per_min));

    ui -> words_per_minute_line -> setText(QString::number(symbols_per_min / 5));

    setFocus();



}

Stats_window::~Stats_window()
{
    delete ui;
}

void Stats_window::on_close_button_clicked()
{
    close();
}

