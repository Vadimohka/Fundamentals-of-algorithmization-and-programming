#include "second_dialod_2.h"

    second_dialod_2::second_dialod_2(projectclass **listOfClass, int *  number_in_array_women_dialog,QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{
    array_women = listOfClass;
    number_in_array_women = number_in_array_women_dialog;

    validator_text2 = new QRegularExpressionValidator(QRegularExpression("[А-Яа-яЁёA-Za-z]*"),this);


    number_of_people_lbl2 = new QLabel("Порядковый номер от 0 до 999",this);
    number_of_people_lbl2->setGeometry(320,220,180,15);
    number_of_people_Led2 = new QLineEdit(this);
    number_of_people_Led2->setGeometry(10,245,780,20);
    number_people_validator2 = new QIntValidator(0,10000,this);
    number_of_people_Led2->setValidator(number_people_validator2);

    name_of_people_lbl2 = new QLabel("Имя",this);
    name_of_people_lbl2->setGeometry(380,275,150,15);
    name_of_people_Led2 = new QLineEdit(this);
    name_of_people_Led2->setGeometry(10,300,780,20);
    name_of_people_Led2->setValidator(validator_text2);

    age_of_people_lbl2 = new QLabel("Возраст от 16 до 99",this);
    age_of_people_lbl2->setGeometry(340,330,150,15);
    age_of_people_Led2  = new QLineEdit(this);
    age_of_people_Led2->setGeometry(10,355,780,20);
    validator_age_of_people2 = new QIntValidator(18,99,this);
    age_of_people_Led2->setValidator(validator_age_of_people2);

    height_of_people_lbl2 =  new QLabel("Рост от 100 до 220",this);
    height_of_people_lbl2->setGeometry(340,385,150,15);
    height_of_people_Led2 = new QLineEdit(this);
    height_of_people_Led2->setGeometry(10,410,780,20);
    validator2 = new QIntValidator(100, 220, this);
    height_of_people_Led2->setValidator(validator2);

    weight_of_people_lbl2 = new QLabel("Вес от 40 до 120",this);
    weight_of_people_lbl2->setGeometry(340,440,150,15);
    weight_of_people_Led2 = new QLineEdit(this);
    weight_of_people_Led2->setGeometry(10,465,780,20);
    validator_weight2 = new QIntValidator(100, 220, this);
    weight_of_people_Led2->setValidator(validator_weight2);

    comboBox2 = new QComboBox(this);
    comboBox2->setGeometry(10,10,780,210);
    QString all = "";
    for (int i = 0; i < *number_in_array_women; i++) {
        if (all.indexOf(listOfClass[i]->get_All_Info()) < 0) {
            comboBox2->addItem(listOfClass[i]->get_All_Info());
            all += listOfClass[i]->get_All_Info();
        }
    }

    edit2 = new QPushButton("Редактировать",this);
    edit2->setGeometry(10,495,780,50);
    connect(edit2,SIGNAL(clicked(bool)),SLOT(applyBtnClicked2()));

    delete2 = new QPushButton("Удалить",this);
    delete2->setGeometry(10,550,780,50);
    connect(delete2,SIGNAL(clicked(bool)),SLOT(deleteBtnClicked2()));


    close_dialog3 = new QPushButton("Закрыть",this);
    close_dialog3->setGeometry(10,610,780,50);
    connect(close_dialog3,SIGNAL(clicked(bool)),SLOT(close()));
}

void second_dialod_2::applyBtnClicked2() {
    QString a = comboBox2->currentText();

    QString number_of_people = number_of_people_Led2->text() ;
    QString name = name_of_people_Led2->text();
    QString age = age_of_people_Led2->text();
    QString height = height_of_people_Led2->text();
    QString weight = weight_of_people_Led2->text();

    if (number_of_people.isEmpty() || name.isEmpty() || age.isEmpty() || height.isEmpty() || weight.isEmpty())
    {
        QMessageBox::warning(this,"Добавьте что-нибудь", "Вы пропускаете некоторые поля");
        return;
    }
    projectclass aClass;
    aClass.set_number_of_people(number_of_people);
    aClass.set_name(name);
    aClass.set_age(age);
    aClass.set_height(height);
    aClass.set_weight(weight);

    for (int i = 0; i < *number_in_array_women; i++) {
        if (aClass.get_All_Info() == array_women[i]->get_All_Info()) {
            QMessageBox::information(this, "Ошибка", "Нет такой Невесты");
            return;
        }
    }

    for (int i = 0; i < *number_in_array_women; i++) {
        if (array_women[i]->get_All_Info() == a) {
            array_women[i]->set_number_of_people(number_of_people);
            array_women[i]->set_name(name);
            array_women[i]->set_age(age);
            array_women[i]->set_height(height);
            array_women[i]->set_weight(weight);
        }
    }
    close();
}

void second_dialod_2::deleteBtnClicked2() {
    QString a = comboBox2->currentText();
    for (int i = 0; i < *number_in_array_women; i++) {
        if (array_women[i]->get_All_Info() == a) {
            for (int j = i + 1; j < *number_in_array_women; j++) {
                array_women[j - 1] = array_women[j];
            }
            (*number_in_array_women)--;
        }
    }
    close();
}
