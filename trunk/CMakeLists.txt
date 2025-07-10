cmake_minimum_required (VERSION 2.6)
project (libxsvf)

add_library(xsvf tap.c statename.c memname.c svf.c xsvf.c scan.c play.c)
target_include_directories(xsvf PUBLIC ${PROJECT_SOURCE_DIR})
# Turn on -fPIC for so code can be added to shared libraries.
set_target_properties(xsvf PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

if (LINUX)
    add_executable(xsvftool-gpio xsvftool-gpio.c)
    target_link_libraries(xsvftool-gpio xsvf)
    target_compile_definitions(xsvftool-gpio PUBLIC XSVFTOOL_RLMS_VLINE)

    add_executable(xsvftool-gpio-dummy xsvftool-gpio.c)
    target_link_libraries(xsvftool-gpio-dummy xsvf)
endif()