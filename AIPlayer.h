//ai��� û�ж��� ��Monster�����һ��
/*  ʹ�ã�
    //���λ��
    srand((unsigned)time(NULL));
    float minX, minY, maxX, maxY, randomX, randomY;
    //����ai���
    std::vector<AIPlayer*> aiPlayers;
    for (int i = 0; i < PLAYER_AMOUNT - humanPlayerAmount; i++) {
        aiPlayers.push_back(AIPlayer::create());
        aiPlayers[i]->BindCharacter(Sprite::create("11.png"));

        minX = aiPlayers[i]->getContentSize().width, minY = aiPlayers[i]->getContentSize().height;
        maxX = 480 - minX, maxY = 320 - minY; //���ڴ�С����
        randomX = (rand() % static_cast<int>(maxX - minX)) + rand() / static_cast<float>(maxX) + minX;
        randomY = (rand() % static_cast<int>(maxY - minY)) + rand() / static_cast<float>(maxY) + minY;
        aiPlayers[i]->setPosition(randomX, randomY);

        aiPlayers[i]->BindScene(this);
        this->addChild(aiPlayers[i]);
    }

    ����//��������

    //ai��Ұ󶨹���
    for (int i = 0; i < aiPlayers.size(); i++) {
        aiPlayers[i]->BindMonsters(monsterManager->GetVecMonsters());
    }
*/
#pragma once

#ifndef __MYAIPLAYER_H__
#define __MYAIPLAYER_H__

#include "Entity.h"
#include "Monster.h"

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
    const float distanceForAttack = 150; //���ӵ������ͬ
    const float speed = 3; //�ƶ��ٶȣ�ÿ0.5�룩
    bool shoot = true;
    bool moveWhenAttack = true;
    int hp = 10; //Ѫ��
};

#endif