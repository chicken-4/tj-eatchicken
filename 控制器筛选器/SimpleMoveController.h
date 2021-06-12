#ifndef __SingleMoveController_H__
#define __SingleMoveController_H__

#include "cocos2d.h"
#include<string>
#include"myController.h"
#include"ControllerListener.h"
using namespace cocos2d; 

class SimpleMoveController : public myController
{
public:
	CREATE_FUNC(SimpleMoveController);
	virtual bool init();
	virtual void update(float dt);

	/*设置移动速度*/
	void setXSpeed(int iSpeed);

	void setYSpeed(int iSpeed);

	/*注册键盘事件*/
	
		//在HelloWorldScene.h头文件中重写键盘按下弹回的两个方法
	virtual void onKeyPressed(EventKeyboard::KeyCode keycode, Event * event);
	virtual int onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
	//int registeTouchEvent();
private:
	int m_iXSpeed;
	int m_iYSpeed;

};


#endif
