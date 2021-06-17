#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"

//场景的切换（主地图、最后排名、房间
//初始主界面在tollgatescene

Scene* MyForthScene::createScene()
{
	Scene* scene = Scene::create();
	MyForthScene* layer = MyForthScene::create();
	scene->addChild(layer);
	return scene;
}
void MyForthScene::EnterFirstScene(Ref* pSender)
{
	//跳转到第一个场景，记得包含第一个场景的头文件：MyFirstScene.h
	Director::getInstance()->replaceScene(TollgateScene::createScene());
}
void MyForthScene::EXIT(Ref* pSender)
{
	//点击退出
	Director::getInstance()->end();
}