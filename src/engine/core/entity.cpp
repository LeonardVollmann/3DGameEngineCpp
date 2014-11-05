#include "entity.h"

Entity::Entity(const Transform &transform) :
	m_transform(transform) {}

void Entity::addChild(Entity *child)
{
	child->setEngine(m_engine);
	m_children.push_back(child);
}

void Entity::processInputAll()
{
	for (Entity *child : m_children) {
		child->processInputAll();
	}

	processInput();
}

void Entity::updateAll()
{
	for (Entity *child : m_children) {
		child->updateAll();
	}

	update();
}

void Entity::renderAll()
{
	for (Entity *child : m_children) {
		child->renderAll();
	}
	
	render();
}

void Entity::setEngine(CoreEngine *engine)
{
	for (Entity *child : m_children) {
		child->setEngine(engine);
	}

	m_engine = engine;
}
