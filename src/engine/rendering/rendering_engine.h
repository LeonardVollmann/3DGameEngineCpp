#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "mesh.h"
#include "shader.h"
#include "camera.h"

class RenderingEngine
{
public:
    RenderingEngine();
    
    void render(const Mesh &mesh);
protected:
private:
    Shader m_basicShader;

    Camera m_camera;
};

#endif
