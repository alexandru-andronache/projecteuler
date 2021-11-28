include(${COMMON_SOURCES}/cmake/utilities.cmake)

function(add_problem NUMBER)
    set(NAME problem.${NUMBER})
    set(NAME_TEST ${NAME}.test)

    add_executable(${NAME_TEST} ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${NUMBER}/main.cpp
                                ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${NUMBER}/test.cpp
                                ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${NUMBER}/test.h
                                ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${NUMBER}/tests/TestClass.cpp
                                ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${NUMBER}/tests/TestClass.h 
                                ${utils_src})

    target_include_directories(${NAME_TEST} PRIVATE ${COMMON_SOURCES}/include)

    add_dependencies(${NAME_TEST} googletest_utilities)
    target_compile_definitions(${NAME_TEST} PRIVATE TESTING=1)

    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        set(CMAKE_DEBUG_POSTFIX d)
    endif()

    target_link_libraries(${NAME_TEST}
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_DEBUG_POSTFIX}.a
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_DEBUG_POSTFIX}.a)
endfunction()

function(add_set_of_problem START END NAME)
    set (SOURCES test.cpp ${utils_src})
    foreach(n RANGE ${START} ${END})
        pad_number_with_0(${n} 3 n)
        list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${n}/main.cpp 
                            ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${n}/test.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${n}/tests/TestClass.cpp 
                            ${CMAKE_CURRENT_SOURCE_DIR}/problems/problem_${n}/tests/TestClass.h)
    endforeach()

    add_executable(${NAME} ${SOURCES})

    target_include_directories(${NAME} PRIVATE ${COMMON_SOURCES}/include)

    add_dependencies(${NAME} googletest_utilities)
    target_compile_definitions(${NAME} PRIVATE TESTING=1)

    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        set(CMAKE_DEBUG_POSTFIX d)
    endif()

    target_link_libraries(${NAME}
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_DEBUG_POSTFIX}.a
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_DEBUG_POSTFIX}.a)
endfunction()

function(problem)
    set(CMAKE_CXX_STANDARD 17)
    SET(COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../../common)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../bin")

    include(${COMMON_SOURCES}/cmake/gtest.cmake)

    file(GLOB utils_src "${COMMON_SOURCES}/src/*.cpp")

    file(GLOB cpp_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
    file(GLOB h_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

    file(GLOB cpp_files_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
    file(GLOB h_files_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h")

    add_executable(main main.cpp ${utils_src})
    add_executable(test main.cpp ${cpp_files} ${h_files} ${utils_src} ${cpp_files_test} ${h_files_test})

    target_include_directories(main PRIVATE ${COMMON_SOURCES}/include)
    target_include_directories(test PRIVATE ${COMMON_SOURCES}/include)

    add_dependencies(test googletest_utilities)

    target_compile_definitions(test PRIVATE TESTING=1)

    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
            set(CMAKE_DEBUG_POSTFIX d)
    endif()

    target_link_libraries(test
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_DEBUG_POSTFIX}.a
            general ${source_dir}/../googletest_utilities-build/googletest/${CMAKE_BUILD_TYPE}Libs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_DEBUG_POSTFIX}.a)
endfunction()