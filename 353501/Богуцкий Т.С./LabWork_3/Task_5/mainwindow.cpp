#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add(const QString& directory, QTreeWidgetItem* parentItem) {
    QDir dir(directory);
    if (!dir.exists() || !dir.isReadable()) {
        return;
    }
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    foreach (const QFileInfo& fileInfo, files) {
        QString fileName = fileInfo.fileName();
        QTreeWidgetItem* item = new QTreeWidgetItem(parentItem, QStringList(fileName));

        if (fileInfo.isDir()) {
            add(fileInfo.filePath(), item);
        }
    }
}

void MainWindow::on_Open_clicked()
{
    QString str = QFileDialog::getExistingDirectory(0, "Выбор папки", "");
    model = new FileModel(this);
    model->setRootPath(str);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(str));
    ui->treeView->setHeaderHidden(true);
    Counter::count(str);
    ui->labelDirCount->setText(QString::number(Counter::getD()));
    ui->labelFilesCount->setText(QString::number(Counter::getF()));
    Counter::toZero();
}
