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

#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "mesh.h"
#include "shader.h"
#include "basic_shader.h"
#include "camera.h"
#include "../core/entity.h"

class RenderingEngine
{
public:
    RenderingEngine();

	inline void setCamera(Camera *camera) { m_camera = camera; }

    void render(const Entity &object) const;
protected:
private:
    BasicShader m_basicShader;
	
    Camera *m_camera;
};

#endif
