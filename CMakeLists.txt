project(algos)
cmake_minimum_required(VERSION 3.22)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

enable_testing()

add_library(
  algos_sorting 
  src/insertion_sort.cc
)

add_executable(
  insertion_sort_test
  test/insertion_sort_test.cc
)

target_include_directories (
	insertion_sort_test PRIVATE
	src
)

target_link_libraries(
  insertion_sort_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(insertion_sort_test)

