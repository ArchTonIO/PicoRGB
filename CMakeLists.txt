# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/antonio/Progetti/picoProjects/pico-sdk")#only true for my machine

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(PicoRGB C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(PicoRGB main.c PicoRGB.c)

pico_generate_pio_header(PicoRGB ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

pico_set_program_name(PicoRGB "picoRGB")
pico_set_program_version(PicoRGB "1.0")

pico_enable_stdio_uart(PicoRGB 0)
pico_enable_stdio_usb(PicoRGB 1)

# Add the standard library to the build
target_link_libraries(PicoRGB pico_stdlib)
target_link_libraries(PicoRGB pico_stdlib hardware_pio)

pico_add_extra_outputs(PicoRGB)

