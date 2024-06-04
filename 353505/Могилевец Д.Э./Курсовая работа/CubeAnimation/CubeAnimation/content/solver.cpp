#include "solver.h"

Solver::Solver(QObject *parent)
    : QObject{parent}
{}

QStringList Solver::Solution(QMap<QString, QString> state)
{
    solution = {};

    CurrState = state;

    solveCenterEdges();

    solveCenterAngles();

    solveEdges();

    solveParitets();

    solveAngles();

    if (solution == QStringList{"FATAL ERROR"}) return solution;

    solveEdgesFinal();

    if (solution == QStringList{"FATAL ERROR"}) return solution;

    if (!checkSolutionOfAngles()) return {"FATAL ERROR"};

    _normalizeSolution();

    return solution;
}

QStringList Solver::invertedMoves(QStringList invertedList)
{
    QStringList resultOfInversion;
    for (int i = invertedList.size() - 1; i >= 0; --i)
        resultOfInversion.append(inversions[invertedList[i]]);
    return resultOfInversion;
}

void Solver::_cyclicPermutation(QString &&a, QString &&b, QString &&c, QString &&d, bool clockwise)
{
    if (clockwise) {
        QString tmp = CurrState[d];
        CurrState[d] = CurrState[c];
        CurrState[c] = CurrState[b];
        CurrState[b] = CurrState[a];
        CurrState[a] = tmp;
        return;
    }
    QString tmp = CurrState[a];
    CurrState[a] = CurrState[b];
    CurrState[b] = CurrState[c];
    CurrState[c] = CurrState[d];
    CurrState[d] = tmp;
}

void Solver::_permuteU(bool clockwise)
{
    _cyclicPermutation("galu", "ralu", "bard", "oalu", clockwise);
    _cyclicPermutation("geul", "reul", "bedr", "oeul", clockwise);
    _cyclicPermutation("geuc", "reuc", "bedc", "oeuc", clockwise);
    _cyclicPermutation("geur", "reur", "bedl", "oeur", clockwise);
    _cyclicPermutation("garu", "raru", "bald", "oaru", clockwise);

    _cyclicPermutation("yalu", "yaru", "yard", "yald", clockwise);
    _cyclicPermutation("yeld", "yeul", "yeru", "yedr", clockwise);
    _cyclicPermutation("yedl", "yelu", "yeur", "yerd", clockwise);
    _cyclicPermutation("ycdl", "ycul", "ycur", "ycdr", clockwise);
    _cyclicPermutation("ycd", "ycl", "ycu", "ycr", clockwise);
    _cyclicPermutation("yedc", "yelc", "yeuc", "yerc", clockwise);
}

void Solver::_permuteR(bool clockwise)
{
    _cyclicPermutation("garu", "yaru", "baru", "waru", clockwise);
    _cyclicPermutation("geru", "yeru", "beru", "weru", clockwise);
    _cyclicPermutation("gerc", "yerc", "berc", "werc", clockwise);
    _cyclicPermutation("gerd", "yerd", "berd", "werd", clockwise);
    _cyclicPermutation("gard", "yard", "bard", "ward", clockwise);

    _cyclicPermutation("oalu", "oaru", "oard", "oald", clockwise);
    _cyclicPermutation("oeld", "oeul", "oeru", "oedr", clockwise);
    _cyclicPermutation("oedl", "oelu", "oeur", "oerd", clockwise);
    _cyclicPermutation("ocdl", "ocul", "ocur", "ocdr", clockwise);
    _cyclicPermutation("ocd", "ocl", "ocu", "ocr", clockwise);
    _cyclicPermutation("oedc", "oelc", "oeuc", "oerc", clockwise);
}

void Solver::_permuteD(bool clockwise)
{
    _cyclicPermutation("gald", "rald", "baru", "oald", !clockwise);
    _cyclicPermutation("gedl", "redl", "beur", "oedl", !clockwise);
    _cyclicPermutation("gedc", "redc", "beuc", "oedc", !clockwise);
    _cyclicPermutation("gedr", "redr", "beul", "oedr", !clockwise);
    _cyclicPermutation("gard", "rard", "balu", "oard", !clockwise);

    _cyclicPermutation("walu", "waru", "ward", "wald", clockwise);
    _cyclicPermutation("weld", "weul", "weru", "wedr", clockwise);
    _cyclicPermutation("wedl", "welu", "weur", "werd", clockwise);
    _cyclicPermutation("wcdl", "wcul", "wcur", "wcdr", clockwise);
    _cyclicPermutation("wcd", "wcl", "wcu", "wcr", clockwise);
    _cyclicPermutation("wedc", "welc", "weuc", "werc", clockwise);
}

