#include<string>
#include<AudioEngine.h>
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"
#include"TimeCounter.h"



//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene

//主地图
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
	/*联网下有多个人类玩家，所以monster绑定的是vector，这里创建一个只含一个元素的vector赋给m_player*/

	int humanPlayerAmount = 1;//加入房间的人类玩家数

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

	//取随机数种子
	srand((unsigned int)time(NULL));

	//背景
	initBG();
	initIF();
	initLABEL();
	 m_player->setPosition(Vec2(240, 160));
	this->addChild(m_player);

	//创建ai玩家
	for (int i = 0; i < PLAYER_AMOUNT - humanPlayerAmount; i++) {
		vecAIPlayer.push_back(AIPlayer::create());
		vecAIPlayer[i]->bindSprite(Sprite::create((cocos2d::StringUtils::format("%1dplayer.png", i % 9))));

		auto aiPlayerBody = PhysicsBody::createBox(vecAIPlayer[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		aiPlayerBody->setDynamic(false);
		aiPlayerBody->setContactTestBitmask(0xFFFFFFFF);
		vecAIPlayer[i]->setPhysicsBody(aiPlayerBody);
		vecAIPlayer[i]->setTag(AIPLAYER_TAG + i);
		mapAIPlayerTag.insert(std::pair<int, AIPlayer*>(AIPLAYER_TAG + i, vecAIPlayer[i]));
		vecAIPlayer[i]->SetNum(i);

		vecAIPlayer[i]->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));

		vecAIPlayer[i]->BindScene(this);
		vecAIPlayer[i]->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_bird1(i % 9));
		this->addChild(vecAIPlayer[i]);
	}

	//创建怪物
	for (int i = 0; i < MONSTER_AMOUNT; i++) {
		vecMonster.push_back(Monster::create());
		vecMonster[i]->bindSprite(Sprite::create("monster11.png"));
		vecMonster[i]->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_monster1());
		vecMonster[i]->retain();

		auto Body = PhysicsBody::createBox(vecMonster[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		vecMonster[i]->setPhysicsBody(Body);
		vecMonster[i]->setTag(MONSTER_TAG + i);
		mapMonsterTag.insert(std::pair<int, Monster*>(MONSTER_TAG + i, vecMonster[i]));

		vecMonster[i]->BindPlayers(vecPlayer); //绑定玩家
		vecMonster[i]->BindAIPlayers(vecAIPlayer); //绑定ai玩家
		vecMonster[i]->BindScene(this); //绑定场景
		vecMonster[i]->BindBackground(start_Page); //绑定背景

		vecMonster[i]->Reset(); //随机坐标
		this->addChild(vecMonster[i]);

	}


	//创建可达鸭
	duck = MonsterDuck::create();
	duck->bindSprite(Sprite::create("monster3.png"));

	auto Body = PhysicsBody::createBox(duck->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	Body->setDynamic(false);
	Body->setContactTestBitmask(0xFFFFFFFF);
	duck->setPhysicsBody(Body);
	duck->setTag(DUCK_TAG);

	duck->BindPlayers(vecPlayer); //绑定玩家
	duck->BindAIPlayers(vecAIPlayer); //绑定ai玩家
	duck->BindScene(this); //绑定场景
	duck->BindBackground(start_Page); //绑定背景

	duck->setPosition(start_Page->getContentSize().width / 2-60, start_Page->getContentSize().height / 2 - 60);
	duck->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_monsterDuck());
	this->addChild(duck);

	duck->SetMissiles();
	vecMissile = duck->GetMissiles();
	mapMissileTag = duck->GetMapMissile();

#if 0
	//创建耿鬼
	for (int i = 0; i < MONSTER_AMOUNT; i++) {
		vecGhost.push_back(Ghost::create());
		vecGhost[i]->bindSprite(Sprite::create("monster4.png"));
		vecGhost[i]->retain();

		auto Body = PhysicsBody::createBox(vecGhost[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		vecGhost[i]->setPhysicsBody(Body);
		vecGhost[i]->setTag(GHOST_TAG + i);
		mapGhostTag.insert(std::pair<int, Ghost*>(GHOST_TAG + i, vecGhost[i]));

		vecGhost[i]->BindPlayers(vecPlayer); //绑定玩家
		vecGhost[i]->BindAIPlayers(vecAIPlayer); //绑定ai玩家
		vecGhost[i]->BindBackground(start_Page); //绑定背景

		vecGhost[i]->Reset(); //随机坐标
		this->addChild(vecGhost[i]);

	}
#endif
	//ai玩家绑定怪物
	for (int i = 0; i < vecAIPlayer.size(); i++) {
		vecAIPlayer[i]->BindMonsters(vecMonster);
		//	vecAIPlayer[i]->BindGhosts(vecGhost);
	}
	/*********************************************************************/
	/*********************************************************************/


	// 定义触摸事件的监听器。监听器有两种：
   // 1.EventListenerTouchOneByOne：此类型对每个触摸事件调用一次回调方法。
   // 2.EventListenerTouchAllAtOnce：此类型对所有的触摸事件调用一次回调方法。
	auto eventListener = EventListenerTouchOneByOne::create();
	// 定义回调函数onTouchBegan():手指第一次碰到屏幕时被调用。
	eventListener->onTouchBegan = CC_CALLBACK_2(MySecondScene::onTouchBegan, this);
	// 使用EventDispatcher来处理各种各样的事件，如触摸和其他键盘事件。
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;

	//键盘监听
	auto listener = EventListenerKeyboard::create();
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

		}//对应键盘操作播放或停止不同的精灵帧
		if (keyCode == EventKeyboard::KeyCode::KEY_ALT) {
			//想写翻转 但缺少素材
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_X) {//治疗键
			if (Pill != nullptr) {
				m_player->AddHP();
				m_player->alter_blood(m_blood);
				Pill->removeFromParentAndCleanup(true);
				Pill = nullptr;
			}
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_1) {
			//切换武器
			if (Gun1 != nullptr) {
				guntype = 2;
				bagblock3->initWithFile("bagblock.png");
				bagblock1->initWithFile("bagblock_ing.png");
			}
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_2) {
			//切换武器
			if (Gun2 != nullptr) {
				guntype = 1;
				bagblock1->initWithFile("bagblock.png");
				bagblock3->initWithFile("bagblock_ing.png");
			}
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
	this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D), 1 / 60);//跑动地图

	scheduleUpdate();

	return true;
}
// NinjaAttack_Level1.h




