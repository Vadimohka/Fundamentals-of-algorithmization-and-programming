
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->vbox = new QVBoxLayout;

    this->validator = new QIntValidator(0, 10);

    this->line_edit = new QLineEdit;
    this->line_edit->setValidator(this->validator);

    this->text_edit = new QTextEdit;
    this->text_edit->setReadOnly(true);

    this->button = new QPushButton("do task");
    QObject::connect(this->button, SIGNAL(clicked()), this, SLOT(doTask()));

    this->vbox->addWidget(this->text_edit);
    this->vbox->addWidget(this->line_edit);
    this->vbox->addWidget(this->button);

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    QString log;
    QString layers = this->line_edit->text();
    int pos = 0;
    if (this->validator->validate(layers, pos) == QValidator::Acceptable) {
        hanoi(layers.toUInt(), 1, 3, 2, log);
        this->text_edit->setText(log);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
