//
// Created by volodya-petarda on 4/25/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    ui->inputPerson->hide();
    connect(ui->inputPersonButton, SIGNAL(clicked()), this, SLOT(showAddPerson()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(hideAddPerson()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(addPerson()));
    connect(ui->menList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onManClicked(QListWidgetItem*)));
    connect(ui->womenList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onWomanClicked(QListWidgetItem*)));
    connect(ui->makePairButton, SIGNAL(clicked()), this, SLOT(makePair()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::showAddPerson() {
    this->ui->inputPerson->show();
}

void mainwindow::hideAddPerson() {
    this->ui->inputPerson->hide();
    showLists();
}

void mainwindow::addPerson() {
    if(this->ui->nameInput->text().size() <= 0 || this->ui->hobbyInput->toPlainText().size() <= 0 || this->ui->ageInput->text().size() <= 0 ||
            this->ui->weightInput->text().size() <= 0 || this->ui->heightInput->text().size() <= 0 || this->ui->minAgeInput->text().size() <= 0 ||
            this->ui->maxAgeInput->text().size() <= 0 || this->ui->minHeightInput->text().size() <= 0 || this->ui->maxHeightInput->text().size() <= 0 ||
            this->ui->minWeightInput->text().size() <= 0 || this->ui->maxWeightInput->text().size() <= 0){
        QMessageBox *message = new QMessageBox();
        message->setText("incorrect input, try again :((((((((");
        message->show();
        return;
    }
    std::string name = this->ui->nameInput->text().toStdString();
    std::string hobby = this->ui->hobbyInput->toPlainText().toStdString();
    int age = stoi(this->ui->ageInput->text().toStdString());
    int weight = stoi(this->ui->weightInput->text().toStdString());
    int height = stoi(this->ui->heightInput->text().toStdString());
    int minAge = stoi(this->ui->minAgeInput->text().toStdString());
    int maxAge = stoi(this->ui->maxAgeInput->text().toStdString());
    int minHeight = stoi(this->ui->minHeightInput->text().toStdString());
    int maxHeight = stoi(this->ui->maxHeightInput->text().toStdString());
    int minWeight = stoi(this->ui->minWeightInput->text().toStdString());
    int maxWeight = stoi(this->ui->maxWeightInput->text().toStdString());
    bool isMan = (this->ui->genderInput->currentIndex() == 0);
    Person *person = new Person(isMan, name, hobby, age, weight, height, minAge, maxAge, minHeight, maxHeight, minWeight, maxWeight);
    persons.push_back(person);
    hideAddPerson();
    showLists();
}

void mainwindow::showLists() {
    this->ui->menList->clear();
    this->ui->womenList->clear();
    this->ui->menList->update();
    this->ui->womenList->update();
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->isMan1()){
            QListWidgetItem *man = new QListWidgetItem();
            man->setText(QString::fromStdString(persons[i]->getDescription()));
            this->ui->menList->addItem(man);
            this->ui->menList->update();
        }
        else{
            QListWidgetItem *woman = new QListWidgetItem();
            woman->setText(QString::fromStdString(persons[i]->getDescription()));
            this->ui->womenList->addItem(woman);
            this->ui->womenList->update();
        }
    }
    showMatchedLists();
}

void mainwindow::onManClicked(QListWidgetItem *man) {
    int ind = this->ui->menList->row(man);
    int cur = -1;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->isMan1())
            cur++;
        if(cur == ind) {
            selectedPerson = persons[i];
            break;
        }
    }
    showMatchedLists();
}

void mainwindow::onWomanClicked(QListWidgetItem *woman) {
    int ind = this->ui->womenList->row(woman);
    int cur = -1;
    for(int i = 0; i < persons.size(); i++){
        if(!persons[i]->isMan1())
            cur++;
        if(cur == ind) {
            selectedPerson = persons[i];
            break;
        }
    }
    showMatchedLists();
}

void mainwindow::showMatchedLists() {
    this->ui->pairsList->clear();
    this->ui->pairsList->update();
    if(selectedPerson == nullptr)
        return;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->isMatched(selectedPerson) && selectedPerson->isMatched(persons[i])){
            QListWidgetItem *person = new QListWidgetItem();
            person->setText(QString::fromStdString(persons[i]->getDescription()));
            this->ui->pairsList->addItem(person);
            this->ui->pairsList->update();
        }
    }
}

void mainwindow::makePair() {
    auto items = this->ui->pairsList->selectedItems();
    if(items.size() == 0)
        return;
    int ind = this->ui->pairsList->row(items[0]);

    int cur = -1;
    Person *anotherPerson;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i]->isMatched(selectedPerson) && selectedPerson->isMatched(persons[i])){
            cur++;
        }
        if(cur == ind){
            persons.erase(std::find(persons.begin(), persons.end(), persons[i]));
            persons.erase(std::find(persons.begin(), persons.end(), selectedPerson));
            break;
        }
    }
    showLists();
}
