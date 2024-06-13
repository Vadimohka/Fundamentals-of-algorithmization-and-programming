//
// Created by acryoz on 15.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->text_edit1 = new QTextEdit;
    this->text_edit1->setReadOnly(true);

    this->text_edit2 = new QTextEdit;
    this->text_edit2->setReadOnly(true);

    this->text_edit3 = new QTextEdit;
    this->text_edit3->setReadOnly(true);

    this->text_edit4 = new QTextEdit;
    this->text_edit4->setReadOnly(true);

    QRegExp regex =
        QRegExp(R"(\d{16}\s[01]\s[A-Za-z]\s\d+\.\d+\s\S*(?:\s\d{12})*)");

    this->validator = new QRegExpValidator(regex);

    this->input_edit = new QLineEdit;
    this->input_edit->setValidator(this->validator);
    this->input_edit->setMinimumWidth(INPUT_LINE_WIDTH);

    this->button = new QPushButton("Do task");
    this->button->setToolTip(
        "1)imei - 16 цифр\n2)включён - 0/1\n3)модель - 1 символ латинского "
        "алфавита\n"
        "4)серийный номер - строка любых символов любой длины\n5)список "
        "номеров телефонов - любое количество номеров (375441234567 - 12 "
        "символов)");
    QObject::connect(this->button, SIGNAL(clicked()), this, SLOT(doTask()));

    this->te_hbox = new QHBoxLayout;
    this->te_hbox->addWidget(this->text_edit1);
    this->te_hbox->addWidget(this->text_edit2);
    this->te_hbox->addWidget(this->text_edit3);
    this->te_hbox->addWidget(this->text_edit4);

    this->u_hbox = new QHBoxLayout;
    this->u_hbox->addWidget(this->input_edit);
    this->u_hbox->addWidget(this->button);

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->u_hbox);
    this->vbox->addLayout(this->te_hbox);

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    QString input_text = this->input_edit->text();
    int pos = 0;
    if (this->validator->validate(input_text, pos) != QValidator::Acceptable) {
        return;
    }
    Smartphone constructed = Smartphone(input_text);
    Smartphone sp1;
    sp1.imei = 1231231231237777;
    sp1.enabled = true;
    sp1.model = 'M';
    sp1.screen_size = 6.1;
    sp1.serial_no = new char[9]{ "ASAD!123" };
    sp1.phone_book = new uint64_t[1]{ 375445343359 };
    sp1.pb_length = 1;

    Smartphone* sp2 = new Smartphone();
    sp2->imei = 4564564564565555;
    sp2->enabled = false;
    sp2->model = 'A';
    sp2->screen_size = 5.5;
    sp2->serial_no = new char[12]{ "IHATEMYLIFE" };
    sp2->phone_book = new uint64_t[0]{};

    Smartphone sp3;
    Smartphone& sp3_ref = sp3;
    sp3_ref.imei = 7897897897891111;
    sp3_ref.enabled = true;
    sp3_ref.model = 'L';
    sp3_ref.screen_size = 4.11;
    sp3_ref.serial_no = new char[7]{ "AABBCC" };
    sp3_ref.phone_book = new uint64_t[2]{ 375445343359, 375291234567 };
    sp3_ref.pb_length = 2;

    this->text_edit1->setText(sp1.print());
    this->text_edit2->setText(sp2->print());
    this->text_edit3->setText(sp3_ref.print());
    this->text_edit4->setText(constructed.print());
}

MainWindow::~MainWindow() {
    delete ui;
}
