#pragma once

#ifndef __MONSTER2_H__
#define __MONSTER2_H__

#include "Entity.h"
#include "Player.h"
#include "AIPlayer.h"

#define DUCK_TAG  90
#define MISSILE_TAG 210 //210-219

#define DUCK_HP 30

class Missile;

class MonsterDuck :public Entity{
public:
    virtual bool init();
    void createMissiles(); //一次创建PLAYER_AMOUNT个missile 储存至vecMissiles
    CREATE_FUNC(MonsterDuck);

    void BindPlayers(std::vector<Player*> sprites);//绑定玩家
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//绑定ai玩家
    void BindScene(cocos2d::Scene* scene);
    void BindBackground(cocos2d::Sprite* sprite);
    void SetMissiles();
   
    void isHit();
    bool isDead();

    std::vector<Missile*> GetMissiles();
    std::map<int, Missile*> GetMapMissile();
private:
    std::vector<Missile*> vecMissiles;
    std::vector<cocos2d::Sprite*> vecTargets;
    std::map<int, Missile*> mapMissileTag;
    cocos2d::Scene* myScene;
    cocos2d::Sprite* background;
    cocos2d::Sprite* target;
    int hp = DUCK_HP; //血量
};


class Missile :public Entity {
public:
    virtual bool init();
    CREATE_FUNC(Missile);

    void BindTarget(cocos2d::Sprite* sprite);//绑定攻击对象
    void BindDuck(MonsterDuck* duck);

    void Move(); //靠近玩家
    void Reset();

    virtual void update(float dt);
private:
    cocos2d::Sprite* target = NULL;
    MonsterDuck* myDuck;
    const float speed = 3; //移动速度
    bool inUse = true;
};


#endif