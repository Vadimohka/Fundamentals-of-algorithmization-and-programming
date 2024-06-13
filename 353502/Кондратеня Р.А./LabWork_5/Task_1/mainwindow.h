#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <QKeyEvent>
#include <QPushButton>
#include <QTimer>
#include <QList>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QRandomGenerator>
#include "stats_window.h"
#include <QTextStream>
#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_time_combobox_currentIndexChanged(int index);

    void on_update_text_edit_button_clicked();

    void on_English_q_button_clicked();

    void on_English_w_button_clicked();

    void on_English_e_button_clicked();

    void on_English_r_button_clicked();

    void on_English_t_button_clicked();

    void on_English_y_button_clicked();

    void on_English_u_button_clicked();

    void on_English_i_button_clicked();

    void on_English_o_button_clicked();

    void on_English_p_button_clicked();

    void on_English_array_left_button_clicked();

    void on_English_array_right_button_clicked();

    void on_English_a_button_clicked();

    void on_English_s_button_clicked();

    void on_English_d_button_clicked();

    void on_English_f_button_clicked();

    void on_English_g_button_clicked();

    void on_English_h_button_clicked();

    void on_English_j_button_clicked();

    void on_English_k_button_clicked();

    void on_English_l_button_clicked();

    void on_English_CAD_button_clicked();

    void on_English_quotes_button_clicked();

    void on_English_z_button_clicked();

    void on_English_x_button_clicked();

    void on_English_c_button_clicked();

    void on_English_v_button_clicked();

    void on_English_b_button_clicked();

    void on_English_n_button_clicked();

    void on_English_m_button_clicked();

    void on_English_comma_button_clicked();

    void on_English_dot_button_clicked();

    void on_English_space_button_clicked();

private:
    Ui::MainWindow *ui;
    QString folder_path;
    QString current_file_path;

    QStringList words_list;

    void keyPressEvent(QKeyEvent* event) override;
    void Add_text_to_Widget();
    void Random_word_list();

    QList<QString> bel_symbols;
    QList<QString> german_symbols;
    QList<QString> french_symbols;
    QList<QString> arabic_symbols;
    QList<QString> chinese_symbols;
    QList<QString> hebrew_symbols;

    QList<QString>* current_language;

    QList<QPushButton*> buttons_list;
    void Add_buttons_to_array();

    void Bel_symbols_array_input();
    void German_symbols_array_input();
    void French_symbols_array_input();
    void Arabic_symbols_array_input();
    void Chinese_symbols_array_input();
    void Hebrew_symbols_array_input();


    void Add_bel_text();
    void Add_German_text();
    void Add_French_text();
    void Add_Arabic_text();
    void Add_Chinese_text();
    void Add_Hebrew_text();

    void Change_keyboard_language();
    QString Check_symbols(QString&);

    void Define_button_to_light(QKeyEvent*, QList<QString>*);
    void Light_the_button(QPushButton* );
    void Start_the_test(int);
    QTextCursor text_cursor;

    void Clear_all_color_text();
    void Letter_in_text_change_color(int index);
    void Last_letter_in_text_clear_color();

    int count_of_right_symbols = 0;
    int count_of_incorrect_symbols = 0;
    int count_of_wrongs = 0;

    int current_word_index = 0;

    int time = 15;
    bool is_timer_start = false;
    void Start_timer();
    void GetStats();
    void Zero();

    Stats_window* stats_window;

};
#endif // MAINWINDOW_H
