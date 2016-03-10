//
//  Player.h
//  ZGGame
//
//  Created by Thesy on 16/3/10.
//
//

#ifndef __ZGGame__Player__
#define __ZGGame__Player__

#include <stdio.h>
#include <cocos/cocos2d.h>
USING_NS_CC;

class Player : public Ref
{
public:
    virtual bool init ()
    {
        isZ = false;
        handMJList = __Array::create();
        disCardList = __Array::create();
    
        return 1;
    }
    
    virtual void think() = 0;
    
    
public:
    bool isZ;                   //庄
    
    __Array *handMJList;        //手牌
    __Array *disCardList;       //弃牌堆
    
};

#endif /* defined(__ZGGame__Player__) */
