#ifndef __GameEngine3D__rendering_engine__
#define __GameEngine3D__rendering_engine__

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

#endif /* defined(__GameEngine3D__rendering_engine__) */