void Solver::_permuteL(bool clockwise)
{
    _cyclicPermutation("galu", "yalu", "balu", "walu", !clockwise);
    _cyclicPermutation("gelu", "yelu", "belu", "welu", !clockwise);
    _cyclicPermutation("gelc", "yelc", "belc", "welc", !clockwise);
    _cyclicPermutation("geld", "yeld", "beld", "weld", !clockwise);
    _cyclicPermutation("gald", "yald", "bald", "wald", !clockwise);

    _cyclicPermutation("ralu", "raru", "rard", "rald", clockwise);
    _cyclicPermutation("reld", "reul", "reru", "redr", clockwise);
    _cyclicPermutation("redl", "relu", "reur", "rerd", clockwise);
    _cyclicPermutation("rcdl", "rcul", "rcur", "rcdr", clockwise);
    _cyclicPermutation("rcd", "rcl", "rcu", "rcr", clockwise);
    _cyclicPermutation("redc", "relc", "reuc", "rerc", clockwise);
}

void Solver::_permuteF(bool clockwise)
{
    _cyclicPermutation("yald", "oalu", "waru", "rard", clockwise);
    _cyclicPermutation("yedl", "oelu", "weur", "rerd", clockwise);
    _cyclicPermutation("yedc", "oelc", "weuc", "rerc", clockwise);
    _cyclicPermutation("yedr", "oeld", "weul", "reru", clockwise);
    _cyclicPermutation("yard", "oald", "walu", "raru", clockwise);

    _cyclicPermutation("galu", "garu", "gard", "gald", clockwise);
    _cyclicPermutation("geld", "geul", "geru", "gedr", clockwise);
    _cyclicPermutation("gedl", "gelu", "geur", "gerd", clockwise);
    _cyclicPermutation("gcdl", "gcul", "gcur", "gcdr", clockwise);
    _cyclicPermutation("gcd", "gcl", "gcu", "gcr", clockwise);
    _cyclicPermutation("gedc", "gelc", "geuc", "gerc", clockwise);
}

void Solver::_permuteB(bool clockwise)
{
    _cyclicPermutation("yalu", "oaru", "ward", "rald", !clockwise);
    _cyclicPermutation("yeul", "oeru", "wedr", "reld", !clockwise);
    _cyclicPermutation("yeuc", "oerc", "wedc", "relc", !clockwise);
    _cyclicPermutation("yeur", "oerd", "wedl", "relu", !clockwise);
    _cyclicPermutation("yaru", "oard", "wald", "ralu", !clockwise);

    _cyclicPermutation("balu", "baru", "bard", "bald", clockwise);
    _cyclicPermutation("beld", "beul", "beru", "bedr", clockwise);
    _cyclicPermutation("bedl", "belu", "beur", "berd", clockwise);
    _cyclicPermutation("bcdl", "bcul", "bcur", "bcdr", clockwise);
    _cyclicPermutation("bcd", "bcl", "bcu", "bcr", clockwise);
    _cyclicPermutation("bedc", "belc", "beuc", "berc", clockwise);
}

void Solver::_permuteu(bool clockwise)
{
    _cyclicPermutation("gelu", "relu", "berd", "oelu", clockwise);
    _cyclicPermutation("gcul", "rcul", "bcdr", "ocul", clockwise);
    _cyclicPermutation("gcu", "rcu", "bcd", "ocu", clockwise);
    _cyclicPermutation("gcur", "rcur", "bcdl", "ocur", clockwise);
    _cyclicPermutation("geru", "reru", "beld", "oeru", clockwise);
}

void Solver::_permuted(bool clockwise)
{
    _cyclicPermutation("geld", "reld", "beru", "oeld", !clockwise);
    _cyclicPermutation("gcdl", "rcdl", "bcur", "ocdl", !clockwise);
    _cyclicPermutation("gcd", "rcd", "bcu", "ocd", !clockwise);
    _cyclicPermutation("gcdr", "rcdr", "bcul", "ocdr", !clockwise);
    _cyclicPermutation("gerd", "rerd", "belu", "oerd", !clockwise);
}

