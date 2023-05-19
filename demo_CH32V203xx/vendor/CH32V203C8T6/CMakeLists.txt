add_library(wchlib OBJECT
    Core/core_riscv.c
    Debug/debug.c
    Peripheral/src/ch32v20x_adc.c
    Peripheral/src/ch32v20x_bkp.c
    Peripheral/src/ch32v20x_can.c
    Peripheral/src/ch32v20x_crc.c
    Peripheral/src/ch32v20x_dbgmcu.c
    Peripheral/src/ch32v20x_dma.c
    Peripheral/src/ch32v20x_exti.c
    Peripheral/src/ch32v20x_flash.c
    Peripheral/src/ch32v20x_gpio.c
    Peripheral/src/ch32v20x_i2c.c
    Peripheral/src/ch32v20x_iwdg.c
    Peripheral/src/ch32v20x_misc.c
    Peripheral/src/ch32v20x_opa.c
    Peripheral/src/ch32v20x_pwr.c
    Peripheral/src/ch32v20x_rcc.c
    Peripheral/src/ch32v20x_rtc.c
    Peripheral/src/ch32v20x_spi.c
    Peripheral/src/ch32v20x_tim.c
    Peripheral/src/ch32v20x_usart.c
    Peripheral/src/ch32v20x_wwdg.c
# CH32V20x_D6 - CH32V203K8-CH32V203C8-CH32V203G8-CH32V203F8 
    Startup/startup_ch32v20x_D6.S
# CH32V20x_D8 - CH32V203RB
    #Startup/startup_ch32v20x_D8.S
# CH32V20x_D8W - CH32V208x
    #Startup/startup_ch32v20x_D8W.S
    User/ch32v20x_it.c
    User/system_ch32v20x.c
)

target_include_directories(wchlib PUBLIC
    Core
    Debug
    Peripheral/inc
    User
)

set(WCHLIB_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Ld/Link.ld PARENT_SCOPE)