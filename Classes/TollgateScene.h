#pragma once
#ifndef __TollgateScene_H__
#define __TollgateScene_H__

#include"cocos2d.h"
using namespace cocos2d;

extern int m_PlayerImage;
class Player;
class TollgateScene :public Scene
{
public:
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);//�����ص�����
	void MySecondScene(Ref* pSender);
	void MyThirdScene(Ref* pSender);
	void MyFifthScene(Ref* pSender);//enter room
	void EXIT(Ref* pSender);
    void ChangeImageToBird(Ref* pSender);
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);
	virtual void update(float delta);
	cocos2d::PhysicsBody* physicsBody1;
private:
	void initBG();//��ʼ���ؿ�����
	//void initIF();
	void initBeginning();
private://��private��ȫ��Ϊ����ͼ�в���
	//Sprite* Small_map;//��������1
	Sprite* m_bgSprite2;//��������2
	/*Sprite* m_blood;
	Sprite* bloodout;*/
	Sprite* start_Page;
	Sprite* border1;
	Sprite* border2;
	Sprite* border3;
	Sprite* border4;
	Sprite* bird;
	/*Sprite* box;
	Sprite* tree;
	Sprite* ball;
	Label* blood_label;
	Label* score_label;
	Label* time_label;*/
	Label* POBG;
	Label* STARTGAME;
	Label* CREATEROOM;
	Label* ENTERROOM;
	Label* Exit;
	int AudioID1; int AudioID2;
	

	Sprite* black1;
	std::map<cocos2d::EventKeyboard::KeyCode, bool>keys;
private:
	Player* m_player;//����
}; 


#endif
