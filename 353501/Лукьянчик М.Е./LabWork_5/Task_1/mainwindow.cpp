#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(1050, 900);
    ui->setupUi(this);

    connect(ui->action_A, &QAction::triggered, this, &MainWindow::menu_click_A);
    connect(ui->action_D, &QAction::triggered, this, &MainWindow::menu_click_D);
    connect(ui->action_F, &QAction::triggered, this, &MainWindow::menu_click_F);
    connect(ui->action_K, &QAction::triggered, this, &MainWindow::menu_click_K);
    connect(ui->action_B, &QAction::triggered, this, &MainWindow::menu_click_B);
    connect(ui->action_I, &QAction::triggered, this, &MainWindow::menu_click_I);

    ui->button_0->setEnabled(false);
    ui->button_1->setEnabled(false);
    ui->button_2->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_4->setEnabled(false);
    ui->button_5->setEnabled(false);
    ui->button_6->setEnabled(false);
    ui->button_7->setEnabled(false);
    ui->button_8->setEnabled(false);
    ui->button_9->setEnabled(false);
    ui->button_q->setEnabled(false);
    ui->button_w->setEnabled(false);
    ui->button_e->setEnabled(false);
    ui->button_r->setEnabled(false);
    ui->button_t->setEnabled(false);
    ui->button_y->setEnabled(false);
    ui->button_u->setEnabled(false);
    ui->button_i->setEnabled(false);
    ui->button_o->setEnabled(false);
    ui->button_p->setEnabled(false);
    ui->button_yo->setEnabled(false);
    ui->button_l_scobka->setEnabled(false);
    ui->button_r_scobka->setEnabled(false);
    ui->button_a->setEnabled(false);
    ui->button_s->setEnabled(false);
    ui->button_d->setEnabled(false);
    ui->button_f->setEnabled(false);
    ui->button_g->setEnabled(false);
    ui->button_h->setEnabled(false);
    ui->button_j->setEnabled(false);
    ui->button_k->setEnabled(false);
    ui->button_l->setEnabled(false);
    ui->button_two_punct->setEnabled(false);
    ui->button_two_chert->setEnabled(false);
    ui->button_shift_l->setEnabled(false);
    ui->button_shift_r->setEnabled(false);
    ui->button_z->setEnabled(false);
    ui->button_x->setEnabled(false);
    ui->button_c->setEnabled(false);
    ui->button_v->setEnabled(false);
    ui->button_b->setEnabled(false);
    ui->button_n->setEnabled(false);
    ui->button_m->setEnabled(false);
    ui->button_comma->setEnabled(false);
    ui->button_punkt->setEnabled(false);
    ui->button_slash->setEnabled(false);
    ui->button_probel->setEnabled(false);
    ui->button_backspase->setEnabled(false);
    ui->button_plus->setEnabled(false);
    ui->button_down_slash->setEnabled(false);


    /*ui->button_0->setStyleSheet("color: white;");
    ui->button_1->setStyleSheet("color: white;");
    ui->button_2->setStyleSheet("color: white;");
    ui->button_3->setStyleSheet("color: white;");
    ui->button_4->setStyleSheet("color: white;");
    ui->button_5->setStyleSheet("color: white;");
    ui->button_6->setStyleSheet("color: white;");
    ui->button_7->setStyleSheet("color: white;");
    ui->button_8->setStyleSheet("color: white;");
    ui->button_9->setStyleSheet("color: white;");
    ui->button_q->setStyleSheet("color: white;");
    ui->button_w->setStyleSheet("color: white;");
    ui->button_e->setStyleSheet("color: white;");
    ui->button_r->setStyleSheet("color: white;");
    ui->button_t->setStyleSheet("color: white;");
    ui->button_y->setStyleSheet("color: white;");
    ui->button_u->setStyleSheet("color: white;");
    ui->button_i->setStyleSheet("color: white;");
    ui->button_o->setStyleSheet("color: white;");
    ui->button_p->setStyleSheet("color: white;");
    ui->button_yo->setStyleSheet("color: white;");
    ui->button_l_scobka->setStyleSheet("color: white;");
    ui->button_r_scobka->setStyleSheet("color: white;");
    ui->button_a->setStyleSheet("color: white;");
    ui->button_s->setStyleSheet("color: white;");
    ui->button_d->setStyleSheet("color: white;");
    ui->button_f->setStyleSheet("color: white;");
    ui->button_g->setStyleSheet("color: white;");
    ui->button_h->setStyleSheet("color: white;");
    ui->button_j->setStyleSheet("color: white;");
    ui->button_k->setStyleSheet("color: white;");
    ui->button_l->setStyleSheet("color: white;");
    ui->button_two_punct->setStyleSheet("color: white;");
    ui->button_two_chert->setStyleSheet("color: white;");
    ui->button_shift_l->setStyleSheet("color: white;");
    ui->button_shift_r->setStyleSheet("color: white;");
    ui->button_z->setStyleSheet("color: white;");
    ui->button_x->setStyleSheet("color: white;");
    ui->button_c->setStyleSheet("color: white;");
    ui->button_v->setStyleSheet("color: white;");
    ui->button_b->setStyleSheet("color: white;");
    ui->button_n->setStyleSheet("color: white;");
    ui->button_m->setStyleSheet("color: white;");
    ui->button_comma->setStyleSheet("color: white;");
    ui->button_punkt->setStyleSheet("color: white;");
    ui->button_slash->setStyleSheet("color: white;");
    ui->button_probel->setStyleSheet("color: white;");
    ui->button_backspase->setStyleSheet("color: white;");
    ui->button_plus->setStyleSheet("color: white;");
    ui->button_down_slash->setStyleSheet("color: white;");*/
    ui->button_0->setStyleSheet("background-color: black");
    ui->button_1->setStyleSheet("background-color: black");
    ui->button_2->setStyleSheet("background-color: black");
    ui->button_3->setStyleSheet("background-color: black");
    ui->button_4->setStyleSheet("background-color: black");
    ui->button_5->setStyleSheet("background-color: black");
    ui->button_6->setStyleSheet("background-color: black");
    ui->button_7->setStyleSheet("background-color: black");
    ui->button_8->setStyleSheet("background-color: black");
    ui->button_9->setStyleSheet("background-color: black");
    ui->button_q->setStyleSheet("background-color: black");
    ui->button_w->setStyleSheet("background-color: black");
    ui->button_e->setStyleSheet("background-color: black");
    ui->button_r->setStyleSheet("background-color: black");
    ui->button_t->setStyleSheet("background-color: black");
    ui->button_y->setStyleSheet("background-color: black");
    ui->button_u->setStyleSheet("background-color: black");
    ui->button_i->setStyleSheet("background-color: black");
    ui->button_o->setStyleSheet("background-color: black");
    ui->button_p->setStyleSheet("background-color: black");
    ui->button_l_scobka->setStyleSheet("background-color: black");
    ui->button_r_scobka->setStyleSheet("background-color: black");
    ui->button_yo->setStyleSheet("background-color: black");
    ui->button_a->setStyleSheet("background-color: black");
    ui->button_s->setStyleSheet("background-color: black");
    ui->button_d->setStyleSheet("background-color: black");
    ui->button_f->setStyleSheet("background-color: black");
    ui->button_g->setStyleSheet("background-color: black");
    ui->button_h->setStyleSheet("background-color: black");
    ui->button_j->setStyleSheet("background-color: black");
    ui->button_k->setStyleSheet("background-color: black");
    ui->button_l->setStyleSheet("background-color: black");
    ui->button_two_punct->setStyleSheet("background-color: black");
    ui->button_two_chert->setStyleSheet("background-color: black");
    ui->button_z->setStyleSheet("background-color: black");
    ui->button_x->setStyleSheet("background-color: black");
    ui->button_c->setStyleSheet("background-color: black");
    ui->button_v->setStyleSheet("background-color: black");
    ui->button_b->setStyleSheet("background-color: black");
    ui->button_n->setStyleSheet("background-color: black");
    ui->button_m->setStyleSheet("background-color: black");
    ui->button_comma->setStyleSheet("background-color: black");
    ui->button_punkt->setStyleSheet("background-color: black");
    ui->button_slash->setStyleSheet("background-color: black");
    ui->button_probel->setStyleSheet("background-color: black");
    ui->button_shift_l->setStyleSheet("background-color: black");
    ui->button_shift_r->setStyleSheet("background-color: black");
    ui->button_backspase->setStyleSheet("background-color: black");
    ui->button_down_slash->setStyleSheet("background-color: black");
    ui->button_plus->setStyleSheet("background-color: black");


    line = new MyLineEdit(this);
    line->setGeometry(15,380,1015,60);
    line->setHintText("sfdsd", 1);

    connect(line, &MyLineEdit::resultSignal, this, &MainWindow::Result);
    connect(line, &MyLineEdit::pressResult, this, &MainWindow::Res);

    ui->action_A->trigger();

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, [=]() {
        // Обновляем содержимое QLabel при каждом срабатывании таймера
        time++;
        ui->time_lable->setText(QString::number(time));
        if (time > 0){
            ui->num_lable_sek->setText(QString::number((double)n/time));
        }
    });

    int interval = 1000; // Интервал в миллисекундах (1 секунда)
    updateTimer->setInterval(interval);
    updateTimer->start();
}

