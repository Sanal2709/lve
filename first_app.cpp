#include "first_app.hpp"

#include "simple_render_system.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <array>
#include <cassert>
#include <stdexcept>

namespace lve
{
    FirstApp::FirstApp()
    {
        loadGameObjects();
    }

    FirstApp::~FirstApp()
    {
    }

    void FirstApp::run()
    {
        SimpleRenderSystem SimpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};

        while (!lveWindow.shouldClose())
        {
            glfwPollEvents();
            if (auto commandBuffer = lveRenderer.beginFrame())
            {
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                SimpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }

    void FirstApp::loadGameObjects()
    {
        std::vector<LveModel::Vertex> vertices{
            {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
            {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
            {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}};

        auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);

        auto triangle = LveGameObject::createGameObject();
        triangle.model = lveModel;
        triangle.color = {0.1f, 0.8f, 0.1f};
        triangle.transform2D.translation.x = 0.2f;
        triangle.transform2D.scale = {2.f, .5f};
        triangle.transform2D.rotation = .25f * glm::two_pi<float>();

        gameObjects.push_back(std::move(triangle));
    }

} // namespace lve
