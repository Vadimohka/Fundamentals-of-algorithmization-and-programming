#ifndef PROJECTCLASS_H
#define PROJECTCLASS_H

#include<QtWidgets>

class projectclass
{
private:
    QString number_of_people;
    QString name;
    QString age;
    QString height;
    QString weight;
    QString habits;
    QString hobby;
    QString age_min;
    QString age_max;
    QString height_min;
    QString height_max;
    QString weight_min;
    QString weight_max;
    QString Odin_or_Odna;

public:
    projectclass() = default;

    QString get_number_of_people();
    void set_number_of_people(QString info);

    QString get_name();
    void set_name(QString info);

    QString get_age();
    void set_age(QString info);

    QString get_height();
    void set_height(QString info);

    QString get_weight();
    void set_weight(QString info);

    QString get_habits();
    void set_habits(QString info);

    QString get_hobby();
    void set_hobby(QString info);

    QString get_age_min();
    void set_age_min(QString info);

    QString get_age_max();
    void set_age_max(QString info);

    QString get_height_min();
    void set_height_min(QString info);

    QString get_height_max();
    void set_height_max(QString info);

    QString get_weight_min();
    void set_weight_min(QString info);

    QString get_weight_max();
    void set_weight_max(QString info);

    QString get_Odin_or_Odna();
    void set_Odin_or_Odna(QString info);

    QString get_All_Info();


};

#endif // PROJECTCLASS_H
