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
#include "../engine/components/camera_component.h"
#include "../engine/components/free_move.h"
#include "../engine/components/free_look.h"

#include <cmath>

TestGame::TestGame() : 
	m_texture("default.png") {}

TestGame::~TestGame() {}

void TestGame::init()
{
	m_root.setEngine(m_engine);

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

	Mesh mesh0 = Mesh(model);

	// IndexedModel model1 = IndexedModel();
	// model1.addVertex(Vertex(Vector3f(-5, -3, -5), Vector2f(0, 1)));
	// model1.addVertex(Vertex(Vector3f(-5, -3,  5), Vector2f(1, 1)));
	// model1.addVertex(Vertex(Vector3f( 5, -3,  5), Vector2f(1, 0)));
	// model1.addVertex(Vertex(Vector3f( 5, -3, -5), Vector2f(0, 0)));
	// model1.addFace(Vector3i(2, 1, 0));
	// model1.addFace(Vector3i(3, 2, 0));
	// Mesh mesh1 = Mesh(model1);

	// m_camera = new Camera(Vector3f(0.0f, 0.0f, -3.0f), Vector3f(0.0f, 0.0f, 1.0f), Vector3f(0.0f, 1.0f, 0.0f), 70.0f, m_engine->getWindow()->getAspectRatio(), 0.1f, 1000.0f);

	m_object0 = (new Entity())->addComponent(new MeshRenderer(mesh0));
	add(m_object0);

	// m_object1 = (new Entity())->addComponent(new MeshRenderer(mesh1));
	// add(m_object1);

	add((new Entity())->addComponent(new CameraComponent(70.0f, m_engine->getWindow()->getAspectRatio(), 0.1f, 1000.0f))
		->addComponent(new FreeMove(0.2f))
		->addComponent(new FreeLook(m_engine->getWindow()->getCenter(), 0.2f)));
    
    m_engine->getRenderingEngine()->setAmbientLight(Vector3f(0.1f, 0.1f, 0.1f));
}

float counter = 0.0f;
float sinCounter;
float cosCounter;

void TestGame::update(float delta)
{
	m_root.updateAll(delta);

	counter += 0.02f;
	sinCounter = sinf(counter);
	cosCounter = cosf(counter);

	// m_object0->getTransform().setRotation(Quaternion(Vector3f(0.0f, 1.0f, 0.0f), counter));
	m_object0->getTransform().rotate(Vector3f(0.0f, 1.0f, 0.0f), 0.02f);
}

void TestGame::render(RenderingEngine *renderingEngine)
{
	m_texture.bind(0);
	renderingEngine->render(m_root);
}
