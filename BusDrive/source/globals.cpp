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
Texture g_tex_panel;
Texture g_tex_door_open;
Texture g_tex_door_closed;
Texture g_tex_control;
Texture g_tex_steering_wheel;
Texture g_tex_dogtags;

std::vector<Texture> numbers;

Shader g_shader_basic;
Shader g_shader_phong;

Model g_model_passenger;
Model g_model_control;

Model g_model_steering_wheel;