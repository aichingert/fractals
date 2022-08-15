#pragma once

#include "srp_window.hpp"

namespace srp {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGTH = 600;

            void run();
        
        private:
            SrpWindow srpWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
    };
}