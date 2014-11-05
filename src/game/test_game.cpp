#include "test_game.h"

#include "../engine/rendering/camera.h"

#include <cmath>

TestGame::TestGame()
{
	IndexedModel model = IndexedModel();
	model.addVertex(Vector3f( 0.0f,  0.5f, 0.0f));
	model.addVertex(Vector3f(-0.5f, -0.5f, 0.0f));
	model.addVertex(Vector3f( 0.5f, -0.5f, 0.0f));
	model.addFace(Vector3i(0, 1, 2));
	m_testMesh = Mesh(model);

	m_camera = Camera();
}

TestGame::~TestGame()
{}

void TestGame::processInput(Input &input)
{
	
}

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
	renderingEngine->render(m_testMesh);
}
