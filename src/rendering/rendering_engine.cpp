//
//  rendering_engine.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 25/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "rendering_engine.h"

RenderingEngine::RenderingEngine() :
    m_basicShader("basicShader")
{
	m_basicShader.addUniform("uniformFloat");
}

float temp = 0.0f;

void RenderingEngine::update()
{
	temp += 0.01f;
	m_basicShader.setUniformFloat("uniformFloat", fabs(sinf(temp)));
}

void RenderingEngine::render(const Mesh &mesh)
{
	m_basicShader.bind();
    mesh.draw();
}