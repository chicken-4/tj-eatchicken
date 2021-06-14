//游戏主角类的绘制
/*  使用： //为了联机做的vector 但地图位置确定只用到一个player 怎么改再看吧
    int humanPlayerAmount = 1;//加入房间的人类玩家数
    //创建玩家对象
    std::vector<Player*> players;
    for (int i = 0; i < humanPlayerAmount; i++) {
        players.push_back(Player::create());
        players[i]->BindCharacter(Sprite::create("11.jpg"));
        players[i]->setPosition(getContentSize().width / 2, getContentSize().height / 2);
        this->addChild(players[i]); //图层待处理
    }
*/

#pragma once

#ifndef __Player_H__
#define __Player_H__

#include"Entity.h"
#include<string>
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

#define PLAYER_AMOUNT              2 //一个房间共10个玩家
#define PLAYER_HP                 10 //血量
#define BULLET_IN_CARTRIDGE       30 //一个弹夹内子弹个数
#define ORIGINAL_CARTRIDGE_AMOUNT  3 //初始弹夹数

class Player :public Entity
{
public:
    CREATE_FUNC(Player);
    virtual bool init();
    void run(int index);
    void action();
    //void SetViewPointByPlayer();

    Animate* animate1;
    Animate* animate2;
    Animate* animate3;
    Animate* animate4;

    void AddHP();
    void ChangeGunType(const int type);
    void AddCartridgeAmount();
    void ChangeCartridge(); //换弹

private:
    int m_iScore;         //分数
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();//动作

    //Text* m_scorelab;    //分数标签
    //LoadingBar m_hpbar; //血量条

    int hp = PLAYER_HP; //血量
    int gunType = 0; //记录枪的类型
    int cartridgeAmount = 0; //拥有的弹夹量
    int bulletAmount = 0; //现使用弹夹内剩余子弹数
};

#endif