#include "TTKeyDict.h"
#include "Common.h"
#include <QTextStream>
#include <qapplication.h>
#include <qcontainerfwd.h>
#include <qguiapplication.h>
#include <qinputmethod.h>
#include <qlocale.h>
#include <qnamespace.h>
#include <QDebug>

TTKeyDict::TTKeyDict() {

//     auto lines = parse_src.split('\n');
//     for(auto l : lines){
//         auto chars = l.split(' ');
//          qDebug() << chars;
//         for(int i = 0; i < chars.size(); ++i){
//             if(chars[i].isEmpty()){
//                 continue;
//             }
//             universal_map[ chars[i] ] = i;
//         }
//     }
// }
// {
//     for(auto l : azerty_src){
//         auto chars = l.split(' ');
//         qDebug() << chars;
//         for(int i = 0; i < chars.size(); ++i){
//             azerty_map[ chars[i] ] = i;
//         }
//     }
// }

auto lines = parse_src.split('\n');

registerKeys(lines[0].split(' '), Common::Locale::Chinese);
registerKeys(lines[1].split(' '), Common::Locale::Chinese);
registerKeys(lines[2].split(' '), Common::Locale::German);
registerKeys(lines[3].split(' '), Common::Locale::German);
registerKeys(lines[4].split(' '), Common::Locale::Arabic);
registerKeys(lines[5].split(' '), Common::Locale::Arabic);
registerKeys(lines[6].split(' '), Common::Locale::Hebrew);
registerKeys(lines[7].split(' '), Common::Locale::Belarussian);
registerKeys(lines[8].split(' '), Common::Locale::Belarussian);
registerKeys(lines[9].split(' '), Common::Locale::French);
registerKeys(lines[10].split(' '), Common::Locale::French);
//registerKeys(lines[11].split(' '), Common::Locale::Chinese);
}


void TTKeyDict::registerKeys(QStringList chars, Common::Locale loc){
    auto ind = static_cast<int>(loc);
    for(int i = 0; i < chars.size(); ++i){
        auto cur = chars[i];
        locale_maps[ind][cur] = i;
    }
}

int TTKeyDict::getKey(QChar c, Common::Locale loc){
    auto ind = static_cast<int>(loc);
    auto val = locale_maps[ind].value(c, -1);
    if(val == -1){
        for(int i = 0; i < 6; ++i){
            val = locale_maps[i].value(c, -1);
            if(val != -1){
                return val;
            }
        }
    }
    return val;
}

QString TTKeyDict::getLocString(Common::Locale loc){
    switch (loc) {
        case Common::Locale::Belarussian:
            return src[3];
            case Common::Locale::French:
            return azerty_src[0];
            case Common::Locale::Arabic:
            return src[2];
            case Common::Locale::German:
            return src[1];
            case Common::Locale::Chinese:
            return src[5];
            case Common::Locale::Hebrew:
            return src[4];
    }
    return src[1];
}