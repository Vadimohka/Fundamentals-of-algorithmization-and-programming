#include "rubickscube.h"

RubicksCube* RubicksCube::_instance = nullptr;

RubicksCube::RubicksCube()
{
    setSolved();

    setStateFromScan();

    connect(solveButtonsDisabler, &QTimer::timeout, [=] {
        solveButtonsDisabler->stop();

        isLastMove = (currStepOfSolution == solution.size());
        isFirstMove = (currStepOfSolution == 0);

        emit moveChanged();
    });

    connect(&autoAnimationTimer, &QTimer::timeout, this, &RubicksCube::onForwardClicked);
}

qreal RubicksCube::getXRotationOf(QString elementName)
{
    return CubeElements[elementName].xRotation();
}

qreal RubicksCube::getYRotationOf(QString elementName)
{
    return CubeElements[elementName].yRotation();
}

qreal RubicksCube::getZRotationOf(QString elementName)
{
    return CubeElements[elementName].zRotation();
}

void RubicksCube::setColor(QString element, QString color)
{
    scaner->setColor(element, color);
}

bool RubicksCube::stateIsValid()
{
    return scaner->stateIsValid();
}

void RubicksCube::animateRotU()
{
    _animateRotatingUpElements("g", 'y', true);
    _animateRotatingUpElements("r", 'y', true);
    _animateRotatingUpElements("o", 'y', true);
    _animateRotatingDownElements("b", 'y', true);
    _animateRotatingSide("y", 'y', true);

    _permuteU(true);
}

void RubicksCube::animateRotUSt()
{
    _animateRotatingUpElements("g", 'y', false);
    _animateRotatingUpElements("r", 'y', false);
    _animateRotatingUpElements("o", 'y', false);
    _animateRotatingDownElements("b", 'y', false);
    _animateRotatingSide("y", 'y', false);

    _permuteU(false);
}

void RubicksCube::animateRotR()
{
    _animateRotatingRightElements("g", 'x', true);
    _animateRotatingRightElements("y", 'x', true);
    _animateRotatingRightElements("b", 'x', true);
    _animateRotatingRightElements("w", 'x', true);
    _animateRotatingSide("o", 'x', true);

    _permuteR(true);
}

void RubicksCube::animateRotRSt()
{
    _animateRotatingRightElements("g", 'x', false);
    _animateRotatingRightElements("y", 'x', false);
    _animateRotatingRightElements("b", 'x', false);
    _animateRotatingRightElements("w", 'x', false);
    _animateRotatingSide("o", 'x', false);

    _permuteR(false);
}

void RubicksCube::animateRotD()
{
    _animateRotatingDownElements("g", 'y', false);
    _animateRotatingDownElements("r", 'y', false);
    _animateRotatingDownElements("o", 'y', false);
    _animateRotatingUpElements("b", 'y', false);
    _animateRotatingSide("w", 'y', false);

    _permuteD(true);
}

void RubicksCube::animateRotDSt()
{
    _animateRotatingDownElements("g", 'y', true);
    _animateRotatingDownElements("r", 'y', true);
    _animateRotatingDownElements("o", 'y', true);
    _animateRotatingUpElements("b", 'y', true);
    _animateRotatingSide("w", 'y', true);

    _permuteD(false);
}

void RubicksCube::animateRotL()
{
    _animateRotatingLeftElements("g", 'x', false);
    _animateRotatingLeftElements("y", 'x', false);
    _animateRotatingLeftElements("b", 'x', false);
    _animateRotatingLeftElements("w", 'x', false);
    _animateRotatingSide("r", 'x', false);

    _permuteL(true);
}

void RubicksCube::animateRotLSt()
{
    _animateRotatingLeftElements("g", 'x', true);
    _animateRotatingLeftElements("y", 'x', true);
    _animateRotatingLeftElements("b", 'x', true);
    _animateRotatingLeftElements("w", 'x', true);
    _animateRotatingSide("r", 'x', true);

    _permuteL(false);
}

void RubicksCube::animateRotF()
{
    _animateRotatingRightElements("r", 'z', true);
    _animateRotatingUpElements("w", 'z', true);
    _animateRotatingLeftElements("o", 'z', true);
    _animateRotatingDownElements("y", 'z', true);
    _animateRotatingSide("g", 'z', true);

    _permuteF(true);
}

