#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->resizeColumnToContents(5);

    std::time_t time = std::time(nullptr);
    std::tm *localtime = std::localtime(&time);
    today = new Date();
    QString string;
    string = QString::number(localtime->tm_mday) + ".0" + QString::number(localtime->tm_mon+1) + '.' + QString::number(localtime->tm_year+1900);
    today->QStringToDate(string);
    ui->presentDay->setText(today->DateToQString());

    birthday = new Date();
    ui->birthday->setText("00.00.0000");

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_actionOpen_file_triggered()
{
    if(File != nullptr && File->open(QIODevice::ReadWrite)){
        QTextStream stream(File);
        for(int i =0 ; i< date.size(); ++i){
            stream << date[i].DateToQString() << '\n';
        }
        File->close();
        delete File;
    }

    if(!date.empty()){
        date.clear();
    }
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
        ui->tableWidget->removeRow(i);
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), filePath, "Text File (*.txt)");

    ui->filePath->setText(fileName);
    File = new QFile(fileName);
    if(File->open(QIODevice::ReadWrite)){
        QTextStream stream(File);
        QString string;
        QTableWidgetItem *item;
        for(int i = 0; !stream.atEnd(); ++i){
            string = stream.readLine();
            ui->tableWidget->insertRow(i);
            if(string.length() > 0){
                date.push_back(Date());
                date[i].QStringToDate(string);
                item = new QTableWidgetItem(date[i].DateToQString());
                ui->tableWidget->setItem(i, 0, item);
            }

        }
        File->close();
    }
    while(fileName != nullptr && fileName.at(fileName.length()-1)!='/'){
        fileName.chop(1);
    }
    filePath = fileName;
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    if(!date.isEmpty()){
        fillTableField();
    }
}

void MainWindow::on_birthday_editingFinished()
{
    QString string = ui->birthday->text();
    bufferDate = *birthday;
    birthday->QStringToDate(string);
    if(birthday->year == 0){
        *birthday = bufferDate;
        if(bufferDate.year == 0){
            ui->birthday->setText("00.00.0000");
        }
        else{
            ui->birthday->setText(bufferDate.DateToQString());
        }
    }
    else{
        fillTableField();
    }
}

void MainWindow::lockColumns()
{
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

void MainWindow::fillTableField()
{
    ui->tableWidget->clearContents();
    QTableWidgetItem *item;
    QString string;
    for(int i = 0; i < date.size(); ++i){
        string = date.at(i).DateToQString();
        item = new QTableWidgetItem(string);
        ui->tableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem(date.at(i).NextDay().DateToQString());
        ui->tableWidget->setItem(i, 1, item);
        item = new QTableWidgetItem(date.at(i).PreviousDay().DateToQString());
        ui->tableWidget->setItem(i, 2, item);
        if(date.at(i).IsLeap()){
            item = new QTableWidgetItem("Is leap");
            ui->tableWidget->setItem(i, 3, item);
        }
        else{
            item = new QTableWidgetItem("Isn't leap");
            ui->tableWidget->setItem(i, 3, item);
        }
        item = new QTableWidgetItem(QString::number(date.at(i).WeekNumber()));
        ui->tableWidget->setItem(i, 4, item);
        if(birthday->year != 0){
            item = new QTableWidgetItem(QString::number(date.at(i).DaysTillYourBirthday(*birthday)));
            ui->tableWidget->setItem(i, 5, item);
        }
        item = new QTableWidgetItem(QString::number(date.at(i).Durration(*today)));
        ui->tableWidget->setItem(i, 6, item);
    }
    lockColumns();
}


void MainWindow::on_isLeapButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && selectedDate.year != 0){
        if(selectedDate.IsLeap()){
            ui->isLeap->setText("Is leap");
        }
        else{
            ui->isLeap->setText("Isn't leap");
        }
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
}


