//
//  MJ.cpp
//  ZGGame
//
//  Created by Thesy on 16/3/8.
//
//

#include "MJ.h"

#pragma 实例化

MJ *MJ::create(MJType _type, int _num)
{
    MJ *mj = MJ::create();
    mj->type = _type;
    mj->NUM = _num;
    mj->tnum = (int)(mj->type)*10+mj->NUM;
    return mj;
}

__String *MJ::getName()
{
    __String *name = __String::create("");
        
    string s = "一二三四五六七八九";
    name->append(s.substr(NUM*3,3));
    
    switch (type) {
        case MJType_Wang:
            name->append("萬");
            break;
        case MJType_Tiao:
            name->append("条");
            break;
        case MJType_Tong:
            name->append("筒");
            break;
        case MJType_Feng:
        {

        }
            break;
        default:
            break;
    }
    return name;
}

#pragma mark - 内部方法

