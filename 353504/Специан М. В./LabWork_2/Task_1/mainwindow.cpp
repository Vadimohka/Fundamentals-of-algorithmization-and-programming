#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"
#include <ctime>
#include <fstream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pDates = new Date[1000];

    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    QString nowDate = Date::ToString(Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900));
    ui->label->setText(nowDate);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pBirthdayDate;
    delete[] m_pDates;
}


bool isValid(QChar &a){
    if(a >= '0' && a <= '9') return true;
    if(a == '.') return true;
    else return false;
}

void MainWindow::AddDate(QString stringDate,bool over){
    if(stringDate.size() != 10) return;
    if(stringDate[0] == '0'){
        if(stringDate[1] > '9' || stringDate[1] < '0') return;
    }
    if(stringDate[2] != '.') return;
    if(stringDate[3] == '0'){
        if(stringDate[4] > '9' || stringDate[4] < '1') return;
    }
    if(stringDate[5] != '.') return;

    QString dd;
    dd.push_back(stringDate[0]);
    dd.push_back(stringDate[1]);
    int DD = dd.toInt();

    QString mm;
    mm.push_back(stringDate[3]);
    mm.push_back(stringDate[4]);
    int MM = mm.toInt();

    QString yy;
    yy.push_back(stringDate[6]);
    yy.push_back(stringDate[7]);
    yy.push_back(stringDate[8]);
    yy.push_back(stringDate[9]);

    int YY = yy.toInt();

    if(YY == 0){
        return;
    }

    if(DD == 0 && MM == 0 && YY == 0){
        return;
    }
    //if(DD == 0 && MM )

    m_pDates[m_datesNum] = Date(DD, MM, YY);

    if(m_fileName != "" && over){
        std::string pathStr;
        for(int i = 0; i < m_fileName.size(); i++){
            pathStr += m_fileName[i].toLatin1();
        }

        std::ofstream ofs(pathStr, std::ios::app);
        if(ofs.is_open()){
            ofs << DD << "." << MM << "." << YY;
        }
        ofs.close();

    }

    m_datesNum++;
}

void MainWindow::UpdateTable(){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(m_datesNum);
    for(int i = 0; i < m_datesNum; i++){
        std::string name;
        if(m_pDates[i].m_day <= 9) name.push_back('0');
        name += std::to_string(m_pDates[i].m_day) + ".";

        if(m_pDates[i].m_mounth <= 9) name.push_back('0');
        name += std::to_string(m_pDates[i].m_mounth) + ".";

        if(m_pDates[i].m_year <= 9) name.push_back('0');
        if(m_pDates[i].m_year <= 99) name.push_back('0');
        if(m_pDates[i].m_year <= 999) name.push_back('0');
        name += std::to_string(m_pDates[i].m_year);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((name.c_str())));

        QString nextDay = Date::ToString(m_pDates[i].NextDay());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((nextDay)));

        if(m_pBirthdayDate == nullptr){
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(" - "));
        }
        else{
            int birthdayDuration = m_pDates[i].Duration(*m_pBirthdayDate);
             ui->tableWidget->setItem(i, 2, new QTableWidgetItem((std::to_string(birthdayDuration).c_str())));
        }

        if(i + 1 < m_datesNum){
             int nextDuration = m_pDates[i].Duration(m_pDates[i + 1]);
             ui->tableWidget->setItem(i, 3, new QTableWidgetItem((std::to_string(nextDuration).c_str())));
        }
        else{
              ui->tableWidget->setItem(i, 3, new QTableWidgetItem(" - "));
        }


        if(i - 1 >= 0){
             int previosDuration = m_pDates[i].Duration(m_pDates[i - 1]);
             ui->tableWidget->setItem(i, 4, new QTableWidgetItem((std::to_string(previosDuration).c_str())));
        }
        else{
             ui->tableWidget->setItem(i, 4, new QTableWidgetItem(" - "));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    qInfo() << m_datesNum;
    m_fileName = QFileDialog::getOpenFileName(this, tr("Open txt with dates!"), QDir::currentPath(), tr("Text Files (*.txt)"));

    QFile file(m_fileName);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream input(&file);

    QString allData = input.readAll();
    QString readedDate;
    for(int i = 0; i < allData.size(); i++){
        if(isValid(allData[i])){
            readedDate.push_back(allData[i]);
        }
        else{
            if(readedDate.size() != 0){
                AddDate(readedDate, false);
            }
            readedDate = QString();
        }
    }
    file.close();

    UpdateTable();
}


void MainWindow::on_pushButton_clicked()
{
    AddDate(ui->lineEdit->text(), true);
    UpdateTable();
}


void MainWindow::on_pushButton_4_clicked()
{
    QString stringDate = ui->lineEdit_2->text();
    if(stringDate.size() != 10) return;
    if(stringDate[0] == '0'){
        if(stringDate[1] > '9' || stringDate[1] < '0') return;
    }
    if(stringDate[2] != '.') return;
    if(stringDate[3] == '0'){
        if(stringDate[4] > '9' || stringDate[4] < '1') return;
    }
    if(stringDate[5] != '.') return;

    QString dd;
    dd.push_back(stringDate[0]);
    dd.push_back(stringDate[1]);
    int DD = dd.toInt();

    QString mm;
    mm.push_back(stringDate[3]);
    mm.push_back(stringDate[4]);
    int MM = mm.toInt();

    QString yy;
    yy.push_back(stringDate[6]);
    yy.push_back(stringDate[7]);
    yy.push_back(stringDate[8]);
    yy.push_back(stringDate[9]);
    int YY = yy.toInt();
    if(m_pBirthdayDate != nullptr)
        delete m_pBirthdayDate;

    m_pBirthdayDate = new Date(DD, MM, YY);

    UpdateTable();
}


void MainWindow::on_pushButton_3_clicked()
{

    m_fileName = QFileDialog::getSaveFileName(this, tr("Save Text File"), "/home/", tr("Text Files (*.txt)"));
    if (m_fileName != "")
    {
        QFile file(QFileInfo(m_fileName).absoluteFilePath());

        if (file.exists())
        {
            QMessageBox::StandardButton chosenButton
                    = QMessageBox::warning(this, tr("File exists"), tr("The file already exists. Do you want to overwrite it?"),
                                           QMessageBox::Ok | QMessageBox::Cancel,
                                           QMessageBox::Cancel);
            if (chosenButton != QMessageBox::Ok)
            {
                return; //Save was cancelled
            }
        }
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Failed to save file"));
            return; //Aborted
        }
        //All ok - save data
        QString text;
        for(int i = 0; i < m_datesNum; i++){
            text += Date::ToString(m_pDates[i]);
            text += "  ";
        }
        QTextStream out(&file);
        out << text;
        file.close();
    }
}

bool MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::WindowActivate) {
    }
    return QWidget::event(e);
}


