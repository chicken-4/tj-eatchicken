/*实体基类*/
#pragma once

#ifndef __Entity_H__
#define __Entity_H__

#include"cocos2d.h"
USING_NS_CC;

class Entity :public cocos2d::Sprite {
public:
	virtual bool init();
	CREATE_FUNC(Entity);

	void bindSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite();

	bool GetVisible();
	void SetVisible(const bool flag);

private:
	cocos2d::Sprite* m_sprite;
	bool visible = true;
};

#endif

