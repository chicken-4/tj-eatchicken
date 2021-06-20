#include<AudioEngine.h>
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"
#include"TimeCounter.h"

//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene

//主地图
Scene* MySecondScene::createScene(int i)
{
	Scene* scene = Scene::createWithPhysics();
	MySecondScene* layer = MySecondScene::create();
	scene->addChild(layer);

	return scene;
}

void MySecondScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	PhysicsBody* body = NULL;

	//大地图


	//边界
	border1 = Sprite::create("border.png");
	border1->setAnchorPoint(Vec2(0, 0));
	border1->setPosition(0, -5);
	auto physicsBody_border = PhysicsBody::createBox(border1->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border->setDynamic(false);
	physicsBody_border->setContactTestBitmask(0xFFFFFFFF);
	border1->setPhysicsBody(physicsBody_border);
	border1->setTag(BORDER_TAG);
	this->addChild(border1);

	border2 = Sprite::create("border2.png");
	border2->setAnchorPoint(Vec2(0, 0));
	border2->setPosition(40, 0);
	auto physicsBody_border2 = PhysicsBody::createBox(border2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border2->setDynamic(false);
	physicsBody_border2->setContactTestBitmask(0xFFFFFFFF);
	border2->setPhysicsBody(physicsBody_border2);
	border2->setTag(BORDER_TAG);
	this->addChild(border2);

	border3 = Sprite::create("border2.png");
	border3->setAnchorPoint(Vec2(0, 0));
	border3->setPosition(3250, 0);
	auto physicsBody_border3 = PhysicsBody::createBox(border3->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border3->setDynamic(false);
	physicsBody_border3->setContactTestBitmask(0xFFFFFFFF);
	border3->setPhysicsBody(physicsBody_border3);
	border3->setTag(BORDER_TAG);
	this->addChild(border3);

	border4 = Sprite::create("border.png");
	border4->setAnchorPoint(Vec2(0, 0));
	border4->setPosition(0, 3230);
	auto physicsBody_border4 = PhysicsBody::createBox(border4->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border4->setDynamic(false);
	physicsBody_border4->setContactTestBitmask(0xFFFFFFFF);
	border4->setPhysicsBody(physicsBody_border4);
	border4->setTag(BORDER_TAG);
	this->addChild(border4);

	river1 = Sprite::create("border.png");
	river1->setAnchorPoint(Vec2(0, 0));
	river1->setPosition(0, 1613);
	auto physicsBody_river1 = PhysicsBody::createBox(river1->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_river1->setDynamic(false);
	physicsBody_river1->setContactTestBitmask(0xFFFFFFFF);
	river1->setPhysicsBody(physicsBody_river1);
	river1->setTag(RIVER_TAG);
	this->addChild(river1);

	river2 = Sprite::create("border2.png");
	river2->setAnchorPoint(Vec2(0, 0));
	river2->setPosition(1645, 0);
	auto physicsBody_river2 = PhysicsBody::createBox(river2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_river2->setDynamic(false);
	physicsBody_river2->setContactTestBitmask(0xFFFFFFFF);
	river2->setPhysicsBody(physicsBody_river2);
	river2->setTag(RIVER_TAG);
	this->addChild(river2);
	
	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(start_Page->getContentSize().width / 2 + 25, start_Page->getContentSize().height / 2);

	lake = Sprite::create("lake.png");
	lake->setPosition(start_Page->getContentSize().width / 2 + 25, start_Page->getContentSize().height / 2);
	auto physicsBody_lake = PhysicsBody::createBox(lake->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_lake->setDynamic(false);
	physicsBody_lake->setContactTestBitmask(0xFFFFFFFF);
	lake->setPhysicsBody(physicsBody_lake);
	lake->setTag(RIVER_TAG);
	this->addChild(lake);
	
	this->addChild(start_Page);

	srand((unsigned int)time(NULL));
	//石头
	brick = SpriteBatchNode::create("bocket.png");

	for (int i = 0; i < BRICK_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("bocket.png");
		if (i >= 0 && i < 100) {
            sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width/2-300) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height/2 - 200) + 100));
		}
		else if (i >= 100 && i < 200) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 -300) + 300+ start_Page->getContentSize().width / 2, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100+start_Page->getContentSize().height / 2));
		}
		else if (i >= 200 && i < 300) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 300 + start_Page->getContentSize().width / 2, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100));
		}
		else if (i >= 300 && i < BRICK_AMOUNT) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100 + start_Page->getContentSize().height / 2));
		}
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(BRICK_TAG + i);
		brick->addChild(sprite);
	}
	this->addChild(brick);
	//brick->setVisible(false);

	gress = SpriteBatchNode::create("gress.png");
	for (int i = 0; i < GRASS_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("gress.png");
		if (i >= 0 && i < 50) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100));
		}
		else if (i >= 50 && i < 100) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 300 + start_Page->getContentSize().width / 2, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100 + start_Page->getContentSize().height / 2));
		}
		else if (i >= 100 && i < 150) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 300 + start_Page->getContentSize().width / 2, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100));
		}
		else if (i >= 150 && i < GRASS_AMOUNT) {
			sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width / 2 - 300) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height / 2 - 200) + 100 + start_Page->getContentSize().height / 2));
		}
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(GRASS_TAG + i);
		gress->addChild(sprite);
	}
	this->addChild(gress);
	//gress->setVisible(false);

	/*box = Sprite::create("bocket.png");
	box->setPosition(Vec2(227, 260));
	box->setTag(50);
	this->addChild(box);

	tree = Sprite::create("cao.png");
	tree->setPosition(Vec2(315, 380));
	tree->setTag(50);
	this->addChild(tree);*/
	gun1 = SpriteBatchNode::create("gun1.png");
	for (int i = 0; i < GUN1_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("gun1.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(GUN1_TAG + i);
		gun1->addChild(sprite);
	}
	this->addChild(gun1);


	gun2 = SpriteBatchNode::create("gun2.png");
	for (int i = 0; i < GUN2_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("gun2.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(GUN2_TAG + i);
		gun2->addChild(sprite);
	}
	this->addChild(gun2);

	pill = SpriteBatchNode::create("pill.png");
	for (int i = 0; i < PILL_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("pill.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(PILL_TAG + i);
		pill->addChild(sprite);
	}
	this->addChild(pill);

	bullet1 = SpriteBatchNode::create("bullet11.png");
	for (int i = 0; i < BULLET1_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("bullet11.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(BULLET1_TAG + i);
		bullet1->addChild(sprite);
	}
	this->addChild(bullet1);

	bullet2 = SpriteBatchNode::create("bullet22.png");
	for (int i = 0; i < BULLET1_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("bullet22.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(BULLET2_TAG + i);
		bullet2->addChild(sprite);
	}
	this->addChild(bullet2);

	addSomething = SpriteBatchNode::create("speed.png");
	for (int i = 0; i < SPEED_AMOUNT+BULLET1LIMIT_AMOUNT+BULLET2LIMIT_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("speed.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		body->setDynamic(false);
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);
		sprite->setTag(SPEED_TAG + i);
		sprite->setScale(0.6);
		addSomething->addChild(sprite);
	}
	this->addChild(addSomething);

	bagblock1 = Sprite::create("bagblock.png");
	bagblock1->setPosition(400, 20);
	this->addChild(bagblock1);

	bagblock2 = Sprite::create("bagblock.png");
	bagblock2->setPosition(370, 20);
	this->addChild(bagblock2);

	bagblock3 = Sprite::create("bagblock.png");
	bagblock3->setPosition(430, 20);
	this->addChild(bagblock3);

	BULLET1 = Label::create();
	BULLET1->setPosition(Vec2(405, 40));
	BULLET1->setString("0/30");
	BULLET1->setScale(0.8);
	BULLET1->setColor(Color3B(0, 0, 0));
	this->addChild(BULLET1);

	BULLET2 = Label::create();
	BULLET2->setPosition(Vec2(435, 40));
	BULLET2->setString("0/30");
	BULLET2->setScale(0.8);
	BULLET2->setColor(Color3B(0, 0, 0));
	this->addChild(BULLET2);
}

void MySecondScene::initIF()
{
	//小地图
	Small_map = Sprite::create("big2.png");
	Small_map->setPosition(453 - Small_map->getContentSize().width / 2, 320 - Small_map->getContentSize().height / 2);
	Small_map->setOpacity(120);
	this->addChild(Small_map );

	//小地图坐标
	ball = Sprite::create("ball.png");
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	ball->setOpacity(100);
	this->addChild(ball );

	//血条
	m_blood = Sprite::create("blood.png");
	m_blood->setPosition(Vec2(110, 300));
	m_blood->setScale(1, 1);
	m_blood->setAnchorPoint(Vec2(0, 0.5));
	m_blood->setColor(Color3B(0,220,0));
	this->addChild(m_blood);

	//血条分隔线
	bloodout = Sprite::create("bloodout.png");
	bloodout->setPosition(Vec2(110, 300));
	bloodout->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(bloodout);

	auto black1 = Sprite::create("black.png");
	black1->setPosition(453 - black1->getContentSize().width / 2, 320 - black1->getContentSize().height / 2);
	black1->setOpacity(80);
	this->addChild(black1);

	//血条标签
	blood_label = Label::create();
	blood_label->setString("Blood Volume");
	blood_label->setColor(Color3B(0, 0, 0));
	blood_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	blood_label->setPosition(Vec2(75, 300));
	this->addChild(blood_label);

	score_label = Label::create();
	score_label->setString("Your Score");
	score_label->setColor(Color3B(0, 0, 0));
	score_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	score_label->setPosition(Vec2(75, 270));
	this->addChild(score_label);

	speed_label = Label::create();
	speed_label->setString("Your Speed");
	speed_label->setColor(Color3B(0, 0, 0));
	speed_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	speed_label->setPosition(Vec2(75, 240));
	this->addChild(speed_label);

	time_label = Label::create();
	time_label->setString("Time:");
	time_label->setColor(Color3B(0, 0, 0));
	time_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	time_label->setPosition(Vec2(260, 300));
	this->addChild(time_label);

	//倒计时
	Clock*timing = Clock::create();
	timing->BindLabel(Label::create());
	timing->setScale(1);
	timing->setColor(Color3B(0, 0, 0));
	timing->setPosition(Vec2(290, 298));
	this->addChild(timing);

	Score = Label::create();
	Score->setPosition(Vec2(115, 270));
	Score->setString("0");
	Score->setColor(Color3B(0, 0, 0));
	this->addChild(Score);

	SPEED = Label::create();
	SPEED->setPosition(Vec2(115, 240));
	SPEED->setString("1.3");
	SPEED->setColor(Color3B(0, 0, 0));
	this->addChild(SPEED);
}

void MySecondScene::initLABEL()
{
	/*auto label1 = Label::create();
	auto menu1 = Menu::create();
	label1->setString("this is main map,click to check the final rank");
	//label1->setPosition(Vec2(0, 50));
	//auto label = Label::createWithSystemFont("this is main map，click to check the final rank", "fonts/arial.ttf", 30);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MySecondScene::EnterForthScene, this));
	menuitem1->setPosition(Vec2(0, 100));
	menu1->addChild(menuitem1);
	this->addChild(menu1);*/



	auto label2 = Label::create();
	label2->setString("Exit");
	auto menu2 = Menu::create();
	label2->setColor(Color3B(0, 0, 0));
	label2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MySecondScene::EXIT, this));
	menuitem2->setPosition(Vec2(160, -100));
	menu2->addChild(menuitem2);
	this->addChild(menu2);

}

void MySecondScene::EXIT(Ref* pSender)
{
	//点击退出
	Director::getInstance()->end();
}

void MySecondScene::EnterForthScene(Ref* pSender)
{
	//跳转到最终结算
	Director::getInstance()->replaceScene(MyForthScene::createScene());
}

void MySecondScene::update(float delta)
{
	if (circle1 != nullptr) {
		if (m_player->getPositionX() > circle1->getPositionX() + circle1->getContentSize().width / 2 || m_player->getPositionX() < circle1->getPositionX() - circle1->getContentSize().width / 2 || m_player->getPositionY() < circle1->getPositionY() - circle1->getContentSize().height / 2 || m_player->getPositionY() > circle1->getPositionY() + circle1->getContentSize().height / 2) {
			m_player->isOutOfCircle();
			m_player->alter_blood(m_blood);
		}
	}
	if (circle2 != nullptr) {
		if (m_player->getPositionX() > circle2->getPositionX() + circle2->getContentSize().width / 2 || m_player->getPositionX() < circle2->getPositionX() - circle2->getContentSize().width / 2 || m_player->getPositionY() < circle2->getPositionY() - circle2->getContentSize().height / 2 || m_player->getPositionY() > circle2->getPositionY() + circle2->getContentSize().height / 2) {
			m_player->isOutOfCircle();
			m_player->alter_blood(m_blood);
		}
	}
	if (m_player->isDead() && !hasDead) {
		hasDead = true;
		Sprite* back = Sprite::create("startpage.png");

		addChild(back, 10);
		back->setPosition(Vec2(0, 0)); ////

		auto choice = MenuItemFont::create("OK", [=](Ref* render) {
			Director::getInstance()->popScene();
			});
		auto menu = Menu::create();
		menu->addChild(choice);
		menu->setPosition(240, 30);
		addChild(menu, 20);

		auto text = Label::createWithTTF("Game over", "fonts/Marker Felt.ttf", 70);
		text->setPosition(Vec2(240, 280)); /// 
		addChild(text, 30);

		for (int i = 0; i < PLAYER_AMOUNT - 1; ++i) {
			auto playerLabel = Label::createWithTTF(StringUtils::format("player%d", i) + StringUtils::format("     %d", vecAIPlayer[i]->queryscore()), "fonts/Marker Felt.ttf", 20);
			playerLabel->setPosition(240, 60 + 20 * i);
			auto playerimage = Sprite::create((cocos2d::StringUtils::format("%1dplayer.png", i % 9)));
			playerimage->setPosition(150, 60 + 20 * i);
			addChild(playerLabel, 30);
			addChild(playerimage, 30);
		}
		auto playerLabel = Label::createWithTTF("me" + StringUtils::format("     %d", m_player->queryscore()), "fonts/Marker Felt.ttf", 20);
		playerLabel->setPosition(240, 40 + 20 * 10);
		auto m_image = Sprite::create((cocos2d::StringUtils::format("%1dplayer.png", m_PlayerImage % 9)));
		m_image->setPosition(150, 40 + 20 * 10);
		addChild(playerLabel, 30);
		addChild(m_image, 30);

	}
	Node::update(delta);

}


void MySecondScene::update_W(float delta)
{
	Node::update(delta);

	if (keys[EventKeyboard::KeyCode::KEY_W]) {
		keyPressedDuration_W();
	}
}
void MySecondScene::update_S(float delta)
{
	Node::update(delta);

	if (keys[EventKeyboard::KeyCode::KEY_S]) {
		keyPressedDuration_S();
	}
}
void MySecondScene::update_A(float delta)
{
	Node::update(delta);

	if (keys[EventKeyboard::KeyCode::KEY_A]) {
		keyPressedDuration_A();
	}
}
void MySecondScene::update_D(float delta)
{
	Node::update(delta);

	if (keys[EventKeyboard::KeyCode::KEY_D]) {
		keyPressedDuration_D();
	}
}

void MySecondScene::keyPressedDuration_Scene(float offsetX, float offsetY)
{
	auto moveTo1 = MoveTo::create(0, Vec2(start_Page->getPositionX() - offsetX, start_Page->getPositionY() - offsetY));
	start_Page->runAction(moveTo1);
	auto border1move = MoveTo::create(0, Vec2(border1->getPositionX() - offsetX, border1->getPositionY() - offsetY));
	border1->runAction(border1move);
	auto border2move = MoveTo::create(0, Vec2(border2->getPositionX() - offsetX, border2->getPositionY() - offsetY));
	border2->runAction(border2move);
	auto border3move = MoveTo::create(0, Vec2(border3->getPositionX() - offsetX, border3->getPositionY() - offsetY));
	border3->runAction(border3move);
	auto border4move = MoveTo::create(0, Vec2(border4->getPositionX() - offsetX, border4->getPositionY() - offsetY));
	border4->runAction(border4move);
	auto river1move = MoveTo::create(0, Vec2(river1->getPositionX() - offsetX, river1->getPositionY() - offsetY));
	river1->runAction(river1move);
	auto river2move = MoveTo::create(0, Vec2(river2->getPositionX() - offsetX, river2->getPositionY() - offsetY));
	river2->runAction(river2move);
	auto lakemove = MoveTo::create(0, Vec2(lake->getPositionX() - offsetX, lake->getPositionY() - offsetY));
	lake->runAction(lakemove);
	if (circle1 != nullptr) {
		auto circle1move = MoveTo::create(0, Vec2(circle1->getPositionX() - offsetX, circle1->getPositionY() - offsetY));
		circle1->runAction(circle1move);
	}
	if (circle2 != nullptr) {
		auto circle2move = MoveTo::create(0, Vec2(circle2->getPositionX() - offsetX, circle2->getPositionY() - offsetY));
		circle2->runAction(circle2move);
	}

	for (int i = 0; i < BRICK_AMOUNT; i++) {
		auto moveTo2 = MoveTo::create(0, Vec2(brick->getChildByTag(BRICK_TAG + i)->getPositionX() - offsetX, brick->getChildByTag(BRICK_TAG + i)->getPositionY() - offsetY));
		brick->getChildByTag(BRICK_TAG + i)->runAction(moveTo2);
	}
	for (int i = 0; i < GRASS_AMOUNT; i++) {
		auto moveTo3 = MoveTo::create(0, Vec2(gress->getChildByTag(GRASS_TAG + i)->getPositionX() - offsetX, gress->getChildByTag(GRASS_TAG + i)->getPositionY() - offsetY));
		gress->getChildByTag(GRASS_TAG + i)->runAction(moveTo3);
	}
	for (int i = 0; i < GUN1_AMOUNT; i++) {
		if (gun1->getChildByTag(GUN1_TAG + i) != nullptr) {
			auto moveTo4 = MoveTo::create(0, Vec2(gun1->getChildByTag(GUN1_TAG + i)->getPositionX() - offsetX, gun1->getChildByTag(GUN1_TAG + i)->getPositionY() - offsetY));
			gun1->getChildByTag(GUN1_TAG + i)->runAction(moveTo4);
		}

	}
	for (int i = 0; i < GUN2_AMOUNT; i++) {
		if (gun2->getChildByTag(GUN2_TAG + i) != nullptr) {
			auto moveTo5 = MoveTo::create(0, Vec2(gun2->getChildByTag(GUN2_TAG + i)->getPositionX() - offsetX, gun2->getChildByTag(GUN2_TAG + i)->getPositionY() - offsetY));
			gun2->getChildByTag(GUN2_TAG + i)->runAction(moveTo5);
		}

	}
	for (int i = 0; i < PILL_AMOUNT; i++) {
		if (pill->getChildByTag(PILL_TAG + i) != nullptr) {
			auto moveTo6 = MoveTo::create(0, Vec2(pill->getChildByTag(PILL_TAG + i)->getPositionX() - offsetX, pill->getChildByTag(PILL_TAG + i)->getPositionY() - offsetY));
			pill->getChildByTag(PILL_TAG + i)->runAction(moveTo6);
		}
	}

	for (int i = 0; i < BULLET1_AMOUNT; i++) {
		if (bullet1->getChildByTag(BULLET1_TAG + i) != nullptr) {
			auto moveTo7 = MoveTo::create(0, Vec2(bullet1->getChildByTag(BULLET1_TAG + i)->getPositionX() - offsetX, bullet1->getChildByTag(BULLET1_TAG + i)->getPositionY() - offsetY));
			bullet1->getChildByTag(BULLET1_TAG + i)->runAction(moveTo7);
		}

	}

	for (int i = 0; i < BULLET2_AMOUNT; i++) {
		if (bullet2->getChildByTag(BULLET2_TAG + i) != nullptr) {
			auto moveTo7 = MoveTo::create(0, Vec2(bullet2->getChildByTag(BULLET2_TAG + i)->getPositionX() - offsetX, bullet2->getChildByTag(BULLET2_TAG + i)->getPositionY() - offsetY));
			bullet2->getChildByTag(BULLET2_TAG + i)->runAction(moveTo7);
		}

	}
	for (int i = 0; i < SPEED_AMOUNT+BULLET1LIMIT_AMOUNT+BULLET2LIMIT_AMOUNT; i++) {
		if (addSomething->getChildByTag(SPEED_TAG + i) != nullptr) {
			auto moveTo8 = MoveTo::create(0, Vec2(addSomething->getChildByTag(SPEED_TAG + i)->getPositionX() - offsetX,addSomething->getChildByTag(SPEED_TAG + i)->getPositionY() - offsetY));
			addSomething->getChildByTag(SPEED_TAG + i)->runAction(moveTo8);
		}
	}
	for (int i = 0; i < vecMonster.size(); i++) {
		auto moveTo9 = MoveTo::create(0, Vec2(vecMonster[i]->getPositionX() - offsetX, vecMonster[i]->getPositionY() - offsetY));
		vecMonster[i]->runAction(moveTo9);
	}
	for (int i = 0; i < vecAIPlayer.size(); i++) {
		auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		vecAIPlayer[i]->runAction(moveBy);
	}
	auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
	duck->runAction(moveBy);
	for (int i = 0; i < vecMissile.size(); i++) {
		auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		vecMissile[i]->runAction(moveBy);
	}
	for (int i = 0; i < vecAIPlayer.size(); i++) {
		auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		if (this->getChildByTag(AIPLAYER_BULLET_TAG + i) != nullptr) {
			this->getChildByTag(AIPLAYER_BULLET_TAG + i)->runAction(moveBy);
		}
	}
	for (int i = 0; i < vecGhost.size(); i++) {
		auto moveBy1 = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		auto moveBy2 = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		vecGhost[i]->runAction(moveBy1);
		vecGhost[i]->myPoint->runAction(moveBy2);
	}
	auto moveByBullet = MoveBy::create(0, Vec2(-offsetX, -offsetY));
	if (this->getChildByTag(PLAYER_BULLET_TAG) != nullptr) {
		this->getChildByTag(PLAYER_BULLET_TAG)->runAction(moveByBullet);
	}
}

void MySecondScene::keyPressedDuration_A()//当按键返回为true时执行的函数
//其中当人物在中心位置时移动人，而人物超出中心位置的时候移动景，之后联机需要用UI坐标转化，将背景坐标与人物坐标相减得到绝对坐标，传输玩家位置信息
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	float offsetX = -m_player->speed; float offsetY = 0;
	if (m_player->getPositionX() >= 150 || start_Page->getPositionX() >= start_Page->getContentSize().width / 2 + 25) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		keyPressedDuration_Scene(offsetX, offsetY);
	}
}
void MySecondScene::keyPressedDuration_D()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	float offsetX = m_player->speed; float offsetY = 0;
	if (m_player->getPositionX() <= 330 || start_Page->getPositionX() <= 455 - start_Page->getContentSize().width / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		keyPressedDuration_Scene(offsetX, offsetY);
	}
}
void MySecondScene::keyPressedDuration_W()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	float offsetX = 0; float offsetY = m_player->speed;
	if (m_player->getPositionY() <= 230 || start_Page->getPositionY() <= 320 - start_Page->getContentSize().height / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		keyPressedDuration_Scene(offsetX, offsetY);
	}
}
void MySecondScene::keyPressedDuration_S()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	float offsetX = 0; float offsetY = -m_player->speed;
	if (m_player->getPositionY() >= 100 || start_Page->getPositionY() >= start_Page->getContentSize().height / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		keyPressedDuration_Scene(offsetX, offsetY);
	}
}

