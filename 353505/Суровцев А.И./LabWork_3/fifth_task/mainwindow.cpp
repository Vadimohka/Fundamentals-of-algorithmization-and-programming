#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(720, 450);
    setFixedSize(720,450);
    model = new FolderOnlyModel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr, "Выберите директорию", QDir::homePath());
    if (directoryPath.isEmpty()) {
        ui->info_label->setText("Походу вы выбрали неправильную директорию!!!");
    }
    else {
        cnt_of_dir = 0;
        cnt_of_files = 0;
        QCoreApplication::processEvents();

        // Создаем новую модель
        model->setRootPath(directoryPath);

        // Устанавливаем новую модель для QTreeView
        ui->treeView->setModel(model);
        ui->treeView->setRootIndex(model->index(directoryPath));
        ui->treeView->setHeaderHidden(true);
        //QThread *thread = new QThread(this);
        //QObject::connect(thread, &QThread::started, [&]() {
            counter.count_up(directoryPath, cnt_of_dir, cnt_of_files);
            QFont font = ui->info_label->font();
            font.setPointSize(font.pointSize() - 2);
            ui->info_label->setFont(font);
            ui->info_label->setText("<html><body>"
                                    "<h1>Путь: </h1>" + directoryPath +
                                    "<p>Число папок: </p>" + QString::number(cnt_of_dir) +
                                    "<p>Число файлов: </p>" + QString::number(cnt_of_files) +
                                    "</body></html>");
        //});
        //thread->start();
    }
}

