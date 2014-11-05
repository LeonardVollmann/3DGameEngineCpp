#ifndef __GameEngine3D__game__
#define __GameEngine3D__game__

#include "entity.h"
#include "../rendering/camera.h"
#include "../rendering/rendering_engine.h"

class CoreEngine;

class Game
{
public:
	Game() {}

	virtual void processInput(Input &input) = 0;
	virtual void update() = 0;
	virtual void render(RenderingEngine *renderingEngine) = 0;

	inline void setEngine(CoreEngine *engine) { m_engine = engine; }
protected:
	CoreEngine *m_engine;

	Entity m_masterEntity;
	
	Camera m_camera;
private:
};

#endif /* defined(__GameEngine3D__game__) */
