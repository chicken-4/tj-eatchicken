#pragma once

#ifndef __Player_H__
#define __Player_H__

#include"Entity.h"
#include<string>
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

#define PLAYER_AMOUNT             10 //һ�����乲10�����
#define PLAYER_HP                 30 //Ѫ��
#define BULLET_IN_CARTRIDGE       30 //һ���������ӵ�����
#define ORIGINAL_CARTRIDGE_AMOUNT  3 //��ʼ������

#define PLAYER_TAG        10 //10-19
#define PLAYER_BULLET_TAG 03

class Player :public Entity
{
public:
    CREATE_FUNC(Player);
    virtual bool init();
    void run(int index);
    void action();
    //void SetViewPointByPlayer();

   
    
    int GetScore();
    void printScore(Label*Score);
    void gain_bullet1();
    void gain_bullet2();
    void lose_bullet1();
    void lose_bullet2();
    void print_rest_bullet1(Label* BULLET1);
    void print_rest_bullet2(Label* BULLET2);
    void print_speed(Label* SPEED);
    void isHit();
    void isOutOfCircle();
    void alter_blood(Sprite* Blood);
    void AddHP();
    void changeSpeed();
    bool speedIsfull();
    int ChangeGunType(const int type);
    void AddCartridgeAmount();
    void ChangeCartridge(); //����
    bool isDead();
    bool bullet1_is_empty();
    bool bullet2_is_empty();
    bool bullet1_is_full();
    bool bullet2_is_full();
    void addBullet1Amount();
    void addBullet2Amount();
    int queryscore();
    float speed = 1.3;

private:
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();//����

    //Text* m_scorelab;    //������ǩ
    //LoadingBar m_hpbar; //Ѫ����

    int score = 0; 
    int bullet1 = 0;
    int bullet2 = 0;//����
    float hp = PLAYER_HP; //Ѫ��
    int gunType = 0; //��¼ǹ������
    int cartridgeAmount = 0; //ӵ�еĵ�����
    int bulletAmount = 0; //��ʹ�õ�����ʣ���ӵ���
    bool hasDead = false;
    int bullet1amount=30;
    int bullet2amount=30;
}; 

#endif