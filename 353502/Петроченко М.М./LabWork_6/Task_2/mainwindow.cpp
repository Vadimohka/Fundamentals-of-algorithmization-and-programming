//
// Created by acryoz on 15.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include "mainwindow.h"
#include "ui_mainwindow2.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->stacked_widget = new QStackedWidget;
    this->combo_box = new QComboBox;
    this->combo_box->addItem("first subtask");
    this->combo_box->addItem("second subtask");
    this->combo_box->addItem("third subtask");
    this->combo_box->addItem("fourth subtask");
    this->combo_box->addItem("fifth subtask");
    QObject::connect(this->combo_box, SIGNAL(activated(int)),
                     this->stacked_widget, SLOT(setCurrentIndex(int)));

    this->first_page = new QWidget;
    //first screen
    this->first_page = new QWidget;
    this->first_input = new QTextEdit;
    this->first_input->installEventFilter(this);
    this->first_output = new QTextEdit;
    this->first_output->setReadOnly(true);
    this->first_grid = new QGridLayout;
    this->first_grid->addWidget(this->first_input, 0, 0);
    this->first_grid->addWidget(this->first_output, 1, 0);
    this->first_page->setLayout(this->first_grid);
    this->stacked_widget->addWidget(this->first_page);

    this->second_page = new QWidget;
    this->second_output = new QLabel;
    this->second_input_1 = new QLineEdit;
    this->second_input_1->setPlaceholderText("Number of numbers");
    this->int_validator = new QIntValidator(1, 9);
    this->second_input_1->setValidator(this->int_validator);
    this->second_input_2 = new QLineEdit;
    this->second_input_2->setPlaceholderText("Numbers");
    this->second_button = new QPushButton("Do task");
    QRegExp regex(R"(-?\d{1,5}(?:\|-?\d{1,5})*)");
    this->second_validator = new QRegExpValidator(regex);
    this->second_input_2->setValidator(this->second_validator);
    QObject::connect(this->second_button, SIGNAL(clicked(bool)), this,
                     SLOT(secondTask()));
    this->second_grid = new QGridLayout;
    this->second_hbox = new QHBoxLayout;
    this->second_hbox->addWidget(this->second_input_1);
    this->second_hbox->addWidget(this->second_button);
    this->second_grid->addLayout(this->second_hbox, 0, 0);
    this->second_grid->addWidget(this->second_input_2, 1, 0);
    this->second_grid->addWidget(this->second_output, 2, 0);
    this->second_page->setLayout(this->second_grid);
    this->stacked_widget->addWidget(this->second_page);

    //OTHERS
    this->third_page = new QWidget;
    this->third_input = new QLineEdit;
    this->third_button = new QPushButton("why");
    QObject::connect(this->third_button, SIGNAL(clicked()), this,
                     SLOT(thirdTask()));
    this->third_output = new QTextEdit;
    this->third_output->setReadOnly(true);
    this->third_button_2 = new QPushButton("print");
    QObject::connect(this->third_button_2, SIGNAL(clicked()), this,
                     SLOT(thirdTaskPrint()));
    this->third_grid = new QGridLayout;
    QRegExp third_regex =
        QRegExp(R"(\d{16}\s[01]\s[A-Za-z]\s\d+\.\d+\s\S*(?:\s\d{12})*)");
    this->third_validator = new QRegExpValidator(third_regex);
    this->third_hbox = new QHBoxLayout;
    this->third_input->setValidator(this->third_validator);
    this->third_hbox->addWidget(this->third_input);
    this->third_hbox->addWidget(this->third_button);
    this->third_hbox->addWidget(this->third_button_2);
    this->third_grid->addLayout(this->third_hbox, 0, 0);
    this->third_grid->addWidget(this->third_output, 1, 0);
    this->third_page->setLayout(this->third_grid);
    this->stacked_widget->addWidget(this->third_page);

    this->fourth_page = new QWidget;
    this->fourth_input = new QLineEdit;
    this->fourth_button = new QPushButton("why2");
    QObject::connect(this->fourth_button, SIGNAL(clicked()), this,
                     SLOT(fourthTask()));
    this->fourth_output = new QTextEdit;
    this->fourth_output->setReadOnly(true);
    this->fourth_button_2 = new QPushButton("print");
    QObject::connect(this->fourth_button_2, SIGNAL(clicked()), this,
                     SLOT(fourthTaskPrint()));
    this->fourth_grid = new QGridLayout;
    QRegExp fourth_regex =
        QRegExp(R"(\d{16}\s[01]\s[A-Za-z]\s\d+\.\d+\s\S*(?:\s\d{12})*)");
    this->fourth_validator = new QRegExpValidator(third_regex);
    this->fourth_hbox = new QHBoxLayout;
    this->fourth_input->setValidator(this->fourth_validator);
    this->fourth_hbox->addWidget(this->fourth_input);
    this->fourth_hbox->addWidget(this->fourth_button);
    this->fourth_hbox->addWidget(this->fourth_button_2);
    this->fourth_grid->addLayout(this->fourth_hbox, 0, 0);
    this->fourth_grid->addWidget(this->fourth_output, 1, 0);
    this->fourth_page->setLayout(this->fourth_grid);
    this->stacked_widget->addWidget(this->fourth_page);

    this->fifth_page = new QWidget;
    //first screen
    this->fifth_page = new QWidget;
    this->fifth_input = new QTextEdit;
    this->fifth_input->installEventFilter(this);
    this->fifth_output = new QTextEdit;
    this->fifth_output->setReadOnly(true);
    this->fifth_grid = new QGridLayout;
    this->fifth_grid->addWidget(this->fifth_input, 0, 0);
    this->fifth_grid->addWidget(this->fifth_output, 1, 0);
    this->fifth_page->setLayout(this->fifth_grid);
    this->stacked_widget->addWidget(this->fifth_page);

    this->main_vbox = new QVBoxLayout;
    this->main_vbox->addWidget(this->combo_box);
    this->main_vbox->addWidget(this->stacked_widget);
    this->setLayout(this->main_vbox);
}

