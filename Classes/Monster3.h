#pragma once

#ifndef __MONSTER3_H__
#define __MONSTER3_H__

#include "Entity.h"
#include "Player.h"
#include "AIPlayer.h"

#define GHOST_TAG  80 //80-89
#define GHOST_AMOUNT 10

class Ghost :public Entity {
public:
    virtual bool init();
    CREATE_FUNC(Ghost);

    void BindPlayers(std::vector<Player*> sprites);//绑定玩家
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//绑定ai玩家

    float GetDistanceForMove();
    cocos2d::Sprite* GetDistance(); //计算怪物与玩家间距离
    bool isGoingToMove();

    void Wait();
    void Move(cocos2d::Sprite* player); //靠近玩家

    virtual void update(float dt);
    cocos2d::Node* myPoint;
private:
    std::vector<cocos2d::Sprite*> vecPlayers;
    float distanceFromPlayer;
    const float distanceForMove = 150;
    const float speed = 4; //移动速度
};


#endif