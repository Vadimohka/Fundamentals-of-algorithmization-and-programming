#include "DialogJobOpenings.h"
#include "ui_dialogjobopenings.h"
#include "mainwindow.h"

extern std::vector<Company> G_companys;
extern std::vector<JobOpener> G_jobOpeners;
extern MainWindow* mainWnd;

DialogJobOpenings::DialogJobOpenings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJobOpenings)
{
    ui->setupUi(this);

    ui->Error_NoCompanyName->setVisible(false);
    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_IncorrectVocationCount->setVisible(false);
    ui->Error_IncorrectAgeRage->setVisible(false);
    ui->Error_IncorrectWorkExpirience->setVisible(false);

    this->setFixedSize(400, 440);
}

DialogJobOpenings::~DialogJobOpenings()
{
    delete ui;
}

bool isNumber(QString str){
    for(int i = 0; i < str.size(); i++){
        if(!str[i].isNumber()) return false;
    }
    return true;
}

void DialogJobOpenings::on_pushButton_clicked()
{
    JobOpener jobOpener;

    QString companyName = ui->EditCompanyName->text();
    int companyIndex = -1;


    for(int i = 0; i < G_companys.size(); i++){
        if(G_companys[i].name == companyName)
        {
            companyIndex = i;
        }
    }

    if(companyIndex == -1 || companyName == "") {
        ui->Error_NoCompanyName->setVisible(true);
        this->setFixedSize(400, 480);
        return;
    }
    ui->Error_NoCompanyName->setVisible(false);
    this->setFixedSize(400, 440);

    jobOpener.companyIndex = companyIndex;
    jobOpener.companyName = companyName;


    QString post = ui->EditPost->text();
    jobOpener.post = post;

    int salary = ui->EditSalary->text().toInt();
    if(salary < 0 || salary > 999000000 || ui->EditSalary->text() == "" || !isNumber(ui->EditSalary->text())){
        ui->Error_IncorrectSalary->setVisible(true);
        this->setFixedSize(400, 480);
        return;
    }
    ui->Error_IncorrectSalary->setVisible(false);
    this->setFixedSize(400, 440);

    jobOpener.salary = salary;

    jobOpener.isUmnitsa = ui->isHaveHighEducation->isChecked();


    int vacationCount = ui->EditVacationCount->text().toInt();
    if(vacationCount < 0 || vacationCount > 999999 || ui->EditVacationCount->text() == "" || !isNumber(ui->EditVacationCount->text())){
        ui->Error_IncorrectVocationCount->setVisible(true);
        this->setFixedSize(400, 480);
        return;
    }
    ui->Error_IncorrectVocationCount->setVisible(false);
    this->setFixedSize(400, 440);

    jobOpener.vacationNum = vacationCount;


    int ageMin = ui->EditAdgeMin->text().toInt();
    int ageMax = ui->EditAdgeMax->text().toInt();
    if(ageMin < 0 || ageMin > 99 || ageMax < 1 || ageMax > 100 || ageMax < ageMin || ui->EditAdgeMin->text() == "" ||
        ui->EditAdgeMax->text() == "" || !isNumber(ui->EditAdgeMin->text()) || !isNumber(ui->EditAdgeMax->text()))
    {
        ui->Error_IncorrectAgeRage->setVisible(true);
        this->setFixedSize(400, 480);
        return;
    }
    ui->Error_IncorrectAgeRage->setVisible(false);
    this->setFixedSize(400, 440);

    jobOpener.ageDiapas[0] = ageMin;
    jobOpener.ageDiapas[1] = ageMax;



    int workExpirience = ui->EditWorkExpirience->text().toInt();

    if(workExpirience < 0 || workExpirience > 60 || ui->EditWorkExpirience->text() == "" || !isNumber(ui->EditWorkExpirience->text())){
        ui->Error_IncorrectWorkExpirience->setVisible(true);
        this->setFixedSize(400, 480);
        return;
    }
    ui->Error_IncorrectWorkExpirience->setVisible(false);
    this->setFixedSize(400, 440);

    jobOpener.howMuchWorking = workExpirience;




    ui->Error_NoCompanyName->setVisible(false);
    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_IncorrectVocationCount->setVisible(false);
    ui->Error_IncorrectAgeRage->setVisible(false);
    ui->Error_IncorrectWorkExpirience->setVisible(false);
    this->setFixedSize(400, 440);

    ui->EditCompanyName->setText(QString());
    ui->EditPost->setText(QString());
    ui->EditSalary->setText(QString());
    ui->EditVacationCount->setText(QString());
    ui->EditAdgeMin->setText(QString());
    ui->EditAdgeMax->setText(QString());
    ui->EditWorkExpirience->setText(QString());
    ui->isHaveHighEducation->setChecked(false);


    G_jobOpeners.push_back(jobOpener);


    mainWnd->UpdateTables();

    this->hide();
}


void DialogJobOpenings::closeEvent(QCloseEvent* event){
    ui->Error_NoCompanyName->setVisible(false);
    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_IncorrectVocationCount->setVisible(false);
    ui->Error_IncorrectAgeRage->setVisible(false);
    ui->Error_IncorrectWorkExpirience->setVisible(false);

    ui->EditCompanyName->setText(QString());
    ui->EditPost->setText(QString());
    ui->EditSalary->setText(QString());
    ui->EditVacationCount->setText(QString());
    ui->EditAdgeMin->setText(QString());
    ui->EditAdgeMax->setText(QString());
    ui->EditWorkExpirience->setText(QString());
    ui->isHaveHighEducation->setChecked(false);

    this->setFixedSize(400, 440);
}
