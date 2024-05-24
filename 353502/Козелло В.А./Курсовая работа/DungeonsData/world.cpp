#include "world.h"

World::World(Player *player, Combat *combat)
{   
    this->player = player;
    this->combat = combat;

    QString filePath = "../Sources/JSONS/places.json";
    places = parsePlaces(filePath);
    entities = parseEntities("../Sources/JSONS/entities.json");
    items = parseItems("../Sources/JSONS/items.json");

    currentPlace = places["Распутье"];

    connect(combat, &Combat::fightEnd, this, &World::handleFightEnd);
}

World::World() = default;

Item *World::getItem(int id)
{
    if (items.contains(id)) {
        return items.value(id);
    } else {
        return new Item();
    }
}

void World::clearWorld()
{
    currentPlace = places["Распутье"];
    for (auto &value : defeated) {
        value = false;
    }
    isListen = false;
    state = CREATION;
}

void World::goToPlace(QString place)
{
    bool isNumber = false;
    bool isExists = false;
    int var = place.toInt(&isNumber);
    if (isNumber && var > 0 && var <= currentPlace->exits.count()) {
        isExists = true;
    }
    if (isExists) {
        place = currentPlace->exits[var - 1];
        if (places[place]->lvl <= player->getLvl()) {
            currentPlace = places[place];

            if (places[place]->type != ENVIRONMENT) {
                emit sendText(currentPlace->description + "\n", Qt::black);
                QString info;
                emit sendText("Дороги в места:\n", Qt::darkBlue);
                for (int i = 0; i < currentPlace->exits.size(); i++) {
                    info.append(QString::number(i + 1) + " " + currentPlace->exits[i] + " (Уровень "
                                + QString::number(places[currentPlace->exits[i]]->lvl) + ")\n");
                }
                emit sendText(info, Qt::black);
                info.clear();
                emit sendText("Список NPC:\n", Qt::darkBlue);
                for (int i = 0; i < currentPlace->npcs.size(); i++) {
                    if (!defeated[currentPlace->npcs[i]]) {
                        info.append(QString::number(i + 1) + " " + currentPlace->npcs[i] + "\n");
                    }
                }
                emit sendText(info, Qt::black);
            } else {
                int randNum = QRandomGenerator::global()->bounded(0, 2);
                if (randNum) {
                    startEvent(TRAP_EVENT);
                } else {
                    QString npc;
                    bool flag = true;
                    for (int i = 0; i < currentPlace->npcs.size(); i++) {
                        npc = currentPlace->npcs[i];
                        if (!defeated[npc]) {
                            emit blockInput(true);
                            combat->start(entities[npc]);
                            state = FIGHT;
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        emit sendText(currentPlace->description + "\n", Qt::black);
                        QString info;
                        emit sendText("Дороги в места:\n", Qt::darkBlue);
                        for (int i = 0; i < currentPlace->exits.size(); i++) {
                            info.append(
                                QString::number(i + 1) + " " + currentPlace->exits[i] + " (Уровень "
                                + QString::number(places[currentPlace->exits[i]]->lvl) + ")\n");
                        }
                        emit sendText(info, Qt::black);
                    }
                }
            }

        } else {
            emit sendText("У вас недостаточно уровней, чтобы добраться до этого места\n",
                          Qt::darkYellow);
        }
    } else {
        emit sendText("Ведите пожалуйста число соответствующее месту\n", Qt::red);
    }
}

void World::talkToNPC(QString npc)
{
    bool isNumber = false;
    bool isExists = false;
    int var = npc.toInt(&isNumber);
    if (isNumber && var > 0 && var <= currentPlace->npcs.count()) {
        isExists = true;
    }
    if (isExists && currentPlace->type != ENVIRONMENT) {
        npc = currentPlace->npcs[var - 1];
        if (!defeated[npc]) {
            state = DIALOG;
            currentEntity = QString::number(var - 1);
            dialog = parseDialog("../Sources/JSONS/"
                                 + entities[currentPlace->npcs[var - 1]]->getRace() + ".json");
            startDialog();
        } else {
            emit sendText(npc + " больше нет\n", Qt::black);
        }
    } else {
        emit sendText("Такого NPC не существует или вы не можете до него добраться\n", Qt::red);
    }
}

void World::fightToNPC(QString npc)
{
    bool isNumber = false;
    bool isExists = false;
    int var = npc.toInt(&isNumber);
    if (isNumber && var > 0 && var <= currentPlace->npcs.count()) {
        isExists = true;
    }
    if (isExists && currentPlace->type != ENVIRONMENT) {
        npc = currentPlace->npcs[var - 1];
        if (!defeated[npc]) {
            emit blockInput(true);
            combat->start(entities[npc]);
            state = FIGHT;
        } else {
            emit sendText(npc + " больше нет\n", Qt::black);
        }
    } else {
        emit sendText("Такого NPC не существует или вы не можете до него добраться\n", Qt::red);
    }
}

void World::startDialog()
{
    findPossibleWays();
    dialog.nodes[0].was = true;
    currentNode = &dialog.nodes[0];

    emit sendText(currentPlace->npcs[currentEntity.toInt()] + ":\n", Qt::darkBlue);
    emit sendText(dialog.nodes[0].dialog + "\n", Qt::black);
    emit sendText("\nВарианты:\n", Qt::darkBlue);
    for (const int var : possibleWays) {
        emit sendText(QString::number(var) + " " + dialog.nodes[var].option + "\n", Qt::black);
    }
}

void World::findPossibleWays()
{
    possibleWays.clear();
    checkWay(0);
}

void World::checkWay(int id)
{
    for (const int &node : dialog.nodes[id].options) {
        if (dialog.nodes[node].was || dialog.nodes[node].option == "") {
            dialog.nodes[node].was = true;
            checkWay(node);
        } else if (!possibleWays.contains(node)) {
            possibleWays.append(node);
        }
    }
}

void World::chooseOption(QString option, bool VIP)
{
    bool isNumber = false;
    bool isExists = false;
    int var = option.toInt(&isNumber);
    if (isNumber && var > 0 && possibleWays.contains(var)) {
        isExists = true;
    }
    if (isExists || VIP) {
        currentNode = &dialog.nodes[var];

        if (!dialog.nodes[var].event) {
            dialog.nodes[var].was = true;

            emit sendText(currentPlace->npcs[currentEntity.toInt()] + ":\n", Qt::darkBlue);
            emit sendText(dialog.nodes[var].dialog + '\n', Qt::black);

            findPossibleWays();
            if (possibleWays.empty()) {
                state = FREE;
                defeated[currentPlace->npcs[currentEntity.toInt()]] = true;
                emit sendText("Диолог закончился\n", Qt::black);
            } else {
                emit sendText("\nВарианты:\n", Qt::darkBlue);
                for (const int var : possibleWays) {
                    emit sendText(QString::number(var) + " " + dialog.nodes[var].option + "\n",
                                  Qt::black);
                }
            }

        } else {
            startEvent(dialog.nodes[var].event);
        }
    } else {
        emit sendText("Ведите пожалуйста число соответствующее выбору\n", Qt::red);
        for (const int var : possibleWays) {
            emit sendText(QString::number(var) + " " + dialog.nodes[var].option + "\n", Qt::black);
        }
    }
}

void World::startEvent(int event)
{
    emit blockInput(true);
    currentEvent = event;

    if (event == FIGHT_EVENT) {
        state = FIGHT;
        fightToNPC(QString::number(currentEntity.toInt() + 1));

    } else if (event == PRIZE_EVENT) {
        int randomNum = QRandomGenerator::global()->bounded(1, 5);

        if (randomNum == 1) {
            randomNum = QRandomGenerator::global()->bounded(ARMOR_ID_START, ARMOR_ID_FINISH + 1);

        } else if (randomNum == 2) {
            if (player->getGameClass() == "Варвар" || player->getGameClass() == "Воин"
                || player->getGameClass() == "Паладин" || player->getGameClass() == "Следопыт"
                || player->getGameClass() == "Плут") {
                randomNum = QRandomGenerator::global()->bounded(WEAPON_ID_START, SPELL_ID_START);
            } else {
                randomNum = QRandomGenerator::global()->bounded(WEAPON_ID_START,
                                                                WEAPON_ID_FINISH + 1);
            }

        } else if (randomNum == 3) {
            randomNum = QRandomGenerator::global()->bounded(POTION_ID_START, POTION_ID_FINISH + 1);

        } else {
            randomNum = QRandomGenerator::global()->bounded(TRINKET_ID_START, TRINKET_ID_FINISH + 1);
        }

        if (state == DIALOG) {
            currentNode->was = true;
            player->inventory.push_back(items[randomNum]);

            emit sendText(currentPlace->npcs[currentEntity.toInt()] + ":\n", Qt::darkBlue);
            emit sendText(currentNode->dialog + '\n', Qt::black);
            emit sendText("Вы получили предмет ", Qt::black);
            emit sendText(items[randomNum]->getName() + '\n', Qt::darkGreen);
            player->addExp(200);
            emit sendText("Вы получили ", Qt::black);
            emit sendText("200 опыта\n", Qt::magenta);

            findPossibleWays();
            if (possibleWays.empty()) {
                state = FREE;
                defeated[currentPlace->npcs[currentEntity.toInt()]] = true;
                emit sendText("\nДиолог закончился\n", Qt::black);
            } else {
                emit sendText("\nВарианты:\n", Qt::darkBlue);
                for (const int var : possibleWays) {
                    emit sendText(QString::number(var) + " " + dialog.nodes[var].option + "\n",
                                  Qt::black);
                }
            }
        } else {
            player->inventory.push_back(items[randomNum]);
            emit sendText("Вы получили предмет ", Qt::black);
            emit sendText(items[randomNum]->getName() + '\n', Qt::darkGreen);
        }
        emit blockInput(false);

    } else if (event == END_EVENT) {
        state = FREE;
        defeated[currentPlace->npcs[currentEntity.toInt()]] = true;
        emit sendText(currentPlace->npcs[currentEntity.toInt()] + ":\n", Qt::darkBlue);
        emit sendText(currentNode->dialog + '\n', Qt::black);
        emit sendText("Диолог закончился\n", Qt::darkRed);
        emit blockInput(false);

    } else if (event == STRENGTH_EVENT) {
        emit sendText("Бросьте D20 по силе\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == DEXTERITY_EVENT) {
        emit sendText("Бросьте D20 по ловкости\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == CONSTITUTION_EVENT) {
        emit sendText("Бросьте D20 по выносливости\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == INTELLEGENCE_EVENT) {
        emit sendText("Бросьте D20 по интеллекту\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == CHARISMA_EVENT) {
        emit sendText("Бросьте D20 по харизме\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == WISDOM_EVENT) {
        emit sendText("Бросьте D20 по мудрости\n", Qt::black);
        isListen = true;
        needRoll = D20;

    } else if (event == TRAP_EVENT) {
        if (!isListen) {
            emit sendText("Вы попали в ловушку!\nБросьте D20 по выносливости\n", Qt::black);
            needRoll = D20;
            isListen = true;
        } else {
            emit sendText("Вам не удалось спастись из ловушки\nБросьте D4 на урон себе\n",
                          Qt::black);
            needRoll = D4;
        }
    }
}

QMap<QString, Place *> World::parsePlaces(const QString &filePath)
{
    QMap<QString, Place *> placesMap;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл";
        return placesMap;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (!doc.isArray()) {
        qDebug() << "Корневой элемент не является массивом";
        return placesMap;
    }

    QJsonArray placeArray = doc.array();
    for (const auto &placeValue : placeArray) {
        if (!placeValue.isObject()) {
            qDebug() << "Элемент места не является объектом";
            continue;
        }

        QJsonObject placeObject = placeValue.toObject();

        Place *place = new Place;
        place->name = placeObject.value("name").toString();
        place->description = placeObject.value("description").toString();
        place->type = placeObject.value("type").toInt();
        place->lvl = placeObject.value("lvl").toInt();

        QJsonArray exitsArray = placeObject.value("exits").toArray();
        for (const auto &exitValue : exitsArray) {
            if (exitValue.isString()) {
                place->exits.append(exitValue.toString());
            }
        }

        QJsonArray npcsArray = placeObject.value("npcs").toArray();
        for (const auto &npcValue : npcsArray) {
            if (npcValue.isString()) {
                place->npcs.append(npcValue.toString());
            }
        }

        placesMap.insert(place->name, place);
    }

    file.close();
    return placesMap;
}

QMap<int, Item *> World::parseItems(const QString &filePath)
{
    QMap<int, Item *> itemMap;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл";
        return itemMap;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (!doc.isArray()) {
        qDebug() << "Корневой элемент не является массивом";
        return itemMap;
    }

    QJsonArray itemArray = doc.array();
    for (const auto &itemValue : itemArray) {
        if (!itemValue.isObject()) {
            qDebug() << "Элемент места не является объектом";
            continue;
        }

        QJsonObject itemObject = itemValue.toObject();

        Item *item;
        int type = itemObject.value("type").toInt();
        if (type == DEFENCE) {
            Armor *armor = new Armor;
            armor->setId(itemObject.value("id").toInt());
            armor->setName(itemObject.value("name").toString());
            armor->setDescription(itemObject.value("description").toString());
            armor->setType(itemObject.value("type").toInt());
            armor->setDef(itemObject.value("defence").toInt());
            item = armor;

        } else if (type == DAMAGE || type == SPELL) {
            Weapon *weap = new Weapon;
            weap->setId(itemObject.value("id").toInt());
            weap->setName(itemObject.value("name").toString());
            weap->setDescription(itemObject.value("description").toString());
            weap->setType(itemObject.value("type").toInt());
            weap->setDam(itemObject.value("damage").toInt());
            item = weap;

        } else if (type == HEAL) {
            Potion *potion = new Potion;
            potion->setId(itemObject.value("id").toInt());
            potion->setName(itemObject.value("name").toString());
            potion->setDescription(itemObject.value("description").toString());
            potion->setType(itemObject.value("type").toInt());
            potion->setHeal(itemObject.value("heal").toInt());
            item = potion;

        } else {
            item = new Item;
            item->setId(itemObject.value("id").toInt());
            item->setName(itemObject.value("name").toString());
            item->setDescription(itemObject.value("description").toString());
            item->setType(itemObject.value("type").toInt());
        }

        itemMap.insert(item->getId(), item);
    }

    file.close();
    return itemMap;
}

QMap<QString, Entity *> World::parseEntities(const QString &filePath)
{
    QMap<QString, Entity *> entityMap;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл";
        return entityMap;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (!doc.isArray()) {
        qDebug() << "Корневой элемент не является массивом";
        return entityMap;
    }

    QJsonArray entityArray = doc.array();
    for (const auto &entityValue : entityArray) {
        if (!entityValue.isObject()) {
            qDebug() << "Элемент места не является объектом";
            continue;
        }

        QJsonObject placeObject = entityValue.toObject();

        Entity *entity = new Entity;
        entity->setName(placeObject.value("name").toString());
        entity->setRace(placeObject.value("race").toString());
        entity->setHealth(placeObject.value("health").toInt());
        entity->setMod(STRENGTH, placeObject.value("str").toInt());
        entity->setMod(DEXTERITY, placeObject.value("dex").toInt());
        entity->setMod(CONSTITUTION, placeObject.value("con").toInt());
        entity->setMod(INTELLEGENCE, placeObject.value("intel").toInt());
        entity->setMod(WISDOM, placeObject.value("wis").toInt());
        entity->setMod(CHARISMA, placeObject.value("cha").toInt());
        entity->setDanger(placeObject.value("danger").toInt());
        entity->setDefence(placeObject.value("defence").toInt());
        entity->setDamage(placeObject.value("damage").toInt());

        entityMap.insert(entity->getName(), entity);
        defeated.insert(entity->getName(), false);
    }

    file.close();
    return entityMap;
}

Dialog World::parseDialog(const QString &filePath)
{
    Dialog dialog;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл";
        return dialog;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (!doc.isObject()) {
        qDebug() << "Корневой элемент не является объектом";
        return dialog;
    }

    QJsonObject rootObject = doc.object();
    dialog.name = rootObject.value("name").toString();

    QJsonArray nodesArray = rootObject.value("dialog_nodes").toArray();
    for (const auto &nodeValue : nodesArray) {
        if (!nodeValue.isObject()) {
            qDebug() << "Элемент узла диалога не является объектом";
            continue;
        }

        QJsonObject nodeObject = nodeValue.toObject();

        Dialog::DialogNode dialogNode;
        dialogNode.id = nodeObject.value("id").toInt();
        dialogNode.option = nodeObject.value("option").toString();
        dialogNode.dialog = nodeObject.value("dialog").toString();
        dialogNode.event = nodeObject.value("event").toInt();

        QJsonArray optionsArray = nodeObject.value("options").toArray();
        for (const auto &optionValue : optionsArray) {
            if (optionValue.isDouble()) {
                dialogNode.options.append(optionValue.toInt());
            }
        }

        dialog.nodes.append(dialogNode);
    }

    file.close();
    return dialog;
}

void World::handleCommand(QString command)
{
    if (state == FREE) {
        if (command.mid(0, 3) == "/go") {
            QString place = command.mid(4);
            goToPlace(place);

        } else if (command == "/i") {
            emit sendText(currentPlace->description + "\n", Qt::black);
            QString info;
            emit sendText("Дороги в места:\n", Qt::darkBlue);
            for (int i = 0; i < currentPlace->exits.size(); i++) {
                info.append(QString::number(i + 1) + " " + currentPlace->exits[i] + " (Уровень "
                            + QString::number(places[currentPlace->exits[i]]->lvl) + ")\n");
            }
            emit sendText(info, Qt::black);
            info.clear();
            if (currentPlace->type != ENVIRONMENT) {
                emit sendText("Список NPC:\n", Qt::darkBlue);
                for (int i = 0; i < currentPlace->npcs.size(); i++) {
                    if (!defeated[currentPlace->npcs[i]]) {
                        info.append(QString::number(i + 1) + " " + currentPlace->npcs[i] + "\n");
                    }
                }
            }
            emit sendText(info, Qt::black);

        } else if (command.mid(0, 2) == "/t") {
            QString npc = command.mid(3);
            talkToNPC(npc);

        } else if (command.mid(0, 2) == "/f") {
            QString npc = command.mid(3);
            fightToNPC(npc);

        } else if (command == "/create") {
            emit sendText("Вы уже создали персонажа\n", Qt::red);

        } else {
            emit sendText("Команда не найдена\n", Qt::red);
        }

    } else if (state == CREATION) {
        if (command == "/create") {
            emit createPlayer();
            state = FREE;
        } else {
            emit sendText("Команда не найдена\n", Qt::red);
        }
    } else if (state == DIALOG) {
        if (command.mid(0, 2) == "/c") {
            QString option = command.mid(3);
            chooseOption(option, false);

        } else if (command.mid(0, 2) == "/f") {
            state = FIGHT;
            fightToNPC(QString::number(currentEntity.toInt() + 1));

        } else if (command.mid(0, 4) == "/end") {
            state = FREE;
            defeated[currentPlace->npcs[currentEntity.toInt()]] = true;
            emit sendText("Диолог закончился\n", Qt::black);

        } else if (command.mid(0, 2) == "/i") {
            emit sendText("\nВарианты:\n", Qt::darkBlue);
            for (const int var : possibleWays) {
                emit sendText(QString::number(var) + " " + dialog.nodes[var].option + "\n",
                              Qt::black);
            }

        } else {
            emit sendText("Команда не найдена\n", Qt::red);
        }
    }
}

void World::handleFightEnd(QString name)
{
    defeated[name] = true;
    state = FREE;
    if (player->isAlive() && entities[name]->getDanger() != 0) {
        startEvent(PRIZE_EVENT);
    }
    emit blockInput(false);
}

void World::handleRoll(int type, int roll)
{
    if (isListen) {
        if (type == needRoll) {
            if (state == DIALOG) {
                if (roll + player->getMod(currentEvent - 1)
                    >= 10
                           + entities[currentPlace->npcs[currentEntity.toInt()]]->getMod(
                               currentEvent - 1)) {
                    currentNode->was = true;
                    emit sendText("Вам удалось выполнить действие\n", Qt::black);
                    chooseOption(QString::number(currentNode->options[0]), true);
                } else {
                    emit sendText("К сожалению, вам не удалось выполнить действие\n", Qt::black);
                    chooseOption(QString::number(currentNode->options[1]), true);
                }
                emit blockInput(false);
                isListen = false;
            } else {
                if (type == D20) {
                    if (roll + player->getMod(CONSTITUTION) >= 15) {
                        emit sendText("Вам удалось избежать ловушки\n", Qt::black);
                        emit blockInput(false);
                        isListen = false;
                    } else {
                        startEvent(TRAP_EVENT);
                    }
                } else {
                    player->getHeart(roll);
                    emit sendText("Вам нанесено " + QString::number(roll) + " урона\n", Qt::black);
                    if (!player->isAlive()) {
                        emit gameOver();
                    }
                    emit blockInput(false);
                    isListen = false;
                    handleCommand("/i"); //ПЛОХАЯ ПРАКТИКА
                }
            }
        } else {
            emit sendText("\nВы бросили не ту кость!(D" + QString::number(type) + ")\nВам нужен D"
                              + QString::number(needRoll) + "\n\n",
                          Qt::darkYellow);
        }
    }
}
