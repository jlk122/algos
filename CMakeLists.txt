project(algos)
cmake_minimum_required(VERSION 3.22)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

enable_testing()

add_library(
  algos_sorting 
  src/insertion_sort.cc
  src/add_binary_integers.cc
  src/selection_sort.cc
)

add_executable(
  algos_test
  test/sorting_test.cc
  test/add_binary_integers_test.cc
)

target_include_directories (
  algos_test PRIVATE
  src
)

target_link_libraries(
  algos_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(algos_test)

