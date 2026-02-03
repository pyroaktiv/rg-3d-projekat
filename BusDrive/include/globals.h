#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "FpsCamera.h"
#include "Texture.h"
#include "Shader.h"
#include "PassengerBunch.h"
#include "Road.h"

extern GLFWmonitor* g_monitor;
extern const GLFWvidmode* g_monitor_mode;
extern GLFWwindow* g_window;

extern FpsCamera g_camera;

extern float g_last_x;
extern float g_last_y;
extern bool g_first_mouse;


extern Bus g_bus;
extern Road g_road;
extern PassengerBunch g_bunch;


extern Texture g_tex_road;
extern Texture g_tex_panel;
extern Texture g_tex_door_open;
extern Texture g_tex_door_closed;
extern Texture g_tex_control;

extern std::vector<Texture> numbers;


extern Shader g_shader_basic;
extern Shader g_shader_phong;