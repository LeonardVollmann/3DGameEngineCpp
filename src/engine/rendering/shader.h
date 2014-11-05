#ifndef SHADER_H
#define SHADER_H

#include "../core/math.h"

#include <string>
#include <map>
#include <GL/glew.h>

class Shader
{
public:
    static std::string loadShader(const std::string &fileName);
    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
    static GLuint createShader(const std::string &text, GLenum shaderType);
    
    Shader(const std::string &fileName);
    virtual ~Shader();
    
    void bind() const;

    void addUniform(const std::string &uniform);
    void setUniformInteger(const std::string &uniform, int value);
    void setUniformFloat(const std::string &uniform, float value);
    void setUniformVector3f(const std::string &uniform, const Vector3f &value);
    void setUniformMatrix4f(const std::string &uniform, const Matrix4f &value);
protected:
private:
    static const unsigned int NUM_SHADERS = 2;

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];

    std::map<std::string, GLint> m_uniforms;
};

#endif
