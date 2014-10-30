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
    m_basicShader("basicShader"),
    m_camera(Vector3f(3.0f, 1.0f, -3.0f), Vector3f(0.0f, 0.0f, 1.0f), Vector3f(0.0f, 1.0f, 0.0f), 70.0f, 800.0f / 600.0f, 0.1f, 1000.0f)
{
	m_basicShader.addUniform("uniformFloat");
	m_basicShader.addUniform("transform");
	m_basicShader.addUniform("viewProjection");
}

float counter = 0.0f;
float temp;
float sinCounter;
Transform transform = Transform();

void RenderingEngine::update()
{
	counter += 0.01f;
	temp = fabs(sinf(counter));
	sinCounter = sinf(counter);
	// transform.setScale(Vector3f(sinCounter, sinCounter, sinCounter).abs());
	transform.setTranslation(Vector3f(sinf(counter * 2), 0.0f, fabs(sinCounter)));
	// transform.setRotation(Quaternion(Vector3f(0.0f, 0.0f, 1.0f), sinCounter));
}

void RenderingEngine::render(const Mesh &mesh)
{
	m_basicShader.bind();
	m_basicShader.setUniformFloat("uniformFloat", temp);
	m_basicShader.setUniformMatrix4f("transform", transform.getTransformation());
	m_basicShader.setUniformMatrix4f("viewProjection", m_camera.getViewProjection());
    mesh.draw();
}
