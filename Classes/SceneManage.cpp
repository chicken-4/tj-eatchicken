#include<string>
#include<AudioEngine.h>
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"
#include"TimeCounter.h"


//�������л�������ͼ���������������
//��ʼ��������tollgatescene

//����ͼ
bool MySecondScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	if (!Scene::initWithPhysics())
	{
		return false;
	}


	/*********************************************************************/
	/*�������ж��������ң�����monster�󶨵���vector�����ﴴ��һ��ֻ��һ��Ԫ�ص�vector����m_player*/

	int humanPlayerAmount = 1;//���뷿������������

	for (int i = 0; i < humanPlayerAmount; i++) {
		vecPlayer.push_back(Player::create());
		vecPlayer[i]->bindSprite(Sprite::create((cocos2d::StringUtils::format("%1dplayer.png", m_PlayerImage % 9))));
		auto playerBody = PhysicsBody::createBox(vecPlayer[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		playerBody->setDynamic(false);
		playerBody->setContactTestBitmask(0xFFFFFFFF);
		vecPlayer[i]->setPhysicsBody(playerBody);
		vecPlayer[i]->setTag(PLAYER_TAG + i);
		mapPlayerTag.insert(std::pair<int, Player*>(PLAYER_TAG + i, vecPlayer[i]));
	}
	m_player = vecPlayer[0];

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	//ȡ���������
	srand((unsigned int)time(NULL));

	//����
	initBG();
	initIF();
	initLABEL();

	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::addCircle), 120);

	m_player->setPosition(Vec2(240, 160));
	this->addChild(m_player);

	//��������ai���
	addMonstersAndAI(humanPlayerAmount);
	

	auto eventListener = EventListenerTouchOneByOne::create();
	eventListener->onTouchBegan = CC_CALLBACK_2(MySecondScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
	
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;

	//���̼���
	listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird2(m_PlayerImage));
			keys[EventKeyboard::KeyCode::KEY_W] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird1(m_PlayerImage));
			keys[EventKeyboard::KeyCode::KEY_S] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird3(m_PlayerImage));
			keys[EventKeyboard::KeyCode::KEY_D] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird4(m_PlayerImage));
			keys[EventKeyboard::KeyCode::KEY_A] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
			auto jump = JumpTo::create(0.4, Vec2(m_player->getPositionX(), m_player->getPositionY()), 20, 1);
			m_player->runAction(jump);
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_ALT) {

		}//��Ӧ���̲������Ż�ֹͣ��ͬ�ľ���֡
		if (keyCode == EventKeyboard::KeyCode::KEY_ALT) {
			//��д��ת ��ȱ���ز�
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_X) {//���Ƽ�
			if (Pill != nullptr) {
				m_player->AddHP();
				m_player->alter_blood(m_blood);
				Pill->removeFromParentAndCleanup(true);
				Pill = nullptr;
			}
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_1) {
			//�л�����
			if (Gun1 != nullptr) {
				guntype = 2;
				bagblock3->initWithFile("bagblock.png");
				bagblock1->initWithFile("bagblock_ing.png");
			}
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_2) {
			//�л�����
			if (Gun2 != nullptr) {
				guntype = 1;
				bagblock1->initWithFile("bagblock.png");
				bagblock3->initWithFile("bagblock_ing.png");
			}
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_P) {
			keys[EventKeyboard::KeyCode::KEY_A]=false;
			keys[EventKeyboard::KeyCode::KEY_S]=false;
			keys[EventKeyboard::KeyCode::KEY_W]=false;
			keys[EventKeyboard::KeyCode::KEY_D]=false; 
			//P��������ϵͳ
			listener->setEnabled(false);
			speak = Label::create();
			speak->setString(" ");
			speak->setColor(Color3B(0, 0, 0));
			speak->setPosition(250, 170);
			this->addChild(speak);
			auto please = Label::create();
			please->setString("Please input word:");
			please->setPosition(250, 190);
			please->setScale(2);
			please->setColor(Color3B(0, 0, 0));
			this->addChild(please);

			auto chat = Label::create();
			chat->setString("CHAT:");
			chat->setPosition(50, 200);
			chat->setColor(Color3B(0, 0, 0));
			this->addChild(chat);

			auto speaklistener = EventListenerKeyboard::create();
			speaklistener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
				if (word.length() <= 10) {
					if (keyCode == EventKeyboard::KeyCode::KEY_A) {
						word = word + "a";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_B) {
						word = word + "b";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_C) {
						word = word + "c";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_D) {
						word = word + "d";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_E) {
						word = word + "e";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_F) {
						word = word + "f";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_G) {
						word = word + "g";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_H) {
						word = word + "h";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_I) {
						word = word + "i";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_J) {
						word = word + "j";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_K) {
						word = word + "k";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_L) {
						word = word + "l";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_M) {
						word = word + "m";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_N) {
						word = word + "n";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_O) {
						word = word + "o";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_P) {
						word = word + "p";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_Q) {
						word = word + "q";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_R) {
						word = word + "r";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_S) {
						word = word + "s";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_T) {
						word = word + "t";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_U) {
						word = word + "u";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_V) {
						word = word + "v";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_W) {
						word = word + "w";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_X) {
						word = word + "x";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_Y) {
						word = word + "y";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_Z) {
						word = word + "z";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_1) {
						word = word + "1";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_2) {
						word = word + "2";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_3) {
						word = word + "3";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_4) {
						word = word + "4";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_5) {
						word = word + "5";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_6) {
						word = word + "6";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_7) {
						word = word + "7";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_8) {
						word = word + "8";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_9) {
						word = word + "9";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_0) {
						word = word + "0";
						speak->setString(word);
					}
					else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
						word = word + " ";
						speak->setString(word);
					}
				}
				 if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
						speak->setString("me:" + word);
						speak->setOpacity(60);
						speak->setAnchorPoint(Vec2(0, 0));
						speak->setPosition(50, 180 + position);
						position = position - 10;
						word = " ";
						please->removeFromParent();
						this->getEventDispatcher()->removeEventListener(speaklistener);
						listener->setEnabled(true);
				 }
				 else if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE) {
					 word = word.substr(0, word.length() - 1);
					 speak->setString(word);
					 
				 }
			
			};
			_eventDispatcher->addEventListenerWithSceneGraphPriority(speaklistener, this);
		}
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird1(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird4(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird3(m_PlayerImage));
			}
			keys[EventKeyboard::KeyCode::KEY_W] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird2(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird4(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird3(m_PlayerImage));
			}
			keys[EventKeyboard::KeyCode::KEY_S] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird2(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird1(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird4(m_PlayerImage));
			}
			keys[EventKeyboard::KeyCode::KEY_D] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird2(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird1(m_PlayerImage));
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird3(m_PlayerImage));
			}
			keys[EventKeyboard::KeyCode::KEY_A] = false;
		}

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	///////////////////////////////////////////////

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(MySecondScene::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(MySecondScene::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	///////////////////////////////////////////////

	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_W), 1 / 60);
	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_S), 1 / 60);
	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_A), 1 / 60);
	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D), 1 / 60);//�ܶ���ͼ

	scheduleUpdate();

	return true;
}



