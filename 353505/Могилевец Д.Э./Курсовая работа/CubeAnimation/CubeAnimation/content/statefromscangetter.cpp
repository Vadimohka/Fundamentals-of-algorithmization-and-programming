#include "statefromscangetter.h"

StateFromScanGetter::StateFromScanGetter(QObject *parent)
    : QObject{parent}
{
    colorsPlaces =  QMap<QString,QString>{
    {"galu", "green"}, {"geul", "green"}, {"geuc", "green"}, {"geur", "green"}, {"garu", "green"},
    {"gelu", "green"}, {"gcul", "green"}, {"gcu", "green"},   {"gcur", "green"}, {"geru", "green"},
    {"gelc", "green"}, {"gcl", "green"},   {"gc", "green"},     {"gcr", "green"},   {"gerc", "green"},
    {"geld", "green"}, {"gcdl", "green"}, {"gcd", "green"},   {"gcdr", "green"}, {"gerd", "green"},
    {"gald", "green"}, {"gedl", "green"}, {"gedc", "green"}, {"gedr", "green"}, {"gard", "green"},

    {"ralu", "red"}, {"reul", "red"}, {"reuc", "red"}, {"reur", "red"}, {"raru", "red"},
    {"relu", "red"}, {"rcul", "red"}, {"rcu", "red"}, {"rcur", "red"}, {"reru", "red"},
    {"relc", "red"}, {"rcl", "red"}, {"rc", "red"}, {"rcr", "red"}, {"rerc", "red"},
    {"reld", "red"}, {"rcdl", "red"}, {"rcd", "red"}, {"rcdr", "red"}, {"rerd", "red"},
    {"rald", "red"}, {"redl", "red"}, {"redc", "red"}, {"redr", "red"}, {"rard", "red"},

    {"walu", "white"}, {"weul", "white"}, {"weuc", "white"}, {"weur", "white"}, {"waru", "white"},
    {"welu", "white"}, {"wcul", "white"}, {"wcu", "white"}, {"wcur", "white"}, {"weru", "white"},
    {"welc", "white"}, {"wcl", "white"}, {"wc", "white"}, {"wcr", "white"}, {"werc", "white"},
    {"weld", "white"}, {"wcdl", "white"}, {"wcd", "white"}, {"wcdr", "white"}, {"werd", "white"},
    {"wald", "white"}, {"wedl", "white"}, {"wedc", "white"}, {"wedr", "white"}, {"ward", "white"},

    {"balu", "blue"}, {"beul", "blue"}, {"beuc", "blue"}, {"beur", "blue"}, {"baru", "blue"},
    {"belu", "blue"}, {"bcul", "blue"}, {"bcu", "blue"},   {"bcur", "blue"}, {"beru", "blue"},
    {"belc", "blue"}, {"bcl", "blue"},   {"bc", "blue"},     {"bcr", "blue"},   {"berc", "blue"},
    {"beld", "blue"}, {"bcdl", "blue"}, {"bcd", "blue"},   {"bcdr", "blue"}, {"berd", "blue"},
    {"bald", "blue"}, {"bedl", "blue"}, {"bedc", "blue"}, {"bedr", "blue"}, {"bard", "blue"},

    {"oalu", "orange"}, {"oeul", "orange"}, {"oeuc", "orange"}, {"oeur", "orange"}, {"oaru", "orange"},
    {"oelu", "orange"}, {"ocul", "orange"}, {"ocu", "orange"}, {"ocur", "orange"}, {"oeru", "orange"},
    {"oelc", "orange"}, {"ocl", "orange"}, {"oc", "orange"}, {"ocr", "orange"}, {"oerc", "orange"},
    {"oeld", "orange"}, {"ocdl", "orange"}, {"ocd", "orange"}, {"ocdr", "orange"}, {"oerd", "orange"},
    {"oald", "orange"}, {"oedl", "orange"}, {"oedc", "orange"}, {"oedr", "orange"}, {"oard", "orange"},

    {"yalu", "yellow"}, {"yeul", "yellow"}, {"yeuc", "yellow"}, {"yeur", "yellow"}, {"yaru", "yellow"},
    {"yelu", "yellow"}, {"ycul", "yellow"}, {"ycu", "yellow"}, {"ycur", "yellow"}, {"yeru", "yellow"},
    {"yelc", "yellow"}, {"ycl", "yellow"}, {"yc", "yellow"}, {"ycr", "yellow"}, {"yerc", "yellow"},
    {"yeld", "yellow"}, {"ycdl", "yellow"}, {"ycd", "yellow"}, {"ycdr", "yellow"}, {"yerd", "yellow"},
    {"yald", "yellow"}, {"yedl", "yellow"}, {"yedc", "yellow"}, {"yedr", "yellow"}, {"yard", "yellow"}};

    _setDefaultState();

    foundElements = QMap<QString, bool> {
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
        {"yald", "yald"}, {"yedl", "yedl"}, {"yedc", "yedc"}, {"yedr", "yedr"}, {"yard", "yard"}
    };

    _setAllUnfound();
}

