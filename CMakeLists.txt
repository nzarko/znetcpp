cmake_minimum_required(VERSION 2.8)

project(network_intro_2)
set(CMAKE_CXX_STANDARD 14)
find_package ( cppnetlib 0.11.0 REQUIRED )
include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} "main.cpp" "increment.cpp" printer.cpp printer.h global.h)
target_link_libraries ( ${PROJECT_NAME} ${CPPNETLIB_LIBRARIES} )
