cmake_minimum_required(VERSION 3.22)
project(tetris_cpp)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-std=c++20)
aux_source_directory(. src)
add_executable(tetris_cpp ${src})

configure_file (${PROJECT_SOURCE_DIR}/tetris.map ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    target_compile_options(tetris_cpp PRIVATE "/utf-8")
    set_property(TARGET tetris_cpp PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# 启用 AddressSanitizer
# if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
#     set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
# endif()
