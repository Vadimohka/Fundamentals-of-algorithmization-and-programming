#include "player.h"

Player::Player()
{
    connect(lvlUpForm, &LvlUpForm::Choose, this, &Player::handleMod);
}

Player::Player(QString name,
               QString race,
               QString gameClass,
               int health,
               int str,
               int dex,
               int con,
               int intel,
               int wis,
               int cha)
    : gameClass(gameClass)
    , healDice(health - con)
{
    strength = str;
    dexterity = dex;
    constitution = con;
    intellegence = intel;
    wisdom = wis;
    charisma = cha;
    this->name = name;
    this->race = race;
    this->health = health;
    maxHealth = health;

    int var = DEF_EXP;
    for (int i = 0; i < MAX_LVL; i++) {
        maxExp.push_back(var);
        var += DEF_EXP;
    }
    connect(lvlUpForm, &LvlUpForm::Choose, this, &Player::handleMod);
}

void Player::setup(Player *other)
{
    gameClass = other->gameClass;
    strength = other->strength;
    dexterity = other->dexterity;
    constitution = other->constitution;
    intellegence = other->intellegence;
    wisdom = other->wisdom;
    charisma = other->charisma;
    name = other->name;
    race = other->race;
    health = other->health;
    healDice = health - constitution;
    maxHealth = health;
    inventory = other->inventory;
    defence = other->defence;
    damage = other->damage;
    exp = 0;
    lvl = 1;

    int var = DEF_EXP;
    for (int i = 0; i < MAX_LVL; i++) {
        maxExp.push_back(var);
        var += DEF_EXP;
    }
}

void Player::setup(QString name,
                   QString race,
                   QString gameClass,
                   int health,
                   int str,
                   int dex,
                   int con,
                   int intel,
                   int wis,
                   int cha)
{
    this->gameClass = gameClass;
    strength = str;
    dexterity = dex;
    constitution = con;
    intellegence = intel;
    wisdom = wis;
    charisma = cha;
    this->name = name;
    this->race = race;
    this->health = health;
    healDice = health - con;
    maxHealth = health;
    exp = 0;
    lvl = 1;

    int var = DEF_EXP;
    for (int i = 0; i < MAX_LVL; i++) {
        maxExp.push_back(var);
        var += DEF_EXP;
    }
}

QString Player::getGameClass()
{
    return gameClass;
}

void Player::setGameClass(QString gameClass)
{
    this->gameClass = gameClass;
}

int Player::getLvl()
{
    return lvl;
}

int Player::getExp()
{
    return exp;
}

int Player::getMaxExp()
{
    return maxExp[lvl - 1];
}

void Player::useItem(int i)
{
    if (i < inventory.size()) {
        if (inventory[i]->getType() == DAMAGE || inventory[i]->getType() == SPELL) {
            damage = inventory[i]->use();
        } else if (inventory[i]->getType() == DEFENCE) {
            defence = inventory[i]->use();
            if (defence <= 15) {
                defence += dexterity;
            }
        } else if (inventory[i]->getType() == HEAL) {
            health += inventory[i]->use();
            if (health > maxHealth) {
                health = maxHealth;
            }
        }
    }
}

void Player::addExp(int incr)
{
    exp += incr;
    while (exp >= maxExp[lvl - 1]) {
        exp -= maxExp[lvl - 1];
        lvl++;
        lvlUpForm->show();
    }
}

void Player::handleMod(int mod)
{
    setMod(mod, getMod(mod) + 1);
    maxHealth += QRandomGenerator::global()->bounded(1, healDice + 1);
    health = maxHealth;
    emit sendText("Ваша характеристика №" + QString::number(mod + 1) + " повысилась на 1",
                  Qt::darkGreen);
}
