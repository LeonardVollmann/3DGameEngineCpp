//
//  rendering_engine.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 25/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "rendering_engine.h"

RenderingEngine::RenderingEngine() :
    m_basicShader(Shader("./res/shaders/basicShader"))
{}

void RenderingEngine::render(const Mesh &mesh)
{
    m_basicShader.bind();
    mesh.draw();
}
