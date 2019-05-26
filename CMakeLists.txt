
cmake_minimum_required(VERSION 3.13)
project(VK)

set(CMAKE_CXX_STANDARD 17)
include_directories(${VK_SOURCE_DIR})

add_executable(vk-util main.cpp)
add_executable(vk-testing vk_testing.cpp
        gtest/gtest-all.cc
        gtest/gtest.h
        gtest/gtest_main.cc)


add_library(VK SHARED lib/Searcher.cpp lib/Searcher.h lib/Simple_searcher.cpp lib/Simple_searcher.h)
include_directories(lib)

#target_link_libraries(vk-util VK)
target_link_libraries(vk-testing VK)