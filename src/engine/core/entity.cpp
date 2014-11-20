/*
 * Copyright (c) 2014 Leonard Vollmann
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "entity.h"
#include "component.h"

Entity::~Entity()
{
	for (unsigned int i = 0; i < m_children.size(); i++) {
		if (m_children[i] != nullptr) {
			delete m_children[i];
		}
	}

	for (unsigned int i = 0; i < m_components.size(); i++) {
		if (m_components[i] != nullptr) {
			delete m_components[i];
		}
	}
}

Entity *Entity::addChild(Entity *child)
{
	child->setEngine(m_engine);
	m_children.push_back(child);

	return this;
}

Entity *Entity::addComponent(Component *component)
{
	component->setEngine(m_engine);
	component->setParent(this);
	m_components.push_back(component);

	return this;
}

void Entity::processInputAll(const Input &input)
{
	for (Entity *child : m_children) {
		child->processInputAll(input);
	}

	for (Component *component : m_components) {
		component->processInput(input);
	}
	
	processInput(input);
}

void Entity::updateAll(float delta)
{
	for (Entity *child : m_children) {
		child->updateAll(delta);
	}

	for (Component *component : m_components) {
		component->update(delta);
	}

	update(delta);
}

void Entity::renderAll(const Shader &shader, const RenderingEngine &renderingEngine, const Camera &camera) const
{
	for (Entity *child : m_children) {
		child->renderAll(shader, renderingEngine, camera);
	}

	for (Component *component : m_components) {
		component->render(shader, renderingEngine, camera);
	}
	
	render();
}

void Entity::setEngine(CoreEngine *engine)
{
	for (Entity *child : m_children) {
		child->setEngine(engine);
	}

	for (Component *component : m_components) {
		component->setEngine(engine);
	}

	m_engine = engine;
}