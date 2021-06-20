#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"

//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene
Scene* MyFifthScene::createScene()
{
	Scene* scene = Scene::create();
	MyFifthScene* layer = MyFifthScene::create();
	scene->addChild(layer);
	return scene;
}
void MyFifthScene::EnterFirstScene(Ref* pSender)
{
	//跳转到主界面，记得包含第一个场景的头文件：MyFirstScene.h
	Director::getInstance()->replaceScene(TollgateScene::createScene());
}
void MyFifthScene::EnterSecondScene(Ref* pSender)
{
	//跳转到主地图，记得包含第一个场景的头文件：MyFirstScene.h
	Director::getInstance()->replaceScene(MySecondScene::createScene());
}
void MyFifthScene::EXIT(Ref* pSender)
{
	//点击退出
	Director::getInstance()->end();
}
/*void something()
{
	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* keyListener = EventListenerKeyboard::create();
	//创建一个事件监听器监听键盘事件
	keyListener->onKeyPressed = CC_CALLBACK_2(MySecondScene::onKeyPressed, this);
	//键盘被按下时响应
	keyListener->onKeyReleased = CC_CALLBACK_2(MySecondScene::onKeyReleased, this);
	//键盘按键被弹回时响应
	dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}*/
