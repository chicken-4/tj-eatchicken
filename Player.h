#pragma once

#ifndef __Player_H__
#define __Player_H__

#include"Entity.h"
#include<string>
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

#define PLAYER_AMOUNT             10 //一个房间共10个玩家
#define PLAYER_HP                 30 //血量
#define BULLET_IN_CARTRIDGE       30 //一个弹夹内子弹个数
#define ORIGINAL_CARTRIDGE_AMOUNT  3 //初始弹夹数

#define PLAYER_TAG        10 //10-19
#define PLAYER_BULLET_TAG 03

class Player :public Entity
{
public:
    CREATE_FUNC(Player);
    virtual bool init();
    void run(int index);
    void action();
    //void SetViewPointByPlayer();

   
    
    int GetScore();
    void printScore(Label*Score);
    void gain_bullet1();
    void gain_bullet2();
    void lose_bullet1();
    void lose_bullet2();
    void print_rest_bullet1(Label* BULLET1);
    void print_rest_bullet2(Label* BULLET2);
    void print_speed(Label* SPEED);
    void isHit();
    void isOutOfCircle();
    void alter_blood(Sprite* Blood);
    void AddHP();
    void changeSpeed();
    bool speedIsfull();
    int ChangeGunType(const int type);
    void AddCartridgeAmount();
    void ChangeCartridge(); //换弹
    bool isDead();
    bool bullet1_is_empty();
    bool bullet2_is_empty();
    bool bullet1_is_full();
    bool bullet2_is_full();
    void addBullet1Amount();
    void addBullet2Amount();
    int queryscore();
    float speed = 1.3;

private:
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();//动作

    //Text* m_scorelab;    //分数标签
    //LoadingBar m_hpbar; //血量条

    int score = 0; 
    int bullet1 = 0;
    int bullet2 = 0;//分数
    float hp = PLAYER_HP; //血量
    int gunType = 0; //记录枪的类型
    int cartridgeAmount = 0; //拥有的弹夹量
    int bulletAmount = 0; //现使用弹夹内剩余子弹数
    bool hasDead = false;
    int bullet1amount=30;
    int bullet2amount=30;
}; 

#endif