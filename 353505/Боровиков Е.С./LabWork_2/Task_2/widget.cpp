#include "widget.h"
#include "ui_widget.h"
//#include"my_dialog.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    array_men = (projectclass **) calloc(1, sizeof(projectclass *));
    array_women = (projectclass **) calloc(1, sizeof(projectclass *));

    validator_text = new QRegularExpressionValidator(QRegularExpression("[А-Яа-яЁёA-Za-z]*"),this);

    validator_weight = new QIntValidator(0,100,this);

    my_openBtn_for_men = new QPushButton("Открыть файл женихов \n и файл невест   ",this);
    my_openBtn_for_men->setGeometry(300,10,195,80);
    connect(my_openBtn_for_men,SIGNAL(clicked(bool)),SLOT(open_men_file()));

    //my_openBtn_for_women = new QPushButton("Открыть файл невест",this);
    //my_openBtn_for_women->setGeometry(300,125,195,100);
    connect(my_openBtn_for_men,SIGNAL(clicked(bool)),SLOT(open_women_file()));

    my_qSort_age = new QPushButton("Сортировка по возрасту",this);
    my_qSort_age->setGeometry(300,605,195,80);
    connect(my_qSort_age,SIGNAL(clicked(bool)),SLOT(age_Sort_All()));

    my_qSort_number_of_people = new QPushButton("Сортировка по номеру",this);
    my_qSort_number_of_people->setGeometry(300,515,195,80);
    connect(my_qSort_number_of_people,SIGNAL(clicked(bool)),SLOT(number_of_people_Sort_All()));

    my_qSort_hieght = new QPushButton("Сортировка по росту",this);
    my_qSort_hieght->setGeometry(300,424,195,80);
    connect(my_qSort_hieght,SIGNAL(clicked(bool)),SLOT(height_Sort_All()));

    my_qSort_wieght = new QPushButton("Сортировка по весу",this);
    my_qSort_wieght->setGeometry(300,335,195,80);
    connect(my_qSort_wieght,SIGNAL(clicked(bool)),SLOT(weight_Sort_All()));

    my_add_new_people = new QPushButton("Добавить",this);
    my_add_new_people->setGeometry(5,605,290,80);
    connect(my_add_new_people,SIGNAL(clicked(bool)),SLOT(Next_Dialog()));

    my_edit_or_delete = new QPushButton("Редактировать или удалить",this);
    my_edit_or_delete->setGeometry(300,180,195,70);
    connect(my_edit_or_delete,SIGNAL(clicked(bool)),SLOT(open_my_dialog_3()));

    my_all_pairs = new QPushButton("Все возможные пары",this);
    my_all_pairs->setGeometry(300,100,195,70);
    connect(my_all_pairs,SIGNAL(clicked(bool)),SLOT(All_par()));

    my_closeBtn = new QPushButton("Закрыть",this);
    my_closeBtn->setGeometry(10,690,485,85);
    connect(my_closeBtn,SIGNAL(clicked(bool)),SLOT(my_fun_close()));

    my_save_file = new QPushButton("Сохранить",this);
    my_save_file->setGeometry(300,258,195,70);
    connect(my_save_file,SIGNAL(clicked(bool)),SLOT(save_to_file()));

    information_from_men_file = new QPlainTextEdit("                                       ЖЕНИХИ",this);
    information_from_men_file->setReadOnly(true);
    information_from_men_file->setGeometry(500,10,330,840);

    information_from_women_file = new QPlainTextEdit("                                     НЕВЕСТЫ",this);
    information_from_women_file->setReadOnly(true);
    information_from_women_file->setGeometry(850,10,330,840);

    information_for_my_fun = new QPlainTextEdit("                           ВСЕ ВОЗМОЖНЫЕ ПАРЫ",this);
    information_for_my_fun->setReadOnly(true);
    information_for_my_fun->setGeometry(1200,10,330,840);

    men_RadioBtn = new QRadioButton("Жених",this);
    men_RadioBtn->setGeometry(50,10,70,25);

    women_RadioBtn = new QRadioButton("Невеста",this);
    women_RadioBtn->setGeometry(160,10,70,25);

    number_of_people_lbl = new QLabel("Порядковый номер от 0 до 999",this);
    number_of_people_lbl->setGeometry(70,45,180,15);
    number_of_people_Led = new QLineEdit(this);
    number_of_people_Led->setGeometry(5,65,290,20);
    number_people_validator = new QIntValidator(0,10000,this);
    number_of_people_Led->setValidator(number_people_validator);


    name_of_people_lbl = new QLabel("Имя",this);
    name_of_people_lbl->setGeometry(130,90,150,15);
    name_of_people_Led = new QLineEdit(this);
    name_of_people_Led->setGeometry(5,110,290,20);
    name_of_people_Led->setValidator(validator_text);

    age_of_people_lbl = new QLabel("Возраст от 16 до 99",this);
    age_of_people_lbl->setGeometry(100,135,150,15);
    age_of_people_Led  = new QLineEdit(this);
    age_of_people_Led->setGeometry(5,155,290,20);
    validator_age_of_people = new QIntValidator(18,99,this);
    age_of_people_Led->setValidator(validator_age_of_people);

    height_of_people_lbl =  new QLabel("Рост от 100 до 220",this);
    height_of_people_lbl->setGeometry(110,180,150,15);
    height_of_people_Led = new QLineEdit(this);
    height_of_people_Led->setGeometry(5,200,290,20);
    validator = new QIntValidator(100, 220, this);
    height_of_people_Led->setValidator(validator);

    weight_of_people_lbl = new QLabel("Вес от 40 до 120",this);
    weight_of_people_lbl->setGeometry(110,225,150,15);
    weight_of_people_Led = new QLineEdit(this);
    weight_of_people_Led->setGeometry(5,245,290,20);
    weight_of_people_Led->setValidator(validator_weight);


    habits_of_people_lbl = new QLabel("Привычки",this);
    habits_of_people_lbl->setGeometry(120,270,150,15);
    habits_of_people_Led = new QLineEdit(this);
    habits_of_people_Led->setGeometry(5,290,290,20);
    habits_of_people_Led->setValidator(validator_text);

    hobby_of_people_lbl = new QLabel("Хобби",this);
    hobby_of_people_lbl->setGeometry(130,315,150,15);
    hobby_of_people_Led = new QLineEdit(this);
    hobby_of_people_Led->setGeometry(5,335,290,20);
    hobby_of_people_Led->setValidator(validator_text);


    age_min_or_max_lbl = new QLabel("Диапазон возраста Min < Max",this);
    age_min_or_max_lbl->setGeometry(60,360,210,15);
    min_1 = new QLabel("Min от 16",this);
    min_1->setGeometry(70,375,70,15);
    max_1 = new QLabel("Max до 99",this);
    max_1->setGeometry(210,375,70,15);
    age_min_Led = new QLineEdit(this);
    age_min_Led->setGeometry(5,395,140,20);
    age_min_Led->setValidator(validator_age_of_people);
    age_max_Led = new QLineEdit(this);
    age_max_Led->setGeometry(160,395,135,20);
    age_max_Led->setValidator(validator_age_of_people);

    height_min_or_max_lbl = new QLabel("Диапазон роста Min < Max",this);
    height_min_or_max_lbl->setGeometry(80,425,190,15);
    min_2 = new QLabel("Min от 100",this);
    min_2->setGeometry(70,440,70,15);
    max_2 = new QLabel("Max до 220",this);
    max_2->setGeometry(210,440,70,15);
    height_min_Led = new QLineEdit(this);
    height_min_Led->setGeometry(5,460,140,20);
    height_min_Led->setValidator(validator);
    height_max_Led = new QLineEdit(this);
    height_max_Led->setGeometry(160,460,135,20);
    height_max_Led->setValidator(validator);

    weight_min_or_max_lbl = new QLabel("Диапазон веса Min < Max",this);
    weight_min_or_max_lbl->setGeometry(80,490,180,15);
    min_3 = new QLabel("Min от 40",this);
    min_3->setGeometry(70,505,70,15);
    max_3 = new QLabel("Max до 120",this);
    max_3->setGeometry(210,505,70,15);
    weight_min_Led = new QLineEdit(this);
    weight_min_Led->setGeometry(5,525,140,20);
    weight_min_Led->setValidator(validator_weight);
    weight_max_Led = new QLineEdit(this);
    weight_max_Led->setGeometry(160,525,135,20);
    weight_max_Led->setValidator(validator_weight);

    Odin_or_Odna_lbl = new QLabel("Женат или Замужем да или нет",this);
    Odin_or_Odna_lbl->setGeometry(50,555,225,15);
    Odin_or_Odna_Led_YES_or_NO = new QLineEdit(this);
    Odin_or_Odna_Led_YES_or_NO->setGeometry(5,575,290,20);
    Odin_or_Odna_Led_YES_or_NO->setValidator(validator_text);


    disable_Btn();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::my_fun_close()
{
    men_file.close();
    women_file.close();
    close();
}

