#include "shader.h"

#include <iostream>
#include <fstream>

Shader::Shader(const std::string &fileName)
{
    m_program = glCreateProgram();
    
    glBindAttribLocation(m_program, 0, "position");
    
    m_shaders[0] = createShader(loadShader("./res/shaders/" + fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadShader("./res/shaders/" + fileName + ".fs"), GL_FRAGMENT_SHADER);
    
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glAttachShader(m_program, m_shaders[i]);
    }
    
    glLinkProgram(m_program);
    checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader linking failed: ");
    
   glValidateProgram(m_program);
   checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Shader validation failed: ");
}

Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    
    glDeleteProgram(m_program);
}

void Shader::bind() const
{
    glUseProgram(m_program);
}

void Shader::addUniform(const std::string &uniform)
{
    GLint location = glGetUniformLocation(m_program, uniform.c_str());

    m_uniforms.insert(std::pair<std::string, GLint>(uniform, location));
}

void Shader::setUniformInteger(const std::string &uniform, int value)
{
    glUniform1i(m_uniforms[uniform], value);
}

void Shader::setUniformFloat(const std::string &uniform, float value)
{
    glUniform1f(m_uniforms[uniform], value);
}

void Shader::setUniformVector3f(const std::string &uniform, const Vector3f &value)
{
    glUniform3f(m_uniforms[uniform], value.getX(), value.getY(), value.getZ());
}

void Shader::setUniformMatrix4f(const std::string &uniform, const Matrix4f &value)
{
    GLfloat matrix[16];
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            matrix[4 * i + j] = (GLfloat)value[i][j];
        }
    }

    glUniformMatrix4fv(m_uniforms[uniform], 1, true, matrix);
}

std::string Shader::loadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());

    std::string output;
    std::string line;

    if (file.is_open()) {
        while(file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    } else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };
    
    if(isProgram) {
        glGetProgramiv(shader, flag, &success);
    } else {
        glGetShaderiv(shader, flag, &success);
    }

    if(success == GL_FALSE) {
        if(isProgram) {
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        } else {
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;   
    }
}

GLuint Shader::createShader(const std::string &text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    if (shader == 0) {
        std::cerr << "Error: Shader creation failed" << std::endl;
    }
    
    const GLchar *shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];
    
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = (GLint)text.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);
    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");
    
    return shader;
}
