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
	distanceFromPlayer = 1000; //��ʼ�� ʹ������еľ��붼Զ
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecPlayers.size(); i++) {
		offset = vecPlayers[i]->getPosition() - this->getPosition();
		if (distanceFromPlayer > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
			distanceFromPlayer = tempDistance;
			closestPlayer = vecPlayers[i];//�õ������������
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
	//ûɶҪ�ɵ�
}

void Monster::Move(cocos2d::Sprite* player)
{
	auto offset = player->getPosition() - this->getPosition(); //�ӹ���λ��ָ�����
	auto destination = offset * speed / distanceFromPlayer + this->getPosition(); //�ӵ�����λ�ã���Ŀ��λ��
	auto Action = cocos2d::MoveTo::create(0.5, destination);
	this->runAction(cocos2d::Sequence::create(Action, nullptr)); //�����ƶ�
}

void Monster::Attack(cocos2d::Sprite* player)
{
	//count�����ӵ���������ÿ50֡��
	if (count >= shootGap) {
		count = 0; //����
		//����һ���ӵ�
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto offset = player->getPosition() - this->getPosition(); //�ӹ���λ��ָ�����
		auto destination = offset * distanceForAttack / distanceFromPlayer + this->getPosition(); //���ΪdistanceFromAttack
		auto Move = cocos2d::MoveTo::create(1.0, destination);
		auto Remove = cocos2d::RemoveSelf::create();
		bullet->runAction(cocos2d::Sequence::create(Move, Remove, nullptr));
		auto disappear = [this, bullet](float) {
			bullet->removeFromParent();
		};
		bullet->scheduleOnce(disappear, 1.0, "disappear"); //һ�루��������ϣ������bullet�ڴ�
	}
	else {
		count++;
	}
}


void Monster::Reset()
{
	//���λ��
	float minX = getContentSize().width, minY = getContentSize().height;
	float maxX = 480 - minX, maxY = 320 - minY; //���ڴ�С���Ǻ궨���
	float randomX = (rand() % static_cast<int>(maxX - minX)) + rand() / static_cast<float>(maxX) + minX;
	float randomY = (rand() % static_cast<int>(maxY - minY)) + rand() / static_cast<float>(maxY) + minY;
	setPosition(randomX, randomY);
}

void Monster::isHit()
{
	if (!isDead()) {
		//��ײ���

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
	//	srand((unsigned)time(NULL)); ����ai���ʱ������
	Monster* monster = NULL;
	for (int i = 0; i < MONSTER_AMOUNT; i++) {
		monster = Monster::create();
		monster->bindSprite(cocos2d::Sprite::create("5.png"));
		monster->Reset(); //�������
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