#include "incompleteintimedialog.h"
#include "ui_incompleteintimedialog.h"

IncompleteInTimeDialog::IncompleteInTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncompleteInTimeDialog)
{
    ui->setupUi(this);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

IncompleteInTimeDialog::~IncompleteInTimeDialog()
{
    delete ui;
}

void IncompleteInTimeDialog::getList(QVector<Product> &gettingList)
{
    dialogList = gettingList;
}

void IncompleteInTimeDialog::fillTableWidget()
{
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
        ui->tableWidget->removeRow(i);
    }

    QTableWidgetItem *item;
    for(int i = 0; i < dialogList.length(); i++){
        if(!dialogList.at(i).isComplete() && dialogList.at(i).Execution() < QDate::currentDate()){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            item = new QTableWidgetItem(dialogList.at(i).Group());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
            item = new QTableWidgetItem(dialogList.at(i).Brand());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
            if(dialogList.at(i).isComplete()){
                item = new QTableWidgetItem("Complete");
            }
            else{
                item = new QTableWidgetItem("Incomplete");
            }
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, item);
            item = new QTableWidgetItem(dialogList.at(i).Acceptance().toString("dd.MM.yyyy"));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, item);
            item = new QTableWidgetItem(dialogList.at(i).Execution().toString("dd.MM.yyyy"));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, item);
        }
    }
    for(int i = 0; i < ui->tableWidget->columnCount(); ++i){
        for(int j = 0; j < ui->tableWidget->rowCount(); ++j){
            QTableWidgetItem *item = ui->tableWidget->item(j, i);
            if(item){
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                ui->tableWidget->setItem(j, i, item);
            }
        }
    }
}
