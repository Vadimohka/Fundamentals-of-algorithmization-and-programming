//
// Created by shosh on 5/26/24.
//

#ifndef LABWORK6_SPORTTEAM_H
#define LABWORK6_SPORTTEAM_H
#include "string"

class SportTeam {
public:
    int count_of_players;
    double coef_of_winning;
    bool isDinamoPinsk;
    char name[10];
    int count_of_GOOOOOOLS[10];
    explicit SportTeam(std::string initializer);
    SportTeam();
};


#endif //LABWORK6_SPORTTEAM_H
