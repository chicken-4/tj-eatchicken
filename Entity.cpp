#include"Player.h"
#include"Entity.h"
#include"myController.h"
/*Entity::Entity()
{
	m_sprite = NULL;
}
Entity::~Entity()
{

}*/
Sprite* Entity::getSprite()
{
	return this->m_sprite;
	this->addChild(m_sprite);
}
void Entity::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}
/*void Entity::setController(myController* controller)
{
	this->m_controller = controller;
	m_controller->setControllerListener(this);
}
void Entity::setTagPosition(int x, int y)
{
	setPosition(Point(x, y));
}
Point Entity::getTagPosition()
{
	return getPosition();
}*/