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

	/*�����ƶ��ٶ�*/
	void setXSpeed(int iSpeed);

	void setYSpeed(int iSpeed);

	/*ע������¼�*/
	
		//��HelloWorldScene.hͷ�ļ�����д���̰��µ��ص���������
	virtual void onKeyPressed(EventKeyboard::KeyCode keycode, Event * event);
	virtual int onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
	//int registeTouchEvent();
private:
	int m_iXSpeed;
	int m_iYSpeed;

};


#endif
