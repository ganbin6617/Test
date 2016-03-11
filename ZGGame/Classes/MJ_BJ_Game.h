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
#include "AIPlayer.h"
#include "UserPlayer.h"

#define GAME_PLAYER_COUNT   4
#define GAME_MJ_COUNT       13

class MJ_BJ_Game : public Ref
{
public:
    //开始
    void start();
    
    
    void test();
    
#pragma mark -create
    bool init(){return 1;};
    CREATE_FUNC(MJ_BJ_Game);
private:
//    MJGroup *mjGroup;           //牌组
    CC_SYNTHESIZE_RETAIN(MJGroup*, mjGroup, MjGroup);
    
//    __Array *playerList;        //玩家
    CC_SYNTHESIZE_RETAIN(__Array *,playerList,PlayerList);
    int zI;                     //庄
//    UserPlayer *userPlayer;
    CC_SYNTHESIZE_RETAIN(UserPlayer*, userPlayer,UserPlayer);
    
    
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
    
    //碰
    bool canPeng(Player *player, MJ *mj);
    //吃
    bool canChi(Player *player, MJ *mj);
    //胡
    bool canHu(Player *player, MJ *mj);
    //杠
    bool canGang(Player *player, MJ *mj);
    //遍历
    void each(__Array, SEL_CallFunc, MJ *mj);
    
    
    //定时器
//    void schedule(int);
    
    //下一位
    int nextPlayerIndex(int);

};

#endif /* defined(__ZGGame__MJ_BJ_Game__) */
