//
//  UserPlayer.h
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#ifndef __ZGGame__UserPlayer__
#define __ZGGame__UserPlayer__

#include <stdio.h>
#include "Player.h"


class UserPlayer : public Player
{
public:
    virtual void think(MJAction action);
    virtual void outMJ();
    
#pragma mark - create
    virtual bool init();
    UserPlayer(){};
    CREATE_FUNC(UserPlayer);
    
    static bool create(__Dictionary *dic);
    
private:
    __Dictionary *info;
};

#endif /* defined(__ZGGame__UserPlayer__) */
