#ifndef UTILS_HPP
#define UTILS_HPP

#include <GLFW/glfw3.h>

inline void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

inline void framebuffer_size_callback(GLFWwindow* window, int width,
                                      int height) {
    (void)window;
    glViewport(0, 0, width, height);
}

char* loadShaderSource(const char* filename);

#endif
