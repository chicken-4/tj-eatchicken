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

#include "HelloWorldScene.h"
#include<string>
#include<AudioEngine.h>

USING_NS_CC;

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
    if ( !Scene::init() )
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
   
    auto border1 = Sprite::create("border.png");
    border1->setPosition(240,10);
    auto physicsBody_border = PhysicsBody::createBox(border1->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border->setDynamic(false);
    physicsBody_border->setContactTestBitmask(0xFFFFFFFF);
    border1->setPhysicsBody(physicsBody_border);
    border1->setTag(50);
    this->addChild(border1);

    auto border2 = Sprite::create("border2.png");
    border2->setPosition(40, 160);
    auto physicsBody_border2 = PhysicsBody::createBox(border2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border2->setDynamic(false);
    physicsBody_border2->setContactTestBitmask(0xFFFFFFFF);
    border2->setPhysicsBody(physicsBody_border2);
    border2->setTag(50);
    this->addChild(border2);

    auto border3 = Sprite::create("border2.png");
    border3->setPosition(440, 160);
    auto physicsBody_border3 = PhysicsBody::createBox(border3->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border3->setDynamic(false);
    physicsBody_border3->setContactTestBitmask(0xFFFFFFFF);
    border3->setPhysicsBody(physicsBody_border3);
    border3->setTag(50);
    this->addChild(border3);


    auto border4 = Sprite::create("border.png");
    border4->setPosition(240, 320);
    auto physicsBody_border4= PhysicsBody::createBox(border4->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_border4->setDynamic(false);
    physicsBody_border4->setContactTestBitmask(0xFFFFFFFF);
    border4->setPhysicsBody(physicsBody_border4);
    border4->setTag(50);
    this->addChild(border4);

    background1 = Sprite::create("big2xx.png");
    background1->setPosition(Vec2(background1->getContentSize().width / 2 + 25, background1->getContentSize().height / 2));


    river2 = Sprite::create("border2.png");
    river2->setPosition(background1->getContentSize().width / 2 + 25, background1->getContentSize().height / 2);
    auto physicsBody_river2 = PhysicsBody::createBox(river2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_river2->setDynamic(false);
    physicsBody_river2->setContactTestBitmask(0xFFFFFFFF);
    river2->setPhysicsBody(physicsBody_river2);
    river2->setTag(30);
    this->addChild(river2);

    box = Sprite::create("bocket.png");
    box->setPosition(Vec2(227, 260));
    auto physicsBody3 = PhysicsBody::createBox(box->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody3->setDynamic(false);
    physicsBody3->setContactTestBitmask(0xFFFFFFFF);
    box->setPhysicsBody(physicsBody3);
    box->setTag(50);
    this->addChild(box);

    tree = Sprite::create("cao.png");
    tree->setPosition(Vec2(315,380));
    auto physicsBody2 = PhysicsBody::createBox(tree->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody2->setDynamic(false);
    physicsBody2->setContactTestBitmask(0xFFFFFFFF);
    tree->setPhysicsBody(physicsBody2);
    tree->setTag(30);
    this->addChild(tree);
    

    
    this->addChild(background1);
    
   

    blood = Sprite::create("blood.png");
    blood->setPosition(Vec2(160, 300));
    blood->setScale(1, 1);
    this->addChild(blood);


    bloodout = Sprite::create("bloodout.png");
    bloodout->setPosition(Vec2(160, 300));
    this->addChild(bloodout);

    Label* plabel1 = Label::create();
    plabel1->setString("Blood Volume");
    plabel1->setColor(Color3B(0, 0, 0));
    plabel1->enableShadow(Color4B(0, 0, 0,255), Size(-0.5, -0.5), 1);
    plabel1->setPosition(Vec2(75,300));
    this->addChild(plabel1);

    Label* plabel2 = Label::create();
    plabel2->setString("Your Score");
    plabel2->setColor(Color3B(0, 0, 0));
    plabel2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
    plabel2->setPosition(Vec2(75, 270));
    this->addChild(plabel2);

    Label* plabel9 = Label::create();
    plabel9->setString("Time");
    plabel9->setColor(Color3B(0, 0, 0));
    plabel9->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
    plabel9->setPosition(Vec2(260, 300));
    this->addChild(plabel9);

    auto black1 = Sprite::create("black.png");
    black1->setPosition(453 - black1->getContentSize().width / 2, 320 - black1->getContentSize().height / 2);
    black1->setOpacity(80);
    this->addChild(black1);

    small_Map =Sprite::create("big2.png");
    small_Map->setPosition(453 - small_Map->getContentSize().width / 2, 320 - small_Map->getContentSize().height / 2);
    small_Map->setOpacity(100);
    this->addChild(small_Map);

    _player = Sprite::create("1.png");
    _player->setPosition(Vec2(112, 124));

    ball = Sprite::create("ball.png");
    ball->setPosition(453 - small_Map->getContentSize().width / 2-(background1->getPositionX()-_player->getPositionX())/35, 320-small_Map->getContentSize().height / 2 -(background1->getPositionY() - _player->getPositionY())/35);
    ball->setOpacity(0);
    this->addChild(ball);

    start_Page=Sprite::create("big2xx.png");
    start_Page -> setPosition(0,0);
    this->addChild(start_Page);
   
    _player = Sprite::create("1.png");
    _player->setPosition(Vec2(112, 124));
    _player->setScale(2.5);
    _player->setName("s1");
    physicsBody1 = PhysicsBody::createBox(_player->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody1->setDynamic(false);
    physicsBody1->setContactTestBitmask(0xFFFFFFFF);
    physicsBody1->setGravityEnable(false);
    physicsBody1->applyImpulse(Vec2(0.01f, 0.01f));
    _player->setPhysicsBody(physicsBody1);
    _player->setTag(40);
    this->addChild(_player);

    
    plabel3 = Label::create();
    plabel3->setString("POBG");
    plabel3->setScale(5);
    plabel3->setColor(Color3B(3, 54, 73));
    plabel3->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
    plabel3->setPosition(Vec2(300, 250));
    this->addChild(plabel3);

    plabel4 = Label::create();
    plabel4->setString("START GAME");
    plabel4->setScale(3);
    plabel4->setColor(Color3B(3, 22, 52));
    plabel4->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
    plabel4->setPosition(Vec2(300, 175));
    auto physicsBody_start = PhysicsBody::createBox(plabel4->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_start->setDynamic(false);
    physicsBody_start->setContactTestBitmask(0xFFFFFFFF);
    plabel4->setPhysicsBody(physicsBody_start);
    plabel4->setTag(70);
    this->addChild(plabel4);

    plabel5 = Label::create();
    plabel5->setString("CREATE ROOM");
    plabel5->setScale(2);
    plabel5->setColor(Color3B(138, 151, 123));
    plabel5->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
    plabel5->setPosition(Vec2(300, 125));
    this->addChild(plabel5);

    plabel6 = Label::create();
    plabel6->setString("ENTER ROOM");
    plabel6->setScale(2);
    plabel6->setColor(Color3B(138, 151, 123));
    plabel6->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
    plabel6->setPosition(Vec2(300, 75));
    this->addChild(plabel6);

    plabel8 = Label::create();
    plabel8->setString("Exit");
    plabel8->setScale(1.5);
    plabel8->setColor(Color3B(3, 22, 52));
    plabel8->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
    plabel8->setPosition(Vec2(400, 40));
    auto physicsBody_end = PhysicsBody::createBox(plabel8->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody_end->setDynamic(false);
    physicsBody_end->setContactTestBitmask(0xFFFFFFFF);
    plabel8->setPhysicsBody(physicsBody_end);
    plabel8->setTag(80);
    this->addChild(plabel8);

    black2 = Sprite::create("black.png");
    black2->setScale(5);
    black2->setPosition(240,180);
    black2->setOpacity(0);
    this->addChild(black2);

    plabel7 = Label::create();
    plabel7->setString("YOU LOSE");
    plabel7->setScale(4);
    plabel7->setColor(Color3B(138, 151, 123));
    plabel7->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
    plabel7->setPosition(Vec2(240, 180));
    plabel7->setOpacity(0);
    this->addChild(plabel7);

    AudioID1=AudioEngine::play2d("bacmusic.mp3");
    
   

    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        Vector<SpriteFrame*> frameVec2;
        SpriteFrame* frame5 = SpriteFrame::create("21.png",Rect(0,0,10.8,20));
        frameVec2.pushBack(frame5);
        SpriteFrame* frame6 = SpriteFrame::create("22.png", Rect(0, 0, 11.2, 19.5));
        frameVec2.pushBack(frame6);
        SpriteFrame* frame7 = SpriteFrame::create("21.png", Rect(0, 0, 10.8, 20));
        frameVec2.pushBack(frame7);
        SpriteFrame* frame8 = SpriteFrame::create("24.png", Rect(0, 0, 11.2, 19));
        frameVec2.pushBack(frame8);
        Animation* animation2 = Animation::createWithSpriteFrames(frameVec2);
        animation2->setLoops(-1);
        animation2->setDelayPerUnit(0.2);
        animate2 = Animate::create(animation2);
       
        Vector<SpriteFrame*> frameVec1;
        SpriteFrame* frame1 = SpriteFrame::create("1.png", Rect(0, 0, 10.6, 20));
        frameVec1.pushBack(frame1);
        SpriteFrame* frame2 = SpriteFrame::create("12.png", Rect(0, 0, 10.6, 19.5));
        frameVec1.pushBack(frame2);
        SpriteFrame* frame3 = SpriteFrame::create("1.png", Rect(0, 0, 10.6, 20));
        frameVec1.pushBack(frame3);
        SpriteFrame* frame4 = SpriteFrame::create("14.png", Rect(0, 0, 11, 19.5));
        frameVec1.pushBack(frame4);
        Animation* animation = Animation::createWithSpriteFrames(frameVec1);
        animation->setLoops(-1);
        animation->setDelayPerUnit(0.2);
        animate1 = Animate::create(animation);


        Vector<SpriteFrame*> frameVec3;
        SpriteFrame* frame9 = SpriteFrame::create("31.png", Rect(0, 0, 8.5, 20));
        frameVec3.pushBack(frame9);
        SpriteFrame* frame10 = SpriteFrame::create("32.png", Rect(0, 0, 9, 20));
        frameVec3.pushBack(frame10);
        SpriteFrame* frame11 = SpriteFrame::create("31.png", Rect(0, 0, 8.5, 20));
        frameVec3.pushBack(frame11);
        SpriteFrame* frame12 = SpriteFrame::create("34.png", Rect(0, 0, 10, 20));
        frameVec3.pushBack(frame12);
        Animation* animation3 = Animation::createWithSpriteFrames(frameVec3);
        animation3->setLoops(-1);
        animation3->setDelayPerUnit(0.2);
        animate3 = Animate::create(animation3);
        
        Vector<SpriteFrame*> frameVec4;
        SpriteFrame* frame13 = SpriteFrame::create("41.png", Rect(0, 0, 8.5, 20));
        frameVec4.pushBack(frame13);
        SpriteFrame* frame14 = SpriteFrame::create("42.png", Rect(0, 0, 10, 20));
        frameVec4.pushBack(frame14);
        SpriteFrame* frame15 = SpriteFrame::create("41.png", Rect(0, 0, 8.5, 20));
        frameVec4.pushBack(frame15);
        SpriteFrame* frame16 = SpriteFrame::create("44.png", Rect(0, 0, 10, 20));
        frameVec4.pushBack(frame16);
        Animation* animation4 = Animation::createWithSpriteFrames(frameVec4);
        animation4->setLoops(-1);
        animation4->setDelayPerUnit(0.2);
        animate4 = Animate::create(animation4);

       
        if (keyCode==EventKeyboard::KeyCode::KEY_W)
        {
            _player->stopAllActions();
            _player->runAction(animate2);
            keys[EventKeyboard::KeyCode::KEY_W] = true;
        
        }
        if (keyCode==EventKeyboard::KeyCode::KEY_S)
        {
            _player->stopAllActions();
            _player->runAction(animate1);
            keys[EventKeyboard::KeyCode::KEY_S] = true;
        }
         if (keyCode == EventKeyboard::KeyCode::KEY_D)
        {
             _player->stopAllActions();
             _player->runAction(animate3);
            keys[EventKeyboard::KeyCode::KEY_D] = true;

        }
        if (keyCode == EventKeyboard::KeyCode::KEY_A)
        {
            _player->stopAllActions();
            _player->runAction(animate4);
            keys[EventKeyboard::KeyCode::KEY_A] = true;

        }
        


        
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        if (keyCode == EventKeyboard::KeyCode::KEY_W)
        {  
            _player->stopAction(animate2);
            keys[EventKeyboard::KeyCode::KEY_W] = false;

        }
        if (keyCode == EventKeyboard::KeyCode::KEY_S)
        {
           
            _player->stopAction(animate1);
            keys[EventKeyboard::KeyCode::KEY_S] = false;
        }
         if (keyCode == EventKeyboard::KeyCode::KEY_D )
        {
           
             _player->stopAction(animate3);
            keys[EventKeyboard::KeyCode::KEY_D] = false;

        }
        if (keyCode == EventKeyboard::KeyCode::KEY_A )
        {
            
            _player->stopAction(animate4);
            keys[EventKeyboard::KeyCode::KEY_A] = false;

        }
       
  
    };
    


    auto eventListener = EventListenerTouchOneByOne::create();
    // 定义回调函数onTouchBegan():手指第一次碰到屏幕时被调用。
    eventListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    // 使用EventDispatcher来处理各种各样的事件，如触摸和其他键盘事件。
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, _player);
    // 碰撞检测 
   
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this); 
    

    
}



void HelloWorld::update_W(float delta)
{
    Node::update(delta);
    
    if (keys[EventKeyboard::KeyCode::KEY_W])
    {
        keyPressedDuration_W();
        
    }
   
 
}
void HelloWorld::update_S(float delta)
{
    Node::update(delta);
    auto leftArrow = EventKeyboard::KeyCode::KEY_A, rightArrow = EventKeyboard::KeyCode::KEY_D;
    auto upArrow = EventKeyboard::KeyCode::KEY_W, downArrow = EventKeyboard::KeyCode::KEY_S;

    if (keys[EventKeyboard::KeyCode::KEY_S])
    {
        keyPressedDuration_S();
      
    }


}
void HelloWorld::update_A(float delta)
{
    Node::update(delta);
    auto leftArrow = EventKeyboard::KeyCode::KEY_A, rightArrow = EventKeyboard::KeyCode::KEY_D;
    auto upArrow = EventKeyboard::KeyCode::KEY_W, downArrow = EventKeyboard::KeyCode::KEY_S;

    if (keys[EventKeyboard::KeyCode::KEY_A])
    {
        keyPressedDuration_A();
    }


}
void HelloWorld::update_D(float delta)
{
    Node::update(delta);
    auto leftArrow = EventKeyboard::KeyCode::KEY_A, rightArrow = EventKeyboard::KeyCode::KEY_D;
    auto upArrow = EventKeyboard::KeyCode::KEY_W, downArrow = EventKeyboard::KeyCode::KEY_S;

    if (keys[EventKeyboard::KeyCode::KEY_D])
    {
        keyPressedDuration_D();
    }


}
void HelloWorld::keyPressedDuration_A()
{
    
    
    ball->setPosition(453 - small_Map->getContentSize().width / 2 - (background1->getPositionX() - _player->getPositionX()) / 35, 320 - small_Map->getContentSize().height / 2 - (background1->getPositionY() - _player->getPositionY()) / 35);
    int offsetX = -1.85; int offsetY = 0;
    if (_player->getPositionX() >= 150  || background1->getPositionX() >= background1->getContentSize().width / 2 + 25)
    {
        auto moveTo = MoveTo::create(0, Vec2(_player->getPositionX() + offsetX, _player->getPositionY() + offsetY));
        _player->runAction(moveTo); 
    }
    else
    {
        auto moveTo1 = MoveTo::create(0, Vec2(background1->getPositionX() - offsetX, background1->getPositionY() - offsetY));
        background1->runAction(moveTo1);
        auto moveTo2 = MoveTo::create(0, Vec2(tree->getPositionX() - offsetX, tree->getPositionY() - offsetY));
        tree->runAction(moveTo2);
        auto moveTo3 = MoveTo::create(0, Vec2(box->getPositionX() - offsetX, box->getPositionY() - offsetY));
        box->runAction(moveTo3);
        
        auto moveTo5 = MoveTo::create(0, Vec2(river2->getPositionX() - offsetX, box->getPositionY() - offsetY));
        river2->runAction(moveTo5);
       
    }
   
}
void HelloWorld::keyPressedDuration_D()
{
   
    
    ball->setPosition(453 - small_Map->getContentSize().width / 2 -(background1->getPositionX() - _player->getPositionX()) / 35, 320 - small_Map->getContentSize().height / 2 -(background1->getPositionY() - _player->getPositionY()) / 35);
    int offsetX = 1.85; int offsetY = 0;
    if ( _player->getPositionX() <= 330  || background1->getPositionX() <= 455 - background1->getContentSize().width / 2)
    {
        auto moveTo = MoveTo::create(0, Vec2(_player->getPositionX() + offsetX, _player->getPositionY() + offsetY));
        _player->runAction(moveTo);
    }
    else
    {
        auto moveTo1 = MoveTo::create(0, Vec2(background1->getPositionX() - offsetX, background1->getPositionY() - offsetY));
        background1->runAction(moveTo1);
        auto moveTo2 = MoveTo::create(0, Vec2(tree->getPositionX() - offsetX, tree->getPositionY() - offsetY));
        tree->runAction(moveTo2);
        auto moveTo3 = MoveTo::create(0, Vec2(box->getPositionX() - offsetX, box->getPositionY() - offsetY));
        box->runAction(moveTo3);
       
        auto moveTo5 = MoveTo::create(0, Vec2(river2->getPositionX() - offsetX, box->getPositionY() - offsetY));
        river2->runAction(moveTo5);
    }
    
}
void HelloWorld::keyPressedDuration_W()
{
    ball->setPosition(453 - small_Map->getContentSize().width / 2 - (background1->getPositionX() - _player->getPositionX()) / 35, 320 - small_Map->getContentSize().height / 2 - (background1->getPositionY() - _player->getPositionY()) / 35);
    int offsetX = 0; int offsetY = 1.85;
    if ( _player->getPositionY() <= 230  || background1->getPositionY() <= 320 - background1->getContentSize().height / 2)
    {
        auto moveTo = MoveTo::create(0, Vec2(_player->getPositionX() + offsetX, _player->getPositionY() + offsetY));
        _player->runAction(moveTo);
        
    }
    else
    {
        auto moveTo1 = MoveTo::create(0, Vec2(background1->getPositionX() - offsetX, background1->getPositionY() - offsetY));
        background1->runAction(moveTo1);
        auto moveTo2 = MoveTo::create(0, Vec2(tree->getPositionX() - offsetX, tree->getPositionY() - offsetY));
        tree->runAction(moveTo2);
        auto moveTo3 = MoveTo::create(0, Vec2(box->getPositionX() - offsetX, box->getPositionY() - offsetY));
        box->runAction(moveTo3);
       
        auto moveTo5 = MoveTo::create(0, Vec2(river2->getPositionX() - offsetX, box->getPositionY() - offsetY));
        river2->runAction(moveTo5);
        

    }
}
void HelloWorld::keyPressedDuration_S()
{
    ball->setPosition(453 - small_Map->getContentSize().width / 2 -(background1->getPositionX() - _player->getPositionX()) / 35, 320 - small_Map->getContentSize().height / 2 - (background1->getPositionY() - _player->getPositionY()) / 35);
    int offsetX = 0; int offsetY = -1.85;
    if (_player->getPositionY() >= 100 || background1->getPositionY() >= background1->getContentSize().height / 2)
    {
        auto moveTo = MoveTo::create(0, Vec2(_player->getPositionX() + offsetX, _player->getPositionY() + offsetY));
        _player->runAction(moveTo);
        
       
    }
    else
    {
        auto moveTo1 = MoveTo::create(0, Vec2(background1->getPositionX() - offsetX, background1->getPositionY() - offsetY));
        background1->runAction(moveTo1);
        auto moveTo2 = MoveTo::create(0, Vec2(tree->getPositionX() - offsetX, tree->getPositionY() - offsetY));
        tree->runAction(moveTo2);
        auto moveTo3 = MoveTo::create(0, Vec2(box->getPositionX() - offsetX, box->getPositionY() - offsetY));
        box->runAction(moveTo3);
        
        auto moveTo5 = MoveTo::create(0, Vec2(river2->getPositionX() - offsetX, box->getPositionY() - offsetY));
        river2->runAction(moveTo5);
       
       
       

    }
}
    // 0代表着动作从开始到结束所用的时间
   


void HelloWorld::addMonster(float dt) {
     monster = Sprite::create("5.png");

    // Add monster
    auto monsterContentSize = monster->getContentSize();
    auto selfContentSize = this->getContentSize();
    int minY = monsterContentSize.height / 2;
    int maxY = selfContentSize.height - minY;
    int rangeY = maxY - minY;
    int randomY = (rand() % rangeY) + minY;
    monster->setPosition(Vec2(selfContentSize.width + monsterContentSize.width / 2, randomY));
    
    auto physicsBody = PhysicsBody::createBox(monster->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody->setDynamic(false);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    monster->setPhysicsBody(physicsBody);
    monster->setTag(20);

    this->addChild(monster);

    // Let monster run
    int minDuration = 2.0;
    int maxDuration = 4.0;
    int rangeDuration = maxDuration - minDuration;
    int randomDuration = (rand() % rangeDuration) + minDuration;

    // 定义移动的object
    // 在randomDuration这个时间内(2-4秒内)，让怪物从屏幕右边移动到左边。(怪物有快有慢)
    auto actionMove1 = MoveTo::create(randomDuration, Vec2(-monsterContentSize.width / 2, randomY));
    // 定义消除的Object。怪物移出屏幕后被消除，释放资源。auto actionMove2 = MoveTo::create(randomDuration, Vec2(monsterContentSize.width / 2, randomY));
    auto actionRemove1 = RemoveSelf::create();
    monster->runAction(Sequence::create(actionMove1, actionRemove1, nullptr));

    
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event) {
    // 1 - Just an example for how to get the player object
    // 说明一下作为第二个参数传递给addEventListenerWithSceneGraphPriority(eventListener, _player)的_player对象被访问的方式。
    // auto node = unused_event->getcurrentTarget();

    // 2.获取触摸点的坐标，并计算这个点相对于_player的偏移量。
    Vec2 touchLocation = touch->getLocation();
    Vec2 offset = touchLocation - _player->getPosition();
    
    // 如果offset的x值是负值，这表明玩家正试图朝后射击。在本游戏中这是不允许的。
    
    if (offset.x < 0) 
    {
        _player->initWithFile("41.png");
        
    }
   
    else if (offset.x >0 )
    {
        _player->initWithFile("31.png");
    }

    // 3.在玩家所在的位置创建一个飞镖，将其添加到场景中。
    auto projectile = Sprite::create("6.png");
    projectile->setPosition(_player->getPosition());
    auto physicsBody = PhysicsBody::createBox(projectile->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicsBody->setDynamic(false);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    projectile->setPhysicsBody(physicsBody);
    projectile->setTag(10);


    this->addChild(projectile);

    // 4.将偏移量转化为单位向量，即长度为1的向量。
    offset.normalize();
    // 将其乘以1000，你就获得了一个指向用户触屏方向的长度为1000的向量。为什么是1000呢？因为长度应当足以超过当前分辨率下屏幕的边界。
    auto shootAmount = offset * 1000;
    // 将此向量添加到飞镖的位置上去，这样你就有了一个目标位置。
    auto realDest = shootAmount + projectile->getPosition();

    // 5.创建一个动作，将飞镖在2秒内移动到目标位置，然后将它从场景中移除。
    auto actionMove = MoveTo::create(2.0f, realDest);
    auto actionRemove = RemoveSelf::create();
    projectile->runAction(Sequence::create(actionMove, actionRemove, nullptr));

    return true;
}


bool HelloWorld::onContactBegin(cocos2d::PhysicsContact& contact)
{
   
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB)
    {
 
     
        if (nodeA->getTag()== 10&&nodeB->getTag()==20)
        {
            nodeA->removeFromParentAndCleanup(true);
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == 10 && nodeA->getTag() == 20)
        {
            nodeA->removeFromParentAndCleanup(true);
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeA->getTag() == 20 && nodeB->getTag() == 40)
        {
            blood->setScale(blood->getScaleX() - 0.1, 1);
            blood->setPosition(blood->getPositionX() - 0.04 * bloodout->getContentSize().width , 300);
            nodeA->removeFromParentAndCleanup(true);
            if (blood->getPositionX() <= 10 + bloodout->getPositionX() - (bloodout->getContentSize().width) / 2)
            {
                plabel7->setOpacity(255);
                black2->setOpacity(255);
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::addMonster));
                AudioEngine::stop(AudioID2);
            }
             
        }
        else if (nodeA->getTag() == 40 && nodeB->getTag() == 20)
        {
            blood->setScale(blood->getScaleX() - 0.1, 1);
            blood->setPosition(blood->getPositionX() - 0.04 * bloodout->getContentSize().width , 300);
            nodeB->removeFromParentAndCleanup(true);
            if (blood->getPositionX() <= 10 + bloodout->getPositionX() - (bloodout->getContentSize().width) / 2)
            {
                plabel7->setOpacity(255);
                black2->setOpacity(255);
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::addMonster));
                AudioEngine::stop(AudioID2);
            }
        }
        else if (nodeA->getTag() == 40 && nodeB->getTag() == 30)
        {
            _player->setOpacity(100);
          
        }
        else if (nodeA->getTag() == 30 && nodeB->getTag() == 40)
        {
            _player->setOpacity(100);

        }
        else if (nodeA->getTag() == 40 && nodeB->getTag() == 50)
        {
            if (_player->getPositionY() <= nodeB->getPositionY()-nodeB->getContentSize().height/2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W));
            }
            else if (_player->getPositionY() > nodeB->getPositionY()+ nodeB->getContentSize().height / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S));
            }
            if (_player->getPositionX() <=nodeB->getPositionX()- nodeB->getContentSize().width / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D));
            }
            else if (_player->getPositionX() > nodeB->getPositionX() +nodeB->getContentSize().width / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A));
            }
        }
        else if (nodeA->getTag() == 50 && nodeB->getTag() == 40)
        {
            if (_player->getPositionY() < nodeA->getPositionY() - nodeA->getContentSize().height / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W));
            }
            else if (_player->getPositionY() > nodeA->getPositionY() +nodeA->getContentSize().height / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S));
            }
            if (_player->getPositionX() < nodeA->getPositionX() - nodeA->getContentSize().width / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D));
            }
            else if (_player->getPositionX() > nodeA->getPositionX() + nodeA->getContentSize().width / 2)
            {
                this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A));
            }
        }
        else if (nodeA->getTag() == 70 && nodeB->getTag() == 10)
        {
            AudioEngine::stop(AudioID1);
            AudioID2 = AudioEngine::play2d("fight.mp3",true,0.5F);
            _player->setScale(1);
            nodeB->removeFromParentAndCleanup(true);
            start_Page->removeFromParentAndCleanup(true);
            plabel3->removeFromParentAndCleanup(true);
            plabel4->removeFromParentAndCleanup(true);
            plabel5->removeFromParentAndCleanup(true);
            plabel6->removeFromParentAndCleanup(true);
            plabel8->removeFromParentAndCleanup(true);
            ball->setOpacity(120);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W), 1/ 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S), 1 / 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A), 1 / 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D), 1 / 60);

           
           

            srand((unsigned int)time(nullptr));
            // 每隔1.5秒生成一个怪物
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::addMonster), 2);
        }
        else if (nodeB->getTag() == 70 && nodeA->getTag() == 10)
        {
             AudioEngine::stop(AudioID1);
             AudioID2 = AudioEngine::play2d("fight.mp3",true,0.5F);
            _player->setScale(1);
            nodeA->removeFromParentAndCleanup(true);
            plabel3->removeFromParentAndCleanup(true);
            plabel4->removeFromParentAndCleanup(true);
            plabel5->removeFromParentAndCleanup(true);
            plabel6->removeFromParentAndCleanup(true);
            plabel8->removeFromParentAndCleanup(true);
            start_Page->removeFromParentAndCleanup(true);
            ball->setOpacity(120);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W), 1 / 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S), 1 / 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A), 1 / 60);
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D), 1 / 60);
            

          
            srand((unsigned int)time(nullptr));
            // 每隔1.5秒生成一个怪物
            this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::addMonster), 2);
        }
        else if (nodeA->getTag() == 80 && nodeB->getTag() == 10)
        {
        Director::getInstance()->end();
        }
        else if (nodeB->getTag() == 80 && nodeA->getTag() == 10)
        {
        Director::getInstance()->end();
        }
        
    }
  return true;
}

