#ifndef _H_CMAKE__ 
#define _H_CMAKE__

#include <string> 

inline std::string createCmakeLists(const std::string project_name) {
  return
"project(" + project_name + ")\n"
"cmake_minimum_required(VERSION 3.16.3)\n"
"\n"
"if(NOT CMAKE_BUILD_TYPE)\n"
" set(CMAKE_BUILD_TYPE Release)\n"
"endif()\n"
"\n"
"set(CMAKE_EXPORT_COMPILE_COMMANDS On)\n"
"\n"
"add_compile_options(-std=c++17 -O3 -Wall -Werror -Wextra -Wpedantic)\n"
"\n"
"include_directories(\n"
"  include\n"
")\n"
"\n"
"set(source_code\n"
"  src/main.cpp\n"
")\n"
"\n"
"add_executable(main ${source_code})\n"
"\n"
"target_link_libraries(main)\n";
}
#endif
