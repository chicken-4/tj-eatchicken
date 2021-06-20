#ifndef __Controller_H__
#define __Controller_H__

#include "cocos2d.h"
#include<string>
#include"ControllerListener.h"
using namespace cocos2d; 

class myController :public Node
{
public:
	/*ÉèÖÃ¼àÌı¶ÔÏó*/
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
};
#endif
