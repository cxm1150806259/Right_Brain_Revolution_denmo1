//
//  MainScene.cpp
//  HelloCpp
//
//  Created by Leo_champion on 14-4-16.
//
//

#include "MainScene.h"
#include <random>
Scene * GameScene::scene()
{
    Scene* scene = Scene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}
bool GameScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    showImgVisiable=true;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    MenuItemImage* pItemImg = MenuItemImage::create("QQ.png", NULL);
    pItemImg->setPosition(Point(origin.x+ visibleSize.width/2,origin.y+ visibleSize.height/2));
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    
    auto * pMenu = Menu::create(pItemImg, closeItem,NULL);
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu);
    
    
    showImgs(5);
//    getRandom6(8,6,2300);
    //延迟事件回调
//    ActionInterval* delayAction = Blink::create(2, 0);
//    CallFunc* callAction=CallFunc::create(CC_CALLBACK_0(GameScene::showImgs, this));
//    Sequence* action = Sequence::create(delayAction,callAction, NULL);
//    this->runAction(action);
    

    return true;
}
void GameScene::onEnter()
{
    Layer::onEnter();
    this->scheduleUpdate();
//    if (showImgVisiable) {
//        this->schedule(schedule_selector(GameScene::showImgs), 5.0f);
//        showImgVisiable=false;
//    }
    
}
void GameScene::update(float delta)
{
    Layer::update(delta);
//    backGround(delta);
}
void GameScene::menuCloseCallback(cocos2d::Object *pSender)
{
     Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void GameScene::backGround(float delta)
{
    MenuItemImage* pItemImg = MenuItemImage::create("QQ.png", NULL);
    pItemImg->setPosition(Point(origin.x+ visibleSize.width/2,origin.y+ visibleSize.height/2));
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    
    auto * pMenu = Menu::create(pItemImg, closeItem,NULL);
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu);
    

}
void GameScene::showImgs(float delta)
{
    Sprite * sp1 = Sprite::create("1.png");
    showImgVisiable=false;
    bornPoint1[0]=Point(origin.x+visibleSize.width/2-80, origin.y + visibleSize.height-sp1->getContentSize().height*2-150);
    bornPoint1[1]=Point(bornPoint1[0].x+100, bornPoint1[0].y);
    bornPoint1[2]=Point(bornPoint1[1].x+100, bornPoint1[0].y);
    bornPoint1[3]=Point(bornPoint1[0].x,bornPoint1[0].y-120);
    bornPoint1[4]=Point(bornPoint1[1].x, bornPoint1[1].y-120);
    bornPoint1[5]=Point(bornPoint1[2].x, bornPoint1[2].y-120);
    
    
    //接下来把六个图显示在界面上
//    int rdmArray[3][6]={
//        {2,3,5,1,4,7},
//        {4,1,2,5,8,3},
//        {6,5,3,4,2,1}
//    };
    getRandom6(7,6,1300);
    
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("selectImg.plist");
    
    for (int index=0; index < 6; index++) {
        sprite1[index]=  Sprite::createWithSpriteFrameName(String::createWithFormat("%d.png",arrayNum6[index])->getCString());
        sprite1[index]->setPosition(bornPoint1[index]);
        sprite1[index]->setScale(1.5f);
        this->addChild(sprite1[index]);
    }
    //显示题目
    MenuItemFont * mFont = MenuItemFont::create("Q.题目是");
    mFont->setPosition(Point(visibleSize.width/2, visibleSize.height/2-100));
    menuQ1=Menu::create(mFont, NULL);
    menuQ1->setPosition(Point::ZERO);
    this->addChild(menuQ1);
    
    //让一张图消失
    int tmd=arrayNum6[getRandom(1, 6)];
    flagImg=arrayNum6[tmd]; //选出消失图片的序号
    indexSprite=sprite1[tmd];
    //延迟事件回调
    ActionInterval* delayAction =DelayTime::create(1);
//    Blink::create(2, 1);
    CallFunc* callAction=CallFunc::create(CC_CALLBACK_0(GameScene::remove, this));
    Sequence* action = Sequence::create(delayAction,callAction, NULL);
    sprite1[2]->runAction(action);
}
void GameScene::remove()
{
    this->removeChild(indexSprite);
    this->removeChild(menuQ1);
    //显示提问
    MenuItemFont * mFont = MenuItemFont::create("Q.请问消失的图片是哪张？");
    mFont->setPosition(Point(visibleSize.width/2, visibleSize.height/2-100));
    menuQ2=Menu::create(mFont, NULL);
    menuQ2->setPosition(Point::ZERO);
    this->addChild(menuQ2);
    //四个选择图片出现位置
    choosePoint[0]=Point(visibleSize.width/2-20, visibleSize.height/2-170);
    choosePoint[1]=Point(choosePoint[0].x-180, choosePoint[0].y-80);
    choosePoint[2]=Point(choosePoint[0].x +250,choosePoint[0].y-80);
    choosePoint[3]=Point(choosePoint[0].x+20,choosePoint[0].y-150);
    //选出其余3个要显示的图片
//    int otherImg[3][4]={{1,3,5},{3,4,1},{4,1,5}};
    getRandom4(8, 4, flagImg);
    
    for (int index=0; index < 4; index++) {
        sprite2[index]=  Sprite::createWithSpriteFrameName(String::createWithFormat("%d.png",arrayNum4[index])->getCString());
        if (arrayNum4[index]==flagImg) {
            indexSprite=sprite2[index];
        }
        sprite2[index]->setPosition(choosePoint[index]);
        sprite2[index]->setScale(1.5f);
        this->addChild(sprite2[index]);
    }
    
    //触摸事件
    auto dispatcher = EventDispatcher::getInstance();
    auto listener1 = EventListenerTouch::create(Touch::DispatchMode::ONE_BY_ONE); //创建一个触摸监听
    auto listener2 = EventListenerTouch::create(Touch::DispatchMode::ONE_BY_ONE);
    listener1->setSwallowTouches(true);//设置是否想下传递触摸
    listener2->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // 获取事件所绑定的 target
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        // 获取当前点击点所在相对按钮的位置坐标
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
       Rect rect = Rect(0, 0, s.width, s.height);
   // 点击范围判断检测
        if (rect.containsPoint(locationInNode))
        {
            return true;
        }
        else{
            return false;
        }
    };
    listener1->onTouchEnded = [=](Touch* touch,Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = indexSprite->getContentSize();
        Rect rect = Rect(0,0,s.width,s.height);
        
        if (rect.containsPoint(locationInNode)) {
            rightSprite=Sprite::create("right.png");
            rightSprite->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
            rightSprite->setScale(0.5f);
            rightSprite->setTag(99);
            this->addChild(rightSprite);
            
            //延迟事件回调
            ActionInterval* delayAction = Blink::create(2, 2);
            CallFunc* callAction=CallFunc::create(CC_CALLBACK_0(GameScene::removeAll, this));
            Sequence* action = Sequence::create(delayAction,callAction, NULL);
            rightSprite->runAction(action);
            
            showImgVisiable=true;
        }
        else
        {
            
        }
        
    };
    listener2->onTouchBegan = [](Touch* touch, Event* event){
        // 获取事件所绑定的 target
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        // 获取当前点击点所在相对按钮的位置坐标
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        // 点击范围判断检测
        if (rect.containsPoint(locationInNode))
        {
            return true;
        }
        else{
            return false;
        }
    };
    listener2->onTouchEnded = [=](Touch* touch,Event* event)
    {
        auto target2 = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target2->convertToNodeSpace(touch->getLocation());
        Size s = target2->getContentSize();
        Rect rect = Rect(0,0,s.width,s.height);
        
        if (rect.containsPoint(locationInNode)) {
            wrongSprite=Sprite::create("wrong.png");
            wrongSprite->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
            wrongSprite->setScale(0.5f);
            wrongSprite->setTag(199);
            this->addChild(wrongSprite);

            ActionInterval* delayAction = Blink::create(2, 2);
            CallFunc* callAction=CallFunc::create(CC_CALLBACK_0(GameScene::removeAll, this));
            Sequence* action = Sequence::create(delayAction,callAction, NULL);
            wrongSprite->runAction(action);
            showImgVisiable=true;

        }
        else
        {
           
        }
        
    };
    //将触摸监听添加到eventDispacher中去
    dispatcher->addEventListenerWithSceneGraphPriority(listener1,sprite2[0]);
    dispatcher->addEventListenerWithSceneGraphPriority(listener2,sprite2[1]);
    dispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(),sprite2[2]);
    dispatcher->addEventListenerWithSceneGraphPriority(listener2->clone(),sprite2[3]);
    
    if (showImgVisiable) {
        this->removeAllChildrenWithCleanup(true);
    }
    
}
void GameScene::getRandom6(int total6, int index6,int t_timer)
{
    std::uniform_int_distribution<unsigned> u(1,total6);//生成0到10（包含）均匀分布的随机数
    std::default_random_engine e2(t_timer);
    
    int i=0,j,count=0;
    while (count<index6)  {
        int temp=u(e2);
        
        if (i==0) {
            arrayNum6[i]=temp;count+=1;i++;
            printf("1_ %d \n",arrayNum6[0]);
            continue;
        }
        
        for (j=0; j<i; j++) {
            if ((temp-arrayNum6[j])==0) {
                break;
            }
        }
        if (j>=i) {
            arrayNum6[i]=temp;
            printf(" %d ",arrayNum6[i]);
            i++;
            count++;
        }
    }
}
void GameScene::getRandom4(int total4, int index4, int tmp)
{
    
    std::uniform_int_distribution<unsigned> u(1,total4);//生成0到10（包含）均匀分布的随机数
    std::default_random_engine e2(2500);
    
    int i=0,j,count=1;
    arrayNum4[0]=tmp;
    while(count<index4) {
        int temp=u(e2);
        if (i==0) {
            printf("%d \n",arrayNum4[0]);i++;
            continue;
        }
        
        for (j=0; j<i; j++) {
            if ((temp-arrayNum4[j])==0) {
                break;
            }
        }
        if (j>=i) {
            arrayNum4[i]=temp;
            count++;
            printf(" %d ",arrayNum4[i]);i++;
        }
    }
}
int GameScene::getRandom(int start, int end)
{
    std::uniform_int_distribution<unsigned> u(start,end);//生成0到10（包含）均匀分布的随机数
    std::default_random_engine e2(2500);
    int temp=0;
    temp=u(e2);
    return temp;
}
void GameScene::removeAll()
{
    for (int i = 0; i<6; i++) {
        this->removeChild(sprite1[i]);
    }
    for (int j=0; j<4; j++) {
        this->removeChild(sprite2[j]);
    }
    this->removeChild(rightSprite);
    this->removeChild(wrongSprite);
    this->removeChild(menuQ2);
    showImgs(3);
}