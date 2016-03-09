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
    MJType_Wang,
    MJType_Tiao,
    MJType_Tong,
    MJType_Feng
}MJType;

class MJ : public Ref
{
public:
    
    MJType getMJType(){return this->type;};     //获取类型
    int getNUM(){return this->NUM;};            //获取NUM
//string *getName();
    
#pragma ----
    
    MJ(){};
    MJ(MJType _type,int _num){this->type = _type; this->NUM = _num;};
    ~MJ(){};
    virtual bool init(){return 1;};
    
public:
    static MJ *create(MJType _type, int _num);
    CREATE_FUNC(MJ);
private:
    string *name;
    MJType  type;
    int      NUM;
    
    
};

#endif /* defined(__ZGGame__MJ__) */
