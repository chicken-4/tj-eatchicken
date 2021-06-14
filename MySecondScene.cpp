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
Scene* MySecondScene::createScene()
{
	Scene* scene = Scene::create();
	MySecondScene* layer = MySecondScene::create();
	scene->addChild(layer);
	return scene;
}
void MySecondScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//大地图
	start_Page = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\big2xx.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);

	//石头
	box = Sprite::create("bocket.png");
	box->setPosition(Vec2(227, 260));
	box->setTag(50);
	this->addChild(box);

	tree = Sprite::create("cao.png");
	tree->setPosition(Vec2(315, 380));
	tree->setTag(50);
	this->addChild(tree);
}
void MySecondScene::initIF()
{
	//小地图
	Small_map = Sprite::create("big2.png");
	Small_map->setPosition(453 - Small_map->getContentSize().width / 2, 320 - Small_map->getContentSize().height / 2);
	this->addChild(Small_map);

	//小地图坐标
	ball = Sprite::create("ball.png");
	ball->setPosition(453 - Small_map->getContentSize().width / 2 - (start_Page->getPositionX() - m_player->getPositionX()) / 35, 320 - Small_map->getContentSize().height / 2 - (start_Page->getPositionY() - m_player->getPositionY()) / 35);
	//ball->setOpacity(0);//设置窗口透明度
	this->addChild(ball);

	//血条
	m_blood = Sprite::create("blood.png");
	m_blood->setPosition(Vec2(160, 300));
	m_blood->setScale(1, 1);
	this->addChild(m_blood);

	//血条分隔线
	bloodout = Sprite::create("bloodout.png");
	bloodout->setPosition(Vec2(160, 300));
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
	time_label->setString("Time");
	time_label->setColor(Color3B(0, 0, 0));
	time_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	time_label->setPosition(Vec2(260, 300));
	this->addChild(time_label);

	black1 = Sprite::create("black.png");
	black1->setPosition(453 - black1->getContentSize().width / 2, 320 - black1->getContentSize().height / 2);
	black1->setOpacity(80);
	this->addChild(black1);
}
void MySecondScene::initLABEL()
{
	auto label1 = Label::create();
	auto menu1 = Menu::create();
	label1->setString("this is main map,click to check the final rank");
	//label1->setPosition(Vec2(0, 50));
	//auto label = Label::createWithSystemFont("this is main map，click to check the final rank", "fonts/arial.ttf", 30);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MySecondScene::EnterForthScene, this));
	menuitem1->setPosition(Vec2(0, 100));
	menu1->addChild(menuitem1);
	this->addChild(menu1);



	auto label2 = Label::create();
	label2->setString("Exit");
	auto menu2 = Menu::create();
	//label2->setColor(Color3B(3, 22, 52));
	label2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MySecondScene::EXIT, this));
	menuitem2->setPosition(Vec2(120, -120));
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
bool MySecondScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	return true;
}

void MySecondScene::update(float delta)
{

}