void RubicksCube::animateRotFSt()
{
    _animateRotatingRightElements("r", 'z', false);
    _animateRotatingUpElements("w", 'z', false);
    _animateRotatingLeftElements("o", 'z', false);
    _animateRotatingDownElements("y", 'z', false);
    _animateRotatingSide("g", 'z', false);

    _permuteF(false);
}

void RubicksCube::animateRotB()
{
    _animateRotatingLeftElements("r", 'z', false);
    _animateRotatingDownElements("w", 'z', false);
    _animateRotatingRightElements("o", 'z', false);
    _animateRotatingUpElements("y", 'z', false);
    _animateRotatingSide("b", 'z', false);

    _permuteB(true);
}

void RubicksCube::animateRotBSt()
{
    _animateRotatingLeftElements("r", 'z', true);
    _animateRotatingDownElements("w", 'z', true);
    _animateRotatingRightElements("o", 'z', true);
    _animateRotatingUpElements("y", 'z', true);
    _animateRotatingSide("b", 'z', true);

    _permuteB(false);
}

void RubicksCube::animateRotu()
{
    _animateRotatingSecondUpElements("g", 'y', true);
    _animateRotatingSecondUpElements("r", 'y', true);
    _animateRotatingSecondUpElements("o", 'y', true);
    _animateRotatingSecondDownElements("b", 'y', true);

    _permuteu(true);
}

void RubicksCube::animateRotuSt()
{
    _animateRotatingSecondUpElements("g", 'y', false);
    _animateRotatingSecondUpElements("r", 'y', false);
    _animateRotatingSecondUpElements("o", 'y', false);
    _animateRotatingSecondDownElements("b", 'y', false);

    _permuteu(false);
}

void RubicksCube::animateRotd()
{
    _animateRotatingSecondDownElements("g", 'y', false);
    _animateRotatingSecondDownElements("r", 'y', false);
    _animateRotatingSecondDownElements("o", 'y', false);
    _animateRotatingSecondUpElements("b", 'y', false);

    _permuted(true);
}

void RubicksCube::animateRotdSt()
{
    _animateRotatingSecondDownElements("g", 'y', true);
    _animateRotatingSecondDownElements("r", 'y', true);
    _animateRotatingSecondDownElements("o", 'y', true);
    _animateRotatingSecondUpElements("b", 'y', true);

    _permuted(false);
}

void RubicksCube::animateRotl()
{
    _animateRotatingSecondLeftElements("g", 'x', false);
    _animateRotatingSecondLeftElements("y", 'x', false);
    _animateRotatingSecondLeftElements("b", 'x', false);
    _animateRotatingSecondLeftElements("w", 'x', false);

    _permutel(true);
}

void RubicksCube::animateRotlSt()
{
    _animateRotatingSecondLeftElements("g", 'x', true);
    _animateRotatingSecondLeftElements("y", 'x', true);
    _animateRotatingSecondLeftElements("b", 'x', true);
    _animateRotatingSecondLeftElements("w", 'x', true);

    _permutel(false);
}

void RubicksCube::animateRotr()
{
    _animateRotatingSecondRightElements("g", 'x', true);
    _animateRotatingSecondRightElements("y", 'x', true);
    _animateRotatingSecondRightElements("b", 'x', true);
    _animateRotatingSecondRightElements("w", 'x', true);

    _permuter(true);
}

void RubicksCube::animateRotrSt()
{
    _animateRotatingSecondRightElements("g", 'x', false);
    _animateRotatingSecondRightElements("y", 'x', false);
    _animateRotatingSecondRightElements("b", 'x', false);
    _animateRotatingSecondRightElements("w", 'x', false);

    _permuter(false);
}

void RubicksCube::animateRotb()
{
    _animateRotatingSecondLeftElements("r", 'z', false);
    _animateRotatingSecondUpElements("y", 'z', false);
    _animateRotatingSecondRightElements("o", 'z', false);
    _animateRotatingSecondDownElements("w", 'z', false);

    _permuteb(true);
}

void RubicksCube::animateRotbSt()
{
    _animateRotatingSecondLeftElements("r", 'z', true);
    _animateRotatingSecondUpElements("y", 'z', true);
    _animateRotatingSecondRightElements("o", 'z', true);
    _animateRotatingSecondDownElements("w", 'z', true);

    _permuteb(false);
}