void Solver::_permutel(bool clockwise)
{
    _cyclicPermutation("geul", "weul", "beul", "yeul", clockwise);
    _cyclicPermutation("gcul", "wcul", "bcul", "ycul", clockwise);
    _cyclicPermutation("gcl", "wcl", "bcl", "ycl", clockwise);
    _cyclicPermutation("gcdl", "wcdl", "bcdl", "ycdl", clockwise);
    _cyclicPermutation("gedl", "wedl", "bedl", "yedl", clockwise);
}

void Solver::_permuter(bool clockwise)
{
    _cyclicPermutation("geur", "weur", "beur", "yeur", !clockwise);
    _cyclicPermutation("gcur", "wcur", "bcur", "ycur", !clockwise);
    _cyclicPermutation("gcr", "wcr", "bcr", "ycr", !clockwise);
    _cyclicPermutation("gcdr", "wcdr", "bcdr", "ycdr", !clockwise);
    _cyclicPermutation("gedr", "wedr", "bedr", "yedr", !clockwise);
}

void Solver::_permuteb(bool clockwise)
{
    _cyclicPermutation("reul", "yeru", "oedr", "weld", !clockwise);
    _cyclicPermutation("rcul", "ycur", "ocdr", "wcdl", !clockwise);
    _cyclicPermutation("rcl", "ycu", "ocr", "wcd", !clockwise);
    _cyclicPermutation("rcdl", "ycul", "ocur", "wcdr", !clockwise);
    _cyclicPermutation("redl", "yelu", "oeur", "werd", !clockwise);
}

void Solver::_permutef(bool clockwise)
{
    _cyclicPermutation("reur", "yerd", "oedl", "welu", clockwise);
    _cyclicPermutation("rcur", "ycdr", "ocdl", "wcul", clockwise);
    _cyclicPermutation("rcr", "ycd", "ocl", "wcu", clockwise);
    _cyclicPermutation("rcdr", "ycdl", "ocul", "wcur", clockwise);
    _cyclicPermutation("redr", "yeld", "oeul", "weru", clockwise);
}

QStringList Solver::_movesForCentralElementToGcd(QString elementPos)
{
    if (elementPos == "gcu") return {F, F};
    else if (elementPos == "gcr") return {F};
    else if (elementPos == "gcl")return {FSt};
    else if (elementPos == "gcd") return {};

    else if (elementPos == "rcd") return {F, d, FSt, dSt, FSt};
    else if (elementPos == "rcr") return {F, L, d, FSt, dSt, FSt};
    else if (elementPos == "rcu") return {F, L, L, d, FSt, dSt, FSt};
    else if (elementPos == "rcl") return {F, LSt, d, F, dSt, FSt};

    else if (elementPos == "ocd") return {F, dSt, FSt, d, FSt};
    else if (elementPos == "ocr") return {F, R, dSt, FSt, d, FSt};
    else if (elementPos == "ocu") return {F, R, R, dSt, FSt, d, FSt};
    else if (elementPos == "ocl") return {F, RSt, dSt, FSt, d, FSt};

    else if (elementPos == "bcu") return {F, d, d, FSt, d, d, FSt};
    else if (elementPos == "bcl") return {F, B, d, d, FSt, d, d, FSt};
    else if (elementPos == "bcr") return {F, BSt, d, d, FSt, d, d, FSt};
    else if (elementPos == "bcd") return {F, B, B, d, d, FSt, d, d, FSt};

    else if (elementPos == "ycr") return {rSt, FSt, r, F, F};
    else if (elementPos == "ycd") return {USt, rSt, FSt, r, F, F};
    else if (elementPos == "ycl") return {U, U, rSt, FSt, r, F, F};
    else if (elementPos == "ycu") return {U, rSt, FSt, r, F, F};

    else if (elementPos == "wcr") return {r, FSt, rSt, F, F};
    else if (elementPos == "wcd") return {DSt, r, FSt, rSt, F, F};
    else if (elementPos == "wcl") return {D, D, r, FSt, rSt, F, F};
    else return {D, r, FSt, rSt, F, F};
}

