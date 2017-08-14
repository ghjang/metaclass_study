cmake_minimum_required(VERSION 3.0.0)
project(interface_test VERSION 0.0.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# clang 4.0.0's C++ header file path
include_directories("/Users/gilhojang/clang/clang+llvm-4.0.0-x86_64-apple-darwin/include/c++/v1")

# prototype clang 5.0.0's additional C++ header file path
include_directories("/Users/gilhojang/clang/llvm_clang_cppx/include")


set(LLVM_5_0_0_BASE "/Users/gilhojang/clang/llvm_clang_cppx")

set(CMAKE_C_COMPILER  "${LLVM_5_0_0_BASE}/bin/clang")
set(CMAKE_CXX_COMPILER  "${LLVM_5_0_0_BASE}/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Xclang -freflection")

set(SOURCE_FILES
        interface_test.cpp
        indexible_test.cpp
        main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
