#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;


void errorCallback(int error, const char *description)
{
    cerr << "GLFW Error " << error << ": " << description << endl;
}

int main()
{
    if (!glfwInit()) 
    {
        cerr << "failed to initialise GLFW" << endl;
        return -1;
    }

    // Set GLFW callbacks
    glfwSetErrorCallback(errorCallback);

    // Set OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 
    // Create window
    GLFWwindow *window = glfwCreateWindow(1200, 1200, "Game Engine", nullptr, nullptr);
    if (!window) 
    {
        cerr << "Failed to create a GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    // Make OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialise GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        cerr << "Failed to initialise GLEW" << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear colour buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}