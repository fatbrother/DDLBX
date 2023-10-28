cmake_minimum_required(VERSION 3.10)

project(ddlbx)

set(CMAKE_CXX_STANDARD 17)

# if llvm-project has not been built, build it with CMakeLists.txt in llvm-project/llvm
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm/build)
    message(STATUS "Building llvm-project")
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S ${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm -B ${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm/build -D CMAKE_BUILD_TYPE=Release)
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm/build)
endif()

# if pegtl has not been built, build it with CMakeLists.txt in pegtl
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/lib/PEGTL/build)
    message(STATUS "Building PEGTL")
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S ${CMAKE_SOURCE_DIR}/lib/PEGTL -B ${CMAKE_SOURCE_DIR}/lib/PEGTL/build -D CMAKE_BUILD_TYPE=Release)
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_SOURCE_DIR}/lib/PEGTL/build)
endif()

include_directories(${CMAKE_SOURCE_DIR}/lib/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/llvm-project/utils/bazel/llvm-project-overlay/llvm/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/PEGTL/include)

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

# # unit tests
# add_executable(ddlbx_test test/ddlbx_test.cpp)
# target_link_libraries(ddlbx_test gtest gtest_main)
# add_test(ddlbx_test ddlbx_test)

# find llvm in llvm-project/llvm/build
set(LLVM_DIR ${CMAKE_SOURCE_DIR}/lib/llvm-project/llvm/build/lib/cmake/llvm)
find_package(LLVM REQUIRED CONFIG PATHS ${LLVM_DIR})

add_executable(ddlbx ddlbx.cc)

# llvm
llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(ddlbx ${llvm_libs})
