#include "../include/util.h";

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <glm/gtc/constants.hpp>


// Autor: Nedeljko Tesanovic
// Opis: pomocne funkcije za zaustavljanje programa, ucitavanje sejdera, tekstura i kursora
// Smeju se koristiti tokom izrade projekta

int endProgram(std::string message) {
    std::cout << message << std::endl;
    glfwTerminate();
    return -1;
}


float wrapAngle(float angle) {
    float wrapped = std::remainder(angle, 2 * glm::pi<float>());

    if (wrapped <= -glm::pi<float>())
        wrapped += 2 * glm::pi<float>();

    return wrapped;
}