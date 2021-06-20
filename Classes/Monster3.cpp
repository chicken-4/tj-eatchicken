#include "Monster3.h"

bool Ghost::init()
{
	myPoint = Node::create();
	this->scheduleUpdate();
	return true;
}

void Ghost::BindPlayers(std::vector<Player*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecPlayers.push_back(sprites[i]);
	}
}

void Ghost::BindAIPlayers(std::vector<AIPlayer*> sprites)
{
	for (int i = 0; i < sprites.size(); i++) {
		vecPlayers.push_back(sprites[i]);
	}
}

float Ghost::GetDistanceForMove()
{
	return distanceForMove;
}

cocos2d::Sprite* Ghost::GetDistance()
{
	cocos2d::Sprite* closestPlayer = NULL;
	distanceFromPlayer = 100000; //��ʼ�� ʹ������еľ��붼Զ
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecPlayers.size(); i++) {
		if (vecPlayers[i]->GetVisible()) {
			offset = vecPlayers[i]->getPosition() - myPoint->getPosition();
			if (distanceFromPlayer > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
				distanceFromPlayer = tempDistance;
				closestPlayer = vecPlayers[i];//�õ������������
			}
		}
	}
	return closestPlayer;
}

bool Ghost::isGoingToMove()
{
	return distanceFromPlayer <= distanceForMove;
}

void Ghost::Wait()
{
	auto offset = myPoint->getPosition() - this->getPosition(); //�ص��ݵ�
	auto destination = offset * speed / 100;
	auto Action = cocos2d::MoveBy::create(0.2, destination);
	this->runAction(Action); //�ƶ�
}

void Ghost::Move(cocos2d::Sprite* player)
{
	auto offset = player->getPosition() - this->getPosition();
	auto destination = offset * speed / distanceFromPlayer;
	auto Action = cocos2d::MoveBy::create(0.2, destination);
	this->runAction(Action);
}

void Ghost::update(float dt)
{
	cocos2d::Sprite* closestPlayer = GetDistance();
	if (closestPlayer != NULL && isGoingToMove()) {
		Move(closestPlayer);
	}
	else {
		Wait();
	}
}
