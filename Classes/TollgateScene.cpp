#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"


using namespace cocos2d;

const int Front = 1;
const int Behind = 2;
const int Right = 3;
const int Left = 4;
int m_PlayerImage = 0;


USING_NS_CC;

Scene* TollgateScene::createScene()
{
	return TollgateScene::create();
}

bool TollgateScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	AudioEngine::stopAll();
	AudioID1 = AudioEngine::play2d("bacmusic.mp3");

	/*游戏标题图片*/
	//Sprite* titleSprite = Sprite::create();

	//m_player = Player::create();
	//m_player->bindSprite(Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\11.png"));

	/*初始化背景图片*/
	initBG();//初始化背景图（地图、石头、树、边界线）

	/*开始图*/
	initBeginning();


	//initIF();//初始化界面（血条图、计时器、得分图、小地图）

	/*创建主角*/

	return true;
}


//跑动地图更新
void TollgateScene::update(float delta)
{
	/*int pos_X= start_Page->getPositionX();
	//int pos_Y = start_Page->getPositionY();
	//int pos_Y=start_Page->getPositionX();
	//int posX1=Small_map
	int i_speedX = 1;
	//int i_speedY = 1;
	pos_X -= i_speedX;
	//pos_Y -= i_speedY;
	start_Page->setPositionX(pos_X);
	//start_Page->setPositionX(pos_Y);*/
}

/*回调函数*/
void TollgateScene::MySecondScene(Ref* pSender)
{
	AudioEngine::stopAll();
	AudioID2 = AudioEngine::play2d("fight.mp3");
	Director::getInstance()->replaceScene(MySecondScene::createScene(m_PlayerImage));
}
void TollgateScene::ChangeImageToBird(Ref* pSender)
{
	m_PlayerImage++;
	bird->initWithFile((cocos2d::StringUtils::format("%1dplayer.png", m_PlayerImage % 9)));
	
}
void TollgateScene::MyThirdScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MyThirdScene::createScene());
}
void TollgateScene::MyFifthScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MyFifthScene::createScene());
}
void TollgateScene::EXIT(Ref* pSender)
{
	Director::getInstance()->end();
}

bool TollgateScene::onTouchBegan(Touch* touch, Event* unused_event)
{

	//CC_CALLBACK_1(UILayer::menuItemCallBack, this);
	ENTERROOM = Label::create();
	ENTERROOM->setString("ENTER ROOM");
	ENTERROOM->setScale(2);
	ENTERROOM->setColor(Color3B(138, 151, 123));
	ENTERROOM->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
	ENTERROOM->setPosition(Vec2(300, 75));
	this->addChild(ENTERROOM);
	return true;
}

