#pragma once

#include "srp_window.hpp"
#include "srp_pipeline.hpp"
#include "srp_device.hpp"

namespace srp {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGTH = 600;

            void run();
        
        private:
            SrpWindow srpWindow{WIDTH, HEIGTH, "Sierpinski triangle"};
            SrpDevice srpDevice{srpWindow};
            SrpPipeline srpPipeline{
                srpDevice, 
            "../shaders/simple_shader.vert.spv", 
            "../shaders/simple_shader.frag.spv", 
            SrpPipeline::defaultPipelineConfigInfo(WIDTH, HEIGTH)
            };
    };
}