bool MainWindow::eventFilter(QObject* object, QEvent* event) {
    if (object == this->first_input && event->type() == QEvent::KeyPress) {
        if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_Enter ||
            static_cast<QKeyEvent*>(event)->key() == Qt::Key_Return) {
            this->firstTask();
        }
    } else if (object == this->fifth_input &&
               event->type() == QEvent::KeyPress) {
        if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_Enter ||
            static_cast<QKeyEvent*>(event)->key() == Qt::Key_Return) {
            this->fifthTask();
        }
    }
    return false;
}

void MainWindow::firstTask() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20.txt");
    if (!file.open(QIODevice::Truncate | QIODevice::ReadWrite)) {
        return;
    }
    this->first_input->removeEventFilter(this);
    QString data = this->first_input->toPlainText();
    std::string str = data.trimmed().toStdString();
    for (auto ch : str) {
        file.putChar(ch);
        file.flush();
    }
    this->firstTaskPrint();
    file.close();
}

void MainWindow::firstTaskPrint() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20.txt");
    this->first_output->clear();
    this->first_input->clear();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    QString data = file.readLine();
    for (auto ch : data) {
        this->first_output->setText(this->first_output->toPlainText() + ch);
    }
    this->first_input->installEventFilter(this);
}

void MainWindow::secondTask() {
    uint len = this->second_input_1->text().toUInt();
    if (len == 0) {
        return;
    }
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_0.txt");
    if (!file.open(QIODevice::Truncate | QIODevice::ReadWrite)) {
        return;
    }
    auto nums = this->second_input_2->text().split("|");
    QTextStream stream(&file);
    for (int i = 0; i < len; ++i) {
        stream << nums[i].toInt() << "|";
    }
    file.close();
    this->secondTaskPrint();
}

void MainWindow::secondTaskPrint() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_0.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    this->second_input_2->clear();
    this->second_input_1->clear();
    QTextStream stream(&file);
    QString str;
    stream >> str;
    this->second_output->clear();
    auto nums = str.split("|");
    for (auto num : nums) {
        this->second_output->setText(this->second_output->text() + " " + num);
    }
    file.close();
}

void MainWindow::thirdTask() {
    QRegExp regex =
        QRegExp(R"(\d{16}\s[01]\s[A-Za-z]\s\d+\.\d+\s\S*(?:\s\d{12})*)");
    QRegExpValidator validator(regex);
    auto str = this->third_input->text();
    int pos = 0;
    if (validator.validate(str, pos) != QValidator::Acceptable) {
        return;
    }
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_1.txt");
    if (!file.open(QIODevice::Append | QIODevice::ReadWrite)) {
        return;
    }
    QTextStream stream(&file);
    Smartphone smartphone = Smartphone(str);
    stream << smartphone.imei << "|" << smartphone.serial_no << "|"
           << smartphone.model << "|" << smartphone.screen_size << "|"
           << smartphone.enabled;
    for (int i = 0; i < smartphone.pb_length; ++i) {
        stream << "|" << smartphone.phone_book[i];
    }
    stream << '\n';
    file.close();
}

