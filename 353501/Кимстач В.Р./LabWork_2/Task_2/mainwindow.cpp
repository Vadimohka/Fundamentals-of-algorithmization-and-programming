#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChar>
#include <QInputDialog>

    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMaximum(10.00);
    ui->spinBox->setMaximum(100);
    ui->spinBox_2->setMaximum(100);
    ui->spinBox_3->setMaximum(100);
    ui -> table -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    ui->table->setSortingEnabled(false);
    int row;
    QString input = ui->lineEdit->text().trimmed();
    QString input2 = ui->lineEdit_2->text().trimmed();
    QString input3 = ui->lineEdit_3->text().trimmed();
    bool russian = true;
    for (int i =0; i< input.length();i++){
        if (input[i].script() != QChar::Script_Cyrillic) {
            russian = false;
        }
    }
    for (int i =0; i< input2.length();i++){
        if (input2[i].script() != QChar::Script_Cyrillic) {
            russian=false;
        }
    }
    for (int i =0; i< input3.length();i++){
        if (input3[i].script() != QChar::Script_Cyrillic) {
            russian=false;
        }
    }
    if (russian&&!input.isEmpty() && input.at(0).isUpper() && !input.contains(" ")&&!input2.isEmpty() && input2.at(0).isUpper() && !input2.contains(" ")&&!input3.isEmpty() && input3.at(0).isUpper() && !input3.contains(" ")||input.length()>=3||input2.length()>=3||input3.length()>=3) {

    } else {
        QMessageBox::warning(this, "Ошибка", "Введено некорректное ФИО!");
        return;
    }
    row = ui->table->rowCount();
    ui->table->insertRow(row);
    QTableWidgetItem *itm = new QTableWidgetItem(input +" "+ input2 +" "+ input3);
    ui->table->setItem(row,0,itm);
    vedomosti[row].setName(input);
    vedomosti[row].setSurname(input2);
    vedomosti[row].setFathername(input3);

    QTableWidgetItem *itm1 = new QTableWidgetItem(ui->comboBox->currentText());
    ui->table->setItem(row,1,itm1);
    vedomosti[row].setSpeciality(ui->comboBox->currentText());

    QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(ui->doubleSpinBox->value()));
    ui->table->setItem(row,2,itm2);
    vedomosti[row].setAttestat(ui->doubleSpinBox->value());

    QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(ui->spinBox->value()));
    ui->table->setItem(row,3,itm3);
    vedomosti[row].setMath(ui->spinBox->value());

    QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(ui->spinBox_2->value()));
    ui->table->setItem(row,4,itm4);
    vedomosti[row].setFiz(ui->spinBox_2->value());

    QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(ui->spinBox_3->value()));
    ui->table->setItem(row,5,itm5);
    vedomosti[row].setRus(ui->spinBox_3->value());

    QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(10*ui->doubleSpinBox->value()+ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()));
    ui->table->setItem(row,6,itm6);
    ui->table->setSortingEnabled(true);
}


void MainWindow::on_pushButton_add_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (!CheckFile(line))
        {
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }

        int row = ui->table->rowCount();
        ui->table->insertRow(row);

        line=line.trimmed();
        QStringList words = line.split(' ');

        QString spec;
        switch (words[3].toInt()) {
        case 0:
            spec="ИиТП";
            break;
        case 1:
            spec="КИ";
            break;
        case 2:
            spec="ПИ";
            break;
        case 3:
            spec="ПОИТ";
            break;
        }

        vedomosti[row].setName(words[1]);
        vedomosti[row].setSurname(words[0]);
        vedomosti[row].setFathername(words[2]);
        vedomosti[row].setSpeciality(spec);
        vedomosti[row].setAttestat(words[4].toDouble());
        vedomosti[row].setMath(words[5].toInt());
        vedomosti[row].setFiz(words[6].toInt());
        vedomosti[row].setRus(words[7].toInt());

        QTableWidgetItem *itm = new QTableWidgetItem(vedomosti[row].getSurname() +" "+ vedomosti[row].getName() +" "+ vedomosti[row].getFathername());
        ui->table->setItem(row, 0, itm);

        QTableWidgetItem *itm1 = new QTableWidgetItem(vedomosti[row].getSpeciality());
        ui->table->setItem(row, 1, itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(vedomosti[row].getAttestat()));
        ui->table->setItem(row, 2, itm2);

        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(vedomosti[row].getMath()));
        ui->table->setItem(row, 3, itm3);

        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(vedomosti[row].getFiz()));
        ui->table->setItem(row, 4, itm4);

        QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(vedomosti[row].getRus()));
        ui->table->setItem(row, 5, itm5);

        QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(vedomosti[row].SummaBallov()));
        ui->table->setItem(row, 6, itm6);



        ui->table->update();

    }

    file.close();

}

