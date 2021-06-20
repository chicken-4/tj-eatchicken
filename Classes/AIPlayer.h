#pragma once

#ifndef __MYAIPLAYER_H__
#define __MYAIPLAYER_H__

#include "Entity.h"
#include "Monster.h"

#define AIPLAYER_TAG 20 //20-29
#define AIPLAYER_BULLET_TAG 200 //200-209

class Monster;

class AIPlayer : public Entity {
public:
    virtual bool init();
    CREATE_FUNC(AIPlayer);

    void BindMonsters(std::vector<Monster*> sprites);
    void BindScene(cocos2d::Scene* scene);
    void SetNum(const int i);
    float GetDistanceForAttack();
    Monster* GetDistance();
    bool isGoingToAttack();

    void Wait();
    void Move(Monster* monster);
    void Attack(Monster* monster);

    void GetScore();
    void isHit();
    bool isDead();

    virtual void update(float dt);

    int queryscore();
private:
    std::vector<Monster*> vecMonsters;
    cocos2d::Scene* myScene;
    float distanceFromMonster;
    const float distanceForAttack = 80; //与子弹射程相同
    const float speed = 1; //移动速度（每0.5秒）
    bool shoot = true;
    bool moveWhenAttack = true;
    int hp = 10; //血量
    int num = 0; //标记是第几个被创建的ai玩家
    int score = 0; //得分
};

#endif