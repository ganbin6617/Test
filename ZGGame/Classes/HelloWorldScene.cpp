#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    MJ_BJ_Game *_mj_bj_Game = MJ_BJ_Game::create();
    
    setMj_bj_Game(_mj_bj_Game);
    this->getMj_bj_Game()->start();
    
    Button* buttonPlay = Button::create();
    buttonPlay->setTouchEnabled(true);
    buttonPlay->setTitleText("点击------");
    buttonPlay->setPosition(Point(100,100));
    buttonPlay->addClickEventListener(CC_CALLBACK_0(HelloWorld::click, this));
    this->addChild(buttonPlay);

    return true;
}

void HelloWorld::click()
{
    CCLOG("sssss");
    
    this->getMj_bj_Game()->test();
}


