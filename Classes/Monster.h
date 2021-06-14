/*  ʹ�ã�
    //��������
    auto monsterManager = MonsterManager::create();
    monsterManager->BindPlayers(players); //�����
    monsterManager->BindAIPlayers(aiPlayers); //��ai���
    monsterManager->BindScene(this); //�󶨳���
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

    void BindPlayers(std::vector<Player*> sprites);//�����
    void BindAIPlayers(std::vector<AIPlayer*> sprites);//��ai��� ģ�庯��û������ ֮������ٳ���
    void BindScene(cocos2d::Scene* scene);
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
    const float distanceForAttack = 150; //���ӵ������ͬ
    const float speed = 2; //�ƶ��ٶȣ�ÿ0.5�룩
    const int shootGap = 30;//�ӵ���������ÿshootGap֡����һ���ӵ���
    int count; //���������ӵ�������
    int hp = MONSTER_HP; //Ѫ��
    cocos2d::Scene* myScene;
};

////////////////////////////////////////////

//д���ο��ӵ��ϡ�Cocos2d - x 3.x��Ϸ����֮�á�

class MonsterManager :public cocos2d::Node {
public:
    virtual bool init();
    void createMonsters(); //һ�δ���MONSTER_AMOUNT��monster ������vecMonsters
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