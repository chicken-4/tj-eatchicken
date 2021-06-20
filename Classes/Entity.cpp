#include"Entity.h"

bool Entity::init()
{
	return true;
}

Sprite* Entity::getSprite()
{
	return this->m_sprite;
}

void Entity::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);

	Size size = m_sprite->getContentSize();
	m_sprite->setPosition(Vec2(size.width / 2, size.height / 2));
	this->setContentSize(size);
}
