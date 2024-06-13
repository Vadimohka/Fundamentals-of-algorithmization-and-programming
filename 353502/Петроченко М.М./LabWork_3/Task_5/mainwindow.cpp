
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->vbox = new QVBoxLayout;

    this->label = new QLabel;

    this->button = new QPushButton("do task");
    QObject::connect(this->button, SIGNAL(clicked()), this, SLOT(doTask()));

    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->button);

    this->future_watcher = new QFutureWatcher<Res>;
    QObject::connect(this->future_watcher, SIGNAL(finished()), this,
                     SLOT(final()));

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    this->label->setText("counting...");
    this->button->setEnabled(false);

    this->future_watcher->setFuture(
        QtConcurrent::run([dir]() -> Res { return count(dir); }));
}

void MainWindow::final() {
    Res files_and_folders = this->future_watcher->result();
    QString result = QString("Files: %1\nDirectories: %2\nErrors: %3")
                         .arg(files_and_folders.files)
                         .arg(files_and_folders.folders)
                         .arg(files_and_folders.errors);
    this->label->setText(result);
    this->button->setEnabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
}
