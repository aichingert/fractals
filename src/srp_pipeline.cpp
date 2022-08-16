#include "srp_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace srp {

    SrpPipeline::SrpPipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        createGraphicsPipeline(vertFilepath, fragFilepath);
    }

    std::vector<char> SrpPipeline::readFile(const std::string &filepath) {

        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if (!file.is_open()) {
            throw std::runtime_error("failed to open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void SrpPipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << "\n";
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << "\n";
    }
}