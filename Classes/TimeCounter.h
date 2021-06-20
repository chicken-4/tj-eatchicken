#pragma once

/*  使用：
	//倒计时
	auto time = Clock::create();
	time->BindLabel(Label::create());
	time->setScale(//);
	time->setColor(//);
	time->setPosition(//);
	this->addChild(time);
*/

#ifndef __TIMECOUNTER_H__
#define __TIMECOUNTER_H__

#include "cocos2d.h"

class Clock :public cocos2d::Node {
public:
	virtual bool init();
	CREATE_FUNC(Clock);
	int time = 600; //一局游戏的时长（秒）

	void BindLabel(cocos2d::Label* label);
	void PrintTime();
	//	void TimeUpdate(float dt);
private:
	
	cocos2d::Label* timeLabel;
};

#endif