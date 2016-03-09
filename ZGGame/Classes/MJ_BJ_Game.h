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

class MJ_BJ_Game
{
    
private:
    
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
    
    
    //开始
    void start();
};

#endif /* defined(__ZGGame__MJ_BJ_Game__) */
