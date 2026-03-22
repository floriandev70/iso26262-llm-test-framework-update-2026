add_library(baseline_lab STATIC
  boolean_algebra.cpp
  math_lib.cpp
  real_world.cpp
)

target_include_directories(baseline_lab
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)
