/*  使用：
    //创建怪物
    auto monsterManager = MonsterManager::create();
    monsterManager->BindPlayers(players); //绑定玩家
    monsterManager->BindAIPlayers(aiPlayers); //绑定ai玩家
    monsterManager->BindScene(this); //绑定场景
    this->addChild(monsterManager);
*/
#pragma once

#ifndef __MYMONSTER_H__
#define __MYMONSTER_H__

#include "Entity.h"
#include "Player.h"
#include "AIPlayer.h"

#define MONSTER_AMOUNT 3
#define MONSTER_HP 3

class AIPlayer;

class Monster :public Entity {
public:
    virtual bool init();
    CREATE_FUNC(Monster);

    void BindPlayers(std::vector<Player*> sprites);//绑定玩家
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//绑定ai玩家 模板函数没做出来 之后可能再尝试
    void BindScene(cocos2d::Scene* scene);
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
    const float distanceForAttack = 150; //与子弹射程相同
    const float speed = 2; //移动速度（每0.5秒）
    const int shootGap = 30;//子弹发射间隔（每shootGap帧发射一个子弹）
    int count; //辅助控制子弹发射间隔
    int hp = MONSTER_HP; //血量
    cocos2d::Scene* myScene;
};

////////////////////////////////////////////

//写法参考钟迪南《Cocos2d - x 3.x游戏开发之旅》

class MonsterManager :public cocos2d::Node {
public:
    virtual bool init();
    void createMonsters(); //一次创建MONSTER_AMOUNT个monster 储存至vecMonsters
    CREATE_FUNC(MonsterManager);

    void BindPlayers(std::vector<Player*> sprites);
    void BindAIPlayers(std::vector<AIPlayer*> sprites);
    void BindScene(cocos2d::Scene* scene);
    std::vector<Monster*> GetVecMonsters();
private:
    std::vector<Monster*> vecMonsters;
    std::vector<cocos2d::Sprite*> vecPlayers;
};


#endif