void Solver::_doMovesFrom(QStringList toDoList)
{
    for (auto &s : toDoList) {
        if (s == "U") _permuteU(true);
        else if (s == "U'") _permuteU(false);
        else if (s == "R") _permuteR(true);
        else if (s == "R'") _permuteR(false);
        else if (s == "F") _permuteF(true);
        else if (s == "F'") _permuteF(false);
        else if (s == "D") _permuteD(true);
        else if (s == "D'") _permuteD(false);
        else if (s == "L") _permuteL(true);
        else if (s == "L'") _permuteL(false);
        else if (s == "B") _permuteB(true);
        else if (s == "B'") _permuteB(false);
        else if (s == "u") _permuteu(true);
        else if (s == "u'") _permuteu(false);
        else if (s == "r") _permuter(true);
        else if (s == "r'") _permuter(false);
        else if (s == "f") _permutef(true);
        else if (s == "f'") _permutef(false);
        else if (s == "d") _permuted(true);
        else if (s == "d'") _permuted(false);
        else if (s == "l") _permutel(true);
        else if (s == "l'") _permutel(false);
        else if (s == "b") _permuteb(true);
        else if (s == "b'") _permuteb(false);
    }
}

QString Solver::posOfWrongCenterEdge()
{
    for (auto key : centerEdges) {
        if (isWrongElement(key) && CurrState[key][0] != 'g') return key;
    }
    return "#";
}

QString Solver::targetPosForCenterEdge(QString centerEdge)
{
    QString color = centerEdge[0];
    if (isWrongElement(color + "cu")) return color + "cu";
    else if (isWrongElement(color + "cr")) return color + "cr";
    else if (isWrongElement(color + "cd")) return color + "cd";
    else return color + "cl";
}

bool Solver::isWrongElement(QString pos)
{
    return pos[0] != CurrState[pos][0];
}

void Solver::solveCenterEdges()
{
    QString currEl = posOfWrongCenterEdge();
    QStringList doneMoves{}, movesToGcd, movesFromGcd;
    QString target;
    while (currEl != "#") {
        movesToGcd = _movesForCentralElementToGcd(currEl);

        _doMovesFrom(movesToGcd);
        target = targetPosForCenterEdge(CurrState["gcd"]);
        movesFromGcd = _movesForCentralElementToGcd(target);

        _doMovesFrom(movesFromGcd);

        solution.append(movesToGcd);
        solution.append(movesFromGcd);

        currEl = posOfWrongCenterEdge();
    }
}

QStringList Solver::_movesForCentralAngleToGcul(QString elementPos)
{
    if (elementPos == "gcul") return {};
    else if (elementPos == "gcur") return {FSt};
    else if (elementPos == "gcdl")return {F};
    else if (elementPos == "gcdr") return {F, F};

    else if (elementPos == "rcdl") return {FSt, LSt, d, F, dSt, F, d, F, F, dSt, FSt};
    else if (elementPos == "rcdr") return {FSt, d, F, dSt, F, d, F, F, dSt, FSt};
    else if (elementPos == "rcur") return {FSt, L, d, F, dSt, F, d, F, F, dSt, FSt};
    else if (elementPos == "rcul") return {FSt, L, L, d, F, dSt, F, d, F, F, dSt, FSt};

    else if (elementPos == "ocdl") return {R, F, u, F, uSt, F, u, F, F, uSt, F};
    else if (elementPos == "ocdr") return {R, R, F, u, F, uSt, F, u, F, F, uSt, F};
    else if (elementPos == "ocur") return {RSt, F, u, F, uSt, F, u, F, F, uSt, F};
    else if (elementPos == "ocul") return {F, u, F, uSt, F, u, F, F, uSt, F};

    else if (elementPos == "bcur") return {B, B, l, l, F, l, l, F, l, l, F, F, l, l, F, F};
    else if (elementPos == "bcul") return {BSt, l, l, F, l, l, F, l, l, F, F, l, l, F, F};
    else if (elementPos == "bcdr") return {B, l, l, F, l, l, F, l, l, F, F, l, l, F, F};
    else if (elementPos == "bcdl") return {l, l, F, l, l, F, l, l, F, F, l, l, F, F};

    else if (elementPos == "ycdr") return {U, l, F, lSt, F, l, F, F, lSt, F, F};
    else if (elementPos == "ycdl") return {l, F, lSt, F, l, F, F, lSt, F, F};
    else if (elementPos == "ycul") return {USt, l, F, lSt, F, l, F, F, lSt, F, F};
    else if (elementPos == "ycur") return {U, U, l, F, lSt, F, l, F, F, lSt, F, F};

    else if (elementPos == "wcur") return {F, F, r, F, rSt, F, r, F, F, rSt};
    else if (elementPos == "wcul") return {D, F, F, r, F, rSt, F, r, F, F, rSt};
    else if (elementPos == "wcdl") return {D, D, F, F, r, F, rSt, F, r, F, F, rSt};
    else return {DSt, F, F, r, F, rSt, F, r, F, F, rSt};
}

