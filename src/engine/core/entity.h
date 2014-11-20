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

#ifndef ENTITY_H
#define ENTITY_H

#include "transform.h"
//#include "core_engine.h"
#include "input.h"
// #include "component.h"
//#include "../rendering/rendering_engine.h"
//#include "../rendering/shader.h"

#include <vector>

class CoreEngine;
class RenderingEngine;
class Shader;
class Camera;
class Component;

class Entity
{
public:
	Entity(const Transform &transform = Transform()) :
		m_transform(transform) {}

    virtual ~Entity();

	void processInputAll(const Input &input);
	void updateAll(float delta);
	void renderAll(const Shader &shader, const RenderingEngine &renderingEngine, const Camera &camera) const;

	Entity *addChild(Entity *child);
	Entity *addComponent(Component *component);

	void setEngine(CoreEngine *engine);

	inline const Transform &getTransform() const { return m_transform; }
	inline Transform &getTransform() { return m_transform; }
	inline void setTransform(const Transform &transform) { m_transform = transform; }
protected:
	void processInput(const Input &input) {}
	void update(float delta) {}
	void render() const {}

	Transform m_transform;
	
	CoreEngine *m_engine;

	std::vector<Entity*> m_children;
	std::vector<Component*> m_components;
private:
};

#endif
