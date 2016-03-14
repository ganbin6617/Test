//
//  Player.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#include "Player.h"


bool Player::init ()
{
    isZ = false;
    setHandMJList(__Array::create());
    setDisCardList(__Array::create());

    return true;
}

void Player::setIsAI(bool _isAI)
{
    isAI = _isAI;
    if(isAI)
    {
        delayTime = 1;
    }
    else
    {
        delayTime = 10;
    }
    
}


void Player::think(MJAction action, int zi)
{
    (getDelegate()->*getM_pfnSelectior())(zi, 1);
}

void Player::outMJ()
{
    
}
