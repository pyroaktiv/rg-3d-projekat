#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../include/Util.h"
#include "../include/setup.h"
#include "../include/defs.h"
#include "../include/Shader.h"
#include <glm/gtc/matrix_transform.hpp>

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

    setupCallbacks();
    setupCamera();


    //test

    std::vector<float> vertices = {
        0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f
    };

    unsigned int stride = 7 * sizeof(float);

    unsigned int VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    Shader simpleShader("shaders/test.vert", "shaders/test.frag");

    simpleShader.use();

    simpleShader.setMat4("uM", glm::mat4(1.0f));
    

    //

    while (!glfwWindowShouldClose(g_window))
    {
        double init_frame_time = glfwGetTime();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        simpleShader.setMat4("uV", g_camera.getViewMatrix());
        simpleShader.setMat4("uP", g_camera.getProjectionMatrix());

        glfwSwapBuffers(g_window);
        glfwPollEvents();

        while (glfwGetTime() - init_frame_time < 1 / DISP_TARGET_FPS);
    }

    glUseProgram(0);
    glfwDestroyWindow(g_window);
    glfwTerminate();
    return 0;
}