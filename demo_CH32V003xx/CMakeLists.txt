cmake_minimum_required(VERSION 3.20)

project(wch_demo VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_C_STANDARD 99)

add_executable(wch_demo 
    src/Core/core_riscv.c
    src/Debug/debug.c
    src/Peripheral/src/ch32v00x_dbgmcu.c
    src/Peripheral/src/ch32v00x_dma.c
    src/Peripheral/src/ch32v00x_exti.c
    src/Peripheral/src/ch32v00x_flash.c
    src/Peripheral/src/ch32v00x_gpio.c
    src/Peripheral/src/ch32v00x_i2c.c
    src/Peripheral/src/ch32v00x_iwdg.c
    src/Peripheral/src/ch32v00x_misc.c
    src/Peripheral/src/ch32v00x_opa.c
    src/Peripheral/src/ch32v00x_pwr.c
    src/Peripheral/src/ch32v00x_rcc.c
    src/Peripheral/src/ch32v00x_spi.c
    src/Peripheral/src/ch32v00x_tim.c
    src/Peripheral/src/ch32v00x_usart.c
    src/Peripheral/src/ch32v00x_wwdg.c
    src/Startup/startup_ch32v00x.S
    src/User/ch32v00x_it.c
    src/User/main.c
    src/User/system_ch32v00x.c
)
target_include_directories(wch_demo PRIVATE
    src/Core
    src/Debug
    src/Peripheral/inc
    src/Startup
    src/User
)

target_compile_options(wch_demo PRIVATE 
    -march=rv32ec
    -mabi=ilp32e
    -msmall-data-limit=0
    -msave-restore
    -Os
    -fmessage-length=0
    -fsigned-char
    -ffunction-sections
    -fdata-sections
    -fno-common
    -g3
    -Wall
    -fstack-usage
    -flto
)
target_link_options(wch_demo PRIVATE
    -march=rv32ec
    -mabi=ilp32e
    -msmall-data-limit=0
    -msave-restore
    -Os
    -fmessage-length=0
    -fsigned-char
    -ffunction-sections
    -fdata-sections
    -fno-common
    -g3
    -Wall
    -fstack-usage
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--print-memory-usage
    -T "${CMAKE_SOURCE_DIR}/src/Ld/Link.ld"
    -Wl,--gc-sections
    -Wl,-Map=wch_demo.map
    -nostartfiles
    -Xlinker
)

set_target_properties(wch_demo PROPERTIES
    SUFFIX ".elf"
)

add_custom_command(TARGET wch_demo POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex "$<TARGET_FILE:wch_demo>" wch_demo.hex
)

