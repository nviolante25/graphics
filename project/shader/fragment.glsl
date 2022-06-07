#version 330

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

in vec3 objectColor;
in vec3 normal;
in vec3 FragPos;

out vec4 fragColor;

void main() {
    vec3 kAmbient = vec3(0.0215, 0.1745, 0.0215);
    vec3 kDiffuse = vec3(0.07568, 0.61424, 0.07568); 
    vec3 kSpec = vec3(0.633, 0.727811, 0.633);
    vec3 lightDir = lightPos - FragPos;

    float diffuse = max(dot(normalize(normal), normalize(lightDir)), 0.0);
    float inv_r2 = 1.0f / pow(length(lightDir), 2); 

    float specularStrength = 0.5;
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec3 reflectDir = reflect(-normalize(lightDir), normalize(normal));  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 10);

    vec3 finalColor = (kAmbient + kDiffuse * diffuse + kSpec * spec) * lightColor * objectColor * inv_r2;
    fragColor = vec4(finalColor, 1.0f);
}