#ifndef FIRST_APP_HPP
#define FIRST_APP_HPP

#include "lve_device.hpp"
#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 1024;
        static constexpr int HEIGHT = 768;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        LvePipeline lvePipeline{lveDevice,
                                "shaders/simple_shader.vert.spv",
                                "shaders/simple_shader.frag.spv",
                                LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
} // namespace lve

#endif
