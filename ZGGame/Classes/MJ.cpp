//
//  MJ.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/8.
//
//

#include "MJ.h"

#pragma 实例化

//初始化
MJ *MJ::init(MJType _type, int _num)
{
    MJ *mj = new MJ();
    mj->type = _type;
    mj->NUM = _num;
    return mj;
}

//获取类型
MJType MJ::getMJType()
{
    return this->type;
}

//获取NUM
int MJ::getNUM()
{
    return this->NUM;
}

#pragma mark - 内部方法

