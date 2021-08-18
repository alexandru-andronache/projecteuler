cmake_minimum_required(VERSION 3.15)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
SET(NAME "project.euler")
project(${NAME})
set(COMMON_TEST_NAME "common.tests")
set(CMAKE_CXX_STANDARD 17)
SET(COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include(${COMMON_SOURCES}/cmake/gtest.cmake)
include(${COMMON_SOURCES}/cmake/utilities.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/add_target.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/add_problem.cmake)

file(GLOB utils_src "common/src/*.cpp")
file(GLOB tests_src "common/tests/*.cpp")
file(GLOB tests_include "common/tests/*.h")

foreach(n RANGE 1 15)
        pad_number_with_0(${n} 3 n)
        add_problem(${n})
endforeach()

add_executable(${COMMON_TEST_NAME} ${tests_include} test.cpp ${tests_src} ${utils_src})

target_include_directories(${COMMON_TEST_NAME} PRIVATE ${COMMON_SOURCES}/include)

add_dependencies(${COMMON_TEST_NAME} googletest_utilities)

target_compile_definitions(${COMMON_TEST_NAME} PRIVATE TESTING=1)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        set(CMAKE_DEBUG_POSTFIX d)
endif()

target_link_libraries(${COMMON_TEST_NAME}
        general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_DEBUG_POSTFIX}.a
        general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_DEBUG_POSTFIX}.a)