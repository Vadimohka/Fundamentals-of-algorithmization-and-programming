#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(checkInputDistrict() and checkInputName() and checkInputParty() and checkInputAge() and checkInputIncome() and checkInputProfession()){
        openFile();
        readFromFile();
            candidate.setAge(ui->lineEdit_4->text().toInt());
            candidate.setFullName(ui->lineEdit_2->text());
            candidate.setNumOfDistrict(ui->lineEdit->text().toInt());
            candidate.setIncome(ui->lineEdit_6->text().toInt());
            candidate.setPartyName(ui->lineEdit_3->text());
            candidate.setProfession(ui->lineEdit_5->text());
            writeToFile();
            _candidates.push_back(candidate);
            getInfo();
            addCandidateToTable();
    }
}

bool MainWindow::checkInputDistrict()
{
    int num;
    bool ok = true;
    QString input = ui->lineEdit->text();
    num = input.toInt(&ok);
    if (!ok) {
        // Строка не может быть преобразована в int
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    if(num<= 0) {
        return false;
    }
    return true;
}

bool MainWindow::checkInputName()
{
    QString input = ui->lineEdit_2->text();
    for(int i = 0; i < input.length(); ++i){
        if(input.at(i).isNumber()){
            QMessageBox::warning(this, "Ошибка", "Введенное имя содержит числа");
            return false;
        }
    }
    if(input.size()==0){
        QMessageBox::warning(this, "Ошибка", "Пустое поле");
        return false;
    }
    return true;
}

bool MainWindow::checkInputParty()
{
    QString input = ui->lineEdit_3->text();
    if(input.size()==0){
        QMessageBox::warning(this, "Ошибка", "Пустое поле");
        return false;
    }
    return true;
}

bool MainWindow::checkInputProfession()
{
    QString input = ui->lineEdit_5->text();
    for(int i = 0; i < input.length(); ++i){
        if(input.at(i).isNumber()){
            QMessageBox::warning(this, "Ошибка", "Введенное имя содержит числа");
            return false;
        }
    }
    if(input.size()==0){
        QMessageBox::warning(this, "Ошибка", "Пустое поле");
        return false;
    }
    return true;
}

bool MainWindow::checkInputAge()
{
    int num;
    bool ok = true;
    QString input = ui->lineEdit_4->text();
    num = input.toInt(&ok);
    if (!ok) {
        // Строка не может быть преобразована в int
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    if(num<= 21) {
        return false;
    }
    return true;
}

bool MainWindow::checkInputIncome()
{
    int num;
    bool ok = true;
    QString input = ui->lineEdit->text();
    num = input.toInt(&ok);
    if (!ok) {
        // Строка не может быть преобразована в int
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    if(num <= 0) {
        return false;
    }
    return true;
}

void MainWindow::openFile()
{
    static bool was = false;
    if(was){
        file.close();
        return;
    }
    _path_to_file =
        QFileDialog::getOpenFileName(this, tr("Open File"), "/home/vlad/lab_2_task_2");
    file.setFileName(_path_to_file);
    if (_path_to_file.isEmpty()) {
        return;
    }
    was = true;
}

void MainWindow::writeToFile()
{
    if (_path_to_file.isEmpty()) {
        return;
    }
    if (file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&file);
        out << this->candidate.toString();
        file.close( );
    }
}

void MainWindow::readFromFile()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    static bool was = false;
    if(was){
        file.close();
        return;
    }
    Candidate candi;
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList fields = line.split("-");
        if (fields.size() == 6) {
            candi.setNumOfDistrict(fields[0].toInt());
            candi.setFullName(fields[1]);
            candi.setPartyName(fields[2]);
            candi.setAge(fields[3].toInt());
            candi.setProfession(fields[4]);
            candi.setIncome(fields[5].toInt());
            _candidates.push_back(candi);
        }
        line = in.readLine();
    }
    was = true;
    file.close();
}

void MainWindow::deleteCandidate()
{
    _candidates.pop_back();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Не удалось открыть файл для записи";
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < _candidates.size(); ++i) {
        out << _candidates.at(i).toString();
    }
    getInfo();
    addCandidateToTable();
    file.close();
}

