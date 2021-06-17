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
	static Animate* createWithSingleFrameName_1();
	static Animate* createWithSingleFrameName_2();
	static Animate* createWithSingleFrameName_3();
	static Animate* createWithSingleFrameName_4();

	/*根据文件名字前缀创建动画对象,指定动画图片数量*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
private:
	Animate*animate1;
	Animate*animate2;
	Animate*animate3;
	Animate*animate4;
};

#endif
