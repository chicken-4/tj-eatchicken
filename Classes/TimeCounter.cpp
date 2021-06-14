#include "TimeCounter.h"

bool Clock::init()
{
	//	this->schedule(schedule_selector(Clock::TimeUpdate),1.0f); //schedule_selectorδ���壬˭����
	auto print = [this](float) {
		this->PrintTime();
	};
	this->schedule(print, 1.0, "print");
	return true;
}

void Clock::BindLabel(cocos2d::Label* label)
{
	timeLabel = label;
	this->addChild(timeLabel);
}

void Clock::PrintTime()
{
	if (time > 0) {
		time--; //����ʱ
		timeLabel->setString((cocos2d::StringUtils::format("TimeLeft : %2d:%2d", time / 60, time % 60)));
	}
	else {
		//����
	}
}