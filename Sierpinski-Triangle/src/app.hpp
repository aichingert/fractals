#pragma once

#include "srp_window.hpp"
#include "srp_pipeline.hpp"
#include "srp_device.hpp"
#include "srp_swap_chain.hpp"

#include <memory>
#include <vector>

namespace srp {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            App();
            ~App();

            App(const App &) = delete;
            App &operator=(const App &) = delete;

            void run();
        
        private:
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();

            SrpWindow srpWindow{WIDTH, HEIGHT, "Sierpinski triangle"};
            SrpDevice srpDevice{srpWindow};
            SrpSwapChain srpSwapChain{srpDevice, srpWindow.getExtent()};
            std::unique_ptr<SrpPipeline> srpPipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
    };
}