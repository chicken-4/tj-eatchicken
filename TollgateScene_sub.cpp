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

using namespace cocos2d;

USING_NS_CC;

void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//大地图
	start_Page = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\big2xx.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);



	//边界线
	border1 = Sprite::create("border.png");
	border1->setPosition(240, 10);
	border1->setTag(50);
	this->addChild(border1);

	border2 = Sprite::create("border2.png");
	border2->setPosition(40, 160);
	border2->setTag(50);
	this->addChild(border2);

	border3 = Sprite::create("border2.png");
	border3->setPosition(440, 160);
	border3->setTag(50);
	this->addChild(border3);

	border4 = Sprite::create("border.png");
	border4->setPosition(240, 320);
	border4->setTag(50);
	this->addChild(border4);

	//石头
	/*box = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\bocket.png");
	box->setPosition(Vec2(227, 260));
	box->setTag(50);
	this->addChild(box);

	tree = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\cao.png");
	tree->setPosition(Vec2(315, 380));
	tree->setTag(50);
	this->addChild(tree);*/

}


void TollgateScene::initBeginning()
{
	auto label1 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label1->setString("START GAME");
	label1->setScale(1.0);
	auto menu1 = Menu::create();
	//label->setPosition(Vec2(300, 175));
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
	//label->setPosition(Vec2(300, 175));
	auto menuitem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(TollgateScene::MyThirdScene, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem2->setPosition(Vec2(70, -70));
	menu2->addChild(menuitem2);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu2);

	auto label3 = Label::create();// = Label::createWithSystemFont("START GAME", "fonts/arial.ttf", 30);
	label3->setString("EXIT");
	label3->setScale(1.0);
	auto menu3 = Menu::create();
	//label->setPosition(Vec2(300, 175));
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(TollgateScene::EXIT, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	menuitem3->setPosition(Vec2(120, -120));
	menu3->addChild(menuitem3);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu3);

	POBG = Label::create();
	POBG->setString("POBG");
	POBG->setScale(5);
	POBG->setColor(Color3B(3, 54, 73));
	POBG->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	POBG->setPosition(Vec2(300, 250));
	this->addChild(POBG);

}