void Widget::open_men_file()
{
    path_to_men_file = QFileDialog::getOpenFileName(this, "Open_men_file.txt","/home/egor1111/QT C++/build-Laba_2_Task_2-Desktop_Qt_6_6_1_GCC_64bit-Debug", tr("Text File (*.txt)"));
    if (path_to_men_file.isEmpty()) {
        QMessageBox::warning(this,"Ошибка", "Файл не выбран");
        return;
    }
    men_file.setFileName(path_to_men_file);
    men_file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&men_file);

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();
        s7 = fileStream.readLine();
        s8 = fileStream.readLine();
        s9 = fileStream.readLine();
        s10 = fileStream.readLine();
        s11 = fileStream.readLine();
        s12 = fileStream.readLine();
        s13 = fileStream.readLine();
        s14 = fileStream.readLine();

        if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty() ||  s4.isEmpty() || s5.isEmpty() ||
            s6.isEmpty() ||s7.isEmpty() ||s8.isEmpty() ||s9.isEmpty() ||s10.isEmpty() ||
            s11.isEmpty()|| s12.isEmpty() ||s13.isEmpty() ||s14.isEmpty() )
        {
            QMessageBox::warning(this, "Ошибка", "Неправильный файл");
            return;
        }

    }

    men_file.close();
    //enableBtn();
    fun_information_from_men_file();

}

