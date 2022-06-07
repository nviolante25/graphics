#version 330

uniform vec3 lightColor;
uniform vec3 lightPos;

in vec3 objectColor;
in vec3 normal;
in vec3 FragPos;

out vec4 fragColor;

void main() {
    float ambient = 0.1f;
    float diffuse = 1.0f;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 finalColor = (ambient + diff ) * lightColor * objectColor;
    fragColor = vec4(finalColor, 1.0f);
}