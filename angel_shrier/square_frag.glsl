#version 450 core

layout (location = 1) in vec4 vertexColor;
out vec4 FragColor;


void main()
{
    FragColor = vec4(vertexColor);
}