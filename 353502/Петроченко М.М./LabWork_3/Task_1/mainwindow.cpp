#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->label = new QLabel;
    this->line_edit = new QLineEdit;
    this->validator = new QDoubleValidator(-100, 100, 12);
    this->line_edit->setValidator(this->validator);
    this->button = new QPushButton("do task");
    this->vbox = new QVBoxLayout;
    this->vbox->addWidget(this->line_edit);
    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->button);
    QObject::connect(this->button, SIGNAL(clicked(bool)), this, SLOT(doTask()));
    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    this->label->setText(Converter::toBin(this->line_edit->text().toDouble()));
}

MainWindow::~MainWindow() {
    delete ui;
}
