//
//  MJ.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/8.
//
//

#include "MJ.h"

#pragma 实例化

static MJ *create(MJType _type, int _num)
{
    MJ *pRet = new MJ(_type, _num);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

#pragma mark - 内部方法

