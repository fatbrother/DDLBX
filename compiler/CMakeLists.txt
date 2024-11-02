cmake_minimum_required(VERSION 3.10)

project(ddlbx)

set(CMAKE_CXX_STANDARD 17)

# set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# if gtest has not been built, build it with CMakeLists.txt in googletest
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/lib/googletest/build)
    message(STATUS "Building googletest")
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S ${CMAKE_SOURCE_DIR}/lib/googletest -B ${CMAKE_SOURCE_DIR}/lib/googletest/build -D CMAKE_BUILD_TYPE=Release)
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_SOURCE_DIR}/lib/googletest/build)
endif()

# gtest
link_directories(${CMAKE_SOURCE_DIR}/lib/googletest/build/lib)
enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include)

# llvm
find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD})

# if BUILD_TYPE is Debug, add DDLBX_DEBUG
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDDLBX_DEBUG)
    set(CMAKE_BUILD_TYPE "Release")
endif()

file(GLOB SOURCES src/**/*.cc src/*.cc)
add_library(source OBJECT ${SOURCES})
target_include_directories(source PUBLIC ${LLVM_INCLUDE_DIRS})
target_include_directories(source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/llvm-project/llvm/include)
target_include_directories(source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/llvm-project/utils/bazel/llvm-project-overlay/llvm/include)
target_include_directories(source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/PEGTL/include)
target_include_directories(source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(source PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/parser)

add_executable(ddlbx ddlbx.cc)
target_link_libraries(ddlbx source)
target_link_libraries(ddlbx ${llvm_libs})

add_executable(unit_test test/unit_test.cc)
target_link_libraries(unit_test source)
target_link_libraries(unit_test ${llvm_libs})
target_link_libraries(unit_test gtest gtest_main)

add_test(unit_test unit_test)

#core folder
add_subdirectory(core)