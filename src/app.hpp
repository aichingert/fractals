#pragma once

#include "srp_window.hpp"
#include "srp_pipeline.hpp"

namespace srp {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGTH = 600;

            void run();
        
        private:
            SrpWindow srpWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
            SrpPipeline srpPipeline{"../shaders/simple_shader.vert.spv", "../shaders/simple_shader.frag.spv"};
    };
}