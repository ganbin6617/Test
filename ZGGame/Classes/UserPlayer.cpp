//
//  UserPlayer.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#include "UserPlayer.h"

bool UserPlayer::init(){
    isAI = false;
    delayTime = 10;
    
    return Player::init();
};

bool UserPlayer::create(__Dictionary *dic)
{
    UserPlayer *player = UserPlayer::create();
    player->info = __Dictionary::createWithDictionary(dic);
    return player;
}

void UserPlayer::think(MJAction action)
{
    
}

void UserPlayer::outMJ()
{
    
}

