//
//  ShowImg.h
//  HelloCpp
//
//  Created by Leo_champion on 14-4-19.
//
//

#ifndef __HelloCpp__ShowImg__
#define __HelloCpp__ShowImg__

#include <iostream>
#include "cocos2d.h"
#include "MainScene.h"
using namespace cocos2d;
class MainImg:public Sprite
{
public:
    MainImg();
    ~MainImg();
    void initWithImgs();
    MainImg* createWithImgs();
public:
    Point bornPoint1[6];
};
#endif /* defined(__HelloCpp__ShowImg__) */
