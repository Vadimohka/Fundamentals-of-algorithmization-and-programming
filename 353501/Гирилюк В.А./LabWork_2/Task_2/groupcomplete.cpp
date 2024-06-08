#include "groupcomplete.h"
#include "ui_groupcomplete.h"

GroupComplete::GroupComplete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupComplete)
{
    ui->setupUi(this);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

GroupComplete::~GroupComplete()
{
    delete ui;
}

void GroupComplete::getList(QVector<Product> &gettingList)
{
    dialogList = gettingList;
}

void GroupComplete::on_lineEdit_editingFinished()
{
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
        ui->tableWidget->removeRow(i);
    }

    aimGroup = ui->lineEdit->text();
    QTableWidgetItem *item;
    for(int i = 0; i < dialogList.length(); i++){
        if(!aimGroup.compare(dialogList.at(i).Group(), Qt::CaseInsensitive)){
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
