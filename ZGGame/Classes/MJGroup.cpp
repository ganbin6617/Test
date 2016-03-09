//
//  MJGroup.cpp
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#include "MJGroup.h"

static MJGroup *create_BJ()
{
    MJGroup *pRet = new MJGroup();
    if (pRet && pRet->init_BJ())
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

bool MJGroup::init_BJ()
{
    this->mjList = __Array::create();
    this->addType(MJType_Wang);
    this->addType(MJType_Tiao);
    this->addType(MJType_Tong);
    return this;
}



#pragma mark - 内部方法

void MJGroup::addType(MJType type)
{
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<9; j++) {
            MJ *mj = MJ::create(type, j);
            this->mjList->addObject(mj);
        }
    }
}
