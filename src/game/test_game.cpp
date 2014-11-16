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

TestGame::TestGame() : 
	m_texture("bricks.png") {}

TestGame::~TestGame()
{
	delete m_camera;
}

void TestGame::init()
{
	IndexedModel model = IndexedModel();

	model.addVertex(Vertex(Vector3f(-1, -1, -1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f(-1,  1, -1), Vector2f(0, 0)));
	model.addVertex(Vertex(Vector3f( 1,  1, -1), Vector2f(0, 1)));
	model.addVertex(Vertex(Vector3f( 1, -1, -1), Vector2f(1, 1)));
        
	model.addVertex(Vertex(Vector3f(-1, -1, 1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f(-1,  1, 1), Vector2f(0, 0)));
	model.addVertex(Vertex(Vector3f( 1,  1, 1), Vector2f(0, 1)));
	model.addVertex(Vertex(Vector3f( 1, -1, 1), Vector2f(1, 1)));
        
	model.addVertex(Vertex(Vector3f(-1, -1, -1), Vector2f(0, 1)));
	model.addVertex(Vertex(Vector3f(-1, -1,  1), Vector2f(1, 1)));
	model.addVertex(Vertex(Vector3f( 1, -1,  1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f( 1, -1, -1), Vector2f(0, 0)));
        
	model.addVertex(Vertex(Vector3f(-1, 1, -1), Vector2f(0, 1)));
	model.addVertex(Vertex(Vector3f(-1, 1,  1), Vector2f(1, 1)));
	model.addVertex(Vertex(Vector3f( 1, 1,  1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f( 1, 1, -1), Vector2f(0, 0)));
        
	model.addVertex(Vertex(Vector3f(-1, -1, -1), Vector2f(1, 1)));
	model.addVertex(Vertex(Vector3f(-1, -1,  1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f(-1,  1,  1), Vector2f(0, 0)));
	model.addVertex(Vertex(Vector3f(-1,  1, -1), Vector2f(0, 1)));
        
	model.addVertex(Vertex(Vector3f(1, -1, -1), Vector2f(1, 1)));
	model.addVertex(Vertex(Vector3f(1, -1,  1), Vector2f(1, 0)));
	model.addVertex(Vertex(Vector3f(1,  1,  1), Vector2f(0, 0)));
	model.addVertex(Vertex(Vector3f(1,  1, -1), Vector2f(0, 1)));

	model.addFace(Vector3i(2, 1, 0));
    model.addFace(Vector3i(3, 2, 0));
        
    model.addFace(Vector3i(4, 5, 6));
	model.addFace(Vector3i(4, 6, 7));
        
	model.addFace(Vector3i(8, 9, 10));
	model.addFace(Vector3i(8, 10, 11));
        
	model.addFace(Vector3i(14, 13, 12));
	model.addFace(Vector3i(15, 14, 12));
        
	model.addFace(Vector3i(18, 17, 16));
	model.addFace(Vector3i(19, 18, 16));
        
	model.addFace(Vector3i(20, 21, 22));
	model.addFace(Vector3i(20, 22, 23));

	m_mesh = Mesh(model);

	m_camera = new Camera(Vector3f(0.0f, 0.0f, -3.0f), Vector3f(0.0f, 0.0f, 1.0f), Vector3f(0.0f, 1.0f, 0.0f), 70.0f, m_engine->getWindow()->getAspectRatio(), 0.1f, 1000.0f);
	m_engine->getRenderingEngine()->setCamera(m_camera);

	m_object = (new Entity())->addComponent(new MeshRenderer(m_mesh));
	add(m_object);
}

void TestGame::processInput(Input &input)
{}

float counter = 0.0f;
float sinCounter;
float cosCounter;

void TestGame::update()
{
	counter += 0.02f;
	sinCounter = sinf(counter);
	cosCounter = cosf(counter);

	m_object->getTransform().setRotation(Quaternion().initFromAxisAngle(Vector3f(0.0f, 1.0f, 0.0f).normalized(), counter));
}

void TestGame::render(RenderingEngine *renderingEngine)
{
	m_texture.bind(0);
	renderingEngine->render(m_root);
}