StateFromScanGetter* StateFromScanGetter::_instance = nullptr;

StateFromScanGetter *StateFromScanGetter::GetInstance()
{
    if (_instance == nullptr) {
        _instance = new StateFromScanGetter();
    }
    return _instance;
}

void StateFromScanGetter::setColor(QString elementKey, QString color)
{
    colorsPlaces[elementKey] = color.first(color.size() - 4);
}

QMap<QString, QString> StateFromScanGetter::getState()
{
    return state;
}

void StateFromScanGetter::_setDefaultState()
{
    state = QMap<QString, QString>{
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
}

void StateFromScanGetter::_setAllUnfound()
{
    for (auto& element : foundElements) {
        element = false;
    }

    foundElements["gc"] = true;
    foundElements["rc"] = true;
    foundElements["yc"] = true;
    foundElements["bc"] = true;
    foundElements["oc"] = true;
    foundElements["wc"] = true;
}

bool StateFromScanGetter::_setEdgesFound(QString &key)
{
    if (contradictiveColors[colorsPlaces[key]] == colorsPlaces[jsonEdges[key]]) return false;
    QString currElementCode = colorsPlaces[key][0];
    currElementCode += "e";
    QString side = defineSideOfEdge(colorsPlaces[key] + colorsPlaces[jsonEdges[key]]);
    currElementCode += side;
    currElementCode += defineFamilyOfEdge(key, side[0]);
    state[key] = currElementCode;
    foundElements[currElementCode] = true;
    foundElements[jsonEdges[currElementCode]] = true;
    state[jsonEdges[key]] = jsonEdges[currElementCode];
    return true;
}

bool StateFromScanGetter::_setAnglesFound(QString &key)
{
    QSet<QString> keyAngle{};
    for(auto& el : angles) {
        if (el.contains(key)){
            keyAngle = el;
            break;
        }
    }
    QSet<QString> colors;
    for (QString coord : keyAngle) {
        colors.insert(colorsPlaces[coord]);
    }
    QSet<QString> elCodes = anglesCodes(colors);
    if (elCodes.size() == 1) return false;
    for (QString code : elCodes) {
        if (code[0] == colorsPlaces[key][0]) {
            foundElements[code] = true;
            state[key] = code;
            return true;
        }
    }
    return true;
}

bool StateFromScanGetter::_setCenterFound(QString &key)
{
    if (key.size() == 2) return true;
    QString colorInd = colorsPlaces[key][0];
    colorInd += "c";
    if (key.size() == 3) {
        if (!foundElements[colorInd + "u"]) {
            foundElements[colorInd + "u"] = true;
            state[key] = colorInd + "u";
            return true;
        }
        else if (!foundElements[colorInd + "r"]) {
            foundElements[colorInd + "r"] = true;
            state[key] = colorInd + "r";
            return true;
        }
        else if (!foundElements[colorInd + "d"]) {
            foundElements[colorInd + "d"] = true;
            state[key] = colorInd + "d";
            return true;
        }
        else if (!foundElements[colorInd + "l"]) {
            foundElements[colorInd + "l"] = true;
            state[key] = colorInd + "l";
            return true;
        }
        else return false;
    }
    else {
        if (!foundElements[colorInd + "ul"]) {
            foundElements[colorInd + "ul"] = true;
            state[key] = colorInd + "ul";
            return true;
        }
        else if (!foundElements[colorInd + "ur"]) {
            foundElements[colorInd + "ur"] = true;
            state[key] = colorInd + "ur";
            return true;
        }
        else if (!foundElements[colorInd + "dl"]) {
            foundElements[colorInd + "dl"] = true;
            state[key] = colorInd + "dl";
            return true;
        }
        else if (!foundElements[colorInd + "dr"]) {
            foundElements[colorInd + "dr"] = true;
            state[key] = colorInd + "dr";
            return true;
        }
        else return false;
    }
    return true;
}

QString StateFromScanGetter::defineSideOfEdge(QString colors)
{
    if (colors == "greenyellow" || colors == "whitegreen" || colors == "redyellow" ||
        colors == "orangeyellow" || colors == "yellowblue" || colors == "bluewhite") return "u";
    else if (colors == "greenred" || colors == "yellowred" || colors == "orangegreen" ||
             colors == "bluered" || colors == "whitered" || colors == "redblue") return "l";
    else if (colors == "greenwhite" || colors == "redwhite" || colors == "yellowgreen" ||
             colors == "blueyellow" || colors == "orangewhite" || colors == "whiteblue") return "d";
    else return "r";
}

QString StateFromScanGetter::defineFamilyOfEdge(QString key, QChar side)
{
    QString surname = key.last(2);
    if (surname == "ul" || surname == "ru" || surname == "dr" || surname == "ld") {
        switch (side.toLatin1()) {
        case 'u':
            return "l";
            break;
        case 'r':
            return "u";
            break;
        case 'd':
            return "r";
            break;
        case 'l':
            return "d";
            break;
        default:
            break;
        }
    }
    else if (surname == "ur" || surname == "rd" || surname == "dl" || surname == "lu") {
        switch (side.toLatin1()) {
        case 'u':
            return "r";
            break;
        case 'r':
            return "d";
            break;
        case 'd':
            return "l";
            break;
        case 'l':
            return "u";
            break;
        default:
            break;
        }
    }
    else return "c";
    return "0";
}

QSet<QString> StateFromScanGetter::anglesCodes(QSet<QString> anglesColors)
{
    if (anglesColors == QSet<QString>{"yellow", "green", "red"}) return angles[0];
    else if (anglesColors == QSet<QString>{"yellow", "green", "orange"}) return angles[1];
    else if (anglesColors == QSet<QString>{"white", "green", "orange"}) return angles[2];
    else if (anglesColors == QSet<QString>{"white", "green", "red"}) return angles[3];

    else if (anglesColors == QSet<QString>{"yellow", "blue", "red"}) return angles[4];
    else if (anglesColors == QSet<QString>{"yellow", "blue", "orange"}) return angles[5];
    else if (anglesColors == QSet<QString>{"white", "blue", "orange"}) return angles[6];
    else if (anglesColors == QSet<QString>{"white", "blue", "red"}) return angles[7];

    else return {"ERROR"};
}

bool StateFromScanGetter::_allFound()
{
    for (auto el : foundElements) if (!el) return false;
    return true;
}

bool StateFromScanGetter::stateIsValid()
{
    _setAllUnfound();
    for (auto& key : colorsPlaces.keys()){
        switch(key[1].toLatin1()) {
        case 'c':
            if (!_setCenterFound(key)){
                return false;
            }
            break;
        case 'e':
            if (!_setEdgesFound(key)) {
                return false;
            }
            break;
        case 'a':
            if (!_setAnglesFound(key)) {
                return false;
            }
            break;
        }
    }
    Solver solver;
    return (solver.Solution(state) != QStringList{"FATAL ERROR"});
}
