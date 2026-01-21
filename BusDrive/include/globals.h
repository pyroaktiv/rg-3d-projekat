#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "FpsCamera.h"
#include "Shader.h"

extern GLFWmonitor* g_monitor;
extern const GLFWvidmode* g_monitor_mode;
extern GLFWwindow* g_window;

extern FpsCamera g_camera;