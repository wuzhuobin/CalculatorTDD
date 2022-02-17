cmake_minimum_required(VERSION 3.16)

project(CalculatorTDD)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.c*)
file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h*)
add_library(${PROJECT_NAME} ${SRC} ${INC})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}Main ${PROJECT_SOURCE_DIR}/src/main/main.cpp)
target_link_libraries(${PROJECT_NAME}Main PRIVATE ${PROJECT_NAME})

option(BUILD_TESTING "Build Test." OFF)
if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker
  # settings
  set(gtest_force_shared_crt
      ON
      CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()

  file(GLOB_RECURSE TEST_SRC ${PROJECT_SOURCE_DIR}/test/*.c*)
  file(GLOB_RECURSE TEST_INC ${PROJECT_SOURCE_DIR}/test/*.h*)
  add_executable(${PROJECT_NAME}Test ${TEST_SRC} ${TEST_INC})
  target_link_libraries(${PROJECT_NAME}Test PRIVATE ${PROJECT_NAME} gtest
                                                    gtest_main gmock gmock_main)
  target_include_directories(
    ${PROJECT_NAME}Test PRIVATE ${PROJECT_SOURCE_DIR}/test/testdouble/include)

  include(GoogleTest)
  gtest_discover_tests(${PROJECT_NAME}Test)
endif()
