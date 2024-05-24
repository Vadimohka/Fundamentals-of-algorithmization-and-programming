#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setLayout(ui->gridLayout);

    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);


    setWindowTitle("Подсчёт числа папок и файлов");
    ui->label_sf->setText("Папка не выбрана!");

    model = new FolderOnlyModel(this);

    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    selectedDirectory = QFileDialog::getExistingDirectory(nullptr, "Select a Directory", QDir::homePath(), QFileDialog::ShowDirsOnly);


    ui->label_sf->setText("Идёт вычисление...");
    if (!selectedDirectory.isEmpty())
    {
        ui->label_sf->setText("Processing...");
        ui->label_files->setText("Processing...");
        QCoreApplication::processEvents();

        model->setRootPath(selectedDirectory);
        ui->treeView->setModel(model);
        ui->treeView->setRootIndex(model->index(selectedDirectory));
        ui->treeView->setHeaderHidden(true);
        ui->treeView->setColumnWidth(0, 400);
        QThread* thread = new QThread(this);
        QObject::connect(thread, &QThread::started, [&]{
            files = 0;
            dirs = 0;
            counter.Count(selectedDirectory, files, dirs);
            ui->label_sf->setText(QString::number(dirs) + " Подпапок");
            ui->label_files->setText(QString::number(files) + " Файлов");
        });
        thread->start();
    } else
    {
        qDebug() << "Отменено пользователем";
    }
}
