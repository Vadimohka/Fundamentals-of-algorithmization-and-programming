#include "creationform.h"
#include "ui_creationform.h"

CreationForm::CreationForm(World *world, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationForm)
    , world(world)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
}

CreationForm::~CreationForm()
{
    delete ui;
}

void CreationForm::on_createButton_clicked()
{
    QString name = ui->name->text();
    QString race = ui->race->currentText();
    QString gameClass = ui->gameClass->currentText();
    int str = 0, dex = 0, con = 0, intel = 0, wis = 0, cha = 0, health = 0;
    player->inventory.clear();

    str = QRandomGenerator::global()->bounded(-2, 3);
    dex = QRandomGenerator::global()->bounded(-2, 3);
    con = QRandomGenerator::global()->bounded(-2, 3);
    intel = QRandomGenerator::global()->bounded(-2, 3);
    wis = QRandomGenerator::global()->bounded(-2, 3);
    cha = QRandomGenerator::global()->bounded(-2, 3);

    if (gameClass == "Варвар") {
        health = D12;
        str = 2;
        dex = 2;
        intel = -2;
        player->inventory.push_back(world->getItem(15));
        player->inventory.push_back(world->getItem(4));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Бард") {
        health = D8;
        cha = 2;
        dex = 1;
        con = 0;
        player->inventory.push_back(world->getItem(27));
        player->inventory.push_back(world->getItem(1));
        player->inventory.push_back(world->getItem(36));

    } else if (gameClass == "Жрец") {
        health = D8;
        con = 1;
        intel = 1;
        cha = -2;
        player->inventory.push_back(world->getItem(32));
        player->inventory.push_back(world->getItem(7));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Друид") {
        health = D8;
        wis = 2;
        str = 0;
        dex = -1;
        player->inventory.push_back(world->getItem(32));
        player->inventory.push_back(world->getItem(5));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Воин") {
        health = D10;
        str = 2;
        intel = -3;
        dex = -1;
        player->inventory.push_back(world->getItem(20));
        player->inventory.push_back(world->getItem(9));
        player->inventory.push_back(world->getItem(36));

    } else if (gameClass == "Монах") {
        health = D8;
        wis = 1;
        dex = 1;
        cha = -2;
        player->inventory.push_back(world->getItem(11));
        player->inventory.push_back(world->getItem(2));
        player->inventory.push_back(world->getItem(36));

    } else if (gameClass == "Паладин") {
        health = D10;
        con = 1;
        wis = 2;
        dex = -3;
        player->inventory.push_back(world->getItem(17));
        player->inventory.push_back(world->getItem(8));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Следопыт") {
        health = D10;
        dex = 2;
        intel = 1;
        cha = -3;
        player->inventory.push_back(world->getItem(25));
        player->inventory.push_back(world->getItem(3));
        player->inventory.push_back(world->getItem(36));

    } else if (gameClass == "Плут") {
        health = D8;
        dex = 4;
        str = 1;
        wis = -3;
        con = 0;
        player->inventory.push_back(world->getItem(12));
        player->inventory.push_back(world->getItem(1));
        player->inventory.push_back(world->getItem(36));

    } else if (gameClass == "Чародей") {
        health = D6;
        con = 1;
        intel = 1;
        dex = 1;
        str = -2;
        player->inventory.push_back(world->getItem(35));
        player->inventory.push_back(world->getItem(3));
        player->inventory.push_back(world->getItem(36));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Колдун") {
        health = D8;
        player->inventory.push_back(world->getItem(29));
        player->inventory.push_back(world->getItem(5));
        player->inventory.push_back(world->getItem(37));

    } else if (gameClass == "Волшебник") {
        health = D6;
        intel = 3;
        dex = -2;
        str = -1;
        player->inventory.push_back(world->getItem(34));
        player->inventory.push_back(world->getItem(8));
        player->inventory.push_back(world->getItem(38));
        player->inventory.push_back(world->getItem(37));
    }

    //раса
    if (race == "Человек") {
    } else if (race == "Дварф") {
        str += 2;
        con += 2;
    } else if (race == "Эльф") {
        dex += 2;
        intel += 1;
        wis += 1;
    } else if (race == "Полурослик") {
        dex += 2;
        con += 1;
    } else if (race == "Драконорожденный") {
        str += 2;
        cha += 1;
    } else if (race == "Гном") {
        intel += 2;
        con += 1;
    } else if (race == "Полуэльф") {
        cha += 2;
    } else if (race == "Полуорк") {
        str += 2;
        con += 1;
    } else if (race == "Тифлинг") {
        intel += 1;
        cha += 2;
    }
    health += con;

    player->inventory.push_back(world->getItem(QRandomGenerator::global()->bounded(41, 46)));

    player->setHealth(health);
    player->setGameClass(gameClass);
    player->setRace(race);
    player->setName(name);
    player->setMod(STRENGTH, str);
    player->setMod(DEXTERITY, dex);
    player->setMod(CONSTITUTION, con);
    player->setMod(INTELLEGENCE, intel);
    player->setMod(WISDOM, wis);
    player->setMod(CHARISMA, cha);

    player->useItem(0);
    player->useItem(1);

    emit Completed(player);
}