QString Solver::posOfWrongCenterAngle()
{
    for (auto key : centerAngles) {
        if (isWrongElement(key) && CurrState[key][0] != 'g') return key;
    }
    return "#";
}

QString Solver::targetPosForCenterAngle(QString centerAngle)
{
    QString color = centerAngle[0];
    if (isWrongElement(color + "cur")) return color + "cur";
    else if (isWrongElement(color + "cul")) return color + "cul";
    else if (isWrongElement(color + "cdl")) return color + "cdl";
    else return color + "cdr";
}

void Solver::solveCenterAngles()
{
    QString currEl = posOfWrongCenterAngle();
    QStringList doneMoves{}, movesToGcul{}, movesFromGcul{};
    QString target;
    while (currEl != "#") {
        movesToGcul = _movesForCentralAngleToGcul(currEl);

        _doMovesFrom(movesToGcul);
        target = targetPosForCenterAngle(CurrState["gcul"]);
        movesFromGcul = _movesForCentralAngleToGcul(target);

        _doMovesFrom(movesFromGcul);

        solution.append(movesToGcul);
        solution.append(movesFromGcul);

        currEl = posOfWrongCenterAngle();
    }
}

QString Solver::posOfUnsolvedEdge()
{
    for (auto& edge : edgeCenters) {
        if (CurrState[edge].first(3) !=
            CurrState[leftNeighborEdge(edge)].first(3) &&
            CurrState[edge].first(3) !=
            jsonEdges[CurrState[leftNeighborEdge(edge)]].first(3)) {
            return edge;
        }
    }
    return "#";
}

QString Solver::posOfParitetEdge()
{
    for (auto& edge : edgeCenters) {
        if (CurrState[edge][0] != CurrState[leftNeighborEdge(edge)][0]) {
            return edge;
        }
    }
    return "#";
}

QString Solver::leftNeighborEdge(QString edgePos)
{
    return edgePos.first(2) + leftNeighborOfEdge[edgePos.last(2)];
}

QString Solver::rightNeighborEdge(QString edgePos)
{
    return edgePos.first(2) + rightNeighborOfEdge[edgePos.last(2)];
}

QStringList Solver::_movesForEdgeToGeu(QString edge)
{
    if (edge == "geuc") return {};
    else if (edge == "gedc") return {F, F};
    else if (edge == "gerc") return {R, R, B, U, U};
    else if (edge == "gelc") return {L, L, BSt, U, U};

    else if (edge == "oeuc") return {U};
    else if (edge == "oedc") return {R, R, U};
    else if (edge == "oerc") return {RSt, U};
    else if (edge == "oelc") return {R, U};

    else if (edge == "reuc") return {USt};
    else if (edge == "redc") return {L, L, USt};
    else if (edge == "rerc") return {LSt, USt};
    else if (edge == "relc") return {L, USt};

    else if (edge == "bedc") return {U, U};
    else if (edge == "beuc") return {B, B, U, U};
    else if (edge == "berc") return {BSt, U, U};
    else if (edge == "belc") return {B, U, U};

    else if (edge == "werc") return {RSt, B, U, U};
    else if (edge == "wedc") return {DSt, RSt, B, U, U, D};
    else if (edge == "welc") return {D, D, RSt, D, D, B, U, U};
    else if (edge == "weuc") return {D, RSt, B, U, U};

    else if (edge == "yerc") return {R, B, U, U};
    else if (edge == "yedc") return {USt, R, B, U, U};
    else if (edge == "yelc") return {U, U, R, U, U, B, U, U};
    else return {U, R, B, U, U};
}

