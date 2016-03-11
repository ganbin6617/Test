//
//  MJ.h
//  ZGGame
//
//  Created by Thesy on 16/3/8.
//
//

#ifndef __ZGGame__MJ__
#define __ZGGame__MJ__

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace std;
USING_NS_CC;

//类型
typedef enum{
    MJType_Wang = 0,
    MJType_Tiao = 1,
    MJType_Tong = 2,
    MJType_Feng = 3
}MJType;

class MJ : public Ref
{
public:
    int     tnum;
    
    MJType getMJType(){return this->type;};     //获取类型
    int getNUM(){return this->NUM;};            //获取NUM
    __String *getName();
    
#pragma ----
    
    virtual bool init(){return 1;};
    CREATE_FUNC(MJ);

public:
    static MJ *create(MJType _type, int _num);
    
private:
    MJType  type;
    int      NUM;
    
};

#endif /* defined(__ZGGame__MJ__) */
