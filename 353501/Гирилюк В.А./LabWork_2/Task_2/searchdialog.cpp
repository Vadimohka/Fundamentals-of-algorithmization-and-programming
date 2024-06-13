#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    ui->unknownRadioButton->setChecked(true);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::getList(QVector<Product> &gettingList)
{
    dialogList = gettingList;
}

void SearchDialog::search()
{
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
        ui->tableWidget->removeRow(i);
    }

    for(int i = 0; i < dialogList.length(); i++){
        if(!ui->searchGroup->text().compare(dialogList.at(i).Group(), Qt::CaseInsensitive)){
            if(!ui->searchBrandEditLine->text().compare(dialogList.at(i).Brand(), Qt::CaseInsensitive)){
                if(dialogList.at(i).Acceptance() == QDate::fromString(ui->acceptanceDateEditLine->text(), "dd.MM.yyyy")){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else if(ui->executionDateEditLIne->text() == ""){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
                else if(ui->acceptanceDateEditLine->text() == ""){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
            }
            else if(ui->searchBrandEditLine->text() == ""){
                if(dialogList.at(i).Acceptance() == QDate::fromString(ui->acceptanceDateEditLine->text(), "dd.MM.yyyy")){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
                else{
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
            }
        }
        else if(ui->searchGroup->text() == ""){
            if(!ui->searchBrandEditLine->text().compare(dialogList.at(i).Brand(), Qt::CaseInsensitive)){
                if(dialogList.at(i).Acceptance() == QDate::fromString(ui->acceptanceDateEditLine->text(), "dd.MM.yyyy")){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else if(ui->executionDateEditLIne->text() == ""){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
                else if(ui->acceptanceDateEditLine->text() == ""){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
            }
            else if(ui->searchBrandEditLine->text() == ""){
                if(dialogList.at(i).Acceptance() == QDate::fromString(ui->acceptanceDateEditLine->text(), "dd.MM.yyyy")){
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
                else{
                    if(dialogList.at(i).Execution() == QDate::fromString(ui->executionDateEditLIne->text(), "dd.MM.yyyy")){
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                    else{
                        if(unknown){
                            setProductRow(ui->tableWidget->rowCount(), i);
                        }
                        else{
                            if(dialogList.at(i).isComplete() == complete){
                                setProductRow(ui->tableWidget->rowCount(), i);
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i < ui->tableWidget->columnCount(); ++i){
        for(int j = 0; j < ui->tableWidget->rowCount(); ++j){
            QTableWidgetItem *item = ui->tableWidget->item(j, i);
            if(item){
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                ui->tableWidget->setItem(j, i, item);
            }
        }
    }
}

void SearchDialog::on_completeRadioButton_clicked()
{
    complete = true;
    unknown = false;
    search();
}


void SearchDialog::on_incompleteRadioButton_clicked()
{
    complete = false;
    unknown = false;
    search();
}


void SearchDialog::on_searchGroup_editingFinished()
{
    search();
}


void SearchDialog::on_searchBrandEditLine_editingFinished()
{
    search();
}


void SearchDialog::on_acceptanceDateEditLine_editingFinished()
{
    search();
}


void SearchDialog::on_executionDateEditLIne_editingFinished()
{
    search();
}


void SearchDialog::on_unknownRadioButton_clicked()
{
    unknown = true;
    search();
}

void SearchDialog::setProductRow(int row, int index)
{
    QTableWidgetItem *item;
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    item = new QTableWidgetItem(dialogList.at(index).Group());
    ui->tableWidget->setItem(row, 0, item);
    item = new QTableWidgetItem(dialogList.at(index).Brand());
    ui->tableWidget->setItem(row, 1, item);
    if(dialogList.at(index).isComplete()){
        item = new QTableWidgetItem("Complete");
    }
    else{
        item = new QTableWidgetItem("Incomplete");
    }
    ui->tableWidget->setItem(row, 2, item);
    item = new QTableWidgetItem(dialogList.at(index).Acceptance().toString("dd.MM.yyyy"));
    ui->tableWidget->setItem(row, 3, item);
    item = new QTableWidgetItem(dialogList.at(index).Execution().toString("dd.MM.yyyy"));
    ui->tableWidget->setItem(row, 4, item);
}

