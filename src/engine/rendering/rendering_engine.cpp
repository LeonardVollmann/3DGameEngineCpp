/*
 * Copyright (c) 2014 Leonard Vollmann
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "rendering_engine.h"
#include "../core/transform.h"
#include "../core/math.h"
#include "basic_shader.h"
#include "phong_shader.h"

RenderingEngine::RenderingEngine() :
    m_ambientLight(1.0f, 1.0f, 1.0f),
    m_directionalLight(Light(Vector3f(1.0f, 1.0f, 1.0f), 0.0f), Vector3f(0.0f, 0.0f, 0.0f))
{
	m_basicShader = new BasicShader();
    m_phongShader = new PhongShader();
}

RenderingEngine::~RenderingEngine()
{
	delete m_basicShader;
    delete m_phongShader;
}

void RenderingEngine::render(const Entity &object) const
{
	object.renderAll(*m_phongShader, *this, *m_camera);
}