#ifndef WORLD_H
#define WORLD_H

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "armor.h"
#include "combat.h"
#include "entity.h"
#include "player.h"
#include "potion.h"
#include "weapon.h"

struct Place
{
    QString name;
    QString description;
    QVector<QString> exits;
    QVector<QString> npcs;
    int type;
    int lvl;
};
struct Dialog
{
    QString name;
    struct DialogNode
    {
        int id;
        QString option;
        QString dialog;
        QVector<int> options;
        int event;
        bool was = false;
    };
    QVector<DialogNode> nodes;
};

class World : public QObject
{
    Q_OBJECT
public:
    World(Player *, Combat *);
    World();

    Item *getItem(int id);
    void clearWorld();

private:
    Dialog dialog;
    QVector<int> possibleWays;
    QMap<QString, Entity *> entities;
    QMap<QString, bool> defeated;
    QMap<int, Item *> items;
    QMap<QString, Place *> places;

    Player *player;
    Place *currentPlace;
    QString currentEntity;
    int currentEvent;
    Dialog::DialogNode *currentNode;
    Combat *combat;

    int state{CREATION};
    bool isListen = false;
    int needRoll;

    QMap<QString, Place *> parsePlaces(const QString &filePath);
    QMap<int, Item *> parseItems(const QString &filePath);
    QMap<QString, Entity *> parseEntities(const QString &filePath);
    Dialog parseDialog(const QString &filePath);

    void goToPlace(QString place);
    void talkToNPC(QString npc);
    void fightToNPC(QString npc);
    void startDialog();
    void findPossibleWays();
    void checkWay(int id);
    void chooseOption(QString option, bool VIP);

    void startEvent(int event);

public slots:
    void handleCommand(QString command);
    void handleFightEnd(QString name);
    void handleRoll(int, int);

signals:
    void sendText(QString, QColor);
    void createPlayer();
    void blockInput(bool);
    void gameOver();
};

#endif // WORLD_H
