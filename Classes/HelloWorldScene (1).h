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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include<AudioEngine.h>

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void update_W(float delta);
    void update_S(float delta);
    void update_A(float delta);
    void update_D(float delta);
    void keyPressedDuration_W();
    void keyPressedDuration_A();
    void keyPressedDuration_S();
    void keyPressedDuration_D();
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    bool onContactSeparate(cocos2d::PhysicsContact& contact);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    void addMonster(float dt);
    
    

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
    cocos2d::Sprite* _player;
    cocos2d::Sprite* monster;
    cocos2d::Sprite* background1;
    cocos2d::Sprite* tree;
    cocos2d::Sprite* box;
    cocos2d::Sprite* bloodout;
    cocos2d::Sprite* blood;
    cocos2d::PhysicsBody* physicsBody1;
    cocos2d::Sprite* small_Map;
    cocos2d::Sprite* ball;
    cocos2d::Sprite* black2;
    cocos2d::Sprite* start_Page;
    cocos2d::Sprite*river1;
    cocos2d::Sprite* river2;
    cocos2d::Label* plabel3;
    cocos2d::Label* plabel4;
    cocos2d::Label* plabel5;
    cocos2d::Label* plabel6;
    cocos2d::Label* plabel7;
    cocos2d::Label* plabel8;
    int AudioID1; int AudioID2;
    cocos2d::Animate* animate1;
    cocos2d::Animate* animate2;
    cocos2d::Animate* animate3;
    cocos2d::Animate* animate4;
    



    std::map<cocos2d::EventKeyboard::KeyCode, bool>keys;
    
};

#endif // __HELLOWORLD_SCENE_H__
