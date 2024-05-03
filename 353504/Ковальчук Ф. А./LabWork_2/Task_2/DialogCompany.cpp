#include "DialogCompany.h"
#include "ui_dialogcompany.h"
#include "mainwindow.h"
#include <vector>

extern std::vector<Company> G_companys;
extern MainWindow* mainWnd;

DialogCompany::DialogCompany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCompany)
{
    ui->setupUi(this);
    ui->errorMsg->setVisible(false);
}

DialogCompany::~DialogCompany()
{
    delete ui;
}

void DialogCompany::on_ButtonAddCompanyName_clicked()
{
    if(!ui->EditCompanyLine->text().isEmpty()){
        for(int i = 0; i < G_companys.size(); i++){
            if(G_companys[i].name == ui->EditCompanyLine->text())
            {
                ui->errorMsg->setVisible(true);

                this->setFixedSize(340, 190);

                return;
            }
        }

        Company comp;
        comp.name = ui->EditCompanyLine->text();
        G_companys.push_back(comp);
    }
    else{
        ui->errorMsg->setVisible(true);
        this->setFixedSize(340, 190);
        return;
    }
    ui->EditCompanyLine->setText(QString());
    ui->errorMsg->setVisible(false);
    this->setFixedSize(340, 165);

    mainWnd->UpdateTables();
    //m_pMainWindow->UpdateTables();
    this->hide();
}

void DialogCompany::closeEvent(QCloseEvent* event){
    ui->EditCompanyLine->setText(QString());
    ui->errorMsg->setVisible(false);
    this->setFixedSize(340, 165);
}

