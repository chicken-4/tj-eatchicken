#include "Monster.h"

bool Monster::init()
{
	this->scheduleUpdate();
	return true;
}

void Monster::BindPlayers(std::vector<Player*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecPlayers.push_back(sprites[i]);
	}
}

void Monster::BindAIPlayers(std::vector<AIPlayer*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecPlayers.push_back(sprites[i]);
	}
}

void Monster::BindScene(cocos2d::Scene* scene)
{
	myScene = scene;
}

void Monster::BindBackground(cocos2d::Sprite* sprite)
{
	background = sprite;
}

float Monster::GetDistanceForMove()
{
	return distanceForMove;
}

float Monster::GetDistanceForAttack()
{
	return distanceForAttack;
}

cocos2d::Sprite* Monster::GetDistance()
{
	cocos2d::Sprite* closestPlayer = NULL;
	distanceFromPlayer = 100000; //初始化 使其比所有的距离都远
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecPlayers.size(); i++) {
		if (vecPlayers[i]->GetVisible()) {
			offset = vecPlayers[i]->getPosition() - this->getPosition();
			if (distanceFromPlayer > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
				distanceFromPlayer = tempDistance;
				closestPlayer = vecPlayers[i];//得到离得最近的玩家
			}
		}
	}
	return closestPlayer;
}

bool Monster::isGoingToMove()
{
	return distanceFromPlayer > distanceForAttack && distanceFromPlayer <= distanceForMove;
}

bool Monster::isGoingToAttack()
{
	return distanceFromPlayer <= distanceForAttack;
}

void Monster::Wait()
{
	//没啥要干的
}

void Monster::Move(cocos2d::Sprite* player)
{
	auto offset = player->getPosition() - this->getPosition(); //从怪物位置指向玩家
	if (stop) {
		if (i == 1) {
			offset = Vec2(2*offset.x,0);
		}
		else if (i == 0) {
			offset = Vec2(0, 2*offset.y);
		}
		
	}
	auto destination = offset * speed / distanceFromPlayer;
	auto Action = cocos2d::MoveBy::create(0.5, destination);
	this->runAction(Action); //怪物移动
}

void Monster::Avoid_brick(int direction) {
	i = direction;
}

void Monster::Attack(cocos2d::Sprite* player)
{
	if (shoot) {
		shoot = !shoot;

		//创建一个子弹
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto Body = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		bullet->setPhysicsBody(Body);
		bullet->setTag(MONSTER_BULLET_TAG);

		auto offset = player->getPosition() - this->getPosition(); //从怪物位置指向玩家
		auto destination = offset * distanceForAttack / distanceFromPlayer; //射程为distanceFromAttack
		auto Move = cocos2d::MoveBy::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParentAndCleanup(true);
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //一秒（即动画完毕）后回收bullet内存

		auto changeShoot = [this](float) {
			shoot = !shoot;
		};
		this->scheduleOnce(changeShoot, 0.3, "changeShoot"); //每0.3秒发射一颗子弹
	}
}

void Monster::Stop(const bool flag)
{
	stop = flag;
	if (flag) {
		stopAllActions();

	}
}

void Monster::Reset()
{
	//随机位置
	background = Sprite::create("startpage.png");
	background->setPosition(background->getContentSize().width / 2 + 25, background->getContentSize().height / 2);
	setPosition(Vec2(CCRANDOM_0_1() * (background->getContentSize().width - 200) + 100, CCRANDOM_0_1() * (background->getContentSize().height - 200) + 100));
}

void Monster::isHit()
{
	if (!isDead()) {
		hp--;
	}
}

bool Monster::isDead()
{
	if (0 >= hp) {
		hp = MONSTER_HP;
		Reset();
		return true;
	}
	return false;
}

void Monster::update(float dt)
{
	cocos2d::Sprite* closestPlayer = GetDistance();
	if (closestPlayer != NULL&&isGoingToMove()) {
		Move(closestPlayer);
	}
	else if (closestPlayer != NULL&&isGoingToAttack()) {
		Attack(closestPlayer);
	}
	else {
		Wait();
	}
}