void MainWindow::menu_click_A(){
    ui->button_0->setText("0");
    ui->button_1->setText("1");
    ui->button_2->setText("2");
    ui->button_3->setText("3");
    ui->button_4->setText("4");
    ui->button_5->setText("5");
    ui->button_6->setText("6");
    ui->button_7->setText("7");
    ui->button_8->setText("8");
    ui->button_9->setText("9");
    ui->button_q->setText("ض");
    ui->button_w->setText("ص");
    ui->button_e->setText("ث");
    ui->button_r->setText("ق");
    ui->button_t->setText("ف");
    ui->button_y->setText("غ");
    ui->button_u->setText("ع");
    ui->button_i->setText("ه");
    ui->button_o->setText("خ");
    ui->button_p->setText("ح");
    ui->button_yo->setText("ذ");
    ui->button_l_scobka->setText("ج");
    ui->button_r_scobka->setText("د");
    ui->button_a->setText("ش");
    ui->button_s->setText("س");
    ui->button_d->setText("ي");
    ui->button_f->setText("ب");
    ui->button_g->setText("ل");
    ui->button_h->setText("ا");
    ui->button_j->setText("ت");
    ui->button_k->setText("ن");
    ui->button_l->setText("م");
    ui->button_two_punct->setText("ك");
    ui->button_two_chert->setText("ط");
    ui->button_shift_l->setText("يحول");
    ui->button_shift_r->setText("يحول");
    ui->button_z->setText("ئ");
    ui->button_x->setText("ء");
    ui->button_c->setText("ؤ");
    ui->button_v->setText("ر");
    ui->button_b->setText("لا");
    ui->button_n->setText("ى");
    ui->button_m->setText("ة");
    ui->button_comma->setText("و");
    ui->button_punkt->setText("ز");
    ui->button_slash->setText("ظ");
    ui->button_probel->setText("");
    ui->button_backspase->setText("مسافة للخلف");
    ui->button_plus->setText("=");
    ui->button_down_slash->setText("-");

    QString txt;
    QFile file("/home/luk-max/Task_1/Ara.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end());
    txt.remove(txt.length() - 1, 1);
    qDebug() << txt;

    line->setHintText(txt,0);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");

}

void MainWindow::menu_click_D(){
    ui->button_0->setText("0");
    ui->button_1->setText("1");
    ui->button_2->setText("2");
    ui->button_3->setText("3");
    ui->button_4->setText("4");
    ui->button_5->setText("5");
    ui->button_6->setText("6");
    ui->button_7->setText("7");
    ui->button_8->setText("8");
    ui->button_9->setText("9");
    ui->button_q->setText("q");
    ui->button_w->setText("w");
    ui->button_e->setText("e");
    ui->button_r->setText("r");
    ui->button_t->setText("t");
    ui->button_y->setText("z");
    ui->button_u->setText("u");
    ui->button_i->setText("i");
    ui->button_o->setText("o");
    ui->button_p->setText("p");
    ui->button_yo->setText("^");
    ui->button_l_scobka->setText("ü");
    ui->button_r_scobka->setText("+");
    ui->button_a->setText("a");
    ui->button_s->setText("s");
    ui->button_d->setText("d");
    ui->button_f->setText("f");
    ui->button_g->setText("g");
    ui->button_h->setText("h");
    ui->button_j->setText("j");
    ui->button_k->setText("k");
    ui->button_l->setText("l");
    ui->button_two_punct->setText("ö");
    ui->button_two_chert->setText("ä");
    ui->button_shift_l->setText("Shift");
    ui->button_shift_r->setText("Shift");
    ui->button_z->setText("y");
    ui->button_x->setText("x");
    ui->button_c->setText("c");
    ui->button_v->setText("v");
    ui->button_b->setText("b");
    ui->button_n->setText("n");
    ui->button_m->setText("m");
    ui->button_comma->setText(",");
    ui->button_punkt->setText(".");
    ui->button_slash->setText("-");
    ui->button_probel->setText("");
    ui->button_backspase->setText("backspace");
    ui->button_plus->setText("´");
    ui->button_down_slash->setText("ß");

        QString txt;
    QFile file("/home/luk-max/Task_1/Deu.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end());
    txt.remove(txt.length() - 1, 1);
    qDebug() << txt;

    line->setHintText(txt,1);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");
}

void MainWindow::menu_click_F(){
    ui->button_q->setText("a");
    ui->button_w->setText("z");
    ui->button_e->setText("e");
    ui->button_r->setText("r");
    ui->button_t->setText("t");
    ui->button_y->setText("y");
    ui->button_u->setText("u");
    ui->button_i->setText("i");
    ui->button_o->setText("o");
    ui->button_p->setText("p");
    ui->button_yo->setText("²");
    ui->button_l_scobka->setText("^");
    ui->button_r_scobka->setText("$");
    ui->button_a->setText("q");
    ui->button_s->setText("s");
    ui->button_d->setText("d");
    ui->button_f->setText("f");
    ui->button_g->setText("g");
    ui->button_h->setText("h");
    ui->button_j->setText("j");
    ui->button_k->setText("k");
    ui->button_l->setText("l");
    ui->button_two_punct->setText("m");
    ui->button_two_chert->setText("ù");
    ui->button_shift_l->setText("Changement");
    ui->button_shift_r->setText("Changement");
    ui->button_z->setText("w");
    ui->button_x->setText("x");
    ui->button_c->setText("c");
    ui->button_v->setText("v");
    ui->button_b->setText("b");
    ui->button_n->setText("n");
    ui->button_m->setText(",");
    ui->button_comma->setText(";");
    ui->button_punkt->setText(":");
    ui->button_slash->setText("!");
    ui->button_probel->setText("");
    ui->button_backspase->setText("retour arrière");
    ui->button_plus->setText("=");
    ui->button_down_slash->setText(")");

    QString txt;
    QFile file("/home/luk-max/Task_1/Fr.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end());
    txt.remove(txt.length() - 1, 1);
    qDebug() << txt;

    line->setHintText(txt,2);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");
}

void MainWindow::menu_click_K(){
    ui->button_0->setText("0");
    ui->button_1->setText("1");
    ui->button_2->setText("2");
    ui->button_3->setText("3");
    ui->button_4->setText("4");
    ui->button_5->setText("5");
    ui->button_6->setText("6");
    ui->button_7->setText("7");
    ui->button_8->setText("8");
    ui->button_9->setText("9");
    ui->button_q->setText("q");
    ui->button_w->setText("w");
    ui->button_e->setText("e");
    ui->button_r->setText("r");
    ui->button_t->setText("t");
    ui->button_y->setText("y");
    ui->button_u->setText("u");
    ui->button_i->setText("i");
    ui->button_o->setText("o");
    ui->button_p->setText("p");
    ui->button_yo->setText("`");
    ui->button_l_scobka->setText("[");
    ui->button_r_scobka->setText("]");
    ui->button_a->setText("a");
    ui->button_s->setText("s");
    ui->button_d->setText("d");
    ui->button_f->setText("f");
    ui->button_g->setText("g");
    ui->button_h->setText("h");
    ui->button_j->setText("j");
    ui->button_k->setText("k");
    ui->button_l->setText("l");
    ui->button_two_punct->setText(";");
    ui->button_two_chert->setText("'");
    ui->button_shift_l->setText("Shift");
    ui->button_shift_r->setText("Shift");
    ui->button_z->setText("z");
    ui->button_x->setText("x");
    ui->button_c->setText("c");
    ui->button_v->setText("v");
    ui->button_b->setText("b");
    ui->button_n->setText("n");
    ui->button_m->setText("m");
    ui->button_comma->setText(",");
    ui->button_punkt->setText(".");
    ui->button_slash->setText("/");
    ui->button_probel->setText("");
    ui->button_backspase->setText("backspace");
    ui->button_plus->setText("=");
    ui->button_down_slash->setText("-");

    QString txt;
    QFile file("/home/luk-max/Task_1/Kit.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end();
    txt.remove(txt.length() - 1, 1);
    qDebug() << txt;

    line->setHintText(txt,3);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");
}

void MainWindow::menu_click_B(){
    ui->button_0->setText("0");
    ui->button_1->setText("1");
    ui->button_2->setText("2");
    ui->button_3->setText("3");
    ui->button_4->setText("4");
    ui->button_5->setText("5");
    ui->button_6->setText("6");
    ui->button_7->setText("7");
    ui->button_8->setText("8");
    ui->button_9->setText("9");
    ui->button_q->setText("й");
    ui->button_w->setText("ц");
    ui->button_e->setText("у");
    ui->button_r->setText("к");
    ui->button_t->setText("е");
    ui->button_y->setText("н");
    ui->button_u->setText("г");
    ui->button_i->setText("ш");
    ui->button_o->setText("ў");
    ui->button_p->setText("з");
    ui->button_yo->setText("ё");
    ui->button_l_scobka->setText("х");
    ui->button_r_scobka->setText("'");
    ui->button_a->setText("ф");
    ui->button_s->setText("ы");
    ui->button_d->setText("в");
    ui->button_f->setText("а");
    ui->button_g->setText("п");
    ui->button_h->setText("р");
    ui->button_j->setText("о");
    ui->button_k->setText("л");
    ui->button_l->setText("д");
    ui->button_two_punct->setText("ж");
    ui->button_two_chert->setText("э");
    ui->button_shift_l->setText("Shift");
    ui->button_shift_r->setText("Shift");
    ui->button_z->setText("я");
    ui->button_x->setText("ч");
    ui->button_c->setText("с");
    ui->button_v->setText("м");
    ui->button_b->setText("і");
    ui->button_n->setText("т");
    ui->button_m->setText("ь");
    ui->button_comma->setText("б");
    ui->button_punkt->setText("ю");
    ui->button_slash->setText(".");
    ui->button_probel->setText("");
    ui->button_backspase->setText("Backspace");
    ui->button_plus->setText("=");
    ui->button_down_slash->setText("-");

    QString txt;
    QFile file("/home/luk-max/Task_1/Bel.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end());
    txt.remove(txt.length() - 1, 1);
    qDebug() << txt;

    line->setHintText(txt,4);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");
}

void MainWindow::menu_click_I(){
    ui->button_0->setText("0");
    ui->button_1->setText("1");
    ui->button_2->setText("2");
    ui->button_3->setText("3");
    ui->button_4->setText("4");
    ui->button_5->setText("5");
    ui->button_6->setText("6");
    ui->button_7->setText("7");
    ui->button_8->setText("8");
    ui->button_9->setText("9");
    ui->button_q->setText("/");
    ui->button_w->setText("'");
    ui->button_e->setText("ק");
    ui->button_r->setText("ר");
    ui->button_t->setText("א");
    ui->button_y->setText("ט");
    ui->button_u->setText("ו");
    ui->button_i->setText("ן");
    ui->button_o->setText("ם");
    ui->button_p->setText("פ");
    ui->button_yo->setText(";");
    ui->button_l_scobka->setText("]");
    ui->button_r_scobka->setText("[");
    ui->button_a->setText("ש");
    ui->button_s->setText("ד");
    ui->button_d->setText("ג");
    ui->button_f->setText("כ");
    ui->button_g->setText("ע");
    ui->button_h->setText("י");
    ui->button_j->setText("ח");
    ui->button_k->setText("ל");
    ui->button_l->setText("ך");
    ui->button_two_punct->setText("ף");
    ui->button_two_chert->setText(",");
    ui->button_shift_l->setText("מִשׁמֶרֶת");
    ui->button_shift_r->setText("מִשׁמֶרֶת");
    ui->button_z->setText("ז");
    ui->button_x->setText("ס");
    ui->button_c->setText("ב");
    ui->button_v->setText("ה");
    ui->button_b->setText("נ");
    ui->button_n->setText("מ");
    ui->button_m->setText("צ");
    ui->button_comma->setText("ת");
    ui->button_punkt->setText("ץ");
    ui->button_slash->setText(".");
    ui->button_probel->setText("");
    ui->button_backspase->setText("מקש לחזור אחורה");
    ui->button_plus->setText("=");
    ui->button_down_slash->setText("-");

    QString txt;
    QFile file("/home/luk-max/Task_1/Ivr.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        QTextStream in(&file);
        txt = in.readAll(); // Считываем строку из файла
        file.close(); // Закрываем файл
    } else {
        qDebug() << "Не удалось открыть файл.";
    }
    //txt.erase(txt.end()-1, txt.end());
    txt.remove(txt.length() - 1);
    qDebug() << txt;

    line->setHintText(txt,5);

    n = 0;
    time = 0;
    ui->time_lable->setText("");
    ui->num_lable->setText("");
    ui->num_lable_sek->setText("");
}

void MainWindow::Result(int res){
    if (res)
    {
        QTimer *timer = new QTimer(this);
        //this->setStyleSheet("background-color: blue;");
        // Подключение сигнала timeout к лямбда-функции
        connect(timer, &QTimer::timeout, this, [=]() {
        //    this->setStyleSheet("background-color: gray;");
            timer->deleteLater();  // Освобождение памяти от таймера
        });

        timer->start(300);

    }
    else {n++;}
}

void MainWindow::Res(QString t){
    QTimer *timer = new QTimer(this);
    timer->start(300);
    connect(timer, &QTimer::timeout, this, [=]() {

        ui->button_0->setStyleSheet("background-color: black");
        ui->button_1->setStyleSheet("background-color: black");
        ui->button_2->setStyleSheet("background-color: black");
        ui->button_3->setStyleSheet("background-color: black");
        ui->button_4->setStyleSheet("background-color: black");
        ui->button_5->setStyleSheet("background-color: black");
        ui->button_6->setStyleSheet("background-color: black");
        ui->button_7->setStyleSheet("background-color: black");
        ui->button_8->setStyleSheet("background-color: black");
        ui->button_9->setStyleSheet("background-color: black");
        ui->button_q->setStyleSheet("background-color: black");
        ui->button_w->setStyleSheet("background-color: black");
        ui->button_e->setStyleSheet("background-color: black");
        ui->button_r->setStyleSheet("background-color: black");
        ui->button_t->setStyleSheet("background-color: black");
        ui->button_y->setStyleSheet("background-color: black");
        ui->button_u->setStyleSheet("background-color: black");
        ui->button_i->setStyleSheet("background-color: black");
        ui->button_o->setStyleSheet("background-color: black");
        ui->button_p->setStyleSheet("background-color: black");
        ui->button_l_scobka->setStyleSheet("background-color: black");
        ui->button_r_scobka->setStyleSheet("background-color: black");
        ui->button_yo->setStyleSheet("background-color: black");
        ui->button_a->setStyleSheet("background-color: black");
        ui->button_s->setStyleSheet("background-color: black");
        ui->button_d->setStyleSheet("background-color: black");
        ui->button_f->setStyleSheet("background-color: black");
        ui->button_g->setStyleSheet("background-color: black");
        ui->button_h->setStyleSheet("background-color: black");
        ui->button_j->setStyleSheet("background-color: black");
        ui->button_k->setStyleSheet("background-color: black");
        ui->button_l->setStyleSheet("background-color: black");
        ui->button_two_punct->setStyleSheet("background-color: black");
        ui->button_two_chert->setStyleSheet("background-color: black");
        ui->button_z->setStyleSheet("background-color: black");
        ui->button_x->setStyleSheet("background-color: black");
        ui->button_c->setStyleSheet("background-color: black");
        ui->button_v->setStyleSheet("background-color: black");
        ui->button_b->setStyleSheet("background-color: black");
        ui->button_n->setStyleSheet("background-color: black");
        ui->button_m->setStyleSheet("background-color: black");
        ui->button_comma->setStyleSheet("background-color: black");
        ui->button_punkt->setStyleSheet("background-color: black");
        ui->button_slash->setStyleSheet("background-color: black");
        ui->button_probel->setStyleSheet("background-color: black");
        ui->button_shift_l->setStyleSheet("background-color: black");
        ui->button_shift_r->setStyleSheet("background-color: black");
        ui->button_backspase->setStyleSheet("background-color: black");
        ui->button_down_slash->setStyleSheet("background-color: black");
        ui->button_plus->setStyleSheet("background-color: black");

        timer->deleteLater();  // Освобождение памяти от таймера
    });

    if (t == '0'){ui->button_0->setStyleSheet("background-color : white");}
    if (t == '1'){ui->button_1->setStyleSheet("background-color : white");}
    if (t == '2'){ui->button_2->setStyleSheet("background-color : white");}
    if (t == '3'){ui->button_3->setStyleSheet("background-color : white");}
    if (t == '4'){ui->button_4->setStyleSheet("background-color : white");}
    if (t == '5'){ui->button_5->setStyleSheet("background-color : white");}
    if (t == '6'){ui->button_6->setStyleSheet("background-color : white");}
    if (t == '7'){ui->button_7->setStyleSheet("background-color : white");}
    if (t == '8'){ui->button_8->setStyleSheet("background-color : white");}
    if (t == '9'){ui->button_9->setStyleSheet("background-color : white");}
    if (t == 'q'){ui->button_q->setStyleSheet("background-color : white");}
    if (t == 'w'){ui->button_w->setStyleSheet("background-color : white");}
    if (t == 'e'){ui->button_e->setStyleSheet("background-color : white");}
    if (t == 'r'){ui->button_r->setStyleSheet("background-color : white");}
    if (t == 't'){ui->button_t->setStyleSheet("background-color : white");}
    if (t == 'y'){ui->button_y->setStyleSheet("background-color : white");}
    if (t == 'u'){ui->button_u->setStyleSheet("background-color : white");}
    if (t == 'i'){ui->button_i->setStyleSheet("background-color : white");}
    if (t == 'o'){ui->button_o->setStyleSheet("background-color : white");}
    if (t == 'p'){ui->button_p->setStyleSheet("background-color : white");}
    if (t == '['){ui->button_r_scobka->setStyleSheet("background-color : white");}
    if (t == ']'){ui->button_l_scobka->setStyleSheet("background-color : white");}
    if (t == "`"){ui->button_yo->setStyleSheet("background-color : white");}
    if (t == 'a'){ui->button_a->setStyleSheet("background-color : white");}
    if (t == 's'){ui->button_s->setStyleSheet("background-color : white");}
    if (t == 'd'){ui->button_d->setStyleSheet("background-color : white");}
    if (t == 'f'){ui->button_f->setStyleSheet("background-color : white");}
    if (t == 'g'){ui->button_g->setStyleSheet("background-color : white");}
    if (t == 'h'){ui->button_h->setStyleSheet("background-color : white");}
    if (t == 'j'){ui->button_j->setStyleSheet("background-color : white");}
    if (t == 'k'){ui->button_k->setStyleSheet("background-color : white");}
    if (t == 'l'){ui->button_l->setStyleSheet("background-color : white");}
    if (t == ';'){ui->button_two_punct->setStyleSheet("background-color : white");}
    if (t == "'"){ui->button_two_chert->setStyleSheet("background-color : white");}
    if (t == 'z'){ui->button_z->setStyleSheet("background-color : white");}
    if (t == 'x'){ui->button_x->setStyleSheet("background-color : white");}
    if (t == 'c'){ui->button_c->setStyleSheet("background-color : white");}
    if (t == 'v'){ui->button_v->setStyleSheet("background-color : white");}
    if (t == 'b'){ui->button_b->setStyleSheet("background-color : white");}
    if (t == 'n'){ui->button_n->setStyleSheet("background-color : white");}
    if (t == 'm'){ui->button_m->setStyleSheet("background-color : white");}
    if (t == ','){ui->button_comma->setStyleSheet("background-color : white");}
    if (t == '.'){ui->button_punkt->setStyleSheet("background-color : white");}
    if (t == '/'){ui->button_slash->setStyleSheet("background-color : white");}
    if (t == ' '){ui->button_probel->setStyleSheet("background-color : white");}
    if (t == '@'){ui->button_shift_l->setStyleSheet("background-color : white");}
    if (t == '@'){ui->button_shift_r->setStyleSheet("background-color : white");}
    if (t == '#'){ui->button_backspase->setStyleSheet("background-color : white");}
    if (t == '-'){ui->button_down_slash->setStyleSheet("background-color : white");}
    if (t == '='){ui->button_plus->setStyleSheet("background-color : white");}
    ui->num_lable->setText(QString::number(n));
}

MainWindow::~MainWindow()
{
    delete ui;
}
