#include "cocos2d.h"
#include<iostream>
#include"myController.h"
#include"ControllerListener.h"
#include"SimpleMoveController.h"
#include"TollgateScene.h"

using namespace cocos2d;

USING_NS_CC;

bool SimpleMoveController::init()
{
	this->m_iXSpeed = 0;
	this->m_iYSpeed = 0;

	

	/*开启update函数调用*/
	this->scheduleUpdate();

	return true;
}

void SimpleMoveController::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}
	/*增加移动对象的x坐标值和Y坐标值*/
	Point curPos = m_controllerListener->getTagPosition();
	curPos.x += m_iXSpeed;
	curPos.y += m_iYSpeed;
	m_controllerListener->setTagPosition(curPos.x+m_iXSpeed, curPos.y + m_iYSpeed);
}

void SimpleMoveController::setXSpeed(int iSpeed)
{
	this->m_iXSpeed = iSpeed;
}

void SimpleMoveController::setYSpeed(int iSpeed)
{
	this->m_iYSpeed = iSpeed;
}

//监听键盘事件
void SimpleMoveController::onKeyPressed(EventKeyboard::KeyCode keycode, Event* event)
{
	


}
int SimpleMoveController::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
	return 0;
}