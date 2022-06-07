#version 330


layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normal_matrix;

out vec3 objectColor;
out vec3 normal;
out vec3 FragPos;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    objectColor = vec3(1.0f, 1.0f, 1.0f);
    FragPos = vec3(model * vec4(aPos, 1.0f));
    normal = normal_matrix * aNormal; 
}