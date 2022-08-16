#pragma once

#include "srp_device.hpp"

#include <string>
#include <vector>


namespace srp {
    struct PipelineConfigInfo {};

    class SrpPipeline {
        public:
            SrpPipeline(
                SrpDevice &device, 
                const std::string &vertFilepath, 
                const std::string &fragFilepath, 
                const PipelineConfigInfo &configInfo);
            ~SrpPipeline() {}

            SrpPipeline(const SrpPipeline&) = delete;
            void operator=(const SrpPipeline&) = delete;

            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t heigth);

        private:
            static std::vector<char> readFile(const std::string &filepath);

            void createGraphicsPipeline(
                const std::string &vertFilepath, 
                const std::string &fragFilepath,
                const PipelineConfigInfo &configInfo);

            void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

            SrpDevice &srpDevice;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
}