bool MySecondScene::onTouchBegan(Touch* touch, Event* unused_event) {
	Vec2 touchLocation = touch->getLocation();
	Vec2 offset = touchLocation - m_player->getPosition();

	// 3.在玩家所在的位置创建一个，将其添加到场景中。
	if (guntype == 1 || guntype == 2) {

		if (guntype == 1) {
			if (!m_player->bullet2_is_empty())
			{
				m_player->lose_bullet2();
				m_player->print_rest_bullet2(BULLET2);
				bullet = Sprite::create("bullet1.png");
				bullet->setPosition(m_player->getPosition());
				auto physicsBody = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
				physicsBody->setDynamic(false);
				physicsBody->setContactTestBitmask(0xFFFFFFFF);
				bullet->setPhysicsBody(physicsBody);
				bullet->setTag(PLAYER_BULLET_TAG);
				this->addChild(bullet);
				// 将偏移量转化为单位向量，即长度为1的向量。
				offset.normalize();
				// 将其乘以1000，你就获得了一个指向用户触屏方向的长度为1000的向量。为什么是1000呢？因为长度应当足以超过当前分辨率下屏幕的边界。
				auto shootAmount = offset * 125;
				// 将此向量添加到子弹的位置上去，这样你就有了一个目标位置。
				auto realDest = shootAmount + bullet->getPosition();
				// 创建一个动作，将子弹在2秒内移动到目标位置，然后将它从场景中移除。
				auto actionMove = MoveTo::create(0.3f, realDest);
				auto actionRemove = RemoveSelf::create();

				float radiansx = atan2(offset.y, -offset.x);
				float degreex = CC_RADIANS_TO_DEGREES(radiansx);
				bullet->setRotation(degreex);

				bullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));
			}

		}
		else {
			if (!m_player->bullet1_is_empty())
			{
				m_player->lose_bullet1();
				m_player->print_rest_bullet1(BULLET1);
				bullet = Sprite::create("bullet2.png");
				bullet->setPosition(m_player->getPosition());
				auto physicsBody = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
				physicsBody->setDynamic(false);
				physicsBody->setContactTestBitmask(0xFFFFFFFF);
				bullet->setPhysicsBody(physicsBody);
				bullet->setTag(PLAYER_BULLET_TAG);
				this->addChild(bullet);
				// 将偏移量转化为单位向量，即长度为1的向量。
				offset.normalize();
				// 将其乘以1000，你就获得了一个指向用户触屏方向的长度为1000的向量。为什么是1000呢？因为长度应当足以超过当前分辨率下屏幕的边界。
				auto shootAmount = offset * 125;
				// 将此向量添加到子弹的位置上去，这样你就有了一个目标位置。
				auto realDest = shootAmount + bullet->getPosition();
				// 创建一个动作，将子弹在2秒内移动到目标位置，然后将它从场景中移除。
				auto actionMove = MoveTo::create(1.6f, realDest);
				auto actionRemove = RemoveSelf::create();

				float radians3 = atan2(offset.y, -offset.x);
				float degree3 = CC_RADIANS_TO_DEGREES(radians3);
				bullet->setRotation(degree3);

				bullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));

				auto bullet2 = Sprite::create("bullet2.png");
				bullet2->setPosition(m_player->getPosition());
				auto physicsBody1 = PhysicsBody::createBox(bullet2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
				physicsBody1->setDynamic(false);
				physicsBody1->setContactTestBitmask(0xFFFFFFFF);
				bullet2->setPhysicsBody(physicsBody1);
				bullet2->setTag(PLAYER_BULLET_TAG);
				this->addChild(bullet2);

				auto bullet3 = Sprite::create("bullet2.png");
				bullet3->setPosition(m_player->getPosition());
				auto physicsBody2 = PhysicsBody::createBox(bullet3->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
				physicsBody2->setDynamic(false);
				physicsBody2->setContactTestBitmask(0xFFFFFFFF);
				bullet3->setPhysicsBody(physicsBody2);
				bullet3->setTag(PLAYER_BULLET_TAG);
				this->addChild(bullet3);
				//向量转化 有点小复杂
				auto side_bullet1 = Vec2(bullet->getPositionX(), bullet->getPositionY());
				auto side_bullet2 = Vec2(bullet->getPositionX(), bullet->getPositionY());

				auto Dest1 = shootAmount + side_bullet1;
				auto Dest2 = shootAmount + side_bullet2;

				auto realDest1 = Vec2(Dest1.x - m_player->getPositionX() + (Dest1.y - m_player->getPositionY()) / 2, Dest1.y - m_player->getPositionY() + (Dest1.x - m_player->getPositionX()) / 2);
				auto realDest2 = Vec2(Dest2.x - m_player->getPositionX() - (Dest2.y - m_player->getPositionY()) / 2, Dest2.y - m_player->getPositionY() - (Dest2.x - m_player->getPositionX()) / 2);

				realDest1.normalize();
				auto realDest11 = realDest1 * 125 + bullet2->getPosition();

				float radians = atan2(realDest1.y, -realDest1.x);
				float degree = CC_RADIANS_TO_DEGREES(radians);
				bullet2->setRotation(degree);


				float radians2 = atan2(realDest2.y, -realDest2.x);
				float degree2 = CC_RADIANS_TO_DEGREES(radians2);
				bullet3->setRotation(degree2);



				realDest2.normalize();
				auto realDest22 = realDest2 * 125 + bullet3->getPosition();

				auto actionMove1 = MoveTo::create(1.6f, realDest11);
				auto actionRemove1 = RemoveSelf::create();
				bullet2->runAction(Sequence::create(actionMove1, actionRemove1, nullptr));

				auto actionMove2 = MoveTo::create(1.6f, realDest22);
				auto actionRemove2 = RemoveSelf::create();
				bullet3->runAction(Sequence::create(actionMove2, actionRemove2, nullptr));
			}


		}
	}
	return true;
}