//创建房间


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
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
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
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu3);

	return true;
}

//碰撞开始
bool MySecondScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
	//取碰撞二者
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB) {
		auto tagA = nodeA->getTag();
		auto tagB = nodeB->getTag();
		//怪物子弹和ai玩家
		if (MONSTER_BULLET_TAG == tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->isHit();
			}
		}
		else if (MONSTER_BULLET_TAG == tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->isHit();
			}
		}
		//怪物子弹和玩家
		else if (MONSTER_BULLET_TAG == tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				iter->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
		else if (MONSTER_BULLET_TAG == tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				iter->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
		if (MISSILE_TAG <= tagA && MISSILE_TAG + PLAYER_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapMissileTag.find(tagA);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapAIPlayerTag.find(tagB);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
				iter2->second->isHit();
			}
		}
		else if (MISSILE_TAG <= tagB && MISSILE_TAG + PLAYER_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapMissileTag.find(tagB);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapAIPlayerTag.find(tagA);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
				iter2->second->isHit();
			}
		}
		//追踪弹和玩家
		else if (MISSILE_TAG <= tagA && MISSILE_TAG + PLAYER_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapMissileTag.find(tagA);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapPlayerTag.find(tagB);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
		else if (MISSILE_TAG <= tagB && MISSILE_TAG + PLAYER_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapMissileTag.find(tagB);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapPlayerTag.find(tagA);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
#if 0
		//耿鬼和ai玩家
		if (GHOST_TAG <= tagA && GHOST_TAG + GHOST_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapGhostTag.find(tagA);
			if (iter != mapGhostTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapAIPlayerTag.find(tagB);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
			}
		}
		else if (GHOST_TAG <= tagB && GHOST_TAG + GHOST_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapGhostTag.find(tagB);
			if (iter != mapGhostTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapAIPlayerTag.find(tagA);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
			}
		}
		//耿鬼和玩家
		else if (GHOST_TAG <= tagA && GHOST_TAG + GHOST_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapGhostTag.find(tagA);
			if (iter != mapGhostTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapPlayerTag.find(tagB);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
		else if (GHOST_TAG <= tagB && GHOST_TAG + GHOST_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapGhostTag.find(tagB);
			if (iter != mapGhostTag.end()) {
				iter->second->Reset();
			}
			auto iter2 = mapPlayerTag.find(tagA);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
#endif
		//ai玩家子弹和怪物
		else if (AIPLAYER_BULLET_TAG <= tagA && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter1 = mapAIPlayerTag.find(AIPLAYER_TAG + tagA - AIPLAYER_BULLET_TAG); //ai得分
			if (iter1 != mapAIPlayerTag.end()) {
				iter1->second->GetScore();
			}
			auto iter2 = mapMonsterTag.find(tagB); //怪物掉血
			if (iter2 != mapMonsterTag.end()) {
				iter2->second->isHit();
			}
		}
		else if (AIPLAYER_BULLET_TAG <= tagB && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter1 = mapAIPlayerTag.find(AIPLAYER_TAG + tagB - AIPLAYER_BULLET_TAG); //ai得分
			if (iter1 != mapAIPlayerTag.end()) {
				iter1->second->GetScore();
			}
			auto iter2 = mapMonsterTag.find(tagA); //怪物掉血
			if (iter2 != mapMonsterTag.end()) {
				iter2->second->isHit();
			}
		}
		//玩家子弹和怪物
		else if (PLAYER_BULLET_TAG == tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter = mapMonsterTag.find(tagB);
			if (iter != mapMonsterTag.end()) {
				iter->second->isHit();
			}
			m_player->GetScore();
			m_player->printScore(Score);
		}
		else if (PLAYER_BULLET_TAG == tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter = mapMonsterTag.find(tagA);
			if (iter != mapMonsterTag.end()) {
				iter->second->isHit();
			}
			m_player->GetScore();
			m_player->printScore(Score);
		}
		//玩家子弹和可达鸭
		else if (PLAYER_BULLET_TAG == tagA && DUCK_TAG == tagB) {
			nodeA->removeFromParentAndCleanup(true);
			duck->isHit();
			m_player->GetScore();
			m_player->printScore(Score);
		}
		else if (PLAYER_BULLET_TAG == tagB && DUCK_TAG == tagA) {
			nodeB->removeFromParentAndCleanup(true);
			duck->isHit();
			m_player->GetScore();
			m_player->printScore(Score);
		}
#if 0
		//玩家子弹和耿鬼
		else if (PLAYER_BULLET_TAG == tagA && GHOST_TAG <= tagB && GHOST_TAG + GHOST_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter = mapGhostTag.find(tagB);
			if (iter != mapGhostTag.end()) {
				iter->second->isHit();
			}
			m_player->GetScore();
			m_player->printScore(Score);
		}
		else if (PLAYER_BULLET_TAG == tagB && GHOST_TAG <= tagA && GHOST_TAG + GHOST_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter = mapGhostTag.find(tagA);
			if (iter != mapGhostTag.end()) {
				iter->second->isHit();
			}
			m_player->GetScore();
			m_player->printScore(Score);
		}
#endif
		//怪物子弹和箱子
		else if (MONSTER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (MONSTER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//ai玩家子弹和箱子
		else if (AIPLAYER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (AIPLAYER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//玩家子弹和箱子
		else if (PLAYER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (PLAYER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//怪物和箱子
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			auto iter = mapMonsterTag.find(tagB);
			if (iter != mapMonsterTag.end()) {
				if (nodeB->getPositionY() <= nodeA->getPositionY() - (nodeA->getContentSize().height / 2) || nodeB->getPositionY() >= nodeA->getPositionY() + (nodeA->getContentSize().height / 2)-4) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(1);
				}
				if (nodeB->getPositionX() <= nodeA->getPositionX() - (nodeA->getContentSize().width / 2) || nodeB->getPositionX() >= nodeA->getPositionX() + (nodeA->getContentSize().width / 2)-5) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(0);
				}

			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			auto iter = mapMonsterTag.find(tagA);
			if (iter != mapMonsterTag.end()) {
				if (nodeA->getPositionY() <= nodeB->getPositionY() - (nodeB->getContentSize().height / 2) || nodeA->getPositionY() >= nodeB->getPositionY() + (nodeB->getContentSize().height / 2)-4) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(1);
				}
				if (nodeA->getPositionX() <= nodeB->getPositionX() - (nodeB->getContentSize().width / 2) || nodeA->getPositionX() >= nodeB->getPositionX() + (nodeB->getContentSize().width / 2)-5) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(0);
				}
				
			}
		}
		//ai玩家和箱子
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				if (nodeB->getPositionY() <= nodeA->getPositionY() - (nodeA->getContentSize().height / 2) || nodeB->getPositionY() >= nodeA->getPositionY() + (nodeA->getContentSize().height / 2) - 4) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(1);
				}
				if (nodeB->getPositionX() <= nodeA->getPositionX() - (nodeA->getContentSize().width / 2) || nodeB->getPositionX() >= nodeA->getPositionX() + (nodeA->getContentSize().width / 2) - 5) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(0);
				}
			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				if (nodeA->getPositionY() <= nodeB->getPositionY() - (nodeB->getContentSize().height / 2) || nodeA->getPositionY() >= nodeB->getPositionY() + (nodeB->getContentSize().height / 2) - 4) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(1);
				}
				if (nodeA->getPositionX() <= nodeB->getPositionX() - (nodeB->getContentSize().width / 2) || nodeA->getPositionX() >= nodeB->getPositionX() + (nodeB->getContentSize().width / 2) - 5) {
					iter->second->Stop(true);
					iter->second->Avoid_brick(0);
				}
			}
		}
		//玩家与箱子/边界
		else if ((tagA == BORDER_TAG || BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			if (nodeB->getPositionY() <= nodeA->getPositionY() - (nodeA->getContentSize().height / 2)) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_W));
			}
			if (nodeB->getPositionY() >= nodeA->getPositionY() + (nodeA->getContentSize().height / 2) - 4) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_S));
			}
			if (nodeB->getPositionX() <= nodeA->getPositionX() - (nodeA->getContentSize().width / 2)) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D));
			}
			if (nodeB->getPositionX() >= nodeA->getPositionX() + (nodeA->getContentSize().width / 2) - 5) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_A));
			}
		}
		else  if ((tagB == BORDER_TAG || BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			if (nodeA->getPositionY() >= nodeB->getPositionY() + (nodeB->getContentSize().height / 2) - 4) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_S));
			}
			if (nodeA->getPositionY() <= nodeB->getPositionY() - (nodeB->getContentSize().height / 2)) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_W));
			}
			if (nodeA->getPositionX() <= nodeB->getPositionX() - (nodeB->getContentSize().width / 2)) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D));
			}
			if (nodeA->getPositionX() >= nodeB->getPositionX() + (nodeB->getContentSize().width / 2) - 5) {
				this->unschedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_A));
			}
		}
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeB->setVisible(false);
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeA->setVisible(false);
		}
		else if (GUN1_TAG <= tagA && GUN1_TAG + GUN1_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			if (Gun1 == nullptr) {
				Gun1 = Sprite::create("gun1.png");
				Gun1->setPosition(400, 20);
				nodeA->removeFromParentAndCleanup(true);
				this->addChild(Gun1);
			}
		}
		else if (GUN1_TAG <= tagB && GUN1_TAG + GUN1_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			if (Gun1 == nullptr) {
				Gun1 = Sprite::create("gun1.png");
				Gun1->setPosition(400, 20);
				nodeB->removeFromParentAndCleanup(true);
				this->addChild(Gun1);
			}
		}
		else if (GUN2_TAG <= tagA && GUN2_TAG + GUN2_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			if (Gun2 == nullptr) {
				Gun2 = Sprite::create("gun2.png");
				Gun2->setPosition(430, 20);
				nodeA->removeFromParentAndCleanup(true);
				this->addChild(Gun2);
			}
		}
		else if (GUN2_TAG <= tagB && GUN2_TAG + GUN2_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			if (Gun2 == nullptr) {
				Gun2 = Sprite::create("gun2.png");
				Gun2->setPosition(430, 20);
				nodeB->removeFromParentAndCleanup(true);
				this->addChild(Gun2);
			}
		}
		else if (PILL_TAG <= tagA && PILL_TAG + PILL_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			if (Pill == nullptr) {
				Pill = Sprite::create("pill.png");
				Pill->setPosition(370, 20);
				nodeA->removeFromParentAndCleanup(true);
				this->addChild(Pill);
			}
		}
		else if (PILL_TAG <= tagB && PILL_TAG + PILL_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			if (Pill == nullptr) {
				Pill = Sprite::create("pill.png");
				Pill->setPosition(370, 20);
				nodeB->removeFromParentAndCleanup(true);
				this->addChild(Pill);
			}
		}
		else if (BULLET1_TAG <= tagA && BULLET1_TAG + BULLET1_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
		if(m_player)
			nodeA->removeFromParentAndCleanup(true);
			m_player->gain_bullet1();
			m_player->print_rest_bullet1(BULLET1);
		}
		else if (BULLET1_TAG <= tagB && BULLET1_TAG + BULLET1_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			m_player->gain_bullet1();
			m_player->print_rest_bullet1(BULLET1);
		}
		else if (BULLET2_TAG <= tagA && BULLET2_TAG + BULLET2_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			m_player->gain_bullet2();
			m_player->print_rest_bullet2(BULLET2);
		}
		else if (BULLET2_TAG <= tagB && BULLET2_TAG + BULLET2_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			m_player->gain_bullet2();
			m_player->print_rest_bullet2(BULLET2);
		}

	}

	return true;
}

