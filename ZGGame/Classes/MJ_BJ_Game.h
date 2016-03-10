//
//  MJ_BJ_Game.h
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#ifndef __ZGGame__MJ_BJ_Game__
#define __ZGGame__MJ_BJ_Game__

#include <stdio.h>
#include "MJGroup.h"

#define GAME_PLAYER_COUNT   4
#define GAME_MJ_COUNT       13

class MJ_BJ_Game : public Ref
{
public:
    //开始
    void start();
    
#pragma mark -create
    virtual bool init(){return 1;};
    MJ_BJ_Game(){};
    CREATE_FUNC(MJ_BJ_Game);
private:
    
    MJGroup *mjGroup;
    __Array *playerList;
    int zI;
    
    //玩家
    void readyPlayers();
    //准备
    void getMJGroup();
    //洗牌
    void washMJ();
    //码牌
    void buildMJ();
    //骰子
    void dice();
    //抓牌
    void gainMJ();
    
    //action
    void action();

};

#endif /* defined(__ZGGame__MJ_BJ_Game__) */
