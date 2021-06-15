#pragma once

#ifndef __MYMONSTER_H__
#define __MYMONSTER_H__

#include "Entity.h"
#include "Player.h"
#include "AIPlayer.h"

#define MONSTER_TAG  30 //30-59
#define BULLET_TAG   01

#define MONSTER_AMOUNT 30
#define MONSTER_HP 3

class AIPlayer;

class Monster :public Entity {
public:
    virtual bool init();
    CREATE_FUNC(Monster);

    void BindPlayers(std::vector<Player*> sprites);//绑定玩家
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//绑定ai玩家 模板函数没做出来 之后可能再尝试
    void BindScene(cocos2d::Scene* scene);
    void BindBackground(cocos2d::Sprite* sprite);
    float GetDistanceForMove();
    float GetDistanceForAttack();
    cocos2d::Sprite* GetDistance(); //计算怪物与玩家间距离
    bool isGoingToMove();
    bool isGoingToAttack();

    void Wait(cocos2d::Sprite* player);
    void Move(cocos2d::Sprite* player); //靠近玩家
    void Attack(cocos2d::Sprite* player); //攻击玩家

    void isHit();
    bool isDead();
    void Reset(); //重置

    virtual void update(float dt);
private:
    std::vector<cocos2d::Sprite*> vecPlayers;
    float distanceFromPlayer;
    const float distanceForMove = 500;
    const float distanceForAttack = 100; //与子弹射程相同
    const float speed = 0.5; //移动速度（每0.5秒）
    const int shootGap = 30;//子弹发射间隔（每shootGap帧发射一个子弹）
    int count; //辅助控制子弹发射间隔
    int hp = MONSTER_HP; //血量
    cocos2d::Scene* myScene;
    cocos2d::Sprite* background;
};


#endif