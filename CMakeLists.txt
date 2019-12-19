cmake_minimum_required (VERSION 3.10)
project (stubbing)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/)

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
enable_testing()

# "external library"
add_library(external src/external.cpp)
target_include_directories(external PRIVATE include/)

# library which uses external library
add_library(internal INTERFACE)
target_include_directories(internal INTERFACE include/)

add_executable(internal_with_mocks_ut ut/stubs.cpp ut/test_internal.cpp)
target_link_libraries(internal_with_mocks_ut GTest::GTest GMock::GMock)
target_include_directories(internal_with_mocks_ut PRIVATE include/)

gtest_add_tests(internal_with_mocks_ut ""  AUTO)