QStringList Solver::_movesForEdgeToGed(QString edge)
{
    if (edge == "gedc") return {};
    else if (edge == "geuc") return {F, F};
    else if (edge == "gerc") return {R, R, BSt, D, D};
    else if (edge == "gelc") return {L, L, B, D, D};

    else if (edge == "oeuc") return {R, R, DSt};
    else if (edge == "oedc") return {DSt};
    else if (edge == "oerc") return {R, DSt};
    else if (edge == "oelc") return {RSt, DSt};

    else if (edge == "reuc") return {L, L, D};
    else if (edge == "redc") return {D};
    else if (edge == "rerc") return {L, D};
    else if (edge == "relc") return {LSt, D};

    else if (edge == "bedc") return {B, B, D, D};
    else if (edge == "beuc") return {D, D};
    else if (edge == "berc") return {BSt, D, D};
    else if (edge == "belc") return {B, D, D};

    else if (edge == "werc") return {RSt, BSt, D, D};
    else if (edge == "wedc") return {DSt, RSt, BSt, D, D};
    else if (edge == "welc") return {D, D, RSt, D, D, BSt, D, D};
    else if (edge == "weuc") return {D, RSt, BSt, D, D};

    else if (edge == "yerc") return {R, BSt, D, D};
    else if (edge == "yedc") return {U, L, FSt};
    else if (edge == "yelc") return {U, U, R, U, U, BSt, D, D};
    else return {U, R, BSt, D, D, USt};
}

QString Solver::posOfEdge(QString edge)
{
    for (auto& key : CurrState) {
        if (CurrState[key] == edge) return key.first(3) + "c";
    }
    return "#";
}

void Solver::solveEdges()
{
    QString currEl = posOfUnsolvedEdge();
    QStringList doneMoves;
    while (currEl != "#") {
        doneMoves = _movesForEdgeToGeu(currEl);
        solution += doneMoves;
        _doMovesFrom(doneMoves);

        if (CurrState["geuc"].first(3) != CurrState["yedr"].first(3) ||
            CurrState["yedc"].first(3) != CurrState["geur"].first(3)) {
            doneMoves = _movesForEdgeToGed(posOfEdge(leftNeighborEdge(CurrState["geuc"])))
                        + solveEdgeAlgorithm;
            solution += doneMoves;
            _doMovesFrom(doneMoves);
        }
        else {
            doneMoves = _movesForEdgeToGed(posOfEdge(jsonEdges[rightNeighborEdge(CurrState["geuc"])]))
                        + solveEdgeAlgorithm;
            solution += doneMoves;
            _doMovesFrom(doneMoves);
        }
        currEl = posOfUnsolvedEdge();
    }
}

void Solver::solveParitets()
{
    QString currEl = posOfParitetEdge();
    QStringList doneMoves;
    while (currEl != "#") {
        doneMoves = _movesForEdgeToGeu(currEl) +
                    QStringList{r, r, B, B, U, U, l, U, U, rSt,
                                U, U, r, U, U, F, F, r, F, F, lSt, B, B, r, r};
        solution += doneMoves;
        _doMovesFrom(doneMoves);
        currEl = posOfParitetEdge();
    }
}

void Solver::setAnglesUnsolved()
{
    for (auto angle : solvedAngles.keys())
        solvedAngles[angle] = (angle == CurrState[angle]);
}

QString Solver::foundUnsolvedAngle()
{
    for (auto angle : solvedAngles.keys()) {
        if (angle != "bald" &&
            angle != CurrState[angle] && !solvedAngles[angle]) return angle;
        else if (angle != "bald" && angle != CurrState[angle] && solvedAngles[angle]) return "FATAL ERROR";
    }
    return "#";
}

QStringList Solver::setupMovesForAngle(QString angle)
{
    if (angle == "gald") return {FSt, R};
    else if (angle == "galu") return {F, F, R};
    else if (angle == "gard") return {R};
    else if (angle == "garu") return {F, R};

    else if (angle == "rald") return {D, D, FSt};
    else if (angle == "ralu") return {L, L, D, R};
    else if (angle == "rard") return {D, R};
    else if (angle == "raru") return {F};

    else if (angle == "yald") return {FSt, D, R};
    else if (angle == "yalu") return {L, L, F, F};
    else if (angle == "yard") return {};
    else if (angle == "yaru") return {R, DSt, FSt};

    else if (angle == "bald") return {LSt, D, F, F};
    else if (angle == "balu") return {D, D, R};
    else if (angle == "bard") return {RSt};
    else if (angle == "baru") return {DSt, FSt};

    else if (angle == "oald") return {FSt};
    else if (angle == "oalu") return {RSt, FSt};
    else if (angle == "oard") return {R, FSt};
    else if (angle == "oaru") return {R, R, FSt};

    else if (angle == "wald") return {D, F, F};
    else if (angle == "walu") return {F, F};
    else if (angle == "ward") return {D, D, F, F};
    else return {DSt, F, F};

}

