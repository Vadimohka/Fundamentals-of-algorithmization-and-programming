#ifndef SECOND_DIALOG_1_H
#define SECOND_DIALOG_1_H
#include<QtWidgets>
#include"projectclass.h"

class second_dialog_1: public QDialog {
    Q_OBJECT
public:
    explicit second_dialog_1(projectclass **listOfClass, int *  number_in_array_men_dialog,QWidget *parent);

private:
    int * number_in_array_men;
    projectclass  **array_men;

    second_dialog_1(QWidget *parent = nullptr);

    QPushButton * close_dialog2;
    QPushButton * edit1;
    QPushButton * delete1;

    QComboBox * comboBox1;

    QRegularExpressionValidator * validator_text1;


    QLabel * number_of_people_lbl1;
    QLineEdit * number_of_people_Led1;
    QIntValidator* number_people_validator1;


    QLabel * name_of_people_lbl1;
    QLineEdit * name_of_people_Led1;

    QLabel * age_of_people_lbl1;
    QLineEdit * age_of_people_Led1;
    QIntValidator * validator_age_of_people1;


    QLabel * height_of_people_lbl1;
    QLineEdit * height_of_people_Led1;
    QIntValidator* validator1;

    QLabel * weight_of_people_lbl1;
    QLineEdit * weight_of_people_Led1;
    QIntValidator* validator_weight1;

private slots:

    void applyBtnClicked1();

    void deleteBtnClicked1();
};

#endif // SECOND_DIALOG_1_H
