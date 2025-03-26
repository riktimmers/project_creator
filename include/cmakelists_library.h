#ifndef H_CMAKE_LIBRARY__
#define H_CMAKE_LIBRARY__

#include <string>

inline std::string createCmakeLists(const std::string project_name) {
  return "cmake_minimum_required(VERSION 3.16.3)\n"
         "project(" +
         project_name +
         ")\n"
         "\n"
         "if(NOT CMAKE_BUILD_TYPE)\n"
         " set(CMAKE_BUILD_TYPE Release)\n"
         " add_compile_options(-std=c++17 -O3 -Wall -Werror -Wextra -Wpedantic)\n"
         "else()\n"
         " add_compile_options(-std=c++17 -Wall -Werror -Wextra -Wpedantic)\n"
         "endif()\n"
         "\n"
         "set(CMAKE_EXPORT_COMPILE_COMMANDS On)\n"
         "\n"
         "include_directories(\n"
         "  include\n"
         ")\n"
         "include(GNUInstallDirs)\n"
         "\n"
         "set(source_code\n"
         "  src/main.cpp\n"
         ")\n"
         "\n"
         "add_library(${CMAKE_PROJECT_NAME} SHARED ${source_code})\n"
         "\n"
         "target_link_libraries(${CMAKE_PROJECT_NAME})\n"
         "\n"
         "# Set include directories\n"
         "target_include_directories(\n"
         "${CMAKE_PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>\n"
         "     $<INSTALL_INTERFACE:include>)\n"
         "\n"
         "if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)\n"
         "    set(CMAKE_INSTALL_PREFIX \"$ENV{HOME}/.local\" CACHE PATH\n"
         "             \"Default install path\" FORCE)\n"
         "endif()\n"
         "\n"
         "#Install the target \n"
         "install(TARGETS ${CMAKE_PROJECT_NAME}\n"
         "        EXPORT ${CMAKE_PROJECT_NAME}Targets\n"
         "        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib\n"
         "        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib\n"
         "        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)\n"
         "\n"
         "#Install headers\n"
         "install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)\n"
         "\n"
         "#Export the library configuration\n"
         "install(EXPORT ${CMAKE_PROJECT_NAME}Targets\n"
         "        FILE ${CMAKE_PROJECT_NAME}Config.cmake\n"
         "        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/${CMAKE_PROJECT_NAME})\n";
}
#endif
