This is my first time using vulkan

This project is following the tutorial from: Brendan Galea
(Youtube: https://www.youtube.com/c/BrendanGalea/videos)

I was having an issue when running this code in Debug configuration, turns out the validation layers couldn't load. If that happens, you need to define some system environment variables (on Windows): VK_INSTANCE_LAYERS and VK_LAYER_PATH. For some reason, the validation layers check didn't catch this problem.


this can be a bit tricky. My first recommendation is try re-installing vulkan, make sure you're downloading the vulkanSDK and not just the vulkan runtime.

Next if that doesn't fix the issue,

in the vulkanSDK/Applications directory there should be an application called vulkaninfo.

Try running that and in the output nearish the top you should see something like

Layers: count = 8
=================

Where validation layer count should be some number greater than 0. 

Then another thing you could try is in the same directory try opening vkconfig, have selected the validation layers option, and then run your program and see if the validation layers can be found in that case.