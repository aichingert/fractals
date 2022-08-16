#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace srp {

    class SrpWindow {

        public:
            SrpWindow(int w, int h, std::string name);
            ~SrpWindow();

            bool shouldClose() { return glfwWindowShouldClose(window); }
        private:

            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
}