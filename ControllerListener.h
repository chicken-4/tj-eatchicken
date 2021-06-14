#ifndef __ControllerListener_H__
#define __ControllerListener_H__

#include "cocos2d.h"
#include<string>
#include"myController.h"
using namespace cocos2d;

class ControllerListener
{
public:
	/*设置目标坐标*/
	virtual void setTagPosition(int x, int y) = 0;

	/*获取目标坐标*/
	virtual Point getTagPosition() = 0;
};

#endif
