cmake_minimum_required(VERSION 2.8.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

PROJECT(tests)

set(tests
        test_select

)


foreach(test ${tests})
  add_executable(${test} ${test}.cpp)
endforeach()
