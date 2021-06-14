#include "AIPlayer.h"

bool AIPlayer::init()
{
	this->scheduleUpdate();
	return true;
}

void AIPlayer::BindMonsters(std::vector<Monster*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecMonsters.push_back(sprites[i]);
	}
}

void AIPlayer::BindScene(cocos2d::Scene* scene)
{
	myScene = scene;
}

float AIPlayer::GetDistanceForAttack()
{
	return distanceForAttack;
}

Monster* AIPlayer::GetDistance()
{
	Monster* closestMonster = NULL;
	distanceFromMonster = 1000; //初始化 使其比所有的距离都远
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecMonsters.size(); i++) {
		offset = vecMonsters[i]->getPosition() - this->getPosition();
		if (distanceFromMonster > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
			distanceFromMonster = tempDistance;
			closestMonster = vecMonsters[i];//得到离得最近的怪物
		}
	}
	return closestMonster;
}

bool AIPlayer::isGoingToAttack()
{
	return distanceFromMonster <= distanceForAttack;
}

void AIPlayer::Move(Monster* monster)
{
	auto offset = monster->getPosition() - this->getPosition();
	auto destination = offset * speed / distanceFromMonster + this->getPosition();
	auto Action = cocos2d::MoveTo::create(0.5, destination);
	this->runAction(cocos2d::Sequence::create(Action, nullptr));
}

void AIPlayer::Attack(Monster* monster)
{
	//发射子弹
	if (shoot) {
		shoot = !shoot;

		//创建一个子弹
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto offset = monster->getPosition() - this->getPosition();
		auto destination = offset * distanceForAttack / distanceFromMonster + this->getPosition(); //射程为distanceFromAttack
		auto Move = cocos2d::MoveTo::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParent();
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //一秒（即动画完毕）后回收bullet内存

		auto changeShoot = [this](float) {
			shoot = !shoot;
		};
		this->scheduleOnce(changeShoot, 0.3, "changeShoot"); //每0.3秒发射一颗子弹
	}

	//小范围移动躲避敌人攻击
	if (moveWhenAttack) {
		moveWhenAttack = !moveWhenAttack;

		float random = CCRANDOM_0_1();
		if (random < 0.5) {
			auto moveRight = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(speed * 10, 0));
			auto moveLeft = cocos2d::MoveBy::create(1.0, cocos2d::Vec2(-speed * 20, 0));
			auto moveBack = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(speed * 10, 0));
			this->runAction(cocos2d::Sequence::create(moveRight, moveLeft, moveBack, nullptr));
		}
		else {
			auto moveUp = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, speed * 10));
			auto moveDown = cocos2d::MoveBy::create(1.0, cocos2d::Vec2(0, -speed * 20));
			auto moveBack = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, speed * 10));
			this->runAction(cocos2d::Sequence::create(moveUp, moveDown, moveBack, nullptr));
		}

		auto change = [this](float) {
			moveWhenAttack = !moveWhenAttack;
		};
		this->scheduleOnce(change, 2.0, "change"); //两秒（即动画完毕）后再来一次
	}
}

void AIPlayer::isHit()
{
	if (!isDead()) {
		//碰撞检测

		hp--;
	}
}

bool AIPlayer::isDead()
{
	if (hp <= 0) {
		return true;
	}
	return false;
}

void AIPlayer::update(float dt)
{
	if (isDead()) {
		this->removeFromParent();//这应该是直接销毁了？不知道要不要保留数据
	}
	Monster* closestMonster = GetDistance();
	if (isGoingToAttack()) {
		Attack(closestMonster);
	}
	else {
		Move(closestMonster);
	}
}