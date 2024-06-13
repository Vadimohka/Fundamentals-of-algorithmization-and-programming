#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(1800,1000);
    ui->setupUi(this);
    table = ui->tableWidget;
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date" << "NextDay" << "PreviousDay" << "Days till today" << "Days till birthday" << "Till next date");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    QString s;
    QString fl = QFileDialog::getOpenFileName(parent,"","/home/lq-84i/QTProjects/l2/Task_1/resources/");
    readWriteFile.setFileName(fl);
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);

    while(!stream.atEnd()){
        s=stream.readLine();
        MyDate date(s);
        vector.append(date);
    }
    readWriteFile.close();
    update();
}

void Widget::update(){
    std::sort(vector.begin(), vector.end());
    MyDate current = MyDate::current();
    MyDate birthday(ui->dateEdit->date().day(), ui->dateEdit->date().month(), ui->dateEdit->date().year());
    table->setRowCount(vector.count());
    for(int i = 0; i < vector.size(); ++i){
        MyDate myDate = vector.at(i);
        table->setItem(i, 0, new QTableWidgetItem(myDate.toString()));
        table->setItem(i, 1, new QTableWidgetItem(myDate.nextDay().toString()));
        table->setItem(i, 2, new QTableWidgetItem(myDate.PreviousDay().toString()));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(myDate.daysBetween(current))));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(myDate.daysTillBirthday(birthday))));
        if(i!=vector.size()-1){
            table->setItem(i, 5, new QTableWidgetItem(QString::number(myDate.daysBetween(vector.at(i+1)))));
        }
    }
}

QString Widget::dialog(QString label)
{
    Dialog dialog;
    dialog.setLabel(label);
    dialog.setModal(true);
    if(!dialog.exec()){
        return "";
    }
    return dialog.getLine();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked()
{
    QString dateString = dialog("Введите дату");
    MyDate date(dateString);
    if (!date.isValid()){
        QMessageBox::critical(parentWidget(), "", "Invalid");
        return;
    }
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);
    stream.readAll();
    stream << date.toString() << "\n";
    stream.flush();
    readWriteFile.close();
    vector.append(date);
    update();
}


void Widget::on_editButton_clicked()
{
    QItemSelectionModel *select = table->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::critical(parentWidget(), "", "No selection");
        return;
    }
    QString dateString = dialog("Введите дату");
    MyDate date(dateString);
    if (!date.isValid()){
        QMessageBox::critical(parentWidget(), "", "Invalid");
        return;
    }
    vector.replace(select->selectedRows().first().row(), date);
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);
    QString content = stream.readAll();
    int startPos = content.indexOf(select->selectedRows().first().data().toString());
    stream.seek(startPos);
    stream << date.toString() << "\n";
    stream.flush();
    readWriteFile.close();
    update();
}


void Widget::on_deleteButton_clicked()
{
    QItemSelectionModel *select = table->selectionModel();
    if(!select->hasSelection()){
        QMessageBox::critical(parentWidget(), "", "No selection");
        return;
    }
    QString toDelete = select->selectedRows().first().data().toString();
    vector.remove(select->selectedRows().first().row());
    readWriteFile.open(QIODevice::ReadWrite);
    QTextStream stream(&readWriteFile);
    QString newContent = stream.readAll();
    int startPos = newContent.indexOf(toDelete);
    int endPos = newContent.indexOf('\n', startPos);
    newContent.remove(startPos, endPos - startPos + 1);
    readWriteFile.resize(0);
    stream.seek(0);
    stream << newContent << "\n";
    stream.flush();
    readWriteFile.close();
    update();
}


void Widget::on_pushButton_clicked()
{
    update();
}

