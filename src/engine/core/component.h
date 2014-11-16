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

#ifndef COMPONENT_H
#define COMPONENT_H

#include "input.h"
//#include "core_engine.h"
//#include "entity.h"
#include "../rendering/rendering_engine.h"

class Entity;
class CoreEngine;

class Component
{
public:
	Component() {}
	virtual ~Component() {}
	
	virtual void processInput(const Input &input) {};
	virtual void update(float delta) {};
	virtual void render(const Shader &shader, const RenderingEngine &renderingEngine, const Camera &camera) {};

	inline const Transform &getTransform() const { return m_parent->getTransform(); }

	inline void setParent(Entity *parent) { m_parent = parent; }
	inline void setEngine(CoreEngine *engine) { m_engine = engine; }
protected:
	Entity *m_parent;
	CoreEngine *m_engine;
private:
};

#endif
