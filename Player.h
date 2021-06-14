//��Ϸ������Ļ���
/*  ʹ�ã� //Ϊ����������vector ����ͼλ��ȷ��ֻ�õ�һ��player ��ô���ٿ���
    int humanPlayerAmount = 1;//���뷿������������
    //������Ҷ���
    std::vector<Player*> players;
    for (int i = 0; i < humanPlayerAmount; i++) {
        players.push_back(Player::create());
        players[i]->BindCharacter(Sprite::create("11.jpg"));
        players[i]->setPosition(getContentSize().width / 2, getContentSize().height / 2);
        this->addChild(players[i]); //ͼ�������
    }
*/

#pragma once

#ifndef __Player_H__
#define __Player_H__

#include"Entity.h"
#include<string>
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

#define PLAYER_AMOUNT              2 //һ�����乲10�����
#define PLAYER_HP                 10 //Ѫ��
#define BULLET_IN_CARTRIDGE       30 //һ���������ӵ�����
#define ORIGINAL_CARTRIDGE_AMOUNT  3 //��ʼ������

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
    void ChangeCartridge(); //����

private:
    int m_iScore;         //����
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();//����

    //Text* m_scorelab;    //������ǩ
    //LoadingBar m_hpbar; //Ѫ����

    int hp = PLAYER_HP; //Ѫ��
    int gunType = 0; //��¼ǹ������
    int cartridgeAmount = 0; //ӵ�еĵ�����
    int bulletAmount = 0; //��ʹ�õ�����ʣ���ӵ���
};

#endif