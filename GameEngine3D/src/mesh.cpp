//
//  mesh.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 20/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "mesh.h"

IndexedModel::IndexedModel(const std::vector<Vector3f> &vertices, const std::vector<unsigned int> &indices) :
    m_vertices(vertices),
    m_indices(indices),
    m_numVertices(0),
    m_numIndices(0)
{}

void IndexedModel::addVertex(const Vector3f &vertex)
{
    m_vertices.push_back(vertex);
    
    m_numVertices++;
}

void IndexedModel::addFace(const Vector3i &indices)
{
    m_indices.push_back(indices[0]);
    m_indices.push_back(indices[1]);
    m_indices.push_back(indices[2]);
    
    m_numIndices += 3;
}

Mesh::Mesh(IndexedModel indexedModel) :
    m_model(indexedModel)
{
    glGenVertexArrays(1, &m_vertexArrayObject);
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getVertices().size() * sizeof(Vector3f), m_model.getVerticesByPointer(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getIndices().size() * sizeof(unsigned int), m_model.getIndicesByPointer(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 1, GL_UNSIGNED_INT, GL_FALSE, 0, 0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw() const
{
    glBindVertexArray(m_vertexArrayObject);
//    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_INDEX]);
    glDrawElements(GL_TRIANGLES, 1, GL_UNSIGNED_INT, m_model.getIndicesByPointer());
}