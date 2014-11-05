#ifndef __GameEngine3D__test_game__
#define __GameEngine3D__test_game__

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

#endif /* defined(__GameEngine3D__test_game__) */
