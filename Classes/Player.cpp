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

//人物动画，包括上下左右四个方向的移动
//重写了第一版，通过图片打包使程序更加简洁


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

int Player::GetScore()
{
    score++;
    return score;
}


void Player::printScore(Label*Score)
{
    
    Score->setString((cocos2d::StringUtils::format("%3d", score)));
}

void Player::print_rest_bullet1(Label* BULLET1)
{
    BULLET1->setString((cocos2d::StringUtils::format("%3d", bullet1)));
}
void Player::print_rest_bullet2(Label* BULLET2)
{
    BULLET2->setString((cocos2d::StringUtils::format("%3d", bullet2)));
}

void Player::lose_bullet1()
{
    bullet1--;
}

void Player::lose_bullet2()
{
    bullet2--;
}

void Player::gain_bullet1()
{
    if (!bullet1_is_full()) {
       bullet1 = bullet1 + 10;
    }
    else {
        bullet1 = 30;
    }
}

void Player::gain_bullet2()
{
    if (!bullet2_is_full()){ 
        bullet2 = bullet2 + 10;
    }
    else {
        bullet2 = 30;
    }
}

bool Player::bullet1_is_empty()
{
    if (bullet1 <= 0) {
        return true;
    }
    return false;
}

bool Player::bullet2_is_empty()
{
    if (bullet2 <= 0) {
        return true;
    }
    return false;
}

bool Player::bullet1_is_full()
{
    if (bullet1 >= 20) {
        return true;
    }
    return false;
}

bool Player::bullet2_is_full()
{
    if (bullet2 >= 20) {
        return true;
    }
    return false;
}


void Player::isHit()
{
    if (!isDead()) {
        hp--;
    }
    CCLOG("%d", hp);
}

void Player::alter_blood(Sprite* Blood)
{
    Blood->setContentSize(Size(9 * hp, 80));
}

bool Player::isDead()
{
    if (hp <= 0)
        return true;
    return false;
}

int Player::queryscore()
{
    return score;
}

void Player::AddHP()
{
    if (hp < PLAYER_HP / 2) {
        hp += PLAYER_HP / 2; //一个医疗包回一半血
    }
    else {
        hp = PLAYER_HP;
    }
}

//0-无枪 1-一次发射一颗子弹 2-一次发射三颗子弹
int Player::ChangeGunType(const int type)
{
    gunType = type;
    if (type != 0) {
        cartridgeAmount = ORIGINAL_CARTRIDGE_AMOUNT;
        bulletAmount = BULLET_IN_CARTRIDGE;
    }
    return type;
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