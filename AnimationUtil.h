
#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__

#include"cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

class AnimationUtil
{
public:
	/*�����ļ�����ǰ׺������������*/
	static Animation* createWithSingleFrameName(int i,float delay, int iLoops);

	/*�����ļ�����ǰ׺������������,ָ������ͼƬ����*/
	//static Animation* createWithSingleFrameNameAndNum(const char* name, int num,float delay, int iLoops);
};

#endif
