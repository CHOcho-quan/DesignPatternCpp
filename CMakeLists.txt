project(DesignPatternCpp)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

message(STATUS ${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB cpp_src "${CMAKE_SOURCE_DIR}/src/*.cpp")
foreach(single_src ${cpp_src})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" target ${single_src})
    add_executable(${target} ${single_src})
endforeach(single_src ${cpp_src})
