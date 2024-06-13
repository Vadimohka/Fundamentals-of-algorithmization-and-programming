
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->vbox = new QVBoxLayout;

    this->validator = new QIntValidator(0, 1000);

    this->line_edit = new QLineEdit;
    this->line_edit->setValidator(this->validator);

    this->label = new QLabel;

    this->button = new QPushButton("do task");
    QObject::connect(this->button, SIGNAL(clicked()), this, SLOT(doTask()));

    this->vbox->addWidget(this->line_edit);
    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->button);

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    uint64_t num = this->line_edit->text().toULongLong();
    uint64_t rev = reverse(num);
    QString res = QString::number(rev);
    this->label->setText(res);
}

MainWindow::~MainWindow() {
    delete ui;
}
