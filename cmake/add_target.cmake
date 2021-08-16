function(add_target NAME)
    file(GLOB_RECURSE ${NAME}_src_files_h "${CMAKE_CURRENT_SOURCE_DIR}/${NAME}/*.h")
    file(GLOB_RECURSE ${NAME}_src_files_cpp "${CMAKE_CURRENT_SOURCE_DIR}/${NAME}/*.cpp")

    list(FILTER ${NAME}_src_files_cpp EXCLUDE REGEX ".*test.cpp$")
    list(FILTER ${NAME}_src_files_h EXCLUDE REGEX ".*cmake-build-debug.*")
    list(FILTER ${NAME}_src_files_cpp EXCLUDE REGEX ".*cmake-build-debug.*")

    list(APPEND ALL_TESTS_FILES ${${NAME}_src_files_cpp} ${${NAME}_src_files_h})

    add_executable(${NAME}.all.tests
                   all.tests.cpp
                   ${${NAME}_src_files_cpp}
                   ${${NAME}_src_files_h}
                   ${utils_src})

    target_include_directories(${NAME}.all.tests PRIVATE ${COMMON_SOURCES}/include)

    add_dependencies(${NAME}.all.tests googletest_utilities)
    target_compile_definitions(${NAME}.all.tests PRIVATE TESTING=1)
endfunction()