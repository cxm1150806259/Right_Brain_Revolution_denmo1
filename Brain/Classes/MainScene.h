//
//  MainScene.h
//  HelloCpp
//
//  Created by Leo_champion on 14-4-16.
//
//

#ifndef __HelloCpp__MainScene__
#define __HelloCpp__MainScene__

#include <iostream>
#include "cocos2d.h"
#include "ShowImg.h"
using namespace cocos2d;

class GameScene:public::Layer {
public:
    virtual bool init();
    static Scene* scene();
    void remove();
    void removeAll();
    void backGround(float delta);
    virtual void onEnter();
    virtual void update(float delta);
    CREATE_FUNC(GameScene);
    void menuCloseCallback(Object* pSender);
private:
    Point bornPoint1[6];
    Point bornPoint2[8];
    Point bornPoint3[10];
    
    Point choosePoint[4];
public:
    void getRandom6(int total6,int index6,int t_timer);
    void getRandom4(int total6,int index4,int tmp);
    int getRandom(int start,int end);
    void showImgs(float delta);
    Size visibleSize;
    Point origin;
    Sprite* indexSprite;
    int flagSpite;
    int flagImg;
    Sprite* sprite1[6];
    Sprite* sprite2[4];
    int arrayNum6[6];
    int arrayNum4[4];
    bool showImgVisiable;
    Sprite* wrongSprite;
    Sprite* rightSprite;
    Menu* menuQ1;//问题菜单
    Menu* menuQ2;//提问菜单
};
#endif /* defined(__HelloCpp__MainScene__) */
