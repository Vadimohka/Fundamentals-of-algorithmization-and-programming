#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <chrono>
#include <iostream>

#include "Game/Game.h"

#include "Physics/PhysicsEngine.h"
#include "Renderer/Renderer.h"
#include "Resources/ResourceManager.h"

static constexpr unsigned int SCALE = 3;
static constexpr unsigned int BLOCK_SIZE = 16;
glm::uvec2 g_windowSize(SCALE * 16 * BLOCK_SIZE, SCALE * 15 * BLOCK_SIZE);

void glfwWindowSizeCallback(GLFWwindow *pWindow, int width, int height) {
    g_windowSize.x = width;
    g_windowSize.y = height;
    Game::setWindowSize(g_windowSize);
}

void glfwKeyCallback(GLFWwindow *pWindow, int key, int scancode, int action,
                     int mode) {
    if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);

    }
    Game::setKey(key, action);
}

int main(int argc, char **argv) {
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *pWindow = glfwCreateWindow(g_windowSize.x, g_windowSize.y,
                                           "World of Tanks", nullptr, nullptr);
    if (!pWindow) {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "Can't load GLAD!" << std::endl;
    }

    std::cout << "Renderer: " << RenderEngine::Renderer::getRendererStr()
              << std::endl;
    std::cout << "OpenGL version: " << RenderEngine::Renderer::getVersionStr()
              << std::endl;

    RenderEngine::Renderer::setClearColor(0, 0, 0, 1);
    RenderEngine::Renderer::setDepthTest(true);

    {
        ResourceManager::setExecutablePath(argv[0]);
        Physics::PhysicsEngine::init();
        Game::initStartScreen(g_windowSize);
        Game::init();

        auto lastTime = std::chrono::high_resolution_clock::now();

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(pWindow)) {
            /* Poll for and process events */
            glfwPollEvents();

            auto currentTime = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration<double, std::milli>(currentTime - lastTime).count();
            lastTime = currentTime;
            Game::update(duration);
            Physics::PhysicsEngine::update(duration);

            /* Render here */
            RenderEngine::Renderer::clear();
            Game::render();

            /* Swap front and back buffers */
            glfwSwapBuffers(pWindow);
        } // Game loop

        Physics::PhysicsEngine::terminate();
        ResourceManager::unloadAllResources();
    }

    glfwTerminate();
    return 0;
}