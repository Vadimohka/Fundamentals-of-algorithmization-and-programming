#ifndef SECOND_DIALOD_2_H
#define SECOND_DIALOD_2_H
#include<QtWidgets>
#include"projectclass.h"

class second_dialod_2 :public QDialog {
    Q_OBJECT
public:
    explicit second_dialod_2(projectclass **listOfClass, int *  number_in_array_women_dialog,QWidget *parent);
private:
    second_dialod_2(QWidget *parent = nullptr);

    int * number_in_array_women;
    projectclass * *array_women;

    QPushButton * edit2;
    QPushButton * delete2;

    QPushButton * close_dialog3;
    QComboBox * comboBox2;

    QRegularExpressionValidator * validator_text2;


    QLabel * number_of_people_lbl2;
    QLineEdit * number_of_people_Led2;
    QIntValidator* number_people_validator2;


    QLabel * name_of_people_lbl2;
    QLineEdit * name_of_people_Led2;

    QLabel * age_of_people_lbl2;
    QLineEdit * age_of_people_Led2;
    QIntValidator * validator_age_of_people2;


    QLabel * height_of_people_lbl2;
    QLineEdit * height_of_people_Led2;
    QIntValidator* validator2;

    QLabel * weight_of_people_lbl2;
    QLineEdit * weight_of_people_Led2;
    QIntValidator* validator_weight2;

private slots:

    void applyBtnClicked2();

    void deleteBtnClicked2();
};

#endif // SECOND_DIALOD_2_H
