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

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "../engine/core/game.h"
#include "../engine/core/core_engine.h"
#include "../engine/core/entity.h"
#include "../engine/core/input.h"
#include "../engine/rendering/camera.h"
#include "../engine/rendering/mesh.h"
#include "../engine/rendering/rendering_engine.h"

class TestGame : public Game
{
public:
	TestGame();
	virtual ~TestGame();

	virtual void processInput(Input &input);
	virtual void update();
	virtual void render(RenderingEngine *renderingEngine);
protected:
private:
	Mesh m_testMesh;
	Transform m_testTransform;
};
#endif
