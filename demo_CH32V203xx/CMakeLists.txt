cmake_minimum_required(VERSION 3.20)

project(wch_demo VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    -march=rv32imac \
    -mabi=ilp32 \
    -msmall-data-limit=8 \
    -msave-restore \
    -Os \
    -g3 \
    -fmessage-length=0 \
    -fsigned-char \
    -ffunction-sections \
    -fdata-sections \
    -fno-common \
    -fstack-usage \
    -flto \
")

add_subdirectory(vendor/CH32V203C8T6)
add_subdirectory(src)
