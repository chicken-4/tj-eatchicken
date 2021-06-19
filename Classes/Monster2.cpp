#include "Monster2.h"

bool MonsterDuck::init()
{
	createMissiles();
	this->scheduleUpdate();
	return true;
}

void MonsterDuck::createMissiles()
{
	Missile* missile = NULL;
	for (int i = 0; i < PLAYER_AMOUNT; i++) {
		missile = Missile::create();
		missile->bindSprite(cocos2d::Sprite::create("missile.png"));
		vecMissiles.push_back(missile);

		auto Body = PhysicsBody::createBox(vecMissiles[i]->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		vecMissiles[i]->setPhysicsBody(Body);
		vecMissiles[i]->setTag(MISSILE_TAG + i);
		mapMissileTag.insert(std::pair<int, Missile*>(MISSILE_TAG + i, vecMissiles[i]));
	}
}

void MonsterDuck::BindPlayers(std::vector<Player*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecTargets.push_back(sprites[i]);
	}
}

void MonsterDuck::BindAIPlayers(std::vector<AIPlayer*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecTargets.push_back(sprites[i]);
	}
}

void MonsterDuck::BindScene(cocos2d::Scene* scene)
{
	myScene = scene;
}

void MonsterDuck::BindBackground(cocos2d::Sprite* sprite)
{
	background = sprite;
}

void MonsterDuck::SetMissiles()
{
	for (int i = 0; i < vecMissiles.size(); i++) {
		vecMissiles[i]->BindTarget(vecTargets[i]);
		vecMissiles[i]->BindDuck(this);
		vecMissiles[i]->setPosition(background->getContentSize() / 2);
		myScene->addChild(vecMissiles[i]);
	}
}

void MonsterDuck::isHit()
{
	if (!isDead()) {
		hp--;
	}
}

bool MonsterDuck::isDead()
{
	//不会清内存 直接移远
	if (0 >= hp) {
		for (int i = 0; i < vecMissiles.size(); i++) {
			vecMissiles[i]->setPosition(10000, 10000);
		}
		this->setPosition(10000, 10000);
		return true;
	}
	return false;
}

std::vector<Missile*> MonsterDuck::GetMissiles()
{
	return vecMissiles;
}

std::map<int, Missile*> MonsterDuck::GetMapMissile()
{
	return mapMissileTag;
}

/////////////////////////////

bool Missile::init()
{
	this->scheduleUpdate();
	return true;
}

void Missile::BindTarget(cocos2d::Sprite* sprite)
{
	target = sprite;
}

void Missile::BindDuck(MonsterDuck* duck)
{
	myDuck = duck;
}

void Missile::Move()
{
	if (inUse && target != NULL) {
		auto offset = target->getPosition() - this->getPosition(); //指向玩家
		offset.normalize();
		auto destination = offset * speed;
		auto Action = cocos2d::MoveBy::create(0.5, destination);
		this->runAction(Action);
	}
}

void Missile::Reset()
{
	inUse = false;
	this->setPosition(myDuck->getPosition());
	auto change = [this](float) {
		inUse = !inUse;
	};
	this->scheduleOnce(change, 5, "change"); //每5秒发射一颗子弹
}

void Missile::update(float dt)
{
	Move();
}