void MySecondScene::addMonstersAndAI(const int humanAmount)
{
	//创建ai玩家
	for (int i = 0; i < PLAYER_AMOUNT - humanAmount; i++) {
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
		vecMonster[i]->setScale(0.15);
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

	duck->setPosition(start_Page->getContentSize().width / 2 - 60, start_Page->getContentSize().height / 2 - 60);
	duck->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_monsterDuck());
	this->addChild(duck);

	duck->SetMissiles();
	vecMissile = duck->GetMissiles();
	mapMissileTag = duck->GetMapMissile();

	//创建耿鬼
	for (int i = 0; i < GHOST_AMOUNT; i++) {
		vecGhost.push_back(Ghost::create());
		vecGhost[i]->bindSprite(Sprite::create("monster2.png"));
		vecGhost[i]->getSprite()->runAction(AnimationUtil::createWithSingleFrameName_monsterGhost());
		vecGhost[i]->retain();
		vecMonster[i]->setScale(0.15);

		auto Body = PhysicsBody::createBox(vecGhost[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		vecGhost[i]->setPhysicsBody(Body);
		vecGhost[i]->setTag(GHOST_TAG + i);
		mapGhostTag.insert(std::pair<int, Ghost*>(GHOST_TAG + i, vecGhost[i]));

		vecGhost[i]->BindPlayers(vecPlayer); //绑定玩家
		vecGhost[i]->BindAIPlayers(vecAIPlayer); //绑定ai玩家

		vecGhost[i]->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
		vecGhost[i]->myPoint->setPosition(vecGhost[i]->getPosition());
		vecGhost[i]->setScale(0.3);
		this->addChild(vecGhost[i]);
		this->addChild(vecGhost[i]->myPoint);
	}

	//ai玩家绑定怪物
	for (int i = 0; i < vecAIPlayer.size(); i++) {
		vecAIPlayer[i]->BindMonsters(vecMonster);
	}
}

void MySecondScene::addCircle(float dt) {
	if (circle == 1) {
		start_Page->initWithFile("startpage_circle1.png");
		Small_map->initWithFile("big2_circle1.png");
		Small_map->setOpacity(120);
		circle1 = Sprite::create("circle1.png");
		circle1->setPosition(start_Page->getPosition());
		this->addChild(circle1);
		circle++;
	}
	else if (circle == 2) {
		start_Page->initWithFile("startpage_circle2.png");
		Small_map->initWithFile("big2_circle2.png");
		Small_map->setOpacity(120);
		circle2 = Sprite::create("circle2.png");
		circle2->setPosition(start_Page->getPosition());
		this->addChild(circle2);
		circle++;
	}
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
		//耿鬼和ai玩家
		if (GHOST_TAG <= tagA && GHOST_TAG + GHOST_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter2 = mapAIPlayerTag.find(tagB);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
			}
		}
		else if (GHOST_TAG <= tagB && GHOST_TAG + GHOST_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter2 = mapAIPlayerTag.find(tagA);
			if (iter2 != mapAIPlayerTag.end()) {
				iter2->second->isHit();
			}
		}
		//耿鬼和玩家
		else if (GHOST_TAG <= tagA && GHOST_TAG + GHOST_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter2 = mapPlayerTag.find(tagB);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
		else if (GHOST_TAG <= tagB && GHOST_TAG + GHOST_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter2 = mapPlayerTag.find(tagA);
			if (iter2 != mapPlayerTag.end()) {
				iter2->second->isHit();
			}
			m_player->alter_blood(m_blood);
		}
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
		//怪物子弹和箱子
		else if (MONSTER_BULLET_TAG == tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
		}
		else if (MONSTER_BULLET_TAG == tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
		}
		//追踪弹和箱子
		else if (MISSILE_TAG <= tagA && MISSILE_TAG + PLAYER_AMOUNT > tagA && BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB) {
			auto iter = mapMissileTag.find(tagA);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
		}
		else if (MISSILE_TAG <= tagB && MISSILE_TAG + PLAYER_AMOUNT > tagB && BRICK_TAG <= tagA && BRICK_TAG + BRICK_AMOUNT > tagA) {
			auto iter = mapMissileTag.find(tagB);
			if (iter != mapMissileTag.end()) {
				iter->second->Reset();
			}
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
		else if (BRICK_TAG <= tagB && BRICK_TAG + BRICK_AMOUNT > tagB && MONSTER_TAG <= tagA && MONSTER_TAG + MONSTER_AMOUNT > tagA) {
			auto iter = mapMonsterTag.find(tagA);
			if (iter != mapMonsterTag.end()) {
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
		//玩家与河湖
		else if (RIVER_TAG == tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		else if (RIVER_TAG == tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		//AI玩家与河湖
		else if (RIVER_TAG == tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		else if (RIVER_TAG == tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		//玩家与草丛
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		//AI玩家与草丛
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(50);
			}
		}
		//玩家与枪1
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
		//玩家与枪2
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
		//玩家与药物
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
		//玩家与枪1匹配的子弹
		else if (BULLET1_TAG <= tagA && BULLET1_TAG + BULLET1_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			nodeA->removeFromParentAndCleanup(true);
			m_player->gain_bullet1();
			m_player->print_rest_bullet1(BULLET1);
		}
		else if (BULLET1_TAG <= tagB && BULLET1_TAG + BULLET1_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			nodeB->removeFromParentAndCleanup(true);
			m_player->gain_bullet1();
			m_player->print_rest_bullet1(BULLET1);
		}
		//玩家与枪2匹配的子弹
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
		//玩家与速度提升道具
		else if (SPEED_TAG <= tagA && SPEED_TAG + SPEED_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				if (!iter->second->speedIsfull()) {
					iter->second->changeSpeed();
					iter->second->print_speed(SPEED);
					nodeA->removeFromParentAndCleanup(true);
				}
			}
		}
		else if (SPEED_TAG <= tagB && SPEED_TAG + SPEED_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				if (!iter->second->speedIsfull()) {
					iter->second->changeSpeed();
					iter->second->print_speed(SPEED);
					nodeB->removeFromParentAndCleanup(true);
				}
			}
		}
		//玩家与弹夹容量1提升道具
		else if (BULLET1LIMIT_TAG <= tagA && BULLET1LIMIT_TAG + BULLET1LIMIT_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				iter->second->addBullet1Amount();
				iter->second->print_rest_bullet1(BULLET1);
				nodeA->removeFromParentAndCleanup(true);
			}
		}
		else if (BULLET1LIMIT_TAG <= tagB && BULLET1LIMIT_TAG + BULLET1LIMIT_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				iter->second->addBullet1Amount();
				iter->second->print_rest_bullet1(BULLET1);
				nodeB->removeFromParentAndCleanup(true);
			}
		}
		//玩家与弹夹容量2提升道具
		else if (BULLET2LIMIT_TAG <= tagA && BULLET2LIMIT_TAG + BULLET2LIMIT_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
		auto iter = mapPlayerTag.find(tagB);
		if (iter != mapPlayerTag.end()) {
			iter->second->addBullet2Amount();
			iter->second->print_rest_bullet2(BULLET2);
			nodeA->removeFromParentAndCleanup(true);
		}
		}
		else if (BULLET2LIMIT_TAG <= tagB && BULLET2LIMIT_TAG + BULLET2LIMIT_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
		auto iter = mapPlayerTag.find(tagA);
		if (iter != mapPlayerTag.end()) {
			iter->second->addBullet2Amount();
			iter->second->print_rest_bullet2(BULLET2);
			nodeB->removeFromParentAndCleanup(true);
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
		//玩家与河湖
		else if (RIVER_TAG == tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				if ((iter->second->getPosition().x >= lake->getPosition().x + lake->getContentSize().width / 2 || iter->second->getPosition().x <= lake->getPosition().x - lake->getContentSize().width / 2) || (iter->second->getPosition().y >= lake->getPosition().y + lake->getContentSize().height / 2 || iter->second->getPosition().y <= lake->getPosition().y - lake->getContentSize().height / 2))
			    {
				    iter->second->getSprite()->setOpacity(255);
				}
			}
		}
		else if (RIVER_TAG == tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				if ((iter->second->getPosition().x >= lake->getPosition().x + lake->getContentSize().width / 2 || iter->second->getPosition().x <= lake->getPosition().x - lake->getContentSize().width / 2) || (iter->second->getPosition().y >= lake->getPosition().y + lake->getContentSize().height / 2 || iter->second->getPosition().y <= lake->getPosition().y - lake->getContentSize().height / 2))
				{
					iter->second->getSprite()->setOpacity(255);
				}
			}
		}
		//AI玩家与河湖
		else if (RIVER_TAG == tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				if ((iter->second->getPosition().x >= lake->getPosition().x + lake->getContentSize().width / 2 || iter->second->getPosition().x <= lake->getPosition().x - lake->getContentSize().width / 2) || (iter->second->getPosition().y >= lake->getPosition().y + lake->getContentSize().height / 2 || iter->second->getPosition().y <= lake->getPosition().y - lake->getContentSize().height / 2))
				{
					iter->second->getSprite()->setOpacity(255);
				}
			}
		}
		else if (RIVER_TAG == tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				if ((iter->second->getPosition().x >= lake->getPosition().x + lake->getContentSize().width / 2 || iter->second->getPosition().x <= lake->getPosition().x - lake->getContentSize().width / 2) ||(iter->second->getPosition().y >= lake->getPosition().y + lake->getContentSize().height / 2 || iter->second->getPosition().y <= lake->getPosition().y - lake->getContentSize().height / 2))
				{
					iter->second->getSprite()->setOpacity(255);
				}
			}
		}
		//玩家和草丛
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && PLAYER_TAG <= tagB && PLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapPlayerTag.find(tagB);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(255);
			}
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && PLAYER_TAG <= tagA && PLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapPlayerTag.find(tagA);
			if (iter != mapPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(255);
			}
		}
		//AI玩家与草丛
		else if (GRASS_TAG <= tagA && GRASS_TAG + GRASS_AMOUNT > tagA && AIPLAYER_TAG <= tagB && AIPLAYER_TAG + PLAYER_AMOUNT > tagB) {
			auto iter = mapAIPlayerTag.find(tagB);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(255);
			}
		}
		else if (GRASS_TAG <= tagB && GRASS_TAG + GRASS_AMOUNT > tagB && AIPLAYER_TAG <= tagA && AIPLAYER_TAG + PLAYER_AMOUNT > tagA) {
			auto iter = mapAIPlayerTag.find(tagA);
			if (iter != mapAIPlayerTag.end()) {
				iter->second->getSprite()->setOpacity(255);
			}
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