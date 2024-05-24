#include "dialogsearch.h"
#include "ui_dialogsearch.h"

DialogSearch::DialogSearch(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSearch)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(updateFirm()));
    connect(ui->comboBox_2, SIGNAL(activated(int)), this, SLOT(updateModel()));
    //connect(ui->comboBox_3, SIGNAL(activated(int)), this, SLOT(updateModel()));
}

DialogSearch::~DialogSearch()
{
    delete ui;
}


void DialogSearch::on_buttonBox_accepted()
{
    emit sendData(ui->comboBox->currentText(), ui->comboBox_2->currentText(), ui->comboBox_3->currentText());
    accept();
}

void DialogSearch::setComponents(component **components, int kolvo)
{
    this->components = components;
    this->kolvo = kolvo;
    makeComboBoxs();
}

void DialogSearch::makeComboBoxs()
{
    //ui->comboBox->clear();
    bool stat;
    for(int i = 0; i < kolvo; i++)
    {
        stat = true;

        for(int m = 0; m < i; m++)
        {
            if(components[i]->retType() == components[m]->retType())
            {
                stat = false;
                break;
            }
        }

        if(stat)
        {
            ui->comboBox->addItem(components[i]->retType());
        }
    }

    updateFirm();
}

void DialogSearch::updateFirm()
{
    ui->comboBox_2->clear();
    bool stat;

    for(int i = 0; i < kolvo; i++)
    {
        stat = true;
        if(components[i]->retType() == ui->comboBox->currentText())
        {
            for(int j = 0; j < ui->comboBox_2->count(); j++)
            {
                if(components[i]->retFirm() == ui->comboBox_2->itemText(j))
                {
                    stat = false;
                    break;
                }
            }
        }
        else
        {
            continue;
        }
        if(stat)
        {
            ui->comboBox_2->addItem(components[i]->retFirm());
        }
    }

    updateModel();
}

void DialogSearch::updateModel()
{
    ui->comboBox_3->clear();
    bool stat;

    for(int i = 0; i < kolvo; i++)
    {
        stat = true;
        if(components[i]->retType() == ui->comboBox->currentText() && components[i]->retFirm() == ui->comboBox_2->currentText())
        {
            for(int j = 0; j < ui->comboBox_3->count(); j++)
            {
                if(components[i]->retCompModel() == ui->comboBox_3->itemText(j))
                {
                    stat = false;
                    break;
                }
            }
        }
        else
        {
            continue;
        }
        if(stat)
        {
            ui->comboBox_3->addItem(components[i]->retCompModel());
        }
    }
}
