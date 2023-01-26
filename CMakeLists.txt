cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this should happen before project()
include(pico_sdk_import.cmake)

project(BlinkD13)

# rest of your project
set(PICO_BOARD adafruit_feather_rp2040)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(blink
    blink.c
    )

# pull in common dependencies
target_link_libraries(blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)
