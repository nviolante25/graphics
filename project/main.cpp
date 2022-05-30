#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/shader.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
} 


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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error: failed to initialize GLAD\n";
        return -1;
    } 
    // --------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f,
        
        0.5f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.75f,  0.5f, 0.0f,
    }; 

    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    Shader shader("./shader/vertex.glsl", "./shader/fragment.glsl");

    // --------------------------------------------------------------------
    // Render loop
    // --------------------------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.3, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // ---------------------------------------------------------------
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // ---------------------------------------------------------------

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}