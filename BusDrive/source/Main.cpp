#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include <glm/gtc/matrix_transform.hpp>

#include "../include/Util.h"
#include "../include/setup.h"
#include "../include/defs.h"
#include "../include/fsm.h"
#include "../include/vaos.h"
#include "../include/matrices.h"
#include "../include/draw.h"

// Main fajl funkcija sa osnovnim komponentama OpenGL programa

// Projekat je dozvoljeno pisati počevši od ovog kostura
// Toplo se preporučuje razdvajanje koda po fajlovima (i eventualno potfolderima) !!!
// Srećan rad! fala

// Vladimir Zorić RA 36/2022

int main()
{
    setupGlfw();

    if (setupScreen() == NULL) return endProgram("Prozor nije uspeo da se kreira.");

    glfwMakeContextCurrent(g_window);

    if (glewInit() != GLEW_OK) return endProgram("GLEW nije uspeo da se inicijalizuje.");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.8f, 0.5f, 0.0f, 1.0f);

    
    setupCamera();
    setupMouselook();
    setupCallbacks();
    setupVAOs();
    setupMatrices();
    setupShaders();
    setupTextures();


    while (!glfwWindowShouldClose(g_window))
    {
        double init_frame_time = glfwGetTime();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        doFSMLoop();

        drawRoad();
        drawBus();
        drawPassenger();

        glfwSwapBuffers(g_window);
        glfwPollEvents();

        while (glfwGetTime() - init_frame_time < 1 / DISP_TARGET_FPS);
    }

    glUseProgram(0);
    glfwDestroyWindow(g_window);
    glfwTerminate();
    return 0;
}