QStringList Solver::unsetupMovesForAngle(QString angle)
{
    return invertedMoves(setupMovesForAngle(angle));
}

void Solver::setAngleSolved(QString angle)
{
    for (auto el : angles) {
        if (el.contains(angle)) {
            solvedAngles[el[0]] = true;
            return;
        }
    }
}

bool Solver::checkSolutionOfAngles()
{
    for (auto angle : anglesVector)
        if (CurrState[angle] != angle) return false;
    return true;
}

void Solver::solveAngles()
{
    setAnglesUnsolved();
    QString currEl = foundUnsolvedAngle();
    QStringList doneMoves;
    while (currEl != "#") {
        doneMoves = setupMovesForAngle(currEl);
        _doMovesFrom(doneMoves);
        solution += doneMoves;

        _doMovesFrom({F, R, USt, RSt, USt, R, U, RSt, FSt, R, U, RSt, USt, RSt, F, R, FSt});
        solution += {F, R, USt, RSt, USt, R, U, RSt, FSt, R, U, RSt, USt, RSt, F, R, FSt};

        doneMoves = unsetupMovesForAngle(currEl);
        _doMovesFrom(doneMoves);
        solution += doneMoves;

        if (CurrState["yalu"] != "yalu" && CurrState["yalu"] != "bald" && CurrState["yalu"] != "ralu") {
            doneMoves = setupMovesForAngle(CurrState["yalu"]);
            _doMovesFrom(doneMoves);
            solution += doneMoves;

            _doMovesFrom({F, R, USt, RSt, USt, R, U, RSt, FSt, R, U, RSt, USt, RSt, F, R, FSt});
            solution += {F, R, USt, RSt, USt, R, U, RSt, FSt, R, U, RSt, USt, RSt, F, R, FSt};

            setAngleSolved(CurrState["yard"]);

            doneMoves = unsetupMovesForAngle(CurrState["yard"]);
            _doMovesFrom(doneMoves);
            solution += doneMoves;
        }

        currEl = foundUnsolvedAngle();

        if (currEl == "FATAL ERROR") {
            solution = {"FATAL ERROR"};
            return;
        }
    }
    if (!checkSolutionOfAngles()) {
        solution = {"FATAL ERROR"};
        return;
    }
}

void Solver::setEdgesUnsolved()
{
    for (auto edge : edgesSolved.keys())
        edgesSolved[edge] = (edge == CurrState[edge]);
}

QString Solver::unsolvedEdge()
{
    for (auto edge : edgesSolved.keys()) {
        if (edge != "yerc" &&
            edge != CurrState[edge] && !edgesSolved[edge]) return edge;
        else if (edge != "yerc" && edge != CurrState[edge] && edgesSolved[edge]) return "FATAL ERROR";
    }
    return "#";
}

QStringList Solver::setupMovesForEdge(QString edge)
{
    if (edge == "gerc") return {U, U, R, U, U};
    else if (edge == "gelc") return {LSt};
    else if (edge == "gedc") return {DSt, L, U, BSt, USt};
    else if (edge == "geuc") return {R, LSt, FSt, LSt, RSt};

    else if (edge == "oerc") return {U, B, USt};
    else if (edge == "oelc") return {USt, FSt, U};
    else if (edge == "oedc") return {DSt, DSt, L, U, BSt, USt};
    else if (edge == "oeuc") return {};

    else if (edge == "werc") return {D, D, L, L};
    else if (edge == "welc") return {L, L};
    else if (edge == "wedc") return {D, L, L};
    else if (edge == "weuc") return {DSt, L, L};

    else if (edge == "berc") return {U, U, RSt, U, U};
    else if (edge == "belc") return {L};
    else if (edge == "bedc") return {RSt, B, L, R};
    else if (edge == "beuc") return {D, L, U, BSt, USt};

    else if (edge == "rerc") return {USt, F, U};
    else if (edge == "relc") return {U, BSt, USt};
    else if (edge == "redc") return {L, U, BSt, USt};
    else if (edge == "reuc") return {LSt, U, BSt, USt};

    else if (edge == "yerc") return {};
    else if (edge == "yelc") return {};
    else if (edge == "yedc") return {L, L, R, R, U, R, R};
    else return {L, L, R, R, USt, R, R};
}

