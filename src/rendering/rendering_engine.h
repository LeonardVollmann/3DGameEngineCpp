//
//  rendering_engine.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 25/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__rendering_engine__
#define __GameEngine3D__rendering_engine__

#include "mesh.h"
#include "shader.h"

class RenderingEngine
{
public:
    RenderingEngine();
    
    void update();
    void render(const Mesh &mesh);
protected:
private:
    Shader m_basicShader;
};

#endif /* defined(__GameEngine3D__rendering_engine__) */