void RubicksCube::animateRotf()
{
    _animateRotatingSecondRightElements("r", 'z', true);
    _animateRotatingSecondDownElements("y", 'z', true);
    _animateRotatingSecondLeftElements("o", 'z', true);
    _animateRotatingSecondUpElements("w", 'z', true);

    _permutef(true);
}

void RubicksCube::animateRotfSt()
{
    _animateRotatingSecondRightElements("r", 'z', false);
    _animateRotatingSecondDownElements("y", 'z', false);
    _animateRotatingSecondLeftElements("o", 'z', false);
    _animateRotatingSecondUpElements("w", 'z', false);

    _permutef(false);
}

bool RubicksCube::setStateFromScramble(QString scramble)
{
    setSolved();
    if (scramble == "") return false;
    auto parsedScramble = scramble.split(' ');

    if (!_validScramble(parsedScramble)) {
        return false;
    }

    _rotateByScramble(parsedScramble);
    setState(CurrState);

    return true;
}

void RubicksCube::setRandomState()
{
    setSolved();
    for (int i = 0; i < 100; ++i) {
        switch (QRandomGenerator::global()->bounded(25)) {
        case 1:
            _permuteU(false);
            break;
        case 2:
            _permuteR(true);
            break;
        case 3:
            _permuteR(false);
            break;
        case 4:
            _permuteF(true);
            break;
        case 5:
            _permuteF(false);
            break;
        case 6:
            _permuteU(true);
            break;
        case 7:
            _permuteD(true);
            break;
        case 8:
            _permuteD(false);
            break;
        case 9:
            _permuteL(true);
            break;
        case 10:
            _permuteL(false);
            break;
        case 11:
            _permuteB(true);
            break;
        case 12:
            _permuteB(false);
            break;
        case 13:
            _permuteu(true);
            break;
        case 14:
            _permuteu(false);
            break;
        case 15:
            _permuter(true);
            break;
        case 16:
            _permuter(false);
            break;
        case 17:
            _permutef(true);
            break;
        case 18:
            _permutef(false);
            break;
        case 19:
            _permuted(true);
            break;
        case 20:
            _permuted(false);
            break;
        case 21:
            _permutel(true);
            break;
        case 22:
            _permutel(false);
            break;
        case 23:
            _permuteb(true);
            break;
        case 24:
            _permuteb(false);
            break;
        default:
            --i;
            break;
        }
    }
    setState(CurrState);
}

void RubicksCube::setStateFromScan()
{
    setState(scaner->getState());
}

void RubicksCube::setState(QMap<QString, QString> state)
{
    for (auto& key : CurrState.keys()) {
        CurrState[key] = state[key];
    }

    for (auto& key : CurrState) {
        if (key.sliced(2) == "") continue;
        _translateElement(key);
    }
}

RubicksCube *RubicksCube::GetInstance()
{
    if (_instance == nullptr) _instance = new RubicksCube();
    return _instance;
}

void RubicksCube::_animateRotatingUpElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "alu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "eul"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "euc"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "eur"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "aru"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingSecondUpElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "elu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cul"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cur"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "eru"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingMiddleHorElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "elc"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cl"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "c"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cr"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "erc"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingSecondDownElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "eld"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cdl"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cd"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cdr"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "erd"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingDownElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "ald"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edl"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edc"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edr"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "ard"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingLeftElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "alu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "elu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "elc"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "eld"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "ald"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingSecondLeftElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "eul"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cul"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cl"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cdl"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edl"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingMiddleVertElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "euc"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cu"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "c"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cd"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edc"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingSecondRightElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "eur"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cur"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cr"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "cdr"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "edr"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingRightElements(QString color, char axis, bool clockwise)
{
    CubeElements[CurrState[color + "aru"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "eru"]].rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "erc"]].rotateAlong(axis, clockwise);
    Element &rotatedCheck = CubeElements[CurrState[color + "erd"]];
    rotatedCheck.rotateAlong(axis, clockwise);
    CubeElements[CurrState[color + "ard"]].rotateAlong(axis, clockwise);
}

