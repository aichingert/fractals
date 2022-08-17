#pragma once

#include "srp_window.hpp"
#include "srp_pipeline.hpp"
#include "srp_device.hpp"
#include "srp_swap_chain.hpp"

namespace srp {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();
        
        private:
            SrpWindow srpWindow{WIDTH, HEIGHT, "Sierpinski triangle"};
            SrpDevice srpDevice{srpWindow};
            SrpSwapChain srpSwapChain{srpDevice, srpWindow.getExtent()};
            SrpPipeline srpPipeline{
                srpDevice, 
                "../shaders/simple_shader.vert.spv", 
                "../shaders/simple_shader.frag.spv", 
                SrpPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
            };
    };
}