# SDL2CEF
A simple example shows how to use SDL2 as render backend for CEF3 on linux.

![screenshot](https://github.com/elephantp/SDL2CEF/raw/master/screenshot.png)

# Introduction
Using cef off-screen rendering you can embed cef in OpenGL/DirectX/Vulkan applications or some need to use the browser pixel buffer applications.
I use sdl2 to display pixel buffer and capture  `mouse` `keyboard` `ime` event send to cef.

# Build
Extract cef to cefroot folder.
And type `mkdir build && cmake .. && make`
