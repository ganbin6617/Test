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

}