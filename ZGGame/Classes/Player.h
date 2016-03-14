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


typedef enum {
    MJAction_Peng,
    MJAction_Chi,
    MJAction_Hu,
    MJAction_Gang,
    MJAction_Out,
}MJAction;

typedef void (Ref::*SEL_CallFun9)(int i, int j);

#define think_selector(_SELECTOR) (SEL_CallFun9)(&_SELECTOR)

class Player : public Ref
{
public:
    virtual bool init ();
    virtual void think(MJAction action, int zi);
    virtual void outMJ();
    
    CREATE_FUNC(Player);
    
public:
    bool isZ;                   //庄
    int delayTime;              //延时
    bool isAI;
    
    void setIsAI(bool);
    
//    __Array *handMJList;        //手牌
    CC_SYNTHESIZE_RETAIN(__Array *, handMJList, HandMJList);
    
//    __Array *disCardList;       //弃牌堆
    CC_SYNTHESIZE_RETAIN(__Array *, disCardList, DisCardList);
    

    // 回调的执行者
//    Ref *m_pListen;
    CC_SYNTHESIZE(Ref *, delegate, Delegate);
    
    // 回调函数指针
//    SEL_CallFun9 m_pfnSelectior;
    CC_SYNTHESIZE(SEL_CallFun9, m_pfnSelectior, M_pfnSelectior);
};


#endif /* defined(__ZGGame__Player__) */
