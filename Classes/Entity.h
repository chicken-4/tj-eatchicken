/*实体基类*/
#pragma once

#ifndef __Entity_H__
#define __Entity_H__

#include"cocos2d.h"
//#include"MyController.h"
USING_NS_CC;

class Entity :public cocos2d::Sprite {
public:
	virtual bool init();
	CREATE_FUNC(Entity);

	void bindSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite();

private:
	cocos2d::Sprite* m_sprite;
};


#if 0
class Entity :public Node, public ControllerListener
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();//接口，获取精灵变量的值
	void bindSprite(Sprite* sprite);//接口，改变精灵变量的值
	/*设置控制器*/
	void setController(myController* controller);
	/*实现SimpleMoveListener接口的方法*/
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();

protected:
	Sprite* m_sprite;
	myController* m_controller;

};
#endif

#endif

