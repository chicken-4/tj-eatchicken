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
		vecPlayer[i]->bindSprite(Sprite::create("11.png"));

		auto playerBody = PhysicsBody::createBox(vecPlayer[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		playerBody->setDynamic(false);
		playerBody->setContactTestBitmask(0xFFFFFFFF);
		vecPlayer[i]->setPhysicsBody(playerBody);
		vecPlayer[i]->setTag(PLAYER_TAG + i);
		mapPlayerTag.insert(std::pair<int, Player*>(PLAYER_TAG + i, vecPlayer[i]));
	}
	m_player = vecPlayer[0];

	Size VisibleSize = Director::getInstance()->getVisibleSize();

	initBG();
	initIF();
	initLABEL();
	m_player->setPosition(Vec2(240, 160));
	this->addChild(m_player);


	///////////////////////////////////////////////////////////////////

	//���λ��
	srand((unsigned)time(NULL));
	float minX, minY, maxX, maxY, randomX, randomY;
	//����ai���
	for (int i = 0; i < PLAYER_AMOUNT - humanPlayerAmount; i++) {
		vecAIPlayer.push_back(AIPlayer::create());
		vecAIPlayer[i]->bindSprite(Sprite::create("niko.png"));

		auto aiPlayerBody = PhysicsBody::createBox(vecAIPlayer[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		aiPlayerBody->setDynamic(false);
		aiPlayerBody->setContactTestBitmask(0xFFFFFFFF);
		vecAIPlayer[i]->setPhysicsBody(aiPlayerBody);
		vecAIPlayer[i]->setTag(AIPLAYER_TAG + i);
		mapAIPlayerTag.insert(std::pair<int, AIPlayer*>(AIPLAYER_TAG + i, vecAIPlayer[i]));

		//minX = vecAIPlayer[i]->getContentSize().width, minY = vecAIPlayer[i]->getContentSize().height;
		//maxX = start_Page->getContentSize().width - minX, maxY = start_Page->getContentSize().height - minY;
		//randomX = (rand() % static_cast<int>(maxX - minX)) + rand() / static_cast<float>(maxX) + minX;
		//randomY = (rand() % static_cast<int>(maxY - minY)) + rand() / static_cast<float>(maxY) + minY;
		vecAIPlayer[i]->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));

		vecAIPlayer[i]->BindScene(this);
		this->addChild(vecAIPlayer[i]);
	}

	//��������
	for (int i = 0; i < MONSTER_AMOUNT; i++) {
		vecMonster.push_back(Monster::create());
		vecMonster[i]->bindSprite(Sprite::create("5.png"));

		auto Body = PhysicsBody::createBox(vecMonster[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		vecMonster[i]->setPhysicsBody(Body);
		vecMonster[i]->setTag(MONSTER_TAG + i);
		mapMonsterTag.insert(std::pair<int, Monster*>(MONSTER_TAG + i, vecMonster[i]));

		vecMonster[i]->BindPlayers(vecPlayer); //�����
		vecMonster[i]->BindAIPlayers(vecAIPlayer); //��ai���
		vecMonster[i]->BindScene(this); //�󶨳���
		vecMonster[i]->BindBackground(start_Page); //�󶨱���

		vecMonster[i]->Reset(); //�������
		this->addChild(vecMonster[i]);

	}

	//ai��Ұ󶨹���
	for (int i = 0; i < vecAIPlayer.size(); i++) {
		vecAIPlayer[i]->BindMonsters(vecMonster);
	}


	/*********************************************************************/


	// ���崥���¼��ļ������������������֣�
   // 1.EventListenerTouchOneByOne�������Ͷ�ÿ�������¼�����һ�λص�������
   // 2.EventListenerTouchAllAtOnce�������Ͷ����еĴ����¼�����һ�λص�������
	auto eventListener = EventListenerTouchOneByOne::create();
	// ����ص�����onTouchBegan():��ָ��һ��������Ļʱ�����á�
	eventListener->onTouchBegan = CC_CALLBACK_2(MySecondScene::onTouchBegan, this);
	// ʹ��EventDispatcher��������ָ������¼����紥�������������¼���
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;


	//���̼���
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_2());
			keys[EventKeyboard::KeyCode::KEY_W] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_1());
			keys[EventKeyboard::KeyCode::KEY_S] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_3());
			keys[EventKeyboard::KeyCode::KEY_D] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			m_player->getSprite()->stopAllActions();
			m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_4());
			keys[EventKeyboard::KeyCode::KEY_A] = true;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
			auto jump = JumpTo::create(0.4, Vec2(m_player->getPositionX(), m_player->getPositionY()), 20, 1);
			m_player->runAction(jump);
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_ALT) {

		}//��Ӧ���̲������Ż�ֹͣ��ͬ�ľ���֡
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_1());
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_4());
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_3());
			}
			keys[EventKeyboard::KeyCode::KEY_W] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_2());
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_4());
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_3());
			}
			keys[EventKeyboard::KeyCode::KEY_S] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_2());
			}
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_1());
			}
			if (keys[EventKeyboard::KeyCode::KEY_A] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_4());
			}
			keys[EventKeyboard::KeyCode::KEY_D] = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			m_player->getSprite()->stopAllActions();
			if (keys[EventKeyboard::KeyCode::KEY_W] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_2());
			}
			if (keys[EventKeyboard::KeyCode::KEY_S] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_1());
			}
			if (keys[EventKeyboard::KeyCode::KEY_D] == true) {
				m_player->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_3());
			}
			keys[EventKeyboard::KeyCode::KEY_A] = false;
		}
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
// NinjaAttack_Level1.h




