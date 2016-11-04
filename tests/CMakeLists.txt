cmake_minimum_required(VERSION 2.8.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

PROJECT(tests)

set(tests
        test_select

        )


foreach (test ${tests})
    add_executable(${test} ${test}.cpp)

    if (WIN32)
        add_test(NAME ${test} WORKING_DIRECTORY ${LIBRARY_OUTPUT_PATH} COMMAND ${test})
    else ()
        add_test(NAME ${test} COMMAND ${test})
    endif ()
    set_tests_properties(${test} PROPERTIES TIMEOUT 10)
endforeach ()
