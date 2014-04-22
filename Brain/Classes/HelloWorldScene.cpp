#include "HelloWorldScene.h"
#include "MainScene.h"
USING_NS_CC;

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    MenuItemFont* pFont = MenuItemFont::create("右脑游戏——欢迎你！！！", CC_CALLBACK_1(HelloWorld::NextScene,this ));
    pFont->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height-pFont->getContentSize().height*6));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,pFont,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    
    return true;
}
void HelloWorld::NextScene(Object* pSender)
{
    Scene * scene = GameScene::scene();
    Director::getInstance()->pushScene(scene);
    //    Director::getInstance()->end();

}

void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
