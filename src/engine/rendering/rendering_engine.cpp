//
//  rendering_engine.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 25/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "rendering_engine.h"
#include "../core/transform.h"
#include "../core/math.h"

RenderingEngine::RenderingEngine() :
    m_basicShader("basicShader")
{
	m_basicShader.addUniform("uniformFloat");
	m_basicShader.addUniform("transform");
	m_basicShader.addUniform("viewProjection");
}

void RenderingEngine::render(const Mesh &mesh)
{
	m_basicShader.bind();
    mesh.draw();
}
