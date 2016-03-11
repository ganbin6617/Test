//
//  AIPlayer.h
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#ifndef __ZGGame__AIPlayer__
#define __ZGGame__AIPlayer__

#include <stdio.h>
#include "Player.h"

class AIPlayer : public Player
{
public:
    
    virtual void think(MJAction);
    virtual void outMJ();

#pragma mark - create
    virtual bool init();
    CREATE_FUNC(AIPlayer);
    
private:
    
};

#endif /* defined(__ZGGame__AI__) */