void MainWindow::thirdTaskPrint() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    QTextStream in(&file);
    this->third_output->clear();
    while (!in.atEnd()) {
        QString phone = in.readLine();
        this->third_output->setPlainText(this->third_output->toPlainText() +
                                         phone + '\n');
    }
}

void MainWindow::fourthTask() {
    auto str = this->fourth_input->text();
    if (str == "" || str == " ") {
        return;
    }
    std::ofstream file(
        "/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_2.bin",
        std::ios::out | std::ios::binary | std::ios::app);
    Smartphone smartphone = Smartphone(str);
    file.write(reinterpret_cast<const char*>(&smartphone.imei),
               sizeof smartphone.imei);
    size_t len = strlen(smartphone.serial_no);
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(smartphone.serial_no,
               strlen(smartphone.serial_no) * sizeof(char));
    file.write(reinterpret_cast<const char*>(&smartphone.model),
               sizeof smartphone.model);
    file.write(reinterpret_cast<const char*>(&smartphone.screen_size),
               sizeof smartphone.screen_size);
    file.write(reinterpret_cast<const char*>(&smartphone.enabled),
               sizeof smartphone.enabled);
    file.write(reinterpret_cast<const char*>(&smartphone.pb_length),
               sizeof smartphone.pb_length);
    for (int i = 0; i < smartphone.pb_length; ++i) {
        file.write(reinterpret_cast<const char*>(&smartphone.phone_book[i]),
                   sizeof smartphone.phone_book[i]);
    }
    file.close();
}

void MainWindow::fourthTaskPrint() {
    std::ifstream file(
        "/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_2.bin",
        std::ios::in | std::ios::binary);
    Smartphone smartphone{};
    this->fourth_output->clear();
    while (file.peek() != std::istream::traits_type::eof()) {
        file.read(reinterpret_cast<char*>(&smartphone.imei),
                  sizeof smartphone.imei);
        size_t len;
        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        smartphone.serial_no = new char[len];
        file.read(smartphone.serial_no, len * sizeof(char));
        file.read(reinterpret_cast<char*>(&smartphone.model),
                  sizeof smartphone.model);
        file.read(reinterpret_cast<char*>(&smartphone.screen_size),
                  sizeof smartphone.screen_size);
        file.read(reinterpret_cast<char*>(&smartphone.enabled),
                  sizeof smartphone.enabled);
        file.read(reinterpret_cast<char*>(&smartphone.pb_length),
                  sizeof smartphone.pb_length);
        smartphone.phone_book = new uint64_t[smartphone.pb_length];
        for (int i = 0; i < smartphone.pb_length; ++i) {
            file.read(reinterpret_cast<char*>(&smartphone.phone_book[i]),
                      sizeof smartphone.phone_book[i]);
        }
        QString ph = QString("%1;%2;%3;%4;%5;")
                         .arg(smartphone.imei)
                         .arg(smartphone.serial_no)
                         .arg(smartphone.model)
                         .arg(smartphone.screen_size)
                         .arg(smartphone.enabled);
        for (int i = 0; i < smartphone.pb_length; ++i) {
            ph += QString("%1;").arg(smartphone.phone_book[i]);
        }
        this->fourth_output->setPlainText(this->fourth_output->toPlainText() +
                                          ph + '\n');
    }
}

void MainWindow::fifthTask() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_3.txt");
    if (!file.open(QIODevice::Append | QIODevice::ReadWrite)) {
        return;
    }
    this->first_input->removeEventFilter(this);
    QTextStream stream(&file);
    stream << this->fifth_input->toPlainText().trimmed() << "\n";
    stream.flush();
    this->fifthTaskPrint();
    file.close();
}

void MainWindow::fifthTaskPrint() {
    QFile file("/home/acryoz/CLionProjects/lab6/src2/ПетроченкоЛаб20_3.txt");
    this->fifth_output->clear();
    this->fifth_input->clear();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        this->fifth_output->append(line);
    }
    this->fifth_input->installEventFilter(this);
    file.close();
}

MainWindow::~MainWindow() {
    delete ui;
}
