//
//  core_engine.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 24/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__core_engine__
#define __GameEngine3D__core_engine__

#include "window.h"

class CoreEngine
{
public:
    CoreEngine(double fps, Window *window);
    
    void start();
    void stop();
protected:
private:
    double m_frameTime;
    
    bool m_running;
    
    Window *m_window;
    
    void update();
    void render();
};

#endif /* defined(__GameEngine3D__core_engine__) */