void Widget::fun_information_from_men_file()
{
    men_file.open(QIODevice::ReadWrite);
    QTextStream stream(&men_file);

    QString number_of_people;
    QString name;
    QString age;
    QString height;
    QString weight;
    QString habits;
    QString hobby;
    QString age_min;
    QString age_max;
    QString height_min;
    QString height_max;
    QString weight_min;
    QString weight_max;
    QString Odin_or_Odna;

    QString all = "";

    do {
        stream >> number_of_people;
        if (!number_of_people.isEmpty()) {
            array_men = (projectclass **) realloc(array_men, (number_in_array_men + 1) * sizeof(projectclass *));
            array_men[number_in_array_men] = new projectclass;

            array_men[number_in_array_men]->set_number_of_people(number_of_people);
            stream >> name;
            array_men[number_in_array_men]->set_name(name);
            stream >> age;
            array_men[number_in_array_men]->set_age(age);
            stream >> height;
            array_men[number_in_array_men]->set_height(height);
            stream >> weight;
            array_men[number_in_array_men]->set_weight(weight);
            stream >> habits;
            array_men[number_in_array_men]->set_habits(habits);
            stream >> hobby;
            array_men[number_in_array_men]->set_hobby(hobby);
            stream >> age_min;
            array_men[number_in_array_men]->set_age_min(age_min);
            stream >> age_max;
            array_men[number_in_array_men]->set_age_max(age_max);
            stream >> height_min;
            array_men[number_in_array_men]->set_height_min(height_min);
            stream >> height_max;
            array_men[number_in_array_men]->set_height_max(height_max);
            stream >> weight_min;
            array_men[number_in_array_men]->set_weight_min(weight_min);
            stream >> weight_max;
            array_men[number_in_array_men]->set_weight_max(weight_max);
            stream >> Odin_or_Odna;
            array_men[number_in_array_men]->set_Odin_or_Odna(Odin_or_Odna);
            if (all.indexOf(array_men[number_in_array_men]->get_All_Info()) < 0) {
                all += array_men[number_in_array_men]->get_All_Info();
                number_in_array_men++;
            }
        }
    } while (!number_of_people.isEmpty());
    information_from_men_file->setPlainText(all);

    if(men_file.isOpen() && women_file.isOpen()){
        men_file.close();
        women_file.close();
        enable_Btn();
    }
    all = "";
}

void Widget::open_women_file()
{
    path_to_women_file = QFileDialog::getOpenFileName(this, "Open_women_file.txt","/home/egor1111/QT C++/Laba_2_Task_2", tr("Text File (*.txt)"));
    if (path_to_women_file.isEmpty()) {
        QMessageBox::warning(this,"Ошибка", "Файл не выбран");
        return;
    }
    women_file.setFileName(path_to_women_file);
    women_file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&women_file);

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();
        s7 = fileStream.readLine();
        s8 = fileStream.readLine();
        s9 = fileStream.readLine();
        s10 = fileStream.readLine();
        s11 = fileStream.readLine();
        s12 = fileStream.readLine();
        s13 = fileStream.readLine();
        s14 = fileStream.readLine();

        if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty() || s4.isEmpty() || s5.isEmpty() ||
            s6.isEmpty()|| s7.isEmpty() ||s8.isEmpty() ||s9.isEmpty() ||s10.isEmpty() ||
            s11.isEmpty() || s12.isEmpty() ||s13.isEmpty() ||s14.isEmpty() )
        {
            QMessageBox::warning(this, "Ошибка", "Неправильный файл");
            return;
        }
    }

    women_file.close();
    fun_information_from_women_file();
}

