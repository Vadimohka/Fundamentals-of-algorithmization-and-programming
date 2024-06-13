#ifndef USERPLAYER_H
#define USERPLAYER_H

#include "abstractplayer.h"

class UserPlayer : public AbstractPlayer
{
public:
    void say();

    UserPlayer(QString name, int balance);
};

#endif // USERPLAYER_H
