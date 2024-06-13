#ifndef SPORT_TEAM_H
#define SPORT_TEAM_H

#include "qtypes.h"

constexpr qsizetype ABBREV_SIZE = 4;
constexpr qsizetype TEAM_SIZE = 11;

struct SportTeam
{
    int ratingPos;
    double winPercentage;
    char division;
    bool passedToChampionsLeague;
    char nameAbbreviation[ABBREV_SIZE];
    int playersNumbers[TEAM_SIZE];
};

#endif // SPORT_TEAM_H
