#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    current_path = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QDir::homePath());
    ui -> Current_path_label -> setText(current_path);

    count_of_files = 0;
    count_of_folders = 0;


    Calculate_number_of_folders_and_files(current_path);

    QTreeWidgetItem* item = new QTreeWidgetItem(ui -> treeWidget);

    setTree(current_path, item);

    ui -> File_count_line -> setText(QString::number(count_of_files));
    ui -> Folder_count_line -> setText(QString::number(count_of_folders));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Change_path_button_clicked()
{
    current_path = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QDir::homePath());

    count_of_files = 0;
    count_of_folders = 0;

    QTreeWidgetItem* item = new QTreeWidgetItem(ui -> treeWidget);

    setTree(current_path, item);

    Calculate_number_of_folders_and_files(current_path);

    ui -> Current_path_label -> setText(current_path);
    ui -> File_count_line -> setText(QString::number(count_of_files));
    ui -> Folder_count_line -> setText(QString::number(count_of_folders));

}

void MainWindow::Calculate_number_of_folders_and_files(QString path){
    QDir dir(path);

    if(dir.exists()){
        length_of_array = list_copy_dir.length();

        list_copy_dir = dir.entryInfoList(QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot);

        QFileInfoList list_of_files = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot);
        count_of_files += list_of_files.length();


        for(int i = 0; i < list_copy_dir.length(); ++i){
            vector_of_all_count_of_dirs.append(list_copy_dir[i]);
        }

        count_of_folders += list_copy_dir.length();

        if(vector_of_all_count_of_dirs.length() != 0){

            QFileInfo temp = vector_of_all_count_of_dirs[0];

            vector_of_all_count_of_dirs.remove(0,1);

            Calculate_number_of_folders_and_files(temp.absoluteFilePath());
        }
        else{
            return;
        }
    }
}

QPair<long, long> MainWindow::setTree(const QString &folderPath, QTreeWidgetItem *parentItem) {
    QDir folder(folderPath);
    QFileInfoList entries = folder.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);

    int folderCount = 0;
    int fileCount = 0;

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            QTreeWidgetItem *subfolderItem = new QTreeWidgetItem(parentItem);
            subfolderItem->setText(0, entry.fileName());

            QPair<long, long> childCount = setTree(entry.filePath(), subfolderItem);
            folderCount += (1 + childCount.first);
            fileCount += childCount.second;
            parentItem->setText(2, QString::number(fileCount));


        } else if (entry.isFile()) {
            QTreeWidgetItem *fileItem = new QTreeWidgetItem(parentItem);
            fileItem->setText(0, entry.fileName());

            ++fileCount;
        }
    }

    QPair<long, long> ret {folderCount, fileCount};
    return ret;
}
