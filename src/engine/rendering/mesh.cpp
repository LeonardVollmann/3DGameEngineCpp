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

#include "mesh.h"

IndexedModel::IndexedModel(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices) :
    m_vertices(vertices),
    m_indices(indices),
    m_numVertices(0),
    m_numIndices(0)
{}

void IndexedModel::addVertex(const Vertex &vertex)
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
    std::vector<Vector3f> positions;
    std::vector<Vector2f> texCoords;

    positions.reserve(m_model.getNumVertices());
    texCoords.reserve(m_model.getNumVertices());

    for (Vertex vertex : m_model.getVertices()) {
        positions.push_back(vertex.getPosition());
        texCoords.push_back(vertex.getTexCoord());
    }

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getNumVertices() * sizeof(Vector3f), &positions[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_TEXCOORD]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getNumVertices() * sizeof(Vector2f), &texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_INDEX]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_model.getNumIndices() * sizeof(unsigned int), &(m_model.getIndices()[0]), GL_STATIC_DRAW);
}

// Mesh::~Mesh()
// {
//     glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
//     glDeleteVertexArrays(1, &m_vertexArrayObject);
// }

void Mesh::draw() const
{
    glBindVertexArray(m_vertexArrayObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_INDEX]);
	glDrawElements(GL_TRIANGLES, m_model.getNumIndices(), GL_UNSIGNED_INT, 0);
}
