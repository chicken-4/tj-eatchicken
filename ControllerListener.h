#ifndef __ControllerListener_H__
#define __ControllerListener_H__

#include "cocos2d.h"
#include<string>
#include"myController.h"
using namespace cocos2d;

class ControllerListener
{
public:
	/*����Ŀ������*/
	virtual void setTagPosition(int x, int y) = 0;

	/*��ȡĿ������*/
	virtual Point getTagPosition() = 0;
};

#endif
