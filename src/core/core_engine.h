//
//  core_engine.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 24/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__core_engine__
#define __GameEngine3D__core_engine__

#include "../rendering/window.h"
#include "../rendering/rendering_engine.h"

class CoreEngine
{
public:
    CoreEngine(double fps, Window *window, RenderingEngine *renderingEngine);
    
    void start();
    void stop();
    
    inline RenderingEngine *getRenderingEngine() { return m_renderingEngine; }
protected:
private:
    double m_frameTime;
    
    bool m_running;
    
    Window *m_window;
    RenderingEngine *m_renderingEngine;

    Mesh m_testMesh;
    
    void update();
    void render();
};

#endif /* defined(__GameEngine3D__core_engine__) */