//��������


bool MyThirdScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	start_Page = Sprite::create("big2xx.png");
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
	//�������˲˵���Ŀ������Ҫ����˵��У�����������Ǵ����˵�
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//�Ѳ˵���ӵ�MyFirstScene����
	this->addChild(menu3);

	return true;
}

bool MyFifthScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	start_Page = Sprite::create("big2xx.png");
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
	//�������˲˵���Ŀ������Ҫ����˵��У�����������Ǵ����˵�
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//�Ѳ˵���ӵ�MyFirstScene����
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

	start_Page = Sprite::create("big2xx.png");
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
	//�������˲˵���Ŀ������Ҫ����˵��У�����������Ǵ����˵�
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//�Ѳ˵���ӵ�MyFirstScene����
	this->addChild(menu3);

	return true;
}

//��ײ��ʼ
bool MySecondScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
	//ȡ��ײ����
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB) {
		auto tagA = nodeA->getTag();
		auto tagB = nodeB->getTag();
		//�����ӵ���ai���
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
		//�����ӵ������
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
		//ai����ӵ��͹���
		else if (AIPLAYER_BULLET_TAG <= tagA && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			auto iter1 = mapAIPlayerTag.find(AIPLAYER_TAG + tagA - AIPLAYER_BULLET_TAG); //ai�÷�
			if (iter1 != mapAIPlayerTag.end()) {
				iter1->second->GetScore();
			}
			auto iter2 = mapMonsterTag.find(tagB); //�����Ѫ
			if (iter2 != mapMonsterTag.end()) {
				iter2->second->isHit();
			}
		}
		else if (AIPLAYER_BULLET_TAG <= tagB && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			auto iter1 = mapAIPlayerTag.find(AIPLAYER_TAG + tagB - AIPLAYER_BULLET_TAG); //ai�÷�
			if (iter1 != mapAIPlayerTag.end()) {
				iter1->second->GetScore();
			}
			auto iter2 = mapMonsterTag.find(tagA); //�����Ѫ
			if (iter2 != mapMonsterTag.end()) {
				iter2->second->isHit();
			}
		}
		//����ӵ��͹���
		else if (PLAYER_BULLET_TAG == tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);

			//��֪��Ϊʲô�򲻵��֣������߼���ai��һģһ��
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
		//�����ӵ�������
		else if (MONSTER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (MONSTER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//ai����ӵ�������
		else if (AIPLAYER_BULLET_TAG <= tagA && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (AIPLAYER_BULLET_TAG <= tagB && AIPLAYER_BULLET_TAG + PLAYER_AMOUNT > tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//����ӵ�������
		else if (PLAYER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (PLAYER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//���������
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && MONSTER_TAG <= tagB && MONSTER_TAG + MONSTER_AMOUNT > tagB) {
			auto iter = mapMonsterTag.find(tagB);
			if (iter != mapMonsterTag.end()) {
				//	iter->second->Wait();
			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			auto iter = mapMonsterTag.find(tagA);
			if (iter != mapMonsterTag.end()) {
				iter->second->Wait();
			}
		}
		//ai��Һ�����
		else if (BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				//	iter->second->Wait();
			}
		}
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->Wait();
			}
		}
		//���������/�߽�
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

	}

	return false;
}
