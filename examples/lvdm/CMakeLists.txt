cmake_minimum_required(VERSION 2.8)

project(lvdm)

set(PLUGIN_NAME "lvdm")
set(PLUGIN_SOURCES "lvdm.cpp")

include(SampPlugin)

target_link_libraries(${PLUGIN_TARGET} sampgdk)

