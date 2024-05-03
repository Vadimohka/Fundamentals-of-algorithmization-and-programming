#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

std::vector<Company> G_companys;
std::vector<JobOpener> G_jobOpeners;
std::vector<Condidate> G_condidates;
MainWindow* mainWnd;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pDialogCompany = new DialogCompany();
    m_pDialogJobOpenings = new DialogJobOpenings();
    m_pDialogCondidates = new DialogCondidate();

    mainWnd = this;

    ui->comboBox->addItem("File");
    ui->comboBox->addItem("Open");
    ui->comboBox->addItem("Save");

    ClearJobOpener();
    ClearCondidate();
    //m_pDialogCompany->m_pMainWindow = this;
    //UpdateTables();
}

MainWindow::~MainWindow()
{
    delete ui;
    m_pDialogCompany->hide();
    delete m_pDialogCompany;
    m_pDialogJobOpenings->hide();
    delete m_pDialogJobOpenings;
}


void MainWindow::UpdateTables(){
    ui->Table_Companies->clearContents();
    ui->Table_Companies->setRowCount(G_companys.size() + 1);
    QTableWidgetItem* aa = new QTableWidgetItem("                     ---All Companies---");
    if(selectetCompanyIndex == -1){
        aa->setBackground(QBrush("gray"));
    }
    else{
        aa->setBackground(QBrush("white"));
    }
    ui->Table_Companies->setItem(0, 0, aa);

    for(int i = 0; i < G_companys.size(); i++){
        QTableWidgetItem* bb = new QTableWidgetItem((G_companys[i].name));
        if(i == selectetCompanyIndex){
            bb->setBackground(QBrush("gray"));
        }
        else{
            bb->setBackground(QBrush("white"));
        }
        ui->Table_Companies->setItem(i + 1, 0, bb);
    }

    m_showedOpeners.clear();
    const JobOpener* selectedJobOpener = nullptr;
    //std::vector<JobOpener> selectedJobOpeners;

    if(selectetCompanyIndex != -1)
    {
        int selectedJobOpenersCount = 0;
        for(int i = 0; i < G_jobOpeners.size(); i++){
            if(G_jobOpeners[i].companyIndex == selectetCompanyIndex) selectedJobOpenersCount++;
        }
        ui->Table_JobOpeners->clearContents();
        ui->Table_JobOpeners->setRowCount(selectedJobOpenersCount + 1);
        QTableWidgetItem* pAllJobWdg = new QTableWidgetItem("                    ---All Job Openers---");
        if(selectetJobOpenerIndex == -1) pAllJobWdg->setBackground(QBrush("gray"));
        else pAllJobWdg->setBackground(QBrush("white"));
        ui->Table_JobOpeners->setItem(0, 0, pAllJobWdg);

        for(int i = 0, j = 1; i < G_jobOpeners.size(); i++){
            if(G_jobOpeners[i].companyIndex == selectetCompanyIndex){
                //selectedJobOpeners.push_back(G_jobOpeners[i]);
                //selectedJobOpener = &G_jobOpeners[i];

                QTableWidgetItem* pAllJobWdg = new QTableWidgetItem("(" + G_jobOpeners[i].companyName + ")  "
                                                                    + G_jobOpeners[i].post + "  (" + QString::number(G_jobOpeners[i].salary) + "$)");
                bool isHaveCondidates = false;
                for(int i = 0; i < G_condidates.size(); i++){
                    if(G_condidates[i].wantPost == G_jobOpeners[i].post) isHaveCondidates = true;
                }
                if(isHaveCondidates){
                    pAllJobWdg->setForeground(QBrush("green"));
                }
                else{
                    pAllJobWdg->setForeground(QBrush("red"));
                }

                if(i == selectetJobOpenerIndex){
                    pAllJobWdg->setBackground(QBrush("gray"));
                    selectedJobOpener = &G_jobOpeners[i];
                }
                else{
                    pAllJobWdg->setBackground(QBrush("white"));
                }

                ui->Table_JobOpeners->setItem(j, 0, pAllJobWdg);
                m_showedOpeners.push_back(&(G_jobOpeners[i]));
                j++;
            }
        }
    }
    else{
        ui->Table_JobOpeners->clearContents();
        ui->Table_JobOpeners->setRowCount(G_jobOpeners.size() + 1);
        QTableWidgetItem* pAllJobWdg = new QTableWidgetItem("                    ---All Job Openers---");
        if(selectetJobOpenerIndex == -1) pAllJobWdg->setBackground(QBrush("gray"));
        else pAllJobWdg->setBackground(QBrush("white"));
        ui->Table_JobOpeners->setItem(0, 0, pAllJobWdg);

        for(int i = 0, j = 1; i < G_jobOpeners.size(); i++){
            if(1){
                QTableWidgetItem* pAllJobWdg = new QTableWidgetItem("(" + G_jobOpeners[i].companyName + ")  "
                                                                    + G_jobOpeners[i].post + "  (" + QString::number(G_jobOpeners[i].salary) + "$)");
                bool isHaveCondidates = false;
                for(int i = 0; i < G_condidates.size(); i++){
                    if(G_condidates[i].wantPost == G_jobOpeners[i].post) isHaveCondidates = true;
                }
                if(isHaveCondidates){
                    pAllJobWdg->setForeground(QBrush("green"));
                }
                else{
                    pAllJobWdg->setForeground(QBrush("red"));
                }

                if(i == selectetJobOpenerIndex){
                    pAllJobWdg->setBackground(QBrush("gray"));
                }
                else{
                    pAllJobWdg->setBackground(QBrush("white"));
                }

                ui->Table_JobOpeners->setItem(j, 0, pAllJobWdg);
                m_showedOpeners.push_back(&(G_jobOpeners[i]));
                j++;
            }
        }
    }

    if(selectedJobOpener != 0){
        qInfo() << selectedJobOpener->companyName;
    }
    else{
        qInfo() << "NUUUL";
    }


    if(selectedJobOpener != nullptr){
        m_showedCondidates.clear();

        for(int i =0; i < G_condidates.size(); i++){
            if(G_condidates[i].wantPost == selectedJobOpener->post){
                m_showedCondidates.push_back(&G_condidates[i]);
            }
        }

        ui->Table_Condidates->clearContents();
        ui->Table_Condidates->setRowCount(m_showedCondidates.size());

        for(int i = 0; i < m_showedCondidates.size(); i++){
            QTableWidgetItem* Condic = new QTableWidgetItem("(" + G_condidates[i].wantPost + ")  "
                                                            + G_condidates[i].FIO);
            bool isGood = true;
            if(selectetJobOpenerIndex != -1){
                if(m_showedCondidates[i]->minOclad > selectedJobOpener->salary) isGood = false;
                if(!m_showedCondidates[i]->isUmnitsa){
                    if(selectedJobOpener->isUmnitsa) isGood = false;
                }

                if(isGood){
                    Condic->setForeground(QBrush("green"));
                }
                else{
                    Condic->setForeground(QBrush("red"));
                }
                ui->Table_Condidates->setItem(i, 0, Condic);
                //ui->Table_Condidates->insertRow(ui->Table_Condidates->rowCount());
                //ui->Table_Condidates->setItem(ui->Table_Condidates->rowCount() - 1, 0, Condic);
            }
        }
    }
    else{
        m_showedCondidates.clear();

        for(int i =0; i < G_condidates.size(); i++){
            //if(G_condidates[i].wantPost == selectedJobOpener->post){
                m_showedCondidates.push_back(&G_condidates[i]);
            //}
        }

        ui->Table_Condidates->clearContents();
        ui->Table_Condidates->setRowCount(m_showedCondidates.size());

        for(int i = 0; i < m_showedCondidates.size(); i++){
            QTableWidgetItem* Condic = new QTableWidgetItem("(" + G_condidates[i].wantPost + ")  "
                                                        + G_condidates[i].FIO);
            ui->Table_Condidates->setItem(i, 0, Condic);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    m_pDialogCompany->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    m_pDialogJobOpenings->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    m_pDialogCondidates->show();
}

void MainWindow::closeEvent(QCloseEvent* event){
    m_pDialogCompany->hide();
    m_pDialogCondidates->hide();
    m_pDialogCompany->hide();
}



void MainWindow::on_Table_Companies_cellClicked(int row, int column)
{
    selectetCompanyIndex = row - 1;
    selectetJobOpenerIndex = -1;
    UpdateTables();
}

void MainWindow::on_Table_JobOpeners_cellClicked(int row, int column)
{
    selectetJobOpenerIndex = row - 1;


    ClearCondidate();
    m_showedCondidates.clear();

    UpdateTables();

    if(selectetJobOpenerIndex != -1){
        ui->JOBSHOW_compNameChanged->show();
        ui->JOBSHOW_compNameChanged->setText(m_showedOpeners[selectetJobOpenerIndex]->companyName);
        ui->JOBSHOW_compNameLabel->show();

        ui->JOBSHOW_postChanged->show();
        ui->JOBSHOW_postChanged->setText(m_showedOpeners[selectetJobOpenerIndex]->post);
        ui->JOBSHOW_postLabel->show();

        ui->JOBSHOW_salaryEdit->show();
        ui->JOBSHOW_salaryEdit->setText(QString::number(m_showedOpeners[selectetJobOpenerIndex]->salary));
        ui->JOBSHOW_postLabel_2->show();

        ui->JOBSHOW_EducEdit->show();
        if(m_showedOpeners[selectetJobOpenerIndex]->isUmnitsa){
            ui->JOBSHOW_EducEdit->setText("true");
        }
        else{
            ui->JOBSHOW_EducEdit->setText("false");
        }

        ui->JOBSHOW_postLabel_3->show();
    }
    else{
        ClearJobOpener();
    }

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 1){
        ReadFile();
    }
    if(index == 2){
        WriteFile();
    }
    ui->comboBox->setCurrentIndex(0);
    UpdateTables();
}


void MainWindow::ReadFile(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open config!", QDir::currentPath(), "Text File (*.txt)");

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream input(&file);

    QString allData = input.readAll();

    ProcessReading(allData, G_companys, G_jobOpeners, G_condidates);
    CorrelateCompanies();

    file.close();
}

void MainWindow::WriteFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text File"), "/home/", tr("Text Files (*.txt)"));
    if (fileName != "")
    {
        QFile file(QFileInfo(fileName).absoluteFilePath());

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
        for(int i = 0; i < G_companys.size(); i++){
            text += "<Company>\n";
            text += G_companys[i].name + "\n\n";
        }

        for(int i = 0; i < G_jobOpeners.size(); i++){
            text += "<JobOpening>\n";
            text += G_jobOpeners[i].companyName + "\n";
            text += G_jobOpeners[i].post + "\n";
            text += QString::number(G_jobOpeners[i].salary) + "\n";
            if(G_jobOpeners[i].isUmnitsa){
                text += "true";
            }
            else{
                text += "false";
            }
            text += "\n";
            text += QString::number(G_jobOpeners[i].ageDiapas[0]) + "\n";
            text += QString::number(G_jobOpeners[i].ageDiapas[1]) + "\n";
            text += QString::number(G_jobOpeners[i].howMuchWorking) + "\n";
            text += QString::number(G_jobOpeners[i].vacationNum) + "\n\n";
        }

        for(int i = 0; i < G_condidates.size(); i++){
            text += "<Condidates>\n";
            text += G_condidates[i].FIO + "\n";
            text += G_condidates[i].birthday + "\n";
            text += G_condidates[i].wantPost + "\n";
            if(G_condidates[i].isUmnitsa){
                text += "true";
            }
            else{
                text += "false";
            }
            text += "\n";
            text += QString::number(G_condidates[i].minOclad) + "\n\n";
        }

        QTextStream out(&file);
        out << text;
        file.close();
    }
}

