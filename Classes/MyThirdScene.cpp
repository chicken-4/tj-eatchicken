#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"

//�������л�������ͼ���������������
//��ʼ��������tollgatescene
Scene* MyThirdScene::createScene()
{
	Scene* scene = Scene::create();
	MyThirdScene* layer = MyThirdScene::create();
	scene->addChild(layer);
	return scene;
}
void MyThirdScene::EnterFirstScene(Ref* pSender)
{
	//��ת�������棬�ǵð�����һ��������ͷ�ļ���MyFirstScene.h
	
	Director::getInstance()->replaceScene(TollgateScene::createScene());
}
void MyThirdScene::EnterSecondScene(Ref* pSender)
{
	//��ת������ͼ���ǵð�����һ��������ͷ�ļ���MyFirstScene.h
	Director::getInstance()->replaceScene(MySecondScene::createScene(0));
}
void MyThirdScene::EXIT(Ref* pSender)
{
	//����˳�
	Director::getInstance()->end();
}
/*void something()
{
	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* keyListener = EventListenerKeyboard::create();
	//����һ���¼����������������¼�
	keyListener->onKeyPressed = CC_CALLBACK_2(MySecondScene::onKeyPressed, this);
	//���̱�����ʱ��Ӧ
	keyListener->onKeyReleased = CC_CALLBACK_2(MySecondScene::onKeyReleased, this);
	//���̰���������ʱ��Ӧ
	dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}*/
