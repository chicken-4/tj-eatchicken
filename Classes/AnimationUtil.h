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
	static Animate* createWithSingleFrameName_bird1(int m_Image);
	static Animate* createWithSingleFrameName_bird2(int m_Image);
	static Animate* createWithSingleFrameName_bird3(int m_Image);
	static Animate* createWithSingleFrameName_bird4(int m_Image);
	static Animate* createWithSingleFrameName_monsterDuck();
	static Animate* createWithSingleFrameName_monster1();
	static Animate* createWithSingleFrameName_monsterGhost();

	/*�����ļ�����ǰ׺������������,ָ������ͼƬ����*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
private:
};

#endif
