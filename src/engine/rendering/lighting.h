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

#ifndef LIGHTING_H
#define LIGHTING_H

#include "../core/math.h"

class Light
{
public:
    Light(const Vector3f &color, float intensity) :
        m_color(color),
        m_intensity(intensity) {}
    
    inline const Vector3f &getColor() const { return m_color; }
    inline float getIntensity() const { return m_intensity; }
    
    inline void setColor(const Vector3f &color) { m_color = color; }
    inline void setIntensity(float intensity) { m_intensity = intensity; }
protected:
private:
    Vector3f m_color;
    float m_intensity;
};

class DirectionalLight
{
public:
    DirectionalLight(const Light &light, const Vector3f &direction) :
        m_light(light),
        m_direction(direction) {}
    
    inline const Light &getLight() const { return m_light; }
    inline const Vector3f &getDirection() const { return m_direction; }
    inline const Vector3f &getColor() const { return m_light.getColor(); }
    inline float getIntensity() const { return m_light.getIntensity(); }
    
    inline void setLight(const Light &light) { m_light = light; }
    inline void setDirection(const Vector3f &direction) { m_direction = direction; }
    inline void setColor(const Vector3f &color) { m_light.setColor(color); }
    inline void setIntensity(float intensity) { m_light.setIntensity(intensity); }
protected:
private:
    Light m_light;
    Vector3f m_direction;
};

#endif
