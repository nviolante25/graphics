#version 330


layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 ourColor;


void main() {
    gl_Position = projection * view * model * vec4(pos, 1.0f);
    ourColor = vec4(color, 1.0f);
}