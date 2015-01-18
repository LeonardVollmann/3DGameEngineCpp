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

#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include "../core/math.h"

class Material
{
public:
    Material(const Texture &texture, const Vector3f &color, float specularIntensity, float specularExponent) :
        m_texture(texture),
        m_color(color),
        m_specularIntensity(specularIntensity),
        m_specularExponent(specularExponent) {}
    
    void bindTexture(unsigned int unit) const;
    
    inline const Texture &getTexture() const { return m_texture; }
    inline const Vector3f &getColor() const { return m_color; }
    inline float getSpecularIntensity() const { return m_specularIntensity; }
    inline float getSpecularExponent() const { return m_specularExponent; }
    
    inline void setTexture(const Texture &texture) { m_texture = texture; }
    inline void setColor(const Vector3f &color) { m_color = color; }
    inline void setSpecularIntensity(float specularIntensity) { m_specularIntensity = specularIntensity; }
    inline void setSpecularExponent(float specularExponent) { m_specularExponent = specularExponent; }
protected:
private:
    Texture m_texture;
    Vector3f m_color;
    float m_specularIntensity;
    float m_specularExponent;
};

#endif