void RubicksCube::_animateRotatingSide(QString color, char axis, bool clockwise)
{
    _animateRotatingLeftElements(color, axis, clockwise);
    _animateRotatingSecondLeftElements(color, axis, clockwise);
    _animateRotatingMiddleVertElements(color, axis, clockwise);
    _animateRotatingSecondRightElements(color, axis, clockwise);
    _animateRotatingRightElements(color, axis, clockwise);
}

void RubicksCube::_cyclicPermutation(QString&& a, QString&& b, QString&& c, QString&& d, bool clockwise)
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

void RubicksCube::_permuteU(bool clockwise)
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

void RubicksCube::_permuteR(bool clockwise)
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

void RubicksCube::_permuteD(bool clockwise)
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

void RubicksCube::_permuteL(bool clockwise)
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

void RubicksCube::_permuteF(bool clockwise)
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

void RubicksCube::_permuteB(bool clockwise)
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

void RubicksCube::_permuteu(bool clockwise)
{
    _cyclicPermutation("gelu", "relu", "berd", "oelu", clockwise);
    _cyclicPermutation("gcul", "rcul", "bcdr", "ocul", clockwise);
    _cyclicPermutation("gcu", "rcu", "bcd", "ocu", clockwise);
    _cyclicPermutation("gcur", "rcur", "bcdl", "ocur", clockwise);
    _cyclicPermutation("geru", "reru", "beld", "oeru", clockwise);
}

void RubicksCube::_permuted(bool clockwise)
{
    _cyclicPermutation("geld", "reld", "beru", "oeld", !clockwise);
    _cyclicPermutation("gcdl", "rcdl", "bcur", "ocdl", !clockwise);
    _cyclicPermutation("gcd", "rcd", "bcu", "ocd", !clockwise);
    _cyclicPermutation("gcdr", "rcdr", "bcul", "ocdr", !clockwise);
    _cyclicPermutation("gerd", "rerd", "belu", "oerd", !clockwise);
}

void RubicksCube::_permutel(bool clockwise)
{
    _cyclicPermutation("geul", "weul", "beul", "yeul", clockwise);
    _cyclicPermutation("gcul", "wcul", "bcul", "ycul", clockwise);
    _cyclicPermutation("gcl", "wcl", "bcl", "ycl", clockwise);
    _cyclicPermutation("gcdl", "wcdl", "bcdl", "ycdl", clockwise);
    _cyclicPermutation("gedl", "wedl", "bedl", "yedl", clockwise);
}

void RubicksCube::_permuter(bool clockwise)
{
    _cyclicPermutation("geur", "weur", "beur", "yeur", !clockwise);
    _cyclicPermutation("gcur", "wcur", "bcur", "ycur", !clockwise);
    _cyclicPermutation("gcr", "wcr", "bcr", "ycr", !clockwise);
    _cyclicPermutation("gcdr", "wcdr", "bcdr", "ycdr", !clockwise);
    _cyclicPermutation("gedr", "wedr", "bedr", "yedr", !clockwise);
}

void RubicksCube::_permuteb(bool clockwise)
{
    _cyclicPermutation("reul", "yeru", "oedr", "weld", !clockwise);
    _cyclicPermutation("rcul", "ycur", "ocdr", "wcdl", !clockwise);
    _cyclicPermutation("rcl", "ycu", "ocr", "wcd", !clockwise);
    _cyclicPermutation("rcdl", "ycul", "ocur", "wcdr", !clockwise);
    _cyclicPermutation("redl", "yelu", "oeur", "werd", !clockwise);
}

void RubicksCube::_permutef(bool clockwise)
{
    _cyclicPermutation("reur", "yerd", "oedl", "welu", clockwise);
    _cyclicPermutation("rcur", "ycdr", "ocdl", "wcul", clockwise);
    _cyclicPermutation("rcr", "ycd", "ocl", "wcu", clockwise);
    _cyclicPermutation("rcdr", "ycdl", "ocul", "wcur", clockwise);
    _cyclicPermutation("redr", "yeld", "oeul", "weru", clockwise);
}

void RubicksCube::_translateElement(QString key)
{
    _rotateMomentalSide(key);
    _rotateMomentalToGreen(key);
    _rotateMomentalToTarget(key);
}