void MainWindow::ProcessReading(const QString& allData, std::vector<Company>& companies, std::vector<JobOpener>& jobOpeners,
                                std::vector<Condidate>& condidates){
    for(int i = 0; i < allData.size(); i++){
        if(allData[i] == "<" && allData[i + 1] == "C" && allData[i+3] == "m"){
            i += 10;

            Company newCompany;
            while(true){
                newCompany.name += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }
            companies.push_back(newCompany);
        }
        if(allData[i] == "<" && allData[i+1] == "J" && allData[i+2] == "o"){
            i+= 13;
            JobOpener newJobOpener;
            while(true){
                newJobOpener.companyName += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            i++;
            while(true){
                newJobOpener.post += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            i++;
            QString sSalary;
            while(true){
                sSalary += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }
            newJobOpener.salary = sSalary.toInt();

            i++;
            QString sUmnitsa;
            while(true){
                sUmnitsa += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            if(sUmnitsa[0] == "t" || sUmnitsa[0] == "T"){
                newJobOpener.isUmnitsa = true;
            }
            else{
                newJobOpener.isUmnitsa = false;
            }

            while(true){
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }
            while(true){
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            while(true){
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            while(true){
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            G_jobOpeners.push_back(newJobOpener);
        }
        if(allData[i] == "<" && allData[i+1] == "C" && allData[i+3] == "n"){
            i+= 13;
            Condidate newCondidate;
            while(true){
                newCondidate.FIO += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            i++;
            while(true){
                newCondidate.birthday += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            i++;
            while(true){
                newCondidate.wantPost += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            i++;
            QString sUmnitsa;
            while(true){
                sUmnitsa += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }

            if(sUmnitsa[0] == "t" || sUmnitsa[0] == "T"){
                newCondidate.isUmnitsa = true;
            }
            else{
                newCondidate.isUmnitsa = false;
            }

            i++;
            QString sSalary;
            while(true){
                sSalary += allData[i];
                i++;
                if(allData[i] == "\n"){
                    break;
                }
            }
            newCondidate.minOclad = sSalary.toInt();
            G_condidates.push_back(newCondidate);
        }
    }
}


void MainWindow::CorrelateCompanies(){
    for(int i = 0; i < G_jobOpeners.size(); i++){
        if(G_jobOpeners[i].companyIndex != -1) continue;
        bool isExist = false;
        for(int j = 0; j < G_companys.size(); j++){
            if(G_jobOpeners[i].companyName == G_companys[i].name) isExist = true;
        }
        if(!isExist){
            G_jobOpeners.erase(G_jobOpeners.begin() + i);
            CorrelateCompanies();
            break;
        }
    }
}

void MainWindow::ClearJobOpener(){
    ui->JOBSHOW_EducEdit->hide();
    ui->JOBSHOW_salaryEdit->hide();
    ui->JOBSHOW_compNameChanged->hide();
    ui->JOBSHOW_compNameLabel->hide();
    ui->JOBSHOW_postChanged->hide();
    ui->JOBSHOW_postLabel_2->hide();
    ui->JOBSHOW_postLabel_3->hide();
    ui->JOBSHOW_postLabel->hide();
}

void MainWindow::ClearCondidate(){
    ui->CONDIDATE_EducEdit_2->hide();
    ui->CONDIDATE_salaryEdit_2->hide();
    ui->CONDIDATE_compNameChanged_2->hide();
    ui->CONDIDATE_compNameLabel_2->hide();
    ui->CONDIDATE_compNameChanged_2->hide();
    ui->CONDIDATE_postChanged_2->hide();
    ui->CONDIDATE_postLabel_4->hide();
    ui->CONDIDATE_postLabel_5->hide();
    ui->CONDIDATE_postLabel_6->hide();
}


void MainWindow::on_comboBox_activated(int index)
{

}


void MainWindow::on_Table_Condidates_cellClicked(int row, int column)
{
    ClearJobOpener();

    ui->CONDIDATE_compNameChanged_2->show();
    ui->CONDIDATE_compNameChanged_2->setText(m_showedCondidates[row]->FIO);
    ui->CONDIDATE_compNameLabel_2->show();

    ui->CONDIDATE_postChanged_2->show();
    ui->CONDIDATE_postChanged_2->setText(m_showedCondidates[row]->wantPost);
    ui->CONDIDATE_postLabel_4->show();

    ui->CONDIDATE_salaryEdit_2->show();
    ui->CONDIDATE_salaryEdit_2->setText(QString::number(m_showedCondidates[row]->minOclad));
    ui->CONDIDATE_postLabel_5->show();

    ui->CONDIDATE_EducEdit_2->show();
    if(m_showedCondidates[row]->isUmnitsa){
        ui->CONDIDATE_EducEdit_2->setText("true");
    }
    else{
        ui->CONDIDATE_EducEdit_2->setText("false");
    }

    ui->CONDIDATE_postLabel_6->show();
}

