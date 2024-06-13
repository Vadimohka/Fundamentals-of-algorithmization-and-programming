#include<InsertionSort.h>

bool isMorePoints(Footballer* player_1, Footballer* player_2){
    return(player_1->getGoals() * 2 - player_1->getPenaltyPoints() <
            player_2->getGoals() * 2 - player_2->getPenaltyPoints());
}

bool isMoreGoals(Footballer* player_1, Footballer* player_2){
    return(player_1->getGoals()  < player_2->getGoals());
}

bool isMorePenalty(Footballer* player_1, Footballer* player_2){
    return(player_1->getPenaltyPoints()  < player_2->getPenaltyPoints());
}


