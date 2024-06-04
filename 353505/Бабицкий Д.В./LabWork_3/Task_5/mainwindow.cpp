#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаем экземпляр модели
    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count(const QString dir, unsigned long long & fileCount, unsigned long long & dirCount, QStandardItem * parent) {
    QDir path(dir), path1(dir);
    QStringList fNames;
    path.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    QStandardItem * child;
    for (const QFileInfo& i : path.entryInfoList()) {
        if (i.isSymLink()) continue;
        fNames.append(i.fileName());
        ++dirCount;
    }
    path.setFilter(QDir::Files);
    for (const QFileInfo& i : path.entryInfoList()) {
        child = new QStandardItem(i.fileName());
        parent->appendRow(child);
    }
    fileCount += path.entryList().count();

    for (auto i : fNames){
        child = new QStandardItem(i);
        parent->appendRow(child);
        count(dir + '/' + i, fileCount, dirCount, child);
    }
}

void MainWindow::on_pushButton_clicked()
{
    directoryPath = QFileDialog::getExistingDirectory(nullptr, "Выберите директорию", QDir::homePath(), QFileDialog::ShowDirsOnly);

    ui->label_sf->setText("Processing...");
    ui->label_files->setText("Processing...");
    QCoreApplication::processEvents();
    if (!directoryPath.isEmpty()){

        QThread* thread = new QThread(this);
        QObject::connect(thread, &QThread::started, [&]{
            model->clear();
            unsigned long long d = 0, f = 0;
            QStandardItem *rootItem = model->invisibleRootItem();
            count(directoryPath, f, d, rootItem);
            ui->label_sf->setText(QString::number(d) + " SubFolders");
            ui->label_files->setText(QString::number(f) + " Files");
        });
        thread->start();
    }
}
