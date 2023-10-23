cmake_minimum_required(VERSION 3.21)
project(PracaLicencjacka)

set(CMAKE_CXX_STANDARD 23)

set(Boost_INCLUDE_DIR C:/MinGW/include)
set(Boost_LIBRARY_DIR C:/MinGW/lib)
find_package(Boost 1.69.0)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)
