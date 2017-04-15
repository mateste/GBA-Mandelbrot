macro(gbafix target_name multiboot_on)
    if(multiboot_on)
        target_link_libraries(${target_name} PUBLIC -specs=gba_mb.specs)
    else()
        target_link_libraries(${target_name} PUBLIC -specs=gba.specs)
    endif()
    target_link_libraries(${target_name}
        PUBLIC
        -mthumb -mthumb-interwork -Wl,-Map,${target_name}.elf.map)
    target_compile_options(${target_name}
        PUBLIC
        -mthumb -mthumb-interwork -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math)
    add_custom_command(TARGET ${target_name}
        COMMAND arm-none-eabi-objcopy ARGS -O binary
        $<TARGET_FILE:${target_name}>
        $<TARGET_FILE:${target_name}>.gba
    COMMENT Copying binary data to GBA rom)
    add_custom_command(TARGET ${target_name}
        COMMAND gbafix ARGS $<TARGET_FILE:${target_name}>.gba
    COMMENT Fixing GBA rom)
endmacro()
