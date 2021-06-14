#pragma once
#include"cocos2d.h"
#include"Player.h"
using namespace cocos2d;
class Player;
class MySecondScene :public Layer//主地图
{
public:
	static Scene* createScene();
	virtual void update(float delta);
	CREATE_FUNC(MySecondScene);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);//声明回调函数
	virtual bool init();
	void initIF();
	void initBG();
	void initLABEL();
	void EnterForthScene(Ref* pSender);//最终结算
	void EXIT(Ref* pSender);//退出
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
	Label* blood_label;
	Label* score_label;
	Label* time_label;
	Sprite* Small_map;
private:
	Player* m_player;
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
};
class MyForthScene :public Layer//最终结算
{
public:
	static Scene* createScene();

	CREATE_FUNC(MyForthScene);

	virtual bool init();

	void EnterFirstScene(Ref* pSender);//主界面
	void EXIT(Ref* pSender);//退出
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
