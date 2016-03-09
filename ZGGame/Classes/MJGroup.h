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
    //洗牌
    void wash();
    
#pragma mark ----
    
    MJGroup();
    virtual bool init();
    
    bool init_BJ();
    static MJGroup *create_BJ();
    
    CREATE_FUNC(MJGroup);
private:
    __Array *mjList;
    
    void addType(MJType type);
};

#endif /* defined(__ZGGame__MJGroup__) */
