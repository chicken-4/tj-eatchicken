#pragma once
#include"cocos2d.h"
#include"Player.h"
#include "AIPlayer.h"
#include "Monster.h"

#define BORDER_TAG   -10
#define BRICK_TAG   -400
#define GRASS_TAG   -600
#define GUN1_TAG   100
#define GUN2_TAG   110
#define PILL_TAG   120

#define BRICK_AMOUNT  399
#define GRASS_AMOUNT 200
#define GUN1_AMOUNT  10
#define GUN2_AMOUNT 10
#define PILL_AMOUNT 20

using namespace cocos2d;
class Player;
class MySecondScene :public Scene//主地图
{
public:
	//void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* events);
	static Scene* createScene();
	void update_W(float delta);
	void update_S(float delta);
	void update_A(float delta);
	void update_D(float delta);
	void update(float delta) override;
	CREATE_FUNC(MySecondScene);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);//声明回调函数
	virtual bool init();
	void initIF();
	void initBG();
	void initLABEL();
	void EnterForthScene(Ref* pSender);//最终结算
	void EXIT(Ref* pSender);//退出

	cocos2d::SpriteBatchNode* brick;
	cocos2d::SpriteBatchNode* gress;
	cocos2d::SpriteBatchNode* gun1;
	cocos2d::SpriteBatchNode* gun2;
	cocos2d::SpriteBatchNode* pill;
	void keyPressedDuration_W();
	void keyPressedDuration_A();
	void keyPressedDuration_S();
	void keyPressedDuration_D();

	bool onContactBegin(cocos2d::PhysicsContact& contact);
	bool onContactSeparate(cocos2d::PhysicsContact& contact);
private:
	Sprite* m_blood;
	Sprite* bloodout;
	Sprite* start_Page;
	Sprite* border1;
	Sprite* border2;
	Sprite* border3;
	Sprite* border4;
	Sprite* box;
	Sprite* tree;
	Sprite* ball;
	Sprite* Gun1;
	Sprite* Gun2;
	Sprite* Pill;
	Label* blood_label;
	Label* score_label;
	Label* Score;
	Label* time_label;
	Sprite* Small_map;

	bool hasDead = false;
private:
	std::vector<Player*> vecPlayer;
	std::vector<AIPlayer*> vecAIPlayer;
	std::vector<Monster*> vecMonster;
	std::map<int, Player*> mapPlayerTag;
	std::map<int, AIPlayer*> mapAIPlayerTag;
	std::map<int, Monster*> mapMonsterTag;
	Player* m_player;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
};

class MyThirdScene :public Layer//创建房间
{
public:
	static Scene* createScene();

	CREATE_FUNC(MyThirdScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);//主界面
	void EnterSecondScene(Ref* pSender);//主地图
	void EXIT(Ref* pSender);//退出
	Sprite* start_Page;
};

class MyForthScene :public Layer//最终结算
{
public:
	static Scene* createScene();

	CREATE_FUNC(MyForthScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);//主界面
	void EXIT(Ref* pSender);//退出
	Sprite* start_Page;
};

class MyFifthScene :public Layer//创建房间
{
public:
	static Scene* createScene();

	CREATE_FUNC(MyFifthScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);//主界面
	void EnterSecondScene(Ref* pSender);//主地图
	void EXIT(Ref* pSender);//退出
	Sprite* start_Page;
};


/*#ifndef __SceneManage_H__
#define __SceneManage_H__

#include"cocos2d.h"
using namespace cocos2d;

USING_NS_CC; */

/*class SceneManage
{
public:
	SceneManage();
	~SceneManage();
	Scene* UIscene;
	void goUIscene();
private:*/

//};

/*class UILayer:public Layer
{
public:
	UILayer();
	~UILayer();
	CREATE_FUNC(UILayer);
	virtual bool init();
	bool initUI();
	void menuItemCallBack(Ref* pSender);
	SceneManage* m_sceneManage;
	Label* POBG;
};
#endif*/
