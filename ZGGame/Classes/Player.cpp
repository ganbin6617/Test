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