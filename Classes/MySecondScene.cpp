#include<AudioEngine.h>
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"
#include"TimeCounter.h"

//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene

//主地图
Scene* MySecondScene::createScene()
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
	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(start_Page->getContentSize().width / 2 + 25, start_Page->getContentSize().height / 2);
	this->addChild(start_Page);

	//边界
	border1 = Sprite::create("border.png");
	border1->setPosition(240, 0);
	auto physicsBody_border = PhysicsBody::createBox(border1->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border->setDynamic(false);
	physicsBody_border->setContactTestBitmask(0xFFFFFFFF);
	border1->setPhysicsBody(physicsBody_border);
	border1->setTag(BORDER_TAG);
	this->addChild(border1);

	border2 = Sprite::create("border2.png");
	border2->setPosition(24, 160);
	auto physicsBody_border2 = PhysicsBody::createBox(border2->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border2->setDynamic(false);
	physicsBody_border2->setContactTestBitmask(0xFFFFFFFF);
	border2->setPhysicsBody(physicsBody_border2);
	border2->setTag(BORDER_TAG);
	this->addChild(border2);

	border3 = Sprite::create("border2.png");
	border3->setPosition(456, 160);
	auto physicsBody_border3 = PhysicsBody::createBox(border3->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border3->setDynamic(false);
	physicsBody_border3->setContactTestBitmask(0xFFFFFFFF);
	border3->setPhysicsBody(physicsBody_border3);
	border3->setTag(BORDER_TAG);
	this->addChild(border3);

	border4 = Sprite::create("border.png");
	border4->setPosition(240, 320);
	auto physicsBody_border4 = PhysicsBody::createBox(border4->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody_border4->setDynamic(false);
	physicsBody_border4->setContactTestBitmask(0xFFFFFFFF);
	border4->setPhysicsBody(physicsBody_border4);
	border4->setTag(BORDER_TAG);
	this->addChild(border4);


	//石头
	brick = SpriteBatchNode::create("bocket.png");

	for (int i = 0; i < BRICK_AMOUNT; i++)
	{
		Sprite* sprite = Sprite::create("bocket.png");
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
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
		sprite->setPosition(Vec2(CCRANDOM_0_1() * (start_Page->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (start_Page->getContentSize().height - 200) + 100));
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


	Sprite* bagblock1 = Sprite::create("bagblock.png");
	bagblock1->setPosition(400, 20);
	this->addChild(bagblock1);

	Sprite* bagblock2 = Sprite::create("bagblock.png");
	bagblock2->setPosition(370, 20);
	this->addChild(bagblock2);

	Sprite* bagblock3 = Sprite::create("bagblock.png");
	bagblock3->setPosition(430, 20);
	this->addChild(bagblock3);
}
void MySecondScene::initIF()
{
	//小地图
	Small_map = Sprite::create("big2.png");
	Small_map->setPosition(453 - Small_map->getContentSize().width / 2, 320 - Small_map->getContentSize().height / 2);
	Small_map->setOpacity(120);
	this->addChild(Small_map);

	//小地图坐标
	ball = Sprite::create("ball.png");
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	ball->setOpacity(100);
	this->addChild(ball);

	//血条
	m_blood = Sprite::create("blood.png");
	m_blood->setPosition(Vec2(110, 300));
	m_blood->setScale(1, 1);
	m_blood->setAnchorPoint(Vec2(0, 0.5));
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



	time_label = Label::create();
	time_label->setString("Time:");
	time_label->setColor(Color3B(0, 0, 0));
	time_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	time_label->setPosition(Vec2(260, 300));
	this->addChild(time_label);

	//倒计时
	auto time = Clock::create();
	time->BindLabel(Label::create());
	time->setScale(1);
	time->setColor(Color3B(0, 0, 0));
	time->setPosition(Vec2(290, 298));
	this->addChild(time);

	Score = Label::create();
	Score->setPosition(Vec2(110, 270));
	Score->setString("0");
	Score->setColor(Color3B(0, 0, 0));
	this->addChild(Score);


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
	if (m_player->isDead() && !hasDead) {
		hasDead = true;
		Sprite* back = Sprite::create("black.png");
		back->setScale(5,5);
		addChild(back, 10);
		back->setPosition(Vec2(240, 160)); ////

		auto choice = MenuItemFont::create("OK", [=](Ref* render) {
			Director::getInstance()->popScene();
			});
		auto menu = Menu::create();
		menu->addChild(choice);
		menu->setPosition(240, 40);
		addChild(menu, 20);

		auto text = Label::createWithTTF("Game over", "fonts/Marker Felt.ttf", 70);
		text->setPosition(Vec2(240, 280)); /// 
		addChild(text, 30);

		for (int i = 0; i < PLAYER_AMOUNT - 1; ++i) {
			auto playerLabel = Label::createWithTTF(StringUtils::format("player%d",i) + StringUtils::format("     %d", vecAIPlayer[i]->queryscore()), "fonts/Marker Felt.ttf", 20);
			playerLabel->setPosition(240, 60 + 20 * i);
			addChild(playerLabel, 30);
		}
		auto playerLabel = Label::createWithTTF("me" + StringUtils::format("     %d", m_player->queryscore()), "fonts/Marker Felt.ttf", 20);
		playerLabel->setPosition(240, 40 + 20 * 10);
		addChild(playerLabel, 30);

	}

	Node::update(delta);
	update_W(delta);
	update_S(delta);
	update_A(delta);
	update_D(delta);
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

void MySecondScene::keyPressedDuration_A()//当按键返回为true时执行的函数
//其中当人物在中心位置时移动人，而人物超出中心位置的时候移动景，之后联机需要用UI坐标转化，将背景坐标与人物坐标相减得到绝对坐标，传输玩家位置信息
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	int offsetX = -2; int offsetY = 0;
	if (m_player->getPositionX() >= 150 || start_Page->getPositionX() >= start_Page->getContentSize().width / 2 + 25) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		auto moveTo1 = MoveTo::create(0, Vec2(start_Page->getPositionX() - offsetX, start_Page->getPositionY() - offsetY));
		start_Page->runAction(moveTo1);

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
		for (int i = 0; i < MONSTER_AMOUNT; i++) {
			auto moveTo7 = MoveTo::create(0, Vec2(vecMonster[i]->getPositionX() - offsetX, vecMonster[i]->getPositionY() - offsetY));
			vecMonster[i]->runAction(moveTo7);
		}

		for (int i = 0; i < vecAIPlayer.size(); i++) {
			auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
			vecAIPlayer[i]->runAction(moveBy);
		}

	}
}
void MySecondScene::keyPressedDuration_D()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	int offsetX = 2; int offsetY = 0;
	if (m_player->getPositionX() <= 330 || start_Page->getPositionX() <= 455 - start_Page->getContentSize().width / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		auto moveTo1 = MoveTo::create(0, Vec2(start_Page->getPositionX() - offsetX, start_Page->getPositionY() - offsetY));
		start_Page->runAction(moveTo1);

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
		for (int i = 0; i < MONSTER_AMOUNT; i++) {
			auto moveTo7 = MoveTo::create(0, Vec2(vecMonster[i]->getPositionX() - offsetX, vecMonster[i]->getPositionY() - offsetY));
			vecMonster[i]->runAction(moveTo7);
		}

		for (int i = 0; i < vecAIPlayer.size(); i++) {
			auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
			vecAIPlayer[i]->runAction(moveBy);
		}
	}
}
void MySecondScene::keyPressedDuration_W()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	int offsetX = 0; int offsetY = 2;
	if (m_player->getPositionY() <= 230 || start_Page->getPositionY() <= 320 - start_Page->getContentSize().height / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		auto moveTo1 = MoveTo::create(0, Vec2(start_Page->getPositionX() - offsetX, start_Page->getPositionY() - offsetY));
		start_Page->runAction(moveTo1);

		for (int i = 0; i < BRICK_AMOUNT - 1; i++) {
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
		for (int i = 0; i < MONSTER_AMOUNT; i++) {
			auto moveTo7 = MoveTo::create(0, Vec2(vecMonster[i]->getPositionX() - offsetX, vecMonster[i]->getPositionY() - offsetY));
			vecMonster[i]->runAction(moveTo7);
		}

		for (int i = 0; i < vecAIPlayer.size(); i++) {
			auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
			vecAIPlayer[i]->runAction(moveBy);
		}
	}
}
void MySecondScene::keyPressedDuration_S()
{
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	int offsetX = 0; int offsetY = -2;
	if (m_player->getPositionY() >= 100 || start_Page->getPositionY() >= start_Page->getContentSize().height / 2) {
		auto moveTo = MoveTo::create(0, Vec2(m_player->getPositionX() + offsetX, m_player->getPositionY() + offsetY));
		m_player->runAction(moveTo);
	}
	else {
		auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
		auto moveTo1 = MoveTo::create(0, Vec2(start_Page->getPositionX() - offsetX, start_Page->getPositionY() - offsetY));
		start_Page->runAction(moveTo1);

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
		for (int i = 0; i < MONSTER_AMOUNT; i++) {
			auto moveTo7 = MoveTo::create(0, Vec2(vecMonster[i]->getPositionX() - offsetX, vecMonster[i]->getPositionY() - offsetY));
			vecMonster[i]->runAction(moveTo7);
		}

		for (int i = 0; i < vecAIPlayer.size(); i++) {
			auto moveBy = MoveBy::create(0, Vec2(-offsetX, -offsetY));
			vecAIPlayer[i]->runAction(moveBy);
		}
	}
}

bool MySecondScene::onTouchBegan(Touch* touch, Event* unused_event) {
	Vec2 touchLocation = touch->getLocation();
	Vec2 offset = touchLocation - m_player->getPosition();

	// 3.在玩家所在的位置创建一个飞镖，将其添加到场景中。
	auto projectile = Sprite::create("6.png");
	projectile->setPosition(m_player->getPosition());

	// Add projectile's physicsBody
	auto physicsBody = PhysicsBody::createBox(projectile->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(0xFFFFFFFF);
	projectile->setPhysicsBody(physicsBody);
	projectile->setTag(PLAYER_BULLET_TAG);

	this->addChild(projectile);

	// 4.将偏移量转化为单位向量，即长度为1的向量。
	offset.normalize();
	// 将其乘以1000，你就获得了一个指向用户触屏方向的长度为1000的向量。为什么是1000呢？因为长度应当足以超过当前分辨率下屏幕的边界。
	auto shootAmount = offset * 125;
	// 将此向量添加到飞镖的位置上去，这样你就有了一个目标位置。
	auto realDest = shootAmount + projectile->getPosition();

	// 5.创建一个动作，将飞镖在2秒内移动到目标位置，然后将它从场景中移除。
	auto actionMove = MoveTo::create(0.3f, realDest);
	auto actionRemove = RemoveSelf::create();
	projectile->runAction(Sequence::create(actionMove, actionRemove, nullptr));

	return true;
}
