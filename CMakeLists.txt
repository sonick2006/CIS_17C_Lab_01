cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(bookstore_test google_test/bookstore_test.cpp)
target_link_libraries(bookstore_test GTest::gtest GTest::gtest_main)

# For the main program
add_executable(bookstore bookstore.cpp)