bool HelloWorld::onContactSeparate(cocos2d::PhysicsContact& contact)
{

    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB)
    {

        if (nodeA->getTag() == 40 && nodeB->getTag() == 30)
        {
            _player->setOpacity(255);

        }
        else if (nodeA->getTag() == 30 && nodeB->getTag() == 40)
        {
            _player->setOpacity(255);

        }
        else if (nodeA->getTag() == 40 && nodeB->getTag() == 50)
        {

            if (_player->getPositionY() < nodeB->getPositionY() - nodeB->getContentSize().height / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W));
            }

            else if (_player->getPositionY() > nodeB->getPositionY() +nodeB->getContentSize().height / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S));
            }
            if (_player->getPositionX() < nodeB->getPositionX() - nodeB->getContentSize().width / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D));
            }
            else if (_player->getPositionX() > nodeB->getPositionX() + nodeB->getContentSize().width / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A));
            }
            
        }
        else if (nodeA->getTag() == 50 && nodeB->getTag() == 40)
        {
            if (_player->getPositionY() < nodeA->getPositionY() - nodeA->getContentSize().height / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_W));
            }

            else if (_player->getPositionY() > nodeA->getPositionY() + nodeA->getContentSize().height / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_S));
            }
            if (_player->getPositionX() < nodeA->getPositionX() - nodeA->getContentSize().width / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_D));
            }
            else if (_player->getPositionX() > nodeA->getPositionX() +nodeA->getContentSize().width / 2)
            {
                this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update_A));
            }
        }
        
    }
    return true;
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
