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

    void BindPlayers(std::vector<Player*> sprites);//�����
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//��ai��� ģ�庯��û������ ֮������ٳ���
    void BindScene(cocos2d::Scene* scene);
    void BindBackground(cocos2d::Sprite* sprite);
    float GetDistanceForMove();
    float GetDistanceForAttack();
    cocos2d::Sprite* GetDistance(); //�����������Ҽ����
    bool isGoingToMove();
    bool isGoingToAttack();

    void Wait(cocos2d::Sprite* player);
    void Move(cocos2d::Sprite* player); //�������
    void Attack(cocos2d::Sprite* player); //�������

    void isHit();
    bool isDead();
    void Reset(); //����

    virtual void update(float dt);
private:
    std::vector<cocos2d::Sprite*> vecPlayers;
    float distanceFromPlayer;
    const float distanceForMove = 500;
    const float distanceForAttack = 100; //���ӵ������ͬ
    const float speed = 0.5; //�ƶ��ٶȣ�ÿ0.5�룩
    const int shootGap = 30;//�ӵ���������ÿshootGap֡����һ���ӵ���
    int count; //���������ӵ�������
    int hp = MONSTER_HP; //Ѫ��
    cocos2d::Scene* myScene;
    cocos2d::Sprite* background;
};


#endif