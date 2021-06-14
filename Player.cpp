//#include "HelloWorldScene.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"

using namespace std;

USING_NS_CC;

bool Player::init()
{
    return true;
}

//���ﶯ�����������������ĸ�������ƶ�
//��д�˵�һ�棬ͨ��ͼƬ���ʹ������Ӽ��
void Player::run(int index)
{
    SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
    if (index == 1)
        frameCache->addSpriteFramesWithFile("front.plist", "front.png");
    else if (index == 2)
        frameCache->addSpriteFramesWithFile("behind.plist", "behind.png");
    else if (index == 3)
        frameCache->addSpriteFramesWithFile("right.plist", "right.png");
    else if (index == 4)
        frameCache->addSpriteFramesWithFile("left.plist", "left.png");
    SpriteFrame* frame = NULL;
    Vector<SpriteFrame*>frameList;

    for (int i = 1; i < 5; i++)
    {
        frame = frameCache->getSpriteFrameByName(StringUtils::format("%d%d.png", index, i));
        frameList.pushBack(frame);
    }

    Animation* animation = Animation::createWithSpriteFrames(frameList);
    animation->setLoops(1);
    animation->setRestoreOriginalFrame(true);
    animation->setDelayPerUnit(0.2f);

    Animate* animate = Animate::create(animation);
    //m_sprite->stopAction(animate);
    this->runAction(animate);
}

/*void Player::SetViewPointByPlayer()
{
    if (m_sprite == NULL)
        return;
    Layer* parent = (Layer*)getParent;
}*/

void Player::action()
{

}

/////////////////////////////////////

void Player::AddHP()
{
    if (hp < PLAYER_HP / 2) {
        hp += PLAYER_HP / 2; //һ��ҽ�ư���һ��Ѫ
    }
    else {
        hp = PLAYER_HP;
    }
}

//0-��ǹ 1-һ�η���һ���ӵ� 2-һ�η��������ӵ�
void Player::ChangeGunType(const int type)
{
    gunType = type;
    if (type != 0) {
        cartridgeAmount = ORIGINAL_CARTRIDGE_AMOUNT;
        bulletAmount = BULLET_IN_CARTRIDGE;
    }
}

void Player::AddCartridgeAmount()
{
    cartridgeAmount++;
}

void Player::ChangeCartridge()
{
    bulletAmount = BULLET_IN_CARTRIDGE;
    cartridgeAmount--;
}