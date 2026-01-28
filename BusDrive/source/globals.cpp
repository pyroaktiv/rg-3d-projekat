#include "../include/globals.h"

GLFWmonitor* g_monitor;
const GLFWvidmode* g_monitor_mode;
GLFWwindow* g_window;

FpsCamera g_camera;

float g_last_x;
float g_last_y;
bool g_first_mouse;


Bus g_bus;
Road g_road;
PassengerBunch g_bunch;


Texture g_tex_road;

Shader g_shader_basic;