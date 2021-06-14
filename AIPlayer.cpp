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
	distanceFromMonster = 1000; //��ʼ�� ʹ������еľ��붼Զ
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecMonsters.size(); i++) {
		offset = vecMonsters[i]->getPosition() - this->getPosition();
		if (distanceFromMonster > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
			distanceFromMonster = tempDistance;
			closestMonster = vecMonsters[i];//�õ��������Ĺ���
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
	//�����ӵ�
	if (shoot) {
		shoot = !shoot;

		//����һ���ӵ�
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto offset = monster->getPosition() - this->getPosition();
		auto destination = offset * distanceForAttack / distanceFromMonster + this->getPosition(); //���ΪdistanceFromAttack
		auto Move = cocos2d::MoveTo::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParent();
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //һ�루��������ϣ������bullet�ڴ�

		auto changeShoot = [this](float) {
			shoot = !shoot;
		};
		this->scheduleOnce(changeShoot, 0.3, "changeShoot"); //ÿ0.3�뷢��һ���ӵ�
	}

	//С��Χ�ƶ���ܵ��˹���
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
		this->scheduleOnce(change, 2.0, "change"); //���루��������ϣ�������һ��
	}
}

void AIPlayer::isHit()
{
	if (!isDead()) {
		//��ײ���

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
		this->removeFromParent();//��Ӧ����ֱ�������ˣ���֪��Ҫ��Ҫ��������
	}
	Monster* closestMonster = GetDistance();
	if (isGoingToAttack()) {
		Attack(closestMonster);
	}
	else {
		Move(closestMonster);
	}
}