cmake_minimum_required (VERSION 2.6)

include_directories(${PROJECT_SOURCE_DIR}/../trunk)
add_library(xsvf_player xsvf_player_base.cc xsvf_player.cc xsvf_file_host.cc)
# Turn on -fPIC for so code can be added to shared libraries.
set_target_properties(xsvf_player PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

target_include_directories(xsvf_player PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(xsvf_player PUBLIC xsvf)