//��������


bool MyThirdScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	auto label1 = Label::createWithSystemFont("MAIN MENU", "fonts/arial.ttf", 15);
	label1->setColor(Color3B(0, 0, 0));
	label1->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MyThirdScene::EnterFirstScene, this));
	auto menu1 = Menu::create(menuitem1, NULL);
	menuitem1->setPosition(Vec2(0, 80));
	this->addChild(menu1);

	auto label2 = Label::create();
	label2->setString("START GAME");
	label2->setScale(3.0);
	label2->setColor(Color3B(0, 0, 0));
	label2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	//auto label2 = Label::createWithSystemFont("create new room there,click to return the main map", "fonts/arial.ttf", 30);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MyThirdScene::EnterSecondScene, this));
	auto menu2 = Menu::create(menuitem2, NULL);
	menuitem2->setPosition(Vec2(-60, 0));
	this->addChild(menu2);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	label3->setColor(Color3B(0, 0, 0));
	label3->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menu3 = Menu::create();
	//label->setPosition(Vec2(300, 175));
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(MyThirdScene::EXIT, this));
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	this->addChild(menu3);

	return true;
}

bool MyFifthScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	auto label1 = Label::createWithSystemFont("MAIN MENU", "fonts/arial.ttf", 15);
	label1->setColor(Color3B(0, 0, 0));
	label1->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MyFifthScene::EnterFirstScene, this));
	auto menu1 = Menu::create(menuitem1, NULL);
	menuitem1->setPosition(Vec2(0, 80));
	this->addChild(menu1);

	auto label2 = Label::create();
	label2->setString("START GAME");
	label2->setScale(3.0);
	label2->setColor(Color3B(0, 0, 0));
	label2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	//auto label2 = Label::createWithSystemFont("create new room there,click to return the main map", "fonts/arial.ttf", 30);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MyFifthScene::EnterSecondScene, this));
	auto menu2 = Menu::create(menuitem2, NULL);
	menuitem2->setPosition(Vec2(-60, 0));
	this->addChild(menu2);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	label3->setColor(Color3B(0, 0, 0));
	label3->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menu3 = Menu::create();
	//label->setPosition(Vec2(300, 175));
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(MyFifthScene::EXIT, this));
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	this->addChild(menu3);

	return true;
}


//������


bool MyForthScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);

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
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	this->addChild(menu3);

	return true;
}
