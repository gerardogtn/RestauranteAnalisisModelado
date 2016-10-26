project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_DIR}/include $ENV{GTEST_DIR}/include)
link_directories($ENV{GMOCK_DIR}/mybuild $ENV{GTEST_DIR}/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources
    main.cpp)
set(testSources)
add_executable(test ${testSources} ${sources})
target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test pthread)
