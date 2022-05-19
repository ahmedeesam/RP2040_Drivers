cmake_minimum_required(VERSION 3.23)

include(pico_sdk_import.cmake)

project(Usart_Test)

pico_sdk_init()

add_executable(Usart_Test APP_Usart.c RP2040_Uart.c RP2040_Gpio.c RP2040_Timer.c RP2040_Spi.c)

target_link_libraries(Usart_Test pico_stdlib)

pico_add_extra_outputs(Usart_Test)