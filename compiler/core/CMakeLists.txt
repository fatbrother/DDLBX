cmake_minimum_required(VERSION 3.10)

project(ddlbx_core)

# build ./*.cc files to object files
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_library(ddlbx_core STATIC ${SRC_FILES})

# include directories
target_include_directories(ddlbx_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ddlbx_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/bdwgc/include)
