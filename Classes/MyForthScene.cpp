#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"SceneManage.h"

//�������л�������ͼ���������������
//��ʼ��������tollgatescene

Scene* MyForthScene::createScene()
{
	Scene* scene = Scene::create();
	MyForthScene* layer = MyForthScene::create();
	scene->addChild(layer);
	return scene;
}
void MyForthScene::EnterFirstScene(Ref* pSender)
{
	//��ת����һ���������ǵð�����һ��������ͷ�ļ���MyFirstScene.h
	Director::getInstance()->replaceScene(TollgateScene::createScene());
}
void MyForthScene::EXIT(Ref* pSender)
{
	//����˳�
	Director::getInstance()->end();
}