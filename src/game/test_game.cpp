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

#include "test_game.h"

#include "../engine/rendering/camera.h"
#include "../engine/core/component.h"
#include "../engine/components/mesh_renderer.h"

#include <cmath>

TestGame::TestGame()
{}

TestGame::~TestGame()
{
	delete m_camera;
}

void TestGame::init()
{
	IndexedModel model = IndexedModel();
	model.addVertex(Vector3f( 0.0f,  0.5f, 0.0f));
	model.addVertex(Vector3f(-0.5f, -0.5f, 0.0f));
	model.addVertex(Vector3f( 0.5f, -0.5f, 0.0f));
	model.addFace(Vector3i(0, 1, 2));
	m_testMesh = Mesh(model);

	m_camera = new Camera(Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 1.0f), Vector3f(0.0f, 1.0f, 0.0f), 70.0f, m_engine->getWindow()->getAspectRatio(), 0.1f, 1000.0f);
	m_engine->getRenderingEngine()->setCamera(m_camera);

	add((new Entity())->addComponent(new MeshRenderer(m_testMesh)));
}

void TestGame::processInput(Input &input)
{}

float counter = 0.0f;
float sinCounter;
float cosCounter;

void TestGame::update()
{
	counter += 0.1f;
	sinCounter = sinf(counter);
	cosCounter = cosf(counter);

	m_testTransform.setTranslation(Vector3f(cosCounter, sinCounter, 0.0f));
}

void TestGame::render(RenderingEngine *renderingEngine)
{
	renderingEngine->render(m_root);
}
