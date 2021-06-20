#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"AnimationUtil.h"
#include "Player.h"

using namespace std;

Animate* AnimationUtil::createWithSingleFrameName_1()
{
    Vector<SpriteFrame*> frameVec1;
    SpriteFrame* frame1 = SpriteFrame::create("11.png", Rect(0, 0, 10.6, 20));
    frameVec1.pushBack(frame1);
    SpriteFrame* frame2 = SpriteFrame::create("12.png", Rect(0, 0, 10.6, 19.5));
    frameVec1.pushBack(frame2);
    SpriteFrame* frame3 = SpriteFrame::create("11.png", Rect(0, 0, 10.6, 20));
    frameVec1.pushBack(frame3);
    SpriteFrame* frame4 = SpriteFrame::create("14.png", Rect(0, 0, 11, 19.5));
    frameVec1.pushBack(frame4);
    Animation* animation1 = Animation::createWithSpriteFrames(frameVec1);
    animation1->setLoops(-1);
    animation1->setDelayPerUnit(0.2);
    Animate*animate1 = Animate::create(animation1);
    

    return animate1;
}

Animate* AnimationUtil::createWithSingleFrameName_2()
{
    Vector<SpriteFrame*> frameVec2;//这里没有简化，四个Vector是精灵帧 spriteframe 用于建立人物走动时的动画 后面多次重复
    SpriteFrame* frame5 = SpriteFrame::create("21.png", Rect(0, 0, 10.8, 20));
    frameVec2.pushBack(frame5);
    SpriteFrame* frame6 = SpriteFrame::create("22.png", Rect(0, 0, 11.2, 19.5));
    frameVec2.pushBack(frame6);
    SpriteFrame* frame7 = SpriteFrame::create("21.png", Rect(0, 0, 10.8, 20));
    frameVec2.pushBack(frame7);
    SpriteFrame* frame8 = SpriteFrame::create("24.png", Rect(0, 0, 11.2, 19));
    frameVec2.pushBack(frame8);
    Animation*animation2 = Animation::createWithSpriteFrames(frameVec2);
    animation2->setLoops(-1);
    animation2->setDelayPerUnit(0.2);
    Animate*animate2 = Animate::create(animation2);
    
	
	return animate2;
}

Animate* AnimationUtil::createWithSingleFrameName_3()
{
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
    Animate*animate3 = Animate::create(animation3);
    


    return animate3;
}


Animate* AnimationUtil::createWithSingleFrameName_4()
{
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
    auto animate4 = Animate::create(animation4);
    


    return animate4;
}


USING_NS_CC;