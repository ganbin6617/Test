//
//  MJ_BJ_Game.cpp
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#include "MJ_BJ_Game.h"
#include "AIPlayer.h"
#include "UserPlayer.h"

void MJ_BJ_Game::start()
{
    //人
    readyPlayers();
    //准备
    getMJGroup();
    //洗牌
    washMJ();
    //码牌
    buildMJ();
    //骰子
    dice();
    //抓牌
    gainMJ();

    //action
//    action();
}

void MJ_BJ_Game::readyPlayers()
{
    playerList = __Array::create();
    
    for (int i = 0; i<GAME_PLAYER_COUNT; i++) {
        AIPlayer *aiPlayer = AIPlayer::create();
        playerList->addObject(aiPlayer);
    }
    
}

void MJ_BJ_Game::getMJGroup()
{
    mjGroup = MJGroup::create_BJ();
}

void MJ_BJ_Game::washMJ()
{
    mjGroup->wash();
}

void MJ_BJ_Game::buildMJ()
{

}

void MJ_BJ_Game::dice()
{
    zI = rand()%GAME_PLAYER_COUNT;
}

void MJ_BJ_Game::gainMJ()
{
    for (int i = 0; i<GAME_PLAYER_COUNT; i++) {
        
        Player *player = (Player *)playerList->getObjectAtIndex(i);
        
        for (int j = 0; j<GAME_MJ_COUNT; j++) {
            player->handMJList->addObject(mjGroup->mjList->getObjectAtIndex(j));
        }
        mjGroup->mjList->removeObjectsInArray(player->handMJList);
        MJGroup::sort(player->handMJList);
    }
}


//action
void MJ_BJ_Game::action()
{
    while (mjGroup->mjList->count()>0) {
        
        Player *player = (Player *)playerList->getObjectAtIndex(zI);
        
        //显示
        cout<<"---------";
        MJGroup::show(player->handMJList);
        
        //抓牌

        MJGroup::showm((MJ*)mjGroup->mjList->getObjectAtIndex(0));
        
        player->handMJList->addObject(mjGroup->mjList->getObjectAtIndex(0));
        mjGroup->mjList->removeObjectAtIndex(0);
        
        
        player->think();
        
    }
}
