#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"AnimationUtil.h"
#include "Player.h"
#include"TollgateScene.h"

using namespace std;

Animate* AnimationUtil::createWithSingleFrameName_bird1(int m_Image)
{
    Vector<SpriteFrame*> bird1;
    Sprite* frame1 = Sprite::create((cocos2d::StringUtils::format("%1dplayer.png", m_Image % 9)));
    SpriteFrame* bird11 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer.png", m_Image % 9)), Rect(0,0,frame1->getContentSize().width, frame1->getContentSize().height));
    bird1.pushBack(bird11);
    Sprite* frame12 = Sprite::create((cocos2d::StringUtils::format("%1dplayer12.png", m_Image % 9)));
    SpriteFrame* bird12 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer12.png", m_Image % 9)), Rect(0, 0, frame12->getContentSize().width, frame12->getContentSize().height));
    bird1.pushBack(bird12);
    SpriteFrame* bird13 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer.png", m_Image % 9)), Rect(0, 0, frame1->getContentSize().width, frame1->getContentSize().height));
    bird1.pushBack(bird13);
    Sprite* frame14 = Sprite::create((cocos2d::StringUtils::format("%1dplayer14.png", m_Image % 9)));
    SpriteFrame* bird14 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer14.png", m_Image % 9)), Rect(0, 0, frame14->getContentSize().width, frame14->getContentSize().height));
    bird1.pushBack(bird14);
    Animation* bird1_move = Animation::createWithSpriteFrames(bird1);
    bird1_move->setLoops(-1);
    bird1_move->setDelayPerUnit(0.2);
    Animate*bird1_move_action = Animate::create(bird1_move);
    

    return bird1_move_action;
}

Animate* AnimationUtil::createWithSingleFrameName_bird2(int m_Image)
{
    Vector<SpriteFrame*> bird2;//这里没有简化，四个Vector是精灵帧 spriteframe 用于建立人物走动时的动画 后面多次重复
    Sprite* frame21 = Sprite::create((cocos2d::StringUtils::format("%1dplayer21.png", m_Image % 9)));
    SpriteFrame* bird21 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer21.png", m_Image % 9)), Rect(0, 0, frame21->getContentSize().width, frame21->getContentSize().height));
    bird2.pushBack(bird21);
    Sprite* frame22 = Sprite::create((cocos2d::StringUtils::format("%1dplayer22.png", m_Image % 9)));
    SpriteFrame* bird22 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer22.png", m_Image % 9)), Rect(0, 0, frame22->getContentSize().width, frame22->getContentSize().height));
    bird2.pushBack(bird22);
    SpriteFrame* bird23 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer21.png", m_Image % 9)), Rect(0, 0, frame21->getContentSize().width, frame21->getContentSize().height));
    bird2.pushBack(bird23);
    Sprite* frame24 = Sprite::create((cocos2d::StringUtils::format("%1dplayer24.png", m_Image % 9)));
    SpriteFrame* bird24 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer24.png", m_Image % 9)), Rect(0, 0, frame24->getContentSize().width, frame24->getContentSize().height));
    bird2.pushBack(bird24);
    Animation*bird2_move = Animation::createWithSpriteFrames(bird2);
    bird2_move->setLoops(-1);
    bird2_move->setDelayPerUnit(0.2);
    Animate* bird2_move_action = Animate::create(bird2_move);
    
	
	return bird2_move_action;
}

Animate* AnimationUtil::createWithSingleFrameName_bird3(int m_Image)
{
    Vector<SpriteFrame*> bird3;
    Sprite* frame31 = Sprite::create((cocos2d::StringUtils::format("%1dplayer31.png", m_Image % 9)));
    SpriteFrame* bird31 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer31.png", m_Image % 9)), Rect(0, 0,frame31->getContentSize().width, frame31->getContentSize().height));
    bird3.pushBack(bird31);
    Sprite* frame32 = Sprite::create((cocos2d::StringUtils::format("%1dplayer32.png", m_Image % 9)));
    SpriteFrame* bird32 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer32.png", m_Image % 9)), Rect(0, 0, frame32->getContentSize().width, frame32->getContentSize().height));
    bird3.pushBack(bird32);
    SpriteFrame* bird33 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer31.png", m_Image % 9)), Rect(0, 0, frame31->getContentSize().width, frame31->getContentSize().height));
    bird3.pushBack(bird33);
    Sprite* frame34 = Sprite::create((cocos2d::StringUtils::format("%1dplayer34.png", m_Image % 9)));
    SpriteFrame* bird34 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer34.png", m_Image % 9)), Rect(0, 0, frame34->getContentSize().width, frame34->getContentSize().height));
    bird3.pushBack(bird34);
    Animation* bird3_move = Animation::createWithSpriteFrames(bird3);
    bird3_move->setLoops(-1);
    bird3_move->setDelayPerUnit(0.2);
    Animate*bird3_move_action = Animate::create(bird3_move);
    


    return bird3_move_action;
}


