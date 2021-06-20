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
	distanceFromPlayer = 100000; //��ʼ�� ʹ������еľ��붼Զ
	float tempDistance;
	cocos2d::Vec2 offset;
	for (int i = 0; i < vecPlayers.size(); i++) {
		if (vecPlayers[i]->GetVisible()) {
			offset = vecPlayers[i]->getPosition() - this->getPosition();
			if (distanceFromPlayer > (tempDistance = sqrt(offset.x * offset.x + offset.y * offset.y))) {
				distanceFromPlayer = tempDistance;
				closestPlayer = vecPlayers[i];//�õ������������
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
	//ûɶҪ�ɵ�
}

void Monster::Move(cocos2d::Sprite* player)
{
	auto offset = player->getPosition() - this->getPosition(); //�ӹ���λ��ָ�����
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
	this->runAction(Action); //�����ƶ�
}

void Monster::Avoid_brick(int direction) {
	i = direction;
}

void Monster::Attack(cocos2d::Sprite* player)
{
	if (shoot) {
		shoot = !shoot;

		//����һ���ӵ�
		auto bullet = Sprite::create("ball.png");
		bullet->setPosition(this->getPosition());
		myScene->addChild(bullet);

		auto Body = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		Body->setDynamic(false);
		Body->setContactTestBitmask(0xFFFFFFFF);
		bullet->setPhysicsBody(Body);
		bullet->setTag(MONSTER_BULLET_TAG);

		auto offset = player->getPosition() - this->getPosition(); //�ӹ���λ��ָ�����
		auto destination = offset * distanceForAttack / distanceFromPlayer; //���ΪdistanceFromAttack
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
	//���λ��
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