bool MySecondScene::onContactSeparate(cocos2d::PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB) {
		auto tagA = nodeA->getTag();
		auto tagB = nodeB->getTag();
		if ((tagA == BORDER_TAG || BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			if (nodeB->getPositionY() <= nodeA->getPositionY() - (nodeA->getContentSize().height / 2)) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_W));
			}
			if (nodeB->getPositionY() >= nodeA->getPositionY() + (nodeA->getContentSize().height / 2) - 4) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_S));
			}
			if (nodeB->getPositionX() <= nodeA->getPositionX() - (nodeA->getContentSize().width / 2)) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D));
			}
			if (nodeB->getPositionX() >= nodeA->getPositionX() + (nodeA->getContentSize().width / 2) - 5) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_A));
			}
		}
		else if ((tagB == BORDER_TAG || BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			if (nodeA->getPositionY() <= nodeB->getPositionY() - (nodeB->getContentSize().height / 2)) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_W));
			}
			if (nodeA->getPositionY() >= nodeB->getPositionY() + (nodeB->getContentSize().height / 2) - 4) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_S));
			}
			if (nodeA->getPositionX() <= nodeB->getPositionX() - (nodeB->getContentSize().width / 2)) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_D));
			}
			if (nodeA->getPositionX() >= nodeB->getPositionX() + (nodeB->getContentSize().width / 2) - 5) {
				this->schedule(CC_SCHEDULE_SELECTOR(MySecondScene::update_A));
			}
		}
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeB->setVisible(true);
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeA->setVisible(true);
		}
		//怪物和箱子
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			auto iter = mapMonsterTag.find(tagB);
			if (iter != mapMonsterTag.end()) {
				iter->second->Stop(false);
			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			auto iter = mapMonsterTag.find(tagA);
			if (iter != mapMonsterTag.end()) {
				iter->second->Stop(false);
			}
		}
		//ai玩家和箱子
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->Stop(false);
			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->Stop(false);
			}
		}
	}

	return false;
}