Animate* AnimationUtil::createWithSingleFrameName_bird4(int m_Image)
{
    Vector<SpriteFrame*> bird4;
    Sprite* frame41 = Sprite::create((cocos2d::StringUtils::format("%1dplayer41.png", m_Image % 9)));
    SpriteFrame* bird41 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer41.png", m_Image % 9)), Rect(0, 0, frame41->getContentSize().width, frame41->getContentSize().height));
    bird4.pushBack(bird41);
    Sprite* frame42 = Sprite::create((cocos2d::StringUtils::format("%1dplayer42.png", m_PlayerImage % 9)));
    SpriteFrame* bird42 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer42.png", m_Image % 9)), Rect(0, 0, frame42->getContentSize().width, frame42->getContentSize().height));
    bird4.pushBack(bird42);
    SpriteFrame* bird43 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer41.png", m_Image % 9)), Rect(0, 0, frame41->getContentSize().width, frame41->getContentSize().height));
    bird4.pushBack(bird43);
    Sprite* frame44 = Sprite::create((cocos2d::StringUtils::format("%1dplayer44.png", m_Image % 9)));
    SpriteFrame* bird44 = SpriteFrame::create((cocos2d::StringUtils::format("%1dplayer44.png", m_Image % 9)), Rect(0, 0,  frame44->getContentSize().width, frame44->getContentSize().height));
    bird4.pushBack(bird44);
    Animation* bird4_move = Animation::createWithSpriteFrames(bird4);
    bird4_move->setLoops(-1);
    bird4_move->setDelayPerUnit(0.2);
    auto bird4_move_action = Animate::create(bird4_move);
    


    return bird4_move_action;
}

Animate* AnimationUtil::createWithSingleFrameName_monster1()
{
    Vector<SpriteFrame*> monster1;
    Sprite* monsterJeny11 = Sprite::create("monster11.png");
    SpriteFrame* monster11 = SpriteFrame::create("monster11.png", Rect(0, 0, monsterJeny11->getContentSize().width, monsterJeny11->getContentSize().height));
    monster1.pushBack(monster11);
    Sprite* monsterJeny12 = Sprite::create("monster12.png");
    SpriteFrame* monster12 = SpriteFrame::create("monster12.png", Rect(0, 0, monsterJeny12->getContentSize().width, monsterJeny12->getContentSize().height));
    monster1.pushBack(monster12);
    Animation* monster1_animation = Animation::createWithSpriteFrames(monster1);
    monster1_animation->setLoops(-1);
    monster1_animation->setDelayPerUnit(0.2);
    auto monster1_animate = Animate::create(monster1_animation);

    return monster1_animate;
}

Animate* AnimationUtil::createWithSingleFrameName_monsterDuck()
{
    Vector<SpriteFrame*> monster_Duck;
    Sprite* monsterDuck11 = Sprite::create("monster3.png");
    SpriteFrame* monsterDuck1 = SpriteFrame::create("monster3.png", Rect(0, 0, monsterDuck11->getContentSize().width, monsterDuck11->getContentSize().height));
    monster_Duck.pushBack(monsterDuck1);
    Sprite* monsterDuck12 = Sprite::create("monster32.png");
    SpriteFrame* monsterDuck2 = SpriteFrame::create("monster32.png", Rect(0, 0, monsterDuck12->getContentSize().width, monsterDuck12->getContentSize().height));
    monster_Duck.pushBack(monsterDuck2);
    Animation* monster3_animation = Animation::createWithSpriteFrames(monster_Duck);
    monster3_animation->setLoops(-1);
    monster3_animation->setDelayPerUnit(0.5);
    auto monster3_animate = Animate::create(monster3_animation);

    return monster3_animate;
}


USING_NS_CC;