QStringList Solver::unsetupMovesForEdge(QString edge)
{
    return invertedMoves(setupMovesForEdge(edge));
}

void Solver::setEdgeSolved(QString edge)
{
    for (auto el : edges) {
        if (el.contains(edge)) {
            edgesSolved[el[0]] = true;
            return;
        }
    }
}

bool Solver::checkSolutionOfEdges()
{
    for (auto edge : edgeCenters)
        if (CurrState[edge] != edge) return false;
    return true;
}

void Solver::solveEdgesFinal()
{
    setEdgesUnsolved();
    QString currEl = unsolvedEdge();
    QStringList doneMoves;
    QString targetPoint;
    while (currEl != "#") {
        targetPoint = CurrState[currEl];

        doneMoves = setupMovesForEdge(currEl);
        _doMovesFrom(doneMoves);
        solution += doneMoves;

        _doMovesFrom(westAlgorithm);
        solution += westAlgorithm;

        doneMoves = unsetupMovesForEdge(currEl);
        _doMovesFrom(doneMoves);
        solution += doneMoves;

        if (targetPoint != "yerc" && targetPoint != "oeuc") {
            doneMoves = setupMovesForEdge(targetPoint);
            _doMovesFrom(doneMoves);
            solution += doneMoves;

            _doMovesFrom(westAlgorithm);
            solution += westAlgorithm;

            setEdgeSolved(targetPoint);

            doneMoves = unsetupMovesForEdge(targetPoint);
            _doMovesFrom(doneMoves);
            solution += doneMoves;
        }

        currEl = unsolvedEdge();

        if (currEl == "FATAL ERROR") {
            solution = {"FATAL ERROR"};
            return;
        }
    }
    if (!checkSolutionOfEdges()) {
        solution = {"FATAL ERROR"};
        return;
    }
}

void Solver::_normalizeSolution()
{
    deleteNearInversions();
    replaceThreeInRow();
    deleteFourInRow();
    deleteNearInversions();
    replaceThreeInRow();
    deleteFourInRow();
}

void Solver::deleteNearInversions()
{
    bool isInversed = false;

    for (int i = 0; i < solution.size() - 1; ++i) {
        if(solution[i] == inversions[solution[i + 1]]) {
            solution.removeAt(i);
            solution.removeAt(i);
            isInversed = true;
        }
    }

    while (isInversed) {
        isInversed = false;
        for (int i = 0; i < solution.size() - 1; ++i) {
            if(solution[i] == inversions[solution[i + 1]]) {
                solution.removeAt(i);
                solution.removeAt(i);
                isInversed = true;
            }
        }
    }
}

void Solver::replaceThreeInRow()
{
    bool isThreeInRow = false;
    QString step;
    for (int i = 0; i < solution.size() - 2; ++i) {
        if(solution[i] == solution[i + 1] && solution[i + 1] == solution[i + 2]) {
            step = solution[i];
            solution.removeAt(i);
            solution.removeAt(i);
            solution.removeAt(i);
            solution.insert(i, inversions[step]);
            isThreeInRow = true;
        }
    }
    while (isThreeInRow) {
        isThreeInRow = false;
        for (int i = 0; i < solution.size() - 2; ++i) {
            if(solution[i] == solution[i + 1] && solution[i + 1] == solution[i + 2]) {
                step = solution[i];
                solution.removeAt(i);
                solution.removeAt(i);
                solution.removeAt(i);
                solution.insert(i, inversions[step]);
                isThreeInRow = true;
            }
        }
    }
}

void Solver::deleteFourInRow()
{
    bool isFourInRow = false;

    for (int i = 0; i < solution.size() - 3; ++i) {
        if (solution[i] == solution[i + 1] && solution[i + 1] == solution[i + 2] &&
           solution[i + 2] == solution[i + 3]) {
            solution.removeAt(i);
            solution.removeAt(i);
            isFourInRow = true;
        }
    }

    while (isFourInRow) {
        isFourInRow = false;
        for (int i = 0; i < solution.size() - 1; ++i) {
            if (solution[i] == solution[i + 1] && solution[i + 1] == solution[i + 2] &&
                solution[i + 2] == solution[i + 3]) {
                solution.removeAt(i);
                solution.removeAt(i);
                solution.removeAt(i);
                solution.removeAt(i);
                isFourInRow = true;
            }
        }
    }
}

