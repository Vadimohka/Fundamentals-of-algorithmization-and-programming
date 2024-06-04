#ifndef STATEFROMSCANGETTER_H
#define STATEFROMSCANGETTER_H

#include <QObject>
#include <QQmlEngine>
#include "solver.h"

class StateFromScanGetter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    void setColor(QString, QString);
    bool stateIsValid();
    explicit StateFromScanGetter(QObject *parent = nullptr);
    static StateFromScanGetter *GetInstance();
    QMap<QString, QString> getState();

private:
    static StateFromScanGetter* _instance;
    QMap<QString, QString> colorsPlaces;
    QMap<QString, QString> state;
    QMap<QString, bool> foundElements;
    const QMap<QString, QString> jsonEdges= QMap<QString, QString>
    {
    {"geul", "yedl"}, {"geuc", "yedc"}, {"geur", "yedr"},
    {"gerd", "oeld"}, {"gerc", "oelc"}, {"geru", "oelu"},
    {"gedl", "weul"}, {"gedc", "weuc"}, {"gedr", "weur"},
    {"geld", "rerd"}, {"gelc", "rerc"}, {"gelu", "reru"},

    {"rerd", "geld"}, {"rerc", "gelc"}, {"reru", "gelu"},
    {"reul", "yelu"}, {"reuc", "yelc"}, {"reur", "yeld"},
    {"relu", "beld"}, {"relc", "belc"}, {"reld", "belu"},
    {"redl", "weld"}, {"redc", "welc"}, {"redr", "welu"},

    {"weld", "redl"}, {"welc", "redc"}, {"welu", "redr"},
    {"weul", "gedl"}, {"weuc", "gedc"}, {"weur", "gedr"},
    {"wedl", "beul"}, {"wedc", "beuc"}, {"wedr", "beur"},
    {"weru", "oedl"}, {"werc", "oedc"}, {"werd", "oedr"},

    {"oedl", "weru"}, {"oedc", "werc"}, {"oedr", "werd"},
    {"oeld", "gerd"}, {"oelc", "gerc"}, {"oelu", "geru"},
    {"oerd", "beru"}, {"oerc", "berc"}, {"oeru", "berd"},
    {"oeul", "yerd"}, {"oeuc", "yerc"}, {"oeur", "yeru"},

    {"beru", "oerd"}, {"berc", "oerc"}, {"berd", "oeru"},
    {"beul", "wedl"}, {"beuc", "wedc"}, {"beur", "wedr"},
    {"beld", "relu"}, {"belc", "relc"}, {"belu", "reld"},
    {"bedl", "yeul"}, {"bedc", "yeuc"}, {"bedr", "yeur"},

    {"yedl", "geul"}, {"yedc", "geuc"}, {"yedr", "geur"},
    {"yelu", "reul"}, {"yelc", "reuc"}, {"yeld", "reur"},
    {"yerd", "oeul"}, {"yerc", "oeuc"}, {"yeru", "oeur"},
    {"yeul", "bedl"}, {"yeuc", "bedc"}, {"yeur", "bedr"},
    };
    const QMap<QString, QString> contradictiveColors = QMap<QString, QString>
    {
    {"white", "yellow"}, {"green", "blue"}, {"red", "orange"},
    {"yellow", "white"}, {"blue", "green"}, {"orange", "red"}
    };
    const QVector<QSet<QString>> angles = QVector<QSet<QString>> {
        {"galu", "raru", "yald"},
        {"garu", "yard", "oalu"},
        {"gard", "oald", "waru"},
        {"gald", "rard", "walu"},
        {"yalu", "ralu", "bald"},
        {"yaru", "bard", "oaru"},
        {"oard", "ward", "baru"},
        {"rald", "wald", "balu"}
    };

    void _setDefaultState();
    void _setAllUnfound();

    bool _setEdgesFound(QString& key);
    bool _setAnglesFound(QString& key);
    bool _setCenterFound(QString& key);

    QString defineSideOfEdge(QString);
    QString defineFamilyOfEdge(QString, QChar);

    QSet<QString> anglesCodes(QSet<QString>);

    bool _allFound();

signals:
};

#endif // STATEFROMSCANGETTER_H
