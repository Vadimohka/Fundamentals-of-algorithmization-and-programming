#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <good.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update(){
    ui->listWidget->clear();
    foreach (Good good, goodsToShow) {
        ui->listWidget->addItem(new QListWidgetItem(ui->checkBox->isChecked() ? (good.toFullInfoString()) : (good.toString())));
    }
}

Good Widget::dialog()
{
    Dialog d;
    if(!d.exec()){
        return Good();
    }
    return d.getGood();
}

void Widget::on_addPushButton_clicked()
{
    Good g = dialog();
    if (g.getGroup() == Good::NONE){
        QMessageBox::critical(parentWidget(), "", "Invalid");
        return;
    }
    goods.append(g);
    goodsToShow = goods;
    update();
}


void Widget::on_updatePushButton_clicked()
{
    QItemSelectionModel *select = ui->listWidget->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::critical(parentWidget(), "", "No selection");
        return;
    }
    Good good = dialog();
    if (good.getGroup() == Good::NONE){
        QMessageBox::critical(parentWidget(), "", "Invalid");
        return;
    }
    goods.replace(select->selectedRows().first().row(), good);
    goodsToShow = goods;
    update();
}


void Widget::on_deletePushButton_clicked()
{
    QItemSelectionModel *select = ui->listWidget->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::critical(parentWidget(), "", "No selection");
        return;
    }
    goods.remove(select->selectedRows().first().row());
    goodsToShow = goods;
    update();
}


void Widget::on_checkBox_stateChanged(int arg1)
{
    update();
}


void Widget::on_writePushButton_clicked()
{
    QString fl = QFileDialog::getOpenFileName(parentWidget(),"","/home/lq-84i/QTProjects/l2/Task_2/resources/");
    QFile readWriteFile(fl);
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);

    foreach (Good good, goods) {
        stream << good.toFullInfoString() << "\n";
    }

    stream.flush();
    readWriteFile.close();
}


void Widget::on_readPushButton_clicked()
{
    goods.clear();

    QString s;
    QString fl = QFileDialog::getOpenFileName(parentWidget(),"","/home/lq-84i/QTProjects/l2/Task_2/resources/");
    QFile readWriteFile(fl);
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);

    while(!stream.atEnd()){
        s=stream.readLine();
        Good g = Good::fromString(s);
        goods.append(g);
    }

    stream.flush();
    readWriteFile.close();
    goodsToShow = goods;
    update();
}


void Widget::on_pushButton_3_clicked()
{
    goodsToShow = goods;
    update();
}


void Widget::on_sortPushButton_clicked()
{
    goodsToShow = goods;
    bool isSorted = false;
    while(!isSorted){
        isSorted = true;
        for (int var = 0; var < goodsToShow.size()-1; ++var) {
            if (goodsToShow[var].getGroup() > goodsToShow[var+1].getGroup()){
                std::swap(goodsToShow[var], goodsToShow[var+1]);
                isSorted = false;
            }
            else{
                if (ui->comboBox->currentIndex() == 0){
                    if (goodsToShow[var].getCode() > goodsToShow[var+1].getCode()){
                        std::swap(goodsToShow[var], goodsToShow[var+1]);
                        isSorted = false;
                    }
                } else if (ui->comboBox->currentIndex() == 1){
                        if (goodsToShow[var].getName() > goodsToShow[var+1].getName()){
                            std::swap(goodsToShow[var], goodsToShow[var+1]);
                            isSorted = false;
                        }
                }  else{
                            if (goodsToShow[var].getPrice() > goodsToShow[var+1].getPrice()){
                                std::swap(goodsToShow[var], goodsToShow[var+1]);
                                isSorted = false;
                            }
                }
            }
        }
    }
    update();
}


void Widget::on_pushButton_clicked()
{
    goodsToShow = goods;
    qint64 count = ui->lessThanLineEdit->text().toLongLong();
    for (int var = 0; var < goodsToShow.size(); ++var) {
        if(goodsToShow[var].getCount() < count){
            goodsToShow.remove(var);
            --var;
        }
    }
    update();
}


void Widget::on_pushButton_2_clicked()
{
    goodsToShow = goods;
    QString name = ui->searchLineEdit->text();
    for (int var = 0; var < goodsToShow.size(); ++var) {
        if(goodsToShow[var].getName().indexOf(name) == -1){
            goodsToShow.remove(var);
            --var;
        }
    }
    update();
}

