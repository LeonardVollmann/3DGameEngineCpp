//
//  mesh.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 20/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__mesh__
#define __GameEngine3D__mesh__

#include "../core/math.h"
#include "shader.h"

#include <GL/glew.h>
#include <vector>

class IndexedModel
{
public:
    IndexedModel(const std::vector<Vector3f> &vertices = std::vector<Vector3f>(), const std::vector<unsigned int> &indices = std::vector<unsigned int>());
    
    void addVertex(const Vector3f &vertex);
    void addFace(const Vector3i &indices);
    
    inline const std::vector<Vector3f> &getVertices()    const { return m_vertices; }
    inline const std::vector<unsigned int> &getIndices() const { return m_indices; }
    inline const Vector3f *getVerticesByPointer()        const { return &m_vertices[0]; }
    inline const unsigned int *getIndicesByPointer() 	 const { return &m_indices[0]; }
    inline unsigned int getNumVertices()                 const { return m_numVertices; }
    inline unsigned int getNumIndices()                  const { return m_numIndices; }
protected:
private:
    std::vector<Vector3f> m_vertices;
    std::vector<unsigned int> m_indices;
    
    unsigned int m_numVertices;
    unsigned int m_numIndices;
};

class Mesh
{
public:
    Mesh(IndexedModel model = IndexedModel());
    // virtual ~Mesh();
    
    void draw() const;
    
    inline const IndexedModel &getModel() { return m_model; }

    inline void setModel(const IndexedModel &model) { m_model = model; }
protected:
private:
    enum {
        BUFFER_VERTEX,
        BUFFER_INDEX,
        
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    
    IndexedModel m_model;
};

#endif /* defined(__GameEngine3D__mesh__) */