void RubicksCube::setSolved()
{
    CubeElements = QMap<QString, Element>{
    {"galu", Element(0,0,0, "green")},    {"geul", Element(0,0,0, "green")},    {"geuc", Element(0,0,0,"green")},     {"geur", Element(0,0,0,"green")},     {"garu", Element(0,0,0,"green")},
    {"gelu", Element(0,0,0, "green")},    {"gcul", Element(0,0,0, "green")},    {"gcu", Element(0,0,0,"green")},      {"gcur", Element(0,0,0,"green")},     {"geru", Element(0,0,0,"green")},
    {"gelc", Element(0,0,0, "green")},    {"gcl", Element(0,0,0, "green")},     {"gc", Element(0,0,0,"green")},       {"gcr", Element(0,0,0,"green")},      {"gerc", Element(0,0,0,"green")},
    {"geld", Element(0,0,0, "green")},    {"gcdl", Element(0,0,0, "green")},    {"gcd", Element(0,0,0,"green")},      {"gcdr", Element(0,0,0,"green")},     {"gerd", Element(0,0,0,"green")},
    {"gald", Element(0,0,0, "green")},    {"gedl", Element(0,0,0, "green")},    {"gedc", Element(0,0,0,"green")},     {"gedr", Element(0,0,0,"green")},     {"gard", Element(0,0,0,"green")},

    {"ralu", Element(0,-90,0, "red")},    {"reul", Element(0,-90,0, "red")},    {"reuc", Element(0,-90,0, "red")},    {"reur", Element(0,-90,0, "red")},    {"raru", Element(0,-90,0, "red")},
    {"relu", Element(0,-90,0, "red")},    {"rcul", Element(0,-90,0, "red")},    {"rcu", Element(0,-90,0, "red")},     {"rcur", Element(0,-90,0, "red")},    {"reru", Element(0,-90,0, "red")},
    {"relc", Element(0,-90,0, "red")},    {"rcl", Element(0,-90,0, "red")},     {"rc", Element(0,-90,0, "red")},      {"rcr", Element(0,-90,0, "red")},     {"rerc", Element(0,-90,0, "red")},
    {"reld", Element(0,-90,0, "red")},    {"rcdl", Element(0,-90,0, "red")},    {"rcd", Element(0,-90,0, "red")},     {"rcdr", Element(0,-90,0, "red")},    {"rerd", Element(0,-90,0, "red")},
    {"rald", Element(0,-90,0, "red")},    {"redl", Element(0,-90,0, "red")},    {"redc", Element(0,-90,0, "red")},    {"redr", Element(0,-90,0, "red")},    {"rard", Element(0,-90,0, "red")},\

    {"walu", Element(90,0,0,"white")},    {"weul", Element(90,0,0, "white")},   {"weuc", Element(90,0,0, "white")},   {"weur", Element(90,0,0, "white")},   {"waru", Element(90,0,0, "white")},
    {"welu", Element(90,0,0, "white")},   {"wcul", Element(90,0,0, "white")},   {"wcu", Element(90,0,0, "white")},    {"wcur", Element(90,0,0, "white")},   {"weru", Element(90,0,0, "white")},
    {"welc", Element(90,0,0, "white")},   {"wcl", Element(90,0,0, "white")},    {"wc", Element(90,0,0, "white")},     {"wcr", Element(90,0,0, "white")},    {"werc", Element(90,0,0, "white")},
    {"weld", Element(90,0,0, "white")},   {"wcdl", Element(90,0,0, "white")},   {"wcd", Element(90,0,0, "white")},    {"wcdr", Element(90,0,0, "white")},   {"werd", Element(90,0,0, "white")},
    {"wald", Element(90,0,0, "white")},   {"wedl", Element(90,0,0, "white")},   {"wedc", Element(90,0,0, "white")},   {"wedr", Element(90,0,0, "white")},   {"ward", Element(90,0,0, "white")},

    {"oalu", Element(0,90,0, "orange")},  {"oeul", Element(0,90,0, "orange")},  {"oeuc", Element(0,90,0, "orange")},  {"oeur", Element(0,90,0, "orange")},  {"oaru", Element(0,90,0, "orange")},
    {"oelu", Element(0,90,0, "orange")},  {"ocul", Element(0,90,0, "orange")},  {"ocu", Element(0,90,0, "orange")},   {"ocur", Element(0,90,0, "orange")},  {"oeru", Element(0,90,0, "orange")},
    {"oelc", Element(0,90,0, "orange")},  {"ocl", Element(0,90,0, "orange")},   {"oc", Element(0,90,0, "orange")},    {"ocr", Element(0,90,0, "orange")},   {"oerc", Element(0,90,0, "orange")},
    {"oeld", Element(0,90,0, "orange")},  {"ocdl", Element(0,90,0, "orange")},  {"ocd", Element(0,90,0, "orange")},   {"ocdr", Element(0,90,0, "orange")},  {"oerd", Element(0,90,0, "orange")},
    {"oald", Element(0,90,0, "orange")},  {"oedl", Element(0,90,0, "orange")},  {"oedc", Element(0,90,0, "orange")},  {"oedr", Element(0,90,0, "orange")},  {"oard", Element(0,90,0, "orange")},

    {"balu", Element(180,0,0, "blue")},   {"beul", Element(180,0,0, "blue")},   {"beuc", Element(180,0,0, "blue")},   {"beur", Element(180,0,0, "blue")},   {"baru", Element(180,0,0, "blue")},
    {"belu", Element(180,0,0, "blue")},   {"bcul", Element(180,0,0, "blue")},   {"bcu", Element(180,0,0, "blue")},    {"bcur", Element(180,0,0, "blue")},   {"beru", Element(180,0,0, "blue")},
    {"belc", Element(180,0,0, "blue")},   {"bcl", Element(180,0,0, "blue")},    {"bc", Element(180,0,0, "blue")},     {"bcr", Element(180,0,0, "blue")},    {"berc", Element(180,0,0, "blue")},
    {"beld", Element(180,0,0, "blue")},   {"bcdl", Element(180,0,0, "blue")},   {"bcd", Element(180,0,0, "blue")},    {"bcdr", Element(180,0,0, "blue")},   {"berd", Element(180,0,0, "blue")},
    {"bald", Element(180,0,0, "blue")},   {"bedl", Element(180,0,0, "blue")},   {"bedc", Element(180,0,0, "blue")},   {"bedr", Element(180,0,0, "blue")},   {"bard", Element(180,0,0, "blue")},

    {"yalu", Element(-90,0,0, "yellow")}, {"yeul", Element(-90,0,0, "yellow")}, {"yeuc", Element(-90,0,0, "yellow")}, {"yeur", Element(-90,0,0, "yellow")}, {"yaru", Element(-90,0,0, "yellow")},
    {"yelu", Element(-90,0,0, "yellow")}, {"ycul", Element(-90,0,0, "yellow")}, {"ycu", Element(-90,0,0, "yellow")},  {"ycur", Element(-90,0,0, "yellow")}, {"yeru", Element(-90,0,0, "yellow")},
    {"yelc", Element(-90,0,0, "yellow")}, {"ycl", Element(-90,0,0, "yellow")},  {"yc", Element(-90,0,0, "yellow")},   {"ycr", Element(-90,0,0, "yellow")},  {"yerc", Element(-90,0,0, "yellow")},
    {"yeld", Element(-90,0,0, "yellow")}, {"ycdl", Element(-90,0,0, "yellow")}, {"ycd", Element(-90,0,0, "yellow")},  {"ycdr", Element(-90,0,0, "yellow")}, {"yerd", Element(-90,0,0, "yellow")},
    {"yald", Element(-90,0,0, "yellow")}, {"yedl", Element(-90,0,0, "yellow")}, {"yedc", Element(-90,0,0, "yellow")}, {"yedr", Element(-90,0,0, "yellow")}, {"yard", Element(-90,0,0, "yellow")}};


    CurrState = QMap<QString, QString>{
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

    solution = {};
    currStepOfSolution = 0;

    currMoveText = "";
    nextSolutionMoves = "";
    prevSolutionMoves = "";

    emit solutionTextChanged();
    isFirstMove = true;
    isLastMove = true;
    emit moveChanged();
}

void RubicksCube::solve()
{
    currStepOfSolution = 0;
    solution = solver->Solution(CurrState);
    if (solution.size() == 0) {
        prevSolutionMoves = "";
        currMoveText = "";
        nextSolutionMoves = "";
    }
    else {
        setSolutionText();
    }

    amountOfMovesInSolution = solution.size();
    emit solutionTextChanged();

    isLastMove = (solution.size() == currStepOfSolution);
    isFirstMove = true;

    emit moveChanged();
}

void RubicksCube::onForwardClicked()
{
    if (currStepOfSolution == solution.size()) {
        onStartStopClicked();
        return;
    }

    if (solution[currStepOfSolution] == "U") animateRotU();
    else if (solution[currStepOfSolution] == "U'") animateRotUSt();
    else if (solution[currStepOfSolution] == "R") animateRotR();
    else if (solution[currStepOfSolution] == "R'") animateRotRSt();
    else if (solution[currStepOfSolution] == "F") animateRotF();
    else if (solution[currStepOfSolution] == "F'") animateRotFSt();
    else if (solution[currStepOfSolution] == "D") animateRotD();
    else if (solution[currStepOfSolution] == "D'") animateRotDSt();
    else if (solution[currStepOfSolution] == "L") animateRotL();
    else if (solution[currStepOfSolution] == "L'") animateRotLSt();
    else if (solution[currStepOfSolution] == "B") animateRotB();
    else if (solution[currStepOfSolution] == "B'") animateRotBSt();
    else if (solution[currStepOfSolution] == "u") animateRotu();
    else if (solution[currStepOfSolution] == "u'") animateRotuSt();
    else if (solution[currStepOfSolution] == "r") animateRotr();
    else if (solution[currStepOfSolution] == "r'") animateRotrSt();
    else if (solution[currStepOfSolution] == "f") animateRotf();
    else if (solution[currStepOfSolution] == "f'") animateRotfSt();
    else if (solution[currStepOfSolution] == "d") animateRotd();
    else if (solution[currStepOfSolution] == "d'") animateRotdSt();
    else if (solution[currStepOfSolution] == "l") animateRotl();
    else if (solution[currStepOfSolution] == "l'") animateRotlSt();
    else if (solution[currStepOfSolution] == "b") animateRotb();
    else if (solution[currStepOfSolution] == "b'") animateRotbSt();
    currStepOfSolution++;

    isLastMove = (currStepOfSolution == solution.size());
    isFirstMove = false;

    emit moveChanged();

    setSolutionText();
}

void RubicksCube::onBackClicked()
{
    if (solution[currStepOfSolution - 1] == "U") animateRotUSt();
    else if (solution[currStepOfSolution - 1] == "U'") animateRotU();
    else if (solution[currStepOfSolution - 1] == "R") animateRotRSt();
    else if (solution[currStepOfSolution - 1] == "R'") animateRotR();
    else if (solution[currStepOfSolution - 1] == "F") animateRotFSt();
    else if (solution[currStepOfSolution - 1] == "F'") animateRotF();
    else if (solution[currStepOfSolution - 1] == "D") animateRotDSt();
    else if (solution[currStepOfSolution - 1] == "D'") animateRotD();
    else if (solution[currStepOfSolution - 1] == "L") animateRotLSt();
    else if (solution[currStepOfSolution - 1] == "L'") animateRotL();
    else if (solution[currStepOfSolution - 1] == "B") animateRotBSt();
    else if (solution[currStepOfSolution - 1] == "B'") animateRotB();
    else if (solution[currStepOfSolution - 1] == "u") animateRotuSt();
    else if (solution[currStepOfSolution - 1] == "u'") animateRotu();
    else if (solution[currStepOfSolution - 1] == "r") animateRotrSt();
    else if (solution[currStepOfSolution - 1] == "r'") animateRotr();
    else if (solution[currStepOfSolution - 1] == "f") animateRotfSt();
    else if (solution[currStepOfSolution - 1] == "f'") animateRotf();
    else if (solution[currStepOfSolution - 1] == "d") animateRotdSt();
    else if (solution[currStepOfSolution - 1] == "d'") animateRotd();
    else if (solution[currStepOfSolution - 1] == "l") animateRotlSt();
    else if (solution[currStepOfSolution - 1] == "l'") animateRotl();
    else if (solution[currStepOfSolution - 1] == "b") animateRotbSt();
    else if (solution[currStepOfSolution - 1] == "b'") animateRotb();
    currStepOfSolution--;

    isFirstMove = (currStepOfSolution == 0);
    isLastMove = false;

    emit moveChanged();

    setSolutionText();
}

void RubicksCube::disableSolveButtons()
{
    solveButtonsDisabler->start(250);
    isLastMove = true;
    isFirstMove = true;
    emit moveChanged();
}

void RubicksCube::onStartStopClicked()
{
    isAutoAnimating = !isAutoAnimating;
    if (isAutoAnimating){
        animatingButtonText = "Стоп";
        autoAnimationTimer.start(250);
    }
    else {
        animatingButtonText = "Пуск";
        autoAnimationTimer.stop();
    }
    emit moveChanged();
    emit animatingButtonTextChanged();
}

qreal RubicksCube::_calcRotation(QString el)
{
    if (el == "lu" || el == "ul" || el == "uc" || el == "u") return 0;
    else if (el == "ur" || el == "ru" || el == "rc" || el == "r") return 90;
    else if (el == "dr" || el == "rd" || el == "dc" || el == "d") return 180;
    else if (el == "dl" || el == "ld" || el == "lc" || el == "l") return 270;
    return -1;
}

void RubicksCube::_rotateMomentalSide(QString key)
{
    Element& translatedElement = CubeElements[CurrState[key]];
    QString translatedElementCode = CurrState[key];
    qreal sideRotatation = _calcRotation(key.sliced(2)) - _calcRotation(CurrState[key].sliced(2));
    bool clockwise = (sideRotatation >= 0);
    sideRotatation = qAbs(sideRotatation);
    switch (CurrState[key][0].toLatin1()) {
    case 'g':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('z', clockwise);
        break;
    case 'o':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('x', clockwise);
        break;
    case 'r':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('x', !clockwise);
        break;
    case 'w':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('y', !clockwise);
        break;
    case 'y':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('y', clockwise);
        break;
    case 'b':
        for (int i = 0; i < sideRotatation / 90; ++i)
            translatedElement.momentalRotate('z', !clockwise);
        break;
    default:
        break;
    }
}

void RubicksCube::_rotateMomentalToGreen(QString key)
{
    Element& translatedElement = CubeElements[CurrState[key]];
    switch (CurrState[key][0].toLatin1()) {
    case 'g':
        break;
    case 'o':
        translatedElement.momentalRotate('y', true);
        break;
    case 'r':
        translatedElement.momentalRotate('y', false);
        break;
    case 'w':
        translatedElement.momentalRotate('x', true);
        break;
    case 'y':
        translatedElement.momentalRotate('x', false);
        break;
    case 'b':
        translatedElement.momentalRotate('x', false);
        translatedElement.momentalRotate('x', false);
        break;
    default:
        break;
    }
}

void RubicksCube::_rotateMomentalToTarget(QString key)
{
    Element& translatedElement = CubeElements[CurrState[key]];
    switch (key[0].toLatin1()) {
    case 'g':
        break;
    case 'o':
        translatedElement.momentalRotate('y', false);
        break;
    case 'r':
        translatedElement.momentalRotate('y', true);
        break;
    case 'w':
        translatedElement.momentalRotate('x', false);
        break;
    case 'y':
        translatedElement.momentalRotate('x', true);
        break;
    case 'b':
        translatedElement.momentalRotate('x', true);
        translatedElement.momentalRotate('x', true);
        break;
    default:
        break;
    }
}

bool RubicksCube::_validScramble(QStringList &scramble)
{
    for (auto& s : scramble) {
        if (s != "U" && s != "U'" && s != "F" && s != "F'" && s != "R" && s != "R'" &&
            s != "D" && s != "D'" && s != "B" && s != "B'" && s != "L" && s != "L'" &&
            s != "u" && s != "u'" && s != "f" && s != "f'" && s != "r" && s != "r'" &&
            s != "d" && s != "d'" && s != "b" && s != "b'" && s != "l" && s != "l'") return false;
    }
    return true;
}

void RubicksCube::_rotateByScramble(QStringList &parsedScramble)
{
    for (auto &s : parsedScramble) {
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

void RubicksCube::setSolutionText()
{
    prevSolutionMoves = "";
    currMoveText = currStepOfSolution == solution.size() ? "" : solution[currStepOfSolution];
    nextSolutionMoves = "";
    for (int i = qMax(0, currStepOfSolution - 5); i < currStepOfSolution; ++i) {
        prevSolutionMoves += solution[i];
    }
    for (int i = currStepOfSolution + 1; i < qMin(solution.size(), currStepOfSolution + 5); ++i) {
        nextSolutionMoves += solution[i];
    }
    emit solutionTextChanged();
}

