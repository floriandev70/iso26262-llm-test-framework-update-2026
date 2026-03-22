cmake_minimum_required(VERSION 3.20)

include(${CMAKE_SOURCE_DIR}/cmake/LocalGTest.cmake)

iso26262_add_gtest_executable(first_baseline_generated_tests
  generated_test_file.cpp
  ${CMAKE_SOURCE_DIR}/tests/supplemental_all_cpp_tests.cpp
)

target_link_libraries(first_baseline_generated_tests
  PRIVATE
    baseline_lab
)

target_include_directories(first_baseline_generated_tests
  PRIVATE
    ${CMAKE_SOURCE_DIR}/baseline/Lab
)
