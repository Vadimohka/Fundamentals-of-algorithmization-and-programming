//
// Created by shosh on 5/26/24.
//

#include "SportTeam.h"

SportTeam::SportTeam(std::string initializer) {
    if (initializer.length() < 26) {
        count_of_players = 0;
        for (int & i : count_of_GOOOOOOLS) {
            i = 0;
        }
        coef_of_winning = 0;
        isDinamoPinsk = false;
        for (char & i : name) {
            i = '0';
        }
    }
    count_of_players = (unsigned char) initializer[1];
    coef_of_winning = (double)initializer[2];
    isDinamoPinsk = initializer[3] % 2;
    for (int i = 4; i < 14; i++) {
        name[i - 4] = initializer[i];
    }
    for (int i = 15; i < 25; i++) {
        count_of_GOOOOOOLS[i - 15] = initializer[i];
    }
}

SportTeam::SportTeam() {
    count_of_players = 0;
    for (int & i : count_of_GOOOOOOLS) {
        i = 0;
    }
    coef_of_winning = 0;
    isDinamoPinsk = false;
    for (char & i : name) {
        i = '0';
    }
}
