#include "DialogCondidate.h"
#include "ui_DialogCondidate.h"
#include "mainwindow.h"

#include "Condidate.h"
#include "QString"
#include "QDebug"


extern std::vector<Company> G_companys;
extern std::vector<JobOpener> G_jobOpeners;
extern std::vector<Condidate> G_condidates;
extern MainWindow* mainWnd;

DialogCondidate::DialogCondidate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCondidate)
{
    ui->setupUi(this);
    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_FIO->setVisible(false);
    ui->Error_IncorrectPost->setVisible(false);
    this->setFixedSize(400, 360);
}

DialogCondidate::~DialogCondidate()
{
    delete ui;
}

static bool isNumber(QString str){
    for(int i = 0; i < str.size(); i++){
        if(!str[i].isNumber()) return false;
    }
    return true;
}

void DialogCondidate::on_pushButton_clicked()
{
    Condidate condidate;

    QString fio;
    fio = ui->EditFIO->text();


    int spacesCount = 0;
    bool isEmpty = true;
    for(int i = 0; i < fio.size(); i++){
        if(fio[i].isNumber() || fio.isEmpty()){
            ui->Error_FIO->setVisible(true);
            this->setFixedSize(400, 400);
            return;
        }
        else{
            isEmpty = false;
        }
        if(fio[i] == " " && !isEmpty && i != 0){
            spacesCount++;
            isEmpty = true;
        }
    }
    if(spacesCount == 2 && !isEmpty){
        ui->Error_FIO->setVisible(false);
        this->setFixedSize(400, 360);
        condidate.FIO = fio;
    }
    else{
        ui->Error_FIO->setVisible(true);
        this->setFixedSize(400, 400);
        return;
    }


    if(ui->EditPost->text().isEmpty()){
        ui->Error_IncorrectPost->setVisible(true);
        this->setFixedSize(400, 400);
        return;
    }
    ui->Error_IncorrectPost->setVisible(false);
    this->setFixedSize(400, 360);
    condidate.wantPost = ui->EditPost->text();

    condidate.birthday = ui->dateEdit->text();
    qInfo() << ui->dateEdit->text();

    condidate.isUmnitsa = ui->isHaveHighEducation->isChecked();




    int minSalary = ui->EditMinimumSalary->text().toInt();
    if(minSalary < 0 || minSalary > 999000000 || ui->EditMinimumSalary->text() == "" || !isNumber(ui->EditMinimumSalary->text())){
        ui->Error_IncorrectSalary->setVisible(true);
        this->setFixedSize(400, 400);
        return;
    }
    ui->Error_IncorrectSalary->setVisible(false);
    this->setFixedSize(400, 360);

    condidate.minOclad = minSalary;

    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_IncorrectPost->setVisible(false);
    ui->Error_FIO->setVisible(false);
    this->setFixedSize(400, 360);

    ui->EditFIO->setText(QString());
    ui->EditMinimumSalary->setText(QString());
    ui->EditPost->setText(QString());
    ui->isHaveHighEducation->setChecked(false);

    G_condidates.push_back(condidate);


    mainWnd->UpdateTables();

    this->hide();
    //Con
}

void DialogCondidate::closeEvent(QCloseEvent* event){
    ui->EditFIO->setText(QString());
    ui->EditMinimumSalary->setText(QString());
    ui->EditPost->setText(QString());
    ui->Error_IncorrectSalary->setVisible(false);
    ui->Error_FIO->setVisible(false);
    this->setFixedSize(400, 360);
}
