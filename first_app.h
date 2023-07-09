#ifndef FIRST_APP_HPP
#define FIRST_APP_HPP

#include "lve_device.hpp"
#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"

// std
#include <memory>
#include <vector>

namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 1024;
        static constexpr int HEIGHT = 768;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<LveModel> lveModel;
    };
} // namespace lve

#endif