void Widget::fun_information_from_women_file()
{
    women_file.open(QIODevice::ReadWrite);
    QTextStream stream(&women_file);

    QString number_of_people;
    QString name;
    QString age;
    QString height;
    QString weight;
    QString habits;
    QString hobby;
    QString age_min;
    QString age_max;
    QString height_min;
    QString height_max;
    QString weight_min;
    QString weight_max;
    QString Odin_or_Odna;

    QString all = "";

    do {
        stream >> number_of_people;
        if (!number_of_people.isEmpty()) {
            array_women = (projectclass **) realloc(array_women, (number_in_array_women + 1) * sizeof(projectclass *));
            array_women[number_in_array_women] = new projectclass;

            array_women[number_in_array_women]->set_number_of_people(number_of_people);
            stream >> name;
            array_women[number_in_array_women]->set_name(name);
            stream >> age;
            array_women[number_in_array_women]->set_age(age);
            stream >> height;
            array_women[number_in_array_women]->set_height(height);
            stream >> weight;
            array_women[number_in_array_women]->set_weight(weight);
            stream >> habits;
            array_women[number_in_array_women]->set_habits(habits);
            stream >> hobby;
            array_women[number_in_array_women]->set_hobby(hobby);
            stream >> age_min;
            array_women[number_in_array_women]->set_age_min(age_min);
            stream >> age_max;
            array_women[number_in_array_women]->set_age_max(age_max);
            stream >> height_min;
            array_women[number_in_array_women]->set_height_min(height_min);
            stream >> height_max;
            array_women[number_in_array_women]->set_height_max(height_max);
            stream >> weight_min;
            array_women[number_in_array_women]->set_weight_min(weight_min);
            stream >> weight_max;
            array_women[number_in_array_women]->set_weight_max(weight_max);
            stream >> Odin_or_Odna;
            array_women[number_in_array_women]->set_Odin_or_Odna(Odin_or_Odna);
            if (all.indexOf(array_women[number_in_array_women]->get_All_Info()) < 0) {
                all += array_women[number_in_array_women]->get_All_Info();
                number_in_array_women++;
            }
        }
    } while (!number_of_people.isEmpty());
    information_from_women_file->setPlainText(all);
    //answerView->clear();
    all = "";

    if(men_file.isOpen() && women_file.isOpen()){
        men_file.close();
        women_file.close();
        enable_Btn();
    }
   // my_openBtn_for_women->setEnabled(false);
}

void Widget::save_to_men_file()
{
    men_file.open(QIODevice::ReadWrite);
    men_file.resize(0);
    QTextStream stream(&men_file);
    for (int i = 0; i < number_in_array_men; i++) {
        stream << array_men[i]->get_number_of_people()  << "\n";
        stream << array_men[i]->get_name() << "\n";
        stream << array_men[i]->get_age() << "\n";
        stream << array_men[i]->get_height() << "\n";
        stream << array_men[i]->get_weight() << "\n";
        stream << array_men[i]->get_habits() << "\n";
        stream << array_men[i]->get_hobby() << "\n";
        stream << array_men[i]->get_age_min() << "\n";
        stream << array_men[i]->get_age_max() << "\n";
        stream << array_men[i]->get_height_min() << "\n";
        stream << array_men[i]->get_height_max() << "\n";
        stream << array_men[i]->get_weight_min() << "\n";
        stream << array_men[i]->get_weight_max() << "\n";
        stream << array_men[i]->get_Odin_or_Odna() << "\n";
    }
    men_file.close();
}

void Widget::save_to_women_file()
{
    women_file.open(QIODevice::ReadWrite);
    women_file.resize(0);
    QTextStream stream(&women_file);
    for (int i = 0; i < number_in_array_women; i++) {
        stream << array_women[i]->get_number_of_people()  << "\n";
        stream << array_women[i]->get_name() << "\n";
        stream << array_women[i]->get_age() << "\n";
        stream << array_women[i]->get_height() << "\n";
        stream << array_women[i]->get_weight() << "\n";
        stream << array_women[i]->get_habits() << "\n";
        stream << array_women[i]->get_hobby() << "\n";
        stream << array_women[i]->get_age_min() << "\n";
        stream << array_women[i]->get_age_max() << "\n";
        stream << array_women[i]->get_height_min() << "\n";
        stream << array_women[i]->get_height_max() << "\n";
        stream << array_women[i]->get_weight_min() << "\n";
        stream << array_women[i]->get_weight_max() << "\n";
        stream << array_women[i]->get_Odin_or_Odna() << "\n";
    }
    women_file.close();
}

void Widget::save_to_file()
{
    save_to_men_file();
    save_to_women_file();
    QMessageBox::information(this, "Сохранён", "Сохранён!");
}

void Widget::Next_Dialog()
{
    men_or_women();
}

void Widget::men_or_women()
{
    int index = 0;
    if(men_RadioBtn->isChecked()){
        index = 1;
    }else if(women_RadioBtn->isChecked()){
        index = 2;
    }

    if(index == 1){
        add_to_array_men();
    }else if(index == 2){
        add_to_array_women();
    }

}

