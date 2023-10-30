project(project_creator)
cmake_minimum_required(VERSION 3.16.3)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS On)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_compile_options(-std=c++17 -Wall -Werror -Wextra -Wpedantic)

include_directories(
  include 
)

set(source_code 
  src/main.cpp 
)

add_executable(project_creator ${source_code})
