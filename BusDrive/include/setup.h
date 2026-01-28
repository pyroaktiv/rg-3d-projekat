#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "globals.h"
#include "callbacks.h"

void setupGlfw();

GLFWwindow* setupScreen();

void setupCallbacks();

void setupCamera();

void setupMouselook();



void setupTextures();

void setupShaders();