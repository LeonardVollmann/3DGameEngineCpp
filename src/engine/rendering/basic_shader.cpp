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

#include "basic_shader.h"
#include "rendering_engine.h"

BasicShader::BasicShader() :
	Shader("basicShader")
{
	addUniform("transform");
	addUniform("viewProjection");
}

void BasicShader::updateUniforms(const Transform &transform, const RenderingEngine &renderingEngine, const Camera &camera) const
{
	setUniformMatrix4f("transform", transform.getTransformation());
	setUniformMatrix4f("viewProjection", camera.getViewProjection());
}
