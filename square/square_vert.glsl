#version 450

layout (location = 0) in vec3 in_loc;
out vec4  vec_col;

void main()
{
    gl_Position = vec4(in_loc, 1.0);
    vec_col = vec4(in_loc.y, in_loc.x, 0.0, 1.0);
}