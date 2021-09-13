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