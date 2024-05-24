#include "second_dialog_1.h"

    second_dialog_1::second_dialog_1(projectclass **listOfClass, int *  number_in_array_men_dialog,QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{
    setFixedSize(800,670);
    setWindowTitle("   Редактировать или удалить");
    setModal(true);
    setWindowFlags(windowFlags() | Qt::MSWindowsOwnDC);

    array_men = listOfClass;
    number_in_array_men = number_in_array_men_dialog;

    validator_text1 = new QRegularExpressionValidator(QRegularExpression("[А-Яа-яЁёA-Za-z]*"),this);


    number_of_people_lbl1 = new QLabel("Порядковый номер от 0 до 999",this);
    number_of_people_lbl1->setGeometry(320,220,180,15);
    number_of_people_Led1 = new QLineEdit(this);
    number_of_people_Led1->setGeometry(10,245,780,20);
    number_people_validator1 = new QIntValidator(0,10000,this);
    number_of_people_Led1->setValidator(number_people_validator1);

    name_of_people_lbl1 = new QLabel("Имя",this);
    name_of_people_lbl1->setGeometry(380,275,150,15);
    name_of_people_Led1 = new QLineEdit(this);
    name_of_people_Led1->setGeometry(10,300,780,20);
    name_of_people_Led1->setValidator(validator_text1);

    age_of_people_lbl1 = new QLabel("Возраст от 16 до 99",this);
    age_of_people_lbl1->setGeometry(340,330,150,15);
    age_of_people_Led1  = new QLineEdit(this);
    age_of_people_Led1->setGeometry(10,355,780,20);
    validator_age_of_people1 = new QIntValidator(18,99,this);
    age_of_people_Led1->setValidator(validator_age_of_people1);

    height_of_people_lbl1 =  new QLabel("Рост от 100 до 220",this);
    height_of_people_lbl1->setGeometry(340,385,150,15);
    height_of_people_Led1 = new QLineEdit(this);
    height_of_people_Led1->setGeometry(10,410,780,20);
    validator1 = new QIntValidator(100, 220, this);
    height_of_people_Led1->setValidator(validator1);

    weight_of_people_lbl1 = new QLabel("Вес от 40 до 120",this);
    weight_of_people_lbl1->setGeometry(340,440,150,15);
    weight_of_people_Led1 = new QLineEdit(this);
    weight_of_people_Led1->setGeometry(10,465,780,20);
    validator_weight1 = new QIntValidator(100, 220, this);
    weight_of_people_Led1->setValidator(validator_weight1);

    comboBox1 = new QComboBox(this);
    comboBox1->setGeometry(10,10,780,210);
    QString all = "";
    for (int i = 0; i < *number_in_array_men; i++) {
        if (all.indexOf(listOfClass[i]->get_All_Info()) < 0) {
            comboBox1->addItem(listOfClass[i]->get_All_Info());
            all += listOfClass[i]->get_All_Info();
        }
    }

    edit1 = new QPushButton("Редактировать",this);
    edit1->setGeometry(10,495,780,50);
    connect(edit1,SIGNAL(clicked(bool)),SLOT(applyBtnClicked1()));

    delete1 = new QPushButton("Удалить",this);
    delete1->setGeometry(10,550,780,50);
    connect(delete1,SIGNAL(clicked(bool)),SLOT(deleteBtnClicked1()));


    close_dialog2 = new QPushButton("Закрыть",this);
    close_dialog2->setGeometry(10,610,780,50);
    connect(close_dialog2,SIGNAL(clicked(bool)),SLOT(close()));
}

void second_dialog_1::applyBtnClicked1() {
    QString a = comboBox1->currentText();

    QString number_of_people = number_of_people_Led1->text() ;
    QString name = name_of_people_Led1->text();
    QString age = age_of_people_Led1->text();
    QString height = height_of_people_Led1->text();
    QString weight = weight_of_people_Led1->text();

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

    for (int i = 0; i < *number_in_array_men; i++) {
        if (aClass.get_All_Info() == array_men[i]->get_All_Info()) {
            QMessageBox::information(this, "Ошибка", "Нет такого Жениха");
            return;
        }
    }

    for (int i = 0; i < *number_in_array_men; i++) {
        if (array_men[i]->get_All_Info() == a) {
            array_men[i]->set_number_of_people(number_of_people);
            array_men[i]->set_name(name);
            array_men[i]->set_age(age);
            array_men[i]->set_height(height);
            array_men[i]->set_weight(weight);
        }
    }
    close();
}

void second_dialog_1::deleteBtnClicked1() {
    QString a = comboBox1->currentText();
    for (int i = 0; i < *number_in_array_men; i++) {
        if (array_men[i]->get_All_Info() == a) {
            for (int j = i + 1; j < *number_in_array_men; j++) {
                array_men[j - 1] = array_men[j];
            }
            (*number_in_array_men)--;
        }
    }
    close();
}