bool MainWindow::CheckFile(QString line){
    line=line.trimmed();
    QStringList words = line.split(' ');
    if(words.size() != 8) {
        return false;
    }

    for(int i = 0; i < 3; i++) {
        for(QChar c : words[i]) {
            if(c.script() != QChar::Script_Cyrillic) {
                return false;
            }
        }
    }

    if (words[3]!='0'&&words[3]!='1'&&words[3]!='2'&&words[3]!='3'){
        return false;
    }

    bool ok;
    double negr = words[4].toDouble(&ok);
    if(!ok&&(negr<0||negr>10)) {
        return false;
    }

    for(int i = 5; i < 8; i++) {
        bool ok1;
        int pidoras = words[i].toInt(&ok1);
        if(!ok1&&(pidoras<0||pidoras>100)) {
            return false;
        }
    }

    return true;
}


void MainWindow::on_pushButton_save_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Сохранение"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QStringList existingVedomost;

    int kolvo=0;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        existingVedomost.append(line);
        kolvo++;
    }

    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    int row = ui->table->rowCount();

    bool уже_Есть=false;
    for (int i = 0;i< row;i++)
    {
        int spec=0;
        if(ui->table->item(i,1)->text()=="ИиТП"){
            spec=0;
        } else if(ui->table->item(i,1)->text()=="КИ"){
            spec=1;
        } else if(ui->table->item(i,1)->text()=="ПИ"){
            spec=2;
        } else if(ui->table->item(i,1)->text()=="ПОИТ"){
            spec=3;
        }
        QString ФИО =ui->table->item(i,0)->text();
        QString спец = QString::number(spec);
        QString оценки =  ui->table->item(i,2)->text()+ " " + ui->table->item(i,3)->text() + " " + ui->table->item(i,4)->text() + " " + ui->table->item(i,5)->text();
        QString vedomost = ФИО + " "+ спец + " " + оценки;

        for (int j=0;j<kolvo;j++){
            if (existingVedomost[j]==vedomost){
                уже_Есть= true;
                continue;
            }
        }
        if (!уже_Есть){
            out << vedomost << '\n';
        }
        уже_Есть=false;
    }
    file.close();
}

void MainWindow::on_pushButton_poisk_clicked()
{
    bool ok;
    QString filter = QInputDialog::getText(this, tr("Поиск"),
                                           tr("Фамилия, Имя или Отчество:"), QLineEdit::Normal,
                                           "", &ok);
    if (ok && !filter.isEmpty())
    {
        for(int i = 0; i < ui->table->rowCount(); ++i)
        {
            bool match = false;
            QTableWidgetItem *item = ui->table->item(i, 0);
            if(item->text().contains(filter))
            {
                match = true;
            }
            ui->table->setRowHidden(i, !match);
        }
    }
}


void MainWindow::on_pushButton_poisk_2_clicked()
{
    for(int i = 0; i < ui->table->rowCount(); ++i)
    {
        ui->table->setRowHidden(i, false);
    }
}


void MainWindow::on_pushButton_sort_clicked()
{
    ui->table->sortItems(6, Qt::DescendingOrder);
    ui->table->sortItems(1, Qt::AscendingOrder);
}
