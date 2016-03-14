//
//  MJ_BJ_Game.cpp
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#include "MJ_BJ_Game.h"


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
    action(zI);
}

void MJ_BJ_Game::readyPlayers()
{
    setPlayerList(__Array::create());
        
    setUserPlayer(Player::create());
    getPlayerList()->addObject(userPlayer);
    
    for (int i = 1; i<GAME_PLAYER_COUNT; i++) {
        Player *aiPlayer = Player::create();
        aiPlayer->setIsAI(true);
        aiPlayer->setDelegate(this);
        aiPlayer->setM_pfnSelectior(think_selector(MJ_BJ_Game::callBack));
        getPlayerList()->addObject(aiPlayer);
    }
}

//准备
void MJ_BJ_Game::getMJGroup()
{
    setMjGroup(MJGroup::create_BJ());
}

//洗牌
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
    zI = 3;
}

//抓牌
void MJ_BJ_Game::gainMJ()
{
    for (int i = 0; i<GAME_PLAYER_COUNT; i++) {
        
        Player *player = (Player *)playerList->getObjectAtIndex(i);
        
        for (int j = 0; j<GAME_MJ_COUNT; j++) {
            player->getHandMJList()->addObject(mjGroup->getMjList()->getObjectAtIndex(j));
        }
        mjGroup->getMjList()->removeObjectsInArray(player->getHandMJList());
        MJGroup::sort(player->getHandMJList());
    }
    
//    for (int i = 0; i<4; i++) {
//        Player *player = (Player *)playerList->getObjectAtIndex(i);
//        MJGroup::show(player->handMJList);
//    }
    
    MJGroup::show(userPlayer->getHandMJList());

}


//action
void MJ_BJ_Game::action(int index)
{
//    while (mjGroup->getMjList()->count()>0){
    if (mjGroup->getMjList()->count() <=0 ) {
        cout<<"荒";
        return;
    }
    
        Player *player = (Player *)playerList->getObjectAtIndex(index);
        
        
        //显示
        cout<<"---------";
        MJGroup::show(player->getHandMJList());
        
        //抓牌

        MJGroup::showm((MJ*)mjGroup->getMjList()->getObjectAtIndex(0));
        
        player->getHandMJList()->addObject(mjGroup->getMjList()->getObjectAtIndex(0));
        mjGroup->getMjList()->removeObjectAtIndex(0);
        
        
        if(player->isAI)player->think(MJAction_Out, index);

        
        /*
        while (player->getHandMJList()->count() == GAME_MJ_COUNT) {
            
            
            for (int i = nextPlayerIndex(index); i<index; ) {
                
                Player *p = (Player *)playerList->getObjectAtIndex(i);
                
                canHu(p, NULL);
                
                i = nextPlayerIndex(i);
            }
            
            index = nextPlayerIndex(index);

            break;
        }
        */
//    }
}

void MJ_BJ_Game::callBack(int zi, int index)
{
    CCLOG("%zd, %zd",zi, index);
    Player *player = (Player *)playerList->getObjectAtIndex(zi);
    player->getHandMJList()->removeObjectAtIndex(index);
    
    int _nextZi = nextPlayerIndex(zi);
    
    action(_nextZi);
}

void MJ_BJ_Game::test()
{
    if (userPlayer->getHandMJList()->count()>GAME_MJ_COUNT) {
        userPlayer->getHandMJList()->removeLastObject();
        
        int _nextZi = nextPlayerIndex(0);
        action(_nextZi);
    }
}

#pragma mark -


//碰
bool MJ_BJ_Game::canPeng(Player *player, MJ *mj)
{
    
}

//吃
bool MJ_BJ_Game::canChi(Player *player, MJ *mj)
{
    
}

//胡
bool MJ_BJ_Game::canHu(Player *player, MJ *mj)
{
    
}

//杠
bool MJ_BJ_Game::canGang(Player *player, MJ *mj)
{
}

void MJ_BJ_Game::each(__Array, SEL_CallFunc, MJ *mj)
{
    
}

int MJ_BJ_Game::nextPlayerIndex(int index)
{
    int nIndex = index;
    nIndex ++;
    if (nIndex > GAME_PLAYER_COUNT-1) {
        nIndex = 0;
    }
    return nIndex;
}
