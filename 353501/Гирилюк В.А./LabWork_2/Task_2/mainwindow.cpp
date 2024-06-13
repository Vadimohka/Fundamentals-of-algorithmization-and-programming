#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    groupComplete = new GroupComplete();
    incomplete = new IncompleteInTimeDialog();
    search = new SearchDialog();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_file_triggered()
{
    if(File != nullptr && File->open(QIODevice::ReadWrite)){
        QTextStream stream(File);
        for(int i = 0; i < list.size(); ++i){
            stream << list[i].StringForSaveInFile();
        }
        File->close();
        delete File;
    }

    if(!list.empty()){
        list.clear();
    }
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
        ui->tableWidget->removeRow(i);
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), filePath, "Text File (*.txt)");

    ui->filePath->setText(fileName);
    File = new QFile(fileName);
    if(File->open(QIODevice::ReadWrite)){
        QString group, brand;
        bool complete;
        QDate acceptance, execution;

        QTextStream stream(File);
        QString string;
        QTableWidgetItem *item;
        for(int i = 0; !stream.atEnd(); ++i){
            stream >> string;
            ui->tableWidget->insertRow(i);
            if(string.length() != 0){
                string = stream.readLine();
                string.remove(0, 1);
                item = new QTableWidgetItem(string);
                ui->tableWidget->setItem(i, 0, item);
                group = string;
                stream >> string;
                stream >> string;
                item = new QTableWidgetItem(string);
                ui->tableWidget->setItem(i, 1, item);
                brand = string;

                stream >> string;
                stream >> string;
                item = new QTableWidgetItem(string);
                ui->tableWidget->setItem(i, 2, item);
                if(string == "Complete"){
                    complete = true;
                }
                else{
                    complete = false;
                }
                stream >> string;
                stream >> string;
                stream >> string;
                acceptance = QDate::fromString(string, "dd.MM.yyyy");
                item = new QTableWidgetItem(acceptance.toString("dd.MM.yyyy"));
                ui->tableWidget->setItem(i, 3, item);
                stream >> string;
                stream >> string;
                stream >> string;
                stream >> string;
                execution = QDate::fromString(string, "dd.MM.yyyy");
                item = new QTableWidgetItem(execution.toString("dd.MM.yyyy"));
                ui->tableWidget->setItem(i, 4, item);
                list.push_back(Product(group, brand, complete, acceptance, execution));
            }

        }
        File->close();
    }
    while(fileName != nullptr && fileName.at(fileName.length()-1)!='/'){
        fileName.chop(1);
    }
    filePath = fileName;
}
void MainWindow::on_openDialogGroupComplete_clicked()
{
    groupComplete->getList(list);
    groupComplete->show();
}

void MainWindow::on_incompleteInTime_clicked()
{
    incomplete->getList(list);
    incomplete->fillTableWidget();
    incomplete->show();
}


void MainWindow::on_searchDutton_clicked()
{
    search->getList(list);
    search->show();
}


void MainWindow::on_sortPushButton_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        ui->tableWidget->removeRow(i);
    }

    QVector<QVector<Product>> groups;

    if(list.length() > 0){
        QVector<Product> group;
        group.push_back(list.at(0));
        groups.push_back(group);
    }

    for(int i = 1; i < list.length(); i++){
        for(int j = 0; j < groups.length(); j++){
            if(list.at(i).Group() == groups.at(j).at(0).Group()){
                groups[j].push_back(list.at(i));
                break;
            }
            else if(j == groups.length() - 1){
                QVector<Product> group;
                group.push_back(list.at(i));
                groups.push_back(group);
                break;
            }
        }
    }

    for(int i = 0; i < groups.length(); i++){
        QVector<Product> group = groups[i];
        std::sort(groups[i].begin(), groups[i].end(), [](const Product &p1, const Product &p2){
            return p1.Execution() < p2.Execution();
            });
    }

    list.clear();

    for(int i = 0; i < groups.length(); i++){
        for(int j = 0; j < groups[i].length(); j++){
            list.push_back(groups.at(i).at(j));
        }
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        ui->tableWidget->removeRow(i);
    }
    for(int i = 0; i < list.length(); i++){
        QTableWidgetItem *item;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        item = new QTableWidgetItem(list.at(i).Group());
        ui->tableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem(list.at(i).Brand());
        ui->tableWidget->setItem(i, 1, item);
        if(list.at(i).isComplete()){
            item = new QTableWidgetItem("Complete");
        }
        else{
            item = new QTableWidgetItem("Incomplete");
        }
        ui->tableWidget->setItem(i, 2, item);
        item = new QTableWidgetItem(list.at(i).Acceptance().toString("dd.MM.yyyy"));
        ui->tableWidget->setItem(i, 3, item);
        item = new QTableWidgetItem(list.at(i).Execution().toString("dd.MM.yyyy"));
        ui->tableWidget->setItem(i, 4, item);
    }
}


void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(!File->isOpen() && ui->tableWidget->currentRow()!=-1){
        QTableWidgetItem *item = ui->tableWidget->item(row, column);
        QDate acceptance = QDate::fromString("0.0.0", "d.M.y"), execution = QDate::fromString("0.0.0", "d.M.y");
        if(row >= list.length()){
            list.push_back(Product("<None>","<None>", false,acceptance, execution));
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        }

        if(column == 0){
            list[row].setGroup(item->text());
        }
        else if(column == 1){
            list[row].setBrand(item->text());
        }
        else if(column == 2){
            list[row].setIsComplete(item->text() == "Complete");
        }
        else if(column == 3){
            acceptance = QDate::fromString(item->text(), "dd.MM.yyyy");
            if(acceptance.toString() == ""){
                acceptance = QDate::fromString("0.0.0", "d.M.y");
            }
            list[row].setAcceptance(acceptance);
        }
        else if(column == 4){
            execution = QDate::fromString(item->text(), "dd.MM.yyyy");
            if(execution.toString() == ""){
                execution = QDate::fromString("0.0.0", "d.M.y");
            }
            list[row].setExecution(execution);
        }
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QTextStream stream(File);
    if(File->open(QIODevice::ReadWrite)){
        for (int i = 0; i < list.length(); ++i) {
            stream << list.at(i).StringForSaveInFile();
        }
    }
    QMainWindow::closeEvent(event);
}

