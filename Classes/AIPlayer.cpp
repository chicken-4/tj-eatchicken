#include "AIPlayer.h"
#include"AnimationUtil.h"

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

void AIPlayer::SetNum(const int i)
{
	num = i;
}

float AIPlayer::GetDistanceForAttack()
{
	return distanceForAttack;
}

Monster* AIPlayer::GetDistance()
{
	Monster* closestMonster = NULL;
	distanceFromMonster = 100000; //��ʼ�� ʹ������еľ��붼Զ
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

void AIPlayer::Wait()
{

}

void AIPlayer::Move(Monster* monster)
{
	auto offset = monster->getPosition() - this->getPosition();
	if (stop) {
		if (i == 1) {
			offset = Vec2(2 * offset.x, 0);
		}
		else if (i == 0) {
			offset = Vec2(0, 2 * offset.y);
		}
	}
	auto destination = offset * speed / distanceFromMonster;
	auto Action = cocos2d::MoveBy::create(0.5, destination);
	this->runAction(Action);
}

void AIPlayer::Avoid_brick(int direction) {
	i = direction;
}

void AIPlayer::Attack(Monster* monster)
{
	//�����ӵ�
	if (shoot) {
		shoot = !shoot;

		//����һ���ӵ�
		auto bullet = Sprite::create("bullet1.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto Body = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		bullet->setPhysicsBody(Body);
		bullet->setTag(AIPLAYER_BULLET_TAG + num); //���ձ���䱸�ӵ�

		auto offset = monster->getPosition() - this->getPosition();
		float radians = atan2(offset.y, -offset.x);
		float degree = CC_RADIANS_TO_DEGREES(radians);
		bullet->setRotation(degree);

		auto destination = offset * distanceForAttack / distanceFromMonster; //���ΪdistanceFromAttack
		auto Move = cocos2d::MoveBy::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParentAndCleanup(true);
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //һ�루��������ϣ������bullet�ڴ�

		auto changeShoot = [this](float) {
			shoot = !shoot;
		};
		this->scheduleOnce(changeShoot, 0.3, "changeShoot"); //ÿ0.3�뷢��һ���ӵ�
	}

	if (!stop) {
		//С��Χ�ƶ���ܵ��˹���
		if (moveWhenAttack) {
			moveWhenAttack = !moveWhenAttack;

			float random = CCRANDOM_0_1();
			if (random < 0.5) {
				auto moveRight = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(speed * 30, 0));
				auto moveLeft = cocos2d::MoveBy::create(1.0, cocos2d::Vec2(-speed * 60, 0));
				auto moveBack = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(speed * 30, 0));
				this->runAction(cocos2d::Sequence::create(moveRight, moveLeft, moveBack, nullptr));
			}
			else {
				auto moveUp = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, speed * 30));
				auto moveDown = cocos2d::MoveBy::create(1.0, cocos2d::Vec2(0, -speed * 60));
				auto moveBack = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, speed * 30));
				this->runAction(cocos2d::Sequence::create(moveUp, moveDown, moveBack, nullptr));
			}

			auto change = [this](float) {
				moveWhenAttack = !moveWhenAttack;
			};
			this->scheduleOnce(change, 2.0, "change"); //���루��������ϣ�������һ��
		}
	}
}

void AIPlayer::Stop(const bool flag)
{
	stop = flag;
	if (flag) {
		stopAllActions();
	}
}


void AIPlayer::GetScore()
{
	score++;
}

void AIPlayer::isHit()
{
	if (!isDead()) {
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
		this->setPosition(100000, 100000); //�Ƶ���Զ�ĵط�������֮��ķ���
	}
	else {
		Monster* closestMonster = GetDistance();
		if (closestMonster != NULL) {
			if (isGoingToAttack()) {
				Attack(closestMonster);
			}
			else {
				Move(closestMonster);
			}
		}
	}
}

int AIPlayer::queryscore()
{
	return score;
}