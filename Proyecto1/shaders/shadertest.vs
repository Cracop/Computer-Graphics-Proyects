#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 transform;

void main()
{
    //Para poder hacer transformaciones
	gl_Position = transform * vec4(aPos, 1.0);
    //vanilla
    //gl_Position = vec4(aPos, 1.0);
}