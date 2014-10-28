#version 120

attribute vec3 position;

varying vec4 color;

uniform float uniformFloat;
uniform mat4 transform;

void main()
{
	color = vec4(clamp(position, 0.0, uniformFloat), 1.0);
    gl_Position = transform * vec4(position, 1.0);
}