void MainWindow::getInfo()
{
    for (int i = 0; i < _candidates.size(); ++i) {
        _parties.push_back(_candidates.at(i).getPartyName());
        for (int i = 0; i < _parties.size(); ++i) {
            for (int k = 0; k < _parties.size(); ++k) {
                if (i != k and _parties.at(i) == _parties.at(k)){
                    _parties.pop_back();
                }
            }
        }
    }

    for (int k = 0; k < _parties.size(); ++k) {
        qDebug() << _parties.at(k);
    }

    QStringList mostFrequent;
    QString now;

    for (int i = 0; i < _parties.size(); ++i) {
        for (int k = 0; k < _candidates.size(); ++k) {
            if(_parties.at(i) == _candidates.at(k).getPartyName()){
                _jobs.push_back(_candidates.at(k).getProfession());
            }
        }
        int maxCount = 0;

        for (int l = 0; l < _jobs.size(); ++l) {
            int count = 0;
            for (int j = 0; j < _jobs.size(); ++j) {
                if (_jobs.at(l) == _jobs.at(j)) {
                    ++count;
                }
            }

            if (count > maxCount) {
                maxCount = count;
                now = _jobs.at(l);
            }
            for (int k = 0; k < mostFrequent.size(); ++k) {
                qDebug() << mostFrequent.at(k);
            }

        }
        mostFrequent.push_back(now);
        _jobs.clear();
    }

    _jobs = mostFrequent;
    _income.resize(_parties.size());
    _amount.resize(_parties.size());
    _age.resize(_parties.size());

    for (int i = 0; i < _parties.size(); ++i) {
        for (int k = 0; k < _candidates.size(); ++k) {
            if(_parties.at(i) == _candidates.at(k).getPartyName()){
                _income.at(i) += _candidates.at(k).getIncome();
                _age.at(i) += _candidates.at(k).getAge();
                _amount.at(i) += 1;
            }
        }
        _income.at(i) /= _amount.at(i);
        _age.at(i) /= _amount.at(i);
    }

    for (int k = 0; k < _income.size(); ++k) {
        qDebug() << _income.at(k);
    }


}

void MainWindow::addCandidateToTable()
{
    ui->tableWidget->setRowCount(0); // Очистить таблицу

    /*if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }*/

    for (int i = 0; i < _parties.size(); ++i){
        ui->tableWidget->insertRow(i);
        QTableWidgetItem* item1 = new QTableWidgetItem(_parties.at(i));
        ui->tableWidget->setItem(i, 0, item1);

        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(_amount.at(i)));
        ui->tableWidget->setItem(i, 1, item2);

        QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(_age.at(i)));
        ui->tableWidget->setItem(i, 2, item3);

        QTableWidgetItem* item4 = new QTableWidgetItem(_jobs.at(i));
        ui->tableWidget->setItem(i, 3, item4);

        QTableWidgetItem* item5 = new QTableWidgetItem(QString::number(_income.at(i)));
        ui->tableWidget->setItem(i, 4, item5);
    }

    _parties.clear();
    _income.clear();
    _age.clear();
    _amount.clear();
    _jobs.clear();
}

void MainWindow::search(QString name)
{
    QString text;
    QString fullName;
    for (int i = 0; i < _candidates.size(); ++i) {
        fullName = _candidates.at(i).getFullName();
        if(fullName.contains(name)){

            text += "Номер округа: " + QString::number(_candidates.at(i).getNumOfDistrict()) + "\n";
            text += "Полное имя: " + _candidates.at(i).getFullName() + "\n";
            text += "Название партии: " + _candidates.at(i).getPartyName() + "\n";
            text += "Возраст: " + QString::number(_candidates.at(i).getAge()) + "\n";
            text += "Профессия: " + _candidates.at(i).getProfession() + "\n";
            text += "Доход: " + QString::number(_candidates.at(i).getIncome()) + "\n";
            text += "\n";

            ui->textEdit->setPlainText(text);
            ui->textEdit->show();
        }
    }
    ui->textEdit->update();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_7->text();
    search(name);
    ui->lineEdit_7->clear();
}


void MainWindow::on_pushButton_3_clicked()
{
    deleteCandidate();
}

