//
// Created by acryoz on 5/10/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setStyleSheet(
        "background-image:url(\"/home/acryoz/CLionProjects/lab5/src/"
        "background.png\")");

    this->keyboard = new Keyboard;
    this->keyboard->setFocusPolicy(Qt::StrongFocus);
    QObject::connect(this->keyboard, SIGNAL(pressed(QString)), this,
                     SLOT(keyPressed(QString)));

    this->hbox = new QHBoxLayout;

    this->flie_button = new QPushButton("Open a file");
    QObject::connect(this->flie_button, SIGNAL(clicked()), this,
                     SLOT(openFile()));

    this->menu = new QComboBox;
    this->menu->addItem("english");
    this->menu->addItem("russian");
    this->menu->addItem("belorussian");
    this->menu->addItem("german");
    this->menu->addItem("french");
    this->menu->addItem("hebrew");
    this->menu->addItem("chinese");
    this->menu->addItem("arabic");
    QObject::connect(this->menu, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(onMenuChange(int)));
    this->menu->setFocusPolicy(Qt::NoFocus);
    this->hbox->addWidget(this->menu);

    this->timer = new QTimer;
    this->timer->setInterval(TIMER_INTERVAL_MSEC);
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(tick()));

    this->time = new QTime;
    time->setHMS(0, 0, 0);

    this->time_edit = new QLineEdit;
    this->time_edit->setReadOnly(true);
    this->time_edit->setFocusPolicy(Qt::NoFocus);
    this->hbox->addWidget(this->time_edit);

    this->acc_percent = new QLineEdit;
    this->acc_percent->setReadOnly(true);
    this->acc_percent->setFocusPolicy(Qt::NoFocus);
    this->hbox->addWidget(this->acc_percent);

    this->hbox->addWidget(this->flie_button);

    this->text_edit = new TextEdit;
    this->text_edit->setFocusPolicy(Qt::ClickFocus);
    this->text_edit->setReadOnly(true);
    this->text_edit->setText(
        "When Mr. Bilbo Baggins of Bag End announced that he would "
        "shortly be celebrating his eleventy-first birthday with a party of "
        "special magnificence, there was much talk and excitement in "
        "Hobbiton. Bilbo was very rich and very peculiar, and had been the "
        "wonder of the Shire for sixty years, ever since his "
        "remarkable disappearance and unexpected return.");

    QObject::connect(this->text_edit, SIGNAL(mistake(double)), this,
                     SLOT(updateAccuracy(double)));
    QObject::connect(this->text_edit, SIGNAL(ended(int)), this,
                     SLOT(onEnd(int)));

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->hbox);
    this->vbox->addWidget(this->text_edit);
    this->vbox->addWidget(this->keyboard);

    this->setLayout(this->vbox);
}

void MainWindow::updateAccuracy(double new_acc) {
    if (new_acc >= 0) {
        this->acc_percent->setText(QString("%1%").arg(new_acc));
    } else {
        this->acc_percent->setText(QString("%1%").arg(0));
    }
}

void MainWindow::keyPressed(QString str) {
    if (!this->started) {
        this->started = true;
        this->timer->start();
        this->acc_percent->setText("100%");
    }
    this->text_edit->text_inputed(str);
}

void MainWindow::tick() {
    this->time = new QTime(this->time->addMSecs(TIMER_INTERVAL_MSEC));
    this->time_edit->setText(this->time->toString("mm:ss.z"));
}

void MainWindow::onEnd(int words) {
    this->timer->stop();
    double seconds = this->time->minute() * 60 + this->time->second() +
                     this->time->msec() / 1000;
    QMessageBox::information(
        this, "Конец тренировки",
        "Время: " + QString("%1c\n").arg(seconds) + "Скорость: " +
            QString("%1 слов в минуту\n")
                .arg(std::round((((double)words * 60) / seconds))) +
            "Точность: " + this->acc_percent->text());
    this->time->setHMS(0, 0, 0);
    this->time_edit->setText(this->time->toString("mm:ss.z"));
    this->keyboard->updateLayout();
    this->started = false;
    this->opened_file = false;
    this->acc_percent->setText("");
}

void MainWindow::openFile() {
    if (this->started) {
        this->text_edit->terminate();
    }
    QString filename =
        QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    QFile file(filename);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        this->text_edit->setText(file.readAll());
        this->opened_file = true;
        file.close();
    } else {
        QMessageBox::critical(this, "ERROR", "Unable to open file");
    }
}