void Widget::add_to_array_men()
{
    QString number_of_people = number_of_people_Led->text();
    QString name = name_of_people_Led->text();
    QString age = age_of_people_Led->text();
    QString height = height_of_people_Led->text();
    QString weight = weight_of_people_Led->text();
    QString habits = habits_of_people_Led->text();
    QString hobby = hobby_of_people_Led->text();
    QString age_min = age_min_Led->text();
    QString age_max = age_max_Led->text();
    QString height_min = height_min_Led->text();
    QString height_max = height_max_Led->text();
    QString weight_min = weight_min_Led->text();
    QString weight_max = weight_max_Led->text();
    QString Odin_or_Odna = Odin_or_Odna_Led_YES_or_NO->text();

    if (number_of_people.isEmpty() || name.isEmpty() || age.isEmpty() || height.isEmpty() || weight.isEmpty()||
         habits.isEmpty() || hobby.isEmpty() || age_min.isEmpty() || age_max.isEmpty() || height_min.isEmpty()||
         height_max.isEmpty() ||  weight_min.isEmpty() || weight_max.isEmpty() || Odin_or_Odna.isEmpty())
    {
        QMessageBox::warning(this, "Добавьте что-нибудь", "Вы пропускаете некоторые поля");
    }else if(age.toInt()< 16 || age.toInt()>100){
        QMessageBox::warning(this, "Ввод возраста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(height.toInt()< 100 || height.toInt()>221){
        QMessageBox::warning(this, "Ввод роста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(weight.toInt()< 40 || weight.toInt()>121){
        QMessageBox::warning(this, "Ввод веса ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(age_min.toInt()< 16  || age_max.toInt()>100 || age_min.toInt()>age_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона возраста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(height_min.toInt()< 100 || height_max.toInt()>221|| height_min.toInt()>height_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона роста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(weight_min.toInt()< 40 || weight_max.toInt()>121 ||weight_min.toInt()>weight_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона веса ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }
    else
    {
        array_men = (projectclass ** ) realloc(array_men, (number_in_array_men + 1) * sizeof(projectclass *));
        array_men[number_in_array_men] = new projectclass;
        array_men[number_in_array_men]->set_number_of_people(number_of_people);
        array_men[number_in_array_men]->set_name(name);
        array_men[number_in_array_men]->set_age(age);
        array_men[number_in_array_men]->set_height(height);
        array_men[number_in_array_men]->set_weight(weight);
        array_men[number_in_array_men]->set_habits(habits);
        array_men[number_in_array_men]->set_hobby(hobby);
        array_men[number_in_array_men]->set_age_min(age_min);
        array_men[number_in_array_men]->set_age_max(age_max);
        array_men[number_in_array_men]->set_height_min(height_min);
        array_men[number_in_array_men]->set_height_max(height_max);
        array_men[number_in_array_men]->set_weight_min(weight_min);
        array_men[number_in_array_men]->set_weight_max(weight_max);
        array_men[number_in_array_men]->set_Odin_or_Odna(Odin_or_Odna);

        if (information_from_men_file->toPlainText().indexOf(array_men[number_in_array_men]->get_All_Info()) < 0)
        {
            (number_in_array_men)++;
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Создан тот же элемент");
        }
    }

    QString all = "";
    for (int i = 0; i < (number_in_array_men); i++)
    {
        all += array_men[i]->get_All_Info();
    }
    information_from_men_file->setPlainText(all);
    // answerView->clear();
    men_file.close();
}

void Widget::add_to_array_women()
{
    QString number_of_people = number_of_people_Led->text() ;
    QString name = name_of_people_Led->text();
    QString age = age_of_people_Led->text();
    QString height = height_of_people_Led->text();
    QString weight = weight_of_people_Led->text();
    QString habits = habits_of_people_Led->text();
    QString hobby = hobby_of_people_Led->text();
    QString age_min = age_min_Led->text();
    QString age_max = age_min_Led->text();
    QString height_min = height_min_Led->text();
    QString height_max = height_max_Led->text();
    QString weight_min = weight_min_Led->text();
    QString weight_max = weight_max_Led->text();
    QString Odin_or_Odna = Odin_or_Odna_Led_YES_or_NO->text();

    if (number_of_people.isEmpty() || name.isEmpty() || age.isEmpty() || height.isEmpty()|| weight.isEmpty()
        || habits.isEmpty()|| hobby.isEmpty()|| age_min.isEmpty()|| age_max.isEmpty()|| height_min.isEmpty()
        || height_max.isEmpty()|| weight_min.isEmpty()|| weight_max.isEmpty()||Odin_or_Odna.isEmpty() ){
        QMessageBox::warning(this,"Добавьте что-нибудь", "Вы пропускаете некоторые поля");
    }else if(age.toInt()< 16 || age.toInt()>100){
        QMessageBox::warning(this, "Ввод возраста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(height.toInt()< 100 || height.toInt()>221){
        QMessageBox::warning(this, "Ввод роста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(weight.toInt()< 40 || weight.toInt()>121){
        QMessageBox::warning(this, "Ввод веса ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(age_min.toInt()< 16 || age_max.toInt()>100 || age_min.toInt()>age_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона возраста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(height_min.toInt()< 100 || height_max.toInt()>221|| height_min.toInt()>height_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона роста ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }else if(weight_min.toInt()< 40 || weight_max.toInt()>121|| weight_min.toInt()>weight_max.toInt()){
        QMessageBox::warning(this, "Ввод диапазона веса ", "Вы ввели неправильное значение . Вышли за диапазон ");
    }
    else {
        array_women = (projectclass ** ) realloc(array_women, (number_in_array_women + 1) * sizeof(projectclass *));
        array_women[number_in_array_women] = new projectclass;
        array_women[number_in_array_women]->set_number_of_people(number_of_people);
        array_women[number_in_array_women]->set_name(name);
        array_women[number_in_array_women]->set_age(age);
        array_women[number_in_array_women]->set_height(height);
        array_women[number_in_array_women]->set_weight(weight);
        array_women[number_in_array_women]->set_habits(habits);
        array_women[number_in_array_women]->set_hobby(hobby);
        array_women[number_in_array_women]->set_age_min(age_min);
        array_women[number_in_array_women]->set_age_max(age_max);
        array_women[number_in_array_women]->set_height_min(height_min);
        array_women[number_in_array_women]->set_height_max(height_max);
        array_women[number_in_array_women]->set_weight_min(weight_min);
        array_women[number_in_array_women]->set_weight_max(weight_max);
        array_women[number_in_array_women]->set_Odin_or_Odna(Odin_or_Odna);
        if (information_from_women_file->toPlainText().indexOf(array_women[number_in_array_women]->get_All_Info()) < 0)
        {
            (number_in_array_women)++;
        } else {
            QMessageBox::warning(this,"Ошибка", "Создан тот же элемент");
        }
    }

    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) all += array_women[i]->get_All_Info();
    information_from_women_file->setPlainText(all);
    //  answerView->clear();
    women_file.close();
}

void Widget::disable_Btn()
{
    my_openBtn_for_men->setEnabled(true);
    my_qSort_age->setEnabled(false);
    my_qSort_hieght->setEnabled(false);
    my_qSort_number_of_people->setEnabled(false);
    my_qSort_wieght->setEnabled(false);
    my_edit_or_delete->setEnabled(false);
    my_all_pairs->setEnabled(false);
    my_add_new_people->setEnabled(false);
    my_save_file->setEnabled(false);

    men_RadioBtn->setEnabled(false);
    women_RadioBtn->setEnabled(false);

    number_of_people_lbl->setEnabled(false);
    number_of_people_Led->setEnabled(false);

    name_of_people_lbl->setEnabled(false);
    name_of_people_Led->setEnabled(false);

    age_of_people_lbl->setEnabled(false);
    age_of_people_Led->setEnabled(false);

    height_of_people_lbl->setEnabled(false);
    height_of_people_Led->setEnabled(false);

    weight_of_people_lbl->setEnabled(false);
    weight_of_people_Led->setEnabled(false);

    habits_of_people_lbl->setEnabled(false);
    habits_of_people_Led->setEnabled(false);

    hobby_of_people_lbl->setEnabled(false);
    hobby_of_people_Led->setEnabled(false);

    age_min_or_max_lbl->setEnabled(false);
    min_1->setEnabled(false);
    max_1->setEnabled(false);
    age_min_Led->setEnabled(false);
    age_max_Led->setEnabled(false);

    height_min_or_max_lbl->setEnabled(false);
    min_2->setEnabled(false);
    max_2->setEnabled(false);
    height_min_Led->setEnabled(false);
    height_max_Led->setEnabled(false);

    weight_min_or_max_lbl->setEnabled(false);
    min_3->setEnabled(false);
    max_3->setEnabled(false);
    weight_min_Led->setEnabled(false);
    weight_max_Led->setEnabled(false);

    Odin_or_Odna_lbl->setEnabled(false);
    Odin_or_Odna_Led_YES_or_NO->setEnabled(false);
}

void Widget::enable_Btn()
{
    my_openBtn_for_men->setEnabled(false);
    my_qSort_age->setEnabled(true);
    my_qSort_hieght->setEnabled(true);
    my_qSort_number_of_people->setEnabled(true);
    my_qSort_wieght->setEnabled(true);
    my_edit_or_delete->setEnabled(true);
    my_all_pairs->setEnabled(true);
    my_add_new_people->setEnabled(true);
    my_save_file->setEnabled(true);

    men_RadioBtn->setEnabled(true);
    women_RadioBtn->setEnabled(true);

    number_of_people_lbl->setEnabled(true);
    number_of_people_Led->setEnabled(true);

    name_of_people_lbl->setEnabled(true);
    name_of_people_Led->setEnabled(true);

    age_of_people_lbl->setEnabled(true);
    age_of_people_Led->setEnabled(true);

    height_of_people_lbl->setEnabled(true);
    height_of_people_Led->setEnabled(true);

    weight_of_people_lbl->setEnabled(true);
    weight_of_people_Led->setEnabled(true);

    habits_of_people_lbl->setEnabled(true);
    habits_of_people_Led->setEnabled(true);

    hobby_of_people_lbl->setEnabled(true);
    hobby_of_people_Led->setEnabled(true);

    age_min_or_max_lbl->setEnabled(true);
    min_1->setEnabled(true);
    max_1->setEnabled(true);
    age_min_Led->setEnabled(true);
    age_max_Led->setEnabled(true);

    height_min_or_max_lbl->setEnabled(true);
    min_2->setEnabled(true);
    max_2->setEnabled(true);
    height_min_Led->setEnabled(true);
    height_max_Led->setEnabled(true);

    weight_min_or_max_lbl->setEnabled(true);
    min_3->setEnabled(true);
    max_3->setEnabled(true);
    weight_min_Led->setEnabled(true);
    weight_max_Led->setEnabled(true);

    Odin_or_Odna_lbl->setEnabled(true);
    Odin_or_Odna_Led_YES_or_NO->setEnabled(true);
}

bool Widget::number_of_people_compare(projectclass *a, projectclass *b) {
    if (a->get_number_of_people() < b->get_number_of_people()) {
        return true;
    } else if (a->get_number_of_people() > b->get_number_of_people()) {
        return false;
    } else return false;
}

void Widget::number_of_people_Sort_men() {
    number_of_people_qSort_men(0, number_in_array_men - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) {
        all += array_men[i]->get_All_Info();
    }
    information_from_men_file->setPlainText(all);
}

void Widget::number_of_people_Sort_women() {
    number_of_people_qSort_women(0, number_in_array_women - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) {
        all += array_women[i]->get_All_Info();
    }
    information_from_women_file->setPlainText(all);
}

void Widget::number_of_people_qSort_men(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (number_of_people_compare(array_men[l], array_men[mid]))
            l++;
        while (number_of_people_compare(array_men[mid], array_men[r]))
            r--;
        if (l <= r)
            qSwap(array_men[l++], array_men[r--]);
    }
    if (b < r)
        number_of_people_qSort_men(b, r);
    if (e > l)
        number_of_people_qSort_men(l, e);
}

void Widget::number_of_people_qSort_women(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (number_of_people_compare(array_women[l], array_women[mid]))
            l++;
        while (number_of_people_compare(array_women[mid], array_women[r]))
            r--;
        if (l <= r)
            qSwap(array_women[l++], array_women[r--]);
    }
    if (b < r)
        number_of_people_qSort_women(b, r);
    if (e > l)
        number_of_people_qSort_women(l, e);
}

void Widget::number_of_people_Sort_All(){
    number_of_people_Sort_men();
    number_of_people_Sort_women();
}

void Widget::age_Sort_men() {
    age_qSort_men(0, number_in_array_men - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) {
        all += array_men[i]->get_All_Info();
    }
    information_from_men_file->setPlainText(all);
}

void Widget::age_qSort_men(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (age_compare(array_men[l], array_men[mid]))
            l++;
        while (age_compare(array_men[mid], array_men[r]))
            r--;
        if (l <= r)
            qSwap(array_men[l++], array_men[r--]);
    }
    if (b < r)
        age_qSort_men(b, r);
    if (e > l)
        age_qSort_men(l, e);
}

void Widget::age_Sort_women() {
    age_qSort_women(0, number_in_array_women - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) {
        all += array_women[i]->get_All_Info();
    }
    information_from_women_file->setPlainText(all);
}

void Widget::age_qSort_women(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (age_compare(array_women[l], array_women[mid]))
            l++;
        while (age_compare(array_women[mid], array_women[r]))
            r--;
        if (l <= r)
            qSwap(array_women[l++], array_women[r--]);
    }
    if (b < r)
        age_qSort_women(b, r);
    if (e > l)
        age_qSort_women(l, e);
}

bool Widget::age_compare(projectclass *a, projectclass *b) {
    if (a->get_age() < b->get_age()) {
        return true;
    } else if (a->get_age() > b->get_age()) {
        return false;
    } else return false;
}

void Widget::age_Sort_All(){
    age_Sort_men();
    age_Sort_women();
}

void Widget::height_Sort_men() {
    height_qSort_men(0, number_in_array_men - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) {
        all += array_men[i]->get_All_Info();
    }
    information_from_men_file->setPlainText(all);
}

void Widget::height_qSort_men(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (height_compare(array_men[l], array_men[mid]))
            l++;
        while (height_compare(array_men[mid], array_men[r]))
            r--;
        if (l <= r)
            qSwap(array_men[l++], array_men[r--]);
    }
    if (b < r)
        height_qSort_men(b, r);
    if (e > l)
        height_qSort_men(l, e);
}

void Widget::height_Sort_women() {
    height_qSort_women(0, number_in_array_women - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) {
        all += array_women[i]->get_All_Info();
    }
    information_from_women_file->setPlainText(all);
}

void Widget::height_qSort_women(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (height_compare(array_women[l], array_women[mid]))
            l++;
        while (height_compare(array_women[mid], array_women[r]))
            r--;
        if (l <= r)
            qSwap(array_women[l++], array_women[r--]);
    }
    if (b < r)
        height_qSort_women(b, r);
    if (e > l)
        height_qSort_women(l, e);
}

