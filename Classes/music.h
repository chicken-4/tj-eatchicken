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


    //Text* m_scorelab;    //������ǩ
    //LoadingBar m_hpbar; //Ѫ����


};

#endif
