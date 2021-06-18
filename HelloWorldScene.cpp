/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

/*#include "HelloWorldScene.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"D:\cocos\Projects\HelloWorld\win32-build\Gamemap.h"
#include"D:\cocos\Projects\HelloWorld\win32-build\Monster.h"
#include"D:\cocos\Projects\HelloWorld\win32-build\Player.h"
#include"D:\cocos\Projects\HelloWorld\win32-build\Weapon.h"

 
using namespace std;

USING_NS_CC;

MainMap mymainmap;

Bullet myball;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    if (!Scene::initWithPhysics())
    {
        return false;
    }


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
       // 2. add a menu item with "X" image, which is clicked to quit the program
       //    you may modify it.

       // add a "close" icon to exit the progress. it's an autorelease object
       // set Background
    //mymainmap.set_mainmap();

    //地图下边界
    //定义、添加物理引擎、settag、添加到可视化
    mymainmap.init();
    /*auto border1 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border.png");
    border1->setPosition(240, 10);
    auto physicsBody_border = PhysicsBody::createBox(border1->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border->setDynamic(false);
    physicsBody_border->setContactTestBitmask(0xFFFFFFFF);
    border1->setPhysicsBody(physicsBody_border);
    border1->setTag(50);
    this->addChild(border1);*/

    /*auto border2 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border2.png");
    border2->setPosition(40, 160);
    auto physicsBody_border2 = PhysicsBody::createBox(border2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border2->setDynamic(false);
    physicsBody_border2->setContactTestBitmask(0xFFFFFFFF);
    border2->setPhysicsBody(physicsBody_border2);
    border2->setTag(50);
    this->addChild(border2);

    auto border3 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border2.png");
    border3->setPosition(440, 160);
    auto physicsBody_border3 = PhysicsBody::createBox(border3->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border3->setDynamic(false);
    physicsBody_border3->setContactTestBitmask(0xFFFFFFFF);
    border3->setPhysicsBody(physicsBody_border3);
    border3->setTag(50);
    this->addChild(border3);


    auto border4 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border.png");
    border4->setPosition(240, 320);
    auto physicsBody_border4 = PhysicsBody::createBox(border4->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border4->setDynamic(false);
    physicsBody_border4->setContactTestBitmask(0xFFFFFFFF);
    border4->setPhysicsBody(physicsBody_border4);
    border4->setTag(50);
    this->addChild(border4);*/
//}


/*void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);//}*/
