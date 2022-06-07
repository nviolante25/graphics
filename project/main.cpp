#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/shader.h"


auto eye = glm::vec3(0, 0, 5);
auto center = glm::vec3(0, 0, 0);
auto up = glm::vec3(0, 1, 0);

auto eye_init = eye;
auto center_init = center;
auto up_init = up;

auto model = glm::mat4(1.0f);
auto view = glm::mat4(1.0f);
auto projection = glm::mat4(1.0f);


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void leftRotation(float angle);
void upRotation(float angle);


int main() {
    // --------------------------------------------------------------------
    // Window creation
    // --------------------------------------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    auto window = glfwCreateWindow(700, 500, "Project", NULL, NULL);
    if (!window) {
        std::cout << "Error: failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwSetWindowPos(window, 500, 200);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error: failed to initialize GLAD\n";
        return -1;
    } 
    // --------------------------------------------------------------------
    // Load data in GPU buffer
    // --------------------------------------------------------------------
    float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    glm::vec3 positions[] = {
        glm::vec3{-2.5 ,0, 0},
        glm::vec3{-0.5, 0, 0},
        glm::vec3{0.75, 0, 0},
    };
    glm::vec3 sizes[] = {
        glm::vec3{1, 1, 1},
        glm::vec3{1.5, 1.5, 1.5},
        glm::vec3{2, 2, 2}
    };

    unsigned int VBO, VAO, EBO, VBNormals;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBNormals);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    // Load vertex data on GPU
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    // Specify vertex attributes (size, type, stride, offsets)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // --------------------------------------------------------------------
    // Load and compile shaders
    // --------------------------------------------------------------------
    Shader shader("./shader/vertex.glsl", "./shader/fragment.glsl");
    
    projection = glm::perspective(45.0f, 700.0f / 500.0f, 0.1f, 100.0f);

    // --------------------------------------------------------------------
    // Render loop
    // --------------------------------------------------------------------
    glEnable(GL_DEPTH_TEST);
    auto lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    auto lightPos = glm::vec3(0, 0, 2.0f);
    
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.8, 0.8, 0.9, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        lightPos.x = 1.5f * glm::cos(glfwGetTime());
        lightPos.y = 1.5f * glm::sin(glfwGetTime());
        // ---------------------------------------------------------------
        shader.use();
        view = glm::lookAt(eye, center, up);
        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniform3fv(glGetUniformLocation(shader.ID, "lightColor"), 1, glm::value_ptr(lightColor));
        glUniform3fv(glGetUniformLocation(shader.ID, "lightPos"), 1, glm::value_ptr(lightPos));
        glUniform3fv(glGetUniformLocation(shader.ID, "cameraPos"), 1, glm::value_ptr(eye));

        glBindVertexArray(VAO);
        for (int i=0; i < 3; i++) {
            model = glm::mat4(1.0f);
            model = glm::scale(model, sizes[i]);
            model = glm::translate(model, positions[i]); 
            glm::mat3 normal_matrix;
            normal_matrix = glm::transpose(glm::inverse(glm::mat3(model)));

            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix3fv(glGetUniformLocation(shader.ID, "normal_matrix"), 1, GL_FALSE, glm::value_ptr(normal_matrix));
            glDrawArrays(GL_TRIANGLES, 0, 36); 
        }
        // ---------------------------------------------------------------

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
} 

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    float speed = 0.05f;
    if (key == GLFW_KEY_W && action != GLFW_RELEASE) {
        eye = eye + speed * glm::normalize(center - eye);
    }
    if (key == GLFW_KEY_S && action != GLFW_RELEASE) {
        eye = eye - speed * glm::normalize(center - eye);
    }
    if (key == GLFW_KEY_LEFT && action != GLFW_RELEASE) {
        leftRotation(glm::radians(5.0f));
    }
    if (key == GLFW_KEY_RIGHT && action != GLFW_RELEASE) {
        leftRotation(glm::radians(-5.0f));
    }
    if (key == GLFW_KEY_UP && action != GLFW_RELEASE) {
        upRotation(glm::radians(5.0f));
    }
    if (key == GLFW_KEY_DOWN && action != GLFW_RELEASE) {
        upRotation(glm::radians(-5.0f));
    }
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        eye = eye_init;
        center = center_init;
        up = up_init;
    }
}

void leftRotation(float angle) {
    auto rotation = glm::mat4(1.0f);
    auto eye4 = glm::vec4(eye, 1.0f);
    
    rotation = glm::rotate(rotation, angle, up);
    eye4 = eye4 * rotation;
    eye = glm::vec3(eye4.x, eye4.y, eye4.z);
}

void upRotation(float angle) {
    auto rotation = glm::mat4(1.0f);
    auto eye4 = glm::vec4(eye, 1.0f);
    auto up4= glm::vec4(up, 1.0f);
    
    auto axis = glm::normalize(glm::cross(up, center - eye));
    rotation = glm::rotate(rotation, angle, axis);
    eye4 = eye4 * rotation;
    eye = glm::vec3(eye4[0], eye4[1], eye4[2]);
    up4 = up4 * rotation;
    up = glm::vec3(up4[0], up4[1], up4[2]);
}