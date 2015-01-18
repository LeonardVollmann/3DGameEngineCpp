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

void IndexedModel::addVertices(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, bool calcNormals)
{
    m_numVertices += vertices.size();
    m_numIndices += indices.size();
    
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        m_vertices.push_back(*it);
    }
    
    for (auto it = indices.begin(); it != indices.end(); it++) {
        m_indices.push_back(*it);
    }
    
    if (calcNormals) {
        calculateNormals();
    }
}

void IndexedModel::calculateNormals()
{
    for (unsigned int i = 0; i < m_indices.size(); i += 3) {
        unsigned int i0 = m_indices[i];
        unsigned int i1 = m_indices[i + 1];
        unsigned int i2 = m_indices[i + 2];
        
        Vector3f v0 = m_vertices[i1].getPosition() - m_vertices[i0].getPosition();
        Vector3f v1 = m_vertices[i2].getPosition() - m_vertices[i0].getPosition();
        
        Vector3f normal = v0.cross(v1).normalized();
        
        m_vertices[i0].setNormal((m_vertices[i0].getNormal() + normal));
        m_vertices[i1].setNormal((m_vertices[i1].getNormal() + normal));
        m_vertices[i2].setNormal((m_vertices[i2].getNormal() + normal));
    }
    
    for (unsigned int i = 0; i < m_vertices.size(); i++) {
        m_vertices[i].setNormal(m_vertices[i].getNormal().normalized());
    }
}

Mesh::Mesh(const IndexedModel &indexedModel, const Material &material) :
    m_model(indexedModel),
    m_material(material)
{
    std::vector<Vector3f> positions;
    std::vector<Vector2f> texCoords;
    std::vector<Vector3f> normals;

    for (Vertex vertex : m_model.getVertices()) {
        positions.push_back(vertex.getPosition());
        texCoords.push_back(vertex.getTexCoord());
        normals.push_back(vertex.getNormal());
    }

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getNumVertices() * sizeof(Vector3f), positions.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_TEXCOORD]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getNumVertices() * sizeof(Vector2f), texCoords.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_NORMAL]);
    glBufferData(GL_ARRAY_BUFFER, m_model.getNumVertices() * sizeof(Vector3f), normals.data(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

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
//    glBindVertexArray(m_vertexArrayObject);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[BUFFER_INDEX]);
	glDrawElements(GL_TRIANGLES, m_model.getNumIndices(), GL_UNSIGNED_INT, 0);
}
