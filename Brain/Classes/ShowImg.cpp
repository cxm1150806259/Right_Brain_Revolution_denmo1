//
//  ShowImg.cpp
//  HelloCpp
//
//  Created by Leo_champion on 14-4-19.
//
//

#include "ShowImg.h"
MainImg::MainImg()
{
}
MainImg::~MainImg()
{
}
void MainImg::initWithImgs()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
//    MenuItemImage* pItemImg = MenuItemImage::create("QQ.png", NULL);
//    pItemImg->setPosition(Point(origin.x+ visibleSize.width/2,origin.y+ visibleSize.height/2));
//    
//    auto * pMenu = Menu::create(pItemImg, NULL);
//    pMenu->setPosition(Point::ZERO);
//    this->addChild(pMenu);
    
    Sprite * sp1 = Sprite::create("1.png");
    //    sp1->setPosition(Point(origin.x+visibleSize.width/2-120, origin.y + visibleSize.height-sp1->getContentSize().height*2-120));
    //    sp1->setScale(1.5f);
    //    this->addChild(sp1);
    
    bornPoint1[0]=Point(origin.x+visibleSize.width/2-80, origin.y + visibleSize.height-sp1->getContentSize().height*2-150);
    bornPoint1[1]=Point(bornPoint1[0].x+100, bornPoint1[0].y);
    bornPoint1[2]=Point(bornPoint1[1].x+100, bornPoint1[0].y);
    bornPoint1[3]=Point(bornPoint1[0].x,bornPoint1[0].y-120);
    bornPoint1[4]=Point(bornPoint1[1].x, bornPoint1[1].y-120);
    bornPoint1[5]=Point(bornPoint1[2].x, bornPoint1[2].y-120);
    
    
    //接下来把六个图显示在界面上
    int rdmArray[3][6]={
        {2,3,5,1,4,7},
        {4,1,2,5,8,3},
        {6,5,3,4,2,1}
    };
    Sprite* sprite[6];
    int rdmNum=int(CCRANDOM_0_1()*33)%6;
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("selectImg.plist");
    
    for (int index=0; index < 6; index++) {
        sprite[index]=  Sprite::createWithSpriteFrameName(String::createWithFormat("%d.png",rdmArray[rdmNum][index+1])->getCString());
        sprite[index]->setPosition(bornPoint1[index]);
        sprite[index]->setScale(1.5f);
        this->addChild(sprite[index]);
    }
    

}

MainImg* MainImg::createWithImgs()
{
    MainImg* mainImg=new MainImg();
    mainImg->initWithImgs();
    mainImg->autorelease();
    return mainImg;
}
