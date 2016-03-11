//
//  AI.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#include "AIPlayer.h"

bool AIPlayer::init (){
    isAI = true;
    delayTime = 1;
    return Player::init();
};

void AIPlayer::think(MJAction action)
{
    
}

void AIPlayer::outMJ()
{

}