//
//  entity.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 31/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__entity__
#define __GameEngine3D__entity__

#include "transform.h"
//#include "core_engine.h"

#include <vector>

class CoreEngine;

class Entity
{
public:
	Entity(const Transform &transform = Transform());

	void processInputAll();
	void updateAll();
	void renderAll();

	void addChild(Entity *child);

	void setEngine(CoreEngine *engine);
protected:
	void processInput() {}
	void update() {}
	void render() {}

	Transform m_transform;
	
	CoreEngine *m_engine;

	std::vector<Entity*> m_children;
private:
};

#endif /* defined(__GameEngine3D__entity__) */
