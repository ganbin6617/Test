//
//  MJGroup.h
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#ifndef __ZGGame__MJGroup__
#define __ZGGame__MJGroup__

#include <stdio.h>
#include "MJ.h"
#include <cocos/cocos2d.h>

USING_NS_CC;

class MJGroup : public Ref
{
public:
//    __Array *mjList;
    CC_SYNTHESIZE_RETAIN(__Array *, mjList, MjList);
    
    //洗牌
    void wash();

    
#pragma mark -create
    bool init(){return 1;};
    CREATE_FUNC(MJGroup);
#pragma mark -other create
    
    bool init_BJ();
    static MJGroup *create_BJ();
private:
    
    void addType(MJType type);
    
    
public:
    
    
    //显示
    static void show(__Array *);
    static void showm(MJ *);
    
    //整理
    static void sort(__Array *);
    
    //判断牌
private:
    
    //分割
    __Array *sqlit(__Array *);
};

#endif /* defined(__ZGGame__MJGroup__) */
