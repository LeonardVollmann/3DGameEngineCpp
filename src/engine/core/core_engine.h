#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H

#include "../rendering/window.h"
#include "../rendering/rendering_engine.h"
#include "game.h"

class CoreEngine
{
public:
    CoreEngine(double fps, Window *window, RenderingEngine *renderingEngine, Game *game);
    
    void start();
    void stop();
    
    inline RenderingEngine *getRenderingEngine() { return m_renderingEngine; }
protected:
private:
    double m_frameTime;
    
    bool m_running;
    
    Window *m_window;
    RenderingEngine *m_renderingEngine;
	Game *m_game;
 
    void update();
    void render();
};

#endif
