#pragma once

#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__

#include"cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

class AnimationUtil
{
public:
	/*�����ļ�����ǰ׺������������*/
	static Animate* createWithSingleFrameName_1();
	static Animate* createWithSingleFrameName_2();
	static Animate* createWithSingleFrameName_3();
	static Animate* createWithSingleFrameName_4();

	/*�����ļ�����ǰ׺������������,ָ������ͼƬ����*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
private:
	Animate*animate1;
	Animate*animate2;
	Animate*animate3;
	Animate*animate4;
};

#endif
