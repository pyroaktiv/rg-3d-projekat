#include "../include/callbacks.h"
#include "../include/globals.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;

    switch (key)
    {
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        break;

    case GLFW_KEY_1:
        glEnable(GL_DEPTH_TEST);
        break;

    case GLFW_KEY_2:
        glDisable(GL_DEPTH_TEST);
        break;

    case GLFW_KEY_3:
        glEnable(GL_CULL_FACE);
        break;

    case GLFW_KEY_4:
        glDisable(GL_CULL_FACE);
        break;

    case GLFW_KEY_P:
        g_camera.setPersp();
        break;

    case GLFW_KEY_O:
        g_camera.setOrtho();
        break;
    }
}


void mouse_callback(GLFWwindow* window, int button, int action, int mods) {

}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
    float xPos = static_cast<float>(xposIn);
    float yPos = static_cast<float>(yposIn);

    if (g_first_mouse) {
        g_last_x = xPos;
        g_last_y = yPos;
        g_first_mouse = false;
    }

    float xOffset = xPos - g_last_x;
    float yOffset = -(yPos - g_last_y);

    g_last_x = xPos;
    g_last_y = yPos;

    const float sensitivity = 0.002f;

    g_camera.handleMouseMovement(xOffset, yOffset, sensitivity);
}