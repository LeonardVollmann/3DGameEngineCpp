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

#ifndef MESH_H
#define MESH_H

#include "../core/math.h"
#include "shader.h"

#include <GL/glew.h>
#include <vector>

class Vertex
{
public:
    Vertex(const Vector3f &position, const Vector2f &texCoord) :
        m_position(position),
        m_texCoord(texCoord) {}

    inline const Vector3f &getPosition() const { return m_position; }
    inline const Vector2f &getTexCoord() const { return m_texCoord; }
protected:
private:
    Vector3f m_position;
    Vector2f m_texCoord;
};

class IndexedModel
{
public:
    IndexedModel(const std::vector<Vertex> &vertices = std::vector<Vertex>(), const std::vector<unsigned int> &indices = std::vector<unsigned int>());
    
    void addVertex(const Vertex &vertex);
    void addFace(const Vector3i &indices);
    
    inline const std::vector<Vertex> &getVertices()      const { return m_vertices; }
    inline const std::vector<unsigned int> &getIndices() const { return m_indices; }
    inline unsigned int getNumVertices()                 const { return m_numVertices; }
    inline unsigned int getNumIndices()                  const { return m_numIndices; }
protected:
private:
    std::vector<Vertex> m_vertices;
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
        BUFFER_TEXCOORD,
        BUFFER_INDEX,
        
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    
    IndexedModel m_model;
};

#endif