void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if(ui->tableWidget->currentColumn() == 0 && ui->tableWidget->currentRow() < date.length()){
        selectedDate = date.at(ui->tableWidget->currentRow());
        ui->groupBox_2->setTitle("Info for: " + date.at(ui->tableWidget->currentRow()).DateToQString());
        ui->nextDay->setText("");
        ui->previousDay->setText("");
        ui->isLeap->setText("");
        ui->weekNumber->setText("");
        ui->tillBirthday->setText("");
        ui->Duration->setText("");
    }
}


void MainWindow::on_nextDayButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && selectedDate.year != 0){
        ui->nextDay->setText(selectedDate.NextDay().DateToQString());
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
}


void MainWindow::on_previousDayButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && selectedDate.year != 0){
        ui->previousDay->setText(selectedDate.PreviousDay().DateToQString());
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
}


void MainWindow::on_weekNumberButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && selectedDate.year != 0){
        ui->weekNumber->setText(QString::number(selectedDate.WeekNumber()));
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
}

void MainWindow::on_tillBirthdayButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && birthday->year != 0 && selectedDate.year != 0){
        ui->tillBirthday->setText(QString::number(selectedDate.DaysTillYourBirthday(*birthday)));
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
    else if(birthday->year == 0 && selectedDate.year != 0){
        QMessageBox::information(nullptr, "Birthday", "\nPlease, input your birthday");
    }
}


void MainWindow::on_durationButton_clicked()
{
    if(ui->tableWidget->currentRow()!=-1 && selectedDate.year != 0){
        ui->Duration->setText(QString::number(selectedDate.Durration(*today)));
    }
    else if(selectedDate.year == 0){
        QMessageBox::information(nullptr, "Date", "\nPlease, selecte date");
    }
}
void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(!File->isOpen() && ui->tableWidget->currentRow()!=-1 && ui->tableWidget->item(row, column)->text() != ""){
        QTableWidgetItem *item = ui->tableWidget->item(row , 0);
        if(row < ui->tableWidget->rowCount()-1){
            bufferDate = date[row];
            date[row].QStringToDate(item->text());
            if(date[row].year == 0){
                date[row] = bufferDate;
            }
            item->setText(date[row].DateToQString());
        }
        else{
            date.push_back(Date());
            date[row].QStringToDate(item->text());
            ui->tableWidget->insertRow(row+1);
            if(date[row].year == 0){
                item->setText("");
                date.removeLast();
                ui->tableWidget->removeRow(row+1);
            }
        }
        ui->tableWidget->setItem(row, 0, item);
        fillTableField();
        if(File != nullptr && File->open(QIODevice::ReadWrite) && date.size() < row){
            QTextStream stream(File);
            stream.seek(11*row);
            stream << date[row].DateToQString() << '\n';
            File->close();
        }
    }
}

bool MainWindow::event(QEvent *e)
{
    if(e->type() == QEvent::WindowActivate) {
        if(!date.empty()){
            date.clear();
        }
        for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i){
            ui->tableWidget->removeRow(i);
        }

        QString fileName = ui->filePath->text();

        ui->filePath->setText(fileName);
        File = new QFile(fileName);
        if(File->open(QIODevice::ReadWrite)){
            QTextStream stream(File);
            QString string;
            QTableWidgetItem *item;
            for(int i = 0; !stream.atEnd(); ++i){
                string = stream.readLine();
                ui->tableWidget->insertRow(i);
                if(string.length() > 0){
                    date.push_back(Date());
                    date[i].QStringToDate(string);
                    item = new QTableWidgetItem(date[i].DateToQString());
                    ui->tableWidget->setItem(i, 0, item);
                }

            }
            File->close();
        }
        while(fileName != nullptr && fileName.at(fileName.length()-1)!='/'){
            fileName.chop(1);
        }
        filePath = fileName;
        if(!date.isEmpty()){
            fillTableField();
        }
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }
    return QWidget::event(e);
}
