#include <student.h>
#include <QDebug>

Student::Student(QString name, QString speciality, QString group, int oaip_mark, int ma_mark, int agila_mark, int ml_mark, int hist_mark) {
    this->name = name;
    this->speciality = speciality;
    this->group = group;
    this->oaip_mark = oaip_mark;
    this->ma_mark = ma_mark;
    this->agila_mark = agila_mark;
    this->ml_mark = ml_mark;
    this->hist_mark = hist_mark;
}

Student::Student(){

}

double Student::averageMark() {
    return (oaip_mark + ma_mark + agila_mark + ml_mark + hist_mark) / 5.;
}

bool Student::isNameCorrect() {
    int c = 0;

    if (name.isEmpty()) {
        return false;
    }

    for (int i = 0; i < name.length(); i++) {
        if (name[i].isLetter()) {
            if (i == 0) {
                if (!name[i].isUpper()) {
                    return false;
                } else {
                    continue;
                }
            } else if (name[i - 1] == ' ') {
                if (!name[i].isUpper()) {
                    return false;
                } else {
                    continue;
                }
            } else if (name[i].isUpper()) {
                return false;
            }
        } else if (name[i] == ' ') {
            c++;
            if (c > 2) {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

bool Student::isSpecCorrect() {
    if (speciality.isEmpty()) {
        return false;
    }

    for (int i = 0; i < speciality.length(); i++) {
        if (!(name[i].isLetter() || name[i] == ' ')) {
            return false;
        }
    }

    return true;
}

bool Student::isGroupCorrect() {
    if (group.isEmpty()) {
        return false;
    }

    if (group.length() != 6) {
        return false;
    }

    for (int i = 0; i < group.length(); i++) {
        if (!group[i].isNumber()) {
            return false;
        }
    }

    return true;
}

QString Student::getInitials() {
    QString initials = "";
    int i = 0;

    while (name[i] != ' ') {
        initials+=name[i];
        i++;
    }

    initials += ' ';
    i++;

    initials += name[i] + '.';
    while (name[i] != ' ') {
        i++;
    }

    i++;
    initials += name[i] + '.';

    return initials;
}

QString Student::getName() {
    return this->name;
}

QString Student::getSpec() {
    return this->speciality;
}

QString Student::getGroup() {
    return this->group;
}

int Student::getOaip() {
    return this->oaip_mark;
}

int Student::getMa(){
    return this->ma_mark;
}

int Student::getAgila() {
    return this->agila_mark;
}

int Student::getMl() {
    return this->ml_mark;
}

int Student::getHist(){
    return this->hist_mark;
}
