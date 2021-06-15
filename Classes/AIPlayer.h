#pragma once

#ifndef __MYAIPLAYER_H__
#define __MYAIPLAYER_H__

#include "Entity.h"
#include "Monster.h"

#define AIPLAYER_TAG 20 //20-29

class Monster;

class AIPlayer : public Entity {
public:
    virtual bool init();
    CREATE_FUNC(AIPlayer);

    void BindMonsters(std::vector<Monster*> sprites);
    void BindScene(cocos2d::Scene* scene);
    float GetDistanceForAttack();
    Monster* GetDistance();
    bool isGoingToAttack();

    void Move(Monster* monster);
    void Attack(Monster* monster);

    void isHit();
    bool isDead();

    virtual void update(float dt);
private:
    std::vector<Monster*> vecMonsters;
    cocos2d::Scene* myScene;
    float distanceFromMonster;
    const float distanceForAttack = 80; //���ӵ������ͬ
    const float speed = 0.5; //�ƶ��ٶȣ�ÿ0.5�룩
    bool shoot = true;
    bool moveWhenAttack = true;
    int hp = 10; //Ѫ��
};

#endif
