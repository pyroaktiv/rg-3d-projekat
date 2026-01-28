#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/setup.h"
#include "../include/defs.h"
#include "../include/callbacks.h"

void setupGlfw() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* setupScreen() {
	g_monitor = glfwGetPrimaryMonitor();
	g_monitor_mode = glfwGetVideoMode(g_monitor);

	g_window = glfwCreateWindow(g_monitor_mode->width, g_monitor_mode->height, "Bus tracker", g_monitor, NULL);

	return g_window;
}

void setupCallbacks() {
	glfwSetKeyCallback(g_window, key_callback);
	glfwSetMouseButtonCallback(g_window, mouse_callback);
}

void setupCamera() {
	g_camera.setScreenSize(g_monitor_mode->height, g_monitor_mode->width);

	g_camera.pos = glm::vec3(5.0f, 0.0f, 5.0f);

	g_camera.setPersp();
}

void setupMouselook() {
	g_first_mouse = true;

	glfwSetInputMode(g_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(g_window, mouse_callback);
}

void setupTextures() {
	g_tex_road = Texture("assets/textures/asphalt.png", GL_REPEAT, GL_LINEAR);
}

void setupShaders() {
	g_shader_basic = Shader("shaders/basic.vert", "shaders/basic.frag");
}