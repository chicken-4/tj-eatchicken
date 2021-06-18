#include "Monster.h"

bool Monster::init()
{
	count = 0;
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
	distanceFromPlayer = 1000; //初始化 使其比所有的距离都远
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecPlayers.size(); i++) {
		offset = vecPlayers[i]->getPosition() - this->getPosition();
		if (distanceFromPlayer > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
			distanceFromPlayer = tempDistance;
			closestPlayer = vecPlayers[i];//得到离得最近的玩家
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

void Monster::Wait(cocos2d::Sprite* player)
{
	//没啥要干的
}

void Monster::Move(cocos2d::Sprite* player)
{
	auto offset = player->getPosition() - this->getPosition(); //从怪物位置指向玩家
	auto destination = offset * speed / distanceFromPlayer + this->getPosition(); //加到怪物位置，得目标位置
	auto Action = cocos2d::MoveTo::create(0.5, destination);
	this->runAction(cocos2d::Sequence::create(Action, nullptr)); //怪物移动
}

void Monster::Attack(cocos2d::Sprite* player)
{
	//count控制子弹发射间隔（每50帧）
	if (count >= shootGap) {
		count = 0; //重置
		//创建一个子弹
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto offset = player->getPosition() - this->getPosition(); //从怪物位置指向玩家
		auto destination = offset * distanceForAttack / distanceFromPlayer + this->getPosition(); //射程为distanceFromAttack
		auto Move = cocos2d::MoveTo::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParent();
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //一秒（即动画完毕）后回收bullet内存
	}
	else {
		count++;
	}
}


void Monster::Reset()
{
	//随机位置
	float minX = getContentSize().width, minY = getContentSize().height;
	float maxX = 480 - minX, maxY = 320 - minY; //窗口大小还是宏定义吧
	float randomX = (rand() % static_cast<int>(maxX - minX)) + rand() / static_cast<float>(maxX) + minX;
	float randomY = (rand() % static_cast<int>(maxY - minY)) + rand() / static_cast<float>(maxY) + minY;
	setPosition(randomX, randomY);
}

void Monster::isHit()
{
	if (!isDead()) {
		//碰撞检测

		hp--;
	}
}

bool Monster::isDead()
{
	if (0 >= hp) {
		hp = MONSTER_HP;
		return true;
	}
	return false;
}

void Monster::update(float dt)
{
	if (isDead()) {
		Reset();
	}
	cocos2d::Sprite* closestPlayer = GetDistance();
	if (isGoingToMove()) {
		Move(closestPlayer);
	}
	else if (isGoingToAttack()) {
		Attack(closestPlayer);
	}
	else {
		Wait(closestPlayer);
	}
}

/////////////////////////////////////////

bool MonsterManager::init()
{
	createMonsters();
	this->scheduleUpdate();
	return true;
}

void MonsterManager::createMonsters()
{
	//	srand((unsigned)time(NULL)); 创建ai玩家时调用了
	Monster* monster = NULL;
	for (int i = 0; i < MONSTER_AMOUNT; i++) {
		monster = Monster::create();
		monster->bindSprite(cocos2d::Sprite::create("5.png"));
		monster->Reset(); //随机坐标
		this->addChild(monster);
		vecMonsters.push_back(monster);
	}
}

void MonsterManager::BindPlayers(std::vector<Player*> sprites)
{
	for (int i = 0; i < vecMonsters.size(); i++) {
		vecMonsters[i]->BindPlayers(sprites);
	}
}

void MonsterManager::BindAIPlayers(std::vector<AIPlayer*> sprites)
{
	for (int i = 0; i < vecMonsters.size(); i++) {
		vecMonsters[i]->BindAIPlayers(sprites);
	}
}

void MonsterManager::BindScene(cocos2d::Scene* scene)
{
	for (int i = 0; i < vecMonsters.size(); i++) {
		vecMonsters[i]->BindScene(scene);
	}
}

std::vector<Monster*> MonsterManager::GetVecMonsters() {
	return vecMonsters;
}