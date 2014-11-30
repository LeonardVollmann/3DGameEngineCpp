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

#include "phong_shader.h"
#include "rendering_engine.h"

PhongShader::PhongShader() :
Shader("phongShader")
{
    addUniform("transform");
    addUniform("color");
    addUniform("viewProjection");
    addUniform("ambientLight");
    
    addUniform("directionalLight.light.color");
    addUniform("directionalLight.light.intensity");
    addUniform("directionalLight.direction");
}

void PhongShader::updateUniforms(const Transform &transform, const RenderingEngine &renderingEngine, const Camera &camera, const Material &material) const
{
    setUniformMatrix4f("transform", transform.getTransformation());
    setUniformVector3f("color", material.getColor());
    setUniformMatrix4f("viewProjection", camera.getViewProjection());
    setUniformVector3f("ambientLight", renderingEngine.getAmbientLight());
    setUniformDirectionalLight("directionalLight", renderingEngine.getDirectionalLight());
}

void PhongShader::setUniformLight(const std::string &uniform, const Light &light) const
{
    setUniformVector3f(uniform + ".color", light.getColor());
    setUniformFloat(uniform + ".intensity", light.getIntensity());
}

void PhongShader::setUniformDirectionalLight(const std::string &uniform, const DirectionalLight &directionalLight) const
{
    setUniformLight(uniform + ".light", directionalLight.getLight());
    setUniformVector3f(uniform + ".direction", directionalLight.getDirection());
}