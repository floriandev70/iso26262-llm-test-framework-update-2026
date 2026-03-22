cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(first_baseline_generated_tests
  generated_test_file.cpp
)

target_link_libraries(first_baseline_generated_tests
  PRIVATE
    baseline_lab
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(first_baseline_generated_tests)
