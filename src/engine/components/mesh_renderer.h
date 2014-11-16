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

#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "../core/component.h"
#include "../rendering/mesh.h"
#include "../rendering/rendering_engine.h"

class MeshRenderer : public Component
{
public:
	MeshRenderer(const Mesh &mesh);

	virtual void render(const Shader &shader, const RenderingEngine &renderingEngine, const Camera &camera);

	inline const Mesh &getMesh() const { return m_mesh; }
	inline void setMesh(const Mesh &mesh) { m_mesh = mesh; }
protected:
private:
	Mesh m_mesh;
};

#endif
