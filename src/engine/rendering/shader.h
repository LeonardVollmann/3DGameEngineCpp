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

#ifndef SHADER_H
#define SHADER_H

#include "../core/math.h"
#include "../core/transform.h"
//#include "rendering_engine.h"
#include "camera.h"
#include "material.h"

#include <string>
#include <map>
#include <GL/glew.h>

class RenderingEngine;

class Shader
{
public:
    static std::string loadShader(const std::string &fileName);
    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
    static GLuint createShader(const std::string &text, GLenum shaderType);
    
    Shader(const std::string &fileName);
    virtual ~Shader();

	virtual void updateUniforms(const Transform &transform, const RenderingEngine &renderingEngine, const Camera &camera, const Material &material) const {}
    
    void bind() const;

    void addUniform(const std::string &uniform) const;
    void setUniformInteger(const std::string &uniform, int value) const;
    void setUniformFloat(const std::string &uniform, float value) const;
    void setUniformVector3f(const std::string &uniform, const Vector3f &value) const;
    void setUniformMatrix4f(const std::string &uniform, const Matrix4f &value) const;
protected:
private:
    static const unsigned int NUM_SHADERS = 2;

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];

    mutable std::map<std::string, GLint> m_uniforms;
};

#endif
