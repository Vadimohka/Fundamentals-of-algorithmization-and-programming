#include "deck.h"

Deck::Deck(QObject *parent)
    : QGraphicsScene{parent}
{
    setSceneRect(0,0,635,330);
    PlayerEnergy = new Energy();
    PlayerEnergy->upEnergy(3);
    QPixmap pixmap(":/prefix1/ForDeckinGame2.tiff");
    QPixmap scaledPixmap = pixmap.scaled(637, 637, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
    this->addItem(pixmapItem);
}

Deck::~Deck()
{
    delete this;
}

void Deck::addCard(Card *card){
    deck.push_back(card);
    noUsedCards.push_back(card);
    card->getPlayerEnergy(this->PlayerEnergy);
    connect(card,&Card::signalClickType,this,&Deck::clickToCard);
    this->activity=0;
    PlayerDeckUpdateSlot();
}

Card *Deck::subCard(int i){return deck[i];}

void Deck::addCardsToGame()
{
    initTenCardsInDeck();
    int s =deck.size();
    for(int i=0;i<s;i++)
    {
        connect(deck[i],&Card::signalClickType,this,&Deck::clickToCard);
    }
    for(int i = 0;i<s;i++){
        noUsedCards.push_back(deck[i]);
    }
    shuffleDeck();
    addToActiveScene();
    this->update();
}

void Deck::usedToNoUsed()
{
    int size = usedCards.size();
    for(int i =0 ; i<size;i++){
        noUsedCards.push_back(usedCards.front());
        usedCards.pop_front();
    }
    qDebug() << "in usedtonoused";
}

Card *Deck::getCardFromA(QVector<Card *> A, Card *card)
{
    int a = A.size();
    for(int i = 0; i < a;i++)
    {
        if(card==A[i])
        {
            card = A[i];
            this->removeItem(A[i]);
            qDebug() << "remove A["<< i << "]";
            A.remove(i);
            return card;
        }
    }
    return nullptr;
}

void Deck::noUsedToActive()
{
    shuffleDeck();
    for(int i =0;i<5;i++){
        activeCards.push_back(noUsedCards.front());
        noUsedCards.pop_front();
    }
    qDebug() << "in nousedtoactive";
}

void Deck::addToActiveScene()
{
    int x = 10, y = 20, w = 120, h = 240;
    for(int i = 0; i < 5; i++)
    {
        noUsedCards[i]->getCoordinate(x, y, w, h);
        numOfActiveCard++;
        addItem(noUsedCards[i]);
        x += 125;
    }
    this->update();
}

void Deck::clickToCard(Card *card)
{
    if(PlayerEnergy->setEnergy() >= 0 && activity==1){
        removeItem(card);
        numOfActiveCard--;
        emit dropSignal(card);
    }
    emit forUpdateView();
}

void Deck::PlayerDeckUpdateSlot()//knopka
{
    for(int i =0; i<noUsedCards.size();i++)
    {
        removeItem(noUsedCards[i]);
    }
    shuffleDeck();
    addToActiveScene();
}

void Deck::initTenCardsInDeck()
{
    for(int i=0; i<10; i++)
    {
        if(i%2==0)
            deck.push_back(GenerateCard(AttackT));
        else
            if(i%3==0)
                deck.push_back(GenerateCard(DefenceT));
            else
                if(i%7==0)
                    deck.push_back(GenerateCard(HealtPointT));
                else
                    if(i%5==0)
                        deck.push_back(GenerateCard(EnergyT));
                    else if(i==1)
                        deck.push_back(GenerateCard(CombinationT));
    }
}

Card* Deck::GenerateCard(int num)
{
    Card *temp = new Card(new QImage(),new Damage(),new Defence(), new Health(), new Energy());
    QImage *i = new QImage();
    Damage *dam = new Damage();
    Defence *def =  new Defence();
    Health *hp = new Health();
    Energy *en = new Energy();
    Energy *enCost = new Energy();
    switch (num)
    {
    case AttackT:{
        dam->upDamage(13);
        temp->getType(AttackT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case DefenceT:{
        def->addDef(8);
        temp->getType(DefenceT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case HealtPointT:{
        temp->getType(HealtPointT);
        hp->addHP(7);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case EnergyT:{
        temp->getType(EnergyT);

        en->upEnergy(2);
        enCost->upEnergy(0);
        break;
    }
    case EffectT:{
        dam->upDamage(7);
        hp->addHP(7);
        def->addDef(3);
        temp->getType(EffectT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case CombinationT:{
        dam->upDamage(5);
        hp->addHP(1);
        def->addDef(1);
        temp->getType(CombinationT);

        en->upEnergy(1);
        enCost->upEnergy(0);
        break;
    }
    }
    temp->getDamage(dam);
    temp->getImage(i);
    temp->getDefence(def);
    temp->getEnergy(en);
    temp->getHp(hp);
    temp->getEnergyCost(enCost);
    temp->getPlayerEnergy(this->PlayerEnergy);
    return temp;
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(noUsedCards.begin(), noUsedCards.end(), g);
}
