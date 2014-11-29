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
 
#version 120

varying vec2 texCoord0;
varying vec3 normal0;

struct Light
{
    vec3 color;
    float intensity;
};

struct DirectionalLight
{
    Light light;
    vec3 direction;
};

uniform sampler2D texture;
uniform vec3 ambientLight;
uniform DirectionalLight directionalLight;

vec4 calculateLight(Light light, vec3 direction, vec3 normal)
{
    float diffuseFactor = dot(normal, -direction);
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    
    if (diffuseFactor > 0) {
        diffuseColor = vec4(light.color, 1) * light.intensity * diffuseFactor;
    }
    
    return diffuseColor;
}

vec4 calculateDirectionalLight(DirectionalLight directionalLight, vec3 normal)
{
    return calculateLight(directionalLight.light, -directionalLight.direction, normal);
}

void main()
{
    vec4 textureColor =  texture2D(texture, texCoord0);
    vec4 totalLight = vec4(ambientLight, 1);
    
    totalLight += calculateDirectionalLight(directionalLight, normal0);
    
    gl_FragColor = textureColor * totalLight;
}