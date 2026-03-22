include_guard(GLOBAL)

if(NOT TARGET iso26262_gtest_shim)
  add_library(iso26262_gtest_shim STATIC
    ${CMAKE_SOURCE_DIR}/third_party/gtest_shim/src/gtest_shim.cpp
  )
  target_include_directories(iso26262_gtest_shim
    PUBLIC
      ${CMAKE_SOURCE_DIR}/third_party/gtest_shim/include
  )
  target_compile_features(iso26262_gtest_shim PUBLIC cxx_std_17)
endif()

if(NOT TARGET iso26262_gtest_shim_main)
  add_library(iso26262_gtest_shim_main STATIC
    ${CMAKE_SOURCE_DIR}/third_party/gtest_shim/src/gtest_shim_main.cpp
  )
  target_link_libraries(iso26262_gtest_shim_main PUBLIC iso26262_gtest_shim)
  target_compile_features(iso26262_gtest_shim_main PUBLIC cxx_std_17)
endif()

if(NOT TARGET GTest::gtest)
  add_library(GTest::gtest ALIAS iso26262_gtest_shim)
endif()

if(NOT TARGET GTest::gtest_main)
  add_library(GTest::gtest_main ALIAS iso26262_gtest_shim_main)
endif()

function(iso26262_add_gtest_executable target_name)
  add_executable(${target_name} ${ARGN})
  target_link_libraries(${target_name}
    PRIVATE
      GTest::gtest_main
  )
  add_test(NAME ${target_name} COMMAND ${target_name})
endfunction()