bool Widget::height_compare(projectclass *a, projectclass *b) {
    if (a->get_height() < b->get_height()) {
        return true;
    } else if (a->get_height() > b->get_height()) {
        return false;
    } else return false;
}

void Widget::height_Sort_All(){
    height_Sort_men();
    height_Sort_women();
}

void Widget::weight_Sort_men() {
    weight_qSort_men(0, number_in_array_men - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) {
        all += array_men[i]->get_All_Info();
    }
    information_from_men_file->setPlainText(all);
}

void Widget::weight_qSort_men(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (weight_compare(array_men[l], array_men[mid]))
            l++;
        while (weight_compare(array_men[mid], array_men[r]))
            r--;
        if (l <= r)
            qSwap(array_men[l++], array_men[r--]);
    }
    if (b < r)
        weight_qSort_men(b, r);
    if (e > l)
        weight_qSort_men(l, e);
}

void Widget::weight_Sort_women() {
    weight_qSort_women(0, number_in_array_women - 1);
    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) {
        all += array_women[i]->get_All_Info();
    }
    information_from_women_file->setPlainText(all);
}

void Widget::weight_qSort_women(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (weight_compare(array_women[l], array_women[mid]))
            l++;
        while (weight_compare(array_women[mid], array_women[r]))
            r--;
        if (l <= r)
            qSwap(array_women[l++], array_women[r--]);
    }
    if (b < r)
        weight_qSort_women(b, r);
    if (e > l)
        weight_qSort_women(l, e);
}

