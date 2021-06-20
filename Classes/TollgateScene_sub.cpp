//#include "HelloWorldScene.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
//#include"D:\cocos\Projects\HelloWorld\win32-build\Gamemap.h"
//#include"D:\cocos\Projects\HelloWorld\win32-build\Monster.h"
#include"Player.h"
//#include"Entity.h"
#include"TollgateScene.h"
#include"SceneManage.h"
#include"AnimationUtil.h"

using namespace cocos2d;

USING_NS_CC;

void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//大地图
	start_Page = Sprite::create("startpage.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);

}

void  TollgateScene::addmissile(float dt)
{

	missile = Sprite::create("missile.png");
	auto monsterContentSize = missile->getContentSize();
	auto selfContentSize = this->getContentSize();
	int minY = monsterContentSize.height / 2;
	int maxY = selfContentSize.height - minY;
	int rangeY = maxY - minY;
	int randomY = (rand() % rangeY) + minY;
	missile->setPosition(Vec2(0, randomY));
	this->addChild(missile);
	// Let monster run
	int minDuration = 2.0;
	int maxDuration = 4.0;
	int rangeDuration = maxDuration - minDuration;
	int randomDuration = (rand() % rangeDuration) + minDuration;

	// 定义移动的object
	// 在randomDuration这个时间内(2-4秒内)，让怪物从屏幕右边移动到左边。(怪物有快有慢)
	auto actionMove1 = MoveTo::create(randomDuration, Vec2(480, randomY));
	// 定义消除的Object。怪物移出屏幕后被消除，释放资源。auto actionMove2 = MoveTo::create(randomDuration, Vec2(monsterContentSize.width / 2, randomY));
	auto actionRemove1 = RemoveSelf::create();
	missile->runAction (Sequence::create(actionMove1, actionRemove1, nullptr));
}


void TollgateScene::initBeginning()
{
	bird = Sprite:: create("0player.png");
	bird->setPosition(125, 110);
	bird->setScale(4);
	this->addChild(bird);

	auto bird_change = Menu::create();
	auto change = Label::create();
	change->setString("Click To Change");
	auto birdChange = MenuItemLabel::create(change, CC_CALLBACK_1(TollgateScene::ChangeImageToBird, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	birdChange->setPosition(Vec2(-110, -110));
	birdChange->setScale(1.0);
	bird_change->addChild(birdChange);
	//把菜单添加到MyFirstScene层中
	this->addChild(bird_change);

	auto label1 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label1->setString("START GAME");
	label1->setScale(1.0);
	auto menu1 = Menu::create();
	label1->setColor(Color3B(0, 0, 0));
	label1->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(TollgateScene::MySecondScene, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem1->setPosition(Vec2(0, 30));
	menuitem1->setScale(3.0);
	menu1->addChild(menuitem1);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu1);

	auto label2 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label2->setString("CREATE ROOM");
	label2->setScale(1.0);
	auto menu2 = Menu::create();
	label2->setColor(Color3B(0, 0, 0));
	label2->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(TollgateScene::MyThirdScene, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem2->setPosition(Vec2(50, -30));
	menuitem2->setScale(2.0);
	menu2->addChild(menuitem2);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu2);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	auto menu3 = Menu::create();
	label3->setColor(Color3B(0, 0, 0));
	label3->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(TollgateScene::EXIT, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu3);

	POBG = Label::create();
	POBG->setString("P   O   B   G");
	POBG->setScale(5);
	POBG->setColor(Color3B(3, 54, 73));
	POBG->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	POBG->setPosition(Vec2(235, 260));
	this->addChild(POBG);

	auto turtle = Sprite::create("monster11.png");
	turtle->setPosition(235, 257);
	turtle->setScale(0.45);
	turtle->runAction(AnimationUtil::createWithSingleFrameName_monster1());
	this->addChild(turtle);

	auto duck = Sprite::create("monster3.png");
	duck->setScale(0.17);
	duck->setPosition(323, 260);
	duck->runAction(AnimationUtil::createWithSingleFrameName_monsterDuck());
	this->addChild(duck);

	auto ghost= Sprite::create("monster2.png");
	ghost->setScale(0.3);
	ghost->setPosition(140, 260);
	ghost->runAction(AnimationUtil::createWithSingleFrameName_monsterGhost());
	this->addChild(ghost);
	
	srand((unsigned int)time(nullptr));
	// 每隔1.5秒生成一个怪物
	this->schedule(CC_SCHEDULE_SELECTOR(TollgateScene::addmissile), 5);

	auto label4 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label4->setString("ENTER ROOM");
	label4->setScale(1.0);
	auto menu4 = Menu::create();
	label4->setColor(Color3B(0, 0, 0));
	label4->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	auto menuitem4 = MenuItemLabel::create(label4, CC_CALLBACK_1(TollgateScene::MyFifthScene, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem4->setPosition(Vec2(50, -70));
	menuitem4->setScale(2.0);
	menu4->addChild(menuitem4);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu4);

}