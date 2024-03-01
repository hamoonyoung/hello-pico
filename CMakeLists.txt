cmake_minimum_required(VERSION 3.27)
include (/home/moon/pico/pico-sdk/external/pico_sdk_import.cmake) #Moon is my account name, so please change it to yours.

set (PROJECT_NAME "hello_pico")

project(PROJECT_NAME C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(JLINK_RTT_USE_SYSCALLS ON)

set(WIFI_SSID "sustainable-music.org") #Change it accordingly.
set(WIFI_PASSWORD "sustainable-music.org") #Change it accordingly.

set(PICO_BOARD pico_w)

add_subdirectory(/home/moon/RTT/ ${CMAKE_CURRENT_BINARY_DIR}/jlink_rtt) #Moon is my account name, so please change it to yours.

pico_sdk_init()

add_executable(PROJECT_NAME main.c)

pico_add_extra_outputs (PROJECT_NAME)

target_link_libraries(PROJECT_NAME
        PUBLIC pico_stdlib
                pico_cyw43_arch_none
        PRIVATE jlink_rtt
)

target_compile_definitions(PROJECT_NAME
        PRIVATE
        WIFI_SSID=\"${WIFI_SSID}\"
        WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
)

target_include_directories(PROJECT_NAME
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_enable_stdio_usb(PROJECT_NAME 1)
pico_enable_stdio_uart(PROJECT_NAME 0)
