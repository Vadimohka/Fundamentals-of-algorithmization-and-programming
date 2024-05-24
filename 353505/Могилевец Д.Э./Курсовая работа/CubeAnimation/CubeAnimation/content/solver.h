#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>
#include <QQmlEngine>
#include "RoationsOfCube.h"
#include <QRandomGenerator>

class Solver : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Solver(QObject *parent = nullptr);
    QStringList Solution(QMap<QString, QString> state);

private:
    QMap<QString, QString> inversions = {
        {U, USt}, {USt, U}, {u, uSt}, {uSt, u},
        {F, FSt}, {FSt, F}, {f, fSt}, {fSt, f},
        {R, RSt}, {RSt, R}, {r, rSt}, {rSt, r},
        {D, DSt}, {DSt, D}, {d, dSt}, {dSt, d},
        {B, BSt}, {BSt, B}, {b, bSt}, {bSt, b},
        {L, LSt}, {LSt, L}, {l, lSt}, {lSt, l},
    };

    const QMap<QString, QString> jsonEdges = QMap<QString, QString>
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

    QMap<QString, QString> CurrState = QMap<QString, QString> {
    {"galu", "galu"}, {"geul", "geul"}, {"geuc", "geuc"}, {"geur", "geur"}, {"garu", "garu"},
    {"gelu", "gelu"}, {"gcul", "gcul"}, {"gcu", "gcu"},   {"gcur", "gcur"}, {"geru", "geru"},
    {"gelc", "gelc"}, {"gcl", "gcl"},   {"gc", "gc"},     {"gcr", "gcr"},   {"gerc", "gerc"},
    {"geld", "geld"}, {"gcdl", "gcdl"}, {"gcd", "gcd"},   {"gcdr", "gcdr"}, {"gerd", "gerd"},
    {"gald", "gald"}, {"gedl", "gedl"}, {"gedc", "gedc"}, {"gedr", "gedr"}, {"gard", "gard"},

    {"ralu", "ralu"}, {"reul", "reul"}, {"reuc", "reuc"}, {"reur", "reur"}, {"raru", "raru"},
    {"relu", "relu"}, {"rcul", "rcul"}, {"rcu", "rcu"},   {"rcur", "rcur"}, {"reru", "reru"},
    {"relc", "relc"}, {"rcl", "rcl"},   {"rc", "rc"},     {"rcr", "rcr"},   {"rerc", "rerc"},
    {"reld", "reld"}, {"rcdl", "rcdl"}, {"rcd", "rcd"},   {"rcdr", "rcdr"}, {"rerd", "rerd"},
    {"rald", "rald"}, {"redl", "redl"}, {"redc", "redc"}, {"redr", "redr"}, {"rard", "rard"},

    {"walu", "walu"}, {"weul", "weul"}, {"weuc", "weuc"}, {"weur", "weur"}, {"waru", "waru"},
    {"welu", "welu"}, {"wcul", "wcul"}, {"wcu", "wcu"},   {"wcur", "wcur"}, {"weru", "weru"},
    {"welc", "welc"}, {"wcl", "wcl"},   {"wc", "wc"},     {"wcr", "wcr"},   {"werc", "werc"},
    {"weld", "weld"}, {"wcdl", "wcdl"}, {"wcd", "wcd"},   {"wcdr", "wcdr"}, {"werd", "werd"},
    {"wald", "wald"}, {"wedl", "wedl"}, {"wedc", "wedc"}, {"wedr", "wedr"}, {"ward", "ward"},

    {"oalu", "oalu"}, {"oeul", "oeul"}, {"oeuc", "oeuc"}, {"oeur", "oeur"}, {"oaru", "oaru"},
    {"oelu", "oelu"}, {"ocul", "ocul"}, {"ocu", "ocu"},   {"ocur", "ocur"}, {"oeru", "oeru"},
    {"oelc", "oelc"}, {"ocl", "ocl"},   {"oc", "oc"},     {"ocr", "ocr"},   {"oerc", "oerc"},
    {"oeld", "oeld"}, {"ocdl", "ocdl"}, {"ocd", "ocd"},   {"ocdr", "ocdr"}, {"oerd", "oerd"},
    {"oald", "oald"}, {"oedl", "oedl"}, {"oedc", "oedc"}, {"oedr", "oedr"}, {"oard", "oard"},

    {"balu", "balu"}, {"beul", "beul"}, {"beuc", "beuc"}, {"beur", "beur"}, {"baru", "baru"},
    {"belu", "belu"}, {"bcul", "bcul"}, {"bcu", "bcu"},   {"bcur", "bcur"}, {"beru", "beru"},
    {"belc", "belc"}, {"bcl", "bcl"},   {"bc", "bc"},     {"bcr", "bcr"},   {"berc", "berc"},
    {"beld", "beld"}, {"bcdl", "bcdl"}, {"bcd", "bcd"},   {"bcdr", "bcdr"}, {"berd", "berd"},
    {"bald", "bald"}, {"bedl", "bedl"}, {"bedc", "bedc"}, {"bedr", "bedr"}, {"bard", "bard"},

    {"yalu", "yalu"}, {"yeul", "yeul"}, {"yeuc", "yeuc"}, {"yeur", "yeur"}, {"yaru", "yaru"},
    {"yelu", "yelu"}, {"ycul", "ycul"}, {"ycu", "ycu"},   {"ycur", "ycur"}, {"yeru", "yeru"},
    {"yelc", "yelc"}, {"ycl", "ycl"},   {"yc", "yc"},     {"ycr", "ycr"},   {"yerc", "yerc"},
    {"yeld", "yeld"}, {"ycdl", "ycdl"}, {"ycd", "ycd"},   {"ycdr", "ycdr"}, {"yerd", "yerd"},
    {"yald", "yald"}, {"yedl", "yedl"}, {"yedc", "yedc"}, {"yedr", "yedr"}, {"yard", "yard"},
    };

    const QVector<QVector<QString>> angles = QVector<QVector<QString>> {
        {"galu", "raru", "yald"},
        {"garu", "yard", "oalu"},
        {"gard", "oald", "waru"},
        {"gald", "rard", "walu"},
        {"bald", "yalu", "ralu"},
        {"bard", "yaru", "oaru"},
        {"baru", "oard", "ward"},
        {"balu", "rald", "wald"}
    };

    const QVector<QString> anglesVector = QVector<QString> {
        "galu", "raru", "yald",
        "garu", "yard", "oalu",
        "gard", "oald", "waru",
        "gald", "rard", "walu",
        "yalu", "ralu", "bald",
        "yaru", "bard", "oaru",
        "oard", "ward", "baru",
        "rald", "wald", "balu"
    };

    const QVector<QVector<QString>> edges = {
        {"geuc", "yedc"},
        {"gerc", "oelc"},
        {"gedc", "weuc"},
        {"gelc", "rerc"},
        {"reuc", "yelc"},
        {"relc", "belc"},
        {"redc", "welc"},
        {"wedc", "beuc"},
        {"werc", "oedc"},
        {"oerc", "berc"},
        {"yerc", "oeuc"},
        {"bedc", "yeuc"}
    };

    QMap<QString, bool> edgesSolved = {
        {"geuc", false},
        {"gerc", false},
        {"gedc", false},
        {"gelc", false},
        {"reuc", false},
        {"relc", false},
        {"redc", false},
        {"wedc", false},
        {"werc", false},
        {"oerc", false},
        {"yerc", false},
        {"bedc", false}
    };

    const QVector<QString> centerEdges = {
        "gcu", "gcr", "gcd", "gcl",
        "bcu", "bcr", "bcd", "bcl",
        "wcu", "wcr", "wcd", "wcl",
        "ycu", "ycr", "ycd", "ycl",
        "rcu", "rcr", "rcd", "rcl",
        "ocu", "ocr", "ocd", "ocl",
    };

    const QVector<QString> centerAngles = {
        "gcul", "gcur", "gcdl", "gcdr",
        "bcul", "bcur", "bcdl", "bcdr",
        "ocul", "ocur", "ocdl", "ocdr",
        "rcul", "rcur", "rcdl", "rcdr",
        "wcul", "wcur", "wcdl", "wcdr",
        "ycul", "ycur", "ycdl", "ycdr",
    };

    const QVector<QString> edgeCenters = {
        "geuc", "gelc", "gedc", "gerc",
        "reuc", "relc", "redc", "rerc",
        "yeuc", "yelc", "yedc", "yerc",
        "beuc", "belc", "bedc", "berc",
        "oeuc", "oelc", "oedc", "oerc",
        "weuc", "welc", "wedc", "werc"
    };

    const QMap<QString, QString> leftNeighborOfEdge
    {
        {"dc", "dr"}, {"uc", "ul"}, {"lc", "ld"}, {"rc", "ru"},
    };

    const QMap<QString, QString> rightNeighborOfEdge
    {
        {"dc", "dl"}, {"uc", "ur"}, {"lc", "lu"}, {"rc", "rd"},
    };

    QMap<QString, bool> solvedAngles = {
        {"garu", false}, {"galu", false}, {"gard", false}, {"gald", false},
        {"baru", false}, {"balu", false}, {"bard", false}, {"bald", false},
    };

    QStringList solveEdgeAlgorithm = {r, U, FSt, L, USt, F, rSt};

    QStringList westAlgorithm = {R, U, RSt, USt, RSt, F, R, R, USt, RSt, USt, R, U, RSt, FSt};

    QStringList invertedMoves(QStringList);

    QStringList solution;

    void _cyclicPermutation(QString&& a, QString&& b, QString&& c, QString&& d, bool clockwise);

    void _permuteU(bool clockwise);
    void _permuteR(bool clockwise);
    void _permuteD(bool clockwise);
    void _permuteL(bool clockwise);
    void _permuteF(bool clockwise);
    void _permuteB(bool clockwise);
    void _permuteu(bool clockwise);
    void _permuted(bool clockwise);
    void _permutel(bool clockwise);
    void _permuter(bool clockwise);
    void _permuteb(bool clockwise);
    void _permutef(bool clockwise);

    void _doMovesFrom(QStringList);
    bool isWrongElement(QString);

    QStringList _movesForCentralElementToGcd(QString elementPos);
    QString posOfWrongCenterEdge();
    QString targetPosForCenterEdge(QString);
    void solveCenterEdges();

    QStringList _movesForCentralAngleToGcul(QString elementPos);
    QString posOfWrongCenterAngle();
    QString targetPosForCenterAngle(QString);
    void solveCenterAngles();

    QString posOfUnsolvedEdge();
    QString posOfParitetEdge();
    QString leftNeighborEdge(QString);
    QString rightNeighborEdge(QString);
    QStringList _movesForEdgeToGeu(QString);
    QStringList _movesForEdgeToGed(QString);
    QString posOfEdge(QString edge);
    void solveEdges();
    void solveParitets();

    void setAnglesUnsolved();
    QString foundUnsolvedAngle();
    QStringList setupMovesForAngle(QString);
    QStringList unsetupMovesForAngle(QString);
    void setAngleSolved(QString);
    bool checkSolutionOfAngles();
    void solveAngles();

    void setEdgesUnsolved();
    QString unsolvedEdge();
    QStringList setupMovesForEdge(QString);
    QStringList unsetupMovesForEdge(QString);
    void setEdgeSolved(QString);
    bool checkSolutionOfEdges();
    void solveEdgesFinal();

    void _normalizeSolution();
    void deleteNearInversions();
    void replaceThreeInRow();
    void deleteFourInRow();
signals:
};

#endif // SOLVER_H