void MainWindow::onMenuChange(int index) {
    if (this->started) {
        this->text_edit->terminate();
    }
    this->keyboard->setNewLayout(index);
    QString text;
    switch (index) {
        case 0:
            text =
                "When Mr. Bilbo Baggins of Bag End announced that he would "
                "shortly be celebrating his eleventy-first birthday with a "
                "party of "
                "special magnificence, there was much talk and excitement in "
                "Hobbiton. Bilbo was very rich and very peculiar, and had been "
                "the "
                "wonder of the Shire for sixty years, ever since his "
                "remarkable disappearance and unexpected return.";
            break;
        case 1:
            text =
                "Воланд молча поднял стакан и чокнулся с Маргаритой. Маргарита "
                "покорно выпила, думая, что тут же ей и будет конец от спирта. "
                "Но ничего плохого не произошло. Живое тепло потекло по ее "
                "животу, что-то мягко стукнуло в затылок, вернулись силы, как "
                "будто она встала после долгого освежающего сна, кроме того, "
                "почувствовала волчий голод. И при воспоминании о том, что она "
                "не ела ничего со вчерашнего утра, он еще более разгорелся. "
                "Она стала жадно глотать икру.";
            break;
        case 2:
            text =
                "А ты падумаў, сыне, ці вядзе гэта да шчасця?.. Зараз у іх "
                "простыя думкі і пачуцці, упэўненасць у тым, што карысная "
                "іхняя праца і яны самі. Чым ты хочаш гэта замяніць? Ты "
                "ведаеш, якія бяздонні, адна за адну страшнейшыя, расчыняюцца "
                "перад вачыма дасведчанага? Якія бяздонні жаху і холаду? Сам я "
                "не так далёка пайшоў — і то часам адчуваю. Ледзяны холад і "
                "ледзяная самота. З кожным пытаннем усё менш разумееш. Просты "
                "бачыць толькі зладжаны крок чалавечых кагорт. Мудры чуе тупат "
                "чарады, якая бяжыць да прорвы.";
            break;
        case 3:
            text =
                "Das Wichtigste aber ist, daß es auch doppelte Rauchportionen "
                "gegeben hat. Für jeden zehn Zigarren, zwanzig "
                "Zigaretten und zwei Stück Kautabak, das ist sehr anständig. "
                "Ich habe meinen Kautabak mit Katczinsky gegen seine "
                "Zigaretten getauscht, das macht für mich vierzig Zigaretten. "
                "Damit langt man schon einen Tag.";
            break;
        case 4:
            text =
                "Assis en terrasse dans le quartier touristique du Vieux Lyon, "
                "James sirote une limonade bien fraîche. Avec la chaleur "
                "estivale, cette journée d’exploration se révèle très "
                "fatigante! Ce matin, James s’est levé tôt, a loué un vélo et "
                "a parcouru les rues de Lyon. Il a longé les quais de la "
                "Saône, traversé la presqu’île, puis rejoint les quais du "
                "Rhône.";
            break;
        case 5:
            text =
                "תורת התפתחות סוציולוגיה של בקר, החלה בחירות מדינות רבה ב."
                "לערך בדפים על אחר. אם ויש מוסיקה גרמנית ברוכים. בהשחתה לחשבון"
                "את כדי. שמו מושגי אנציקלופדיה ב."
                "לויקיפדים אל, אם מושגי ואמנות אתה. אנא בה מתוך החול";
            break;
        case 6:
            text =
                " "
                "tai4yang5 xiang4 yi1ge4 ju4da4 de5 huo3qiu2, bi1 she4 zhe5 "
                "da4di4, tai2wan1 de5 zhong4xia4, ku4re4 de2 rang4 ren2 "
                "yun1xuan4. bai3 pei4 wen2"
                "ba3 che1zi5 ting2 zai4 gong1chang3 men2kou3, zuan1 chu1 "
                "che1zi5, yi4 gu3 re4lang4 pu1mian4er2lai2, lie4ri4 shan3shuo4 "
                "de2 ta1 zheng1 bu4 kai1yan3 jing1."
                "zou3jin4 gong1chang3, cha2ye4 de5 qing1xiang1 jiu4 mi2man4 "
                "zai4 kong1qi4 zhong1, zai4 jia1za2 zhe5 mo4li5hua1 de5";
            break;
        case 7:
            text =
                "ان عدة الشهور عند الله اثنا عشر شهرا في كتاب الله يوم خلق "
                "السماوات والارض منها اربعة حرم ذلك الدين القيم فلاتظلموا فيهن "
                "انفسكم وقاتلوا المشركين كافة كما يقاتلونكم كافة واعلموا ان "
                "الله مع المتقين ";
            break;
    }
    if (!this->opened_file) {
        this->text_edit->setText(text);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
