#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MJ_BJ_Game.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void click();
    
//    MJ_BJ_Game *mj_bj_Game;
    CC_SYNTHESIZE_RETAIN(MJ_BJ_Game*, mj_bj_Game, Mj_bj_Game);
};

#endif // __HELLOWORLD_SCENE_H__
