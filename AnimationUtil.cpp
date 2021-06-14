#include "cocos2d.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"AnimationUtil.h"

using namespace std;

Animation* AnimationUtil::createWithSingleFrameName(int i,float delay, int iLoops)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	SpriteFrame* frame = NULL;// cache->getSpriteFrameByName(StringUtils::format("C:\\Cocos\\POBG\\HelloWorld\\Resources\\11.png"));//cache->getSpriteFrameByName("C:\\Cocos\\POBG\\HelloWorld\\Resources\\11.png");
	Vector<SpriteFrame*>frameVec;
	int index = 1;
	do
	{
		frame = cache->getSpriteFrameByName(StringUtils::format("%d%d.png",i,index));
		index++;
		/*���ϵػ�ȡSpriteFrame����ֱ����ȡ��ֵΪNULLΪֹ*/
		if (frame == NULL)
		{
			break;
		}
		frameVec.pushBack(frame);
	} while (true);
	//PrintLog(&frame);
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	//animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);

	return animation;
}

USING_NS_CC;