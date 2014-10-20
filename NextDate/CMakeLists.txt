cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
SET(SRC_LIST main.cpp NextDate.cpp)
add_executable(runTests ${SRC_LIST})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
