#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QMap>
#include <QVector>

class Language
{
private:
    QMap<int, QString> english;
    QMap<int, QString> russian;
    QMap<int, QString> german;
    QMap<int, QString> french;
    QMap<int, QString> arabian;
    QMap<int, QString> chineese;
    QMap<int, QString> belorussian;
    QMap<int, QString> ivrit;

    QString english1 = "`1234567890-=";
    QString english2 = "qwertyuiop[]";
    QString english3 = "asdfghjkl;'";
    QString english4 = "zxcvbnm,./";

    QString russian1 = "ё1234567890-=";
    QString russian2 = "йцукенгшщзхъ";
    QString russian3 = "фывапролджэ";
    QString russian4 = "ячсмитьбю.";

    QString german1 = "¹234567890ß´";
    QString german2 = "qwertzuiopü+";
    QString german3 = "asdfghjklöä";
    QString german4 = "yxcvbnm,.-";

    QString french1 = "²&é\"'(-è_çà)=";
    QString french2 = "azertyuiop^$";
    QString french3 = "qsdfghjklmù";
    QString french4 = "wxcvbn,;:!";

    QString arabian1 = "ذ1234567890-=";
    QString arabian2 = "ضصثقفغعهخحجد";
    QString arabian3 = "شسيبلاتنمكط";
    QString arabian4 = "ئءؤرلاىةوزظ";

    QString chineese1 = "`1234567890-=";
    QString chineese2 = "qwertyuiop[]";
    QString chineese3 = "asdfghjkl;'";
    QString chineese4 = "zxcvbnm,./";

    QString belorussian1 = "ё1234567890-=";
    QString belorussian2 = "йцукенгшўзх'";
    QString belorussian3 = "фывапролджэ";
    QString belorussian4 = "ячсмітьбю.";

    QString ivrit1 = ";1234567890-=";
    QString ivrit2 = "/'קראטוןםפ][";
    QString ivrit3 = "שדגכעיחלךף,";
    QString ivrit4 = "זסבהנמצתץ.";

public:
    Language();
    QMap<int, QString> getMap(int index);
    QVector<QString> getKeys (int index);

};

#endif // LANGUAGE_H
