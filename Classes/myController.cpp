#include "cocos2d.h"
#include<iostream>
#include"myController.h"

using namespace cocos2d;

USING_NS_CC;

void myController::setControllerListener(ControllerListener* controllerListener)
{
	this->m_controllerListener = controllerListener;
}
