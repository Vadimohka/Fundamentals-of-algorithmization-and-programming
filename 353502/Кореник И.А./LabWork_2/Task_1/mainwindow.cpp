#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    Date* today = new Date("13.04.2024");
    Date* birthday = new Date("30.11.2005");

    input.push_back(*today);
    input.push_back(*birthday);

    for (auto date : input){
        qDebug() << date.getDate();
    }
    readFile(filename, &input);

    this->createUI(QStringList() << ("id")
                                 << ("input")
                                 << ("next day")
                                 << ("previous day")
                                 << ("duration to next")
                                 << ("day of the week")
                                 << ("days till your birthday"));



}

void MainWindow::createUI(const QStringList &headers)
{
    //ui->tableWidget->set
    ui->tableWidget->setColumnCount(7); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
    ui->tableWidget->hideColumn(0);


    for (int i = 0; i < input.size(); i++){
        addRow(&input[i], i);
    }
    ui->tableWidget->resizeColumnsToContents();
}


void MainWindow::readFile(QString filename, QVector<Date>* input)
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while(!in.atEnd()) {
            input->push_back(in.readLine());
        }

        file.close();
    }

}


void MainWindow::addRow(Date *date, int i)
{
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i ,1 , new QTableWidgetItem(date->getDate()));
    ui->tableWidget->setItem(i ,2 , new QTableWidgetItem(date->nextday()->getDate()));
    ui->tableWidget->setItem(i ,3 , new QTableWidgetItem(date->previousDate()->getDate()));
    ui->tableWidget->setItem(i ,4 , new QTableWidgetItem(input[fmin(input.size() - 1, i + 1)].getDuration(date)));
    if (i != 0)
        ui->tableWidget->setItem(i - 1 ,4 , new QTableWidgetItem(date->getDuration(&input[i - 1])));
    ui->tableWidget->setItem(i ,5 , new QTableWidgetItem(date->getWeekNumber()));
    ui->tableWidget->setItem(i ,6 , new QTableWidgetItem(date->getDuration(&input[1])));

}


void MainWindow::changeDate(Date* date, int i)
{

    input[i] = *date;
    QFile f(filename);
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QVector<QString> s;
        QTextStream t(&f);
        for (int i = 0; i < input.size() - 2; i++)
        {
            QString line = t.readLine();
            s.push_back(line + "\n");
        }
        f.resize(0);
        for (int j = 0; j < s.size(); j++){
            if (j != i - 2){
                t << s[j];
            }
            else{
                t << date->getDate() << '\n';
            }
        }
        f.close();
    }
    ui->tableWidget->setItem(i ,1 , new QTableWidgetItem(date->getDate()));
    ui->tableWidget->setItem(i ,2 , new QTableWidgetItem(date->nextday()->getDate()));
    ui->tableWidget->setItem(i ,3 , new QTableWidgetItem(date->previousDate()->getDate()));
    ui->tableWidget->setItem(i ,4 , new QTableWidgetItem(input[fmax(0, i - 1)].getDuration(date)));
    ui->tableWidget->setItem(i - 1 ,4 , new QTableWidgetItem(date->getDuration(&input[i - 1])));
    ui->tableWidget->setItem(i ,5 , new QTableWidgetItem(date->getWeekNumber()));
    ui->tableWidget->setItem(i ,6 , new QTableWidgetItem(date->getDuration(&input[1])));
}


Date* MainWindow::getInfo()
{
    Date* date = new Date(ui->daySpin->text().toInt(), ui->monthSpin->text().toInt(),ui->yearSpin->text().toInt());
    return date;
}

void MainWindow::deleteDate(int i)
{
    ui->tableWidget->removeRow(i);
    input.remove(i);
    QFile f(filename);
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QVector<QString> s;
        QTextStream t(&f);

        for (int i = 0; i < input.size() - 2; i++)
        {
            QString line = t.readLine();
            s.push_back(line + "\n");
        }
        f.resize(0);

        for (int j = 0; j < s.size(); j++){
            if (j != i - 2){
                t << s[j];
            }
        }
        f.close();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{

    Date* newDate = getInfo();

    if (newDate->isCorrect()){
        input.push_back(*newDate);

        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream out(&file);
            out << newDate->getDate() << '\n';
            int i = ui->tableWidget->rowCount();
            addRow(newDate, i);
            file.close();
        }
    }
    else{
        qDebug() << "date does not exist";
    }

}


void MainWindow::on_birthdayButton_clicked()
{
    changeDate(getInfo(), 1);
}


void MainWindow::on_deleteButton_clicked()
{
    if (!ui->tableWidget->selectedItems().empty()){
        int i = ui->tableWidget->selectedItems()[0]->row();

        if (i > 1)
            deleteDate(i);
    }
    else if (input.size() > 2){
        deleteDate(ui->tableWidget->rowCount() - 1);
    }


}


void MainWindow::on_changeButton_clicked()
{
    if (!ui->tableWidget->selectedItems().empty()){
        int i = ui->tableWidget->selectedItems()[0]->row();
        Date* date = getInfo();

        if (i > 1 && date->isCorrect())
            changeDate(date, i);
    }
}


void MainWindow::on_open_clicked()
{
    filename = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;");

    Date today = input[0];
    Date birthday = input[1];
    input.clear();
    input.push_back(today);
    input.push_back(birthday);

    readFile(filename, &input);

    ui->tableWidget->setRowCount(0);
    this->createUI(QStringList() << ("id")
                                 << ("input")
                                 << ("next day")
                                 << ("previous day")
                                 << ("duration to next")
                                 << ("day of the week")
                                 << ("days till your birthday"));

}

