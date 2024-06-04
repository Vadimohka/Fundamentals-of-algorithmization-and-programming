#include "dialogshowcards.h"
#include "ui_dialogshowcards.h"

DialogShowCards::DialogShowCards(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogShowCards)
{
    ui->setupUi(this);
    graphicsView= new QGraphicsView;
    scene = new QGraphicsScene();
    setWindowTitle("Ваши карты");
}

void DialogShowCards::enableCardsActivity()
{
    for(int i =0;i<deck.size();i++)
        deck[i]->setEnabled(1);
}

DialogShowCards::~DialogShowCards()
{
    enableCardsActivity();
    delete ui;
}

void DialogShowCards::getPlayerAndDeck(Player *p){
    this->player=p;
    deck=*player->deck->setNoUsedDeck();
    for(int i =0;i<deck.size();i++)
    {
        energyCost.push_back(deck[i]->setIEnergyCost());
        HP.push_back(deck[i]->setIHP());
        Attack.push_back(deck[i]->setIDamage());
    }
    BittonSort::bitonicsort(HP);
    BittonSort::bitonicsort(energyCost);
    BittonSort::bitonicsort(Attack);
}

void DialogShowCards::on_pushButton_HP_clicked()
{
    removeElements();
    paintElements(1);
}

void DialogShowCards::on_pushButton_Energy_clicked()
{
    removeElements();
    paintElements(2);
}


void DialogShowCards::on_pushButton_Attack_clicked()
{
    removeElements();
    paintElements(3);
}

void DialogShowCards::open()
{
    this->showNormal();
    paintElements(0);
}

void DialogShowCards::paintElements(int num)
{
    this->setMouseTracking(0);
    int x = 10, y = 20, w = 120, h = 240;
    switch (num){
        case 0:{
        for(int i = 0; i < deck.size(); i++)
        {
            deck[i]->setEnabled(0);
            deck[i]->getCoordinate(x, y, w, h);
            scene->addItem(deck[i]);
            x += 125;
        }
        break;
        }
            case 1:{
            for(int i = 0; i < deck.size(); i++)
            {
                for(int j =0 ; j<deck.size();j++)
                {
                    qDebug() << "i =" << i << "j =" << j;
                    if(HP[i]==deck[j]->setIHP() && deck[j]->scene()==nullptr)
                        {
                        deck[j]->setEnabled(0);
                        deck[j]->getCoordinate(x, y, w, h);
                        scene->addItem(deck[j]);
                        x += 125;
                        qDebug() << "addItem";
                    }
                }

            }
            break;
        }
            case 2:{
            for(int i = 0; i < deck.size(); i++)
            {
                for(int j =0 ; j<deck.size();j++)
                {
                    if(energyCost[i]==deck[j]->setIEnergyCost() && deck[j]->scene()==nullptr){
                        deck[j]->setEnabled(0);
                        deck[j]->getCoordinate(x, y, w, h);
                        scene->addItem(deck[j]);
                        x += 125;
                    }
                }
            }
            break;
        }
            case 3:{
            for(int i = 0; i < deck.size(); i++)
            {
                for(int j =0 ; j<deck.size();j++)
                {
                    if(Attack[i]==deck[j]->setIDamage() && deck[j]->scene()==nullptr){
                        deck[j]->setEnabled(0);
                        deck[j]->getCoordinate(x, y, w, h);
                        scene->addItem(deck[j]);
                        x += 125;
                    }
                }
            }
                break;
        }
    }
    scene->update();
    ui->graphicsView->setScene(scene);
    this->update();
}

void DialogShowCards::removeElements()
{
    for(int i = 0; i < deck.size(); i++)
    {
        scene->removeItem(deck[i]);
    }
    scene->update();
    ui->graphicsView->setScene(scene);
    this->update();

}

