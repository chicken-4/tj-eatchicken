#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"myController.h"
#include"SimpleMoveController.h"
#include"ControllerListener.h"
#include"SceneManage.h"

//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene

//主地图

bool MySecondScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("11.png"));
	initBG();
	initIF();
	initLABEL();
	m_player->setPosition(Vec2(150, 124));
	this->addChild(m_player);
	// 定义触摸事件的监听器。监听器有两种：
   // 1.EventListenerTouchOneByOne：此类型对每个触摸事件调用一次回调方法。
   // 2.EventListenerTouchAllAtOnce：此类型对所有的触摸事件调用一次回调方法。
	auto eventListener = EventListenerTouchOneByOne::create();
	// 定义回调函数onTouchBegan():手指第一次碰到屏幕时被调用。
	eventListener->onTouchBegan = CC_CALLBACK_2(MySecondScene::onTouchBegan, this);
	// 使用EventDispatcher来处理各种各样的事件，如触摸和其他键盘事件。
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);


	//玩家动作
	SimpleMoveController* simpleMoveControll = SimpleMoveController::create();


	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;

	//auto* dispatcher = Director::getInstance()->getEventDispatcher();
	//auto* keyListener = EventListenerKeyboard::create();
	//创建一个事件监听器监听键盘事件
	//keyListener->onKeyPressed = CC_CALLBACK_2(MySecondScene::onKeyPressed, this);
	//键盘被按下时响应
	//keyListener->onKeyReleased = CC_CALLBACK_2(MySecondScene::onKeyReleased, this);
	//键盘按键被弹回时响应
	//dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	/*keyListener->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
		{
			if (code == EventKeyboard::KeyCode::KEY_S)
			{
				m_player->stopAllActions();
				m_player->run(1,0);
			}
			else if (code == EventKeyboard::KeyCode::KEY_W)
			{
				m_player->stopAllActions();
				m_player->run(2, 0);
			}
			else if (code == EventKeyboard::KeyCode::KEY_D)
			{
				m_player->stopAllActions();
				m_player->run(3, 0);
			}
			else if (code == EventKeyboard::KeyCode::KEY_A)
			{
				m_player->stopAllActions();
				m_player->run(4, 0);
			}
		});
	keyListener->onKeyReleased = ([=](EventKeyboard::KeyCode code, Event* event)
		{
			if (code == EventKeyboard::KeyCode::KEY_S)
			{
				auto moveTo = MoveTo::create(0.3, Vec2(m_player->getPositionX(), m_player->getPositionY() - 25));
				m_player->runAction(moveTo);
				m_player->stopAllActions();
				start_Page->stopAllActions();
				m_player->run(4, 1);
			}
		});*/
	auto listenerKey = EventListenerKeyboard::create();
	listenerKey->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
		{
			ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
			if (code == EventKeyboard::KeyCode::KEY_S)
			{
				m_player->stopAllActions();
				if(0)//if (m_player->getPositionY() >= 100 || start_Page->getPositionY() >= start_Page->getContentSize().height / 2)
				{
					auto moveTo = MoveTo::create(0.3, Vec2(m_player->getPositionX(), m_player->getPositionY() - 25));
					m_player->runAction(moveTo);
				}
				else
				{
					//ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
					//玩家动画
					auto moveTo1 = MoveTo::create(0.6, Vec2(start_Page->getPositionX(), start_Page->getPositionY() + 25));
					start_Page->runAction(moveTo1);
				}
				m_player->run(1);
			}
			else if (code == EventKeyboard::KeyCode::KEY_W)
			{
				m_player->stopAllActions();
				if (0)//if (m_player->getPositionY() <= 230 || start_Page->getPositionY() <= 320 - start_Page->getContentSize().height / 2)
				{
					auto moveTo = MoveTo::create(0.3, Vec2(m_player->getPositionX(), m_player->getPositionY() + 1.85));
					m_player->runAction(moveTo);

				}
				else
				{
					auto moveTo1 = MoveTo::create(0.6, Vec2(start_Page->getPositionX(), start_Page->getPositionY() - 25));
					start_Page->runAction(moveTo1);
				}

				//玩家动画
				m_player->run(2);
			}
			else if (code == EventKeyboard::KeyCode::KEY_D)
			{
				m_player->stopAllActions();
				start_Page->stopAllActions();
				if (0)//if (start_Page->getPositionX() < -1160 || m_player->getPositionX() < 35)
					//if (m_player->getPositionX() <= 330 || start_Page->getPositionX() <= 455 - start_Page->getContentSize().width / 2)
				{
					auto moveTo = MoveTo::create(0.5, Vec2(m_player->getPositionX() + 25, m_player->getPositionY()));
					m_player->runAction(moveTo);
				}
				else
				{
					auto moveTo1 = MoveTo::create(0.5, Vec2(start_Page->getPositionX() - 25, start_Page->getPositionY()));
					start_Page->runAction(moveTo1);
				}

				//玩家动画
				m_player->run(3);
			}
			else if (code == EventKeyboard::KeyCode::KEY_A)
			{
				m_player->stopAllActions();
				if (0)//if (start_Page->getPositionX() > 1600 || m_player->getPositionX() > 70)
				{
					auto moveTo = MoveTo::create(0.1, Vec2(m_player->getPositionX() - 25, m_player->getPositionY()));
					m_player->runAction(moveTo);
				}
				else
				{
					auto moveTo1 = MoveTo::create(0.1, Vec2(start_Page->getPositionX() + 25, start_Page->getPositionY()));
					start_Page->runAction(moveTo1);
				}

				//玩家动画
				m_player->run(4);
			}

		});

	auto dispatcher = Director::getInstance()->getEventDispatcher();

	//添加到事件分发器
	dispatcher->addEventListenerWithSceneGraphPriority(listenerKey, this);

	/*控制器要添加到场景中才能让update调用*/
	this->addChild(simpleMoveControll);

	/*设置控制器到主角身上*/
	m_player->setController(simpleMoveControll);

	this->scheduleUpdate();//跑动地图

	return true;
}



//创建房间


bool MyThirdScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	auto label1 = Label::createWithSystemFont("create new room,main menu", "fonts/arial.ttf", 30);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MyThirdScene::EnterFirstScene, this));
	auto menu1 = Menu::create(menuitem1, NULL);
	menuitem1->setPosition(Vec2(0, 80));
	this->addChild(menu1);

	auto label2 = Label::create();
	label2->setString("startgame"); 
	//auto label2 = Label::createWithSystemFont("create new room there,click to return the main map", "fonts/arial.ttf", 30);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MyThirdScene::EnterSecondScene, this));
	auto menu2 = Menu::create(menuitem2, NULL);
	this->addChild(menu2);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	auto menu3 = Menu::create();
	//label->setPosition(Vec2(300, 175));
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(MyThirdScene::EXIT, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu3);

	return true;
}


//最后结算


bool MyForthScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	auto label1 = Label::create();
	label1->setString("final,mainmenu");
	auto menu1 = Menu::create();
	//auto label1 = Label::createWithSystemFont("final,mainmenu", "fonts/arial.ttf", 30);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MyForthScene::EnterFirstScene, this));
	menuitem1->setPosition(Vec2(0, 110));
	menu1->addChild(menuitem1);
	this->addChild(menu1);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	auto menu3 = Menu::create();
	//label->setPosition(Vec2(300, 175));
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(MyForthScene::EXIT, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu3);

	return true;
}


