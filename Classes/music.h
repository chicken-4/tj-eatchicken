#pragma once

#ifndef __music_H__
#define __music_H__

#include"Entity.h"
#include<string>
using namespace cocos2d;

class music :public Entity
{
public:
    CREATE_FUNC(music);
    virtual bool initMusic();

private:


    //Text* m_scorelab;    //分数标签
    //LoadingBar m_hpbar; //血量条


};

#endif