bool Widget::weight_compare(projectclass *a, projectclass *b) {
    if (a->get_weight() < b->get_weight()) {
        return true;
    } else if (a->get_weight() > b->get_weight()) {
        return false;
    } else return false;
}

void Widget::weight_Sort_All(){
    weight_Sort_men();
    weight_Sort_women();
}

void Widget::open_my_dialog_3(){
    my_dialog_3 first_okno(this);
    connect(&first_okno, &my_dialog_3::nextPageRequested1, this, &Widget::open_second_dialog_1);
    connect(&first_okno, &my_dialog_3::nextPageRequested2, this, &Widget::open_second_dialog_2);
    first_okno.exec();
}

void Widget::open_second_dialog_1(){
    second_dialog_1 dialog_1(array_men,&number_in_array_men,this);
    dialog_1.exec();
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) all += array_men[i]->get_All_Info();
    information_from_men_file->setPlainText(all);

}

void Widget::open_second_dialog_2(){
    second_dialod_2 dialog_2(array_women,&number_in_array_women,this);
    dialog_2.exec();
    QString all = "";
    for (int i = 0; i < number_in_array_women; i++) all += array_women[i]->get_All_Info();
    information_from_women_file->setPlainText(all);
}

void Widget::All_par(){
    QString all = "";
    for (int i = 0; i < number_in_array_men; i++) {
        for(int j = 0;j<number_in_array_women;j++){
            if(array_men[i]->get_age_min()<=array_women[j]->get_age()&&array_men[i]->get_age_max()>=array_women[j]->get_age()

                &&  array_men[i]->get_height_min()<=array_women[j]->get_height()&&array_men[i]->get_height_max()>=array_women[j]->get_height()

                && array_men[i]->get_weight_min()<=array_women[j]->get_weight()&&array_men[i]->get_weight_max()>=array_women[j]->get_weight()

                && array_women[j]->get_age_min()<=array_men[i]->get_age()&&array_women[j]->get_age_max()>=array_men[i]->get_age()

                &&  array_women[j]->get_height_min()<=array_men[i]->get_height()&&array_women[j]->get_height_max()>=array_men[i]->get_height()

                && array_women[j]->get_weight_min()<=array_men[i]->get_weight()&&array_women[j]->get_weight_max()>=array_men[i]->get_weight()){
                all+= array_men[i]->get_name() +"->"+array_women[j]->get_name()+"\n";
            }
        }
    }
    information_for_my_fun->setPlainText(all);
}
