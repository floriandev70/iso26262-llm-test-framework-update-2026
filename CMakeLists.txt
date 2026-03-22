cmake_minimum_required(VERSION 3.20)
project(iso26262_llm_test_framework_update_2026 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ISO26262_BASELINE_ENABLE_COVERAGE "Enable baseline-aligned GCC/Clang coverage flags" OFF)
set(ISO26262_BASELINE_GENERATED_TEST_DIR "" CACHE PATH "Directory containing generated baseline test CMakeLists.txt")

if(ISO26262_BASELINE_ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O0 -g --coverage)
    add_link_options(--coverage)
  else()
    message(WARNING "Coverage flags requested, but compiler '${CMAKE_CXX_COMPILER_ID}' is not yet wired for the minimal baseline import.")
  endif()
endif()

include(CTest)
enable_testing()

add_subdirectory(baseline/Lab)

if(ISO26262_BASELINE_GENERATED_TEST_DIR)
  if(EXISTS "${ISO26262_BASELINE_GENERATED_TEST_DIR}/CMakeLists.txt")
    add_subdirectory("${ISO26262_BASELINE_GENERATED_TEST_DIR}" generated_baseline_tests)
  else()
    message(FATAL_ERROR "ISO26262_BASELINE_GENERATED_TEST_DIR was set to '${ISO26262_BASELINE_GENERATED_TEST_DIR}', but no CMakeLists.txt was found there.")
  endif()
endif()
