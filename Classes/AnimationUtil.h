#pragma once

#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__

#include"cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

class AnimationUtil
{
public:
	/*根据文件名字前缀创建动画对象*/
	static Animate* createWithSingleFrameName_bird1(int m_Image);
	static Animate* createWithSingleFrameName_bird2(int m_Image);
	static Animate* createWithSingleFrameName_bird3(int m_Image);
	static Animate* createWithSingleFrameName_bird4(int m_Image);
	static Animate* createWithSingleFrameName_monsterDuck();
	static Animate* createWithSingleFrameName_monster1();
	static Animate* createWithSingleFrameName_monsterGhost();

	/*根据文件名字前缀创建动画对象,指定动画图片数量*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
private:
};

#endif
