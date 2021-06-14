
#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__

#include"cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

class AnimationUtil
{
public:
	/*根据文件名字前缀创建动画对象*/
	static Animation* createWithSingleFrameName(int i,float delay, int iLoops);

	/*根据文件名字前缀创建动画对象,指定动画图片数量*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
};

#endif
