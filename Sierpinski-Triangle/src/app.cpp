#include "app.hpp"

namespace srp {
    void App::run() {
        while (!srpWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}