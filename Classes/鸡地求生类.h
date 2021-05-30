/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

 // HelloWorldScene.h
//cocos2dx最重要的三个类：
/*
Ref:引擎的基类，自动释放内存
Node：日常所需的大部分功能
Layer：继承自node，拥有更多功能*/

/*class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);//一个回调函数（关闭按钮回调函数

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);//一个宏（一种预编译手段
    void addMonster(float dt);
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

    //HelloWorldScene.h
private:
    cocos2d::Sprite* _player;
    cocos2d::Sprite* projectile;
};*/

//Sound类，用来存放游戏中各种声音，包括背景音乐和游戏音效
class Sound
{
public:
private:

};
//枪支（攻击类装备
/*
武器 （抽象）
显示属性
被拿起、放下
攻击（分开为远程武器、近战武器两个⼦类）
biubiu
⼦弹（也要⾃成⼀类吗？）
砍击
响应增益或减益*/
class Weapon
{
public:
private:

};
//防御类装备
/*思路：if(玩家穿着盔甲)，伤害减小*/
class qiangzhi
{
public:
private:

};
//药品类装备
class Medicine
{
public:
private:

};
/*场景，包括游戏地图，
登录界面，
背包，
房间（联机暂时不写），
积分排行榜，
游戏之间的衔接场景
* */
class Map
{
public:
private:

};
//玩家
/*
⾎/防/蓝（或是其它参数）
移动
技能（获取、改写和使⽤，⼀个类？）
buff / debuff （永久的和暂时的）
拿起/放下武器
启动武器
与其他物品交互、查看物品
被击中*/
class Player
{
public:
private:
    cocos2d::Sprite* _player;
};
//怪物
/*
运动：1、降落伞从天而降 2、到地面后降落伞消失，走动
3、会简单移动（向游戏玩家靠近或远离）
攻击
不同等级（小怪、大怪）*/
class Monster
{
public:
    //物理
    
private:
    cocos2d::Sprite* _monster;
};
//道具
/*
道具
被拾起
作⽤*/
class daojur
{
public:
private:

};
/*
增/减益 （？）
技能产⽣的效果也是⼀种增益
状态和⾏为？
*/
class qiangzhi
{
public:
private:

};
/*
⼦弹 （抽象）
在武器中创建实例，定义的时候可以跟武器⼀起（？）
速度
伤害
碰撞体积
效果*/
class qiangzhi
{
public:
private:

};
/*
* 箱⼦？⽊块？墙？
* 在地图中会阻止人物运动
*/
class qiangzhi
{
public:
private:

};
#endif // __HELLOWORLD_SCENE_H__
#pragma once
