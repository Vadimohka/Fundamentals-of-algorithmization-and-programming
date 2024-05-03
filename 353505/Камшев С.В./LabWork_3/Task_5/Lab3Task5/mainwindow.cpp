#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button->setParent(this);
    button->setText("Выбрать папку");
    button->setGeometry(400, 960, 200, 30);

    numberOfFilesLabel->setParent(this);
    numberOfFilesLabel->setGeometry(0,30,500,30);

    numberOfFoldersLabel->setParent(this);
    numberOfFoldersLabel->setGeometry(0,80,500,30);

    treeWidget->setParent(this);
    treeWidget->setGeometry(0, 120, 1000, 800);

    QPushButton::connect(button, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::func(QString str, int &quantityOfFolders, QTreeWidgetItem* item)
{
    QDir dir;
    dir.setPath(str);
    QFileInfoList d = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotDot);

    int qtyFiles = 0;
    for(int i = 0; i < d.count(); i++) {
        QFileInfo info = d[i];
        if ( info.isFile() ) {
            qtyFiles++;
            QTreeWidgetItem* child = new QTreeWidgetItem;
            child->setText(0, info.fileName());
            item->addChild(child);
        } else if ( info.isDir() ) {
            QTreeWidgetItem* child = new QTreeWidgetItem;
            child->setText(0, info.fileName());
            item->addChild(child);
            qtyFiles += func(info.path() + '/' + info.fileName(), quantityOfFolders, child);
            quantityOfFolders += 1;
        }
    }
    return qtyFiles;
}



void MainWindow::on_button_clicked()
{

    QString str = "";
    str = QFileDialog::getExistingDirectory(this, "Выберите файл", "/home/stepan");
    if (str != ""){
        treeWidget->clear();
        treeWidget->setColumnCount(1);
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setText(0,str);
        treeWidget->addTopLevelItem(item);

        numberOfFilesLabel->setText("Количество файлов: " + QString::number(func(str, quantityOfFolders, item)));
        numberOfFoldersLabel->setText("Количество папок: " + QString::number(quantityOfFolders));
    }


}
