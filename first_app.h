#ifndef FIRST_APP_HPP
#define FIRST_APP_HPP

#include "lve_window.hpp"

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
    };
} // namespace lve

#endif
