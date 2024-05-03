#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include"my_dialog_3.h"
#include "second_dialog_1.h"
#include "second_dialod_2.h"
#include"projectclass.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    Ui::Widget *ui;

    projectclass  ** array_men;
    int number_in_array_men = 0;

    projectclass  * *array_women;
    int number_in_array_women = 0;


    QRegularExpressionValidator * validator_text;

    QFile men_file;
    QFile women_file;

    QString path_to_men_file;
    QString path_to_women_file;

    QPushButton * my_closeBtn;
    QPushButton * my_openBtn_for_men;
    QPushButton * my_openBtn_for_women;
    QPushButton * my_qSort_age;
    QPushButton * my_qSort_number_of_people;
    QPushButton * my_qSort_hieght;
    QPushButton * my_qSort_wieght;
    QPushButton * my_edit_or_delete;
    QPushButton * my_all_pairs;
    QPushButton * my_add_new_people;
    QPushButton * my_save_file;

    QPlainTextEdit   * information_from_men_file;
    QPlainTextEdit   * information_from_women_file;
    QPlainTextEdit   * information_for_my_fun;

    QRadioButton * men_RadioBtn;
    QRadioButton * women_RadioBtn;

    QLabel * number_of_people_lbl;
    QLineEdit * number_of_people_Led;
    QIntValidator* number_people_validator;


    QLabel * name_of_people_lbl;
    QLineEdit * name_of_people_Led;

    QLabel * age_of_people_lbl;
    QLineEdit * age_of_people_Led;
    QIntValidator * validator_age_of_people;


    QLabel * height_of_people_lbl;
    QLineEdit * height_of_people_Led;
    QIntValidator* validator;

    QLabel * weight_of_people_lbl;
    QLineEdit * weight_of_people_Led;
    QIntValidator* validator_weight;


    QLabel * habits_of_people_lbl;
    QLineEdit * habits_of_people_Led;

    QLabel * hobby_of_people_lbl;
    QLineEdit * hobby_of_people_Led;

    QLabel * age_min_or_max_lbl;
    QLabel * min_1,*max_1;
    QLineEdit * age_min_Led;
    QLineEdit * age_max_Led;

    QLabel * height_min_or_max_lbl;
    QLabel * min_2,*max_2;
    QLineEdit * height_min_Led;
    QLineEdit * height_max_Led;

    QLabel *weight_min_or_max_lbl;
    QLabel * min_3,*max_3;
    QLineEdit * weight_min_Led;
    QLineEdit * weight_max_Led;

    QLabel * Odin_or_Odna_lbl;
    QLineEdit * Odin_or_Odna_Led_YES_or_NO;

    void save_to_men_file();

    void save_to_women_file();

    void add_to_array_women();

    void add_to_array_men();

    void men_or_women();

    void disable_Btn();

    void enable_Btn();

    void age_qSort_men(int b, int e);

    void age_Sort_men();

    void age_qSort_women(int b, int e);

    void age_Sort_women();

    bool age_compare(projectclass *a, projectclass *b);

    void number_of_people_qSort_men(int b, int e);

    void number_of_people_Sort_men();

    void number_of_people_qSort_women(int b, int e);

    void number_of_people_Sort_women();

    bool number_of_people_compare(projectclass *a, projectclass *b);

    void height_qSort_men(int b, int e);

    void height_Sort_men();

    void height_qSort_women(int b, int e);

    void height_Sort_women();

    bool height_compare(projectclass *a, projectclass *b);


    void weight_qSort_men(int b, int e);

    void weight_Sort_men();

    void weight_qSort_women(int b, int e);

    void weight_Sort_women();

    bool weight_compare(projectclass *a, projectclass *b);

    void open_second_dialog_1();

    void open_second_dialog_2();



public slots:

    void open_men_file();

    void fun_information_from_men_file();

    void open_women_file();

    void fun_information_from_women_file();

    void my_fun_close();

    void save_to_file();

    void Next_Dialog();

    void age_Sort_All();

    void height_Sort_All();

    void weight_Sort_All();

    void number_of_people_Sort_All();

    void open_my_dialog_3();

    void All_par();
};
#endif // WIDGET_H
