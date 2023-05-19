add_executable(wch_demo 
    main.c
)
target_link_libraries(wch_demo wchlib)

target_link_options(wch_demo PRIVATE
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--print-memory-usage
    -T "${WCHLIB_LINKER_SCRIPT}"
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