//
//  shader.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 24/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__shader__
#define __GameEngine3D__shader__

#include <string>
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
protected:
private:
    static const unsigned int NUM_SHADERS = 2;

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif /* defined(__GameEngine3D__shader__) */